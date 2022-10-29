CC=gcc
CFLAGS=-Wall -o
CFILES=allduty.c
OUTFILES=allduty

all:
	make build
	make run

build:
	$(CC) $(CFLAGS) $(OUTFILES) $(CFILES)
	gcc -Wall -o duty momduty.c duty.c
	gcc -Wall -o tinkoffduty tinkoffduty.c

run:
	./$(OUTFILES)