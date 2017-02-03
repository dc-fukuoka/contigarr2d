CC     = gcc
CFLAGS = -g -fpic -MMD -MP -Wall
LFLAGS = -shared
LIBS   =
OBJS   = contigarr2d.o
BIN    = libcontigarr2d.so

.SUFFIXES: .c.o
.PHONY: clean

ALL: $(BIN)

.c.o:
	$(CC) -c $(CFLAGS) $<

$(BIN): $(OBJS)
	$(CC) $(LFLAGS) $(LIBS) $^ -o $@

clean:
	rm -f *.o *.d *~ $(BIN)
