#include <stdio.h>

void restaMatrices(int matriz1[3][3], int matriz2[3][3], int resultado[3][3]) {
    // Resta de matrices
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            resultado[i][j] = matriz1[i][j] - matriz2[i][j];
        }
    }
}

int main() {
    printf("** Resta de matrices **\n");
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

    // Calcular la resta de matrices
    restaMatrices(matriz1, matriz2, resultado);

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

    // Imprimir la matriz resultado de la resta
    printf("\nMatriz Resta:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

    return 0;
}
