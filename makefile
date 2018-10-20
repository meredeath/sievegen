all: sieve.c sieve.h
	gcc -g sieve.c -lm
run:
	./a.out
clean:
	rm *.o
