main: main.o String.o Tests.o
	g++ -o main main.o String.o Tests.o

String.o: String.cpp
	g++ -c String.cpp
	
Tests.o: Tests.cpp
	g++ -c Tests.cpp
	
main.o: main.cpp
	g++ -c main.cpp