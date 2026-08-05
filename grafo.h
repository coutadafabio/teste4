#ifndef GRAFO_H
#define GRAFO_H

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct grafo{
    int numVertices;
    vertice *inicioV;
}grafo;

typedef struct verticeFicheiro{
    int id;
    char nome[tamString];
    int numAdj;
}verticeFicheiro;

typedef struct adjacenciaFicheiro{
    int peso;
    verticeFicheiro *dadosV;
}verticeAdjacencia;

typedef struct adjacencia{
    adjacenciaFicheiro dados;
    struct adjacencia *seguinte;
}adjacencia;

typedef struct vertice{
    verticeFicheiro dados;
    struct vertice *seguinte;
    adjacencia *inicioA;
}vertice;

#endif