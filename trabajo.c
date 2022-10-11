#include <stdio.h>
#include <stdlib.h>

#include "trabajo.h"
#include "auto.h"
#include "servicios.h"

int inicializarTrabajos(eTrabajo vec[], int tamTR)
{
    int todoOk = 0;

    if(vec!= NULL && tamTR > 0)
    {

        for( int i = 0; i < tamTR; i++)
        {
            vec[i].isEmpty = 1;
        }

        todoOk = 1;
    }


    return todoOk;
}







int altaTrabajo(eTrabajo vec[], int tamTR, eAuto autos[], int tam, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC,  int* pNextId)
{

    int todoOk = 0;
    int indice;
    int idAuto;
    int idServicio;
    eFecha fecha;
     eTrabajo nuevoTrabajo;


    if(vec != NULL  && autos != NULL && marcas != NULL && servicios != NULL  && colores != NULL && tamTR > 0 && tam > 0 && tamM > 0 && tamS > 0 && tamC > 0 && pNextId != NULL)

    {
        system("cls");
        printf("         ********Alta Trabajo********\n");
        printf("-----------------------------------------\n");
        buscarLibreTrabajo(vec, tamTR, &indice); //esta funcion devuelve -1 sino hay lugar o el numero de indice proximo vacio.


        if (indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }

        else
        {
            nuevoTrabajo.id = *pNextId;



             //listar autos
            listarAutos(autos, tam, marcas, tamM, colores, tamC);
            printf("Ingrese  Id Auto: ");
            fflush(stdin);
            scanf("%d", &idAuto);
            while(validarAuto(autos,tam, idAuto)==0)
            {
                printf("Reingrese  Id Auto: ");
                fflush(stdin);
                scanf("%d", &idAuto);
            }

            nuevoTrabajo.idAuto = idAuto;

            //listar colores.
            listarServicios(servicios, tamS);
            printf("Ingrese  Id Servicio: ");
            fflush(stdin);
            scanf("%d", &idServicio);
            while(validarServicio(servicios,tamS, idServicio)==0)
            {
                printf("Reingrese  Id servicio: ");
                fflush(stdin);
                scanf("%d", &idServicio);
            }

            nuevoTrabajo.idServicio = idServicio;


            while(pidoValidoFecha(&fecha)== 0)
            {
                printf("ingrese fecha de Ingreso dd/mm/aaaa:");
                scanf("%d/%d/%d",
                      &fecha.dia,
                      &fecha.mes,
                      &fecha.anio);

            }

            nuevoTrabajo.fecha = fecha;


            nuevoTrabajo.isEmpty = 0;
            //lo igual a cero porque digo que esa posicion no va a estar libre
            //recordar que isEmpty es 1 si esta libre. y 0 sin no lo esta


            vec[indice] = nuevoTrabajo;
            //aca lo inyecto en la lista de motos

            (*pNextId)++;
            //aca una vez inyectado tengo que actualizar a traves de *pNextId lo incremento en 1



            todoOk = 1;

        }




    }

    return todoOk;
}


int buscarLibreTrabajo(eTrabajo vec[], int tamTR, int* pIndex)
{
    int todoOk;

    if(vec != NULL && pIndex != NULL && tamTR > 0)
    {
        for(int i = 0; i < tamTR ; i++)
        {
            *pIndex = -1;

            if(vec[i].isEmpty)
            {
                *pIndex = i;
                break;
            }

        }

        todoOk = 1;

    }

    return todoOk;

}



int listarTrabajos(eTrabajo trabajos[],  int tamTR, eServicio servicios[], int tamS)
{
    int todoOk = 0;
    int flag = 1;

    if(trabajos != NULL && servicios != NULL && tamTR > 0 && tamS > 0)
    {

        printf("                ***Listado de Trabajos***       \n");
        printf(" Id Trabajo       Id Auto     Id Servicio          Fecha\n");
        printf("---------------------------------------------------------- \n");

        for(int i = 0; i < tamTR; i++)
        {

            if( !trabajos[i].isEmpty)
            {
                mostrarTrabajoFila(trabajos[i], servicios, tamS);
                flag = 0;
            }

        }
        todoOk = 1;
    }

    if(flag)
    {

        printf("     no hay trabajos en el sistema\n");
    }


    return todoOk;
}


void mostrarTrabajoFila (eTrabajo trabajos, eServicio servicios[], int tamS)
{

    char descripcionServicio [20];


    cargarDescripcionServicio(servicios, tamS, trabajos.idServicio, descripcionServicio);




    printf("    %4d            %4d      %10s        %2d/%2d/%2d\n",
           trabajos.id,
           trabajos.idAuto,
           descripcionServicio,
           trabajos.fecha.dia,
           trabajos.fecha.mes,
           trabajos.fecha.anio
          );

}


int harcodearTrabajos(eTrabajo vec[], int tamTR, int cantTR, int* pNextId)
{
    int todoOk = 0;

    eTrabajo trabajos [15]=
    {
        {0, 1000, 20001 ,{10,7,2019},0},
        {0, 1001, 20001 ,{10,10,2019},0},
        {0, 1002, 20002 ,{9,9,2022},0},
        {0, 1003, 20003 ,{29,9,2021},0},
        {0, 1004, 20004 ,{11,8,2022},0},
        {0, 1005, 20004 ,{12,7,2022},0},
        {0, 1006, 20003 ,{14,6,2022},0},
        {0, 1007, 20002 ,{23,5,2022},0},
        {0, 1008, 20002 ,{19,4,2022},0},
        {0, 1009, 20000 ,{12,3,2022},0},
        {0, 1010, 20002 ,{26,2,2022},0},
        {0, 1011, 20002 ,{22,2,2020},0},
        {0, 1012, 20003 ,{12,1,2021},0},
        {0, 1013, 20003 ,{30,10,2022},0},
        {0, 1014, 20000 ,{17,8,2022},0}



    };

    if(vec != NULL && pNextId != NULL && tamTR > 0 && tamTR <=15 && cantTR <= tamTR)
    {
        for (int i = 0; i<cantTR; i++)
        {
            vec[i]= trabajos[i];
            vec[i].id = *pNextId;
            (*pNextId)++;

        }

        todoOk = 1;
    }

    return todoOk;
}
