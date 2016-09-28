## FIXME add docs but not sure how long this will be around.
#include(docs/doc.pri)
TEMPLATE = subdirs
CONFIG += ordered
SUBDIRS += \
    $$PWD/src \
    $$PWD/example
OTHER_FILES += \
    $$PWD/LICENSE \
    $$PWD/README.md

