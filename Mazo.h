#ifndef MAZO_H
#define MAZO_H

#include "Carta.h"

class Mazo{

    private:
        Carta cartas[100];
        int siguiente;

    public:
        Mazo();

        void Inicializar();
        void Barajar();
        Carta SacarCarta();
        bool SinCartas();
};

#endif