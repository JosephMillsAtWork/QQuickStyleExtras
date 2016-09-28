#ifndef QQUICKSTYLEEXTRAS_PLUGIN_H
#define QQUICKSTYLEEXTRAS_PLUGIN_H

#include <QQmlExtensionPlugin>






class QQuickStyleExtrasPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif // QQUICKSTYLEEXTRAS_PLUGIN_H
