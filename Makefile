CC=gcc

all:
	make main

main: main.o getaline.o strcpy/strcpy.o alloc/alloc.o
	$(CC) main.o getaline.o strcpy/strcpy.o alloc/alloc.o -o main

main.o: main.c getaline.o strcpy/strcpy.o alloc/alloc.o
	$(CC) -c main.c -o main.o

getaline.o: getaline.c getaline.h
	$(CC) -c getaline.c -o getaline.o

strcpy/strcpy.o: strcpy/strcpy.c strcpy/strcpy.h
	$(CC) -c strcpy/strcpy.c -o strcpy/strcpy.o

alloc/alloc.o: alloc/alloc.c alloc/alloc.h
	$(CC) -c alloc/alloc.c -o alloc/alloc.o

clean:
	rm *.o
	rm alloc/*.o
	rm strcpy/*.o
