CXX = g++
CXXFLAGS = -O2 -Wall -std=c++17
OBJS = build/main.o
PREFIX ?= /usr/local

build/learn_ex: $(OBJS)
	$(CXX) $(OBJS) -o build/learn_ex $(CXXFLAGS)

build/main.o: src/main.cpp
	mkdir -p build
	$(CXX) -c src/main.cpp -o build/main.o $(CXXFLAGS)

install: build/learn_ex
	mkdir -p ${PREFIX}/bin
	cp -f build/learn_ex ${PREFIX}/bin
	chmod 755 ${PREFIX}/bin/learn_ex

uninstall:
	rm -f ${PREFIX}/bin/learn_ex

clean:
	$(RM) $(OBJS) build/a
