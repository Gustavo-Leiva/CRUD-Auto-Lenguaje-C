#include <stdio.h>
#include <stdlib.h>

#include "auto.h"
#include "marca.h"
#include "color.h"


#include "validaciones.h"

#include <string.h>

#include <ctype.h>
#include <string.h>

int menuAuto()
{
    int opcion;

    system("cls");
    printf("********** ABM Auto*******\n\n");
    printf("1. Alta Auto\n");
    printf("2. Modificar Auto\n");
    printf("3. Baja Auto\n");
    printf("4. Listar Autos\n");
    printf("5. Listar Marcas\n");
    printf("6. Listar Colores\n");
    printf("7. Listar Servicios\n");
    printf("8. Alta de Trabajo\n");
    printf("9. Listar Trabajos\n");
    printf("30. Salir\n");

    printf("ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);


    return opcion;

}


int inicializarAutos(eAuto vec[], int tam)
{
    int todoOk = 0;

    if(vec!= NULL && tam > 0)
    {

        for( int i = 0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }

        todoOk = 1;
    }


    return todoOk;
}



int harcodearAutos(eAuto vec[], int tam, int cantA, int* pNextId)
{
    int todoOk = 0;

    eAuto autos [15]=
    {
        {0, 1000, 5000,'m',0},
        {0, 1002, 5003,'a',0},
        {0, 1001, 5004,'a',0},
        {0, 1004, 5002,'a',0},
        {0, 1003, 5001,'m',0},
        {0, 1001, 5000,'m',0},
        {0, 1002, 5003,'a',0},
        {0, 1003, 5002,'m',0},
        {0, 1002, 5001,'a',0},
        {0, 1001, 5004,'a',0},
        {0, 1004, 5003,'a',0},
        {0, 1002, 5002,'a',0},
        {0, 1000, 5000,'m',0},
        {0, 1003, 5001,'a',0},
        {0, 1004, 5004,'m',0}

    };

    if(vec != NULL && pNextId != NULL && tam> 0 && tam <=15 && cantA <= tam)
    {
        for (int i = 0; i<cantA; i++)
        {
            vec[i]= autos[i];
            vec[i].id = *pNextId;
            (*pNextId)++;

        }

        todoOk = 1;
    }

    return todoOk;
}


int buscarLibreAuto(eAuto vec[], int tam, int* pIndex)
{
    int todoOk;

    if(vec != NULL && pIndex != NULL && tam > 0)
    {
        for(int i = 0; i < tam ; i++)
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



int altaAuto(eAuto vec[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, int* pNextId)
{

    int todoOk = 0;
    int indice;
    int idMarca;
    int idColor;
    char auxCaja;
    eAuto nuevoAuto;


    if(vec != NULL  && marcas != NULL && colores != NULL  && tam > 0 && tamM > 0 && tamC > 0 && pNextId != NULL)

    {
        system("cls");
        printf("********Alta Auto********\n");
        printf("-------------------------\n");
        buscarLibreAuto(vec, tam, &indice); //esta funcion devuelve -1 sino hay lugar o el numero de indice proximo vacio.


        if (indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }

        else
        {
            nuevoAuto.id = *pNextId;




           // pidoValidoLetras(nuevoAuto.marca, tam, "marca");
           // fflush(stdin);



            //listar marcas
            listarMarcas(marcas, tamM);
            printf("Ingrese  Id Marca: ");
            fflush(stdin);
            scanf("%d", &idMarca);
            while(validarMarca(marcas,tamM, idMarca)==0)
            {
                printf("Reingrese  Id Marca: ");
                fflush(stdin);
                scanf("%d", &idMarca);
            }

            nuevoAuto.idMarca = idMarca;

            //listar colores.
            listarColores(colores, tamC);
            printf("Ingrese  Id color: ");
            fflush(stdin);
            scanf("%d", &idColor);
            while(validarColores(colores,tamC, idColor)==0)
            {
                printf("Reingrese  Id color: ");
                fflush(stdin);
                scanf("%d", &idColor);
            }

            nuevoAuto.idColor = idColor;


            //listarCaja();
            printf("ingrese caja(Automatica[a], Manual[m]: ");
            fflush(stdin);
            scanf("%c", &auxCaja);
            auxCaja = tolower(auxCaja);

            while(!validarCaracter(auxCaja,'a', 'm'))
            {
                printf("Dato Invalido. Reingrese Tipo de Caja(a/m): ");
                fflush(stdin);
                scanf("%c", &auxCaja);
                auxCaja = tolower(auxCaja);

            }

            nuevoAuto.caja= auxCaja;


            nuevoAuto.isEmpty = 0;
            //lo igual a cero porque digo que esa posicion no va a estar libre
            //recordar que isEmpty es 1 si esta libre. y 0 sin no lo esta


            vec[indice] = nuevoAuto;
            //aca lo inyecto en la lista de motos

            (*pNextId)++;
            //aca una vez inyectado tengo que actualizar a traves de *pNextId lo incremento en 1



            todoOk = 1;

        }




    }

    return todoOk;
}





int modificarAuto(eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
    int todoOk = 0;
    int indice;
    int id;
    int idColor;
    char auxModelo;
    char confirma;



    if(autos != NULL && tam > 0 && marcas != NULL && colores != NULL && tamC >0)
    {
        listarAutos(autos, tam, marcas, tamM, colores, tamC); //tiene listar y lista fila.
        printf("Ingrese Id:");
        scanf("%d", &id);

        system("cls");
        printf("*********Datos del Auto Modificar*******\n");

        if(buscarAuto(autos, tam, id, &indice)==1)
        {
            if(indice == -1)
            {
                printf("no existe un auto con Id %d en el sistema\n", id);
            }

            else
            {
                mostrarAuto(autos[indice], tam, marcas, tamM, colores, tamC);

                switch(menuModificarAuto())
                {
                case 1:

                    listarColores(colores, tamC);
                    printf("Ingrese el id del Color: \n");
                    fflush(stdin);
                    scanf("%d", &idColor);
                    while(validarColores(colores, tamC, idColor)==0)
                    {
                        printf("Error!! Reingrese el id del Color: \n");
                        fflush(stdin);
                        scanf("%d", &idColor);

                    }


                    autos[indice].idColor = idColor;
                    if(confirmarCarga(&confirma))
                    {

                       autos[indice].idColor = idColor;
                    }
                    break;



                case 2:
                    printf("ingrese modelo (Automatico[a]/ Manual[m]: ");
                    fflush(stdin);
                    scanf("%c", &auxModelo);
                    auxModelo = tolower(auxModelo);

                    while(!validarCaracter(auxModelo,'a', 'm'))
                    {
                        printf("Modelo Invalido. Reingrese modelo(a/m): ");
                        fflush(stdin);
                        scanf("%c", &auxModelo);
                        auxModelo = tolower(auxModelo);

                    }


                    if(confirmarCarga(&confirma))
                    {

                        autos[indice].caja = auxModelo;
                    }
                    //strcpy(autos->caja, auxModelo);


                }

            }

            todoOk = 1;

        }

    }

    return todoOk;
}





int listarAutos(eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
    int todoOk = 0;
    int flag = 1;
    if(autos != NULL  && marcas!= NULL  && colores != NULL && tam > 0 && tamM > 0 && tamC > 0)
    {
        //system("cls");
        printf("****** Listado  De Autos ****************\n");
        printf("   ID       MARCA        COLOR      CAJA  \n");
        printf("------------------------------------------ \n");

        for(int i = 0; i< tam; i++)
        {
            if(!autos[i].isEmpty)//es un filtro que dice que no se muestra cuando el campo isEmpty no esta vacio. es lo mismo que decir vec[i].isEmpty ==0
            {
                mostrarAutoFila(autos[i], tam, marcas, tamM, colores, tamC);
                flag = 0;

            }


        }

        if(flag)
        {

            printf("     no hay autos en el sistema\n");
        }
    }


    return todoOk;
}


void mostrarAutoFila(eAuto autos, int tam, eMarca marcas[], int tamM, eColor colores[], int tamC)
{

    char descripcionMarca [20];
    char descripcionColor [20];

    cargarDescripcionMarcas(marcas, tamM, autos.idMarca, descripcionMarca);
    cargarDescripcionColores(colores, tamC, autos.idColor, descripcionColor);


    printf("%4d     %10s     %10s    %c\n",
           autos.id,
           descripcionMarca,
           descripcionColor,
           autos.caja
          );

}




int buscarAuto(eAuto autos[], int tam, int id, int* pIndex)
{
    int todoOk = 0;

    if(autos != NULL && tam > 0  && pIndex != NULL)
    {

        *pIndex = -1;
        for(int i = 0; i < tam; i++)
        {

            //aca busco que la estructura no este vacia y que el id que busco coincida con ese lugar.
            if(!autos[i].isEmpty && autos[i].id == id)
            {
                *pIndex = i;
                break;

            }

        }

        todoOk = 1;
    }


    return todoOk;
}




int validarAuto (eAuto autos[], int tam, int id)
{
    int esValido = 0;
    int indice;

    if(buscarAuto(autos, tam, id, &indice))
    {
        if(indice!=-1)
        {
            esValido=1;
        }
    }

    return esValido;
}



void mostrarAuto(eAuto autos, int tam, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
    char descripcionMarca [20];
    char descripcionColor[20];

    cargarDescripcionMarcas(marcas, tamM, autos.idMarca, descripcionMarca);
    cargarDescripcionColores(colores, tamC, autos.idColor, descripcionColor);


    printf("Id: %d\n", autos.id);
    printf("Marca: %s\n", descripcionMarca);
    printf("Color: %s\n", descripcionColor);
    printf("Modelo: %c\n", autos.caja);


}




int menuModificarAuto()
{
    int opcion;
    printf("******************************\n\n");
    printf("   *** Campo a modificar ***  \n");
    printf("-----------------------------*\n\n");
    printf("1. Color\n");
    printf("2. Modelo\n");
    printf("3. Salir:\n");
    printf("Ingrese Opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;


}



int bajaAuto (eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;

    if(autos != NULL && tam > 0 && marcas != NULL && tamM > 0 && colores != NULL && tamC >0)
    {
        listarAutos(autos, tam, marcas, tamM, colores, tamC);

        printf("Ingrese Id:");
        scanf("%d", &id);
        if(buscarAuto(autos,tam, id, &indice)==1)
        {
            if(indice == -1)
            {
                printf("no existe esa auto con ese Id %d en el sistema\n", id);
            }

            else
            {
                mostrarAuto(autos[indice], tam, marcas,tamM, colores, tamC);
                printf("confirma baja?\n");
                fflush(stdin);
                scanf("%c", &confirma);

                if(confirma == 's' || confirma == 'S')
                {

                    autos[indice].isEmpty = 1;
                    printf("Baja exitosa\n");
                }

                else
                {
                    printf("Baja cancelada por el usuario\n");
                }

            }

            todoOk = 1;

        }



    }


    return todoOk;

}





int ordenarAutoMarcaCaja(eAuto vec[], int tam)
{
    int todoOk = 0;
    eAuto auxAuto;

    if(vec != NULL && tam > 0)
    {
        for(int i = 0; i < tam -1; i++)
        {
            for(int j = i +1; j < tam; j++)
            {
                if(((vec[i].caja == vec[j].caja) && (vec[i].idMarca > vec[j].idMarca))


                        ||((vec[i].caja!= vec[j].caja) && (vec[i].caja > vec[j].caja)))
                {

                    auxAuto = vec[i];
                    vec[i]= vec[j];
                    vec[j]= auxAuto;

                }
            }
        }

        todoOk = 1;
    }


    return todoOk;
}





/*
void listarCaja()
{
    printf("*** Listar Caja ***\n");
    printf("--------------------------\n");
    printf("          Manual\n");
    printf("          Automatica\n");


}

*/

int confirmarCarga (char* x)
{
    int todoOk = 0;

    if( x != NULL)
    {
        printf("confirma carga? (S/N): ");
        fflush(stdin);
        scanf("%c", x );
        *x=toupper(*x);

        while(!(*x =='S' || *x =='N'))
        {
            printf("Error!! Ingrese 'S' o 'N': ");
            fflush(stdin);
            scanf("%c",x);
            *x = toupper(*x);
        }

        if(*x == 's' || *x == 'S')
        {
            printf("Carga exitosa\n");
            todoOk = 1;

        }

        else
        {
            printf("Carga cancelada por usuario\n");
        }

    }

    return todoOk;
}












void confirmarSalida (char* x)
{
    printf("confirma salida? (S/N): ");
    fflush(stdin);
    scanf("%c", x );
    *x=toupper(*x);

    while(!(*x =='S' || *x =='N'))
    {
        printf("Error!! Ingrese 'S' o 'N': ");
        fflush(stdin);
        scanf("%c",x);
        *x = toupper(*x);
    }


}
