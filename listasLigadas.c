#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
    Listas enlazadas (Linked Lists)

    Una lista enlazada es una colección de elementos llamdos nodos, donde cada nodo
    contiene dos partes: el dato y un puntero que apunta al siguiente nodo en la secuencia.
    El primer nodo de la lista se llama cabeza (head). A diferencia de los arreglos, los nodos
    no necesitan estar en memoria contigua.  

    Características principales:
    - Tamaño dinamico: El tamaño de una lista enlazada puede crecer o disminuir en tiempo de 
      ejecución.
    - Inserción y eliminación eficientes: Es muy facil añadir o quitar nodos en cualquier posición 
      sin mover los demás nodos.
    - Acceso secuencial: Para llegar a un elemento especifico, debes empezar desde el inicio
      (head) y seguir los punteros uno por uno.
*/

/*
    Para implementar una lista enlazada devemos crear una estructura para el nodo
*/

// Estructura para los nodos
struct listaEnlazada{
    int dato; //Dato que almacena el nodo
    char nombre[20]; //Nombre del nodo
    struct listaEnlazada* siguiente; //Puntero al siguiente nodo
};

// Función para imprimir la lista
void ImprimirLista(struct listaEnlazada* nodo){
    printf("\nImprimir lista enlazada: \n");
    while(nodo != NULL){
        printf("Dato: %d \n", nodo->dato);
        printf("Nombre: %s", nodo->nombre);
        nodo = nodo->siguiente; //Avanza al siguiente nodo.
        printf("\n");
    }
}

//Función para insertar nodos a la lista
struct listaEnlazada* InsertarNodos(){

    struct listaEnlazada* cabeza = NULL;
    struct listaEnlazada* segundo = NULL;
    struct listaEnlazada* tercero = NULL;
    struct listaEnlazada* cuarto = NULL;

    //Asignart memoria para nodos
    cabeza = (struct listaEnlazada*)malloc(sizeof(struct listaEnlazada));
    segundo = (struct listaEnlazada*)malloc(sizeof(struct listaEnlazada));
    tercero = (struct listaEnlazada*)malloc(sizeof(struct listaEnlazada));
    cuarto = (struct listaEnlazada*)malloc(sizeof(struct listaEnlazada));

    //Asignamos datos y enlazamos los nodos
    cabeza->dato = 1;
    strcpy (cabeza->nombre, "Nodo 1");
    cabeza->siguiente=segundo;
    
    segundo->dato=2;
    strcpy(segundo->nombre, "Nodo 2");
    segundo->siguiente=tercero;

    tercero->dato=3;
    strcpy(tercero->nombre,"Nodo 3");
    tercero->siguiente=cuarto;

    cuarto->dato=4;
    strcpy(cuarto->nombre,"Nodo 4");
    cuarto->siguiente=NULL; //El último nodo apunta a NULL

    return cabeza;
}

/*
   Insertar un nuevo nodo en la lista enlazada al inicio de la lista. 
*/

struct listaEnlazada* InsertarNodoInicio(struct listaEnlazada* cabeza,char* nombre, int dato) {
    struct listaEnlazada* nuevaCabeza = NULL; 
    
    nuevaCabeza = (struct listaEnlazada*)malloc(sizeof(struct listaEnlazada));
    
    char nodo[20]= "Nodo";
    char nombreNodo[30];
    int cont = 1;

    //Insertamos los valores a nuestro nuevo nodo.
    nuevaCabeza->dato = dato;
    strcpy(nuevaCabeza->nombre,nombre);
    nuevaCabeza->siguiente = cabeza;
    
    return nuevaCabeza;
}

/*
   Insertar un nuevo nodo en la lista enlazada al final de la lista. 
*/

struct listaEnlazada* InsertarNodoFin(struct listaEnlazada* cabeza,char* nombre, int dato) {
    struct listaEnlazada* nuevaNodo = NULL; 
    struct listaEnlazada* Nodo = NULL;

