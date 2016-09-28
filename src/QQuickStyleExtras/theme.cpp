#include "theme.h"


// IMPORTANT
// These method MUST be followed one by one


Theme::Theme(QObject *parent) : QObject(parent)
{
    // handel errors
    connect(this,SIGNAL(error(QString)),this,SLOT(handelErrorString(QString)));
    // set up all colors
    connect(this,SIGNAL(initSetupDone()),this,SLOT(setupColors()));
    connect( this,SIGNAL(colorsSet()),this,SLOT(setupPrimaryAccentColors()));

    setdefaultDarkAmmount(dDarkAmmount);
    setdefaultLightAmmount(dLightAmmount);

}


/*!
 \brief Theme::setUpIniReader
 Read the conf file and pass to signal that sets all things up.

  The conf file that is passed into this MUST be the full path and file name.
  if using a file that is in the file system and not in the qrc system.

  Example:
  /home/joseph/Themes/qtquickconstrols2.conf

  Else if you are using the qrc system pass it in with the : key

  Example:

  :/qtquickcontrols2.conf

*/
void Theme::setUpIniReader(const QString &confFile)
{


    QFile cFile(confFile) ;
    if( !cFile.open(QIODevice::ReadOnly | QIODevice::Text) )
    {
        error("Could not open up the Conf file that is needed to set the theme class up");
        return;
    }

    //FIXME  Check the file to see if there is a background primary ect here as a function
    // parseIniForPropertys(cFile);


    cFile.close();

    // set up the ini reader now
    QSettings iniReader(confFile, QSettings::IniFormat);

    // settheme(QQuickStyle::name());
    setthemePath(QQuickStyle::path());

    // Style read the ini file and get these propertys and values
    // [Controls]
    // Style=Material
    iniReader.beginGroup("Controls");
    settheme(iniReader.value("Style").toString());
    iniReader.endGroup();

    if(m_theme.isEmpty())
    {
        error("Controls Style field is not setup. Please fix your conf file ");
        return;
    }
    else
    {
        if ( !setPrimaryAccent( confFile , m_theme ) )
        {
            error("Was not able to set up all Primary and Secondary colors");
        }
        else
        {
            initSetupDone();
        }
    }
}




/*!
 \qmlproperty string Theme::errorString
  returns a error string (if any) when this singleton is set up.
 */
QString Theme::errorString() const
{
    return m_errorString;
}

QColor Theme::darkerShade(const QColor &color, const qreal &ammount)
{

    QColor hsl = color.toHsl();
    hsl.setHslF(hsl.hueF(), hsl.saturationF(), qBound<qreal>(0.0, hsl.lightnessF() - ammount, 1.0), color.alphaF());
    return hsl.convertTo(color.spec());
}

QColor Theme::lighterShade(const QColor &color, const qreal &ammount)
{

    QColor hsl = color.toHsl();
    hsl.setHslF(hsl.hueF(), hsl.saturationF(), qBound<qreal>(0.0, hsl.lightnessF() + ammount, 1.0), color.alphaF());
    return hsl.convertTo(color.spec());
}


bool Theme::setPrimaryAccent( QString cFiles, const QString &themeName)
{
    bool tempBool;
    QSettings ini(cFiles, QSettings::IniFormat);

    ini.beginGroup(themeName);

    if( ini.value("Theme").toString() == "Dark" )
    {
        setisDark(true);
    }
    else
    {
        setisDark(false);
    }


    setprimaryColorStr( ini.value("Primary").toString() );
    setaccentColorStr( ini.value("Accent").toString() );

    ini.endGroup();

    if( !m_primaryColorStr.isEmpty() && !m_accentColorStr.isEmpty() )
    {
        tempBool = true;
    }
    else
    {
        tempBool = false;
    }
    return tempBool;
}

void Theme::handelErrorString(const QString &err)
{
    if(m_errorString == err)
        return;
    m_errorString = err;
    emit errorStringChanged();
}


