/*
  Grafos
  Matriz adyacente: 

  Idea basica de una matriz adyacencia
  Un grafo con N vértices se puede representar con una matriz de N X N:
    - Filas: nodo origen.
    - Columnas: nodo destino.
    - Valor: indica si hay una conexión (1) o no (0).
    - Si el grafo es ponderado l conexión no es 1 si no el peso de la conexión.
*/


#include <stdio.h>

#define N 4 //Número de nodos


//Implementamos una Matriz de adyacente (no dirigido) 

//Inicializamos los grafos sin conexiones.
void iniciarMatriz(int grafo[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            grafo[i][j]= 0;  
        }
    }
}

//Implementamos una Matriz de adyacente (dirigido)
void agregarAristasNoDirigidas(int grafo[N][N], int origen, int destino){
    grafo[origen][destino]=1;
    grafo[destino][origen]=1;
}

void mostrarMatriz(int grafo[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d", grafo[i][j]);
        }
        printf("\n");
    }
}


//Implementamos una Matriz de adyacente (dirigido) 
void agregarAristasDirigidas(int grafo[N][N], int origen, int destino){
    grafo[origen][destino]=1;
}

void imprimirMatrizDirigida(){
    printf("\nEjemplo visual de grafos dirigidos:\n");
    printf("\n0 -> 1\n");
    printf("0 -> 2\n");
    printf("0 -> 3\n");
    printf("2 -> 3\n\n");
}

void imprimirMatrizNoDirigida(){
    printf("\nEjemplo visual de grafos no dirigidos:\n");
    printf("\n0 <-> 1\n");
    printf("0 <-> 2\n");
    printf("0 <-> 3\n\n");
}

int main() {
    int grafo[N][N];
    int opc=0;
    iniciarMatriz(grafo);
    
    printf("Implementación de Matrices adyacentes\n");
    printf("1- Matriz adyacente (No diriguida)\n");
    printf("2- Matriz adyacente (Diriguida)\n");
    printf("Ingrese una opcion: ");
    scanf("%d",&opc);

    switch (opc)
    {
    case 1:
        //Imprimirmos matriz no dirigida
        imprimirMatrizNoDirigida();
        
        agregarAristasNoDirigidas(grafo,0,1);
        agregarAristasNoDirigidas(grafo,0,2);
        agregarAristasNoDirigidas(grafo,0,3);    
        mostrarMatriz(grafo);
        break;
    case 2:
        //Imprimirmos matriz dirigida
        imprimirMatrizDirigida();
        //Agregamos las aristas 
        agregarAristasDirigidas(grafo,0,1);
        agregarAristasDirigidas(grafo,0,2);
        agregarAristasDirigidas(grafo,0,3);
        agregarAristasDirigidas(grafo,2,3);

        //Imprimir la matriz
        mostrarMatriz(grafo);
        break;
    
    default:
        break;
    }
    
    return 0;
}
