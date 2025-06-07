// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Sophia Garcia
//  email:sophiagarccia2@gmail.com
//  Matrícula: 20242160002
//  Semestre:2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "SophiaGuimaraes20242160002.h" 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

DataQuebrada quebraData(char data[]) {
    DataQuebrada dq;
    char jDia[3], jMes[3], jAno[5];
    int i, j;

    for (i = 0; data[i] != '/'; i++) {
        jDia[i] = data[i];
    }
    jDia[i] = '\0'; 
    if (i != 1 && i != 2) {
        dq.valido = 0;
        return dq;
    }

    j = i + 1; // pra nao dar erro de ficar tentando ler a barra e pular
    for (i = 0; data[j] != '/'; j++, i++) {
        jMes[i] = data[j];
    }
    jMes[i] = '\0';
    if (i != 1 && i != 2) {
        dq.valido = 0;
        return dq; 
    }

    j = j + 1;
    for (i = 0; data[j] != '\0'; j++, i++) {
        jAno[i] = data[j];
    }
    jAno[i] = '\0'; 
    if (i != 2 && i != 4) {
        dq.valido = 0;
        return dq; 
    }

    dq.iDia = atoi(jDia);
    dq.iMes = atoi(jMes);
    dq.iAno = atoi(jAno);
    dq.valido = 1;

    return dq;
}

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
    DataQuebrada dq = quebraData(data);

    if (dq.valido == 0)
        return 0;

    int dia = dq.iDia;
    int mes = dq.iMes;
    int ano = dq.iAno;

    if(ano >= 0 && ano <= 99){
	ano+= (ano >= 49)? 2000: 1900;
   }   

    if (mes < 1 || mes > 12 || dia < 1)
        return 0;
	
    int diasDoMes;

    switch (mes)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        diasDoMes = 31;
        break;
    case 4: case 6: case 9: case 11:
        diasDoMes = 30;
        break;
    case 2: // logica do bissexto em fev
        if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
            diasMes = 29;
        else
            diasMes = 28;
        break;
    default:
        return 0;
    }

    if (dia > diasDoMes){
        return 0;
    }    

    return 1;
}


/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{
    DiasMesesAnos dma;
    dma.qtdDias = 0;
    dma.qtdMeses = 0;
    dma.qtdAnos = 0;

    if (q1(datainicial) == 0)
    {
        dma.retorno = 2;
        return dma;
    }

    if (q1(datafinal) == 0)
    {
        dma.retorno = 3;
        return dma;
    }

    DataQuebrada inicio = quebraData(datainicial);
    DataQuebrada fim = quebraData(datafinal);

    if (inicio.iAno <= 99) inicio.iAno += (inicio.iAno <= 49) ? 2000 : 1900;
    if (fim.iAno <= 99) fim.iAno += (fim.iAno <= 49) ? 2000 : 1900;

    if (fim.iAno < inicio.iAno || (fim.iAno == inicio.iAno && fim.iMes < inicio.iMes) ||
        (fim.iAno == inicio.iAno && fim.iMes == inicio.iMes && fim.iDia < inicio.iDia))
    {
        dma.retorno = 4;
        return dma;
    }


    dma.qtdAnos = fim.iAno - inicio.iAno;
    dma.qtdMeses = fim.iMes - inicio.iMes;
    dma.qtdDias = fim.iDia - inicio.iDia;

    if (dma.qtdDias < 0)
    {
        dma.qtdMeses--;
        int mesAnterior = fim.iMes - 1;
        int anoDoMesAnterior = fim.iAno;

   	if (mesAnterior == 0) // se era janeiro, o mes anterior é dezembro do ano passsado
        {
            mesAnterior = 12;
            anoDoMesAnterior--;
        }

	int diasPorMes[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int diasParaSomar = diasPorMes[mesAnterior];
	if (mesAnterior == 2 && ((anoDoMesAnterior % 4 == 0 && anoDoMesAnterior % 100 != 0) || (anoDoMesAnterior % 400 == 0)){
            diasParaSomar = 29;
	}

	dma.qtdDias += diasParaSomar;
    }	    
	
    if (dma.qtdMeses < 0){

        dma.qtdAnos--;
        dma.qtdMeses += 12;
    }

    dma.retorno = 1;
    return dma;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */

int q3(char texto[], char c, int isCaseSensitive) {
	int contador = 0;
	for(int i = 0; texto[i] != '\0'; i++){
		 if (isCaseSensitive == 1) {
            		if (texto[i] == c) {
                		contador++;
            		}
		 }else{
 			if(tolower(texto[i]) == tolower(c)){
				contador++;
			}
		 }
	}
	return contador;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */

int q4(char *strTexto, char *strBusca, int posicoes[30]) {
    int qtdOcorrencias = 0;
    int tamTexto = strlen(strTexto);
    int tamBusca = strlen(strBusca);
    int i, j, k;

    for (i = 0; i <= tamTexto - tamBusca; i++) {
        int encontrou = 1;
        
        for (j = 0; j < tamBusca; j++) {
            if (strTexto[i + j] != strBusca[j]) {
                encontrou = 0;
                break;
            }
        }

        if (encontrou) {
            posicoes[qtdOcorrencias * 2] = i + 1;                 // posição inicial (começa em 1)
            posicoes[qtdOcorrencias * 2 + 1] = i + tamBusca;      // posição final
            qtdOcorrencias++;
        }
    }

    return qtdOcorrencias;
}


/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num) {
    int negativo = num < 0;
    if (negativo) num = -num;

    int invertido = 0;
    while (num != 0) {
        int digito = num % 10;
        invertido = invertido * 10 + digito;
        num /= 10;
    }

    return negativo ? -invertido : invertido;
}


/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca) {
    // Converte os números em strings
    char strBase[50], strBusca[50];
    sprintf(strBase, "%d", numerobase);
    sprintf(strBusca, "%d", numerobusca);

    int ocorrencias = 0;
    int tamBase = strlen(strBase);
    int tamBusca = strlen(strBusca);

    for (int i = 0; i <= tamBase - tamBusca; i++) {
        int encontrou = 1;

        for (int j = 0; j < tamBusca; j++) {
            if (strBase[i + j] != strBusca[j]) {
                encontrou = 0;
                break;
            }
        }

        if (encontrou) {
            ocorrencias++;
        }
    }

    return ocorrencias;
}


/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */

int buscaPalavra(char matriz[8][10], int linhas, int colunas, char *palavra) {
    int len = strlen(palavra);

    int direcoes[8][2] = {
        {0, 1},    // Direita
        {0, -1},   // Esquerda
        {1, 0},    // Baixo
        {-1, 0},   // Cima
        {1, 1},    // Diagonal inferior direita
        {-1, -1},  // Diagonal superior esquerda
        {1, -1},   // Diagonal inferior esquerda
        {-1, 1}    // Diagonal superior direita
    };

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {

            // Para cada direção
            for (int d = 0; d < 8; d++) {
                int dx = direcoes[d][0];
                int dy = direcoes[d][1];
                int k, x = i, y = j;

                for (k = 0; k < len; k++) {
                    if (x < 0 || x >= linhas || y < 0 || y >= colunas)
                        break;
                    if (matriz[x][y] != palavra[k])
                        break;

                    x += dx;
                    y += dy;
                }

                if (k == len) {
                    return 1;  // Palavra encontrada
                }
            }
        }
    }

    return 0;  // Palavra não encontrada
}


