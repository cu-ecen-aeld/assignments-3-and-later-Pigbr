# Default compiler
CC ?= gcc

# Cross-compiler setup
CROSS_COMPILE ?= aarch64-none-linux-gnu-

CFLAGS = -Wall
LDFLAGS =

# Use the cross-compiler if CROSS_COMPILE is set
CC = $(CROSS_COMPILE)gcc

all: writer

writer: writer.o
	$(CC) $(LDFLAGS) -o writer writer.o

clean:
	rm -f writer *.o
