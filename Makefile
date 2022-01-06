AR=ar
FLAGS= -Wall -g


all: graph


graph: main.o algo.o
	gcc $(FLAGS) -o graph main.o algo.o




algo.o: algo.c graph.h
	gcc $(FLAGS) -c algo.c


main.o: main.c graph.h
	gcc $(FLAGS) -c main.c



.PHONY: clean all

clean: 
	rm -f *.o *.a graph
