SOURCES=$(wildcard src/*.cpp)

OBJS=$(patsubst src/%.cpp,build/%.o,$(SOURCES))

CXXFLAGS ?=

main: build $(OBJS)
	$(CXX) $(CXXFLAGS) -o main $(OBJS)

debug: clean
	CXXFLAGS=-g $(MAKE)
	gdb ./main

build:
	mkdir build

build/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	rm -rf build main

.PHONY: remake
remake: clean main
