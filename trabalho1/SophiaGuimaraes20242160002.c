#include <stdio.h>
#include <stdlib.h> // Para atoi
#include <string.h> // Para strlen (permitido em q4, usado em q6, q7) e para strcpy (se usado)
#include <ctype.h>  // Para tolower em q3 e normalizeChar

#include "SophiaGuimaraes20242160002.h" // Seu arquivo header

static char normalizeChar(char c) {
    // Converter para minúsculo (simples ASCII)
    if (c >= 'A' && c <= 'Z') {
        c = c + ('a' - 'A');
    }

    // Remover acentos (minúsculas e maiúsculas)
    switch (c) {
        case 'á': case 'à': case 'â': case 'ã': case 'ä':
        case 'Á': case 'À': case 'Â': case 'Ã': case 'Ä':
            return 'a';

        case 'é': case 'è': case 'ê': case 'ë':
        case 'É': case 'È': case 'Ê': case 'Ë':
            return 'e';

        case 'í': case 'ì': case 'î': case 'ï':
        case 'Í': case 'Ì': case 'Î': case 'Ï':
            return 'i';

        case 'ó': case 'ò': case 'ô': case 'õ': case 'ö':
        case 'Ó': case 'Ò': case 'Ô': case 'Õ': case 'Ö':
            return 'o';

        case 'ú': case 'ù': case 'û': case 'ü':
        case 'Ú': case 'Ù': case 'Û': case 'Ü':
            return 'u';

        case 'ç': case 'Ç':
            return 'c';

        default:
            return c;
    }
}



