TEMPLATE = app
TARGET = YTDownload

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x050F00

FORMS += \
    mainwindow.ui \
    settingswindow.ui

HEADERS += \
    mainwindow.h \
    settingswindow.h \
    yt.h

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    settingswindow.cpp \
    yt.cpp

RESOURCES += \
    resources.qrc
