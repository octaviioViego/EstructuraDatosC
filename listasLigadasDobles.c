#include<stdio.h>
#include<stdlib.h>

/*
    Listas Enlazadas Simples (Singly Linked Lists)

    Es una versión mejorada en la que cada nodo tiene dos punteros: uno que apunta al siguiente
    nodo y otro que apunta al anterior nodo.

    Caracteristicas clave:
    - Recorrido bidireccional: Puedes moverte hacia adelante (usando el puntero siguiente)
      y hacia atrás (usando el puntero anterior) en lalista. 
    - Operaciones más eficientes: La eliminación de un nodo es más sencilla por que no necesitas un puntero
      al nodo anterior para desplazarlo; el nodo actual ya lo tiene.
    - Memoria adicional: Cada nodo requiere más memoria, ya que necesita almacenar un puntero
      adicional (anterior).
*/

/*
    Para implementar una lista doblemente enlazada.
*/

struct ListaEnlazada
{
    int dato;
    struct ListaEnlazada* anterior;
    struct ListaEnlazada* siguiente;
};


// Función para imprimir la lista doblemente ligada.
void ImprimirListaDoble(struct ListaEnlazada* nodo){

    while(nodo != NULL){

        printf("%d", nodo->dato);

        nodo = nodo->siguiente; //Avanza al siguiente nodo.

        printf("\n");

    }

}

struct ListaEnlazada* llenarListaEnlazada(){
    struct ListaEnlazada* cabeza= NULL;
    struct ListaEnlazada* primero= NULL;
    struct ListaEnlazada* segundo= NULL;
    struct ListaEnlazada* tercero= NULL;
    

    /*
        Explicación de la asignación de memoria
        
        malloc(sizeof(struct ListaEnlazada))
        - sizeof(struct ListaEnlazada)
            Calcula la cantidad de bytes que necesita tu estructura ListaEnlazada.
        - malloc()
            es una función de la biblioteca <stdlib.h> que solicita al sistema operativo 
            un bloque de memoria del tamaño especificado. devuelve un puntero de tipo 
            void* que apunta a la primera dirección de ese bloque de memoria.
        - (struct ListaEnlazada*) 
            Esto es un casting o conversión de tipo.malloc no sabe qué tipo de dato vas 
            a almacenar en esa memoria.
        - cabeza =
            Finalmente, asignas la dirección de memoria recién obtenida al puntero cabeza.
    */
    
    //Asignamos memoria
    cabeza = (struct ListaEnlazada*)malloc(sizeof(struct ListaEnlazada));
    primero = (struct ListaEnlazada*)malloc(sizeof(struct ListaEnlazada));
    segundo = (struct ListaEnlazada*)malloc(sizeof(struct ListaEnlazada));
    tercero = (struct ListaEnlazada*)malloc(sizeof(struct ListaEnlazada));



    /*
        Accedemos a la estructura de ListaEnlazada y asignamos los valores
        - dato
            Asignamos un valor de tipo entero
        - anterior
            Apuntamos el puntero llamado anterior a un nodo anterior o null 
        - siguiente  
            Apuntamos el puntero llamado siguiente a un nodo anterior o null
    */  
    
    //Enlazamos los nodos a las listas
    cabeza->dato = 1;
    cabeza->anterior = NULL;
    cabeza->siguiente= primero;

    primero->dato = 2;
    primero->anterior = cabeza;
    primero->siguiente= segundo;

    segundo->dato = 3;
    segundo->anterior = primero;
    segundo->siguiente= tercero;

    tercero->dato = 4;
    tercero->anterior = segundo;
    tercero->siguiente= NULL;

    return cabeza;

}

struct ListaEnlazada* agrearListaInicio(struct ListaEnlazada* cabeza, int dato){
    struct ListaEnlazada* nuevalista;
    nuevalista = (struct ListaEnlazada*)malloc(sizeof(struct ListaEnlazada));

    nuevalista->dato = dato;
    nuevalista->anterior = NULL;
    nuevalista->siguiente = cabeza;

    cabeza->anterior = nuevalista;
    
    return nuevalista;

}

struct ListaEnlazada* agregarListaFin(struct ListaEnlazada* cabeza, int dato){
    struct ListaEnlazada* nuevaLista;
    struct ListaEnlazada* ultimaLista = cabeza;
    nuevaLista = (struct ListaEnlazada*)malloc(sizeof(struct ListaEnlazada));

    //Recorremos la lista hasta alcanzar la ultima
    while (ultimaLista->siguiente != NULL)
    {
        ultimaLista = ultimaLista->siguiente ;
    }
    

    nuevaLista->dato = dato;
    nuevaLista->siguiente= NULL;
    ultimaLista->siguiente = nuevaLista;

