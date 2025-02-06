CC = gcc
ARGS = -Wall
OBJS = main.o getaline.o strcpy/strcpy.o alloc/alloc.o

main: $(OBJS)
	$(CC) main.o getaline.o strcpy/strcpy.o alloc/alloc.o -o main $(ARGS)

main.o: main.c getaline.o strcpy/strcpy.o alloc/alloc.o
	$(CC) -c main.c -o main.o $(ARGS)

getaline.o: getaline.c getaline.h
	$(CC) -c getaline.c -o getaline.o $(ARGS)

strcpy/strcpy.o: strcpy/strcpy.c strcpy/strcpy.h
	$(CC) -c strcpy/strcpy.c -o strcpy/strcpy.o $(ARGS)

alloc/alloc.o: alloc/alloc.c alloc/alloc.h
	$(CC) -c alloc/alloc.c -o alloc/alloc.o $(ARGS)

clean:
	rm main $(OBJS)
