#ifndef HASHABERTO_H
#define HASHABERTO_H

#include "hashGeral.h"

template <typename TIPO>
struct TElementoHashAberto{
     TIPO dado;
     int chave;
     int quantidade;
};

template <typename TIPO> // TAMANHO -> NUMERO PRIMO E NÃO POTENCIA DE 2
struct HashAberto{
    int nColisoes = 0;
    int quantidade = 0;
    int table_size = 0;
    TElementoHashAberto<string>** elemento;
};

template <typename TIPO>
TElementoHashAberto<TIPO>* newElementoAberto(){
    TElementoHashAberto<TIPO>* novo = new TElementoHashAberto<TIPO>;
    novo->quantidade = 0;
    return novo;
}

template <typename TIPO>
HashAberto<TIPO>* criaHashAberto(int tamanho){
    if(tamanho > 0){
        HashAberto<TIPO>* ha = new HashAberto<TIPO>();
        ha->table_size = tamanho;
        ha->quantidade = 0;
        ha->elemento = new TElementoHashAberto<TIPO>*[tamanho];
        for(int i = 0; i < tamanho; i++)
            ha->elemento[i] = NULL;
        return ha;
    }
    return NULL;
}

template <typename TIPO>
void liberaHashAberto(HashAberto<TIPO>*& ha){
    if(ha != NULL){
        ha->elemento = NULL;
        ha = NULL;
    }
}

template <typename TIPO>
bool insereHashComColisaoAberto(HashAberto<TIPO>*& ha, TIPO dado, Controle c){
    if(ha == NULL || ha->quantidade == ha->table_size)
        return false;
    int chave = 0, newPos;

    chave = stringToInt(dado);
    for(int i = 0; i < ha->table_size; i++){
        newPos = duploHash(sondagemQuadratica(chave, i, ha->table_size, c.x, c.y),
                           chaveUniversal(c.a, c.b, chave, c.p, ha->table_size), i, ha->table_size);
        TElementoHashAberto<TIPO>* aux = newElementoAberto<TIPO>();
        aux = ha->elemento[newPos];
        if(aux == NULL){
            TElementoHashAberto<TIPO>* novo = new TElementoHashAberto<TIPO>();
            if(novo == NULL)
                return false;
            else{
                novo->dado = dado;
                novo->chave = chave;
                ha->elemento[newPos] = novo;
                ha->elemento[newPos]->quantidade++;
                ha->quantidade++;
                return true;
            }
        }else {
            ha->nColisoes++;
            if(aux->dado == dado) {
                aux->quantidade++;
                return true;
             }
        }
    }
    return false;
}

template <typename TIPO>
int buscaHashComColisaoAberto(HashAberto<TIPO>*& ha, int chaveDescodificada, Controle c){
    if(ha == NULL)
        return NULL;
    int pos, newPos;
    pos = chaveUniversal(c.a, c.b, chaveDescodificada, c.p, ha->table_size);
    for(int i = 0; i < ha->table_size;i++){
        newPos = duploHash(sondagemQuadratica(pos, i, ha->table_size, c.x, c.y),
                           chaveUniversal(c.a, c.b, chaveDescodificada, c.p, ha->table_size), i, ha->table_size);
        if(ha->elemento[newPos] == NULL)
            return NULL;
        if(ha->elemento[newPos]->chave == chaveDescodificada) // .DADO.CHAVE DADO DENTRO DA PALAVRA PARA CHAVE INTERNA
            return newPos;
    }
    return NULL;
}

#endif // HASHABERTO_H
