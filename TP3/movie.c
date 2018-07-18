#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "movie.h"
#include "funciones.h"

void inicializarMovies(EMovie lista[]) {
    for(int i = 0; i < T_LISTA; i++) {
        lista[i].id = 0;
    }
}

int obtenerMovieLibre(EMovie lista[]) {
    int res = -1;
    for(int i = 0; i < T_LISTA; i++) {
        if(lista[i].id == 0) {
            res = i;
            break;
        }
    }
    return res;
}

int contarElementos(EMovie lista[]) {
    int cont = 0;
    for(int i = 0; i < T_LISTA; i++){
        if(lista[i].id != 0) {
            cont++;
        }
    }
    return cont;
}
