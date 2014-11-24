CC=gcc
FLAGS=-Wall -std=c99
PROGRAMS=db.c db.h main.c

main: main.o db.o
	gcc $(FLAGS) main.o db.o -o main -pg
main.o: main.c db.h
	gcc $(FLAGS) -c main.c
db.o: db.c 
	gcc $(FLAGS) -c db.c
run: main
	./main SWE.db

test: unittests.c db.c db.h
	$(CC) $(FLAGS) unittests.c db.c -o unittests -lcunit
	./unittests
clean: 
	$(RM) *.o *~ $(main)
