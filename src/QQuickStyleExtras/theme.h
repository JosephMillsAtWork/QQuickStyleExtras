#ifndef THEME_H
#define THEME_H

#include <QObject>
#include <QString>
#include <QColor>
#include <QSettings>
#include <QFile>
#include <QQuickStyle>



#include "QQmlConstRefPropertyHelpers.h"

// material
static const QRgb backgroundColorLight = 0xFFFAFAFA;
static const QRgb backgroundColorDark = 0xFF303030;


class Theme : public QObject
{
    Q_OBJECT

    QML_READONLY_CSTREF_PROPERTY(qreal, defaultLightAmmount )
    QML_READONLY_CSTREF_PROPERTY(qreal, defaultDarkAmmount )

//    QML_READONLY_CSTREF_PROPERTY(QString, )
    QML_READONLY_CSTREF_PROPERTY(QString, theme)
    QML_READONLY_CSTREF_PROPERTY(QString, themePath)
    QML_READONLY_CSTREF_PROPERTY(bool , isDark)

    QML_READONLY_CSTREF_PROPERTY(QString , primaryColorStr)
    QML_READONLY_CSTREF_PROPERTY(QColor , PrimaryColor)

    QML_READONLY_CSTREF_PROPERTY(QString , accentColorStr)
    QML_READONLY_CSTREF_PROPERTY(QColor , AccentColor)

    QML_READONLY_CSTREF_PROPERTY(QColor , backgroundColor)
    QML_READONLY_CSTREF_PROPERTY(QColor , tabHighlightColor)
    QML_READONLY_CSTREF_PROPERTY(QColor , textColor)
    QML_READONLY_CSTREF_PROPERTY(QColor , subTextColor)
    QML_READONLY_CSTREF_PROPERTY(QColor , subTitleLightColor)

    QML_READONLY_CSTREF_PROPERTY(QColor , iconColor)


    QML_READONLY_CSTREF_PROPERTY(QColor , Red)
    QML_READONLY_CSTREF_PROPERTY(QColor , Pink)
    QML_READONLY_CSTREF_PROPERTY(QColor , Purple)
    QML_READONLY_CSTREF_PROPERTY(QColor , DeepPurple)
    QML_READONLY_CSTREF_PROPERTY(QColor , Indigo)
    QML_READONLY_CSTREF_PROPERTY(QColor , Blue )
    QML_READONLY_CSTREF_PROPERTY(QColor , LightBlue)
    QML_READONLY_CSTREF_PROPERTY(QColor , Cyan)
    QML_READONLY_CSTREF_PROPERTY(QColor , Teal )
    QML_READONLY_CSTREF_PROPERTY(QColor , Green)
    QML_READONLY_CSTREF_PROPERTY(QColor , LightGreen)
    QML_READONLY_CSTREF_PROPERTY(QColor , Lime)
    QML_READONLY_CSTREF_PROPERTY(QColor , Yellow)
    QML_READONLY_CSTREF_PROPERTY(QColor , Amber)
    QML_READONLY_CSTREF_PROPERTY(QColor , Orange)
    QML_READONLY_CSTREF_PROPERTY(QColor , DeepOrange)
    QML_READONLY_CSTREF_PROPERTY(QColor , Brown)
    QML_READONLY_CSTREF_PROPERTY(QColor , Grey)
    QML_READONLY_CSTREF_PROPERTY(QColor , BlueGrey)
    QML_READONLY_CSTREF_PROPERTY(QColor , Emerald)
    QML_READONLY_CSTREF_PROPERTY(QColor , Colbaly )
    QML_READONLY_CSTREF_PROPERTY(QColor , Violet)
    QML_READONLY_CSTREF_PROPERTY(QColor , Magenta)
    QML_READONLY_CSTREF_PROPERTY(QColor , Crimson)
    QML_READONLY_CSTREF_PROPERTY(QColor , Olive)
    QML_READONLY_CSTREF_PROPERTY(QColor , Steel)
    QML_READONLY_CSTREF_PROPERTY(QColor , Mauve)
    QML_READONLY_CSTREF_PROPERTY(QColor , Taupe)





    Q_PROPERTY(QString errorString READ errorString NOTIFY errorStringChanged)

public:
    explicit Theme(QObject *parent = 0);


    QString matchDarkColor(const QString &strColor);
    QString errorString()const;
    Q_INVOKABLE QColor darkerShade(const QColor &color, const qreal &ammount);
    Q_INVOKABLE QColor lighterShade(const QColor &color,const qreal &ammount);
    Q_INVOKABLE void setUpIniReader(const QString &confFile);



    bool setPrimaryAccent(QString cFiles ,const QString &themeName);

    QColor retPrim(QString col);
    Q_INVOKABLE QColor alpha(const QColor color,const qreal &alpha);


    const qreal dLightAmmount = 0.26;
    const qreal dDarkAmmount = 0.26;

signals:

    void error(QString);
    void errorStringChanged();
    void initSetupDone();
    void colorsSet();
protected slots:
    void handelErrorString(const QString &err);
    void setupColors();
    void setupPrimaryAccentColors();

private:
    QString m_errorString;
};

#endif // THEME_H
