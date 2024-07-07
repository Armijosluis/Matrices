#include <stdio.h>

int main() {
    int matriz[3][3];
    int i, j;

    // Pedir al usuario que ingrese los valores de la matriz en una sola línea
    printf("Ingrese los 9 valores de la matriz 3x3:");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Imprimir la matriz completa
    printf("\nMatriz:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Imprimir los 4 elementos de la esquina
    printf("\nElementos de las esquinas:\n");
    printf("%d    %d\n", matriz[0][0], matriz[0][2]);
    printf("%d    %d\n", matriz[2][0], matriz[2][2]);

    return 0;
	}
