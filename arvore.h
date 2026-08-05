#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct componenteFicheiro{
    int id;
    char nome[tamString];
}componenteFicheiro;

typedef struct componente
{
    componenteFicheiro dados;
    struct componente *esquerda;
    struct componente *direita;
}componente;

typedef struct arvore{
    componente *raiz;
    int numC;
}arvore;

#endif