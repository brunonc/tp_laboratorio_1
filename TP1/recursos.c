#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "recursos.h"

long int getEntero() {
    long int res;

    fflush(stdin);
    printf("Ingrese un numero : ");
    scanf("%d", &res);
    while(validateRange(res)) {
        printf("Numero fuera de rango!\n");
        printf("Ingrese un numero : ");
        scanf("%d", &res);
    }
    return res;
}

int validateRange(long int num) {
    int res = 0;
    if(num < -INT_MAX || num > INT_MAX) {
        res = 1;
    }
    return res;
}

long int add(long int a, long int b) {
    return a + b;
}

void printSum(long int a, long int b) {
    long int num = add(a, b);
    if(validateRange(num)) {
        printf("El resultado esta fuera de rango!\n");
    } else {
        if(b < 0) {
            printf("La suma de %d + (%d) = %d\n", a, b, num);
        } else {
            printf("La suma de %d + %d = %d\n", a, b, num);
        }
    }
    return;
}

long int subtract(long int a, long int b) {
    return a - b;
}

void printSubtraction(long int a, long int b) {
    long int num = subtract(a, b);
    if(validateRange(num)) {
        printf("El resultado esta fuera de rango!\n");
    } else {
        if(b < 0) {
            printf("La resta de %d - (%d) = %d\n", a, b, num);
        } else {
            printf("La resta de %d - %d = %d\n", a, b, num);
        }
    }
}

float divide(long int a, long int b) {
    return (float) a / b;
}

void printDivision(long int a, long int b) {
    float num = divide(a, b);
    if(validateRange(num)) {
        printf("El resultado esta fuera de rango!\n");
    } else {
        printf("La division de %d / %d = %.5f\n", a, b, num);
    }
}

long int multiply(long int a, long int b) {
    return a * b;
}

void printMultiplication(long int a, long int b) {
    long int num = multiply(a, b);
    if(validateRange(num)) {
        printf("El resultado esta fuera de rango!\n");
    } else {
        printf("La multiplicacion de %d * %d = %d\n", a, b, num);
    }
}

long int factorial(long int a) {
    if(a == 0) {
        return 1;
    } else {
        return a * factorial(a - 1);
    }
}

void printFactorial(long int a) {
    long int num = factorial(a);
    if(a > 12) {
        printf("El resultado esta fuera de rango!");
    } else {
        printf("El factorial de %d = %d\n", a, num);
    }
}
