#ifndef LISTA_HPP
#define LISTA_HPP

#include "NodoLista.hpp"

class Lista {
public:
    Lista();
    ~Lista();
    void insertar(Paciente v);
    void mostrar();
    int getLongitud();
    void vaciar();
    void mostrarPrimero();
    void mostrarUltimo();

private:
    pnodoLista cabeza;
    int longitud;
};

#endif