#include "Controlador.hpp"
#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

Controlador::Controlador() {
    reiniciarNumerosAleatorios();
}

Controlador::~Controlador() {}

void Controlador::reiniciarNumerosAleatorios() {
    idsApendicitis.clear();
    habsApendicitis.clear();
    idsHernias.clear();
    habsHernias.clear();

    for(int i = 1; i <= 49; i++) idsApendicitis.push_back(i);
    for(int i = 101; i <= 199; i++) habsApendicitis.push_back(i);
    for(int i = 51; i <= 99; i++) idsHernias.push_back(i);
    for(int i = 201; i <= 299; i++) habsHernias.push_back(i);

    random_device rd;
    mt19937 g(rd());
    shuffle(idsApendicitis.begin(), idsApendicitis.end(), g);
    shuffle(habsApendicitis.begin(), habsApendicitis.end(), g);
    shuffle(idsHernias.begin(), idsHernias.end(), g);
    shuffle(habsHernias.begin(), habsHernias.end(), g);
}

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
            if (!idsApendicitis.empty() && !habsApendicitis.empty()) {
                p.setId(idsApendicitis.back()); idsApendicitis.pop_back();
                p.setHabitacion(habsApendicitis.back()); habsApendicitis.pop_back();
            }
            if (salaA.getLongitud() <= salaB.getLongitud()) {
                salaA.insertar(p);
            } else {
                salaB.insertar(p);
            }
        } else {
            if (!idsHernias.empty() && !habsHernias.empty()) {
                p.setId(idsHernias.back()); idsHernias.pop_back();
                p.setHabitacion(habsHernias.back()); habsHernias.pop_back();
            }
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
    while (salaA.getLongitud() > 0) quirofanoApendicitis.insertar(salaA.eliminar());
    while (salaB.getLongitud() > 0) quirofanoApendicitis.insertar(salaB.eliminar());
    while (salaC.getLongitud() > 0) quirofanoHernias.insertar(salaC.eliminar());
    while (salaD.getLongitud() > 0) quirofanoHernias.insertar(salaD.eliminar());
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
    reiniciarNumerosAleatorios();
}