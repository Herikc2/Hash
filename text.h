#ifndef TEXT_H
#define TEXT_H

#include <iomanip>
#include <fstream>
#include "string"

#include "listaEncadeada.h"
#include "auxiliar.h"

#define LIMFILTER 2

using namespace std;

struct Controle {
    int a, b, p, x, y;
    int position = 0;
    int count = 0;
    TListaEncadeada<string> listWords;
    bool addList = false;
};

void inicializaControle(Controle& c, int size){
    inicializaListaEncadeada(c.listWords);
    c.p = geraPrimo(size, LONG_MAX);
    c.a = geraAleatorio(1, c.p);
    c.b = geraAleatorio(0, c.p);
    c.x = geraAleatorio(1, INT_MAX);
    c.y = geraAleatorio(1, INT_MAX);
}

void addWord(Controle& c, string& aux) {
    int tam = aux.length();
    for(int i = 0; i < tam; i++){
        if(aux[i] == ',' || aux[i] == '.' || aux[i] == ';' ){
            aux[i] = ' ';
        }
        aux[i] = tolower(aux[i]);
    }
    if(c.count > 1){
        if(tam > LIMFILTER){
            insereListaEncadeada(c.listWords, aux, c.position);
            c.position++;
        }

    }
    c.count = 0;
    aux = "";
    c.addList = false;
}


int contaPalavras(int count_words){
    ifstream txtFile;
    string aux = "";
    char pre_c;
    txtFile.open("C:/Users/herik/OneDrive/Documents/hashFinal/text.txt");
    while(txtFile.get(pre_c))
        if(pre_c == ' '){
            if(aux.length() > LIMFILTER){
                count_words++;
                aux="";
            }
        }
        else
            if(pre_c == ',' || pre_c == '.' || pre_c == ';' || pre_c == ' ')
                continue;
            else
                aux += pre_c;

    aux="";
    int tamanho = (int)(count_words + 1) * 0.25;
    if(tamanho == 0) tamanho = 1;
    txtFile.close();
    return tamanho;
}

void carregaListaExterna(Controle& controle){
    ifstream txtFile;
    char c;
    string aux = "";
    txtFile.open("C:/Users/herik/OneDrive/Documents/hashFinal/text.txt");
    int count_space = 0;

    while(txtFile.get(c)){
        if(c == ' ' || c == '\n'){
            controle.addList = true;
            count_space++;
         }
        else {
            if(!(c == ',' || c == '.' || c == ';' || c == ' ' || c == '\n' || count_space >= 2))
            {
                aux += c;
                count_space = 0;
            }
            controle.count++;
        }
        if(controle.addList)
            addWord(controle, aux);
        cout << c;
    }
    addWord(controle, aux);
    txtFile.close();
}

#endif // TEXT_H
