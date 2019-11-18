# BASIC
CC = g++
NAME = ts-timetracker
MAIN = main.cpp

# PATHS
HELPERSPATH = ./helpers
HELPERSHEADERPATH = $(HELPERSPATH)/headers

CONTROLLERSPATH = ./application/controllers
CONTROLLERSHEADERPATH = $(CONTROLLERSPATH)/headers

# FILES
HELPERHEADERS = \
    $(HELPERSHEADERPATH)/TS_Helper.h \
    $(HELPERSHEADERPATH)/TS_Info.h

HELPERS = \
    $(HELPERSPATH)/TS_Helper.cpp \
    $(HELPERSPATH)/TS_Info.cpp

CONTROLLERHEADERS = \
    $(CONTROLLERSHEADERPATH)/TS_Base.h \
    $(CONTROLLERSHEADERPATH)/TS_CommandDelegator.h

CONTROLLERS = \
    $(CONTROLLERSPATH)/TS_Base.cpp \
    $(CONTROLLERSPATH)/TS_CommandDelegator.cpp

# TESTS
TESTFILENAME = ts-test
TESTFILES = ./tests/TS_UnitTest.cpp

build:
	$(CC) -o $(NAME) $(MAIN) $(HELPERS) $(HELPERHEADERS) $(CONTROLLERS) $(CONTROLLERHEADERS)

test:
	$(CC) -o $(TESTFILENAME) $(TESTFILES)
