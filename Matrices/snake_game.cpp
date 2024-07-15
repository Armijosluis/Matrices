#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>

#define ROWS 20
#define COLS 70
#define NUM_A 5
#define NUM_B 5

typedef struct {
    int x;
    int y;
} Position;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hidecursor() {
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void generateRandomPosition(int *ax, int *ay, Position *body, int length) {
    bool validPosition;
    do {
        validPosition = true;
        *ax = 1 + rand() % (COLS - 2);
        *ay = 1 + rand() % (ROWS - 2);
        for (int i = 0; i < length; i++) {
            if (body[i].x == *ax && body[i].y == *ay) {
                validPosition = false;
                break;
            }
        }
    } while (!validPosition);
}

void showDifficultyMenu(int *speed) {
    system("cls");

    printf("Seleccione la dificultad:\n");
    printf("1. Nivel1\n");
    printf("2. Nivel2\n");
    printf("3. Salir\n");

    char option;
    do {
        option = _getch();
        switch (option) {
            case '1':
                *speed = 85;
                return;
            case '2':
                *speed = 10;
                return;
            case '3':
                exit(0);
            default:
                break;
        }
    } while (option != '1' && option != '2' && option != '3');
}

int main() {
    char player = 'b'; // Caracter del jugador
    int initial_player_size = 1; // Tamaño inicial del jugador
    int x, y; // Posición inicial del jugador
    Position body[ROWS * COLS]; // Cuerpo del jugador
    int length = 0; // Tamaño inicial del cuerpo del jugador
    char direction = 'd'; // Dirección inicial: derecha
    bool game_started = false; // El juego no ha comenzado
    int game_speed = 100; // Velocidad por defecto (media)

    Position a_positions[NUM_A]; // Posiciones de las "A"
    Position b_positions[NUM_B]; // Posiciones de las "B"

    srand(time(NULL));
    hidecursor();
    showDifficultyMenu(&game_speed); // Mostrar menú de dificultades y configurar la velocidad

    int high_score = 0; // Variable para guardar el puntaje más alto alcanzado

    while (1) {
        x = 1 + rand() % (COLS - 2);
        y = 1 + rand() % (ROWS - 2);

        // Generar posiciones aleatorias para "A" y "B"
        for (int i = 0; i < NUM_A; i++) {
            generateRandomPosition(&a_positions[i].x, &a_positions[i].y, body, length);
        }
        for (int i = 0; i < NUM_B; i++) {
            generateRandomPosition(&b_positions[i].x, &b_positions[i].y, body, length);
        }

        clock_t start_time;
        double elapsed_time = 0.0;

        while (1) {
            // Mostrar tiempo transcurrido
            gotoxy(0, ROWS); // Colocar el cronómetro en la última fila
            printf("Tiempo transcurrido: %.1f segundos", elapsed_time);

            start_time = clock(); // Iniciar el cronómetro al inicio de cada ciclo

            gotoxy(0, 0);

            // Imprimir el borde y los elementos del juego
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1) {
                        setColor(FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_BLUE); // Líneas de color azul como borde
                        printf(" ");
                    } else {
                        bool printed = false;
                        bool isBodyPart = false;

                        // Verificar si la posición actual es parte del cuerpo del jugador
                        for (int k = 0; k < length; k++) {
                            if (body[k].x == j && body[k].y == i) {
                                setColor(FOREGROUND_GREEN | BACKGROUND_GREEN); // Verde con fondo verde para el cuerpo del jugador
                                printf("%c", player);
                                setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Restaurar color original
                                printed = true;
                                isBodyPart = true;
                                break;
                            }
                        }

                        // Si no es parte del cuerpo del jugador, verificar otros elementos
                        if (!printed) {
                            if (i == y && j == x) {
                                setColor(FOREGROUND_GREEN | BACKGROUND_GREEN); // Verde con fondo verde para el jugador
                                printf("%c", player);
                                setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Restaurar color original
                                printed = true;
                            } else {
                                for (int k = 0; k < NUM_A; k++) {
                                    if (i == a_positions[k].y && j == a_positions[k].x) {
                                        setColor(FOREGROUND_RED | BACKGROUND_RED); // Rojo con fondo rojo para la "A"
                                        printf("A");
                                        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Restaurar color original
                                        printed = true;
                                        break;
                                    }
                                }
                                for (int k = 0; k < NUM_B; k++) {
                                    if (i == b_positions[k].y && j == b_positions[k].x) {
                                        setColor(FOREGROUND_RED | FOREGROUND_BLUE); // Rojo con fondo azul para la "B"
                                        printf("\xDB"); // Carácter extendido para formar un bloque sólido
                                        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Restaurar color original
                                        printed = true;
                                        break;
                                    }
                                }
                                if (!printed) {
                                    // Imprimir los espacios dentro del cuadro del juego
                                    if (j > 0 && j < COLS - 1 && i > 0 && i < ROWS - 1 && !isBodyPart) {
                                        setColor(FOREGROUND_GREEN); // Establecer color verde para los espacios dentro del cuadrado
                                        printf(" ");
                                        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Restaurar color para los elementos futuros
                                        printed = true;
                                    }
                                }
                            }
                        }

                        if (!printed) {
                            printf(" ");
                        }
                    }
                }
                printf("\n");
            }

            // Esperar hasta que el usuario presione una tecla para iniciar el juego
            if (!game_started) {
                if (_kbhit()) {
                    char movimiento = _getch();
                    switch (movimiento) {
                        case 'w':
                            direction = 'w';
                            game_started = true;
                            break;
                        case 'a':
                            direction = 'a';
                            game_started = true;
                            break;
                        case 's':
                            direction = 's';
                            game_started = true;
                            break;
                        case 'd':
                            direction = 'd';
                            game_started = true;
                            break;
                        case 'q':
                            printf("Juego terminado.\n");
                            return 0;
                    }
                }
                continue; // Saltar el resto del ciclo hasta que el juego comience
            }

            Sleep(game_speed); // Retardo para controlar la velocidad del movimiento

            // Guardar la posición anterior del jugador
            int prev_x = x, prev_y = y;
            bool game_over = false;

            // Verificar si se ha presionado alguna tecla
            if (_kbhit()) {
                char movimiento = _getch();
                switch (movimiento) {
                    case 'w':
                        if (direction != 's') direction = 'w';
                        break;
                    case 'a':
                        if (direction != 'd') direction = 'a';
                        break;
                    case 's':
                        if (direction != 'w') direction = 's';
                        break;
                    case 'd':
                        if (direction != 'a') direction = 'd';
                        break;
                    case 'q':
                        printf("Juego terminado.\n");
                        return 0;
                }
            }

            /// Mover el jugador en la dirección actual
switch (direction) {
    case 'w':
        if (y > 1) {
            y--;
        } else {
            game_over = true;
        }
        break;
    case 'a':
        if (x > 1) {
            x--;
        } else {
            game_over = true;
        }
        break;
    case 's':
        if (y < ROWS - 2) {
            y++;
        } else {
            game_over = true;
        }
        break;
    case 'd':
        if (x < COLS - 2) {
            x++;
        } else {
            game_over = true;
        }
        break;
}

// Verificar colisión con el propio cuerpo del jugador
for (int k = 1; k < length; k++) {
    if (y == body[k].y && x == body[k].x) {
        game_over = true;
        break;
    }
}


            // Verificar colisión con las "A"
            for (int k = 0; k < NUM_A; k++) {
                if (y == a_positions[k].y && x == a_positions[k].x) {
                    // Aumentar el tamaño del cuerpo y generar una nueva posición para "A"
                    body[length++] = (Position){prev_x, prev_y};
                    a_positions[k].x = -1; // Marcar como posición inválida temporalmente
                    generateRandomPosition(&a_positions[k].x, &a_positions[k].y, body, length);
                    break;
                }
            }

            // Verificar colisión con las "B"
            for (int k = 0; k < NUM_B; k++) {
                if (y == b_positions[k].y && x == b_positions[k].x) {
                    // Reducir el tamaño del cuerpo y restar 2 al puntaje
                    if (length > 1) {
                        if (length <= 2) {
                            // Mostrar "Game Over" y reiniciar el juego
                            gotoxy(COLS / 2 - 5, ROWS / 2);
                            setColor(FOREGROUND_RED | FOREGROUND_INTENSITY); // Texto rojo brillante
                            printf("Game Over!");
                            setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Restaurar color original
                            gotoxy(0, ROWS + 1);

                            // Mostrar el tamaño alcanzado
                            printf("\n\nPuntaje: %d\n", length);

                            // Actualizar el puntaje más alto
                            if (length > high_score) {
                                high_score = length;
                                printf("¡Nuevo récord!\n");
                            } else {
                                printf("Puntaje más alto: %d\n", high_score);
                            }

                            // Limpiar el cuerpo del jugador
                            length = 0;

                            // Preguntar al usuario si desea volver a jugar o salir
                            printf("\n1. Volver a empezar\n");
                            printf("2. Salir al menu\n");
                            char option;
                            do {
                                option = _getch();
                                if (option == '1') {
                                    game_over = true; // Salir del ciclo actual para reiniciar el juego
                                    length = initial_player_size;
                                    x = 1 + rand() % (COLS - 2);
                                    y = 1 + rand() % (ROWS - 2);
                                    direction = 'd'; // Dirección inicial: derecha
                                    game_started = false; // Reiniciar el estado del juego
                                    break;
                                } else if (option == '2') {
                                    return 0; // Salir al menú principal
                                }
                            } while (option != '1' && option != '2');
                            break;
                        } else {
                            // Reducir el tamaño del cuerpo en 2 casillas
                            length -= 2;
                        }
                    } else {
                        game_over = true;
                    }
                    // Generar nueva posición para "B"
                    b_positions[k].x = -1; // Marcar como posición inválida temporalmente
                    generateRandomPosition(&b_positions[k].x, &b_positions[k].y, body, length);
                    break;
                }
            }

            // Actualizar la posición del cuerpo del jugador
            for (int i = length - 1; i > 0; i--) {
                body[i] = body[i - 1];
            }
            body[0] = (Position){prev_x, prev_y};

            // Mostrar "Game Over" si es necesario
            if (game_over) {
                gotoxy(COLS / 2 - 5, ROWS / 2);
                setColor(FOREGROUND_RED | FOREGROUND_INTENSITY); // Texto rojo brillante
                printf("Game Over!");
                setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Restaurar color original
                gotoxy(0, ROWS + 1);

                // Mostrar el tamaño alcanzado
                printf("\n\nPuntaje: %d\n", length);

                // Actualizar el puntaje más alto
                if (length > high_score) {
                    high_score = length;
                    printf("Nuevo record\n");
                } else {
                    printf("Puntaje mes alto: %d\n", high_score);
                }

                // Limpiar el cuerpo del jugador
                length = 0;

                // Preguntar al usuario si desea volver a jugar o salir
                printf("\n1. Volver a empezar\n");
                printf("2. Salir\n");
                char option;
                do {
                    option = _getch();
                    if (option == '1') {
                        game_over = true; // Salir del ciclo actual para reiniciar el juego
                        length = initial_player_size;
                        x = 1 + rand() % (COLS - 2);
                        y = 1 + rand() % (ROWS - 2);
                        direction = 'd'; // Dirección inicial: derecha
                        game_started = false; // Reiniciar el estado del juego
                        break;
                    } else if (option == '2') {
                        return 0; // Salir al menú principal
                    }
                } while (option != '1' && option != '2');
                break;
            }

            // Actualizar la posición del jugador
            body[0] = (Position){x, y};

            // Calcular tiempo transcurrido
            elapsed_time += (double)(clock() - start_time) / CLOCKS_PER_SEC;
        }
    }

    return 0;
}