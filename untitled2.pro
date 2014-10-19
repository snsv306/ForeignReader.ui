#-------------------------------------------------
#
# Project created by QtCreator 2014-10-19T07:41:40
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mainprogram.cpp \
    translator.cpp

HEADERS  += mainwindow.h \
    mainprogram.h \
    translator.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    settings-icn2.png \
    Translate2.png

RESOURCES += \
    res.qrc
