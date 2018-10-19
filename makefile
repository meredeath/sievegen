all: sieve.o
	gcc -g sieve.o
sieve.o: sieve.c sieve.h
	gcc -c sieve.c
run:
	./a.out
clean:
	rm *.o
