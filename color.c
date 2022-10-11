#include <stdio.h>
#include <stdlib.h>

#include "color.h"


#include <string.h>

int cargarDescripcionColores(eColor colores[], int tamC, int id, char desc[])
{
    int todoOk = 0;

    if(colores != NULL && tamC > 0 && desc != NULL)
    {

        for(int i = 0; i < tamC ; i++)
        {

            if(colores[i].id == id)//repasar que hace esto.
            {
                strcpy(desc, colores[i].nombreColor);
                todoOk = 1;
                break;

            }
        }


    }


    return todoOk;
}




int listarColores(eColor colores[], int tamC)
{
    int todoOk = 0;

    if(colores != NULL && tamC > 0)
    {

        printf("         ***Listado de Colores***          \n");
        printf("        id                   Descripcion   \n");
        printf("-------------------------------------------\n");


        for(int i = 0; i< tamC; i++)
        {
            printf("       %4d      %20s\n", colores[i].id, colores[i].nombreColor);

        }

        todoOk = 1;
    }


    return todoOk;
}


int buscarColores(eColor colores[], int tamC, int id, int* pIndex)
{
    int todoOk = 0;

    if(colores !=NULL && tamC > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i = 0; i < tamC; i++)
        {
            if(colores[i].id == id)
            {

                *pIndex = i;
                break;

            }
        }


        todoOk = 1;
    }

    return todoOk;
}


int validarColores(eColor colores[], int tamC, int id)
{
    int esValido = 0;
    int indice;

    if(colores != NULL && tamC > 0)
    {

       if(buscarColores(colores, tamC, id, &indice))
        {
            if(indice != -1)
            {
                esValido = 1;
            }
        }

    }

    return esValido;
}
