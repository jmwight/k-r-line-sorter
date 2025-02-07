CC = gcc
ARGS = -Wall
OBJ = main.o getaline.o strcpy/strcpy.o alloc/alloc.o alloc/readwritelines.o
DEBUG = -g # add -g to make a symbol list so GDB will work. If you don't want it remove the -g from the Makefile

line-sorter: $(OBJ)
	$(CC) $(DEBUG) $(OBJ) -o line-sorter $(ARGS)

main.o: main.c getaline.h alloc/readwritelines.h
	$(CC) $(DEBUG) -c main.c -o main.o $(ARGS)

getaline.o: getaline.c getaline.h
	$(CC) $(DEBUG) -c getaline.c -o getaline.o $(ARGS)

strcpy/strcpy.o: strcpy/strcpy.c strcpy/strcpy.h
	$(CC) $(DEBUG) -c strcpy/strcpy.c -o strcpy/strcpy.o $(ARGS)

alloc/readwritelines.o: alloc/readwritelines.c alloc/readwritelines.h alloc/alloc.h strcpy/strcpy.h
	$(CC) $(DEBUG) -c alloc/readwritelines.c -o alloc/readwritelines.o $(ARGS)

alloc/alloc.o: alloc/alloc.c alloc/alloc.h
	$(CC) $(DEBUG) -c alloc/alloc.c -o alloc/alloc.o $(ARGS)

.PHONY: clean
clean:
	rm -rf line-sorter $(OBJ)
