#include "Carta.h"

Carta::Carta(){
    valor = 0;
}

Carta::Carta(int valor_){
    valor = valor_;
}

int Carta::ObtenerValor(){
    return valor;
}

void Carta::FijarValor(int valor_){
    valor = valor_;
}