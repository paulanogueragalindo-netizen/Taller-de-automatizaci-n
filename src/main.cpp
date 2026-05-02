#include <iostream>
#include "print.h"

double taylor_sin(double x) {
    double suma    = 0.0;
    double termino = x;

    for (int k = 0; k < 30; k++) {
        suma    += termino;
        termino *= (-x * x) / ((2.0*k + 2.0) * (2.0*k + 3.0));
    }
    return suma;
}

double taylor_cos(double x) {
    double suma    = 0.0;
    double termino = 1.0;

    for (int k = 0; k < 30; k++) {
        suma    += termino;
        termino *= (-x * x) / ((2.0*k + 1.0) * (2.0*k + 2.0));
    }
    return suma;
}

double taylor_exp(double x) {
    double suma    = 0.0;
    double termino = 1.0;

    for (int k = 0; k < 30; k++) {
        suma    += termino;
        termino *= x / (k + 1.0);
    }
    return suma;
}

double taylor_ln(double x) {
    if (x <= -1.0) {
        PRINT("   [Error] ln(1+x): x debe ser mayor que -1");
        return 0.0;
    }
    
    if (x > 1.0) {
        PRINT("   [Advertencia] ln(1+x): convergencia lenta para |x| > 1");
    }

    double suma    = 0.0;
    double termino = x;
    int    signo   = 1;

    for (int k = 1; k <= 100; k++) {
        suma    += signo * termino / (double)k;
        termino *= x;
        signo   *= -1;
    }
    return suma;
}

double taylor_sinh(double x) {
    double suma    = 0.0;
    double termino = x;

    for (int k = 0; k < 30; k++) {
        suma    += termino;
        termino *= (x * x) / ((2.0*k + 2.0) * (2.0*k + 3.0));
    }
    return suma;
}

double taylor_cosh(double x) {
    double suma    = 0.0;
    double termino = 1.0;

    for (int k = 0; k < 30; k++) {
        suma    += termino;
        termino *= (x * x) / ((2.0*k + 1.0) * (2.0*k + 2.0));
    }
    return suma;
}

double taylor_tan(double x) {
    double c = taylor_cos(x);
    if (c == 0.0) {
        PRINT("   [Error] tan(x): cos(x) = 0, indefinido");
        return 0.0;
    }
    return taylor_sin(x) / c;
}

int main() {
    imprimirTitulo();

    int opcion;
    double x;

    do {
        PRINT("");
        PRINT("1. sin(x)");
        PRINT("2. cos(x)");
        PRINT("3. tan(x)");
        PRINT("4. exp(x)  [ e^x ]");
        PRINT("5. ln(1+x) [ |x| < 1 recomendado ]");
        PRINT("6. sinh(x)");
        PRINT("7. cosh(x)");
        PRINT("8. Salir");
        PRINT("");
        std::cout << "Opcion: ";
        std::cin  >> opcion;

        if (opcion == 0) break;

        if (opcion < 1 || opcion > 7) {
            PRINT("   Opcion invalida, intenta de nuevo.");
            continue;
        }

        std::cout << "Ingresa x: ";
        std::cin  >> x;

        double        resultado = 0.0;
        std::string   nombre;

        switch (opcion) {
            case 1: resultado = taylor_sin(x);  
            nombre = "sin";    
            break;

            case 2: resultado = taylor_cos(x);  
            nombre = "cos";    
            break;

            case 3: resultado = taylor_tan(x);  
            nombre = "tan";    
            break;

            case 4: resultado = taylor_exp(x);  
            nombre = "exp";    
            break;

            case 5: resultado = taylor_ln(x);   
            nombre = "ln(1+x)"; 
            break;

            case 6: resultado = taylor_sinh(x); 
            nombre = "sinh";   
            break;

            case 7: resultado = taylor_cosh(x); 
            nombre = "cosh";   
            break;
        }

        imprimirResultado(nombre, x, resultado);

    } while (opcion != 0);

    PRINT("");
    PRINT("Hasta luego!");
    return 0;
}