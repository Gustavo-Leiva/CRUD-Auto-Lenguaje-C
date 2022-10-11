#include <stdio.h>
#include <stdlib.h>


#include <string.h>
#include <ctype.h>

int validarCaracter(char valor, char a, char b)
{
    int todoOk = 0;

    if(valor == a || valor == b)
    {

        todoOk = 1;

    }
    return todoOk;


}

int validarOpcion(char opcion[])
{
    int i;
    for(i=0; i<strlen(opcion); i++)
    {
        if(!(isdigit(opcion[i])))
        {
            printf("Opcion Incorrecta!!! \nIngrese solo una de las opciones indicadas, por favor.\n\n");

            return 1;
        }
    }
    return 0;
}


