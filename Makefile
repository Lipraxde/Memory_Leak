OUTEXE = main

.PHONY : all build clean

all: build

build: main.c
	cc $^ -g -lpthread -o $(OUTEXE)

clean:
	rm $(OUTEXE)
