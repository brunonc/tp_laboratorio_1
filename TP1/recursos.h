#ifndef RESURSOS_H_INCLUDED
#define RECURSOS_H_INCLUDED

/**
* @brief Obtiene un entero de stdin y lo devuelve.
*
* @return Retorna el entero obtenido como long int.
*/
long int getEntero();

/**
* @brief Valida el rango del entero pasado como parametro.
*
* @param num El entero a validar.
* @return Devuelve 0 si es un rango valido y 1 en caso contrario.
*/
int validateRange(long int);

/**
* @brief Funcion que suma los enteros pasados como parametro.
*
* @param a El primer sumando.
* @param b El segundo sumando.
* @return Un entero que representa la suma de los sumandos pasados como parametro.
*/
long int add(long int, long int);

/**
* @brief Valida e imprime el resultado de una suma.
*
* @param a Primer sumando.
* @param b Segundo sumando.
*/
void printSum(long int, long int);

/**
* @brief Funcion que resta los enteros pasados como parametro.
*
* @param a Entero que representa al minuendo.
* @param b Entero que representa al sustraendo.
* @return Un entero que representa el resultado de la resta.
*/
long int subtract(long int, long int);

/**
* @brief Valida e imprime el resultado de una resta.
*
* @param a Minuendo.
* @param b Sustraendo.
*/
void printSubtraction(long int, long int);

/**
* @brief Funcion que divide los enteros pasados como parametro.
*
* @param a Entero que representa al dividendo.
* @param b Entero que representa al divisor.
* @return Un flotante que representa el resultado de la operacion.
*/
float divide(long int, long int);

/**
* @brief Valida e imprime el resultado de una division.
*
* @param a Dividendo.
* @param b Divisor.
*/
void printDivision(long int, long int);

/**
* @brief Funcion que multiplica los enteros pasados como parametro.
*
* @param a Entero que representa al multiplicando.
* @param b Entero que representa al multiplicador.
* @return Un entero que representa el resultado de la multiplicacion.
*/
long int multiply(long int, long int);

/**
* @brief Valida e imprime el resultado de una multiplicacion.
*
* @param a Multiplicando.
* @param b Multiplicador.
*/
void printMultiplication(long int, long int);

/**
* @brief Funcion que calcula el factorial del entero pasado como parametro.
*
* @param a El entero del cual se quiere calcular el factorial.
* @return Un entero que representa el resultado de la operacion.
*/
long int factorial(long int);

/**
* @brief Valida e imprime el resultado del calculo de un factorial.
*
* @param a El numero del cual se quiere calcular el factorial.
*/
void printFactorial(long int);

#endif // RECURSOS_H_INCLUDED
