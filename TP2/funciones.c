#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funciones.h"

void imprimirError(int codigo) {
     switch(codigo) {
        case 1:
            printf("El nombre ingresado es incorrecto!!!!\n");
            break;
        case 2:
            printf("La edad ingresada es incorrecta!!!!\n");
            break;
        case 3:
            printf("El DNI ingresado es incorrecto!!!!\n");
            break;
        case 4:
            printf("El DNI ingresado ya se encuentra cargado!!!!\n");
            break;
        case 5:
            printf("No hay mas espacio para cargar personas!!!!\n");
            break;
        case 6:
            printf("No se encontro el numero de DNI a borrar!!!!\n");
            break;
        case 7:
            printf("No hay personas cargadas!!!!\n");
            break;
        case 8:
            printf("La edad debe estar entre 0 y 125!!!!\n");
            break;
        case 9:
            printf("La opcion ingresada es incorrecta!!!!\n");
            break;
     }
     system("pause");
}

int obtenerEspacioLibre(EPersona lista[]) {
    int res = -1;
    for(int i = 0; i < C_PERSONAS; i++) {
        if(lista[i].estado == 0) {
            res = i;
            break;
        }
    }
    return res;
}

int buscarPorDni(EPersona lista[], int dni) {
    int res = -1;
    for(int i = 0; i < C_PERSONAS; i++) {
        if(lista[i].estado != 0 && lista[i].dni == dni) {
            res = i;
            break;
        }
    }
    return res;
}

char existenPersonasCargadas(EPersona lista[]) {
    char res = 0;
    for(int i = 0; i < C_PERSONAS; i++){
        if(lista[i].estado != 0){
            res = 1;
            break;
        }
    }
    return res;
}

char* leerValidarDato(char* dato, char tipo) {
    fflush(stdin);
    char* aux;
    if((aux = fgets(dato, MAX_NOMBRE, stdin))) {
        do {
            switch(tipo) {
                case 1:
                    if (!((*aux >= 'A' && *aux <= 'Z') || (*aux >= 'a' && *aux <= 'z') || *aux == ' ' || *aux == '\n')) {
                        dato = NULL;
                    }
                    break;
                case 2:
                    if (!((*aux >= '0' && *aux <= '9') || *aux == '\n')) {
                        dato = NULL;
                    }
                    break;
                case 3:
                    if (!((*aux >= '0' && *aux <= '9') || *aux != '.' || *aux == '\n')) {
                        dato = NULL;
                    }
                    break;
            }
            if(!dato) {
                break;
            }
        } while(*++aux != '\0');
    } else {
        dato = NULL;
    }

    return dato;
}

char *formatearNombre(char* dato) {
    char* aux = malloc(sizeof(char) * MAX_NOMBRE);
    aux = dato;
    *aux = toupper(*aux);
    while(*(++aux) != '\n') {
        if(*aux == ' ') {
            aux++;
            *aux = toupper(*aux);
        } else {
            *aux = tolower(*aux);
        }
    }

    return dato;
}

void inicializarPersonas(EPersona lista[]) {
    for(int i = 0; i < C_PERSONAS; i++) {
        lista[i].estado = 0;
    }
}

