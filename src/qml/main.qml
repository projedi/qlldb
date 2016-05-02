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

        TextArea {
            id: outputLog
            font.family: "Courier"
            Layout.fillHeight: true
            Layout.fillWidth: true
            text: CommandInterpreter.outputLog
            readOnly: true
        }

        TextField {
            id: inputPrompt
            font.family: "Courier"
            Layout.alignment: Qt.AlignLeft | Qt.AlignBottom
            Layout.fillWidth: true
            placeholderText: qsTr("lldb prompt")

            onAccepted: {
              CommandInterpreter.sendCommand(text)
              text = ""
            }
        }
    }

    visible: true
    title: "qlldb"

    width: 800
    height: 600
}
