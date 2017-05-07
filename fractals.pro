#-------------------------------------------------
#
# Project created by QtCreator 2017-05-06T10:13:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = fractals
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    juliaset.cpp

HEADERS  += mainwindow.h \
    juliaset.h

FORMS    += mainwindow.ui

CONFIG += c++14
