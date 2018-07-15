CFLAGS = -std=c++11

all: show-cmd

show-cmd: show-cmd.cpp class_nono
	$(CXX) $(CFLAGS) -o show-cmd.out show-cmd.cpp class_nono.o

class_nono: class_nono.hpp
	$(CXX) $(CFLAGS) -c class_nono.cpp
