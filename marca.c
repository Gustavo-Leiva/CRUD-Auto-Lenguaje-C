#include <stdio.h>
#include <stdlib.h>

#include "marca.h"


#include <string.h>


int cargarDescripcionMarcas(eMarca marcas[], int tamM, int id, char desc[])
{
    int todoOk = 0;

    if(marcas != NULL && tamM > 0 && desc != NULL)
    {

        for(int i = 0; i < tamM ; i++)
        {

            if(marcas[i].id == id)//repasar que hace esto.
            {
                strcpy(desc, marcas[i].descripcion);
                todoOk = 1;
                break;

            }
        }



    }


    return todoOk;
}




int listarMarcas(eMarca marcas[], int tamM)
{
    int todoOk = 0;

    if(marcas != NULL && tamM > 0)
    {
        printf("         ***Listado de Marcas***           \n");
        printf("        id                   Descripcion   \n");
        printf("-------------------------------------------\n");

        for(int i = 0; i < tamM ; i++)
        {

            printf("        %4d           %15s\n", marcas[i].id, marcas[i].descripcion);
        }


        todoOk = 1;
    }


    return todoOk;
}


int buscarMarca(eMarca marcas[], int tamM, int id, int* pIndex)
{
    int todoOk = 0;

    if(marcas != NULL && tamM > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i = 0; i < tamM; i++)
        {

            if(marcas[i].id == id)
            {
                *pIndex = i;
                break;

            }

        }
        todoOk = 1;
    }



    return todoOk;
}

int validarMarca(eMarca marcas[], int tamM, int id)
{
    int esValido = 0;
    int indice;

    if(marcas != NULL && tamM > 0)
    {

        if(buscarMarca(marcas, tamM, id, &indice))
        {
            if(indice != -1)
            {
                esValido = 1;
            }
        }

    }

    return esValido;
}
