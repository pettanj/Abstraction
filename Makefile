CC=gcc
FLAGS=-Wall -ggdb -std=c99
PROGRAMS=db.c db.h main.c

main: main.o db.o
	gcc $(FLAGS) main.o db.o -o main
main.o: main.c db.h
	gcc $(FLAGS) -c main.c
db.o: db.c 
	gcc $(FLAGS) -c db.c
run: main
	./main SWE.db

clean: 
	$(RM) *.o *~ $(main)
