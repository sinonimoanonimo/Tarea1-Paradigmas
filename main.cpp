#include "SistemaEntrenamiento.h"

int main() {
    GestorRutinas gestor;
    int opcion;

    do {
        cout << "\n=== MENU DE GESTION DE ENTRENAMIENTO ===" << endl;
        cout << "1. Crear un ejercicio" << endl;
        cout << "2. Actualizar un ejercicio" << endl;
        cout << "3. Eliminar un ejercicio" << endl;
        cout << "4. Consultar informacion de un ejercicio" << endl;
        cout << "5. Buscar ejercicios por intensidad" << endl;
        cout << "6. Generar una rutina de entrenamiento" << endl;
        cout << "7. Avanzar a la siguiente semana" << endl;
        cout << "8. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                gestor.crearEjercicio();
                break;
            case 2:
                gestor.actualizarEjercicio();
                break;
            case 3:
                gestor.eliminarEjercicio();
                break;
            case 4:
                gestor.consultarEjercicio();
                break;
            case 5:
                gestor.buscarPorIntensidad();
                break;
            case 6:
                gestor.generarRutina();
                break;
            case 7:
                gestor.avanzarSemana();
                break;
            case 8:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
                break;
        }
    } while (opcion != 8);

    return 0;
}