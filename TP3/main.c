#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main() {
    EMovie movies[T_LISTA];
    inicializarMovies(movies);
    cargarLista(movies);

    int proxId = obtenerProxId(movies);
    char seguir = 's';
    int opcion = 0;

    while(seguir == 's'){
        if(contarElementos(movies)) {
            system("cls");
            fflush(stdin);

            imprimirOpcionMenu(1);
            imprimirOpcionMenu(2);
            imprimirOpcionMenu(3);
            imprimirOpcionMenu(4);
            imprimirOpcionMenu(5);

            scanf("%d", &opcion);

            switch(opcion) {
                case 1:
                    proxId = agregarPelicula(movies, proxId);
                    break;
                case 2:
                    modificarPelicula(movies);
                    break;
                case 3:
                    borrarPelicula(movies);
                    break;
                case 4:
                    generarPaginaWeb(movies);
                    break;
                case 5:
                    seguir = 'n';
                    break;
                default:
                    imprimirError(14);
                    break;
            }
        } else {
            system("cls");
            fflush(stdin);

            imprimirOpcionMenu(1);
            imprimirOpcionMenu(5);

            scanf("%d",&opcion);

            switch(opcion) {
                case 1:
                    proxId = agregarPelicula(movies, proxId);
                    break;
                case 5:
                    seguir = 'n';
                    break;
                default:
                    imprimirError(14);
                    break;
            }
        }
    }

    return 0;
}
