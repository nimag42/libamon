TEMPLATE = app
TARGET = build/libamon
DEPENDPATH += . include
INCLUDEPATH += . include

# Input
HEADERS += include/lbmw_setting.hpp \
           include/lbmw_tray.hpp \
           include/lbmc_utils.hpp \

SOURCES += src/main.cpp src/lbmw_setting.cpp src/lbmw_tray.cpp src/lbmc_utils.cpp
