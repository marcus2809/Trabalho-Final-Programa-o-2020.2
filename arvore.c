#include <stdio.h>
#include "./arvore.h"

int pos = 0; // usado na função percorrer_arvore como índice do vetor que irá receber as chaves da árvore

// Faz o primeiro elemento da arvore apontar para NULL
void inicializar_arvore (Arvore **arv) {
	*arv = NULL;
}

// Insere um elemento na árvore de busca binária
void inserir_arvore (Arvore **arv, int chave, float info) {
	Arvore *novo, *temp;

    //Alocar memoria para o novo nó (folha) da árvore:
	novo = (Arvore*) malloc(sizeof(Arvore));
	if (novo == NULL) {
		printf("Erro ao alocar memoria\n");
		return;
    }

    //Atribuir chave e informação float ao No (novo)
	novo->info = info;
	novo->chave = chave;
	novo->esq = NULL; //Como o nó ainda não foi inserido, ele não aponta para outros
	novo->dir = NULL;
	
    //Verificar se a lista é vazia:
	if (*arv == NULL) {
		*arv = novo;
		return;
	}

    //criar um nó temporário/auxiliar:
	temp = *arv;

    //Achar um ponteiro para NULL de acordo com as condições da ABB e inserir um novo nó
	while (temp != NULL){
		if ( chave < (temp)->chave && (temp)->esq != NULL ) {
			temp = temp->esq;
		}
		else if (chave < (temp)->chave && (temp)->esq == NULL) {
			temp->esq = novo;
			return;
		}
		else if (chave > (temp)->chave && (temp)->dir != NULL) {
			temp = temp->dir;
		}
		else if (chave > (temp)->chave && (temp)->dir == NULL) {
			temp->dir = novo;
			return;
		}
	}
}

// Busca um elemento pela chave na árvore e retorna a um ponteiro para o nó da arvore se a chave for igual a buscada
//Senão retorna um ponteiro para NULL:
Arvore* abb_busca(Arvore *arv, int chave){
	if (arv == NULL || arv->chave == chave)
		return arv;
	if (chave < arv->chave)
		return abb_busca(arv->esq, chave);
	return abb_busca(arv->dir, chave);
}

// Chama a função que busca um nó cuja chave foi passada por parâmetro e checa se tal nó de fato está na árvore, retornando 1 se a chave existir e 0 caso contrário
int buscar_arvore(Arvore *arv, int chave){
	if (abb_busca(arv, chave) != NULL)
		return 1; //A chave se encontra na árvore
	return 0; //A chave não se encontra na árvore
}

// insere as chaves da árvore em um vetor de maneira ordenada
void percorrer_arvore (Arvore *arv, int *vetor){
	if (arv != NULL){
		percorrer_arvore (arv->esq, vetor);
		vetor[pos++] = arv->chave;
		percorrer_arvore (arv->dir, vetor);
	}
}
