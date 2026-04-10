#include "SistemaEntrenamiento.h"

// Implementacion de Ejercicio
Ejercicio::Ejercicio(int id, string nombre, string intensidad, int tiempoMinutos, string descripcion, int ultimaSemanaUsado) {
    this->id = id;
    this->nombre = nombre;
    this->intensidad = intensidad;
    this->tiempoMinutos = tiempoMinutos;
    this->descripcion = descripcion;
    this->ultimaSemanaUsado = ultimaSemanaUsado;
}

void Ejercicio::mostrarInformacion() const {
    cout << "ID: " << id << " | Nombre: " << nombre << " | Tipo: " << getTipo() << endl;
    cout << "Intensidad: " << intensidad << " | Tiempo: " << tiempoMinutos << " min" << endl;
    cout << "Descripcion: " << descripcion << endl;
    cout << "Ultima semana usado: " << (ultimaSemanaUsado == 0 ? "Nunca" : to_string(ultimaSemanaUsado)) << endl;
    cout << "--------------------------------------------------" << endl;
}

int Ejercicio::getId() const { return id; }
string Ejercicio::getIntensidad() const { return intensidad; }
int Ejercicio::getTiempo() const { return tiempoMinutos; }
int Ejercicio::getUltimaSemana() const { return ultimaSemanaUsado; }
void Ejercicio::setUltimaSemana(int semana) { ultimaSemanaUsado = semana; }

void Ejercicio::actualizarDatos(string nuevoNombre, string nuevaIntensidad, int nuevoTiempo, string nuevaDescripcion) {
    this->nombre = nuevoNombre;
    this->intensidad = nuevaIntensidad;
    this->tiempoMinutos = nuevoTiempo;
    this->descripcion = nuevaDescripcion;
}

// Implementacion de EjercicioCardio
EjercicioCardio::EjercicioCardio(int id, string nombre, string intensidad, int tiempoMinutos, string descripcion, int ultimaSemanaUsado) 
    : Ejercicio(id, nombre, intensidad, tiempoMinutos, descripcion, ultimaSemanaUsado) {}

string EjercicioCardio::getTipo() const { return "Cardiovascular"; }

// Implementacion de EjercicioFuerza
EjercicioFuerza::EjercicioFuerza(int id, string nombre, string intensidad, int tiempoMinutos, string descripcion, int ultimaSemanaUsado) 
    : Ejercicio(id, nombre, intensidad, tiempoMinutos, descripcion, ultimaSemanaUsado) {}

string EjercicioFuerza::getTipo() const { return "Fuerza"; }

// Implementacion de GestorRutinas
GestorRutinas::GestorRutinas() {
    semanaActual = 1;
}

GestorRutinas::~GestorRutinas() {
    for (Ejercicio* ej : listaEjercicios) {
        delete ej;
    }
    listaEjercicios.clear();
}

void GestorRutinas::crearEjercicio() {
    int id, tipo, tiempo;
    string nombre, intensidad, descripcion;

    cout << "\n--- CREAR EJERCICIO ---" << endl;
    cout << "ID: ";
    cin >> id;

    // Validar si el ID ya existe
    for (Ejercicio* ej : listaEjercicios) {
        if (ej->getId() == id) {
            cout << "Error: Ya existe un ejercicio con ese ID." << endl;
            return;
        }
    }

    cin.ignore();
    cout << "Nombre del ejercicio: ";
    getline(cin, nombre);

    cout << "Tipo (1: Cardio, 2: Fuerza): ";
    cin >> tipo;

    cin.ignore();
    cout << "Nivel de intensidad (Basico, Intermedio, Avanzado, Alto rendimiento): ";
    getline(cin, intensidad);

    cout << "Tiempo estimado (minutos): ";
    cin >> tiempo;

    cin.ignore();
    cout << "Descripcion: ";
    getline(cin, descripcion);

    Ejercicio* nuevoEjercicio = nullptr;
    if (tipo == 1) {
        nuevoEjercicio = new EjercicioCardio(id, nombre, intensidad, tiempo, descripcion, 0);
    } else {
        nuevoEjercicio = new EjercicioFuerza(id, nombre, intensidad, tiempo, descripcion, 0);
    }

    listaEjercicios.push_back(nuevoEjercicio);
    cout << "Ejercicio creado con exito." << endl;
}

