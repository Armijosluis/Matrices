#include <stdio.h>

int main() {
    printf("Ingrese los datos de la matriz\n");

    float matriz[3][3];
    float identidad[3][3];
    float determinante = 0;

    // Ingresamos los datos de la matriz
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%f", &matriz[i][j]);
        }
    }

    // Mostramos los datos de la matriz ingresada
    printf("Matriz ingresada\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("  %f  ", matriz[i][j]);
        }
        printf("\n");
    }

    // Calculamos el determinante
    determinante = matriz[0][0] * (matriz[1][1] * matriz[2][2] - matriz[2][1] * matriz[1][2]) -
                   matriz[0][1] * (matriz[1][0] * matriz[2][2] - matriz[2][0] * matriz[1][2]) +
                   matriz[0][2] * (matriz[1][0] * matriz[2][1] - matriz[2][0] * matriz[1][1]);

    if (determinante != 0) {
        // Iniciamos la matriz identidad
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                identidad[i][j] = (i == j) ? 1.0 : 0.0;
            }
        }

        // Proceso de Gauss-Jordan para calcular la inversa
        float pivote, aux;
        for (int i = 0; i < 3; i++) {
            pivote = matriz[i][i];
            for (int k = 0; k < 3; k++) {
                matriz[i][k] /= pivote;
                identidad[i][k] /= pivote;
            }
            for (int j = 0; j < 3; j++) {
                if (i != j) {
                    aux = matriz[j][i];
                    for (int k = 0; k < 3; k++) {
                        matriz[j][k] -= aux * matriz[i][k];
                        identidad[j][k] -= aux * identidad[i][k];
                    }
                }
            }
        }

        // Mostramos la matriz inversa
        printf("Matriz inversa:\n");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf("  %f  ", identidad[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("La matriz no tiene inversa porque su determinante es igual a 0\n");
    }

    return 0;
}
