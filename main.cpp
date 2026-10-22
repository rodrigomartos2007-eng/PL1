#include <iostream>
#include <cctype> 
#include "Controlador.hpp"

using namespace std;

int main() {
    Controlador gestor;
    char opcion;

    do {
        // Mostramos los contadores en la parte superior
        cout << "Pacientes en la pila -> " << gestor.pacientesEnPila() << endl;
        cout << "Pacientes en las colas:" << endl;
        cout << "  Sala A-> " << gestor.pacientesEnSalaA() << endl;
        cout << "  Sala B-> " << gestor.pacientesEnSalaB() << endl;
        cout << "  Sala C-> " << gestor.pacientesEnSalaC() << endl;
        cout << "  Sala D-> " << gestor.pacientesEnSalaD() << endl;
        cout << "Pacientes en las listas:" << endl;
        cout << "  Quirofano Apendicitis-> " << gestor.pacientesEnListaApendicitis() << endl;
        cout << "  Quirofano hernias-> " << gestor.pacientesEnListaHernias() << endl;
        cout << "Pacientes en el arbol -> 0" << endl << endl;
        cout << "A. Generar 12 pacientes de forma aleatoria y almacenarlos en la Pila." << endl;
        cout << "B. Consultar todos los pacientes generados en la Pila (pendientes de entrar en las salas)." << endl;
        cout << "C. Borrar los pacientes generados en la pila." << endl;
        cout << "D. Simular llegada de los pacientes en las colas." << endl;
        cout << "E. Consultar los pacientes de las salas A y B." << endl;
        cout << "F. Consultar los pacientes de las salas C y D." << endl;
        cout << "G. Borrar los todos los pacientes de las salas." << endl;
        cout << "H. Simular la entrada de los pacientes a los quirofanos (a las listas)." << endl;
        cout << "I. Mostrar los pacientes que hay en el quirofano que atiende apendicitis." << endl;
        cout << "J. Mostrar los pacientes que hay en el quirofano que atiende hernias." << endl;
        cout << "K. Buscar en las listas el paciente con apendicitis de menor prioridad y el de hernia con mayor prioridad." << endl;
        cout << "L. Reiniciar el programa." << endl;
        cout << "S. Salir." << endl << endl;

        cout << "Indique la opcion deseada: ";
        cin >> opcion;
        opcion = toupper(opcion); 
        cout << endl;
        switch (opcion) {
            case 'A': gestor.opcionA_generarPacientes(); break;
            case 'B': gestor.opcionB_mostrarPila(); break;
            case 'C': gestor.opcionC_borrarPila(); break;
            case 'D': gestor.opcionD_pasarAColas(); break;
            case 'E': gestor.opcionE_mostrarSalasAB(); break;
            case 'F': gestor.opcionF_mostrarSalasCD(); break;
            case 'G': gestor.opcionG_borrarSalas(); break;
            case 'H': gestor.opcionH_pasarAListas(); break;
            case 'I': gestor.opcionI_mostrarQuirofanoApendicitis(); break;
            case 'J': gestor.opcionJ_mostrarQuirofanoHernias(); break;
            case 'K': gestor.opcionK_buscarExtremos(); break;
            case 'L': gestor.opcionL_reiniciar(); break;
            case 'S': cout << "Saliendo del programa..." << endl; break;
            default: cout << "Opcion no valida. Intentalo de nuevo." << endl; break;
        }
        cout << endl;

    } while (opcion != 'S');

    return 0;
}