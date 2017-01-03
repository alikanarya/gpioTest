QT += core
QT -= gui
QT += network

CONFIG += c++11

TARGET = gpioTest
target.files = gpioTest
target.path=/root

INSTALLS += target
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    client.cpp \
    server.cpp \
    gpiothread.cpp

HEADERS += \
    client.h \
    server.h \
    globals.h \
    gpiothread.h
