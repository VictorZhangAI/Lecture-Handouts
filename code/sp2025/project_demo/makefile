CC=gcc
MAIN=main
OBJ= main.o\
     gcd.o\
     lcm.o
HEAD=main.c\
     gcd.h\
     lcm.h
CFLAGS= -g -Wall -Werror -std=c11

main: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(MAIN)
main.o: $(HEAD)
	$(CC) $(CFLAGS) -c main.c -o main.o
gcd.o: gcd.c
	$(CC) $(CFLAGS) -c gcd.c -o gcd.o
lcm.o: lcm.c gcd.h
	$(CC) $(CFLAGS) -c lcm.c -o lcm.o

.PHONY: clean
clean:
	rm -rf *.o main
