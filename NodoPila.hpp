#ifndef NODOPILA_HPP
#define NODOPILA_HPP

#include "Paciente.hpp"

class NodoPila {
public:
    NodoPila(Paciente v, NodoPila* sig = NULL);
    ~NodoPila();

private:
    Paciente valor;
    NodoPila* siguiente;
    friend class Pila;
};

typedef NodoPila* pnodoPila;

#endif