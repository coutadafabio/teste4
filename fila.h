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

#endif