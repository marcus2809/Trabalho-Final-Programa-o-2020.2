#ifndef lista_h
#define lista_h

#include <stdlib.h>

//Define estrutura para ser a lista:
typedef struct _lista {
	int chave;
	float info;
	struct _lista *prox, *ant;
} Lista;

void inicializar_lista (Lista** l);
void incluir_lista (Lista **l, int chave, float info);
int buscar_lista (Lista *l, int x);
void percorrer_lista (Lista *l);

#endif