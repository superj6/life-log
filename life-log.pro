QT = core widgets
TEMPLATE = app
TARGET = life-log

INCLUDEPATH += src/

# Input
SOURCES += src/*.cpp
HEADERS += src/*.hpp

#output
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
