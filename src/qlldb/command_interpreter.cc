#include "qlldb/command_interpreter.h"

#include "lldb/API/SBCommandReturnObject.h"

#include <QDebug>

#include "application.h"

namespace qlldb {

CommandInterpreter::CommandInterpreter(
    lldb::SBCommandInterpreter command_interpreter)
    : command_interpreter_(command_interpreter) {}

CommandInterpreter::~CommandInterpreter() = default;

void CommandInterpreter::sendCommand(const QString& command) {
  if (command.isEmpty())
    return;
  lldb::SBCommandReturnObject result;
  command_interpreter_.HandleCommand(command.toStdString().c_str(), result,
                                     true);
  if (result.GetStatus() == lldb::eReturnStatusQuit) {
    Application::quit();
    return;
  }
  output_log_ += QString("> ") + command + "\n";
  output_log_ += result.GetOutput();
  output_log_ += result.GetError();
  emit outputLogChanged();
}

void CommandInterpreter::sendInterrupt() {
  command_interpreter_.GetDebugger().DispatchInputInterrupt();
}

}  // namespace qlldb
