#include <stdio.h>
#include <stdlib.h>
#include <math.h>  /* para usar o INFINITY */
#include "../include/grafo.h"




int main ()
{
    int n, dig, i, origem, destino;
    Grafo g;
    ListaDeVertices caminho;
    float custo;
    float dist[MAX_VERT];
    int ant[MAX_VERT];


    /* **********************************************
               DADOS DO GRAFO DO PROBLEMA
    ********************************************** */

    // grafo do PPT
    n = 11;
    dig = 0;
    origem = 4;
    destino = 7;
    CriarGrafo (&g, n, dig);
    //InserirAresta (&g, , , );

    InserirAresta (&g, 0, 1, 1);
    InserirAresta (&g, 0, 3, 2);
    InserirAresta (&g, 0, 4, 6);
    InserirAresta (&g, 1, 2, 2);
    InserirAresta (&g, 1, 4, 5);
    InserirAresta (&g, 1, 5, 3);
    InserirAresta (&g, 1, 6, 9);
    InserirAresta (&g, 2, 6, 7);
    InserirAresta (&g, 2, 6, 9);
    InserirAresta (&g, 3, 4, 8);
    InserirAresta (&g, 3, 8, 1);
    InserirAresta (&g, 4, 5, 1);
    InserirAresta (&g, 4, 8, 7);
    InserirAresta (&g, 4, 9, 2);
    InserirAresta (&g, 5, 6, 6);
    InserirAresta (&g, 5, 9, 4);
    InserirAresta (&g, 6, 7, 2);
    InserirAresta (&g, 6, 9, 3);
    InserirAresta (&g, 6, 10, 1);
    InserirAresta (&g, 7, 10, 4);
    InserirAresta (&g, 8, 9, 9);
    InserirAresta (&g, 9, 10, 1);

    /* **********************************************
               DADOS DO GRAFO DO PROBLEMA
    ********************************************** */


    ExibirGrafo (g);


    printf ("Dijkstra: \n");
    Dijkstra(g, origem, destino, dist, ant, &caminho);
    printf("Vert\tAnt\tDist\n");
    for (i=0; i<g.nVertices; i++)
        if (dist[i] != INFINITY)
            printf(" %i\t%i\t%5.2f\n",i, ant[i], dist[i]);
        else
            printf(" %i\t%i\t +inf\n",i, ant[i]);
    printf ("\n");

    printf ("Caminho: ");
    for (i=0; i<caminho.nVertices; i++)
        printf("%i   ", caminho.vertices[i]);
    printf ("\n\n\n");



    printf ("Prim: \n");
    Prim(g, origem, ant, &custo);
    printf("Vert\tAnt\n");
    for (i=0; i<g.nVertices; i++)
        printf(" %i\t%i\n",i, ant[i]);
    printf ("\n");
    printf("Custo: %.2f   ", custo);
    printf ("\n\n");


    return 0;
}
