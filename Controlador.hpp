#ifndef CONTROLADOR_HPP
#define CONTROLADOR_HPP

#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"

class Controlador {
public:
    Controlador();
    ~Controlador();

    void opcionA_generarPacientes();
    void opcionB_mostrarPila();
    void opcionC_borrarPila();
    void opcionD_pasarAColas();
    void opcionE_mostrarSalasAB();
    void opcionF_mostrarSalasCD();
    void opcionG_borrarSalas();
    void opcionH_pasarAListas();
    void opcionI_mostrarQuirofanoApendicitis();
    void opcionJ_mostrarQuirofanoHernias();
    void opcionK_buscarExtremos();
    void opcionL_reiniciar();

    int pacientesEnPila();
    int pacientesEnSalaA();
    int pacientesEnSalaB();
    int pacientesEnSalaC();
    int pacientesEnSalaD();
    int pacientesEnListaApendicitis();
    int pacientesEnListaHernias();

private:
    Pila pilaPacientes;
    Cola salaA;
    Cola salaB;
    Cola salaC;
    Cola salaD;
    Lista quirofanoApendicitis;
    Lista quirofanoHernias;

    int contadorIdApendicitis;
    int contadorIdHernias;
    int contadorHabitacionApendicitis;
    int contadorHabitacionHernias;
};

#endif