#include "Jugador.h"

Jugador::Jugador(){
    id = 0;
    cantidadCartas = 0;
}

Jugador::Jugador(int id_){
    id = id_;
    cantidadCartas = 0;
}

void Jugador::LimpiarMano(){
    cantidadCartas = 0;
}

void Jugador::RecibirCarta(Carta nueva){

    if(cantidadCartas < 12){
        mano[cantidadCartas] = nueva;
        cantidadCartas++;
        OrdenarMano();
    }
}

void Jugador::OrdenarMano(){

    Carta temporal;

    for(int i = 0; i < cantidadCartas - 1; i++){
        for(int j = i + 1; j < cantidadCartas; j++){
            if(mano[j].ObtenerValor() < mano[i].ObtenerValor()){
                temporal = mano[i];
                mano[i] = mano[j];
                mano[j] = temporal;
            }
        }
    }
}

void Jugador::MostrarMano(){

    if(cantidadCartas == 0){
        cout << "Sin cartas." << endl;
        return;
    }

    for(int i = 0; i < cantidadCartas; i++){
        cout << i + 1 << ". " << mano[i].ObtenerValor() << endl;
    }
}

Carta Jugador::JugarCarta(int posicion){

    Carta temporal = mano[posicion - 1];
    EliminarCarta(posicion);
    return temporal;
}

void Jugador::EliminarCarta(int posicion){

    if(posicion >= 1 && posicion <= cantidadCartas){

        for(int i = posicion - 1; i < cantidadCartas - 1; i++){
            mano[i] = mano[i + 1];
        }

        cantidadCartas--;
    }
}

int Jugador::ObtenerMenorCarta(){

    if(cantidadCartas > 0){
        return mano[0].ObtenerValor();
    }

    return 101;
}

bool Jugador::SinCartas(){
    return (cantidadCartas == 0);
}

int Jugador::ObtenerCantidadCartas(){
    return cantidadCartas;
}

int Jugador::ObtenerId(){
    return id;
}

int Jugador::DescartarMenoresIguales(int valor){

    int descartadas = 0;

    while(cantidadCartas > 0 && mano[0].ObtenerValor() <= valor){
        EliminarCarta(1);
        descartadas++;
    }

    return descartadas;
}