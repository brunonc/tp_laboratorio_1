#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "movie.h"

#define T_LISTA 20


/**
 * @brief Funcion que imprime las opciones del menu mediante un codigo.
 *
 * @param codigo Un entero que representa el codigo de menu.
 */
void imprimirOpcionMenu(int);

/**
 * @brief Funcion que imprime un error mediante un codigo.
 *
 * @param codigo Un entero que representa el codigo de error a imprimir.
 */
void imprimirError(int);

/**
 * @brief Genera un archivo html a partir de una lista de EMovie.
 *
 * @param lista La lista de EMovie con la cual operar.
 * @param nombre El nombre para el archivo html.
 */
void generarPagina(EMovie[], char[]);

/** @brief Genera una pagina web.
 *
 * @param lista La lista de EMovie con la cual operar.
 */
void generarPaginaWeb(EMovie[]);

/**
 * @brief Solicita el ingreso de un nombre de archivo para la pagina web.
 *
 * @param nombre Puntero a cadena de caracteres.
 * @return El nombre del archivo.
 */

char* cargarNombreDeArchivo(char*);

/**
 * @brief Funcion que permite borrar un puntero a char.
 *
 * @param dato Es el puntero que se quiere borrar.
 * @return Devuelve un puntero a cadena de caracteres nulo.
 */
char* borrarPuntero(char*);

/**
 * @brief Lee una cadena de caracteres y la valida.
 *
 * @param dato La cadena de caracteres a validar.
 * @param tipo Un char que indica el tipo de dato que se lee
 * (1 - String, 2 - StringConEspacio, 3 - AlfaNumerico, 4 - AlfaNumericoConEspacio, 5 - NumeroEntero,
 *  6 - NumeroConComa).
 * @return Puntero a una cadena de caracteres.
 */
char* leerDato(char*, char);

/**
 * @brief Le da un formato predefinido a una cadena de caracteres.
 *
 * @param dato Es un puntero a cadena de caracteres en el cual operar.
 * @param tam Es el tamaño de la cadena.
 * @return Puntero a una cadena de caracteres.
 */
char* formatearNombreArchivo(char*, int);

/**
 * @brief Le da un formato predefinido a una cadena de caracteres.
 *
 * @param dato Es un puntero a cadena de caracteres en el cual operar.
 * @param tam Es el tamaño de la cadena.
 * @return Puntero a una cadena de caracteres.
 */
char* formatearNombrePelicula(char*,int);

/**
 * @brief Escribe nuevamente el archivo binario con los cambios que se realizaron.
 *
 * @param lista La lista de EMovie con la cual operar.
 */
void actualizarArchivo(EMovie[]);

/**
 * @brief Borra una pelicula del archivo binario.
 *
 * @param lista La lista de EMovie con la cual operar.
 */
void borrarPelicula(EMovie[]);

/**
 * @brief Modifica una pelicula del archivo binario.
 *
 * @param lista Lista de EMovie con la cual operar.
 */
void modificarPelicula(EMovie []);

/**
 * @brief Imprime por pantalla un listado de las peliculas con su id.
 *
 * @param lista La lista de EMovie con la cual operar.
 */
void imprimirPeliculasConId(EMovie[]);

/**
 * @brief Busca un id en la lista de EMovie pasada como parametro.
 *
 * @param lista La lista de EMovie en la cual buscar.
 * @param id Un entero que representa el id de la pelicula a buscar.
 * @return Un entero que representa el indice del id buscado o -1 en caso de que no exista tal.
 */
int buscarPorId(EMovie[], int);

/**
 * @brief Devuelve un puntero a archivo en modo lectura o escritura de acuerdo a la opcion pasada como parametro.
 *
 * @param opcion Modo en que se va a abrir el archivo.
 * 1-Se abre en modo lectura, 2-Se abre en modo escritura.
 * @return Devuelve el puntero al archivo.
 */
FILE* devuelveArchivo(int);

/**
 * @brief Carga en memoria el archivo de peliculas.
 *
 * @param lista La lista de EMovie en la cual se cargara el archivo.
 */
void cargarLista(EMovie[]);

/**
 * @brief Obtiene el proximo id a asignar.
 *
 * @param lista La lista de EMovie con la cual operar.
 * @return Un entero que representa el proximo id a utilizar.
 */
int obtenerProxId(EMovie[]);

#endif // FUNCIONES_H_INCLUDED
