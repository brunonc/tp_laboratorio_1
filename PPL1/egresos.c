#include <time.h>

#include "egresos.h"
#include "ingresos.h"
#include "propietarios.h"

void initEgresos(tEgreso egresos[], int cant, int valor) {
    int i;
    for(i = 0; i < cant; i++) {
        egresos[i].marca = valor;
        egresos[i].importe = valor;
    }
}

void cargarEgresos(tEgreso egresos[]) {
    int marca[]= {1, 1, 2, 3, 2, 2, 3, 4, 1, 1};
    float importe[]= {100, 200, 100, 300, 100, 100, 200, 200, 100, 100};
    for (int i = 0; i < 10 ; i++) {
        egresos[i].marca = marca[i];
        egresos[i].importe = importe[i];
    }
}

int devolverHorasEstadia() {
    int horas;
    srand(time(NULL));
    horas = (rand()%24)+1;
    return horas ;
}

int calcularEgreso(int marca) {
    int res;
    switch(marca) {
        case ALPHA_ROMEO:
            res = 150 * devolverHorasEstadia();
            break;
        case FERRARI:
            res = 175 * devolverHorasEstadia();
            break;
        case AUDI:
            res = 200 * devolverHorasEstadia();
            break;
        case OTROS:
            res = 250 * devolverHorasEstadia();
            break;
    }
    return res;
}

int buscarValorEgresos(tEgreso egresos[], int valor) {
    int res = -1;
    for (int i = 0; i < MAX_EGRESOS; i++) {
        if (egresos[i].marca == valor) {
            res = i;
            break;
        }
    }
    return res;
}

void altaEgreso(tEgreso egresos[], tPropietario propietarios[], tIngreso ingresos[]) {
    float costo;
    int indiceProp;
    int idIngreso = getValidInt("Id del ingreso del vehiculo: ","El id debe ser numerico\n", 1, MAX_INGRESOS);
    int indiceIngreso = buscarValorIngresos(ingresos, idIngreso);
    while(indiceIngreso == -1) {
        printf("\n\nEL ID NO EXISTE!!!\n");
        idIngreso = getValidInt("Id del ingreso del vehiculo: ","El id debe ser numerico\n", 1, MAX_INGRESOS);
        indiceIngreso = buscarValorIngresos(ingresos, idIngreso);
    }
    indiceProp = buscarValorPropietarios(propietarios, MAX, ingresos[indiceIngreso].propietario);
    costo = calcularEgreso(ingresos[indiceIngreso].marca);
    printf("Nombre: %s\n", propietarios[indiceProp].nombre);
    printf("Patente: %s\n", ingresos[indiceIngreso].patente);
    printf("Marca: ");
    mostrarMarca(ingresos[indiceIngreso].marca);
    printf("\n");
    printf("Importe: %.2f\n", costo);
    cargarEgreso(egresos, ingresos[indiceIngreso].marca, costo);
    bajarIngresosxId(ingresos, idIngreso);
    return;
}

int cargarEgreso(tEgreso egresos[], int marca, float importe) {
    int res = 0;
    int indice = buscarValorEgresos(egresos, 0);
    if( indice != -1) {
        egresos[indice].marca = marca;
        egresos[indice].importe = importe;
        res = 1;
    }
    return res;
}

void recaudaTotal(tEgreso egresos[]) {
    float total;
    for(int i = 0; i < MAX_EGRESOS; i++) {
        total += egresos[i].importe;
    }
    printf("El total recaudado es: %.2f\n", total);
}
