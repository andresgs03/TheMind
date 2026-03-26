#ifndef JUGADOR_H
#define JUGADOR_H

#include "Carta.h"
#include <iostream>

using namespace std;

class Jugador{

    private:
        int id;
        Carta mano[12];
        int cantidadCartas;

    public:
        Jugador();
        Jugador(int id_);

        void LimpiarMano();
        void RecibirCarta(Carta nueva);
        void OrdenarMano();
        void MostrarMano();
        Carta JugarCarta(int posicion);
        void EliminarCarta(int posicion);
        int ObtenerMenorCarta();
        bool SinCartas();

        int ObtenerCantidadCartas();
        int ObtenerId();
        int DescartarMenoresIguales(int valor);
};

#endif