QT -= gui
TARGET = cm-lib
TEMPLATE = lib
CONFIG += c++14
DEFINES += CMLIB_LIBRARY
INCLUDEPATH += source

SOURCES += source/models/client.cpp \
    source/controllers/master-controller.cpp

HEADERS += source/cm-lib_global.h \
    source/models/client.h \
    source/controllers/master-controller.h