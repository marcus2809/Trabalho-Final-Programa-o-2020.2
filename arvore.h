#ifndef arvore_h
#define arvore_h

#include <stdlib.h>

typedef struct _arvore {
	int chave;
	float info;
	struct _arvore *esq, *dir;
} Arvore;

void inicializar_arvore (Arvore **arv);
void inserir_arvore (Arvore **arv, int chave, float info);
int buscar_arvore (Arvore *arv, int chave);
Arvore* abb_busca(Arvore *arv, int chave);
void percorrer_arvore (Arvore *arv, int* vetor);

#endif