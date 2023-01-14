import QtQuick 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0

import ToDo 1.0

ColumnLayout {

    Frame {
        Layout.fillWidth: true

        //needs size, model, and delegate
        ListView {
            implicitHeight: 250
            implicitWidth: 250

            anchors.fill: parent

            //forces model to be inside of listview
            clip: true

            //model: 100
            /*
            model: ListModel {
                ListElement {
                    done: true
                    description: "Task"
                }
                ListElement {
                    done: false
                    description: "Task"
                }
            }
            */
            model: ToDoModel {
                list: toDoList
            }

            delegate: RowLayout {
                width: parent.width

                CheckBox {
                    checked: model.done
                    onClicked: model.done = checked
                }
                TextField {
                    Layout.fillWidth: true
                    text: model.description
                    onEditingFinished: model.description = text
                }
            }
        }
    }

    RowLayout {
      Button {
        text: qsTr("Add new item")
        Layout.fillWidth: true
        onClicked: toDoList.appendItem()
      }

      Button {
        text: qsTr( "Remove Completed")
        Layout.fillWidth: true
        onClicked: toDoList.removeCompletedItems()
      }
    }
}
