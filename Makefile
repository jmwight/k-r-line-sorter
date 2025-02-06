CC = gcc
ARGS = -Wall
OBJS = main.o getaline.o strcpy/strcpy.o alloc/alloc.o
DEBUG = -g # add -g to make a symbol list so GDB will work. If you don't want it remove the -g from the Makefile

line-sorter: $(OBJS)
	$(CC) $(DEBUG) main.o getaline.o strcpy/strcpy.o alloc/alloc.o -o line-sorter $(ARGS)

main.o: main.c getaline.o strcpy/strcpy.o alloc/alloc.o
	$(CC) $(DEBUG) -c main.c -o main.o $(ARGS)

getaline.o: getaline.c getaline.h
	$(CC) $(DEBUG) -c getaline.c -o getaline.o $(ARGS)

strcpy/strcpy.o: strcpy/strcpy.c strcpy/strcpy.h
	$(CC) $(DEBUG) -c strcpy/strcpy.c -o strcpy/strcpy.o $(ARGS)

alloc/alloc.o: alloc/alloc.c alloc/alloc.h
	$(CC) $(DEBUG) -c alloc/alloc.c -o alloc/alloc.o $(ARGS)

.PHONY: clean
clean:
	rm -rf line-sorter $(OBJS)
