#ifndef CARTA_H
#define CARTA_H

class Carta{

    private:
        int valor;

    public:
        Carta();
        Carta(int valor_);

        int ObtenerValor();
        void FijarValor(int valor_);
};

#endif
