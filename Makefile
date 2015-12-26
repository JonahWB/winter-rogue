CXX=g++
CXXFLAGS=-g -Wall -std=c++11 -pedantic
rw: *.cpp *.h
	g++ *.cpp -o rw -std=c++11 

clean:
	rm rw
