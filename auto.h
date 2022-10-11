#include <stdio.h>
#include <stdlib.h>

#include "marca.h"
#include "color.h"



#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

typedef struct{

int id;
int idMarca;
int idColor;
char caja;
int isEmpty;



}eAuto;



#endif // AUTO_H_INCLUDED




int menuAuto();
int inicializarAutos(eAuto vec[], int tam);
int harcodearAutos(eAuto vec[], int tam, int cantA, int* pNextId);
int buscarLibreAuto (eAuto vec[], int tam, int* pIndex);
int altaAuto(eAuto vec[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC, int* pNextId);



int modificarAuto(eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC);
int listarAutos(eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC);
void mostrarAutoFila(eAuto autos, int tam, eMarca marcas[], int tamM, eColor colores[], int tamC);
int buscarAuto(eAuto autos[], int tam, int id, int* pIndex);
int validarAuto (eAuto autos[], int tam, int id);
void mostrarAuto(eAuto autos, int tam, eMarca marcas[], int tamM, eColor colores[], int tamC);
int menuModificarAuto();

int bajaAuto (eAuto autos[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC);


int ordenarAutoMarcaCaja(eAuto vec[], int tam);



//void listarCaja();
int confirmarCarga (char* x);
void confirmarSalida (char* x);
