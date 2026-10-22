#include "Pila.hpp"

Pila::Pila() {
    ultimo = NULL;
    longitud = 0;
}

void Pila::insertar(Paciente v) {
    pnodoPila nuevo;
    nuevo = new NodoPila(v, ultimo);
    ultimo = nuevo;
    longitud++;
}

Paciente Pila::extraer() {
    pnodoPila nodo;
    Paciente v;
    if (!ultimo) return v;
    nodo = ultimo;
    ultimo = nodo->siguiente;
    v = nodo->valor;
    longitud--;
    delete nodo;
    return v;
}

Paciente Pila::cima() {
    if (!ultimo) {
        Paciente v;
        return v;
    }
    return ultimo->valor;
}

void Pila::mostrar() {
    pnodoPila aux = ultimo;
    while (aux) {
        aux->valor.mostrar();
        aux = aux->siguiente;
    }
}

int Pila::getLongitud() {
    return longitud;
}

void Pila::vaciar() {
    pnodoPila aux;
    while (ultimo) {
        aux = ultimo;
        ultimo = ultimo->siguiente;
        delete aux;
    }
    longitud = 0;
}

Pila::~Pila() {
    vaciar();
}