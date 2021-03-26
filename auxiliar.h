#ifndef AUXILIAR_H
#define AUXILIAR_H

#include <iostream>

using namespace std;

int geraAleatorio(int a, int b);
int geraPrimo(int a, int b);

int geraPrimo(int a, int b){
    int contador = 0;
    int temp = 0;
    bool exit = false;

    while(!exit){
        temp = geraAleatorio(a,b);
        for(int i = 2; i < temp / 2; i++)
            if(temp % i == 0){
                contador++;
                break;
            }
        if(contador != 0)
            contador = 0;
        else
            exit = true;
    }
    return temp;
}

int geraAleatorio(int a, int b){
    return a + (rand()%(b-a));;
}

#endif // AUXILIAR_H
