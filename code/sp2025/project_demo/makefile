CC=gcc
CFLAGS=-std=c11 -w
OBJ=main.o\
    gcd.o\
    lcm.o\
    score.o
HEADER=gcd.h\
       lcm.h\
       score.h

main: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o main
main.o: $(HEADER)
	$(CC) $(CFLAGS) -c main.c -o main.o
gcd.o: $(HEADER)
	$(CC) $(CFLAGS) -c gcd.c -o gcd.o
lcm.o: $(HEADER)
	$(CC) $(CFLAGS) -c lcm.c -o lcm.o
score.o:
	$(CC) $(CFLAGS) -c score.c -o score.o

.PHONY: clean
clean:
	rm -rf $(OBJ) main
