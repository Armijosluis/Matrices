#include <stdio.h>

int main() {
	
	   
    printf("              **Elementos que no estan en las esquinas**\n");
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

  
   
    // Imprimirlos elelemntos que no esten en las esquinas
    printf("\nImprimir los elelemntos que no esten en las esquinas:\n");
    printf("  %d\n", matriz[0][1]); // Elemento arriba
    printf("%d %d %d\n", matriz[1][0], matriz[1][1], matriz[1][2]); // Fila central
    printf("  %d\n", matriz[2][1]); // Elemento abajo

    return 0;
}

