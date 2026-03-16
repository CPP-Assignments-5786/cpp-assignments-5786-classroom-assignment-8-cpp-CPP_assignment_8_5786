CXX=g++
CXXFLAGS=-std=c++23 -Werror -Wsign-conversion

# All code is in header files (templates + metaprogramming)

all: demo
	./demo

demo: main.o
	$(CXX) $(CXXFLAGS) $^ -o demo

test: TestRunner.o
	$(CXX) $(CXXFLAGS) $^ -o test
	./test

TestRunner.o: test.cpp TypeInfo.hpp MySwap.hpp Formatter.hpp Derivative.hpp PhysicsUnits.hpp DecltypeUtils.hpp doctest.h
	$(CXX) $(CXXFLAGS) --compile test.cpp -o TestRunner.o

main.o: main.cpp TypeInfo.hpp MySwap.hpp Formatter.hpp Derivative.hpp PhysicsUnits.hpp DecltypeUtils.hpp
	$(CXX) $(CXXFLAGS) --compile main.cpp -o main.o

clean:
	rm -f *.o demo test