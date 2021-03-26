#ifndef MENU_H
#define MENU_H

#include "hashAberto.h"
#include "hashEncadeado.h"

int exibeMenu(){
    int op = 0;
    cout << endl << endl << endl << "Digite a opção de tabela hash que deseja aplicar:" << endl;
    cout << "1- Hash Aberto" << endl;
    cout << "2- Hash Encadeado" << endl;
    cout << "Opção: ";
    cin >> op;
    return op;
}

void escolhe(int op, Controle controle, int tamanho){
    int i = 0;
    if(op == 2){
        // HASH ENCADEADO
        HashEncadeado<string>* hashEncadeado = criaHashEncadeado<string>(tamanho);

        for(TElementoEncadeada<string>* nav = controle.listWords.inicio; nav != nullptr; nav = nav->prox, i++)
                insereHashComColisaoEncadeado(hashEncadeado, nav->dado, controle);

        cout << endl << endl;
        for(int i = 0; i < tamanho; i++) {
            cout << i << endl; // TESTE DE INDICE SÃ“ PARA VISUALIZAR UMA SEPARAÃ‡ÃƒO DE CADA LISTA E SABER QUAL ESTA VAZIA
            ImprimirListaEncadeada(hashEncadeado->elemento[i]->dado);
        }
        cout << endl << endl << "Tamano da Hash: " << hashEncadeado->table_size << endl;
        cout << endl << "Posicoes livres na tabela Hash: " << hashEncadeado->table_size - hashEncadeado->quantidade << endl;
        cout << endl << "Percentual de posicoes ocupadas: " <<
                ((hashEncadeado->quantidade*100)/hashEncadeado->table_size) << "%" << endl;
        cout << endl << "Numero de colisoes: " << hashEncadeado->nColisoes << endl;
        liberaHashEncadeado(hashEncadeado);
    }else if(op == 1){
        // HASH ABERTO
        HashAberto<string>* hashAberto = criaHashAberto<string>(tamanho);

        for(TElementoEncadeada<string>* nav = controle.listWords.inicio; nav != nullptr && i <= tamanho; nav = nav->prox, i++)
            insereHashComColisaoAberto(hashAberto, nav->dado, controle);
        cout << endl;
        for(int i = 0; i < tamanho; i++)
            if(hashAberto->elemento[i] != nullptr)
                cout << hashAberto->elemento[i]->dado << " - " << i << " - Quantidade: " << hashAberto->elemento[i]->quantidade << endl;
        cout << endl << endl << "Tamanho da Hash: " << hashAberto->table_size << endl;
        cout << endl << "Posições livres na tabela Hash: " << hashAberto->table_size - hashAberto->quantidade << endl;
        cout << endl << "Posições ocupadas: " << hashAberto->quantidade << endl;
        cout << endl << "Percentual de posições ocupadas: " <<
                ((hashAberto->quantidade*100)/hashAberto->table_size) << "%" << endl;
        cout << endl << "Numero de colisões: " << hashAberto->nColisoes << endl;
        liberaHashAberto(hashAberto);
    }
}

#endif // MENU_H
