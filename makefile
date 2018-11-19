all: main.o 
	gcc main.o

a.out: main.o
	gcc main.o

main.o: main.c 
	gcc -c main.c

run: a.out
	./a.out

clean: main.c
	rm *.o

