#include "Lista.hpp"
#include <iostream>

using namespace std;

Lista::Lista() {
    cabeza = NULL;
    longitud = 0;
}

void Lista::insertar(Paciente v) {
    pnodoLista nuevo;
    nuevo = new NodoLista(v);
    pnodoLista aux = cabeza;
    pnodoLista ant = NULL;

    while (aux && aux->valor.getId() < v.getId()) {
        ant = aux;
        aux = aux->siguiente;
    }

    if (!ant) {
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
    } else {
        ant->siguiente = nuevo;
        nuevo->siguiente = aux;
    }
    longitud++;
}

void Lista::mostrar() {
    pnodoLista aux = cabeza;
    while (aux) {
        aux->valor.mostrar();
        aux = aux->siguiente;
    }
}

int Lista::getLongitud() {
    return longitud;
}

void Lista::vaciar() {
    pnodoLista aux;
    while (cabeza) {
        aux = cabeza;
        cabeza = cabeza->siguiente;
        delete aux;
        longitud--;
    }
}

void Lista::mostrarPrimero() {
    if (cabeza != NULL) {
        cabeza->valor.mostrar();
    } else {
        cout << "La lista esta vacia." << endl;
    }
}

void Lista::mostrarUltimo() {
    pnodoLista aux = cabeza;
    if (aux != NULL) {
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->valor.mostrar();
    } else {
        cout << "La lista esta vacia." << endl;
    }
}

Lista::~Lista() {
    vaciar();
}