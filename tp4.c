#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>

typedef struct Tarea{
    int tareaID;  //Numerado en ciclo iterativo
    char *descripcion; //Ingresado por el usuario
    int duracion; //Entre 10 y 100
}tarea;
//Declaracion de funciones
void cargar_tareas(tarea **t, int cantidadTareas);
void mostrar_tareas(tarea **t, int cantidadTareas);
void control_tareas(tarea **tareaRealizada, tarea **tareaPendiente, int cantidadTareas);
void buscar_tarea(tarea **tareaRealizada, tarea **tareaPendiente, int cantidadTareas);
int main()
{
    srand(time(NULL));
    int cantTareas;
    printf("Ingrese la cantidad de tareas que realizara:   ");
    scanf("%d", &cantTareas);
    tarea **tareasPendientes= (tarea **) malloc(sizeof(tarea) * cantTareas);
    tarea **tareasRealizadas= (tarea **) malloc(sizeof(tarea) * cantTareas);
    cargar_tareas(tareasPendientes, cantTareas);
    system("cls");
    mostrar_tareas(tareasPendientes, cantTareas);
    getch();
    system("cls");
    control_tareas(tareasRealizadas,tareasPendientes,cantTareas);
    getch();
    system("cls");
    printf("\n----------------------\nTareas realizadas\n----------------------\n");
    mostrar_tareas(tareasRealizadas, cantTareas);
    printf("\n----------------------\nTareas pendientes\n----------------------\n");
    mostrar_tareas(tareasPendientes, cantTareas);
    getch();
    system("cls");
    printf("\n----------------------\nBuscar tarea\n----------------------\n");
    buscar_tarea(tareasRealizadas,tareasPendientes,cantTareas);

    // scanf(" %d");
    getch();
    return 0;
}
void cargar_tareas(tarea **t, int cantidadTareas)
{
    char buff[100];
    for (int i = 0; i < cantidadTareas; i++)
    {
        fflush(stdin);
        t[i]= (tarea *) malloc(sizeof(tarea));
        t[i]->tareaID= i + 1;
        t[i]->duracion= 10 + rand() % (101 - 10);
        printf("Ingrese una descripcion de la tarea a realizar:\n");
        gets(buff);
        // scanf("%s", buff);
        t[i]->descripcion= (char *) malloc(sizeof(char) * strlen(buff));
        strcpy(t[i]->descripcion, buff);
    }   
}
void mostrar_tareas(tarea **t, int cantidadTareas)
{
    printf("Lista de tareas:\n");
    for (int i = 0; i < cantidadTareas; i++)
    {
        if (t[i])
        {
            printf("ID de la tarea: %d\n", t[i]->tareaID);
            printf("Duracion de la tarea: %d min\n", t[i]->duracion);
            printf("Descriocion de la tarea: %s\n----------------------------------\n", t[i]->descripcion);
        }
    }
    
}
void control_tareas(tarea **tareaRealizada, tarea **tareaPendiente, int cantidadTareas)
{
    char buff;

    printf("-*-*-*-*-*-*-*-*-*-*-*-\nControl de tareas\n-*-*-*-*-*-*-*-*-*-*-*\n");
    for (int i = 0; i < cantidadTareas; i++)
    {
        printf("La tarea: %s, con ID %d, se realizo?\n s para si, n para no\n", tareaPendiente[i]->descripcion, tareaPendiente[i]->tareaID);
        // getc(buff);
        scanf("%c", &buff);
        fflush(stdin);
        if (buff =='s')
        {
            tareaRealizada[i]= (tarea *) malloc(sizeof(tarea));
            tareaRealizada[i]= tareaPendiente[i];
            tareaPendiente[i]= NULL;
        }else{
            tareaRealizada[i]= NULL;
        }
    }
    printf("\nSe controlaron todas las tareas.\n");   
}
void buscar_tarea(tarea **tareaRealizada, tarea **tareaPendiente, int cantidadTareas)
{
    int idAux;
    printf("Ingrese el ID de la tarea buscada (no mayor que %d)", cantidadTareas);
    scanf("%d", &idAux);
    for (int i = 0; i < cantidadTareas; i++)
    {
        if (tareaPendiente[i]->tareaID == idAux && tareaPendiente[i])
        {
            printf("La tarea buscada con ID = %d esta pendientes\n", tareaPendiente[i]->tareaID);
            printf("Tarea: %s\n", tareaPendiente[i]->descripcion);
            printf("Duracion: %d\n", tareaPendiente[i]->duracion);
        }else{
            if (tareaRealizada[i]->tareaID == idAux && tareaRealizada[i]);
            {
                printf("La tarea buscada con ID = %d esta realizada\n", tareaRealizada[i]->tareaID);
                printf("Tarea: %s\n", tareaRealizada[i]->descripcion);
                printf("Duracion: %d\n", tareaRealizada[i]->duracion);
            }
        }
    }
}