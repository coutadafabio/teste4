#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>

#define tamString 200

typedef struct produtoFicheiro{
    int id;
    char nome[tamString];
}produtoFicheiro;

typedef struct produto{
    produtoFicheiro dados;    
    struct produto *seguinte;
}produto;

typedef struct Fila{
    int numProdutos;
    struct produto *inicioP;
    struct produto *fimP;
}Fila;

Fila *criaControlador (bool *resultado);
produto *criaProduto (int ident, char n[], bool *resultado);
produto *inserirProduto (produto **inicio, produto *fim, produto *novo, bool *resultado);
Fila *inserirFila (Fila *controlador, produto *novo, bool *resultado);
bool mostraFila (Fila *controlador);


#endif