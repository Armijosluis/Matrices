#include <stdio.h>

int main() {
    int matriz[3][3];
    
    matriz[0][0] = 4;
    matriz[0][1] = 5;
    matriz[0][2] = 2;
    matriz[1][0] = 4;
    matriz[1][1] = 3;
    matriz[1][2] = 2;
    matriz[2][0] = 7;
    matriz[2][1] = 1;
    matriz[2][2] = 0;

    // Imprimir la matriz completa
    printf("Matriz:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Generar la matriz simétrica
    int simetrica[3][3];
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) {
                simetrica[i][j] = matriz[i][j]; // La diagonal principal permanece igual
            } else {
                simetrica[i][j] = (matriz[i][j] + matriz[j][i]) / 2; // Promedio de los valores simétricos
            }
        }
    }

    // Imprimir la matriz simétrica
    printf("\nMatriz Simétrica:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", simetrica[i][j]);
        }
        printf("\n");
    }

    return 0;
}
