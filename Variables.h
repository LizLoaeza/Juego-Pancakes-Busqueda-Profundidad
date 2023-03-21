#ifndef VARIABLES_INCLUDED
#define VARIABLES_INCLUDED

#define MAX     100

int nodes;
int maxDepht;
int sized;
int solSize;

char Goal[2*('z'-'a'+1)+1];//Toma en cuenta que la meta es todo el abecedario de minusculas y mayusculas
int ActSol[MAX];
int bestSol[MAX];
int bestSolSize;

void flip(char *, int);
void dfs(char *, int);

#endif // VARIABLES_INCLUDED
