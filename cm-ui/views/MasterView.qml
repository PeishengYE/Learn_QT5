import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Client Management")
//    StackView {
//        id: contentFrame
//        initialItem: "qrc:/views/SplashView.qml"
//    }

    Text {
//        text: "Welcome to the Client Management system!"
        text: masterController.ui_welcomeMessage
        font {
                    bold: true
                    pointSize: 34
                }

    }
}
