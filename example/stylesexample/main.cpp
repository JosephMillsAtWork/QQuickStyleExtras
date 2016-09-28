#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // This is optional
    QQuickStyle::setStyle("Material");

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
