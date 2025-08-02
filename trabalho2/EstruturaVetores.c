#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10


#include "EstruturaVetores.h"

typedef struct {
    int* numeros;
    int quantidade_atual;
    int capacidade;
} EstruturaAuxiliar;




EstruturaAuxiliar* vetorPrincipal[TAM];

int comparar_inteiros_crescente(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}


/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa
*/
void inicializar() {
    int i;
    for (i = 0; i < TAM; i++) {
        vetorPrincipal[i] = NULL;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa
para poder liberar todos os espaços de memória das estruturas auxiliares.
*/
void finalizar() {
    int i;
    for (i = 0; i < TAM; i++) {
        if (vetorPrincipal[i] != NULL) {
            free(vetorPrincipal[i]->numeros);
            free(vetorPrincipal[i]);
            vetorPrincipal[i] = NULL;
        }
    }
}


/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{

    int indice = posicao - 1; 

    int retorno = 0;

    if (vetorPrincipal[indice] != NULL) {
        return JA_TEM_ESTRUTURA_AUXILIAR;
    }

    // se posição é um valor válido {entre 1 e 10}

    if (indice < 0 || indice >= TAM) {
        return POSICAO_INVALIDA;
    }
    
    // o tamanho ser muito grande
    retorno = SEM_ESPACO_DE_MEMORIA;
    if (tamanho < 1) {
        return TAMANHO_INVALIDO;
    }

    vetorPrincipal[indice] = (EstruturaAuxiliar*) malloc(sizeof(EstruturaAuxiliar));
    if (vetorPrincipal[indice] == NULL) {
        return SEM_ESPACO_DE_MEMORIA;
    }

    vetorPrincipal[indice]->numeros = (int*) malloc(tamanho * sizeof(int));
    if (vetorPrincipal[indice]->numeros == NULL) {
        free(vetorPrincipal[indice]); // Libera a struct que já tinha alocado
        return SEM_ESPACO_DE_MEMORIA;
    }

    vetorPrincipal[indice]->quantidade_atual = 0;
    vetorPrincipal[indice]->capacidade = tamanho;

    return SUCESSO;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/

int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int indice = posicao - 1;
    if (indice < 0 || indice >= TAM) {
        return POSICAO_INVALIDA; 
    }

    if (vetorPrincipal[indice] == NULL) {
        return SEM_ESTRUTURA_AUXILIAR; 
    }

    EstruturaAuxiliar *lista = vetorPrincipal[indice];

    if (lista->quantidade_atual >= lista->capacidade) {
        return SEM_ESPACO; 
    }


    lista->numeros[lista->quantidade_atual] = valor;
    lista->quantidade_atual++;

    return SUCESSO;
}


/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{

    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA) {
        return POSICAO_INVALIDA;
    }

    int indice = posicao - 1; // Converte para o índice do vetor (0-9)

    if (vetorPrincipal[indice] == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    EstruturaAuxiliar *lista = vetorPrincipal[indice];

    if (lista->quantidade_atual == 0) {
        return ESTRUTURA_AUXILIAR_VAZIA;
    }

    
    lista->quantidade_atual--;

    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
     if (ehPosicaoValida(posicao) == POSICAO_INVALIDA) {
        return POSICAO_INVALIDA;
    }

    int indice = posicao - 1; 

    if (vetorPrincipal[indice] == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    EstruturaAuxiliar *lista = vetorPrincipal[indice];

    if (lista->quantidade_atual == 0) {
        return ESTRUTURA_AUXILIAR_VAZIA;
    }

    int indice_para_excluir = -1; 

    for (int i = 0; i < lista->quantidade_atual; i++) {
        if (lista->numeros[i] == valor) {
            indice_para_excluir = i;
            break; 
        }
    }

    if (indice_para_excluir == -1) {
        return NUMERO_INEXISTENTE;
    }

 
    for (int i = indice_para_excluir; i < lista->quantidade_atual - 1; i++) {

        lista->numeros[i] = lista->numeros[i + 1];
    }
    
    lista->quantidade_atual--;

    return SUCESSO;
}


// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    if (posicao >= 1 && posicao <= 10) {
        // Se a posição é válida, já retorna SUCESSO e a função para aqui.
        return SUCESSO;
    } else {
        // Senão, com certeza é inválida. Retorna o erro.
        return POSICAO_INVALIDA;
    }
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int indice = posicao - 1;

    if (indice < 0 || indice >= TAM) {
        return POSICAO_INVALIDA;
    }

    if (vetorPrincipal[indice] == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    EstruturaAuxiliar *lista = vetorPrincipal[indice];

    for (int i = 0; i < lista->quantidade_atual; i++) {
        vetorAux[i] = lista->numeros[i];
    }

    return SUCESSO;
}


/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA) {
        return POSICAO_INVALIDA;
    }

    int indice = posicao - 1;

    // Passo 1.2: Validação da Existência da Estrutura
    if (vetorPrincipal[indice] == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    EstruturaAuxiliar *lista = vetorPrincipal[indice];
    
    // Se a lista estiver vazia, a operação é um sucesso, mas não há dados para copiar.
    if (lista->quantidade_atual == 0) {
        return SUCESSO; 
    }

    // Passo 2: Cópia Segura dos Dados
    // Copiamos os 'quantidade_atual' números da nossa estrutura para o vetor do chamador.
    for (int i = 0; i < lista->quantidade_atual; i++) {
        vetorAux[i] = lista->numeros[i];
    }
    
    // Passo 3: Ordenar a CÓPIA que está em vetorAux
    qsort(vetorAux, lista->quantidade_atual, sizeof(int), comparar_inteiros_crescente);

    // Passo 4: Retornar sucesso!
    return SUCESSO;
}
 

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

     int indice_vetor_aux = 0;

    // Loop para visitar cada posição do painel principal (de 0 a 9)
    for (int i = 0; i < TAM; i++) {
        
        // Se existe uma lista auxiliar nesta posição e ela não está vazia...
        if (vetorPrincipal[i] != NULL && vetorPrincipal[i]->quantidade_atual > 0) {
            
            EstruturaAuxiliar *lista_atual = vetorPrincipal[i];

            // ...copia todos os números dessa lista para o vetorAux.
            for (int j = 0; j < lista_atual->quantidade_atual; j++) {
                vetorAux[indice_vetor_aux] = lista_atual->numeros[j];
                indice_vetor_aux++; // Avança a posição no cesto para o próximo número
            }
        }
    }

    if (indice_vetor_aux == 0) {
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    } else {
        return SUCESSO;
    }
}

