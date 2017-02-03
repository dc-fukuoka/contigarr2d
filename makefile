CC     = gcc
CFLAGS = -I./libcontigarr2d -g -MMD -MP -Wall
LFLAGS = -L./libcontigarr2d -Wl,-rpath=$(PWD)/libcontigarr2d
LIBS   = -lcontigarr2d
OBJS   = main.o
BIN    = a.out

.SUFFIXES: .c.o
.PHONY: clean

ALL: $(BIN)

$(LIBS):
	make -C libcontigarr2d

.c.o:
	$(CC) -c $(CFLAGS) $<

$(BIN): $(OBJS) $(LIBS)
	$(CC) $(LFLAGS) $(LIBS) $^ -o $@

clean:
	rm -f *.o *.d *~ $(BIN)
	make -C libcontigarr2d clean
