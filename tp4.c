#include<stdio.h>
#include<stdlib.h>
#include<time.h>
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
int main()
{
    srand(time(NULL));
    int cantTareas;
    printf("Ingrese la cantidad de tareas que realizara:   ");
    scanf("%d", &cantTareas);
    tarea **tareasPendientes= (tarea **) malloc(sizeof(tarea) * cantTareas);
    tarea **tareasRealizadas= (tarea **) malloc(sizeof(tarea) * cantTareas);
    cargar_tareas(tareasPendientes, cantTareas);
    mostrar_tareas(tareasPendientes, cantTareas);
    control_tareas(tareasRealizadas,tareasPendientes,cantTareas);
    mostrar_tareas(tareasRealizadas, cantTareas);
    printf("Pendientes");
    mostrar_tareas(tareasPendientes, cantTareas);
    
    scanf(" %d");
    // getchar();
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
        if (t[i] != NULL)
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
        }
    }
    printf("\nSe controlaron todas las tareas.\n");
    
}