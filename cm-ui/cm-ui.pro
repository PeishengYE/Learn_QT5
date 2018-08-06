QT += qml quick

TEMPLATE = app

CONFIG += c++14
INCLUDEPATH += source \
    ../cm-lib/source

SOURCES += source/main.cpp

RESOURCES += views.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = $$PWD

LIBS += -L$$PWD/../../build-cm-Desktop_Qt_5_10_0_GCC_64bit-Debug//cm-lib -lcm-lib
