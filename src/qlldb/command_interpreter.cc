#include "qlldb/command_interpreter.h"

#include "lldb/API/SBCommandReturnObject.h"

#include <QDebug>

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
  output_log_ += QString("> ") + command + "\n";
  output_log_ += result.GetOutput();
  output_log_ += result.GetError();
  emit outputLogChanged();
}

}  // namespace qlldb
