#include <string.h>

#include "propietarios.h"
#include "ingresos.h"
#include "egresos.h"

void initPropietarios(tPropietario propietarios[], int cant, int valor) {
    int i;
    for(i = 0; i < cant; i++) {
        propietarios[i].id = valor;
    }
}

void cargarPropietarios(tPropietario propietarios[]) {
    int id[]= {1, 2, 3, 4};
    char nombre[][20]= {"Juan", "Luis", "Maria", "Jose"};
    char tarjeta[][20]= {"111-111", "222-222", "333-333", "444-444"};
    char direccion[][20]= {"mitre", "urquiza", "belgrano", "alsina"};
    for (int i = 0; i < 4; i++) {
        propietarios[i].id = id[i];
        strcpy(propietarios[i].nombre, nombre[i]);
        strcpy(propietarios[i].tarjeta, tarjeta[i]);
        strcpy(propietarios[i].direccion, direccion[i]);
    }
}

void abmPropietarios(tPropietario propietarios[], tIngreso ingresos[], tEgreso egresos[]) {
    tPropietario propAux;
    int option = 0;
    int indice, id;
    while(option != 4) {
         printf("\n------------  ABM Propietarios ------------");
         option = getInt("\n1 - ALTA \n2 - MODIFICACION \n3 - BAJA\n4 - REGRESAR\n\n\n");
         switch(option)
         {
            case 1: // ALTA DE propietario

                indice = buscarValorPropietarios(propietarios, MAX, 0);
                if(indice == -1)
                {
                    printf("\n\nNO QUEDAN LUGARES LIBRES!!!\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }

                propAux.id = getValidInt("Ingrese el id del propietario: ","El id del propietario debe ser numerico\n", 1, 50);
                if(buscarValorPropietarios(propietarios, MAX, propAux.id) != -1)
                {
                    printf("\n\nEL ID YA EXISTE!!!\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }

                getValidString("Ingrese el nombre del propietario: ", "El nombre debe estar compuesto solo por letras\n", propAux.nombre);

                getValidString("Ingrese la direccion del propietario: ", "La direccion debe estar compuesto solo por letras\n", propAux.direccion);

                getValidTarjeta("Ingrese el numero de tarjeta del propietario: ", "El numero de tarjeta es incorrecto\n", propAux.tarjeta);

                setPropietario(propietarios, propAux, indice);

                break;

            case 2: // MODIF propietario
                id = getInt("Ingrese el id del propietario a modificar: ");
                indice = buscarValorPropietarios(propietarios, MAX, id);
                if (indice == -1) {
                    printf("\n\nEL ID NO EXISTE!!!\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }
                getValidTarjeta("Ingrese el nuevo numero de tarjeta del propietario: ", "El numero de tarjeta es incorrecto\n", propietarios[indice].tarjeta);
                break;

            case 3: // BAJA propietarios
                id = getInt("Ingrese el id del propietario a dar de baja: ");
                indice = buscarValorPropietarios(propietarios, MAX, id);
                if (indice == -1) {
                    printf("\n\nEL ID NO EXISTE!!!\n");
                    getChar("\n\nENTER (para continuar)");
                    break;
                }
                bajaPropietario(propietarios, ingresos, egresos, indice);
                break;

         }
    }
}

int bajaPropietario(tPropietario propietarios[], tIngreso ingresos[], tEgreso egresos[], int indice) {
    int res = -1;
    float total = 0;
    for(int i = 0; i < MAX_INGRESOS; i++) {
        if(ingresos[i].propietario == propietarios[indice].id) {
            float costo = calcularEgreso(ingresos[i].marca);
            total += costo;
            res = cargarEgreso(egresos, ingresos[i].marca, costo);
            if(!res) {
                break;
            }
        }
    }

    if(res == -1) {
        propietarios[indice].id = 0;
        printf("Se dio de baja el usuario!\n");
    } else if(res == 1) {
        bajarIngresosxProp(ingresos, propietarios[indice].id);
        propietarios[indice].id = 0;
        printf("El propietario debera abonar $%.2f\n", total);
        printf("Se dio de baja el usuario!\n");
    } else {
        printf("El propietario no pudo ser dado de baja!");
    }


}

int buscarValorPropietarios(tPropietario propietarios[], int cant, int valor) {
    int res = -1;
    for (int i = 0; i < cant; i++) {
        if (propietarios[i].id == valor) {
            res = i;
            break;
        }
    }
    return res;
}

int setPropietario(tPropietario propietarios[], tPropietario propAux, int indice) {
    propietarios[indice].id = propAux.id;
    strcpy(propietarios[indice].nombre, propAux.nombre);
    strcpy(propietarios[indice].direccion, propAux.direccion);
    strcpy(propietarios[indice].tarjeta, propAux.tarjeta);
}