void agregarPersona(EPersona lista[]){
    char* nombre = NULL;
    char* edad = NULL;
    char* dni = NULL;
    int indice = obtenerEspacioLibre(lista);

    if(indice!=-1) {
        while(nombre == NULL || edad == NULL || dni == NULL) {
            system("cls");
            fflush(stdin);
            printf("Cargar persona:\n");
            if(nombre) {
                printf("Nombre: %s\n", nombre);
            } else {
                nombre = malloc(sizeof(char) * MAX_NOMBRE);
                printf("Ingrese nombre: ");
                if(leerValidarDato(nombre, 1)) {
                    strcpy(lista[indice].nombre, formatearNombre(nombre));
                } else {
                    free(nombre);
                    nombre = NULL;
                    imprimirError(1);
                }
            }
            if(edad){
                printf("Edad: %s\n", edad);
            } else {
                edad = malloc(sizeof(char) * MAX_NOMBRE);
                printf("Ingrese edad: ");
                if(leerValidarDato(edad, 2)) {
                    int auxEdad = atoi(edad);
                    if(auxEdad >= EDAD_MIN && auxEdad <= MAX_EDAD) {
                        lista[indice].edad = auxEdad;
                    } else {
                        free(edad);
                        edad = NULL;
                        imprimirError(8);
                    }
                } else {
                    free(edad);
                    edad = NULL;
                    imprimirError(2);
                }
            }
            if(dni) {
                printf("DNI: %s\n", dni);
            } else {
                dni = malloc(sizeof(char) * MAX_NOMBRE);
                printf("Ingrese dni: ");
                if(leerValidarDato(dni, 2)) {
                    int parDni = atoi(dni);
                    if(buscarPorDni(lista, parDni) == -1) {
                        lista[indice].dni = parDni;
                    } else {
                        free(dni);
                        dni = NULL;
                        imprimirError(4);
                    }
                } else {
                    free(dni);
                    dni = NULL;
                    imprimirError(3);
                }
            }
        }
        lista[indice].estado = 1;
        free(nombre);
        free(edad);
        free(dni);
    } else {
        imprimirError(5);
    }
}

void borrarPersona(EPersona lista[]) {
    char *dni = NULL;
    int indice;
    while(!dni) {
        system("cls");
        if(!dni) {
            dni = malloc(sizeof(char) * MAX_NOMBRE);
            printf("Ingrese dni a borrar: ");
            if(!leerValidarDato(dni, 2)) {
                free(dni);
                dni = NULL;
            }
        }
    }
    if((indice = buscarPorDni(lista, atoi(dni)))!= -1) {
        lista[indice].estado = 0;
        printf("Se borro el dni ingresado!!!\n");
        system("pause");
    } else {
        imprimirError(6);
    }
}

void imprimirListaOrdenada(EPersona lista[]){
    system("cls");
    for(int i = 0; i < C_PERSONAS; i++) {
        for(int j = i + 1; j < C_PERSONAS; j++) {
            if(lista[i].estado && lista[j].estado) {
                if(strcmp(lista[j].nombre, lista[i].nombre) < 0) {
                    char auxNombre[MAX_NOMBRE];
                    strcpy(auxNombre, lista[i].nombre);
                    strcpy(lista[i].nombre, lista[j].nombre);
                    strcpy(lista[j].nombre, auxNombre);

                    int auxEdad;
                    auxEdad = lista[i].edad;
                    lista[i].edad = lista[j].edad;
                    lista[j].edad = auxEdad;

                    int auxDni;
                    auxDni = lista[i].dni;
                    lista[i].dni = lista[j].dni;
                    lista[j].dni = auxDni;
                }
            }
        }
    }
    for(int i = 0; i < C_PERSONAS; i++) {
        if(lista[i].estado) {
            printf("Nombre: %s\n", lista[i].nombre);
            printf("Edad  : %d\n", lista[i].edad);
            printf("DNI   : %d\n", lista[i].dni);
            printf("-----------------------------------\n");
        }
    }
    system("pause");
}

void imprimirGrafico(EPersona lista[]) {
    int menor = 0;
    int entre = 0;
    int mayor = 0;

    for(int i = 0; i < C_PERSONAS; i++) {
        if(lista[i].estado != 0){
            if(lista[i].edad <= 18) {
                menor++;
            } else if(lista[i].edad > 18 && lista[i].edad < 35) {
                entre++;
            } else {
                mayor++;
            }
        }
    }

    system("cls");
    printf(" Grafico edades: \n");
    printf("-----------------\n");
    for(int i = C_PERSONAS; i >= 0; i--) {
        if((menor - i) > 0) {
            printf(" *  |");
        } else {
            printf("    |");
        }
        if((entre - i) > 0) {
            printf("   *   |");
        } else {
            printf("       |");
        }
        if((mayor - i) > 0) {
            printf("  *");
        }
        printf("\n");
    }
    printf("-----------------\n");
    printf("<18 | 19-35 | >35\n");
    system("pause");
}
