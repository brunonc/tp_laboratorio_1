#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"

int main() {
    char seguir = 's';
    int opcion = 0;
    EPersona personas[C_PERSONAS];

    inicializarPersonas(personas);

    while(seguir == 's') {
        system("cls");
        fflush(stdin);
        opcion = 0;

        if(existenPersonasCargadas(personas)) {
            printf("1- Agregar persona\n");
            printf("2- Borrar persona\n");
            printf("3- Imprimir lista ordenada por nombre\n");
            printf("4- Imprimir grafico de edades\n\n");
            printf("5- Salir\n");

            scanf("%d", &opcion);

            switch(opcion) {
                case 1:
                    agregarPersona(personas);
                    break;
                case 2:
                    borrarPersona(personas);
                    break;
                case 3:
                    imprimirListaOrdenada(personas);
                    break;
                case 4:
                    imprimirGrafico(personas);
                    break;
                case 5:
                    seguir = 'n';
                    break;
                default:
                    imprimirError(9);
                    break;
            }
        } else {
            printf("1- Agregar persona\n");
            printf("5- Salir\n");

            scanf("%d", &opcion);

            switch(opcion){
                case 1:
                    agregarPersona(personas);
                    break;
                case 5:
                    seguir = 'n';
                    break;
                default:
                    imprimirError(9);
                    break;
            }
        }
    }
    return 0;
}
