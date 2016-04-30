#include "application.h"

#include <QString>
#include <QtQml>

Application::Application(int& argc, char** argv) : QGuiApplication(argc, argv) {
  setApplicationName("qlldb");
  setOrganizationName("qlldb");
  engine_.load(QUrl(QStringLiteral("qrc:/main.qml")));
}

void Application::RunCommandInterpreter(const lldb::SBDebugger& debugger,
                                        const Driver::OptionData& options) {
  debugger_ = debugger;
  options_ = options;
#if 0
  debugger_.RunCommandInterpreter(true, false);
#else
  exec();
#endif
}
