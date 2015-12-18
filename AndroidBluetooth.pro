#-------------------------------------------------
#
# Project created by QtCreator 2014-04-24T17:50:04
#
#-------------------------------------------------

QT       += core gui androidextras widgets

TARGET = AndroidBluetooth

TEMPLATE = app

SOURCES += src/main.cpp\
        src/mainwidget.cpp\
        src/androidrfcomm.cpp

HEADERS  += src/mainwidget.h\
        src/androidrfcomm.h

FORMS    +=

CONFIG += mobility

MOBILITY = 

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

OTHER_FILES += android/AndroidManifest.xml

