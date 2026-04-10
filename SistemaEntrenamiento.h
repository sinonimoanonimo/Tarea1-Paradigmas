#ifndef SISTEMA_ENTRENAMIENTO_H
#define SISTEMA_ENTRENAMIENTO_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Clase base abstracta
class Ejercicio {
protected:
    int id;
    string nombre;
    string intensidad; // Basico, Intermedio, Avanzado, Alto rendimiento
    int tiempoMinutos;
    string descripcion;
    int ultimaSemanaUsado;

public:
    Ejercicio(int id, string nombre, string intensidad, int tiempoMinutos, string descripcion, int ultimaSemanaUsado);
    virtual ~Ejercicio() {}

    // Metodos virtuales para polimorfismo
    virtual string getTipo() const = 0;
    virtual void mostrarInformacion() const;

    // Getters y Setters
    int getId() const;
    string getIntensidad() const;
    int getTiempo() const;
    int getUltimaSemana() const;
    void setUltimaSemana(int semana);

    void actualizarDatos(string nuevoNombre, string nuevaIntensidad, int nuevoTiempo, string nuevaDescripcion);
};

// Clase derivada: Ejercicio Cardiovascular
class EjercicioCardio : public Ejercicio {
public:
    EjercicioCardio(int id, string nombre, string intensidad, int tiempoMinutos, string descripcion, int ultimaSemanaUsado);
    string getTipo() const override;
};

// Clase derivada: Ejercicio de Fuerza
class EjercicioFuerza : public Ejercicio {
public:
    EjercicioFuerza(int id, string nombre, string intensidad, int tiempoMinutos, string descripcion, int ultimaSemanaUsado);
    string getTipo() const override;
};

// Clase gestora del sistema
class GestorRutinas {
private:
    vector<Ejercicio*> listaEjercicios;
    int semanaActual;

public:
    GestorRutinas();
    ~GestorRutinas();

    void crearEjercicio();
    void actualizarEjercicio();
    void eliminarEjercicio();
    void consultarEjercicio();
    void buscarPorIntensidad();
    void generarRutina();
    void avanzarSemana();
};

#endif