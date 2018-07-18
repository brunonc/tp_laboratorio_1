#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define C_PERSONAS 20
#define MAX_NOMBRE 50
#define EDAD_MIN 0
#define MAX_EDAD 125

typedef struct {

    char nombre[MAX_NOMBRE];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * @brief Funcion que imprime un error a partir de las validaciones,
 * mediante un codigo.

 * @param codigo El codigo del error.
 */
void imprimirError(int);

/**
 * @brief Obtiene el primer indice libre la lista pasada como parametro.
 *
 * @param lista La lista con la cual operar.
 * @return Un entero que representa al indice del elemento libre o -1 en caso de que no exista tal.
 */
int obtenerEspacioLibre(EPersona[]);

/**
 * @brief Obtiene el indice que coincide con el dni pasado por parametro.
 *
 * @param lista La lista con la cual operar.
 * @param dni El dni a ser buscado en la lista.
 * @return Un entero que representa el indice con el que coincide el dni pasado como parametro o -1 en caso de
 * no haber coincidencia.
 */
int buscarPorDni(EPersona[], int);

/**
 * @brief Busca dentro la lista de personas si hay alguna persona cargada.
 *
 * @param lista La lista de EPersona con la cual operar.
 * @return devuelve 0 si no hay personas cargadas o 1 si hay personas cargadas.
 */
char existenPersonasCargadas(EPersona[]);

/**
 * @brief Lee y valida una cadena pasada como parametro.
 *
 * @param dato Puntero a una cadena de char.
 * @param tipo define el tipo de dato que se lee y valida
 * (1 - cadena de caracteres, 2 - entero, 3 - punto flotante).
 * @return Puntero a una cadena de char.
 */
char* leerValidarDato(char*, char);

/**
 * @brief Le da un formato predefinido a una cadena de caracteres.

 * @param dato Puntero a una cadena de char.
 * @return Puntero a una cadena de char.
 */
char* formatearNombre(char*);

/**
 * @brief Inicializa en cero el estado de una lista de EPersonas.
 *
 * @param lista La lista de EPersonas con la cual operar.
 */
void inicializarPersonas(EPersona[]);

/**
 * @brief Carga una persona dentro de la lista pasada como parametro.
 *
 * @param lista La lista de EPersona con la cual operar.
 */
void agregarPersona(EPersona[]);

/**
 * @brief Borra una persona de la lista de EPersonas pasada como parametro.
 *
 * @param lista La lista de EPersona con la cual operar.
 */
void borrarPersona(EPersona[]);

/**
 * @brief Imprime por pantalla la lista pasada como parametro por nombre ordenada alfabeticamente en forma ascendente.
 *
 * @param lista La lista de EPersona con la cual operar.
 */
void imprimirListaOrdenada(EPersona[]);

/**
 * @brief Imprime por pantalla un grafico de la lista de EPersona ordenado por edad.
 *
 * @param lista La lista de EPersona con la cual operar.
 */
void imprimirGrafico(EPersona[]);

#endif // FUNCIONES_H_INCLUDED
