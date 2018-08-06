include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)
QT += testlib
QT -= gui
TARGET = client-tests
TEMPLATE = app

CONFIG += c++14
CONFIG += console
CONFIG -= app_bundle

INCLUDEPATH += source

SOURCES += source/models/tst_testcase1.cpp
DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/.ui
LIBS += -L$$PWD/../binaries/$$DESTINATION_PATH -lcm-lib
