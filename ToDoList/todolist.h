#ifndef TODOLIST_H
#define TODOLIST_H

#include <QObject>
#include <QVector>

struct ToDoItem
{
    bool done;
    QString description;
};

//class goal: add item, modify item, and remove item
class ToDoList : public QObject
{
    Q_OBJECT
public:
    explicit ToDoList(QObject *parent = nullptr);

    QVector< ToDoItem > items() const;

    bool setItemAt( int index, const ToDoItem &item );

signals:
  void preItemAppended();
  void postItemAppended();

  void preItemRemoved( int index );
  void postItemRemoved();

//qml can call theses
public slots:
  void appendItem();
  void removeCompletedItems();

private:
    QVector< ToDoItem > mItems;
};

#endif // TODOLIST_H
