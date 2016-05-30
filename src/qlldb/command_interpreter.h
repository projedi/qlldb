#pragma once

#include <QObject>

#include <lldb/API/SBCommandInterpreter.h>

namespace qlldb {

class CommandInterpreter : public QObject {
  Q_OBJECT
  Q_PROPERTY(const QString& outputLog READ outputLog NOTIFY outputLogChanged)
 public:
  explicit CommandInterpreter(lldb::SBCommandInterpreter command_interpreter);
  CommandInterpreter(const CommandInterpreter&) = delete;
  CommandInterpreter(CommandInterpreter&&) = delete;
  ~CommandInterpreter() override;
  CommandInterpreter& operator=(const CommandInterpreter&) = delete;
  CommandInterpreter& operator=(CommandInterpreter&&) = delete;

  const QString& outputLog() const { return output_log_; }

 public slots:
  void sendCommand(const QString& command);
  void sendInterrupt();

 signals:
  void outputLogChanged();

 private:
  lldb::SBCommandInterpreter command_interpreter_;
  QString output_log_;
};

}  // namespace qlldb
