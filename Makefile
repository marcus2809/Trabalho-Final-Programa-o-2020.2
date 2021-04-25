ALL: main

main: main.o arvore.o lista.o vetor_bb.o vetor.o
	gcc main.o arvore.o lista.o vetor_bb.o vetor.o -o main

main.o: main.c arvore.h lista.h vetor_bb.h vetor.h
	gcc -c main.c

arvore.o: arvore.c arvore.h
	gcc -c arvore.c

lista.o: lista.c lista.h
	gcc -c lista.c

vetor_bb.o: vetor_bb.c vetor_bb.h
	gcc -c vetor_bb.c

vetor.o: vetor.c vetor.h
	gcc -c vetor.c

clean:
	rm -f *.o main