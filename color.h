#include <stdio.h>
#include <stdlib.h>


#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED


typedef struct {

int id;
char nombreColor[20];



}eColor;

#endif // COLOR_H_INCLUDED
int cargarDescripcionColores(eColor colores[], int tamC, int id, char desc[]);
int listarColores(eColor colores[], int tamC);
int buscarColores(eColor colores[], int tamC, int id, int* pIndex);
int validarColores(eColor colores[], int tamC, int id);
