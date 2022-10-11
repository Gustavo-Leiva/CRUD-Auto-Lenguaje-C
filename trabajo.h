#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

#include "fecha.h"
#include "auto.h"
#include "marca.h"
#include "servicios.h"

typedef struct{

int id;
int idAuto;
int idServicio;
eFecha fecha;
int isEmpty;


}eTrabajo;

#endif // TRABAJO_H_INCLUDED
int inicializarTrabajos(eTrabajo vec[], int tamTR);
int altaTrabajo(eTrabajo vec[], int tamTR, eAuto autos[], int tam, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC,  int* pNextId);
int buscarLibreTrabajo(eTrabajo vec[], int tamTR, int* pIndex);
int listarTrabajos(eTrabajo trabajos[],  int tamTR, eServicio servicios[], int tamS);
void mostrarTrabajoFila (eTrabajo trabajos, eServicio servicios[], int tamS);
int harcodearTrabajos(eTrabajo vec[], int tamTR, int cantTR, int* pNextId);
