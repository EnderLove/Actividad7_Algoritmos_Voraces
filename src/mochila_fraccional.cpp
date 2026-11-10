/*
 * Problema 1: Mochila Fraccional (Fractional Knapsack)
 * Estrategia Greedy: elegir primero los objetos con mayor valor/peso.
 *
 * Formato de entrada (archivo o teclado):
 *   capacidad
 *   n
 *   nombre valor peso      (n lineas, una por objeto)
 *
 * Uso:
 *   ./mochila_fraccional ../examples/mochila1.txt
 *   ./mochila_fraccional              (lee desde el teclado)
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Objeto {
    string nombre;
    double valor;
    double peso;
    double razon;  // valor / peso
};

// Orden descendente por razon valor/peso.
// Se usa stable_sort para que, en caso de empate, se respete el orden de entrada.
bool mayorRazon(const Objeto& a, const Objeto& b) {
    return a.razon > b.razon;
}

int main(int argc, char* argv[]) {
    // Si se pasa un archivo como argumento se lee de el, si no, del teclado
    ifstream archivo;
    istream* in = &cin;
    if (argc > 1) {
        archivo.open(argv[1]);
        if (!archivo) {
            cerr << "Error: no se pudo abrir el archivo " << argv[1] << endl;
            return 1;
        }
        in = &archivo;
    } else {
        cerr << "Formato: capacidad, n, y luego n lineas 'nombre valor peso'" << endl;
    }

    double capacidad;
    int n;
    if (!(*in >> capacidad >> n) || capacidad < 0 || n <= 0) {
        cerr << "Error: capacidad o cantidad de objetos invalida." << endl;
        return 1;
    }

    vector<Objeto> objetos(n);
    for (int i = 0; i < n; i++) {
        if (!(*in >> objetos[i].nombre >> objetos[i].valor >> objetos[i].peso) ||
            objetos[i].valor < 0 || objetos[i].peso <= 0) {
            cerr << "Error: el objeto " << i + 1
                 << " es invalido (valor >= 0 y peso > 0)." << endl;
            return 1;
        }
        objetos[i].razon = objetos[i].valor / objetos[i].peso;
    }

    // Paso 1: ordenar por valor/peso de mayor a menor -> O(n log n)
    stable_sort(objetos.begin(), objetos.end(), mayorRazon);

    // Paso 2: recorrer los objetos tomando lo que quepa -> O(n)
    double restante = capacidad;
    double valorTotal = 0;

    cout << "Capacidad maxima: " << capacidad << endl;
    cout << "Objetos seleccionados:" << endl;

    for (const Objeto& o : objetos) {
        if (restante <= 0) break;  // la mochila ya esta llena

        if (o.peso <= restante) {
            // El objeto cabe completo
            cout << o.nombre << " completo" << endl;
            restante -= o.peso;
            valorTotal += o.valor;
        } else {
            // Solo cabe una fraccion: se llena lo que queda de la mochila
            double fraccion = restante / o.peso;
            cout << restante << "/" << o.peso << " Parte del objeto "
                 << o.nombre << endl;
            valorTotal += o.valor * fraccion;
            restante = 0;
        }
    }

    cout << "Valor total obtenido: " << valorTotal << endl;
    return 0;
}
