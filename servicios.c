#include <stdio.h>
#include <stdlib.h>

#include "servicios.h"

#include <string.h>


int cargarDescripcionServicio(eServicio servicios[], int tamS, int id, char desc[])
{
    int todoOk = 0;

    if(servicios != NULL && desc != NULL && tamS > 0)
    {
      for(int i = 0; i < tamS; i++)
      {
          if(servicios[i].id == id)
          {
              strcpy(desc, servicios[i].descripcion);
              todoOk = 1;
              break;
          }
      }
    }
    return todoOk;
}



int buscarServicio(eServicio servicios[], int tamS, int id, int* pIndex)
{
    int todoOk = 0;


    if(servicios && pIndex && tamS > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tamS; i++)
        {
            if(servicios[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int listarServicios(eServicio servicios[], int tamS)
{
    int todoOk = 0;

    if(servicios != NULL && tamS > 0)
    {

        printf("            ***Listado de Servicios***       \n");
        printf("        id            Descripcion       Precio\n");
        printf("---------------------------------------------- \n");

        for(int i = 0; i< tamS; i++)
        {

            printf("       %5d    %15s        %5.2f\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);

        }




        todoOk = 1;
    }


    return todoOk;
}


int validarServicio(eServicio servicios[], int tamS, int id)
{
    int esValido = 0;
    int indice;

    if(buscarServicio(servicios, tamS, id, &indice) == 1)
    {
        if(indice != -1)
        {
            esValido = 1;
        }
    }
    return esValido;
}
