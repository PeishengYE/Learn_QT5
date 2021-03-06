import QtQuick 2.9
import assets 1.0
Item {
    property alias iconCharacter: textIcon.text
    property alias description: textDescription.text
    width: parent.width
    height: Style.heightNavigationButton
    signal navigationButtonClicked()
    property color hoverColour: Style.colourNavigationBarHoverBackground



    Rectangle {
        id: background
        anchors.fill: parent
        color: Style.colourNavigationBarBackground
        states: [
            State {        name: "hover"
                PropertyChanges {
                    target: background
                    color: hoverColour
                }
            }
        ]
        Row {
            Text {
                id: textIcon
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                width: Style.widthNavigationButtonIcon
                height: Style.heightNavigationButtonIcon
                font {
                    family: Style.fontAwesome
                    pixelSize: Style.pixelSizeNavigationBarIcon
                }

                color: Style.colourNavigationBarFont
                text: "\uf11a"
            }

            Text {
                id: textDescription
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: Style.pixelSizeNavigationBarText
                width: Style.widthNavigationButtonDescription
                height: Style.heightNavigationButtonDescription
                color: Style.colourNavigationBarFont
                text: "SET ME!!"
            }
        }

    MouseArea {
        anchors.fill: parent
        cursorShape: Qt.PointingHandCursor
        hoverEnabled: true
        onEntered: background.state = "hover"
        onExited: background.state = ""
        onClicked: navigationButtonClicked()}
    }
}
