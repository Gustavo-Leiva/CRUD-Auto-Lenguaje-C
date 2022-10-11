#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED
typedef struct
{

    int id;
    char descripcion [25];
    float precio;

} eServicio;



#endif // SERVICIOS_H_INCLUDED
int cargarDescripcionServicio(eServicio servicios[], int tamS, int id, char desc[]);
int listarServicios (eServicio servicios[], int tamS);
int buscarServicio(eServicio servicios[], int tamS, int id, int* pIndex);
int validarServicio(eServicio servicios[], int tamS, int id);
