#include "qquickstyleextras_plugin.h"
#include "theme.h"
#include <qqml.h>



static QObject *themeSingle(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)
    Theme *themeExtra = new Theme();
    return themeExtra;
}


void QQuickStyleExtrasPlugin::registerTypes(const char *uri)
{
    // @uri QQuickStyleExtras
    qmlRegisterSingletonType<Theme>(uri, 1, 0, "Theme", themeSingle);
}

