CC = gcc
CFLAGS = -g -Wall -lm

all: clean build

build: zig_zag.c
	$(CC) zig_zag.c ../utilities/*.h -o zig_zag  $(CFLAGS)
.PHONY : clean
clean:
	rm -f zig_zag