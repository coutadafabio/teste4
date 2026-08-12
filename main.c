#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "fila.h"

int main (void){

    int op = -1;
    int idAux = 0;
    char nomeAux[tamString];
    bool resultado = true;
    Fila *controlador = criaControlador (&resultado);
    if (resultado == false)
    {
        getchar();
        return 1;
    }

    produto *novoProduto = NULL;

    while (op != 0)
    {
        printf ("Menu:\n\n");
        printf ("1 - Insere produto\n");
        printf ("2 - Mostra listagem de produtos\n\n");
        printf ("3 - Processar produto\n");
        printf ("Opcao: ");
        scanf ("%d", &op);

        switch (op){
            case 1:
                printf("Insere o id do produto: ");
                scanf ("%d", &idAux);
                while (getchar() != '\n');
                printf("Insere o nome do produto: ");
                fgets (nomeAux,tamString,stdin);
                nomeAux[strcspn(nomeAux,"\n")] = '\0';

                novoProduto = criaProduto(idAux, nomeAux, &resultado);
                if (resultado == false)
                {
                    printf("1\n");
                    printf ("Não foi possivel inserir o produto devido a um problema do sistema!\n");
                    break;
                }

                controlador = inserirFila (controlador, novoProduto, &resultado);
                if (resultado == false)
                {
                    printf("2\n");
                    printf ("Não foi possivel inserir o produto devido a um problema do sistema!\n");
                    break;
                }

                break;
            case 2:
                resultado = mostraFila (controlador);
                if (resultado == false)
                    printf ("Nao ha produtos para mostrar!\n");
                
                break;
            case 3:
                produtoFicheiro *data = (produtoFicheiro*)malloc(sizeof(produtoFicheiro));
                controlador = removerProdutoFila (controlador,data,&resultado);
                if (resultado == false)
                    printf("Erro ao processar produto!\n");

                printf("Produto %d com nome %s processado\n", data->id,data->nome);
                free(data);
            case 0:
                break;
            }
                
    }
    
    getchar();
    return 0;
}