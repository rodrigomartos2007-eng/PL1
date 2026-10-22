#include "Cola.hpp"

Cola::Cola() {
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}

void Cola::insertar(Paciente v) {
    pnodoCola nuevo;
    nuevo = new NodoCola(v);
    if (ultimo) {
        ultimo->siguiente = nuevo;
    }
    ultimo = nuevo;
    if (!primero) {
        primero = nuevo;
    }
    longitud++;
}

Paciente Cola::eliminar() {
    pnodoCola nodo;
    Paciente v;
    if (!primero) {
        return v;
    }
    nodo = primero;
    primero = nodo->siguiente;
    v = nodo->valor;
    longitud--;
    if (!primero) {
        ultimo = NULL;
    }
    delete nodo;
    return v;
}

void Cola::mostrar() {
    pnodoCola aux = primero;
    while (aux) {
        aux->valor.mostrar();
        aux = aux->siguiente;
    }
}

Paciente Cola::verPrimero() {
    if (!primero) {
        Paciente v;
        return v;
    }
    return primero->valor;
}

int Cola::getLongitud() {
    return longitud;
}

void Cola::vaciar() {
    pnodoCola aux;
    while (primero) {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
        longitud--;
    }
    ultimo = NULL;
}

Cola::~Cola() {
    vaciar();
}