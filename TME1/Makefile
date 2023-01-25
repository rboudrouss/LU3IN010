BDIR = ./bin/
CFLAGS=-lm -Wall
CC=gcc

max:
	$(CC) -o $(BDIR)$@ $@.c $(CFLAGS)

tab: tab.c tab.h
	$(CC) -o $(BDIR)$@ $^ $(CFLAGS)

# $(BDIR)%.o: %.c %.h
# 	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f vgcore* bin/* *.log