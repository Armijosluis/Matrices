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
    
			 
    // los 4 elementos de la esquina no
    printf("\n Todos los elementos de la mmatriz menos el de las esquinas :\n");
    printf("  %d \n", matriz[0][1]),

    printf("%d %d %d\n", matriz[1][0], matriz[1][1], matriz[1][2]);

    printf("  %d \n", matriz[2][1]);
    
			 
    return 0;
}

