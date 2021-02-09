QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
win32:contains(QMAKE_HOST.arch, x86):{
QMAKE_LFLAGS *= /MACHINE:X86
}
win32:contains(QMAKE_HOST.arch, x86_64):{
QMAKE_LFLAGS *= /MACHINE:X64
}
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    newproject.cpp \
    renderer.cpp

HEADERS += \
    mainwindow.h \
    newproject.h \
    renderer.h \
    utils/utils.h

FORMS += \
    mainwindow.ui \
    newproject.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
unix:LIBS += -lGLEW  -lglfw -lGL -lX11 -lpthread -lXrandr -lreactphysics3d
win32:LIBS += -lglfw3 -lglew32 -lopengl32 -lglu32
win32:contains(QMAKE_HOST.arch, x86_64):{
    CONFIG(release, debug|release) {
        win32:LIBS += -lreactphysics3d
    }
    CONFIG(debug, debug|release) {
        win32:LIBS += -lreactphysics3dD
    }
}

RESOURCES += \
    resources.qrc
