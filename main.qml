import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 300
    height: 400
    title: qsTr("Hello World")

    Table {
        width: parent.width
        height: parent.height
    }

}
