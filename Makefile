WX_CONFIG := wx-config
WX_CXXFLAGS := $(shell $(WX_CONFIG) --cxxflags)
WX_LIBS := $(shell $(WX_CONFIG) --libs)
CXX := g++
BUILD := obj
SOURCE := src

PROGAM_EXEC := system-login

OBJECTS := $(BUILD)/main.o $(BUILD)/login.o $(BUILD)/register.o $(BUILD)/file.o

all: build main

#$(BUILD)/main.o: main.cpp
#	$(CXX) -g -Wall -c main.cpp -o $(BUILD)/main.o
#
#$(BUILD)/login.o: login.cpp
#	$(CXX) -g -Wall -c login.cpp -o $(BUILD)/login.o
#
#$(BUILD)/register.o: register.cpp
#	$(CXX) -g -Wall -c register.cpp -o $(BUILD)/register.o
#
#$(BUILD)/file.o: file.cpp
#	$(CXX) -g -Wall $(LDFLAGS) -c file.cpp -o $(BUILD)/file.o
#

main: $(OBJECTS)
	$(CXX) -g -o $(PROGAM_EXEC) $(OBJECTS) $(LDFLAGS) $(WX_LIBS) $(LIBS)

$(OBJECTS): $(BUILD)/%.o: $(SOURCE)/%.cpp
	$(CXX) -g -c -o $@ $(WX_CXXFLAGS) $(CXXFLAGS) $<

clean:
	rm -rf $(PROGAM_EXEC) $(BUILD)

build:
	mkdir -p $(BUILD)

.PHONY: clean build
