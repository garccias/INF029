#ifndef TRABALHO2_ESTRUTURAVETORES_H
#define TRABALHO2_ESTRUTURAVETORES_H

enum {
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS = -11,
    NOVO_TAMANHO_INVALIDO = -10,
    NUMERO_INEXISTENTE = -9,
    ESTRUTURA_AUXILIAR_VAZIA = -8,
    TAMANHO_INVALIDO = -7,
    SEM_ESPACO_DE_MEMORIA = -6,
    POSICAO_INVALIDA = -5,
    JA_TEM_ESTRUTURA_AUXILIAR = -4,
    SEM_ESTRUTURA_AUXILIAR = -3,
    SEM_ESPACO = -2,
    SUCESSO = 0
};

typedef struct reg {
    int conteudo;
    struct reg *prox;
} No;



void inicializar();
void finalizar();
int criarEstruturaAuxiliar(int posicao, int tamanho);
int inserirNumeroEmEstrutura(int posicao, int valor);
int excluirNumeroDoFinaldaEstrutura(int posicao);
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor);
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho);
int getQuantidadeElementosEstruturaAuxiliar(int posicao);

int ehPosicaoValida(int posicao);


No* montarListaEncadeadaComCabecote();
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]);
void destruirListaEncadeadaComCabecote(No **inicio);

#endif  // TRABALHO2_ESTRUTURAVETORES_H