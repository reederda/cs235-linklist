CC = g++
CFLAGS = -g -Wall -std=c++11

default: lab6

lab6: LinkedList.o main.o
	$(CC) $(CFLAGS) -o lab5 LinkedList.o main.o

LinkedList.o: LinkedList.cpp LinkedList.h LinkedListInterface.h 
	$(CC) $(CFLAGS) -c LinkedList.cpp

main.o: main.cpp LinkedList.h 
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) lab5 *.o *.~
