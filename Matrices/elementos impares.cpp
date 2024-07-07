#include <stdio.h>

int main() {
	
	   
    printf("              **Elementos impares de la matriz**\n");
    int matriz[3][3];

    // Pedir al usuario que ingrese los 9 valores de la matriz en una sola línea
    printf("Ingrese los 9 valores de la matriz 3x3 separados por espacios:");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Imprimir la matriz completa
    printf("\nMatriz:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Imprimir los elementos impares de la matriz
    printf("\nElementos impares de la matriz:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz[i][j] % 2 != 0) {
                printf("%d ", matriz[i][j]);
            } else {
                printf("   "); // Espacio en blanco para los elementos pares
            }
        }
        printf("\n");
    }

    return 0;
}
