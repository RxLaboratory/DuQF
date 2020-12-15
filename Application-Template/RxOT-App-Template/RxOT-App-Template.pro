QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RxOT-App-Template
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    duqf-app/app-style.cpp \
    duqf-utils/language-utils.cpp \
    duqf-utils/utils.cpp \
    duqf-widgets/appearancesettingswidget.cpp \
    duqf-widgets/progressslider.cpp \
    duqf-widgets/settingswidget.cpp \
    duqf-widgets/sliderspinbox.cpp \
    duqf-widgets/toolbarspacer.cpp \
    main.cpp \
    mainwindow.cpp \
    testcustomwidgets.cpp \
    testwidgets.cpp

HEADERS += \
    duqf-app/app-style.h \
    duqf-app/app-utils.h \
    duqf-app/app-version.h \
    duqf-utils/language-utils.h \
    duqf-utils/utils.h \
    duqf-widgets/appearancesettingswidget.h \
    duqf-widgets/progressslider.h \
    duqf-widgets/settingswidget.h \
    duqf-widgets/sliderspinbox.h \
    duqf-widgets/toolbarspacer.h \
    mainwindow.h \
    testcustomwidgets.h \
    testwidgets.h

FORMS += \
    duqf-widgets/appearancesettingswidget.ui \
    duqf-widgets/settingswidget.ui \
    duqf-widgets/sliderspinbox.ui \
    duqf-widgets/toolbarspacer.ui \
    mainwindow.ui \
    testcustomwidgets.ui \
    testwidgets.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# OS Specific configurations
win* {
    # Add version and other metadata
    DISTFILES += app.rc
    RC_FILE = app.rc
    !build_pass:touch($$RC_FILE, DuF/version.h)
    # Enable console output
    CONFIG += console
} else:unix {
    # Fix issue with c++ version used to compile Qt in some distros (Ubuntu) with Qt <= 5.12.
    # Need to check the version of c++ used with distros providing Qt > 5.12
    equals(QT_MAJOR_VERSION, 5):lessThan(QT_MINOR_VERSION, 13):QMAKE_CXXFLAGS += "-fno-sized-deallocation"
} else:macx {
    # Just in case...
}

RESOURCES += \
    duqf_resources.qrc
