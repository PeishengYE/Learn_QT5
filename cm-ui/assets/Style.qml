pragma Singleton
import QtQuick 2.9


Item {
 property alias fontAwesome:    fontAwesomeLoader.name

    property color colourBackground: "#efefef"
    FontLoader {
        id: fontAwesomeLoader
        source: "qrc:/assets/fontawesome.ttf"
    }
}
