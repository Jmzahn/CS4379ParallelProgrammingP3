CC = gcc
LIB = -fopenmp

prog1: gaussOmp.c
	$(CC) $(LIB) gaussOmp.c -o gaussOmp

prog2: LUOmp.c
	$(CC) $(LIB) LUOmp.c -o LUOmp

all: 
	$(CC) $(LIB) gaussOmp.c -o gaussOmp
	$(CC) $(LIB) LUOmp.c -o LUOmp

clean:
	rm -f *.exe *.o