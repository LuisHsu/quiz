CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99
.PHONY: all clean test_iterative

EXEC = iterative recursive generator Time_test
SOURCE = iterative.c recursive.c generator.c Time_test.c
all: $(EXEC)

$(EXEC): $(SOURCE)
	$(CC) $(CFLAGS_common) -o $@ $@.c

clean:
	rm $(EXEC) *.o
