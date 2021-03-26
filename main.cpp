#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

#include "text.h"
#include "hashAberto.h"
#include "hashEncadeado.h"
#include "listaEncadeada.h"
#include "menu.h"

int main()
{
    // INICIALIZA ADD-ONS
    setlocale(LC_ALL, "Portuguese");
    srand(time(nullptr));
    // -------------------------------------------------------------------------------------------------------

    // INICIALIZAÇÃO DE VARIAVEIS
    Controle controle;
    int count_words = 0;
    // -------------------------------------------------------------------------------------------------------

    // INICIALIZAÇÃO DO SISTEMA TXT E CONTROLE
    int tamanho = contaPalavras(count_words);
    inicializaControle(controle, tamanho);
    controle.addList = false;
    // -------------------------------------------------------------------------------------------------------

    // CARREGAMENTO DE TODAS PALAVRAS EM UMA LISTA ENCADEADA EXTERNA
    carregaListaExterna(controle);
    // -------------------------------------------------------------------------------------------------------

    // MENU
    int  op = exibeMenu();
    // -------------------------------------------------------------------------------------------------------

    // CARREGA E IMPRIME O HASH ENCADEADO OU ABERTO
    escolhe(op, controle, tamanho);
    cout<< endl << endl;
    // -------------------------------------------------------------------------------------------------------

    return 0;
}
