#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED

#define TDATO 1000

typedef struct{
    unsigned int id;
    char titulo[TDATO];
    char genero[TDATO];
    unsigned int duracion;
    char descripcion[TDATO];
    unsigned int puntaje;
    char linkImagen[TDATO];
}EMovie;


/**
 * @brief Inicializa la lista de peliculas poniendo todos los id en cero.
 *
 * @param lista Lista de EMovie en la cual operar.
 */
void inicializarMovies(EMovie[]);

/**
 * @brief Busca dentro de la lista de peliculas cual es el primer id en cero.
 *
 * @param lista La lista de EMovie en la cual operar.
 * @return Devuelve un entero que representa el indicie del primer elemento con id en cero o -1 en caso de que
 * no exista tal.
 */
int obtenerMovieLibre(EMovie[]);

/**
 * @brief Cuenta cuantas peliculas hay cargadas dentro de la lista pasada como parametro.
 *
 * @param lista La lista de EMovie en la cual operar.
 * @return Un entero que representa el numero de peliculas cargadas en la lista.
 */
int contarElementos(EMovie[]);

#endif // MOVIE_H_INCLUDED
