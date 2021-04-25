#include <stdio.h>
#include "./vetor_bb.h"

// Função que realiza a busca binária em um vetor
int bb(int* V, int p, int r, int x){
	int q;

	if ( p == r - 1)
		return r;
	
	q = (int) (p+r) / 2;

	if(V[q] < x)
		return bb(V, q, r, x);
	else
		return bb(V, p, q, x);
}

// Função que chama bb, que de fato realizará a busca binária, e analisa se a chave buscada está ou não no vetor
int busca_binaria(int* V, int n, int x){ //n = tamanho do vetor, x = chave para ser buscada
	int res;
	res = bb(V, 0, n, x); // sendo "n" o tamanho do vetor
	if (res >= 0 && res < n && V[res] == x)
		return 1;//Encontrou uma chave igual
	else
		return 0;//Não encontrou uma chave igual
}