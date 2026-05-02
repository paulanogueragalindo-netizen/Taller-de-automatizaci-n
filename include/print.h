#ifndef PRINT_H
#define PRINT_H
 
#include <iostream>
#include <string>
 
#define PRINT(x)    std::cout << (x) << "\n"
#define PRINT2(a,b) std::cout << (a) << (b) << "\n"
#define PRINT3(a,b,c) std::cout << (a) << (b) << (c) << "\n"
 
void imprimirSeparador();
void imprimirTitulo();
void imprimirResultado(const std::string& nombre, double x, double resultado);
 
#endif