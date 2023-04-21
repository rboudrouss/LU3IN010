BDIR = ./bin
CFLAGS=-lm -Wall
CC=gcc

main: loopcpu loopsys mytimes

%: %.c
	$(CC) -o $(BDIR)/$@ $@.c $(CFLAGS)
