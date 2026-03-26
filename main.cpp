#include "Partida.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

    srand(time(NULL));

    Partida juego;
    int opcion;

    cout << "============================" << endl;
    cout << "THE MIND - VERSION CONSOLA" << endl;
    cout << "============================" << endl;
    cout << "1. Nueva partida" << endl;
    cout << "2. Cargar partida" << endl;
    cout << "3. Salir" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    while(opcion < 1 || opcion > 3){
        cout << "Opcion invalida. Intente otra vez: ";
        cin >> opcion;
    }

    if(opcion == 1){
        juego.NuevaPartida();
        juego.Jugar();
    }else if(opcion == 2){
        if(juego.CargarPartida()){
            cout << "Partida cargada correctamente." << endl;
            juego.Jugar();
        }else{
            cout << "No existe una partida guardada." << endl;
        }
    }else{
        cout << "Programa finalizado." << endl;
    }

    return 0;
}