    nuevaNodo = (struct listaEnlazada*)malloc(sizeof(struct listaEnlazada));
    //Nodo = (struct listaEnlazada*)malloc(sizeof(struct listaEnlazada));
    Nodo = cabeza;
    
    //Ingresamoslos valores al nuevo nodo 
    nuevaNodo->dato = dato;
    strcpy(nuevaNodo->nombre,nombre);
    nuevaNodo->siguiente = NULL;

    while (1)
    {
        if(cabeza->siguiente == NULL){
            cabeza->siguiente = nuevaNodo;
            break;
            
        }
        
        cabeza = cabeza->siguiente;
        
        
    }

    return Nodo;
    
    //Insertamos los valores a nuestro nuevo nodo.
    nuevaNodo->dato = dato;
    strcpy(nuevaNodo->nombre,nombre);
    nuevaNodo->siguiente = cabeza;
    
    return cabeza;
}

/*Eliminar un nodo al inicio de la lista ligada */
struct listaEnlazada* eliminarNodoInicio(struct listaEnlazada* cabeza){
    //Solo recoremos el puntero 
    cabeza = cabeza->siguiente;
    return cabeza;
}

/*Eliminar un nodo al final de la fila.*/
struct listaEnlazada* eliminarNodoFin(struct listaEnlazada* cabeza){
    int salir = 1;
    struct listaEnlazada* Nodo;
    struct listaEnlazada* Anterior;
    

    Nodo = cabeza;
    //Solo recoremos el puntero 
    while (1)
    {   
        if(cabeza->siguiente == NULL){
            break;
        }
        
        Anterior = cabeza;
        cabeza = cabeza->siguiente;
        
    }

    //Eliminamos el ultimo Nodo
    Anterior->siguiente = NULL;

    return Nodo;   
}

/*Eliminar un Nodo seleccionado*/
struct listaEnlazada* eliminarNodoSeleccionado(struct listaEnlazada* cabeza, int posicion){
    struct listaEnlazada* Nodo;
    struct listaEnlazada* antNodo;
    int cont = 0;
    
    antNodo = (struct listaEnlazada*)malloc((sizeof(struct listaEnlazada)));
    Nodo = cabeza;
    posicion = posicion-1;
    
    while (1)
    {
        
        if(cabeza->siguiente == NULL){
            perror("\nNo se encontro posición en la lista ligada.\n");
            break;
        }
        
        //En este caso es si el usuario quiere eliminar la posicion 1 indice 0.
        if(cont == posicion && cont == 0){
            cabeza= cabeza->siguiente;
            Nodo = cabeza;  
            break;
        }
        
        //Este caso es es si el usuario escoje mayor del inicio y menor del final.
        if(cont == posicion && cabeza->siguiente != NULL){
            antNodo->siguiente = cabeza->siguiente;
            break;   
        }        

        //Vamos guardando el anterior nodo
        antNodo = cabeza;
        //Recorremos la lista.
        cabeza= cabeza->siguiente; 
        cont ++;  
        
        //Este caso es si el usuario quiere eliminar el ultimo Nodo.
        if(cont == posicion && cabeza->siguiente == NULL){
            antNodo->siguiente = NULL;
            break;
        }

    }
    return Nodo;
}

/*Insertamos un nodo en la posición de un usuario lo espeficique.*/
struct listaEnlazada* InsertarNodoPosicion(struct listaEnlazada* cabeza, int posicion, char* nombre, int dato){
    int cont = 1;
    
    struct listaEnlazada* nuevoNodo;
    struct listaEnlazada* Anterior = NULL;
    struct listaEnlazada* Actual = cabeza;

    nuevoNodo = (struct listaEnlazada*)malloc(sizeof(struct listaEnlazada));
    

    //Llenamos el nodo com el nuevo valor
    nuevoNodo->dato = dato;
    strcpy(nuevoNodo->nombre,nombre);
    nuevoNodo->siguiente = NULL;

    //Posición de inicio
      // Insertar al inicio
    if (posicion == 1) {
        nuevoNodo->siguiente = cabeza;
        return nuevoNodo;
    }
    
