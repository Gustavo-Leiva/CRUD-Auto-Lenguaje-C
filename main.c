#include <stdio.h>
#include <stdlib.h>

#include "auto.h"
#include "marca.h"
#include "color.h"
#include "servicios.h"
#include "trabajo.h"
#include "validaciones.h"


#define TAM 15
#define TAMM 5
#define TAMC 5
#define TAMS 4

#define TAMTR 15
#define CANTA 8
#define CANTTR 6

int main()
{
    char salir = 'N';
    char opcion [] = {"1,2,3,4,30"};
    int proximoId = 1000;
    int proximoIdTrabajo = 7000;
    eAuto autos[TAM];
    eTrabajo trabajos[TAMTR];


    inicializarAutos(autos, TAM);
    inicializarTrabajos(trabajos, TAMTR);
    harcodearAutos(autos, TAM, CANTA, &proximoId);
    harcodearTrabajos(trabajos, TAMTR, CANTTR, &proximoIdTrabajo);


    eMarca marcas[TAMM] =
    {
        {1000, "Chevrolet"},
        {1001, "Fiat"},
        {1002, "Ford"},
        {1003, "Peugeot"},
        {1004, "Renault"}


    };


    //harcodeo un array de colores
    eColor colores[TAMC] =
    {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Rojo"},
        {5003, "Verde"},
        {5004, "Azul"}
    };




    eServicio servicios[TAMS] =
    {
        {20000, "Lavado", 450},
        {20001, "Pulido", 500},
        {20002, "Encerado", 600},
        {20003, "Completo", 900}


    };


    do
    {
        switch(menuAuto())
        {
        case 1:
            if(altaAuto(autos, TAM, marcas, TAMM, colores, TAMC, &proximoId))
            {
                printf("Datos cargados con exito!!!\n");

            }

            else
            {
                printf("No se pudo cargar los datos\n");

            }

            break;
        case 2:

            modificarAuto(autos, TAM, marcas, TAMM, colores, TAMC);
            break;
        case 3:
            bajaAuto(autos, TAM, marcas, TAMM, colores, TAMC);
            break;
        case 4:
            system("cls");
            ordenarAutoMarcaCaja(autos, TAM);
            listarAutos(autos, TAM, marcas, TAMM, colores, TAMC);
            break;
        case 5:
            system("cls");
            listarMarcas(marcas, TAMM);
            break;
        case 6:
            system("cls");
            listarColores(colores, TAMC);
            break;
        case 7:
            system("cls");
            listarServicios(servicios, TAMS);
            break;
        case 8:


            if(altaTrabajo(trabajos, TAMTR, autos, TAM, servicios, TAMS, marcas, TAMS, colores, TAMC, &proximoIdTrabajo))
            {
                printf("Trabajo cargado con exito!!\n");
            }
            else
            {
                printf("No se pudo cargar trabajo\n");
            }

            break;


        case 9:
            system("cls");
            listarTrabajos(trabajos, TAMTR,servicios, TAMS);
            break;

        case 30:
            confirmarSalida (&salir);
            while(salir != 'S' && salir != 'N')
            {
                printf("Error!!");
                confirmarSalida (&salir);
            }
            break;

        default:
            validarOpcion(opcion);
            break;

        }

        system("pause");//importante para mostrar los informes sino no pausa el sistema.


    }
    while(salir != 'S');



    return 0;

}









