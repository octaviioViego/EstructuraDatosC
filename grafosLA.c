/*
    Grafos 
    Listas adyacentes
*/

#include<stdio.h>
#include<stdlib.h>

#define N 5

//Noto: Cuando ponemos un nombre enseguida de la estructura es el alias de la misma.
typedef struct Nodo{
    int vertice;
    struct Nodo* siguiete;
}Nodo;
//Noto: Cuando ponemos un nombre enseguida de la estructura es el alias de la misma. Así no
//yo no ponemos struct Nodo  cada vez que intentemos llamarla (Es un alias).

//Es un arreglo de punteros
Nodo* listaAdy[N] = {NULL};

void agregarArista(int origen, int destino){
    Nodo* nuevo = malloc(sizeof(Nodo));
    nuevo->vertice= destino;
    nuevo->siguiete= listaAdy[origen];
    listaAdy[origen] = nuevo;
}

void imprimirGrafo() {
    for (int i = 0; i < N; i++) {
        printf("%d: ", i);
        Nodo* temp = listaAdy[i];
        while (temp) {
            printf("%d -> ", temp->vertice);
            temp = temp->siguiete;
        }
        printf("NULL\n");
    }
}

int main(){
    agregarArista(0, 1);
    agregarArista(0, 4);
    agregarArista(1, 2);
    agregarArista(1, 3);
    agregarArista(1, 4);

    imprimirGrafo();
    return 0;

}