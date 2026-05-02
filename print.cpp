#include "print.h"

void imprimirSeparador() {
    PRINT("------------------------------------------");
}

void imprimirTitulo() {
    imprimirSeparador();
    PRINT("   Aproximacion de Funciones - Taylor");
    PRINT("   Ingenieria de Sistemas - Programacion I");
    imprimirSeparador();
}

void imprimirResultado(const std::string& nombre, double x, double resultado) {
    if (x < 0.0) { std::cout << "-"; x = -x; }
    long long ex = (long long)x;
    double    dx = x - (double)ex;
    std::cout << "   " << nombre << "(" << ex << ".";
    for (int i = 0; i < 4; i++) { dx *= 10; int d = (int)dx; std::cout << d; dx -= d; }

    std::cout << ") = ";
    if (resultado < 0.0) { std::cout << "-"; resultado = -resultado; }
    long long er = (long long)resultado;
    double    dr = resultado - (double)er;
    std::cout << er << ".";
    for (int i = 0; i < 10; i++) { dr *= 10; int d = (int)dr; std::cout << d; dr -= d; }

    std::cout << "\n";
    imprimirSeparador();
}