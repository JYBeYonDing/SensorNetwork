#-------------------------------------------------
#
# Project created by QtCreator 2018-10-29T16:28:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SensorNetwork
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    Main (2).cpp \
    Main (2).cpp \
    Main2.cpp \
    Bigscene.cpp \
    Centeritem.cpp \
    Mainwindow.cpp \
    Network.cpp \
    Node.cpp \
    Smallscene.cpp \
    event_handle.cpp \
    event_manage.cpp \
    event_handle.cpp \
    event_manage.cpp \
    light_adhoc.cpp \
    main2.cpp

HEADERS += \
    Light_AdHoc.h \
    Bigscene.h \
    Centeritem.h \
    Mainwindow.h \
    Network.h \
    Node.h \
    Smallscene.h \
    event_manage.h \
    event_handle.h \
    event_manage.h \
    light_adhoc.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    center.qrc
