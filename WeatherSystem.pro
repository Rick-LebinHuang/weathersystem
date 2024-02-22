QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    citynamelineedit.cpp \
    filehelper.cpp \
    main.cpp \
    weatherbackground.cpp \
    weathericonmapper.cpp \
    widget.cpp

HEADERS += \
    citynamelineedit.h \
    filehelper.h \
    weatherbackground.h \
    weathericonmapper.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    picture/Drizzle.png \
    picture/Mist.png \
    picture/Snow.png \
    picture/Squalls.png \
    picture/Thunderstorm.png

RESOURCES += \
    resources.qrc
