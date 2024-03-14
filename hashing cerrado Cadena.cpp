#include <iostream>
#include <vector>
#include <string>

#define CLASES 10

using namespace std;

typedef struct Nodo {
    int llave;
    string dato;
    Nodo* sig;
} celdas;

class TablaHash {
private:
    vector<celdas*> Tabla;
    int Clases = 10;
    int hash;

public:
    TablaHash(int Clases) {
        this->hash = 0;
        this->Clases = Clases;
        Tabla.resize(Clases);
    }

    // Método que recibe la llave a ingresar y obtiene su hash para posteriormente guardarlo en la tabla
    unsigned int hash_(int llave) {
        return llave % CLASES;
    }

    void agregar(int llave, const string& dato);
    void mostrarTabla();
};

// Método que se encarga de agregar elementos a la lista
void TablaHash::agregar(int llave, const string& dato) {
    // Se obtiene el hash para insertar en la tabla
    hash = hash_(llave);

    celdas* nodo = new celdas;
    nodo->llave = llave;
    nodo->dato = dato;
    nodo->sig = NULL;

    // Si la tabla está vacía, se inserta el elemento
    if (Tabla[hash] == NULL) {
        Tabla[hash] = nodo;
    }
    else {
        // Si no está vacía, se avanza al siguiente nodo e inserta el elemento
        celdas* nuevo_nodo = Tabla[hash];

        while (nuevo_nodo->sig != NULL) {
            nuevo_nodo = nuevo_nodo->sig;
        }
        nuevo_nodo->sig = nodo;
    }
}

void TablaHash::mostrarTabla() {
    for (int i = 0; i < CLASES; i++) {
        celdas* nodo = Tabla[i];

        cout << "[" << i << "]: ";

        while (nodo != NULL) {
            cout << nodo->dato << " ";
            nodo = nodo->sig;
        }
        cout << endl;
    }
}

int main() {
    TablaHash tabla(10); // Crear una instancia de la tabla de hash con 10 clases

    tabla.agregar(20, "uno");
    tabla.agregar(2, "dos");
    tabla.agregar(3, "tres");
    tabla.agregar(4, "cuatro");
    tabla.agregar(5, "cinco");
    tabla.agregar(6, "seis");
    tabla.agregar(7, "siete");
    tabla.agregar(8, "ocho");
    tabla.agregar(9, "nueve");
    tabla.agregar(10, "diez");

    tabla.mostrarTabla(); // Mostrar la tabla de hash

    return 0;
}