#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "fila.h"

Fila *criaControlador (bool *resultado)
{
    *resultado = false;
    Fila *controlador = (Fila*)malloc(sizeof(Fila));
    
    if (controlador == NULL)
    {
        return NULL;
    }

    *resultado = true;
    controlador->fimP = NULL;
    controlador->inicioP = NULL;
    controlador->numProdutos = 0;
    return controlador;

}

produto *criaProduto (int ident, char n[], bool *resultado)
{
    *resultado = false;
    produto *novo = (produto*)malloc(sizeof(produto));
    if (novo == NULL)
        return NULL;

    novo->dados.id = ident;
    strcpy (novo->dados.nome,n);
    novo->seguinte = NULL;
    *resultado = true;
    return novo;
}

bool verificarProdutosDuplicados (produto *inicio, int idAux)
{
    if (inicio == NULL)
        return false;

    while (inicio != NULL)
    {
        if (inicio->dados.id == idAux) 
            return true;

        inicio = inicio->seguinte;
    }

    return false;
}

produto *inserirProduto (produto **inicio, produto *fim, produto *novo, bool *resultado)
{
    *resultado = true;

    if (novo == NULL)
    {

    printf("3\n");
        *resultado = false;
        return fim;
    }
    *resultado = verificarProdutosDuplicados (*inicio, novo->dados.id);
    if (*resultado == true)
    {
        printf ("4\n");
        *resultado = false;
        return fim;
    }
    *resultado = true;

    if (fim == NULL)
    {   
        *inicio = novo;
        return novo;
    }

    fim->seguinte = novo;

    return novo;
    
}

Fila *inserirFila (Fila *controlador, produto *novo, bool *resultado)
{
    *resultado = false;

    if (controlador == NULL)
        return NULL;

    controlador->fimP = inserirProduto(&(controlador->inicioP),controlador->fimP,novo,resultado);
    if (*resultado == true)
    {
        (controlador->numProdutos)++;
    }
    
    return controlador;
     
}

bool mostraFila (Fila *controlador)
{
    if (controlador == NULL)
        return false;

    if (controlador->numProdutos == 0)
        return false;

    produto *aux = controlador->inicioP;

    while (aux != NULL)
    {
        printf ("Nome: %s; Id: %d\n", aux->dados.nome, aux->dados.id);
        aux = aux->seguinte;
    }
    return true;
}

produto *removerProduto (produto *inicio, produtoFicheiro *data, bool *resultado)
{
    *resultado = false;
    if (inicio == NULL)
        return NULL;

    produto *aux = inicio;
    data->id = aux->dados.id;
    strcpy (data->nome,aux->dados.nome);
    inicio = inicio->seguinte;
    free(aux);
    *resultado = true;
    return inicio;
}

Fila *removerProdutoFila (Fila *controlador, produtoFicheiro *data, bool *resultado)
{
    *resultado = false;
    if (controlador == NULL)
        return NULL;

    if (controlador->numProdutos == 0)
        return controlador;

    controlador->inicioP = removerProduto(controlador->inicioP,data,resultado);
    if (*resultado == true)
        (controlador->numProdutos)--;
    return controlador;
}