QT = core widgets
TEMPLATE = app
TARGET = life-log

INCLUDEPATH += src/ include/

# Input
SOURCES += src/*.cpp
HEADERS += src/*.hpp include/*.h

#output
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
