CC = gcc
CFLAGS = -g -Wall -lm

all: clean build

build: nr_of_paths.c
	$(CC) nr_of_paths.c ../utilities/*.h -o nr_of_paths  $(CFLAGS)
.PHONY : clean
clean:
	rm -f nr_of_paths