// This is the final step that is used to gathere the info about the colors
void Theme::setupColors()
{

    QColor red = m_theme == "Material" ?  "#F44336" : m_theme == "Universal" ? "#E51400" : "red";
    setRed(red );

    QColor pink = m_theme == "Material" ? "#E91E63" : m_theme == "Universal" ? "#F472D0" :  "pink";
    setPink( pink );

    QColor purple = m_theme == "Material" ? "#9C27B0"  :  "purple";
    setPurple(purple);

    QColor deepPurple = m_theme == "Material" ? "#673AB7" : "#673AB7";
    setDeepPurple(deepPurple );

    QColor indigo = m_theme == "Material" ? "#3F51B5" : m_theme == "Universal" ? "#6A00FF" : "indigo";
    setIndigo(indigo);

    QColor blue = m_theme == "Material" ? "#2196F3" : "blue";
    setBlue(blue );

    QColor lightBlue = m_theme == "Material" ? "#03A9F4" : "lightBlue";
    setLightBlue(lightBlue );

    QColor cyan = m_theme == "Material" ? "#00BCD4" : m_theme == "Universal" ? "#1BA1E2" : "cyan";
    setCyan(cyan );

    QColor teal = m_theme == "Material" ? "#009688" : m_theme == "Universal" ? "#00ABA9" : "teal";
    setTeal(teal);

    QColor green = m_theme == "Material" ? "#4CAF50" : m_theme == "Universal" ? "#60A917" : "green";
    setGreen(green);

    QColor lightGreen = m_theme == "Material" ? "#8BC34A" :  "lightGreen";
    setLightGreen(lightGreen);

    QColor lime = m_theme == "Material" ? "#CDDC39" : m_theme == "Universal" ? "#A4C400" : "lime";
    setLime(lime );

    QColor yellow = m_theme == "Material" ?  "#FFEB3B" : m_theme == "Universal" ? "#E3C800" :"yellow";
    setYellow(yellow);

    QColor amber = m_theme == "Material" ? "#FFC107" : m_theme == "Universal" ? "#F0A30A" : "amber";
    setAmber(amber);

    QColor orange = m_theme == "Material" ? "#FF9800" : m_theme == "Universal" ? "#FA6800" : "#FA6800";
    setOrange(orange);

    QColor deepOrange = m_theme == "Material" ? "#FF5722" :  "#FF5722";
    setDeepOrange(deepOrange);

    QColor brown = m_theme == "Material" ? "#795548" : m_theme == "Universal" ? "#825A2C" : "brown";
    setBrown(brown);

    QColor grey = m_theme == "Material" ? "#9E9E9E" : "grey";
    setGrey(grey);

    QColor blueGrey = m_theme == "Material" ? "#607D8B" : "#607D8B";
    setBlueGrey(blueGrey);

    // Only in universal
    QColor emerald = "#008A00";
    setEmerald(emerald);

    QColor colbaly  ="#3E65FF";
    setColbaly(colbaly);

    QColor violet = "#AA00FF";
    setViolet(violet );

    QColor magenta = "#D80073";
    setMagenta( magenta );

    QColor crimson = "#A20025";
    setCrimson(crimson);

    QColor olive = "#6D8764";
    setOlive(olive);

    QColor steel = "#647687";
    setSteel(steel );

    QColor mauve = "#76608A";
    setMauve(mauve );

    QColor taupe = "#87794E" ;
    setTaupe(taupe);





    // ok now that the colors are set it is time to finaly set up the primary and accect colors
    colorsSet();


}

void Theme::setupPrimaryAccentColors()
{

    setPrimaryColor( retPrim(m_primaryColorStr) );
    setAccentColor(retPrim(m_accentColorStr)); // :  lighterShade(retPrim(m_accentColorStr))
    settextColor(m_isDark ? "#fafafa" : "#303030");
    setsubTitleLightColor(m_isDark ? "#fafafa" : "#c3c3c3");
    setsubTextColor(m_textColor);

    //FIXME read the ini and make sure there is not custom shit going on
    if (m_theme == "Material" && m_isDark == true){ setbackgroundColor( backgroundColorDark); }
    if (m_theme == "Material" && m_isDark == false){ setbackgroundColor( backgroundColorLight); }


    if (m_theme == "Universal" && m_isDark == true){ setbackgroundColor( backgroundColorDark); }
    if (m_theme == "Universal" && m_isDark == false){ setbackgroundColor( backgroundColorLight); }



}



