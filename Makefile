# Term Snake

CC = g++
CFLAGS = -std=c++14 -Wall

all: bin/ts.exe

# Components

obj/main.o: src/main.cpp
	$(CC) $(CFLAGS) -o obj/main.o -c src/main.cpp

obj/term.o: src/term.cpp src/term.hpp
	$(CC) $(CFLAGS) -o obj/term.o -c src/term.cpp

TS_BLOCKS = obj/term.o obj/main.o

bin/ts.exe: $(TS_BLOCKS) src/ts.cpp
	$(CC) $(CFLAGS) -o bin/ts.exe src/ts.cpp $(TS_BLOCKS)
