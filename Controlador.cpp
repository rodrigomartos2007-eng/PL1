#include "Controlador.hpp"
#include <iostream>

using namespace std;

Controlador::Controlador() {
    contadorIdApendicitis = 1;
    contadorHabitacionApendicitis = 101;
    contadorIdHernias = 51;
    contadorHabitacionHernias = 201;
}

Controlador::~Controlador() {}

int Controlador::pacientesEnPila() { return pilaPacientes.getLongitud(); }
int Controlador::pacientesEnSalaA() { return salaA.getLongitud(); }
int Controlador::pacientesEnSalaB() { return salaB.getLongitud(); }
int Controlador::pacientesEnSalaC() { return salaC.getLongitud(); }
int Controlador::pacientesEnSalaD() { return salaD.getLongitud(); }
int Controlador::pacientesEnListaApendicitis() { return quirofanoApendicitis.getLongitud(); }
int Controlador::pacientesEnListaHernias() { return quirofanoHernias.getLongitud(); }

void Controlador::opcionA_generarPacientes() {
    for (int i = 0; i < 12; i++) {
        if (pilaPacientes.getLongitud() < 48) {
            Paciente p;
            pilaPacientes.insertar(p);
        }
    }
}

void Controlador::opcionB_mostrarPila() {
    pilaPacientes.mostrar();
}

void Controlador::opcionC_borrarPila() {
    pilaPacientes.vaciar();
}

void Controlador::opcionD_pasarAColas() {
    while (pilaPacientes.getLongitud() > 0) {
        Paciente p = pilaPacientes.extraer();

        if (p.tieneApendicitis()) {
            p.setId(contadorIdApendicitis++);
            p.setHabitacion(contadorHabitacionApendicitis++);
            if (salaA.getLongitud() <= salaB.getLongitud()) {
                salaA.insertar(p);
            } else {
                salaB.insertar(p);
            }
        } else {
            p.setId(contadorIdHernias++);
            p.setHabitacion(contadorHabitacionHernias++);
            if (salaC.getLongitud() <= salaD.getLongitud()) {
                salaC.insertar(p);
            } else {
                salaD.insertar(p);
            }
        }
    }
}

void Controlador::opcionE_mostrarSalasAB() {
    cout << "Sala A:" << endl;
    salaA.mostrar();
    cout << "Sala B:" << endl;
    salaB.mostrar();
}

void Controlador::opcionF_mostrarSalasCD() {
    cout << "Sala C:" << endl;
    salaC.mostrar();
    cout << "Sala D:" << endl;
    salaD.mostrar();
}

void Controlador::opcionG_borrarSalas() {
    salaA.vaciar();
    salaB.vaciar();
    salaC.vaciar();
    salaD.vaciar();
}

void Controlador::opcionH_pasarAListas() {
    while (salaA.getLongitud() > 0) {
        Paciente p = salaA.eliminar();
        quirofanoApendicitis.insertar(p);
    }
    while (salaB.getLongitud() > 0) {
        Paciente p = salaB.eliminar();
        quirofanoApendicitis.insertar(p);
    }
    while (salaC.getLongitud() > 0) {
        Paciente p = salaC.eliminar();
        quirofanoHernias.insertar(p);
    }
    while (salaD.getLongitud() > 0) {
        Paciente p = salaD.eliminar();
        quirofanoHernias.insertar(p);
    }
}

void Controlador::opcionI_mostrarQuirofanoApendicitis() {
    quirofanoApendicitis.mostrar();
}

void Controlador::opcionJ_mostrarQuirofanoHernias() {
    quirofanoHernias.mostrar();
}

void Controlador::opcionK_buscarExtremos() {
    cout << "Apendicitis menor prioridad ->> " << endl;
    quirofanoApendicitis.mostrarUltimo();
    cout << "Hernias mayor prioridad ->> " << endl;
    quirofanoHernias.mostrarPrimero();
}

void Controlador::opcionL_reiniciar() {
    pilaPacientes.vaciar();
    salaA.vaciar();
    salaB.vaciar();
    salaC.vaciar();
    salaD.vaciar();
    quirofanoApendicitis.vaciar();
    quirofanoHernias.vaciar();

    contadorIdApendicitis = 1;
    contadorHabitacionApendicitis = 101;
    contadorIdHernias = 51;
    contadorHabitacionHernias = 201;
}