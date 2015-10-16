CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99

EXEC = iterative recursive Time_test generator
SOURCE = iterative.c recursive.c Time_test.c generator.c

all: $(EXEC)

$(EXEC): $(SOURCE)
	$(CC) $(CFLAGS_common) -o $@ $@.c

clean:
	$(RM) $(EXEC) *.o 
