import QtQuick 2.7
import QtQuick.Window 2.2

import QtQuick.Controls 2.0
import QQuickStyleExtras 1.0

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Quick Style Extras Example" )
    color: Theme.backgroundColor
    // this should be in main or plugin. But for exxample wanted to show 1st steps
    Component.onCompleted: Theme.setUpIniReader(":/qtquickcontrols2.conf")

    Text {
        id: title
        text: qsTr("%1").arg(Theme.theme)
        color: Theme.textColor
        font.pixelSize: 32
    }

    Row{
        height: parent.height - (title.paintedHeight*2)
        width: parent.width / 1.07
        anchors{
            top: title.bottom
            bottomMargin: title.paintedHeight*2
            horizontalCenter: parent.horizontalCenter
        }
        Rectangle{
            width: parent.width/ 2
            height: parent.height
            color: Theme.lighterShade(Theme.AccentColor, Theme.defaultLightAmmount )
            Text {
                anchors.fill: parent
                text: qsTr("Lighter Shade of AccentColor \n Accent Color = %1" ).arg(Theme.accentColorStr)
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: Theme.isDark ? Theme.darkerShade(Theme.BlueGrey, 0.54) : Theme.textColor
            }
        }

        Rectangle{
            width: parent.width/ 2
            height: parent.height
            color: Theme.PrimaryColor
            Text {
                anchors.fill: parent
                text: "Primary Color  = "  + Theme.primaryColorStr
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: Theme.textColor
            }
        }
    }


    Connections{
        target: Theme
        onColorsSet: console.log("QQuickStylesExtras is set up")
    }
}
