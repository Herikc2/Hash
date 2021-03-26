#ifndef HASHGERAL_H
#define HASHGERAL_H

#include "text.h"

int stringToInt(string word){
    int valor = 7;
    for(int i = 0; i < word.length(); i++)
        if(word[i] == ' ')
            continue;
        else valor = 31 * valor + (int)word[i];
    return valor;
}

/*int stringToInt(char *str){
    int valor = 7;
    int tam = strlen(str);
    for(int i = 0; i < tam; i++)
        valor = 31 * valor + (int)str[i];
    return valor;
}*/

int chaveRestoDivisao(int chave, int size){
    return (chave & 0x7FFFFFFF) % size;
}

int sondagemLinear(int chave, int i, int size){
    return ((chave + i) & 0x7FFFFFFF) % size;
}

// FUNÇÃO UNIVERSAL PARA HASH, DE MANEIRA QUE EVITA O DESCOBRIMENTO DA CHAVE.
// REGRAS:
// K É A CHAVE
// 0 <= K < P
// P É MAIOR DO QUE O TAMANHO DO HASH E É UM NUMERO PRIMO
// 0 < A <= P
// 0 <= B < P
int chaveUniversal(int a, int b, int chave, int p, int size){
    return (((a*chave) + b) % p) % size;
}

int duploHash(int h1, int h2, int i, int size){
    return ((h1 + i * h2) & 0x7FFFFFFF) % size;
}

int sondagemQuadratica(int pos, int i, int size, int x, int y){
    pos = x*i*i + y*i + pos;
    return (pos  & 0x7FFFFFFF) % size;
}

#endif // HASHGERAL_H
