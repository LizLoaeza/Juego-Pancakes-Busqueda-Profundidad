//INTENTO NÚMERO MIL OCHO MIL DE PANCAKES RESUELTO POR BPP//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DEP 	4
#define VOL 		4

#include "Variables.h"

//VOID PARA VOLTEAR LOS PANCAKES
void flip(char *x, int n){
    char c;
    int i, j, longs;
    if(n<2){
        return;
    }
    longs = strlen(x);
    if(n>longs){
        return;
    }
    for ( i = longs-n, j = longs-1 ; i<j ; i++,j-- ) {
		c = x[i];
		x[i] = x[j];
		x[j] = c;
	}
}

//VOID PAR LA BUSQUEDA EN PROFUNDIDAD
void dfs(char *x, int prevNode){

    nodes++; //para ir contabilizando los nodos visitados

    if(!strncmp(x, Goal, sized)){
        if (solSize < bestSolSize){
            for (int i = 0; i<solSize; i++){
                bestSol[i] = ActSol[i];
                bestSolSize = solSize;
            }
        }
        return;
    }
    if(maxDepht <= solSize){
        return;
    }
    for(int i = 2; i <= sized; i++){
        if(i==prevNode){
            continue;
            flip(x, i);
            ActSol[solSize++] = i;
            dfs(x, i);
            flip(x, i);
            solSize--;
        }
    }


}



int main (){

    int i;
    char Pancakes[64], OriginalPancake[64];

    //Variables.h
    solSize = 0;
    bestSolSize = MAX;
    maxDepht = MAX_DEP;
    sized = VOL;
    strcpy(Goal, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    strncpy(Pancakes, Goal, sized);
    Pancakes[sized] = '\0'; //establecer el caracter nulo para indicar el final de la cadena

    //CADENA ESPECIFICA
    strcpy(Pancakes, "badc");
    strcpy(OriginalPancake, Pancakes);
    printf("Cadena inicial: %s\n",Pancakes);

    //IMPRESION DE LA BÚSQUEDA
    printf("\nBusqueda en profundidad: ");
    nodes = 0;
    dfs(Pancakes, 0);
    printf("\n", nodes);
    for (i=0; i<bestSolSize; i++){
        printf("%d ", bestSol[i]);
    }
    return 0;
}
