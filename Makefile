
#Makefile


CXX = clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -o2
DEBUG=-g

TARGETS = traveling.o middleearth.o


a.out: $(TARGETS)
	$(CXX) $(DEBUG) $(TARGETS) -o a.out
		doxygen -g




traveling.o: traveling.cpp
middleearth.o: middleearth.cpp middleearth.h




.PHONY: clean
clean:
	-rm -f *.o *~a.out
