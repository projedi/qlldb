#pragma once

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <lldb/API/SBDebugger.h>

#include "driver/Driver.h"

namespace qlldb {
class CommandInterpreter;
}  // namespace qlldb

class Application : public QGuiApplication {
  Q_OBJECT
 public:
  Application(int& argc, char** argv);
  ~Application() override;

  // This is the entry point from lldb driver.
  void RunCommandInterpreter(const lldb::SBDebugger& debugger,
                             const Driver::OptionData& options);

 private:
  QQmlApplicationEngine engine_;
  lldb::SBDebugger debugger_;
  Driver::OptionData options_;
  std::unique_ptr<qlldb::CommandInterpreter> command_interpreter_;
};
