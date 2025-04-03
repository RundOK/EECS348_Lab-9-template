CC := g++
CFLAGS := -Wall

matrix.exe: main.o
	$(CC) $(CFLAGS) -o main.exe

matrix.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp