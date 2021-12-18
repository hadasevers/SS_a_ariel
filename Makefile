
AR=ar
FLAGS= -Wall -g
OBJECTS= my_gimatric.o my_atbash.o my_anagram.o 


all: stringProg


stringProg: main.o my_gimatric.o my_atbash.o my_anagram.o
	gcc $(FLAGS) -o stringProg main.o my_gimatric.o my_atbash.o my_anagram.o





my_anagram.o: my_anagram.c main.h
	gcc $(FLAGS) -c my_anagram.c

my_atbash.o: my_atbash.c main.h
	gcc $(FLAGS) -c my_atbash.c

my_gimatric.o: my_gimatric.c main.h
	gcc $(FLAGS) -c my_gimatric.c

main.o: main.c main.h
	gcc $(FLAGS) -c main.c



.PHONY: clean all

clean: 
	rm -f *.o *.a stringProg
