## QQuickStylesExtras


Simple wrapper to QQuick Styles that is used to gather info on QQuick.Controls 2.0  Themes

Warning I am sure that this will not be around for that long as I am sure that QQuickStyles will get all this
in a non private file.

#### building

````
qmake
make
make install
````


#### Using it
Please see the example

works like so,

1)  Make a qtquickcontrols2.conf and add it to your qrc system
2)  (optional) In your main or where ever add QQuickStyle::setStyle("Material"); | or whatever theme you are using.
3)  make sure that the plugin is istalled (see building)


## getting it via qpm

coming soon
