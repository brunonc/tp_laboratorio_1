#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "recursos.h"

int main() {
    char seguir='s';
    int opcion=0;
    long int op1 = -1;
    long int op2 = -1;

    while(seguir=='s') {
        system("cls");
        fflush(stdin);

        if(op1 == -1) {
            printf("1- Ingresar 1er operando (A=x)\n");
        } else {
            printf("1- Ingresar 1er operando (A=%d)\n", op1);
        }

        if(op2 == -1) {
            printf("2- Ingresar 2do operando (B=y)\n");
        } else {
            printf("2- Ingresar 2do operando (B=%d)\n", op2);
        }

        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion) {
            case 1:
                op1 = getEntero();
                break;
            case 2:
                op2 = getEntero();
                break;
            case 3:
                if(op1 != -1 && op2 != -1) {
                    printSum(op1, op2);
                    getch();
                } else {
                    printf("Debe ingresar ambos operandos para realizar la operacion!");
                    getch();
                }
                break;
            case 4:
                if(op1 != -1 && op2 != -1) {
                    printSubtraction(op1, op2);
                    getch();
                } else {
                    printf("Debe ingresar ambos operandos para realizar la operacion!");
                    getch();
                }
                break;
            case 5:
                if(op1 != -1 && op2 != -1) {
                    if(op2 == 0) {
                        printf("El divisor (2do operando) no puede ser cero!");
                    } else {
                        printDivision(op1, op2);
                        getch();
                    }
                } else {
                    printf("Debe ingresar ambos operandos para realizar la operacion!");
                    getch();
                }
                break;
            case 6:
                if(op1 != -1 && op2 != -1) {
                    printMultiplication(op1, op2);
                    getch();
                } else {
                    printf("Debe ingresar ambos operandos para realizar la operacion!");
                    getch();
                }
                break;
            case 7:
                if(op1 != -1) {
                    if(op1 < 0) {
                        printf("El operando debe ser mayor a cero!");
                        getch();
                    } else {
                        printFactorial(op1);
                        getch();
                    }
                } else {
                    printf("Debe ingresar el 1er operando para realizar la operacion!");
                    getch();
                }
                break;
            case 8:
                if(op1 != -1 && op2 != -1) {
                    printSum(op1, op2);
                    printSubtraction(op1, op2);
                    if(op2 != 0) {
                        printDivision(op1, op2);
                    } else {
                        printf("No se puede calcular la division!\n");
                    }
                    printMultiplication(op1, op2);
                    printFactorial(op1);
                    getch();
                }
                break;
            case 9:
                seguir = 'n';
                break;
        }


    }
    return 0;
}
