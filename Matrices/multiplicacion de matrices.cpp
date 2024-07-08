#include <stdio.h>

int main() {
    printf("**Multiplicacion de matrices**\n");
    int matriz1[3][3], matriz2[3][3], resultado[3][3];

    // Pedir al usuario que ingrese los valores de la primera matriz 3x3
    printf("Ingrese los 9 valores de la primera matriz 3x3 separados por espacios:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matriz1[i][j]);
        }
    }

    // Pedir al usuario que ingrese los valores de la segunda matriz 3x3
    printf("Ingrese los 9 valores de la segunda matriz 3x3 separados por espacios:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matriz2[i][j]);
        }
    }

    // Imprimir la primera matriz ingresada
    printf("\nPrimera Matriz:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz1[i][j]);
        }
        printf("\n");
    }

    // Imprimir la segunda matriz ingresada
    printf("\nSegunda Matriz:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz2[i][j]);
        }
        printf("\n");
    }

    // Multiplicación de matrices: matriz1 * matriz2 = resultado
    printf("\nResultado de la multiplicacion:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

    return 0;
}