    return cabeza;
}             

struct ListaEnlazada* agregarListaPosicion(struct ListaEnlazada* cabeza, int dato, int posicion){
    struct ListaEnlazada* nuevaLista;
    struct ListaEnlazada* Nodo = cabeza;
    int contador = 0;

    nuevaLista = (struct ListaEnlazada*)malloc(sizeof(struct ListaEnlazada));
    

    while (Nodo->siguiente != NULL && contador < posicion)
    {
       Nodo = Nodo->siguiente;
       contador++;
    }
    
    if(contador == posicion){
        nuevaLista->dato = dato;

        nuevaLista->anterior = Nodo->anterior; 
        nuevaLista->siguiente = Nodo;
        
        if (Nodo->anterior != NULL) {
            Nodo->anterior->siguiente = nuevaLista;
        }
        
        Nodo->anterior = nuevaLista; 
    }else{
         // La posición está fuera de rango
        fprintf(stderr, "No se encontró índice donde guardar el Nodo.\n");
        free(nuevaLista);
    }
    
    return cabeza;


}

struct ListaEnlazada* eliminarLista(struct ListaEnlazada* cabeza, int posicion) {
    if (cabeza == NULL) {
        fprintf(stderr, "Error: la lista está vacía.\n");
        return NULL;
    }

    // Indices humanos (1,2,3,...) los paso a base 0
    posicion = posicion - 1;

    struct ListaEnlazada* actual = cabeza;
    int cont = 0;

    // Caso especial: eliminar el primer nodo
    if (posicion == 0) {
        cabeza = actual->siguiente;
        if (cabeza != NULL) {
            cabeza->anterior = NULL;
        }
        free(actual);
        return cabeza;
    }

    // Buscar el nodo a eliminar
    while (actual != NULL && cont < posicion) {
        actual = actual->siguiente;
        cont++;
    }

    // Si no existe la posición
    if (actual == NULL) {
        fprintf(stderr, "Error: la posición no existe en la lista.\n");
        return cabeza;
    }

    // Reenlazar nodos
    if (actual->siguiente != NULL) {
        actual->siguiente->anterior = actual->anterior;
    }
    if (actual->anterior != NULL) {
        actual->anterior->siguiente = actual->siguiente;
    }

    free(actual); // liberar memoria del nodo eliminado
    return cabeza;
}

int main(){
    int posicion = 0;
    int opc = 0;
    struct ListaEnlazada* cabeza;

    printf("Ejercicio con listas enlazadas.\n");
    printf("1. Ver lista enlazada.\n");
    printf("2. Agregar nueva lista.\n");
    printf("Ingrese opción: ");
    scanf("%d", &opc);

    switch (opc)
    {
        case 1:
            cabeza = llenarListaEnlazada();
            ImprimirListaDoble(cabeza);
            break;
        case 2:
            printf("1. Agregar una nueva lista al inicio.\n");
            printf("2. Agregar una nueva lista al final.\n");
            printf("3. Agregar una nueva lista en el lugar que descee.\n");
            printf("4. Eliminar un elemento de la lista.\n");
            printf("Ingrese opción: ");
            scanf("%d",&opc);
            switch (opc)
            {
                case 1:
                    printf("Ingrese el numero que se guardara como dato: ");
                    scanf("%d",&opc);
                    cabeza = llenarListaEnlazada();
                    cabeza = agrearListaInicio(cabeza,opc);
                    ImprimirListaDoble(cabeza);
                    exit(1);
                case 2:
                    printf("Ingrese el numero que se guardara como dato: ");
                    scanf("%d",&opc);
                    cabeza = llenarListaEnlazada();
                    cabeza = agregarListaFin(cabeza,opc);
                    ImprimirListaDoble(cabeza);
                    exit(1);    
                
                case 3:
                    
                    printf("Ingrese la posicion donde se guardara la lista:");
                    scanf("%d",&posicion);
                    printf("Ingrese el numero que se guardara como dato: ");
                    scanf("%d",&opc);
                    cabeza = llenarListaEnlazada();
                    cabeza = agregarListaPosicion(cabeza,opc,posicion);
                    ImprimirListaDoble(cabeza);
                    exit(1);
                case 4:
                    printf("Ingrese la posicion donde se eliminara la lista:");
                    scanf("%d",&posicion);
                    cabeza = llenarListaEnlazada();
                    cabeza = eliminarLista(cabeza,posicion);
                    ImprimirListaDoble(cabeza);
                    exit(1);
                default:
                    printf("Opcion no valida.");
                    break;
            }
            
            break;
        
        default:
            printf("Opción no valida. ");
            break;
    }
}
