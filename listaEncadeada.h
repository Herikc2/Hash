#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

#include <iostream>

template<typename T>
struct TElementoEncadeada {
    T dado;
    int quantidade;
    TElementoEncadeada *prox;
};

template<typename T>
struct TListaEncadeada {
    TElementoEncadeada<T> *inicio;
};

template<typename T>
void verificaExisteEncadeada(TListaEncadeada<T> l, T* dado);
template<typename T>
TElementoEncadeada<T>* navegadorEncadeadaAnterior(TListaEncadeada<T> l, int pos);
template<typename T>
int descobreIndiceEncadeada(TListaEncadeada<T> l, TElementoEncadeada<T> e);
template<typename T>
bool insereListaEncadeada(TListaEncadeada<T> &l, T dado, int pos);
template<typename T>
void BubbleSortEncadeada(TListaEncadeada<T> &l);

template<typename T>
TElementoEncadeada<T>* criarNovoElementoEncadeada(T dado) {
    TElementoEncadeada<T> *N = new TElementoEncadeada<T>();
    N->prox = nullptr;
    N->dado = dado;
    N->quantidade = 0;
    return N;
}

template<typename T>
int quantidadeElementosListaEncadeada(TListaEncadeada<T> l) {
    int cont = 0;
    TElementoEncadeada<T> *nav = l.inicio;
    while (true) {
        if (nav == nullptr)
            return cont;
        nav = nav->prox;
        cont++;
    }
}

template<typename T>
TElementoEncadeada<T>* navegadorEncadeadaAnterior(TListaEncadeada<T> l, int pos) {
    if (pos >= 0) {
        TElementoEncadeada<T> *nav = l.inicio;
        int i = 0;
        while (nav != nullptr && i < pos - 1) {
            nav = nav->prox;
            i++;
        }
        return nav;
    }
    return NULL;
}

template<typename T>
TElementoEncadeada<T>* navegadorEncadeadaAtual(TListaEncadeada<T> l, int pos) {
    if (pos >= 0) {
        TElementoEncadeada<T> *nav = l.inicio;
        for (int i = 0; i < pos; i++)
            nav = nav->prox;
        return nav;
    }
    return NULL;
}

template<typename T>
void inicializaListaEncadeada(TListaEncadeada<T> &l) {
    l.inicio = nullptr;
}

template<typename T>
bool insereListaEncadeada(TListaEncadeada<T> &l, T dado, int pos) {
    if (pos == 0) {
        TElementoEncadeada<T> *novo = criarNovoElementoEncadeada(dado);
        novo->prox = l.inicio;
        novo->quantidade++;
        l.inicio = novo;
        return true;
    }
    else {
        TElementoEncadeada<T> *nav = l.inicio;
        int i = 0;
        while (nav != nullptr && i < pos - 1) {
            nav = nav->prox;
            i++;
        }
        if (nav == nullptr) {
            return false;
        }
        else {
            TElementoEncadeada<T> *novo = criarNovoElementoEncadeada(dado);
            novo->prox = nav->prox;
            novo->quantidade++;
            nav->prox = novo;
            return true;
        }
    }
}

template<typename T>
bool removeListaEncadeada(TListaEncadeada<T> &l, int pos) {
    if (pos == 0)
    {
        TElementoEncadeada<T> *removido = l.inicio;
        l.inicio = removido->prox;
        delete removido;
        removido = nullptr;
    }
    else
    {
        TElementoEncadeada<T> *nav = navegadorEncadeadaAnterior(l, pos);
        if (nav == nullptr)
            return false;
        else {
            TElementoEncadeada<T> *removido = nav->prox;
            nav->prox = removido->prox;
            delete removido;
            removido = nullptr;
        }
    }
}

template<typename T>
TElementoEncadeada<T>* obtemDadoListaEncadeada(TListaEncadeada<T> l, int pos) {
    TElementoEncadeada<T> *nav = l.inicio;
    for (int i = 0; i < quantidadeElementosListaEncadeada(l); i++) {
        if (i == pos)
            return nav;
        nav = nav->prox;
    }
    return nav;
}

template<typename T>
void ImprimirElementoEncadeada(T dado) {
    ImprimirElementoEncadeada(dado);
}

template<typename T>
void ImprimirListaEncadeada(TListaEncadeada<T> l) {
    for (TElementoEncadeada<T>* nav = l.inicio; nav != nullptr; nav = nav->prox)
        ImprimirElementoEncadeada(nav->dado, nav->quantidade);
}

template<typename T>
void verificaExisteEncadeada(TListaEncadeada<T> l, T dado) {
    verificaExisteEncadeada(l, dado);
}

template<typename T>
int descobreIndiceEncadeada(TListaEncadeada<T> l, TElementoEncadeada<T> e) {
    int i = 0;
    for (TElementoEncadeada<T>* nav = l.inicio; nav != nullptr; nav = nav->prox, i++)
        if (verificaExisteEncadeada(*nav, e))
            return i;
    return -1;
}

#endif // LISTAESTATICA_H
