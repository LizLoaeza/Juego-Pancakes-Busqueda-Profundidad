//Juego de los pancakes por b�squeda en profundidad//
/*Trabajo realizado p�ra la materia de Inteligencia Artificial*/

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
    longs = strlen(x);//longs representa la cantidad de caracteres que tiene x
    if(n>longs){
        return;
    }
    for ( i = longs-n, j = longs-1 ; i<j ; i++,j-- ) {
		c = x[i];
		x[i] = x[j];
		x[j] = c;
	}
	/*Funcion que representa la manera en la que se voltean los pancakes, de manera que
	el flip intercambia la posicion del primer elemento con la del �ltimo, la del segundo
	con la del penultimo y as� sucesivamente hasta llegar a la mitad de la cadena*/
}

//VOID PAR LA BUSQUEDA EN PROFUNDIDAD
void dfs(char *x, int prevNode){

    //nodes++;

    if(!strncmp(x, Goal, sized)){
        if (solSize < bestSolSize){
            for (int i = 0; i<solSize; i++){
                bestSol[i] = ActSol[i];
                bestSolSize = solSize;
            }
        }
        return;
    /*Dentro de estos ifs primero se pregunta: �la cadena est� ordenada?
    Si s�, se pregunta si la distancia es menor a la de la jugada anterior,
    si es afirmativo, se actualiza la soluci�n y se regresa.
    Si el primer if entra en el else, el programa simplemente sigue buscando
    la solucion*/
    }
    if(maxDepht <= solSize){
        return;
        /*Si la profundidad m�xima es menor o igual al tama�o de la solucion,
        significa que el programa no puede ir m�s prfundo y se tiene que regresar,
        aunque no se haya encontrado la soluci�n*/
    }
    for(int i = 2; i <= sized; i++){
        if(i==prevNode)//condici�n que evita que la misma cantidad de pancakes sea volteada
            continue;
        flip(x, i);//Se voltean los primeros pancakes
        ActSol[solSize++] = i;//el valor de i se convierte en la soluci�n actual y el tama�o de la solucion aumenta
        dfs(x, i);//usa la dfs desde el estado actual de la pila
        flip(x, i);//vuelte a voltear para retroceder
        solSize--;
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
    Pancakes[sized] = '\0'; //establece el caracter nulo para indicar el final de la cadena

    //CADENA ESPECIFICA
    strcpy(Pancakes, "badc");
    strcpy(OriginalPancake, Pancakes);
    printf("Cadena inicial: %s\n",Pancakes);

    //IMPRESION DE LA B�SQUEDA
    dfs(Pancakes, 0);
    printf("\nPancakes que se movieron: ");
    for (i=0; i<bestSolSize; i++){
        printf("\n%d ", bestSol[i]);
    }
    printf("\nCantidad de movimientos utilizados para llegar a la solucion: %d\n", bestSolSize);
    return 0;
}
