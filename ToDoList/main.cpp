#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext> //allow class to "see" qml

#include "todolist.h"
#include "todomodel.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    //Allows qml to see type
    qmlRegisterType<ToDoModel>( "ToDo", 1, 0, "ToDoModel" );

    qmlRegisterUncreatableType<ToDoList>("ToDo", 1, 0, "ToDoList"
                                        , QStringLiteral( "ToDoList should not be created in QML") );

    ToDoList toDoList;

    QQmlApplicationEngine engine;

    //expose object to qml
    engine.rootContext()->setContextProperty( QStringLiteral("toDoList"), &toDoList );

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
