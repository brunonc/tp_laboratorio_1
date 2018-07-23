#include "ingresos.h"
#include "propietarios.h"

void initIngresos(tIngreso ingresos[], int cant, int valor) {
    int i;
    for(i = 0; i < cant; i++) {
        ingresos[i].id = valor;
    }
}

void cargarIngresos(tIngreso ingresos[]) {
    int id[]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char patente[][20]= {"AAA", "CCC", "DDD", "BBB", "ZZZ", "III", "HHH", "EEE", "FFF", "GGG"};
    int marca[]= {1, 3, 3, 2, 2, 3, 3, 4, 3, 1};
    int propietario[]= {2, 1, 2, 1, 3, 3, 4, 1, 4, 3};
    for (int i = 0; i < 10 ; i++) {
        ingresos[i].id = id[i];
        strcpy(ingresos[i].patente, patente[i]);
        ingresos[i].marca = marca[i];
        ingresos[i].propietario = propietario[i];
    }
}

void bajarIngresosxProp(tIngreso ingresos[], int propietario) {
    for(int i = 0; i < MAX_INGRESOS; i++) {
        if(ingresos[i].propietario == propietario) {
            ingresos[i].id == 0;
        }
    }
}

void bajarIngresosxId(tIngreso ingresos[], int id) {
    int indice = buscarValorIngresos(ingresos, id);
    if(indice != -1) {
        ingresos[indice].id = 0;
    }

}

void altaIngreso(tIngreso ingresos[], tPropietario propietarios[]) {
    tIngreso ingresoAux;
    int indice = buscarValorIngresos(ingresos, 0);
    if(indice == -1)
    {
        printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
        getChar("\n\nENTER (para continuar)");
    } else {
        getValidString("Ingrese la patente del vehiculo: ", "La patente debe estar compuesta solo por letras\n", ingresoAux.patente);
        ingresoAux.marca = getValidInt("Ingrese el id de marca del vehiculo: ", "El id debe ser numerico", 1, 4);
        ingresoAux.propietario = getValidInt("Ingrese el id del propietario: ","El id del propietario debe ser numerico\n", 1, 50);
        while(buscarValorPropietarios(propietarios, MAX, ingresoAux.propietario) == -1) {
            printf("\n\nEL ID NO EXISTE!!!\n");
            ingresoAux.propietario = getValidInt("Ingrese el id del propietario: ","El id del propietario debe ser numerico\n", 1, 50);
        }
        setIngreso(ingresos, ingresoAux, indice);
    }
    return;

}

int buscarValorIngresos(tIngreso ingresos[], int valor) {
    int res = -1;
    for (int i = 0; i < MAX_INGRESOS; i++) {
        if (ingresos[i].id == valor) {
            res = i;
            break;
        }
    }
    return res;
}

int setIngreso(tIngreso ingresos[], tIngreso ingresoAux, int indice) {
    ingresos[indice].id = indice + 1;
    strcpy(ingresos[indice].patente, ingresoAux.patente);
    ingresos[indice].marca = ingresoAux.marca;
    ingresos[indice].propietario = ingresoAux.propietario;
}

void mostrarMarca(int id) {
    switch(id) {
        case ALPHA_ROMEO:
            printf("Alpha Romeo");
            break;
        case FERRARI:
            printf("Ferrari");
            break;
        case AUDI:
            printf("Audi");
            break;
        case OTROS:
            printf("Otros");
            break;
        default:
            printf("Id de marca desconocido");
            break;
    }
}
