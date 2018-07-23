#ifndef INGRESOS_H_INCLUDED
#define INGRESOS_H_INCLUDED

#define MAX_INGRESOS 20
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTROS 4

typedef struct {
    int id;
    char patente[20];
    int marca;
    int propietario;
    int estado;
} tIngreso;

void initIngresos(tIngreso[], int, int);
void cargarIngresos(tIngreso[]);

#endif // INGRESOS_H_INCLUDED