void GestorRutinas::actualizarEjercicio() {
    int id;
    cout << "\n--- ACTUALIZAR EJERCICIO ---" << endl;
    cout << "Ingrese el ID del ejercicio a actualizar: ";
    cin >> id;

    for (Ejercicio* ej : listaEjercicios) {
        if (ej->getId() == id) {
            string nombre, intensidad, descripcion;
            int tiempo;

            cin.ignore();
            cout << "Nuevo nombre: ";
            getline(cin, nombre);
            cout << "Nueva intensidad: ";
            getline(cin, intensidad);
            cout << "Nuevo tiempo (minutos): ";
            cin >> tiempo;
            cin.ignore();
            cout << "Nueva descripcion: ";
            getline(cin, descripcion);

            ej->actualizarDatos(nombre, intensidad, tiempo, descripcion);
            cout << "Ejercicio actualizado." << endl;
            return;
        }
    }
    cout << "Ejercicio no encontrado." << endl;
}

void GestorRutinas::eliminarEjercicio() {
    int id;
    cout << "\n--- ELIMINAR EJERCICIO ---" << endl;
    cout << "Ingrese el ID del ejercicio a eliminar: ";
    cin >> id;

    for (size_t i = 0; i < listaEjercicios.size(); i++) {
        if (listaEjercicios[i]->getId() == id) {
            delete listaEjercicios[i];
            listaEjercicios.erase(listaEjercicios.begin() + i);
            cout << "Ejercicio eliminado." << endl;
            return;
        }
    }
    cout << "Ejercicio no encontrado." << endl;
}

void GestorRutinas::consultarEjercicio() {
    int id;
    cout << "\n--- CONSULTAR EJERCICIO ---" << endl;
    cout << "Ingrese el ID del ejercicio: ";
    cin >> id;

    for (Ejercicio* ej : listaEjercicios) {
        if (ej->getId() == id) {
            ej->mostrarInformacion();
            return;
        }
    }
    cout << "Ejercicio no encontrado." << endl;
}

void GestorRutinas::buscarPorIntensidad() {
    string intensidad;
    cout << "\n--- BUSCAR POR INTENSIDAD ---" << endl;
    cin.ignore();
    cout << "Ingrese la intensidad (Basico, Intermedio, Avanzado, Alto rendimiento): ";
    getline(cin, intensidad);

    bool encontrado = false;
    for (Ejercicio* ej : listaEjercicios) {
        if (ej->getIntensidad() == intensidad) {
            ej->mostrarInformacion();
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No hay ejercicios con esa intensidad." << endl;
    }
}

void GestorRutinas::generarRutina() {
    int cantidad;
    string intensidad;

    cout << "\n--- GENERAR RUTINA (Semana " << semanaActual << ") ---" << endl;
    cout << "Cantidad de ejercicios deseados: ";
    cin >> cantidad;
    cin.ignore();
    cout << "Nivel de intensidad deseado: ";
    getline(cin, intensidad);

    vector<Ejercicio*> rutinaGenerada;
    int tiempoTotal = 0;

    for (Ejercicio* ej : listaEjercicios) {
        // Filtrar por intensidad y revisar que no se haya usado la semana pasada
        if (ej->getIntensidad() == intensidad && ej->getUltimaSemana() != (semanaActual - 1)) {
            rutinaGenerada.push_back(ej);
            tiempoTotal += ej->getTiempo();
            ej->setUltimaSemana(semanaActual);

            if (rutinaGenerada.size() == cantidad) {
                break;
            }
        }
    }

    if (rutinaGenerada.empty()) {
        cout << "No se encontraron ejercicios disponibles que cumplan los criterios (intensidad y regla de semanas)." << endl;
    } else {
        cout << "\nRutina generada con exito:" << endl;
        for (Ejercicio* ej : rutinaGenerada) {
            ej->mostrarInformacion();
        }
        cout << "Tiempo estimado total: " << tiempoTotal << " minutos." << endl;
        if (rutinaGenerada.size() < cantidad) {
            cout << "Nota: Solo se encontraron " << rutinaGenerada.size() << " ejercicios disponibles." << endl;
        }
    }
}

void GestorRutinas::avanzarSemana() {
    semanaActual++;
    cout << "Se ha avanzado a la semana " << semanaActual << "." << endl;
}