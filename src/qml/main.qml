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

    ColumnLayout {
        id: columnLayout1
        anchors.fill: parent

        ScrollView {
          Layout.fillHeight: true
          Layout.fillWidth: true
          ListView {
              id: outputLog
              model: CommandInterpreter.outputLog
              delegate: Text {
                text: display
                font.family: "Courier"
              }
          }
        }

        TextField {
            id: inputPrompt
            font.family: "Courier"
            Layout.alignment: Qt.AlignLeft | Qt.AlignBottom
            Layout.fillWidth: true
            placeholderText: qsTr("lldb prompt")
            focus: true

            // TODO: Logic has no place here.
            Keys.onPressed: {
              var modifier = Qt.platform.os == "osx"
                  ? Qt.MetaModifier
                  : Qt.ControlModifier;
              if (event.modifiers == modifier &&
                  event.key == Qt.Key_C &&
                  selectionStart == selectionEnd) {
                event.accepted = true;
                CommandInterpreter.sendInterrupt()
                text = ""
              }
            }

            onAccepted: {
              CommandInterpreter.sendCommand(text)
              text = ""
            }

            onActiveFocusChanged: {
              if (!activeFocus)
                forceActiveFocus()
            }
        }
    }

    visible: true
    title: "qlldb"

    width: 800
    height: 600
}
