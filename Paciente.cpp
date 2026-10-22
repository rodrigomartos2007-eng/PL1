#include "Paciente.hpp"

Paciente::Paciente()
{
    this->apendicitis = (rand() % 2); 
    this->generarDNI();
    this->id = 0;
    this->habitacion = 0;
}

bool Paciente::tieneApendicitis()
{
    return this->apendicitis;
}

int Paciente::getId()
{
    return this->id;
}

int Paciente::getHabitacion()
{
    return this->habitacion;
}

void Paciente::setId(int id)
{
    this->id = id;
}

void Paciente::setHabitacion(int habitacion)
{
    this->habitacion = habitacion;
}

void Paciente::mostrar()
{
    if (this->id == 0) {
        // Si está en la pila (sin ID asignado todavía)
        if (this->apendicitis)
            cout << "El paciente cuyo DNI es " << this->DNI << " tiene apendicitis" << endl;
        else
            cout << "El paciente cuyo DNI es " << this->DNI << " tiene hernias" << endl;
    } else {
        // Si ya pasó al preoperatorio o listas (con ID y habitación)
        if (this->apendicitis)
            cout << "El paciente cuyo DNI es " << this->DNI << " tiene apendicitis, su ID es: " << this->id << " y su habitacion asignada es: " << this->habitacion << endl;
        else
            cout << "El paciente cuyo DNI es " << this->DNI << " tiene hernias, su ID es: " << this->id << " y su habitacion asignada es: " << this->habitacion << endl;
    }
}

// Versión ultra sencilla para generar un DNI ficticio
void Paciente::generarDNI()
{
    // Generamos 8 números aleatorios (del '0' al '9')
    for(int i = 0; i < 8; i++) {
        this->DNI[i] = '0' + (rand() % 10);
    }
    
    // Asignamos una letra aleatoria para simplificar (de la 'A' a la 'Z')
    char letras[] = "TRWAGMYFPDXBNJZSQVHLCKE";
    this->DNI[8] = letras[rand() % 23];
    
    // Carácter nulo al final para cerrar la cadena de texto
    this->DNI[9] = '\0';
}

Paciente::~Paciente()
{
}