QColor Theme::retPrim(QString col)
{
    QColor color;
    if(col ==  "Red"){ m_theme == "Material" ? color = "#F44336" : m_theme == "Universal" ? color = "#E51400" : color = "red" ; }
    if(col ==  "Pink"){ m_theme == "Material" ? color = "#E91E63" : m_theme == "Universal" ? color = "#F472D0" :  color = "pink";}
    if(col ==  "Purple"){m_theme == "Material" ? color = "#9C27B0"  :  color = "purple";}
    if(col ==  "DeepPurple"){ m_theme == "Material" ? color = "#673AB7" : color = "#673AB7";}
    if(col ==  "Indigo" ){ m_theme == "Material" ? color = "#3F51B5" : m_theme == "Universal" ? color = "#6A00FF" : color = "indigo";}
    if(col ==  "Blue" ){ m_theme == "Material" ? color = "#2196F3" : color = "blue";}
    if(col ==  "LightBlue" ){m_theme == "Material" ? color = "#03A9F4" : color = "lightBlue";}
    if(col ==  "Cyan" ){   m_theme == "Material" ? color = "#00BCD4" : m_theme == "Universal" ? color = "#1BA1E2" : color = "cyan";}
    if(col ==  "Teal"){ m_theme == "Material" ? color = "#009688" : m_theme == "Universal" ? color = "#00ABA9" : color = "teal";}
    if(col ==  "Green" ){   m_theme == "Material" ? color = "#4CAF50" : m_theme == "Universal" ? color = "#60A917" : color = "green";}
    if(col ==  "LightGreen"){m_theme == "Material" ? color = "#8BC34A" : color = "lightGreen";}
    if(col ==  "Lime"){ m_theme == "Material" ? color = "#CDDC39" : m_theme == "Universal" ? color = "#A4C400" : color = "lime";}
    if(col ==  "Yellow"){ m_theme == "Material" ? color = "#FFEB3B" : m_theme == "Universal" ? color = "#E3C800" : color = "yellow";}
    if(col ==  "Amber"){  m_theme == "Material" ? color = "#FFC107" : m_theme == "Universal" ? color = "#F0A30A" : color = "amber";}
    if(col ==  "Orange"){ m_theme == "Material" ? color = "#FF9800" : m_theme == "Universal" ?color = "#FA6800" :color = "#FA6800";}
    if(col ==  "DeepOrange"){  m_theme == "Material" ? color = "#FF5722" :  "#FF5722";}
    if(col ==  "Brown"){  m_theme == "Material" ? color = "#795548" : m_theme == "Universal" ? color = "#825A2C" : color = "brown";}
    if(col ==  "Grey"){  m_theme == "Material" ? color = "#9E9E9E " : color ="grey";}
    if(col ==  "BlueGrey"){m_theme == "Material" ?color = "#607D8B" : color = "#607D8B";}
    // Only in universal
    if(col ==  "Emerald"){ color = "#008A00";}
    if(col ==  "Colbaly"){color = "#3E65FF";}
    if(col ==  "Violet"){ color = "#AA00FF";}
    if(col ==  "Magenta"){ color = "#D80073";}
    if(col ==  "Crimson"){color = "#A20025";}
    if(col ==  "Olive"){ color = "#6D8764";}
    if(col ==  "Steel"){ color = "#647687";}
    if(col ==  "Mauve"){ color = "#76608A";}
    if(col ==  "Taupe"){ color = "#87794E" ;}
    return color;

}

QColor Theme::alpha(const QColor color, const qreal &alpha)
{
    QColor aColor(color);
    aColor.setAlphaF(alpha);
    return aColor;
}

