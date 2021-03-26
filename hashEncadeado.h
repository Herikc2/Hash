#ifndef HASHENCADEADO_H
#define HASHENCADEADO_H

#include "hashGeral.h"

template <typename TIPO>
struct TElementoHashEncadeado{
     TListaEncadeada<TIPO> dado;
     int chave;
     int quantidade;
};

template <typename TIPO>
struct HashEncadeado{
    int nColisoes = 0;
    int quantidade = 0;
    int table_size = 0;
    TElementoHashEncadeado<TIPO>** elemento;
};

template <typename TIPO>
TElementoHashEncadeado<TIPO>* newElementoEncadeado(){
    TElementoHashEncadeado<TIPO>* novo = new TElementoHashEncadeado<TIPO>;
    novo->quantidade = 0;
    return novo;
}

template <typename TIPO>
HashEncadeado<TIPO>* criaHashEncadeado(int tamanho){
    if(tamanho > 0){
        HashEncadeado<TIPO>* ha = new HashEncadeado<TIPO>();
        ha->table_size = tamanho;
        ha->quantidade = 0;
        ha->elemento = new TElementoHashEncadeado<TIPO>*[tamanho];
        for(int i = 0; i < tamanho; i++)
            ha->elemento[i] = new TElementoHashEncadeado<TIPO>();
        for(int i = 0; i < tamanho; i++)
            inicializaListaEncadeada(ha->elemento[i]->dado);
        return ha;
    }
    return NULL;
}

template <typename TIPO>
void liberaHashEncadeado(HashEncadeado<TIPO>*& ha){
    if(ha != NULL){
        ha->elemento = NULL;
        ha = NULL;
    }
}

template <typename TIPO>
bool insereHashComColisaoEncadeado(HashEncadeado<TIPO>*& ha, TIPO dado, Controle c){
    int i = 0;

    if(ha == NULL)
        return false;
    int chave = 0, newPos;

    chave = stringToInt(dado); // CONVERTE A PALAVRA DE STRING PARA VALORES DADOS EM INT NA TABELA ASCII
    newPos = duploHash(sondagemQuadratica(chave, 0, ha->table_size, c.x, c.y), chaveUniversal(c.a, c.b, chave, c.p, ha->table_size),
                       0, ha->table_size);
    //cout << endl << "chave: " << chave << endl;
    //cout << endl << "newPos: " << newPos << endl;
    for(TElementoEncadeada<TIPO>* nav = ha->elemento[newPos]->dado.inicio; nav != nullptr; nav = nav->prox, i++)
        if(nav->dado == dado){
            obtemDadoListaEncadeada(ha->elemento[newPos]->dado, i)->quantidade++;
            return true;
        }

    if(ha->elemento[newPos]->dado.inicio != NULL)
        ha->nColisoes++;
    else
        ha->quantidade++;

    if(insereListaEncadeada(ha->elemento[newPos]->dado, dado, ha->elemento[newPos]->quantidade)){
        ha->elemento[newPos]->chave = chave;
        ha->elemento[newPos]->quantidade++;
        return true;
    }
    return false;
}

// FALTA FAZER FUNÇÃO DE BUSCA DA LISTA ENCADEADA. NO MOMENTO [E UMA EXATA CÓPIA DA FUNÇÃO DO HASH ABERTO
template <typename TIPO>
TElementoHashEncadeado<TIPO> buscaHashComColisaoEncadeado(HashEncadeado<TIPO>*& ha, int chaveDescodificada, Controle c){
    if(ha == NULL)
        return NULL;
    int pos, newPos;
    pos = chaveUniversal(c.a, c.b, chaveDescodificada, c.p, ha->table_size);
    for(int i = 0; i < ha->table_size;i++){
        newPos = duploHash(sondagemQuadratica(pos, 0, ha->table_size, c.x, c.y),
                           chaveUniversal(c.a, c.b, chaveDescodificada, c.p, ha->table_size), 0, ha->table_size);
        if(ha->elemento[newPos] == NULL)
            return NULL;
        if(ha->elemento[newPos]->chave == chaveDescodificada)
            return ha->elemento[newPos];
    }
    return NULL;
}

void ImprimirElementoEncadeada(string dado, int qtd) {
    cout << dado << " - Quantidade: " << qtd << endl;
}

#endif // HASHENCADEADO_H
