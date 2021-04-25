#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./lista.h"
#include "./arvore.h"
#include "./vetor.h"
#include "./vetor_bb.h"

#define N 51000
#define K 3150000

// N = 51000 K = 3150000 Fez as buscas na ABB em média em 2 segundos

int main (int narg, char** argv) {
	
	Arvore *arv;
	Lista *lst;
	int *v, a, *chaves;
	int key;//Guardar a chave.
  	float info_real; //Guardar a informação float.
  	int busca; //Guarda se a chave já está na lista e na árvore.
	int divisao; // Usado pra gerar o float
	int i, chave_busca;
	//tempo_ini -> Tempo inicial da busca
    //tempo_fin - > Tempo final da busca
    //bb -> Busca binária;
    //seq -> Busca sequencial
	time_t tempo_ini_arvore, tempo_fin_arvore;
	time_t tempo_ini_lista, tempo_fin_lista;
	time_t tempo_ini_vetor_bb, tempo_fin_vetor_bb;
	time_t tempo_ini_vetor_seq, tempo_fin_vetor_seq;

    //Variáveis para guardar o tempo decorrido nas buscas:
    long double tempo_total_arvore, tempo_total_lista, tempo_total_vetor_bb, tempo_total_vetor_seq;

    //Inicializar a lista e a árvore
	inicializar_lista(&lst);
	inicializar_arvore(&arv);

    //Criar o vetor para armazenar as futuras chaves aleatórias
	v = criar_vetor(N);
	if (v == NULL) {
		printf("Erro ao alocar memoria\n");
		return EXIT_FAILURE;
	}

	chaves = malloc(K * sizeof(int));
	if (chaves == NULL){
		printf("Erro ao alocar memoria\n");
		return EXIT_FAILURE;
	}

	//Executar iteração para sortear numeros:
	srand(time(NULL));

	printf("Inserindo %d tuplas em cada estrutura de dados...\n", (int)N);

	for(i = 0; i < N; i++){
		key = rand() % 2147483646; //Maior numero que pode ser sorteado - 1;
        
        //Verificar se a chave já se encontra na arvore binária, caso retorne 1 (se encontre na árvore), entrar
        //no ciclo while até sortear uma chave diferente.
		busca = buscar_arvore(arv, key);//Verificar se a chave é repetida.
		while (busca == 1){
			//Sortear uma nova chave:
			key = rand() % 2147483646;
			busca = buscar_arvore(arv, key);
		}

		info_real = rand();
		divisao = rand();
		divisao += 1; //Evitar denominador 0;
		info_real /= divisao; //Esse procedimento serve para possibilitar que as casas decimais possam ser iguais a zero.
		
        //Após sortear uma chave diferente das outras inseridas anteriormente
		//Adicionar os elementos sorteados na lista e na árvore:
		incluir_lista(&lst, key, info_real);
		inserir_arvore(&arv, key, info_real);
  	}

    percorrer_arvore(arv, v); // inserir as chaves da árvore no vetor
	printf("Tuplas inseridas com sucesso.\n\n");

    //Sortear chaves aleatórias para realizar as buscas - armazená - las em um vetor:
	for ( i = 0; i < K; i++) {
		chave_busca = rand() % 2147483646;
		chaves[i] = chave_busca;
		//printf("chaves %d\n", chaves[i]);
	}

//-----------------Vetor Busca Binaria-----------------------
	printf("Executando Busca Binaria no Vetor...\n");
    tempo_ini_vetor_bb = clock();//Tempo de início da busca

    for ( i = 0; i < K; i++){
		busca_binaria(v, N, chaves[i]); //Verificar se a chave se encontra no vetor
	}

    tempo_fin_vetor_bb = clock(); //Tempo do fim da busca

    //Calcular o tempo e deccorrido em segundos:
    tempo_total_vetor_bb = (long double)(tempo_fin_vetor_bb - tempo_ini_vetor_bb)/CLOCKS_PER_SEC;

    printf("O tempo decorrido na Busca Binaria em Vetor foi de: %.2Lf segundos.\n\n", tempo_total_vetor_bb);

//-----------------Arvore-----------------------
	printf("Executando busca na Arvore...\n");
    tempo_ini_arvore = clock();//Tempo de início da busca

    for( i = 0; i < K; i++){
		buscar_arvore(arv, chaves[i]); //Verificar se a chave K se encontra na arvore
	}

    tempo_fin_arvore = clock();//Tempo do fim da busca

    //Calcular o tempo e deccorrido em segundos:
    tempo_total_arvore = (long double)(tempo_fin_arvore - tempo_ini_arvore) / CLOCKS_PER_SEC;

    printf("O Tempo decorrido na busca em Arvore foi de: %.2Lf segundos.\n\n", tempo_total_arvore);

//-----------------Vetor Sequencial-----------------------
	printf("Executando Busca Sequencial no Vetor...\n");
    tempo_ini_vetor_seq = clock();//Tempo de início da busca

    for ( i = 0; i < K; i++){
		busca_sequencial(v, N, chaves[i]);
	}

    tempo_fin_vetor_seq = clock();//Tempo do fim da busca

    //Calcular o tempo e deccorrido em segundos:
    tempo_total_vetor_seq = (long double)(tempo_fin_vetor_seq - tempo_ini_vetor_seq)/CLOCKS_PER_SEC;

    printf("O Tempo decorrido na busca sequencial em Vetor foi de: %.2Lf segundos.\n\n", tempo_total_vetor_seq);

//-----------------Lista-----------------------
	printf("Executando busca na Lista...\n");
    tempo_ini_lista = clock();//Tempo de início da busca

    for ( i = 0; i < K; i++){
		buscar_lista(lst, chaves[i]); //Verificar se a chave se encontra na lista
	}

    tempo_fin_lista = clock();//Tempo do fim da busca
    
    //Calcular o tempo e deccorrido em segundos:
    tempo_total_lista = (long double)(tempo_fin_lista - tempo_ini_lista)/CLOCKS_PER_SEC;

    printf("O Tempo decorrido na busca em Lista Duplamente Encadeada foi de: %.2Lf segundos.\n\n", tempo_total_lista);

	return EXIT_SUCCESS;
}