DataQuebrada quebraData(char data[]) {
    DataQuebrada dq;
    char sDia[3], sMes[3], sAno[5];
    int i, j;

    for (i = 0; data[i] != '/'; i++) {
        sDia[i] = data[i];
    }
    sDia[i] = '\0'; 
    if (i != 1 && i != 2) {
        dq.valido = 0;
        return dq;
    }

    j = i + 1;
    for (i = 0; data[j] != '/'; j++, i++) {
        sMes[i] = data[j];
    }
    sMes[i] = '\0';
    if (i != 1 && i != 2) {
        dq.valido = 0;
        return dq; 
    }

    j = j + 1;
    for (i = 0; data[j] != '\0'; j++, i++) {
        sAno[i] = data[j];
    }
    sAno[i] = '\0'; 
    if (i != 2 && i != 4) {
        dq.valido = 0;
        return dq; 
    }

    dq.iDia = atoi(sDia);
    dq.iMes = atoi(sMes);
    dq.iAno = atoi(sAno);
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
int q1(char data[]) {
     DataQuebrada dq = quebraData(data);

    if (dq.valido == 0)
        return 0;

    int dia = dq.iDia;
    int mes = dq.iMes;
    int ano = dq.iAno;

    if (ano < 100)
    {
        if (ano >= 0 && ano <= 49)
            ano += 2000;
        else
            ano += 1900;
    }

    if (mes < 1 || mes > 12)
        return 0;

    if (dia < 1)
        return 0;

    int diasMes;

    switch (mes)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        diasMes = 31;
        break;
    case 4: case 6: case 9: case 11:
        diasMes = 30;
        break;
    case 2:
        if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
            diasMes = 29;
        else
            diasMes = 28;
        break;
    default:
        return 0;
    }

    if (dia > diasMes)
        return 0;

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
DiasMesesAnos q2(char datainicial[], char datafinal[]) {
    DiasMesesAnos dma;
    dma.qtdDias = 0;
    dma.qtdMeses = 0;
    dma.qtdAnos = 0;
    dma.retorno = 0; // Inicializa retorno

    if (q1(datainicial) == 0) {
        dma.retorno = 2;
        return dma;
    }
    if (q1(datafinal) == 0) {
        dma.retorno = 3;
        return dma;
    }

    DataQuebrada dqInicio = quebraData(datainicial);
    DataQuebrada dqFinal = quebraData(datafinal);

    // Assegurar que os anos estão em formato de 4 dígitos
    // A função q1 não altera o valor em dqInicio/dqFinal, apenas usa uma cópia local.
    // Portanto, precisamos ajustar aqui para os cálculos.
    if (dqInicio.iAno >= 0 && dqInicio.iAno <= 99) {
        dqInicio.iAno += (dqInicio.iAno <= 49) ? 2000 : 1900;
    }
    if (dqFinal.iAno >= 0 && dqFinal.iAno <= 99) {
        dqFinal.iAno += (dqFinal.iAno <= 49) ? 2000 : 1900;
    }
    
    // Verificar se data inicial é maior que data final
    if (dqInicio.iAno > dqFinal.iAno ||
        (dqInicio.iAno == dqFinal.iAno && dqInicio.iMes > dqFinal.iMes) ||
        (dqInicio.iAno == dqFinal.iAno && dqInicio.iMes == dqFinal.iMes && dqInicio.iDia > dqFinal.iDia)) {
        dma.retorno = 4;
        return dma;
    }

    int dia1 = dqInicio.iDia;
    int mes1 = dqInicio.iMes;
    int ano1 = dqInicio.iAno;
    int dia2 = dqFinal.iDia;
    int mes2 = dqFinal.iMes;
    int ano2 = dqFinal.iAno;

    dma.qtdAnos = ano2 - ano1;
    dma.qtdMeses = mes2 - mes1;
    dma.qtdDias = dia2 - dia1;

    if (dma.qtdDias < 0) {
        dma.qtdMeses--;
        // Determinar dias no mês anterior ao mês final (mes2)
        int mesAnterior = mes2 - 1;
        int anoDoMesAnterior = ano2;
        if (mesAnterior == 0) { // Se mes2 era Janeiro, o anterior é Dezembro do ano anterior
            mesAnterior = 12;
            anoDoMesAnterior--;
        }
        
        int diasNoMesAnterior;
        switch (mesAnterior) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                diasNoMesAnterior = 31; break;
            case 4: case 6: case 9: case 11:
                diasNoMesAnterior = 30; break;
            case 2:
                diasNoMesAnterior = ((anoDoMesAnterior % 4 == 0 && anoDoMesAnterior % 100 != 0) || (anoDoMesAnterior % 400 == 0)) ? 29 : 28;
                break;
            default: // Não deve acontecer se as datas são válidas
                diasNoMesAnterior = 30; 
        }
        dma.qtdDias += diasNoMesAnterior;
    }

    if (dma.qtdMeses < 0) {
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
int q3(char *texto, char c, int isCaseSensitive) {
    int contador = 0;
    char charTexto;
    char charBusca = c;

    if (texto == NULL) return 0;

    if (!isCaseSensitive) {
        charBusca = tolower(c);
    }

    for (int i = 0; texto[i] != '\0'; i++) {
        charTexto = texto[i];
        if (!isCaseSensitive) {
            charTexto = tolower(texto[i]);
        }
        if (charTexto == charBusca) {
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
int q4(char *strTexto, char *strBusca, int posicoes[30]) {
    int qtdOcorrencias = 0;
    int idxPosicoes = 0; // Índice para o array posicoes

    if (!strTexto || !strBusca) return 0;

    // Calcular tamanhos manualmente para seguir estritamente a restrição,
    // embora strlen seja permitido nesta questão.
    int lenBusca = 0;
    char *temp = strBusca;
    while (*temp != '\0') {
        lenBusca++;
        temp++;
    }

    int lenTexto = 0;
    temp = strTexto;
    while (*temp != '\0') {
        lenTexto++;
        temp++;
    }
    
    if (lenBusca == 0) return 0; // Não é possível encontrar uma string vazia

    for (int i = 0; i <= lenTexto - lenBusca; ) {
        int achou = 1;
        for (int j = 0; j < lenBusca; j++) {
            // Usar normalizeChar para comparação case-insensitive e ignorando acentos
            if (normalizeChar(strTexto[i + j]) != normalizeChar(strBusca[j])) {
                achou = 0;
                break;
            }
        }

        if (achou) {
            if (idxPosicoes + 1 < 30) { // Garante espaço para par (início, fim)
                posicoes[idxPosicoes++] = i + 1;      // Posição inicial (base 1)
                posicoes[idxPosicoes++] = i + lenBusca; // Posição final (base 1)
                qtdOcorrencias++;
                i += lenBusca; // Pula a palavra encontrada para não haver sobreposição
            } else {
                break; // Array posicoes está cheio
            }
        } else {
            i++;
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
    int invertido = 0;
    int ehNegativo = 0;

    if (num == 0) return 0;

    if (num < 0) {
        ehNegativo = 1;
        // Cuidado com INT_MIN, -INT_MIN pode estourar.
        // Para este problema, vamos assumir que não ocorrerá ou que o comportamento padrão é aceitável.
        if (num == -2147483648) { // Caso especial para o menor int
             // Não é possível inverter diretamente -2147483648 para 2147483648 e depois processar,
             // pois 2147483648 pode ser maior que INT_MAX.
             // No entanto, o processo de inversão dígito a dígito pode funcionar.
             // Ex: -123 -> invertido = 321 -> retorna -321
             // Ex: -2147483648, o invertido seria -8463847412, que estoura int.
             // O problema não especifica o comportamento para estouro.
             // Vamos seguir a lógica original que pode resultar em estouro para números muito grandes.
        }
        num = -num; 
    }

    while (num > 0) {
        int digito = num % 10;
        // Checagem de estouro antes da multiplicação
        if (invertido > (2147483647 - digito) / 10) {
            // Estouro! O problema não diz como tratar. Retornar 0 ou o valor até o estouro?
            // Por simplicidade, a lógica original não trata isso explicitamente.
            // Se o número invertido estourar, o comportamento é indefinido pela linguagem C
            // ou resultará em um valor "enrolado".
        }
        invertido = invertido * 10 + digito;
        num /= 10;
    }

    return ehNegativo ? -invertido : invertido;
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
    // Nota: Esta solução usa sprintf e strlen. Se "funções próprias de string"
    // for uma restrição estrita que proíbe estas, a lógica precisaria ser
    // puramente matemática, o que é consideravelmente mais complexo.
    char baseStr[50];
    char buscaStr[50];

    // Lidar com número de busca sendo 0.
    // Se numerobusca é 0:
    //   Se numerobase também é 0, 0 ocorre em 0 uma vez ("0" em "0").
    //   Se numerobase é 10203, 0 ocorre 2 vezes.
    // A conversão para string lida bem com isso. "0" em "1020".
    
    sprintf(baseStr, "%d", numerobase);
    sprintf(buscaStr, "%d", numerobusca);

    int lenBase = strlen(baseStr);
    int lenBusca = strlen(buscaStr);
    int ocorrencias = 0;

    if (lenBusca == 0) return 0; // Busca vazia não ocorre
    if (lenBusca > lenBase) return 0; // Busca maior que base

    for (int i = 0; i <= lenBase - lenBusca; i++) {
        int encontrou = 1;
        for (int j = 0; j < lenBusca; j++) {
            if (baseStr[i + j] != buscaStr[j]) {
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
int q7(char matriz[8][10], char palavra[5]) {
    int linhas = 8, colunas = 10;
    int tamPalavra = strlen(palavra);

    if (tamPalavra == 0) return 0; // Palavra vazia não pode ser encontrada (ou 1 se interpretação diferente)

    // Direções: {dx, dy}
    // Horizontal ->, Horizontal <-
    // Vertical V, Vertical ^
    // Diagonal VD->, Diagonal VE->
    // Diagonal VD^, Diagonal VE^
    int direcoes[8][2] = {
        {0, 1},  // Direita
        {0, -1}, // Esquerda
        {1, 0},  // Baixo
        {-1, 0}, // Cima
        {1, 1},  // Diagonal Inferior Direita
        {1, -1}, // Diagonal Inferior Esquerda
        {-1, 1}, // Diagonal Superior Direita
        {-1, -1} // Diagonal Superior Esquerda
    };

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            for (int d = 0; d < 8; d++) { // Para cada uma das 8 direções
                int atualLin = i;
                int atualCol = j;
                int k; // Índice para a palavra

                for (k = 0; k < tamPalavra; k++) {
                    if (atualLin < 0 || atualLin >= linhas || atualCol < 0 || atualCol >= colunas ||
                        matriz[atualLin][atualCol] != palavra[k]) {
                        break; // Fora dos limites ou caractere não coincide
                    }
                    // Move para o próximo caractere na direção atual
                    if (k < tamPalavra -1) { // Só avança se não for o último char da palavra
                        atualLin += direcoes[d][0];
                        atualCol += direcoes[d][1];
                    }
                }

                if (k == tamPalavra) { // Todos os caracteres da palavra coincidiram
                    return 1; // Achou
                }
            }
        }
    }
    return 0; // Não achou
}

