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
//  email: sophiagarccia2@gmail.com
//  Matrícula: 20242160002
//  Semestre: 2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "SophiaGuimaraes20242160002.h" 
#include <stdlib.h>

DataQuebrada quebraData(char data[]){
    
    DataQuebrada dq;
    char qDia[3] = {0}, qMes[3] = {0}, qAno[5] = {0};
    int i = 0, j = 0, k = 0;
    int barra = 0;
    
    for(i = 0; data[i] != '\0'; i++){
        if(data[i] == '/'){
            barra++;
        }
    }    
        
    if(barra != 2){
        
        dq.valido = 0;
        return dq;
    } 
    
    // Pegar o dia
    for(i = 0; data[i] != '/' && i < 2; i++){ // é 2 e nao 3, pq comeca no indice 0
        qDia[i] = data[i];
    }
    // Finalizar o dia
    qDia[i] = '\0';
    
    // Verificacao se passou mais do que o ideal
    if(i != 1 && i != 2){
        dq.valido = 0;
        return dq;
    }
    
    //Incrementa pra pular a barra e nao causar erro
    j = i + 1;
    
    // Pegar o mes
    for(i = 0; data[j] != '/' && i < 2; i++, j++){
        qMes[i] = data[j];
    }
    
    qMes[i] = '\0';
    
    if(i != 1 && i != 2){
        separar.valido = 0;
        return dq;
    }
    k = j + 1;
    
    // Pegar o ano;
    
    for(i = 0; data[k] != '/' && i < 4; i++, k++){
        qAno[i] = data[k];
    }
    qAno[i] = '\0';
    
    if(i != 2 && i != 4){
        dq.valido = 0;
        return dq;
    }
    
    
    // Transformar em inteiro 
    
    dq.dia = atoi(qDia);
    dq.mes = atoi(qMes);
    dq.ano = atoi(qAno);
    
    if(dq.dia <= 0 || dq.mes <= 0 || dq.ano <= 0){
        dq.valido = 0;
        return dq;
    }
    
    dq.valido = 1;
    return dq;
    }

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
DataQuebrada dq = quebraData(data);
    
    if(dq.valido == 0){
        return 0;
    }
    
    int dia = dq.dia;
    int mes = dq.mes;
    int ano = dq.ano;
    int diasPorMes;
    
    // Verificar o ano
    if(ano < 100){
        
        if(ano >= 0 && ano <= 49){
            ano += 2000;
        }
        else{
            ano += 1900;
        }
    }
    // Verificar o mes
    
    if(mes < 1 || mes > 12) {
        return 0;
    }   
    
    // Verificar o dia
    if(dia < 1){
        return 0;
    }
    
    switch(mes){
        
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:  
        diasPorMes = 31;
        break;
        
        case 4: case 6: case 9: case 11:
        diasPorMes = 30;
        break;
        
        
        case 2: 
            int bissexto = (ano % 4 == 0 && ano % 100 != 0) || 
            (ano % 400 == 0);
             diasPorMes = bissexto ? 29 : 28;
             break;
            
        default:
        return 0;
    }
    
    if(dia > diasPorMes){
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
    int m, a;
    int diasNoMesAnterior;

    
    dma.qtdDia = 0;
    dma.qtdMes = 0;
    dma.qtdAno = 0;
    
    if(q1(datainicial) == 0){
        dma.retorno = 2;
        return dma;
    }
    if(q1(datafinal) == 0){
        dma.retorno = 3;
        return dma;
    }
    
    DataQuebrada inicio = quebrarData(datainicial);
    DataQuebrada final = quebrarData(datafinal);
    
    if(inicio.ano >= 0 && inicio.ano <= 49){
        inicio.ano += 2000;
        }
    else{
        inicio.ano += 1900;
        }
        
    if (final.ano < 100)
        final.ano += (final.ano <= 49) ? 2000 : 1900;    


if(inicio.ano > final.ano || (inicio.ano == final.ano && inicio.mes > final.mes) || (inicio.ano == final.ano && inicio.mes == final.mes && inicio.dia > final.dia)){
    
    dma.retorno = 4;
    return dma;
}

int dia1 = inicio.dia;
int dia2 = final.dia;
int mes1 = inicio.mes;
int mes2 = final.mes;
int ano1 = inicio.ano;
int ano2 = final.ano;

dma.qtdAno = ano2 - ano1;
dma.qtdMes = mes2 - mes1;
dma.qtdDia = dia2 - dia1;

if(dma.qtdDia < 0){
    dma.qtdMes--;
     m = mes2 - 1;
     a = ano2;
}

// Pegar janeiro
if(m == 0){
    m = 12;
    a--;
}

switch(m){
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        diasNoMesAnterior = 31; break;
    case 4: case 6: case 9: case 11:
        diasNoMesAnterior = 30; break;
    case 2:
        diasNoMesAnterior = ((a % 4 == 0 && a % 100 != 0) || (a %
        400 == 0)) ? 29 : 28;
        break;
    default:
        diasNoMesAnterior = 30;
        }

dma.qtdDia += diasNoMesAnterior;   

if(dma.qtdMes < 0){
    dma.qtdAno--;
    dma.qtdMes += 12;
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
int q3(char *texto, char c, int isCaseSensitive)
{
 int contador = 0;

    for (int i = 0; texto[i] != '\0'; i++) {
        char atual = texto[i];

        if (!isCaseSensitive) {
            atual = tolower(atual);
            c = tolower(c);
        }

        if (atual == c) {
            contador++;
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
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
   void noSpecials(char *text) {
    char buffer[256];
    int i = 0, j = 0;

    while (text[i] != '\0' && j < 255) {
        char c = text[i];
        switch (c) {
            case 'Á': case 'À': case 'Â': case 'Ã': case 'Ä': c = 'A'; break;
            case 'á': case 'à': case 'â': case 'ã': case 'ä': c = 'a'; break;
            case 'É': case 'È': case 'Ê': case 'Ë': c = 'E'; break;
            case 'é': case 'è': case 'ê': case 'ë': c = 'e'; break;
            case 'Í': case 'Ì': case 'Î': case 'Ï': c = 'I'; break;
            case 'í': case 'ì': case 'î': case 'ï': c = 'i'; break;
            case 'Ó': case 'Ò': case 'Ô': case 'Õ': case 'Ö': c = 'O'; break;
            case 'ó': case 'ò': case 'ô': case 'õ': case 'ö': c = 'o'; break;
            case 'Ú': case 'Ù': case 'Û': case 'Ü': c = 'U'; break;
            case 'ú': case 'ù': case 'û': case 'ü': c = 'u'; break;
            case 'Ç': c = 'C'; break;
            case 'ç': c = 'c'; break;
        }
        buffer[j++] = c;
        i++;
    }

    buffer[j] = '\0';
    strcpy(text, buffer);
}

int q4(char *strTexto, char *strBusca, int posicoes[30]) {
    int qtdOcorrencias = 0;
    int posicao = 0;
    int lenBusca = strlen(strBusca);
    int lenTexto = strlen(strTexto);

    noSpecials(strTexto);
    noSpecials(strBusca);

    for (int i = 0; i <= lenTexto - lenBusca; ) {
        int achou = 1;
        for (int j = 0; j < lenBusca; j++) {
            if (strTexto[i + j] != strBusca[j]) {
                achou = 0;
                break;
            }
        }
        if (achou) {
            posicoes[posicao++] = i + 1;
            posicoes[posicao++] = i + lenBusca;
            qtdOcorrencias++;
            i += lenBusca;
        } else {
            i++;
        }
    }

    return qtdOcorrencias;
}

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

int q5(int num)
{

    return num;
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

int q6(int numerobase, int numerobusca)

char base[50], busca[50];
    sprintf(base, "%d", numerobase);
    sprintf(busca, "%d", numerobusca);

    int tamBase = strlen(base);
    int tamBusca = strlen(busca);
    int ocorrencias = 0;

    for (int i = 0; i <= tamBase - tamBusca; i++) {
        int encontrou = 1;

        for (int j = 0; j < tamBusca; j++) {
            if (base[i + j] != busca[j]) {
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

 int q7(char matriz[8][10], char palavra[5])
 {
     int linhas = 8, colunas = 10;
    int tamPalavra = strlen(palavra);
    
    int direcoes[8][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}, {0, -1}, {-1, 0}, {-1, -1}, {-1, 1}};
    
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            for (int d = 0; d < 8; d++) {
                int dirX = direcoes[d][0], dirY = direcoes[d][1];
                int k, x = i, y = j;
                int encontrado = 1;
                
                for (k = 0; k < tamPalavra; k++) {
                    if (x < 0 || x >= linhas || y < 0 || y >= colunas || matriz[x][y] != palavra[k]) {
                        encontrado = 0;
                        break;
                    }
                    x += dirX;
                    y += dirY;
                }
                
                if (encontrado) {
                    return 1;  
                }
            }
        }
    }
    
    return 0;
 }



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}
