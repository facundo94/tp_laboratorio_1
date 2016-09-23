#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"

int main()
{
    float numeroUno;
    float numeroDos;
    float resultado;
    float aux;
    int fNumeroUno=0;   //bandera que se iguala a uno cuando se ingresa correctamente el primer numero
    int fNumeroDos=0;   //bandera que se iguala a uno cuando se ingresa correctamente el segundo numero
    char seguir='s';

    while(seguir=='s')
    {
        switch(mostrarMenu("1-Ingresar 1er operando (A=",'x',")\n2-Ingresar 2do operando (B=",'y',
                            ")\n3-Calcular suma(A+B)\n4-Calcular resta(A-B)\n5-Calcular division(A/B)"
                            "\n6-Calcular multiplicacion (A*B)\n7-Calcular factorial (A!)\n8-Hacer todas\n9-Salir\n",
                            "Error. Debe ser un Numero entero entre 1 y 9. Reingrese: ",1,9,
                            numeroUno,numeroDos,fNumeroUno,fNumeroDos))
        {
            case 1:
                if(!pedirNumero("Error. Solo pueden ingresarse numeros.","Ingrese el 1er operando: ",&aux))
                {
                    numeroUno=aux;
                    fNumeroUno=1;/*se iguala a uno para que la funcion menu sepa que tiene
                                   que mostrar el valor de numeroUno en vez de 'x' */
                }
                break;

            case 2:
                if(!pedirNumero("Error. Solo pueden ingresarse numeros.","Ingrese el 2do operando: ",&aux))
                {
                    numeroDos=aux;
                    fNumeroDos=1;/*se iguala a uno para que la funcion menu sepa que tiene
                                   que mostrar el valor de numeroDos en vez de 'y' */
                }
                break;

            case 3:
                /*toma los vaores de los flags para saber si se ingresaron los numeros*/
                if(!comenzarOperacion(fNumeroUno,fNumeroDos))
                {
                    resultado= sumar(numeroUno,numeroDos);
                    printf("\nEl resultado de la suma es: %.2f\n",resultado);
                    system("pause");
                }
                break;

            case 4:
                if(!comenzarOperacion(fNumeroUno,fNumeroDos))
                {
                    resultado=restar(numeroUno,numeroDos);
                    printf("\nEl resultado de la resta es: %.2f\n",resultado);
                    system("pause");
                }
                break;

            case 5:
                if(!comenzarOperacion(fNumeroUno,fNumeroDos) && !dividir(numeroUno,numeroDos,&resultado))
                {
                    printf("El resultado de la division es: %.2f\n",resultado);
                    system("pause");
                }

                break;

            case 6:
                if(!comenzarOperacion(fNumeroUno,fNumeroDos))
                {
                    resultado=multiplicar(numeroUno,numeroDos);
                    printf("\nEl resultado de la multiplicacion es: %.2f\n",resultado);
                    system("pause");
                }
                break;

            case 7:
                if(fNumeroUno==0)//toma solo el valor de fNumeroUno para saber si se ingreso el numero
                {
                    printf("Ingrese el 1er operando primero.\n");
                    resultado=0;
                    system("pause");
                }
                else
                {
                    resultado=sacarFactorial(numeroUno);

                }

                if(resultado!=0)
                {
                    printf("\nEl factorial de %.2f es: %.2f\n",numeroUno,resultado);
                    system("pause");
                }

                break;

            case 8:
                if(!comenzarOperacion(fNumeroUno,fNumeroDos))
                {
                    hacerTodas(numeroUno,numeroDos,resultado);
                }

                break;

            case 9:
                seguir = 'n';
                break;
        }

        printf("\n\n\n");

    }
    return 0;
}
