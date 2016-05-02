#include "application.h"

#include <QString>
#include <QtQml>

#include "qlldb/command_interpreter.h"

namespace {

void registerTypes() {
  const char* uri = "qlldb";
  const int version_major = 0;
  const int version_minor = 1;
  qmlRegisterUncreatableType<qlldb::CommandInterpreter>(
      uri, version_major, version_minor, "CommandInterpreter",
      "Cannot instantiate CommandInterpreter");
}

}  // namespace

Application::Application(int& argc, char** argv) : QGuiApplication(argc, argv) {
  registerTypes();
  setApplicationName("qlldb");
  setOrganizationName("qlldb");
}

Application::~Application() = default;

void Application::RunCommandInterpreter(const lldb::SBDebugger& debugger,
                                        const Driver::OptionData& options) {
  debugger_ = debugger;
  options_ = options;
  command_interpreter_ = std::make_unique<qlldb::CommandInterpreter>(
      debugger_.GetCommandInterpreter());
  engine_.rootContext()->setContextProperty("CommandInterpreter",
                                            command_interpreter_.get());
  engine_.load(QUrl(QStringLiteral("qrc:/main.qml")));
  exec();
}
