#include "application.h"

#include <QString>
#include <QtQml>

Application::Application(int argc, char** argv) : QGuiApplication(argc, argv) {
  setApplicationName("qlldb");
  setOrganizationName("qlldb");
  engine_.load(QUrl(QStringLiteral("qrc:/main.qml")));
}