     // Recorrer hasta la posición deseada
    while (Actual != NULL && cont < posicion) {
        Anterior = Actual;
        Actual = Actual->siguiente;
        cont++;
    }
    
    if (cont == posicion) {
        // Insertar en medio o al final
        Anterior->siguiente = nuevoNodo;
        nuevoNodo->siguiente = Actual;
    } else {
        // La posición está fuera de rango
        fprintf(stderr, "No se encontró índice donde guardar el Nodo.\n");
        free(nuevoNodo);
    }
    
    return cabeza;
}

int main()
{   
    int opc = 0;
    int datoNodo=0;
    int posicionNodo = 0;
    char nombreNodo[30];
    struct listaEnlazada* cabeza = NULL;

    printf("Ejercicios de listas ligadas.\n");
    printf("Opciones: \n");
    printf("1. Imprimir lista enlazada. \n");   
    printf("2. Agregar un nuevo elementos. \n");
    printf("3. Eliminar un elementos. \n");
    printf("4. Buscar un elemento. \n");
    
    printf("Ingresa la opción:");
    scanf("%d", &opc);

    cabeza = InsertarNodos();

    switch (opc)
    {
        case 1:
            ImprimirLista(cabeza);
            break;
        case 2:
            printf("Insertar un nuevo elemento en la lista.\n");
            printf("1. Insertar en el inicio. \n");
            printf("2. Insertar en el final. \n");
            printf("3. Insertar en una posición específico. \n");
            scanf("%d", &opc);
            switch (opc)
            {
                case 1:
                    printf("Ingresa en nombre del nuevo nodo: ");
                    scanf("%s",nombreNodo);
                    
                    printf("Ingresa en dato del nuevo nodo: ");
                    scanf("%d",&datoNodo);

                    cabeza = InsertarNodoInicio(cabeza,nombreNodo,datoNodo);
                    ImprimirLista(cabeza);
                    exit(1);
                case 2:
                    printf("Ingresa en nombre del nuevo nodo (sin espacios): ");
                    scanf("%s",nombreNodo);
                    
                    printf("Ingresa en dato del nuevo nodo: ");
                    scanf("%d",&datoNodo);

                    cabeza = InsertarNodoFin(cabeza,nombreNodo,datoNodo);
                    ImprimirLista(cabeza);
                    exit(1);
                    
                case 3:
                    printf("Ingresa en nombre del nuevo nodo (sin espacios): ");
                    scanf("%s",nombreNodo);
                    
                    printf("Ingresa en dato del nuevo nodo: ");
                    scanf("%d",&datoNodo);
                    
                    printf("Ingresa la posición dondese insertara el nodo: ");
                    scanf("%d",&posicionNodo);

                    cabeza=InsertarNodoPosicion(cabeza, posicionNodo, nombreNodo,datoNodo);
                    ImprimirLista(cabeza);
                    exit(1);

                default:
                    printf("Opción no válida.");
                    exit(1);
            }
        case 3:
                printf("1. Elimina un nodo al inicio. \n");
                printf("2. Elimina un nodo al final. \n");
                printf("3. Elimina un nodo que ingresando su posición. \n");
                scanf("%d", &opc);
                switch (opc)
                {
                    case 1:
                        cabeza = eliminarNodoInicio(cabeza);
                        ImprimirLista(cabeza);
                        exit(1);

                    case 2:
                        cabeza = eliminarNodoFin(cabeza);
                        ImprimirLista(cabeza);
                        exit(1);

                    case 3:
                        int posicion = 0;
                        printf("Ingresa la posición del Nodo: ");
                        scanf("%d",&posicion);
                        cabeza = eliminarNodoSeleccionado(cabeza, posicion);
                        ImprimirLista(cabeza);
                        exit(1);

                    default:
                        printf("Opción no válida.");
                        exit(1);
                }
                break;
        default:
            printf("Opción no válida. \n");
            break;
    }
    
    return 0;
}
