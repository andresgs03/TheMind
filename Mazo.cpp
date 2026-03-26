#include "Mazo.h"
#include <cstdlib>

Mazo::Mazo(){
    Inicializar();
}

void Mazo::Inicializar(){

    for(int i = 0; i < 100; i++){
        cartas[i].FijarValor(i + 1);
    }

    siguiente = 0;
}

void Mazo::Barajar(){

    Carta temporal;
    int uno;
    int dos;

    for(int i = 0; i < 300; i++){
        uno = rand() % 100;
        dos = rand() % 100;

        temporal = cartas[uno];
        cartas[uno] = cartas[dos];
        cartas[dos] = temporal;
    }

    siguiente = 0;
}

Carta Mazo::SacarCarta(){

    if(siguiente < 100){
        Carta temporal = cartas[siguiente];
        siguiente++;
        return temporal;
    }

    return Carta(0);
}

bool Mazo::SinCartas(){
    return (siguiente >= 100);
}