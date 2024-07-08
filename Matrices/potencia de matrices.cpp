#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Función para multiplicar dos matrices
       
vector<vector<int>> multiplicarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int m = A.size();
    int n = B[0].size();
    int p = B.size();
    vector<vector<int>> resultado(m, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < p; ++k) {
                resultado[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return resultado;
}

// Función para calcular la potencia de una matriz
vector<vector<int>> potenciaMatriz(const vector<vector<int>>& matriz, int exp) {
    int n = matriz.size();
    vector<vector<int>> resultado(n, vector<int>(n, 0));

    // Inicializamos la matriz resultado como la identidad
    for (int i = 0; i < n; ++i) {
        resultado[i][i] = 1;
    }

    // Multiplicamos la matriz consigo misma exp veces
    for (int i = 0; i < exp; ++i) {
        resultado = multiplicarMatrices(resultado, matriz);
    }

    return resultado;
}

// Función para imprimir una matriz
void imprimirMatriz(const vector<vector<int>>& matriz) {
    int m = matriz.size();
    int n = matriz[0].size();

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

// Función para ingresar una matriz desde el usuario en una sola línea
vector<vector<int>> ingresarMatriz() {
    vector<vector<int>> matriz(3, vector<int>(3, 0));
cout << "     ***Potencia de Matrices****\n" << endl;
    cout << "Ingrese los elementos de la matriz 3x3 separados por espacios:" << endl;
    string input;
    getline(cin, input);
    istringstream iss(input);
    int num;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            iss >> num;
            matriz[i][j] = num;
        }
    }

    return matriz;
}

int main() {
    vector<vector<int>> matriz = ingresarMatriz();
    int exponente;
 
    cout << "Ingrese el exponente al que desea elevar la matriz: ";
    cin >> exponente;

    vector<vector<int>> resultado = potenciaMatriz(matriz, exponente);

    cout << "\nMatriz original:" << endl;
    imprimirMatriz(matriz);

    cout << "\nMatriz elevada a la potencia " << exponente << ":" << endl;
    imprimirMatriz(resultado);

    return 0;
}

