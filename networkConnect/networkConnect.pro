#-------------------------------------------------
#
# Project created by QtCreator 2016-12-04T12:16:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = networkConnect
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp\
        wireless/iwlist.c\
        wireless/iwconfig.c\
        wireless/iwevent.c\
        wireless/iwgetid.c\
        wireless/iwlib.c\
#        wireless/iwpriv.c\
#        wireless/iwspy.c\
#        wireless/macaddr.c\
#        wireless/sample_enc.c\
#        wireless/sample_pm.c\
#        wireless/sample_priv_addr.c

HEADERS  += dialog.h\
#    wireless/CHANGELOG.h\
    wireless/iwlib.h\
#    wireless/wireless.10.h\
#    wireless/wireless.11.h\
#    wireless/wireless.12.h\
#    wireless/wireless.13.h\
#    wireless/wireless.14.h\
#    wireless/wireless.15.h\
    wireless/wireless.h

FORMS    += dialog.ui

RESOURCES += \
    img.qrc
