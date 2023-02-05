WX_CONFIG := wx-config
WX_CXXFLAGS := $(shell $(WX_CONFIG) --cxxflags)
WX_LIBS := $(shell $(WX_CONFIG) --libs)
CXX := g++

PROGAM_EXEC := system-login

OBJECTS := main.o login.o register.o file.o

main: $(OBJECTS)
	$(CXX) -g -o $(PROGAM_EXEC) $(OBJECTS) $(LDFLGAS) $(WX_LIBS) $(LIBS)

$(OBJECTS): %.o: %.cpp
	$(CXX) -g -c -o $@ $(WX_CXXFLAGS) $(CXXFLAGS) $<

clean:
	rm -rf $(PROGAM_EXEC) $(OBJECTS)

.PHONY: clean
