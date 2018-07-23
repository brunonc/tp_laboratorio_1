#ifndef EGRESOS_H_INCLUDED
#define EGRESOS_H_INCLUDED

#define MAX_EGRESOS 1000

typedef struct {
    int marca;
    float importe;
} tEgreso;

void initEgresos(tEgreso[], int, int);
void cargarEgresos(tEgreso[]);
int cargarEgreso(tEgreso[], int, float);

#endif // EGRESOS_H_INCLUDED
