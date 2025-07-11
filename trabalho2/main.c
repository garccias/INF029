#include <stdio.h>
#include <stdlib.h>
#include "EstruturaVetores.h" 

int main() {
    inicializar(); 
    
    int op;
    int sair = 0;

    while (!sair) {

        printf("\n============ MENU DE OPÇÕES ============\n");
        printf(" 1 - Criar estrutura auxiliar\n");
        printf(" 2 - Inserir número em estrutura\n");
        printf(" 3 - Excluir número de estrutura\n");
        printf(" 4 - Listar dados de uma estrutura\n");
        printf(" 5 - Obter quantidade de elementos\n");
        printf(" 0 - Sair\n");

        printf("=======================================\n");

        printf("Digite sua escolha: ");
        scanf("%d", &op);
        printf("\n");

        switch (op) {
            case 0: {
                sair = 1;
                finalizar(); 
                break;
            }

            case 1: { // Criar Estrutura
                int posicao, tamanho, ret;
                printf("Digite a posição para criar (1-10): ");
                scanf("%d", &posicao);
                printf("Digite o tamanho da nova estrutura: ");
                scanf("%d", &tamanho);
                
                ret = criarEstruturaAuxiliar(posicao, tamanho);

                if (ret == SUCESSO) printf(">> Estrutura criada com SUCESSO!\n");
                else if (ret == POSICAO_INVALIDA) printf("Posição inválida!\n");
                else if (ret == JA_TEM_ESTRUTURA_AUXILIAR) printf("Ja existe uma estrutura nesta posição.\n");
                else if (ret == TAMANHO_INVALIDO) printf("Tamanho deve ser maior que 0.\n");
                else if (ret == SEM_ESPACO_DE_MEMORIA) printf("Faltou memória para criar a estrutura.\n");
                
                break;
            }


            case 2: { // Inserir Número
                int posicao, valor, ret;
                printf("Digite a posição para inserir (1-10): ");
                scanf("%d", &posicao);
                printf("Digite o valor a inserir: ");
                scanf("%d", &valor);

                ret = inserirNumeroEmEstrutura(posicao, valor);

                if (ret == SUCESSO) printf(">> Número inserido com SUCESSO!\n");
                else if (ret == POSICAO_INVALIDA) printf("Posição inválida!\n");
                else if (ret == SEM_ESTRUTURA_AUXILIAR) printf("Crie a estrutura nesta posição primeiro.\n");
                else if (ret == SEM_ESPACO) printf("A estrutura está cheia.\n");

                break;
            }
            
            case 3: { // Excluir Número
                int posicao, valor, ret;
                printf("Digite a posição para excluir (1-10): ");
                scanf("%d", &posicao);
                printf("Digite o valor a excluir: ");
                scanf("%d", &valor);

                ret = excluirNumeroEspecificoDeEstrutura(posicao, valor);
                
                if (ret == SUCESSO) printf(">> Número excluído com SUCESSO!\n");
                else if (ret == POSICAO_INVALIDA) printf("Posição inválida!\n");
                else if (ret == SEM_ESTRUTURA_AUXILIAR) printf("Não existe estrutura nesta posição.\n");
                else if (ret == ESTRUTURA_AUXILIAR_VAZIA) printf("A estrutura já estava vazia.\n");
                else if (ret == NUMERO_INEXISTENTE) printf("O número %d não foi encontrado para excluir.\n", valor);

                break;
            }

            case 4: { // Listar dados de uma estrutura
                int posicao, qtd;
                printf("Qual a estrutura a ser listada (1-10)? ");
                scanf("%d", &posicao);

                qtd = getQuantidadeElementosEstruturaAuxiliar(posicao);

                if (qtd < 0) {
                    if(qtd == POSICAO_INVALIDA) printf(">> ERRO: Posição inválida!\n");
                    else if (qtd == SEM_ESTRUTURA_AUXILIAR) printf(">> AVISO: Nenhuma estrutura foi criada nesta posição.\n");
                } else if (qtd == 0) {
                    printf(">> A estrutura na posição %d está VAZIA.\n", posicao);
                } else { 
                    int *vetorAux = (int*)malloc(qtd * sizeof(int));
                    getDadosEstruturaAuxiliar(posicao, vetorAux);
                    
                    printf(">> Dados da posição %d: [ ", posicao);
                    for (int i = 0; i < qtd; i++) {
                        printf("%d ", vetorAux[i]);
                    }
                    printf("]\n");
                    free(vetorAux);
                }
                break;
            }
            
            case 5: { 
                int posicao, qtd;
                printf("Consultar quantidade da posição (1-10): ");
                scanf("%d", &posicao);
                qtd = getQuantidadeElementosEstruturaAuxiliar(posicao);
                 if (qtd >= 0) {
                     printf("A estrutura na posição %d tem %d elemento(s).\n", posicao, qtd);
                } else {
                     if(qtd == POSICAO_INVALIDA) printf("Posição inválida!\n");
                     else if (qtd == SEM_ESTRUTURA_AUXILIAR) printf("Nenhuma estrutura foi criada nesta posição.\n");
                }
                break;
            }

            default: {
                printf("Opção inválida! Por favor, tente novamente.\n");
            }
        }
    }
    
    return 0;
}