#include <stdio.h>

int main() {
    int filas, columnas;

    printf("**Dimenciones de matrices **\n");
    printf("Ingrese las dimensiones de la matriz: ");
    scanf("%d %d", &filas, &columnas);

    float matriz[filas][columnas];

    // Ingresamos los datos de la matriz
    printf("Ingrese los datos de la matriz %d x %d:\n", filas, columnas);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            scanf("%f", &matriz[i][j]);
        }
    }

    // Mostramos los datos de la matriz ingresada
    printf("Matriz ingresada (%d x %d):\n", filas, columnas);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("  %f  ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("La matriz tiene %d filas y %d columnas.\n", filas, columnas);

    return 0;
}

