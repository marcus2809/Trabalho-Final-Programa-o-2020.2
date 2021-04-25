#include <stdio.h>
#include "./vetor.h"

// cria um vetor que irá receber os elementos ordenados da árvore
int* criar_vetor(int tam){
	int* vetor;
    //Alocar memória para o vetor
	vetor = (int*) malloc(tam * sizeof(int));
	return vetor;
}

// busca iterativa sequencial em um vetor ordenado
int busca_sequencial(int *V, int tam, int chave){
	int i;

	if (V[0] > chave) //Se o primeiro elemento do vetor for maior que a chave, então a chave não se encontra no vetor, uma vez que este está ordenado.
		return 0;

	for(i = 0; i < tam; i++)
		if(V[i] == chave) //Caso a chave seja igual ao elemento do vetor, retornar 1.
			return 1;
	return 0;
}