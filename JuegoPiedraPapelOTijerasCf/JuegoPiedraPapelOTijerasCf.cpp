#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream> // Para usar stringstream

using namespace std;

int main() {
    string opciones[3] = {"Piedra", "Papel", "Tijera"};
    int eleccionUsuario, eleccionComputadora, ronda = 1;
    string historial[3]; // Guardar las elecciones

    srand(time(0)); // Inicializa el generador de n�meros aleatorios

    for (ronda = 1; ronda <= 3; ronda++) { // Jugar 3 rondas
        cout << "\nRonda " << ronda << " - Elige una opcion:" << endl;
        cout << "1. Piedra" << endl;
        cout << "2. Papel" << endl;
        cout << "3. Tijera" << endl;
        cin >> eleccionUsuario;

        // Validar la entrada del usuario
        if (eleccionUsuario < 1 || eleccionUsuario > 3) {
            cout << "Elecci�n no v�lida. Debe ser 1, 2 o 3." << endl;
            return 1; // Salir del programa con un c�digo de error
        }

        eleccionComputadora = rand() % 3;

        // Convertir ronda a string usando stringstream
        stringstream ss;
        ss << "Ronda " << ronda << ": Usuario -> " << opciones[eleccionUsuario-1] << ", Computadora -> " << opciones[eleccionComputadora];
        historial[ronda-1] = ss.str();

        // Mostrar las elecciones
        cout << "Tu eleccion: " << opciones[eleccionUsuario - 1] << endl;
        cout << "Eleccion de la computadora: " << opciones[eleccionComputadora] << endl;

        // Determinar el resultado
        if (eleccionUsuario - 1 == eleccionComputadora) {
            cout << "Empate!" << endl;
        } else if ((eleccionUsuario - 1 == 0 && eleccionComputadora == 1) ||
                   (eleccionUsuario - 1 == 1 && eleccionComputadora == 2) ||
                   (eleccionUsuario - 1 == 2 && eleccionComputadora == 0)) {
            cout << "Perdiste!" << endl;
        } else {
            cout << "Ganaste!" << endl;
        }
    }

    // Mostrar el historial
    cout << "\nHistorial de las elecciones:\n";
    for (int i = 0; i < 3; i++) {
        cout << historial[i] << endl;
    }

    return 0;
}

