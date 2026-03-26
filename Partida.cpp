#include "Partida.h"

void LimpiarPantalla(){
    for(int i = 0; i < 35; i++){
        cout << endl;
    }
}

void Pausa(){
    cout << endl;
    cout << "Presione ENTER para continuar...";
    cin.ignore();
    cin.get();
}

Partida::Partida(){

    jugadores[0] = Jugador(1);
    jugadores[1] = Jugador(2);

    nivel = 1;
    vidas = 2;
    ultimaCarta = 0;
}

void Partida::NuevaPartida(){

    jugadores[0] = Jugador(1);
    jugadores[1] = Jugador(2);

    nivel = 1;
    vidas = 2;
    ultimaCarta = 0;

    PrepararNivel();
}

void Partida::PrepararNivel(){

    mazo.Inicializar();
    mazo.Barajar();

    jugadores[0].LimpiarMano();
    jugadores[1].LimpiarMano();

    ultimaCarta = 0;

    for(int i = 0; i < nivel; i++){
        jugadores[0].RecibirCarta(mazo.SacarCarta());
        jugadores[1].RecibirCarta(mazo.SacarCarta());
    }
}

void Partida::MostrarEstado(){

    cout << "============================" << endl;
    cout << "THE MIND" << endl;
    cout << "Nivel actual: " << nivel << endl;
    cout << "Vidas: " << vidas << endl;
    cout << "Ultima carta jugada: " << ultimaCarta << endl;
    cout << "============================" << endl << endl;
}

int Partida::MenorGlobal(){

    int menorUno = jugadores[0].ObtenerMenorCarta();
    int menorDos = jugadores[1].ObtenerMenorCarta();

    if(menorUno < menorDos){
        return menorUno;
    }

    return menorDos;
}

void Partida::AplicarError(int valorJugada){

    int descartadasJ1;
    int descartadasJ2;

    vidas--;

    descartadasJ1 = jugadores[0].DescartarMenoresIguales(valorJugada);
    descartadasJ2 = jugadores[1].DescartarMenoresIguales(valorJugada);

    ultimaCarta = valorJugada;

    cout << endl;
    cout << "Jugada incorrecta." << endl;
    cout << "Se pierde una vida." << endl;
    cout << "Cartas descartadas automaticamente hasta " << valorJugada << "." << endl;
    cout << "Descartadas del jugador 1: " << descartadasJ1 << endl;
    cout << "Descartadas del jugador 2: " << descartadasJ2 << endl;
}

bool Partida::NivelSuperado(){

    return (jugadores[0].SinCartas() && jugadores[1].SinCartas());
}

bool Partida::PartidaGanada(){

    return (nivel > 12);
}

bool Partida::PartidaPerdida(){

    return (vidas <= 0);
}

void Partida::GuardarPartida(){

    ofstream archivoSalida("partida.dat", ios::binary);

    if(archivoSalida.is_open()){
        archivoSalida.write((char*)this, sizeof(Partida));
        archivoSalida.close();
        cout << endl;
        cout << "Partida guardada correctamente." << endl;
    }else{
        cout << endl;
        cout << "No se pudo guardar la partida." << endl;
    }
}

bool Partida::CargarPartida(){

    ifstream archivoEntrada("partida.dat", ios::binary);

    if(archivoEntrada.is_open()){
        archivoEntrada.read((char*)this, sizeof(Partida));
        archivoEntrada.close();
        return true;
    }

    return false;
}

void Partida::TurnoJugador(int numeroJugador){

    int posicion;
    int menorCorrecto;
    Carta jugada;
    int valorJugada;

    menorCorrecto = MenorGlobal();

    cout << "Turno del jugador " << jugadores[numeroJugador].ObtenerId() << endl;
    cout << endl;
    cout << "Tu mano es:" << endl;
    jugadores[numeroJugador].MostrarMano();
    cout << endl;
    cout << "Seleccione la posicion de la carta que desea jugar: ";
    cin >> posicion;

    while(posicion < 1 || posicion > jugadores[numeroJugador].ObtenerCantidadCartas()){
        cout << "Posicion invalida. Intente otra vez: ";
        cin >> posicion;
    }

    jugada = jugadores[numeroJugador].JugarCarta(posicion);
    valorJugada = jugada.ObtenerValor();

    cout << endl;
    cout << "El jugador " << jugadores[numeroJugador].ObtenerId()
         << " jugo la carta " << valorJugada << "." << endl;

    if(valorJugada == menorCorrecto){
        ultimaCarta = valorJugada;
        cout << "Jugada correcta." << endl;
    }else{
        AplicarError(valorJugada);
    }

    Pausa();
}

void Partida::Jugar(){

    int opcion;

    while(!PartidaGanada() && !PartidaPerdida()){

        if(NivelSuperado()){

            if(nivel == 12){
                nivel++;
                break;
            }

            cout << "Nivel " << nivel << " superado." << endl;
            cout << "Se preparara el siguiente nivel." << endl;
            Pausa();

            nivel++;
            PrepararNivel();
            LimpiarPantalla();
        }

        for(int i = 0; i < 2; i++){

            if(jugadores[i].SinCartas()){
                continue;
            }

            LimpiarPantalla();
            MostrarEstado();

            cout << "Jugador " << jugadores[i].ObtenerId() << endl;
            cout << "1. Jugar carta" << endl;
            cout << "2. Guardar partida y salir" << endl;
            cout << "Seleccione una opcion: ";
            cin >> opcion;

            while(opcion < 1 || opcion > 2){
                cout << "Opcion invalida. Intente otra vez: ";
                cin >> opcion;
            }

            if(opcion == 2){
                GuardarPartida();
                return;
            }

            LimpiarPantalla();
            MostrarEstado();
            TurnoJugador(i);

            if(PartidaPerdida()){
                break;
            }

            if(NivelSuperado()){
                break;
            }
        }
    }

    LimpiarPantalla();

    if(PartidaGanada()){
        cout << "Felicidades, ganaron la partida." << endl;
    }else if(PartidaPerdida()){
        cout << "La partida ha terminado. Se quedaron sin vidas." << endl;
    }
}