
#include <stdio.h>

int main() {
    float matriz[3][3]; // Matriz original
    float identidad[3][3]; // Matriz identidad
    float determinante = 0; // Determinante de la matriz original
    float matriz2[3][3]; // Segunda matriz para la división
    float resultado[3][3]; // Resultado de la división

    // Ingreso de la primera matriz
    printf("Ingrese los datos de la primera matriz (3x3):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%f", &matriz[i][j]);
        }
    }

    // Ingreso de la segunda matriz
    printf("\nIngrese los datos de la segunda matriz (3x3):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%f", &matriz2[i][j]);
        }
    }

    // Mostrar la primera matriz ingresada
    printf("\nMatriz ingresada:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("  %f  ", matriz[i][j]);
        }
        printf("\n");
    }

    // Mostrar la segunda matriz ingresada
    printf("\nSegunda matriz:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("  %f  ", matriz2[i][j]);
        }
        printf("\n");
    }

    // Calcular el determinante de la segunda matriz
    determinante = matriz2[0][0] * (matriz2[1][1] * matriz2[2][2] - matriz2[2][1] * matriz2[1][2]) -
                   matriz2[0][1] * (matriz2[1][0] * matriz2[2][2] - matriz2[2][0] * matriz2[1][2]) +
                   matriz2[0][2] * (matriz2[1][0] * matriz2[2][1] - matriz2[2][0] * matriz2[1][1]);

    // Verificar si la matriz tiene inversa
    if (determinante != 0) {
        // Inicializar la matriz identidad
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                identidad[i][j] = (i == j) ? 1.0 : 0.0;
            }
        }

        // Proceso de Gauss-Jordan para obtener la matriz inversa de la segunda matriz
        for (int i = 0; i < 3; i++) {
            float pivote = matriz2[i][i];
            for (int k = 0; k < 3; k++) {
                matriz2[i][k] /= pivote;
                identidad[i][k] /= pivote;
            }
            for (int j = 0; j < 3; j++) {
                if (i != j) {
                    float aux = matriz2[j][i];
                    for (int k = 0; k < 3; k++) {
                        matriz2[j][k] -= aux * matriz2[i][k];
                        identidad[j][k] -= aux * identidad[i][k];
                    }
                }
            }
        }

        // Mostrar la matriz inversa obtenida
        printf("\nMatriz inversa de la segunda matriz:\n");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf("   %f   ", identidad[i][j]);
            }
            printf("\n");
        }

        // Realizar la división de las matrices usando la matriz inversa de la segunda matriz
        printf("\nLa división de las matrices es:\n");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                resultado[i][j] = 0;
                for (int k = 0; k < 3; k++) {
                    resultado[i][j] += identidad[i][k] * matriz[k][j];
                }
                printf("   %f   ", resultado[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("\nLa segunda matriz no tiene inversa porque su determinante es igual a 0\n");
    }

    return 0;
}
