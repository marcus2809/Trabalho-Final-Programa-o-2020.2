#include <stdio.h>
#include "./lista.h"

//Faz o primeiro elemento da lista apontar para NULL
void inicializar_lista (Lista** l){
	*l = NULL;
}

// função para checar se a chave a ser inserida é repetida
int buscar_lista (Lista *l, int chave){
	while(l != NULL){
		if(l->chave == chave)
			return 1;
		l = l->prox;
	}
	return 0;
}

// inclui uma chave na lista se ela não estiver na lista
void incluir_lista (Lista **l, int chave, float info){
	Lista *novo; //Declarar um ponteiro para ser o novo elemento para a lista;

	if  (buscar_lista(*l, chave) )
		return;

	//Alocar espaço para o novo elemento:
	novo = malloc(sizeof(Lista));
	if ( novo == NULL){
		printf("Erro ao alocar memoria\n");
		return;
	}

    //Atribuir a chave e a informação real ao nó:
	novo->chave = chave;
	novo->info = info;
	novo->prox = NULL; //Como este nó ainda não foi adicionado, ele não aponta para outros
	novo->ant = NULL;

	if (*l == NULL) { //Verifica se a lista está vazia
		(*l) = novo;
		return;
	}

    //Inserir nó na lista e fazê-lo apontar para outros.
	novo->prox = *l; //Primeiro aponta pro segundo 
	(*l)->ant = novo; //Segundo aponta pro primeiro 
	(*l) = novo; //Atualiza o primeiro elemento
}

// Função que percorre a lista encadeada e mostrar cada um de seus elementos
void percorrer_lista (Lista *l){
	int n = 0;
	while(l != NULL){
		printf("%d lista %d\n", l->chave, n);
		n++;
		l = l->prox;
	}
}