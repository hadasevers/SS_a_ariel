
AR=ar
FLAGS= -Wall -g
OBJECTS_LIBLOOP=basicClassification.o advancedClassificationLoop.o
OBJECTS_LIBREC=basicClassification.o advancedClassificationRecursion.o


all: mains maindloop maindrec libclassloops.a libclassrec.a libclassrec.so libclassloops.so

mains: main.o libclassrec.a
	gcc $(FLAGS) -o mains main.o libclassrec.a -lm

maindloop: main.o libclassloops.so
	gcc $(FLAGS) -o maindloop main.o ./libclassloops.so -lm

maindrec: main.o libclassrec.so
	gcc $(FLAGS) -o maindrec main.o ./libclassrec.so -lm


loops: libclassloops.a
libclassloops.a: $(OBJECTS_LIBLOOP)
	$(AR) -rcs libclassloops.a $(OBJECTS_LIBLOOP)


recursives: libclassrec.a
libclassrec.a: $(OBJECTS_LIBREC)
	$(AR) -rcs libclassrec.a $(OBJECTS_LIBREC)


recursived: libclassrec.so
libclassrec.so: $(OBJECTS_LIBREC)
	gcc -shared -o libclassrec.so $(OBJECTS_LIBREC)


loopd: libclassloops.so
libclassloops.so: $(OBJECTS_LIBLOOP)
	gcc -shared -o libclassloops.so $(OBJECTS_LIBLOOP)


basicClassification.o: basicClassification.c NumClass.h
	gcc $(FLAGS) -c basicClassification.c 
advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	gcc $(FLAGS) -c advancedClassificationLoop.c
advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	gcc $(FLAGS) -c advancedClassificationRecursion.c
main.o: main.c NumClass.h
	gcc $(FLAGS) -c main.c
	

.PHONY: clean all

clean: 
	rm -f *.o *.a *.so mains maindloop maindrec




