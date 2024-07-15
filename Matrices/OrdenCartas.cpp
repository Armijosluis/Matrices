#include <iostream>
#include <vector>
#include <algorithm> // Para std::shuffle y std::sort
#include <random>    // Para generación de números aleatorios

// Estructura para representar una carta
struct Carta {
    int valor;
    std::string palo;
};

// Función para obtener el nombre del valor de la carta
std::string nombreCarta(int valor) {
    if (valor == 1) {
        return "A";
    } else if (valor >= 2 && valor <= 10) {
        return std::to_string(valor);
    } else if (valor == 11) {
        return "J";
    } else if (valor == 12) {
        return "Q";
    } else if (valor == 13) {
        return "K";
    } else {
        return "";
    }
}

// Función para imprimir el contenido de un vector de cartas
void imprimirCartas(const std::vector<Carta>& cartas) {
    for (const Carta& carta : cartas) {
        std::string paloAbreviado;
        if (carta.palo == "Corazones") {
            paloAbreviado = "co";
        } else if (carta.palo == "Diamantes") {
            paloAbreviado = "di";
        } else if (carta.palo == "Picas") {
            paloAbreviado = "pi";
        } else if (carta.palo == "Treboles") {
            paloAbreviado = "tre";
        }
        std::cout << nombreCarta(carta.valor) << " " << paloAbreviado << "\n";
    }
}

int main() {
    // Definir los valores y palos de las cartas
    std::vector<std::string> palos = {"Corazones", "Diamantes", "Treboles", "Picas"};
    
    // Crear el mazo completo de cartas
    std::vector<Carta> mazo;
    for (int valor = 1; valor <= 13; ++valor) {
        for (const std::string& palo : palos) {
            mazo.push_back({valor, palo});
        }
    }
    
    // Desordenar el mazo
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(mazo.begin(), mazo.end(), g);
    
    std::cout << "Mazo desordenado:\n";
    imprimirCartas(mazo);
    
    // Ordenar el mazo por palo y luego por valor
    std::sort(mazo.begin(), mazo.end(), [](const Carta& a, const Carta& b) {
        if (a.palo == b.palo) {
            return a.valor < b.valor;
        } else {
            return a.palo < b.palo;
        }
    });
    
    std::cout << "\nMazo ordenado:\n";
    imprimirCartas(mazo);
    
    return 0;
}
