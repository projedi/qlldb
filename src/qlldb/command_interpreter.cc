#include "qlldb/command_interpreter.h"

#include "lldb/API/SBCommandReturnObject.h"

#include <QDebug>

#include "application.h"

namespace {

// TODO: ensure that it's efficient.
QStringListModel& operator<<(QStringListModel& string_list_model,
                             const QString& string) {
  string_list_model.setStringList(string_list_model.stringList() << string);
  return string_list_model;
}

}  // namespace

namespace qlldb {

CommandInterpreter::CommandInterpreter(
    lldb::SBCommandInterpreter command_interpreter)
    : command_interpreter_(command_interpreter) {}

CommandInterpreter::~CommandInterpreter() = default;

void CommandInterpreter::sendCommand(const QString& command) {
  if (command.isEmpty())
    return;
  // TODO: This should be more systematic.
  if (command == "gui") {
    output_log_ << "> gui";
    output_log_ << "error: gui command is unsupported in qlldb (since, you "
                   "know, it's a "
                   "gui already)";
    return;
  }
  lldb::SBCommandReturnObject result;
  command_interpreter_.HandleCommand(command.toStdString().c_str(), result,
                                     true);
  if (result.GetStatus() == lldb::eReturnStatusQuit) {
    Application::quit();
    return;
  }
  output_log_ << (QString("> ") + command);
  output_log_ << result.GetOutput();
  output_log_ << result.GetError();
}

void CommandInterpreter::sendInterrupt() {
  command_interpreter_.GetDebugger().DispatchInputInterrupt();
}

}  // namespace qlldb
