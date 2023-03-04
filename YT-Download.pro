TEMPLATE = app
TARGET = YTDownload

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

FORMS += \
    mainwindow.ui \
    settingswindow.ui

HEADERS += \
    mainwindow.h \
    settingswindow.h

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    settingswindow.cpp
