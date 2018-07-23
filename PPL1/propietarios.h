#ifndef PROPIETARIOS_H_INCLUDED
#define PROPIETARIOS_H_INCLUDED

#include "ingresos.h"
#include "egresos.h"

#define MAX 50

typedef struct {
    int id;
    char nombre[50];
    char direccion[50];
    int tarjeta[8];
    int estado;
} tPropietario;

void initPropietarios(tPropietario[], int, int);
void cargarPropietarios(tPropietario[]);
void abmPropietarios(tPropietario[], tIngreso[], tEgreso[]);
int buscarValorPropietarios(tPropietario[], int, int);
int setPropietario(tPropietario[], tPropietario, int);

#endif // PROPIETARIOS_H_INCLUDED
