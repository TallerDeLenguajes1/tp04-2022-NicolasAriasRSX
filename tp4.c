#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
//Estructuras//
typedef struct Tarea{
    int tareaID;  //Numerado en ciclo iterativo
    char *descripcion; //Ingresado por el usuario
    int duracion; //Entre 10 y 100
}tarea;
typedef struct Nodo{
    tarea T; //Dato de tipo tarea
    struct Nodo *siguiente; // puntero al siguiente nodo
}nodo;
//Declaracion de funciones
nodo *crear_lista_vacia();
nodo *crear_nodo(int);
void insertar_nodo_en_lista(nodo **, int);
void insertar_nodo_final_lista(nodo **, int);
void cargar_lista(nodo **, int);
void mostrar_lista(nodo *);
void control_tareas(nodo **, nodo **);

//tareas
//crear lista vacia x
//crear nodo x
//cargar lista de tareas x
//mostarar lista de tareas x
//separar tareas ente pendientes y realizadas
int main()
{
    srand(time(NULL));
    int cantTareas;
    nodo *cabeceraListaTareaPendiente;
    nodo *cabeceraListaTareaRealizada;
    printf("Ingrese la cantidad de tareas que realizara:   ");
    scanf("%d", &cantTareas);
    cabeceraListaTareaPendiente= crear_lista_vacia();
    cabeceraListaTareaRealizada= crear_lista_vacia();
    // getch();
    system("cls");
    cargar_lista(&cabeceraListaTareaPendiente, cantTareas);
    getch();
    system("cls");
    control_tareas(&cabeceraListaTareaPendiente, &cabeceraListaTareaRealizada);
    printf("\nTareas pendientes\n");
    mostrar_lista(cabeceraListaTareaPendiente);
    printf("\nTareas realizadas\n");
    
    // scanf(" %d");
    getch();
    return 0;
}
//Funciones//__________________-------------------------____________________
nodo *crear_lista_vacia()
{
    return NULL;
}
nodo *crear_nodo(int id)
{
    char buff[100];
    nodo *nNodo;
    nNodo= (nodo *) malloc(sizeof(nodo));//reservo memoria para el nuevo nodo
    //inicio de carda de datos del nodo
    nNodo->T.duracion= 10 + rand() % (101 - 10);
    nNodo->T.tareaID= id + 1;
    printf("Ingrese una descripcion de la tarea a realizar:\n");
    fflush(stdin);
    gets(buff);
    nNodo->T.descripcion= (char *) malloc(sizeof(char) * strlen(buff));
    strcpy(nNodo->T.descripcion, buff);
    //fin de carga de datos del nodo
    nNodo->siguiente= NULL;//puntero siguente a null.

    return nNodo;
}
void insertar_nodo_en_lista(nodo **listaTareas, int id)
{
    nodo *nuevoNodo= NULL;
    
    nuevoNodo= crear_nodo(id);
    if (nuevoNodo != NULL)//Es para saber si se reservo memoria correctamete.
    {
        nuevoNodo->siguiente= *listaTareas;
        *listaTareas= nuevoNodo;
    }       
}
void insertar_nodo_final_lista(nodo **listaTareas, int id)
{
    nodo *nNodo= NULL;
    nodo *nAux= *listaTareas;

    nNodo= crear_nodo(id);

    if(nNodo != NULL)//Veo si se reservo la memoria.
    {
        if(nAux != NULL)//Creo que es para ver si la lista no esta llegando vacia
            {
                while (nAux->siguiente != NULL)
                {
                    nAux= nAux->siguiente;
                }
                nAux->siguiente= nNodo;
            }else{
                *listaTareas= nNodo;
            }
    }
}
void mostrar_lista(nodo *listaTareas)
{
    nodo *nAux= listaTareas;

    while (nAux != NULL)
    {
        printf("Id de la tarea: %d\n", nAux->T.tareaID);
        printf("Duracion de la tarea: %d\n", nAux->T.duracion);
        printf("Descripcion de la tarea: %s\n", nAux->T.descripcion);
        printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
        nAux= nAux->siguiente;
    }   
}
void cargar_lista(nodo** listaTarea, int cantidadTareas)
{
    int j= 0;
    char buffOpcion;
    printf("\nCargar lista desde el princiopio opcion--> p\nCargar lista desde el final opcion--> f\n");
    fflush(stdin);
    scanf("%c",&buffOpcion);
    if (buffOpcion == 'p')
    {
        for (int i = 0; i < cantidadTareas; i++)
        {
            insertar_nodo_en_lista(listaTarea,j);
            j++;
        }
    }else{
        for (int i = 0; i < cantidadTareas; i++)
        {
            insertar_nodo_final_lista(listaTarea,j);
            j++;
        }
    }
}
void control_tareas(nodo **tareasPendientes, nodo **tareasRealizadas)
{
    nodo *nAux;
    char buff;
    nAux= *tareasPendientes;
    while (nAux != NULL)
    {
        printf("\nLa tarea %s con id %d fue realizada?\nPreione:\ns->si\nn->no\n", nAux->T.descripcion, nAux->T.tareaID);
        fflush(stdin);
        scanf("%c", &buff);
        if (buff == 's')
        {
            //muevo la tarea a tareasRealizadas
            //la elimino de la lista de tareasPendientes
            //muevo el nodo al siguiente
            printf("Presiono s");
            nAux= nAux->siguiente;
        }else{
            printf("presiono n");
            nAux= nAux->siguiente;
        }
        
    }
    
}