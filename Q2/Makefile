CC = gcc
LIB = -fopenmp

prog: gaussOmp.c
	$(CC) $(LIB) gaussOmp.c -o gaussOmp

all: gaussOmp
	$(CC) $(LIB) gaussOmp.c -o gaussOmp

clean:
	rm -f *.exe *.o