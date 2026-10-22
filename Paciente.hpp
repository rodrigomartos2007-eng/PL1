#ifndef PACIENTE_HPP
#define PACIENTE_HPP

#include <iostream>
#include <cstdlib>

using namespace std;

class Paciente {
public:
    Paciente();
    ~Paciente();
    bool tieneApendicitis();
    int getId();
    int getHabitacion();
    void setId(int id);
    void setHabitacion(int habitacion);
    void mostrar();

private:
    bool apendicitis;
    int id;
    int habitacion;
    char DNI[10];
    
    void generarDNI();
};

#endif