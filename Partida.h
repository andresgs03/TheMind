#ifndef PARTIDA_H
#define PARTIDA_H

#include "Jugador.h"
#include "Mazo.h"
#include <fstream>
#include <iostream>

using namespace std;

class Partida{

    private:
        Jugador jugadores[2];
        Mazo mazo;
        int nivel;
        int vidas;
        int ultimaCarta;

    public:
        Partida();

        void NuevaPartida();
        void PrepararNivel();
        void MostrarEstado();
        void TurnoJugador(int numeroJugador);
        int MenorGlobal();
        void AplicarError(int valorJugada);
        bool NivelSuperado();
        bool PartidaGanada();
        bool PartidaPerdida();
        void GuardarPartida();
        bool CargarPartida();
        void Jugar();
};

#endif