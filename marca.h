#include <stdio.h>
#include <stdlib.h>

#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED


typedef struct {

int id;
char descripcion [20];



}eMarca;


#endif // MARCA_H_INCLUDED

int cargarDescripcionMarcas(eMarca marcas[], int tamM, int id, char desc[]);
int listarMarcas(eMarca marcas[], int tamM);
int buscarMarca(eMarca marcas[], int tamM, int id, int* pIndex);
int validarMarca(eMarca marcas[], int tamM, int id);
