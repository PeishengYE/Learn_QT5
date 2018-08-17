import QtQuick 2.0
import assets 1.0
Item {

        property bool isCollapsed: true
        anchors {
            top: parent.top
            bottom: parent.bottom
            left: parent.left
        }

        Rectangle{

//            width: isCollapsed ? Style.widthNavigationBarCollapsed : Style.heightNavigationBarExpanded
            color: Style.colourNavigationBarBackground
            width:100

            Column {
                NavigationButton {
                                 iconCharacter: "\uf0c9"
                                 description: ""
                }
                NavigationButton {
                                  iconCharacter: "\uf015"
                                  description: "Dashboard"
                }
                NavigationButton {
                                 iconCharacter: "\uf234"
                                 description: "New Client"
                }
                NavigationButton {
                                 iconCharacter: "\uf002"
                                 description: "Find Client"
                }
            }

        }

}
