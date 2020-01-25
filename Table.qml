import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1

Rectangle {
    width: 300
    height: 300

    TableView {
        anchors.margins: 10
        anchors.fill: parent

        model: myModel
        clip: true

        TableViewColumn {
            width: 150
            title: "Name"
            role: "name"
        }
        TableViewColumn {
            id: col
            width: 70
            title: "Latitude"
            role: "color"
            delegate: Circle  {
                color: styleData.value
                anchors.centerIn: parent
            }

        }

        itemDelegate: Item {
            Text {
                anchors.centerIn: parent
                renderType: Text.NativeRendering
                text: styleData.value
            }
        }
        rowDelegate: Item {
            height: col.width
        }
    }
}
