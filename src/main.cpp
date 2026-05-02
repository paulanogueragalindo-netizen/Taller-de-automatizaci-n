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
