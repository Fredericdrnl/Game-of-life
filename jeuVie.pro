TEMPLATE = app
TARGET = name_of_the_app

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    Main.cpp \
    gestion.cpp \
    mainwindow.cpp \
    mascene.cpp \
    monrect.cpp \
    stats.cpp \
    tableau.cpp

HEADERS += \
    gestion.h \
    mainwindow.h \
    mascene.h \
    monrect.h \
    stats.h \
    tableau.h
