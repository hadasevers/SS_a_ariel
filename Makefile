
AR=ar
FLAGS= -Wall -g



all: connections libclasss.a


connections: main.o libclasss.a
	gcc $(FLAGS) -o connections main.o libclasss.a



runnings: libclasss.a
libclasss.a: my_mat.o
	$(AR) -rcs libclasss.a my_mat.o




my_mat.o: my_mat.c my_mat.h
	gcc $(FLAGS) -c my_mat.c

main.o: main.c my_mat.h
	gcc $(FLAGS) -c main.c




.PHONY: clean all

clean: 
	rm -f *.o *.a connections 
