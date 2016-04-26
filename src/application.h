#pragma once

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <lldb/API/SBDebugger.h>

class Application : public QGuiApplication {
  Q_OBJECT
 public:
  Application(int argc, char** argv);

 private:
  QQmlApplicationEngine engine_;
  lldb::SBDebugger debugger_;
};
