#-------------------------------------------------
#
# Project created by QtCreator 2018-08-16T17:03:51
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ddu
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    IP/ipshow.cpp \
    Beeper/beeper.cpp \
    IP/changeip.cpp \
    Brightness/brightness.cpp \
    Badpoint/badpoint.cpp \
    IP/inputnum.cpp

HEADERS  += mainwindow.h \
    IP/ipshow.h \
    Beeper/beeper.h \
    IP/changeip.h \
    Brightness/brightness.h \
    Badpoint/badpoint.h \
    disphw32.h \
    windefs.h \
    IP/inputnum.h

FORMS    += mainwindow.ui \
    IP/ipshow.ui \
    Beeper/beeper.ui \
    IP/changeip.ui \
    Brightness/brightness.ui \
    Badpoint/badpoint.ui \
    IP/inputnum.ui

unix:!macx: LIBS += -L$$PWD/./ -lenvcon

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

unix:!macx: PRE_TARGETDEPS += $$PWD/./libenvcon.a

unix:!macx: LIBS += -L$$PWD/../../../../../lib/x86_64-linux-gnu/ -lexpat

INCLUDEPATH += $$PWD/../../../../../lib/x86_64-linux-gnu
DEPENDPATH += $$PWD/../../../../../lib/x86_64-linux-gnu
