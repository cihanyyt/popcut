#-------------------------------------------------
#
# Project created by QtCreator 2015-06-02T21:09:30
#
#-------------------------------------------------

QT       += core gui winextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = popCut

TEMPLATE = app

SOURCES +=    main.cpp \
              popcut.cpp

HEADERS  +=	popcut.h

FORMS    += popcut.ui



win32: LIBS += -lQt5WinExtrasd -lshell32
