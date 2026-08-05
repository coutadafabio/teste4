#ifndef TABELA_H
#define TABELA_H

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct ferramenta{
    char codigo[tamString];
    char nome[tamString];
    struct ferramenta *seguinte;
}ferramente;

typedef struct posto{
    int id;
    char nome[tamString];
    ferramenta *inicioF;
    int numF;
}posto;

#endif