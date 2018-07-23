#include <stdio.h>
#include <stdlib.h>

#include "propietarios.h"
#include "ingresos.h"
#include "egresos.h"

int main()
{
    tPropietario propietarios[MAX];
    tIngreso ingresos[MAX_INGRESOS];
    tEgreso egresos[MAX_EGRESOS];

    initPropietarios(propietarios, MAX, 0);
    initIngresos(ingresos, MAX_INGRESOS, 0);
    initEgresos(egresos, MAX_EGRESOS, 0);

    cargarPropietarios(propietarios);
    cargarIngresos(ingresos);
    cargarEgresos(egresos);

    int option = 0;
    int opcionReportes;

    while(option != 5) {
        printf("\n------------  MENU PRINCIPAL ------------");
        option = getInt("\n1 - ABM Propietarios \n2 - Ingreso de automovil \n3 - Egreso de automovil\n4 - Reportes\n5 - SALIR\n\n\n");
        switch(option) {
            case 1: // ABM Propietarios
                abmPropietarios(propietarios, ingresos, egresos);
                break;
            case 2: // Ingreso de automovil
                altaIngreso(ingresos, propietarios);
                break;
            case 3: // Egreso de automovil
                altaEgreso(egresos, propietarios, ingresos);
                break;
            case 4: // Reportes
                opcionReportes = 0;
                while(option != 6) {
                    printf("\n------------  Reportes ------------");
                    option = getInt("\n1 - Recaudacion total \n2 - Recaudacion por marca \n3 - Propietarios\n4 - Propietarios Audi\n5 - Propietarios ordenado\n6 - SALIR\n\n\n");
                    switch(option) {
                        case 1: // Total
                            recaudaTotal(egresos);
                            break;
                        case 2: // Por marca
                            break;
                        case 3: // Propietarios
                            break;
                        case 4: // Propietarios Audi
                            break;
                        case 5: // Propietarios ordenados
                            break;
                        case 6:
                            break;
                    }
                }
                break;
            case 5:
                break;
        }
    }

    return 0;
}
