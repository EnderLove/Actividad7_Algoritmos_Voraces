/*
 * Problema 2: Cobertura de antenas
 * Estrategia Greedy: tomar la primera casa sin cubrir (la mas a la izquierda)
 * y colocar la antena lo mas a la derecha posible, en (casa + R), de modo que
 * esa casa quede justo en el borde izquierdo de la cobertura.
 *
 * Formato de entrada (archivo o teclado):
 *   R
 *   n
 *   posiciones de las n casas (separadas por espacios)
 *
 * Uso:
 *   ./cobertura_antenas ../examples/antenas1.txt
 *   ./cobertura_antenas              (lee desde el teclado)
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

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
        cerr << "Formato: R, n, y luego las n posiciones de las casas" << endl;
    }

    long long R;
    int n;
    if (!(*in >> R >> n) || R < 0 || n <= 0) {
        cerr << "Error: R o cantidad de casas invalida." << endl;
        return 1;
    }

    vector<long long> casas(n);
    for (int i = 0; i < n; i++) {
        if (!(*in >> casas[i])) {
            cerr << "Error: posicion de casa invalida." << endl;
            return 1;
        }
    }

    // Paso 1: ordenar las casas de izquierda a derecha -> O(n log n)
    sort(casas.begin(), casas.end());

    // Paso 2: recorrer las casas una sola vez -> O(n)
    vector<long long> antenas;
    int i = 0;
    while (i < n) {
        // casas[i] es la primera casa sin cubrir
        long long posAntena = casas[i] + R;  // antena lo mas a la derecha posible
        antenas.push_back(posAntena);

        // La antena cubre hasta posAntena + R: se saltan todas las casas cubiertas
        long long limite = posAntena + R;
        while (i < n && casas[i] <= limite) {
            i++;
        }
    }

    cout << "Antenas colocadas en:" << endl;
    for (long long a : antenas) {
        cout << a << endl;
    }
    cout << "Cantidad total: " << antenas.size() << endl;
    return 0;
}