static int getQtdNumerosTotais(EstruturaAuxiliar* vetorPrincipal[]){
    int i, total = 0;
    for (i = 0; i < TAM; i++) {
        if (vetorPrincipal[i] != NULL) {
            total += vetorPrincipal[i]->quantidade_atual;
        }
    }
    return total;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
*/

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int indice_vetor_aux = 0;

    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i] != NULL && vetorPrincipal[i]->quantidade_atual > 0) {
            
            EstruturaAuxiliar *lista_atual = vetorPrincipal[i];

            for (int j = 0; j < lista_atual->quantidade_atual; j++) {
                vetorAux[indice_vetor_aux] = lista_atual->numeros[j];
                indice_vetor_aux++; 
            }
        }
    }


    if (indice_vetor_aux == 0) {
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }


    qsort(vetorAux, indice_vetor_aux, sizeof(int), comparar_inteiros_crescente);
    
    return SUCESSO;
}


/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{

    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA) {
        return POSICAO_INVALIDA;
    }

    int indice = posicao - 1;

    if (vetorPrincipal[indice] == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    EstruturaAuxiliar *lista = vetorPrincipal[indice];
    int nova_capacidade = lista->capacidade + novoTamanho;

    if (nova_capacidade < 1) {
        return NOVO_TAMANHO_INVALIDO;
    }

    int* novo_ponteiro = (int*) realloc(lista->numeros, nova_capacidade * sizeof(int));

    if (novo_ponteiro == NULL) {
        return SEM_ESPACO_DE_MEMORIA;
    }

    lista->numeros = novo_ponteiro; // O ponteiro da nossa lista agora aponta para o novo bloco de memória.
    lista->capacidade = nova_capacidade; // Atualizamos a capacidade máxima.

    if (lista->quantidade_atual > nova_capacidade) {
        lista->quantidade_atual = nova_capacidade;
    }

    return SUCESSO;
}


/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{

    if (ehPosicaoValida(posicao) != SUCESSO) { // Supondo que SUCESSO seja 0
        return POSICAO_INVALIDA;
    }

    int indice = posicao - 1;

    if (vetorPrincipal[indice] == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    EstruturaAuxiliar *lista = vetorPrincipal[indice];

    if (lista->quantidade_atual == 0) {
        return ESTRUTURA_AUXILIAR_VAZIA;
    }
    
    return lista->quantidade_atual;
}


/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{

    No *cabecote = (No*) malloc(sizeof(No));
    if (cabecote == NULL) {
        return NULL; 
    }
    cabecote->conteudo = -1; // Valor sentinela, não faz parte dos dados.
    cabecote->prox = NULL;

    No *cauda = cabecote;
    int numeros_encontrados = 0;

    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i] != NULL && vetorPrincipal[i]->quantidade_atual > 0) {
            
            EstruturaAuxiliar *lista_atual = vetorPrincipal[i];
            
            for (int j = 0; j < lista_atual->quantidade_atual; j++) {
                int numero = lista_atual->numeros[j];
                
                No *novo_no = (No*) malloc(sizeof(No));
                novo_no->conteudo = numero;
                novo_no->prox = NULL;

                cauda->prox = novo_no;
                cauda = novo_no;
                
                numeros_encontrados++;
            }
        }
    }

   
    if (numeros_encontrados == 0) {
        free(cabecote); 
        return NULL;   
    }

    return cabecote;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
    if (inicio == NULL || inicio->prox == NULL) {
        return; 
    }

    No *atual = inicio->prox;
    
    int indice_vetor = 0;

    while (atual != NULL) {
        
        vetorAux[indice_vetor] = atual->conteudo;

        indice_vetor++;
        atual = atual->prox;
    }

}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/

void destruirListaEncadeadaComCabecote(No **inicio_ref) {

    No *atual = *inicio_ref;
    No *proximo_no;

    while (atual != NULL) {
        
        proximo_no = atual->prox;
        free(atual);
        atual = proximo_no;
    }

    *inicio_ref = NULL;
    
}
