import QtQuick 2.4
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1
import Qt.labs.settings 1.0

ApplicationWindow {
  id: window

  Settings {
    category: "ApplicationWindow"
    property alias x: window.x
    property alias y: window.y
    property alias width: window.width
    property alias height: window.height
  }

  visible: true
  title: "qlldb"

  width: 800
  height: 600
}
