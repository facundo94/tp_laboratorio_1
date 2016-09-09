#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"


/** \brief muestra un menu y deja al usuario elegir una opcion de este
 *
 * \param opcionUno es la primera opcion del menu
 * \param opcionUnoX es la pocision de valor variable de la primera opcion
 * \param opcionDos es la segunda opcion del menu
 * \param opcionDosY es la pocision de valor variable de la segunda opcion
 * \param opciones son el resto de opciones a elegir
 * \param error es el mensaje en caso de que se ingrese un numero fuera del parametro o algo que no sea un numero
 * \param desde es el numero de la primera opcion
 * \param hasta es el numero de la ultima opcion
 * \param numeroUno es el primero numero ingresado por el usuario(se muestra en lugar de opcionUnoX)
 * \param numeroDos es el segundo numero ingresado por el usuario(se muestra en lugar de opcionDosY)
 * \param flagUno es la bandera que indica cuando mostrar opcionUnoX o numeroUno
 * \param flagDos es la bandera que indica cuando mostrar opcionDosY o numeroDos
 * \return
 *
 */
int mostrarMenu(char opcionUno[],char opcionUnoX, char opcionDos[], char opcionDosY,
                char opciones[],char error[], int desde, int hasta,
                float numeroUno, float numeroDos, int flagUno, int flagDos)
{
    int opcion=0;
    int flagTres=0;

    do
    {
        system("cls");

        if(flagUno==1)
        {
            printf("%s%.2f",opcionUno,numeroUno);
        }
        else
        {
            printf("%s%c",opcionUno,opcionUnoX);
        }

        if(flagDos==1)
        {
            printf("%s%.2f",opcionDos,numeroDos);
        }
        else
        {
            printf("%s%c",opcionDos,opcionDosY);
        }

        printf("%s",opciones);

        if(flagTres==1)
        {
            fflush(stdin);
            printf("\n\n%s",error);
        }

        if(!scanf("%d",&opcion))
        {
            fflush(stdin);
        }

        flagTres=1;


    }while(opcion < desde || opcion > hasta);

    return opcion;
}


/** \brief Recibe dos numeros por parametro y devuelve la suma de estos.
 *
 * \param a es el primer numero a sumar.
 * \param b es el segundo numero a sumar.
 * \return Retorna la suma de los dos numeros ingresados.
 *
 */
float sumar(float a,float b)
{
    return a+b;
}


/** \brief Recibe dos numeros por parametro y devuelve la diferencia de estos.
 *
 * \param a es el primer numero a restar.
 * \param b es el segundo numero a restar.
 * \return Retorna la diferencia de los dos numeros ingresados.
 *
 */
float restar(float a,float b)
{
    return a-b;
}


/** \brief Recibe dos numeros por parametro y divide al primero por el segundo, pasa el resultado por parametro.
 *
 * \param a es el dividendo.
 * \param b es el divisor.
 * \return retorna si lña funcion pudo ejecutarse con exito o no.
 *
 */
int dividir(float a,float b,float *resultado)
{
    int funciona=0;

    if(b==0)
    {
        printf("\nError. El segundo operando no puede ser 0 en la division\n");
        system("pause");
        funciona=1;
    }
    else
    {
        *resultado= a/b;
    }


    return funciona;
}


/** \brief Recibe dos numeros por parametro y retorna el producto de los dos.
 *
 * \param a es el primero numero a multiplicar.
 * \param b es el segundo numero a multiplicar.
 * \return retorna el producto de los dos numero que recibe.
 *
 */
float multiplicar(float a,float b)
{
    return a*b;
}


/** \brief Recibe un numero por parametro y retorna el factorial del mismo.
 *
 * \param a es el numero al que se le aplica el factorial.
 * \return retorna el factorial del numero que recibe.
 *
 */
float sacarFactorial(float a)
{
    float factorial;
    int i;

    if(validarEntero(a))
    {
        printf("\nError. Debe ser un numero sin parte decimal para el factorial.\n");
        factorial=0;
    }
    else if(a<0)
    {
        printf("\nError. Debe ser un numero positivo para el factorial.\n");
        factorial=0;
        system("pause");
    }
    else if(a==0 || a==1)
    {
        factorial=1;
    }
    else
    {
        factorial=a;

        for(i=1;i<a;i++)
        {
            factorial=factorial*i;
        }
    }

    return factorial;
}


/** \brief recibe un numero por parametro y retorna 0 si es entero y 1 si tene parte decimal.
 *
 * \param a es el numero a analizar.
 * \return retorna 1 si el numero tiene parte decimal y 0 si no la tiene.
 *
 */
float validarEntero(float a)
{
    int b;
    int esValido=0;

    b=a;

    if(a>b)
    {
        esValido=1;
    }

    return esValido;
}


/** \brief muestra un mensaje pidiendo al usario un numero que se devuelve por parametro
 *  \brief muestra un mensaje de error si lo ingresado no es un numero
 *
 * \param error es el mensaje mostrado en caso de no ingresar un numero
 * \param mensaje es el mensaje que le pide al usuario el ingreso del numero
 * \param aux es la variable que pasa el numero por parametro
 * \return retorna 0 si lo ingresado es un numero y 1 si no lo es
 *
 */
int pedirNumero(char error[],char mensaje[], float *aux)
{
    int a=0;

    printf("\n%s",mensaje);
    if(!scanf("%f",aux))
    {
        printf("\n%s\n",error);
        system("pause");
        fflush(stdin);
        a=1;
    }

    return a;

}


/** \brief recibe dos banderas para verificar que se hayan ingresado numeros y asi poder realizar las operaciones matematicas
 *
 * \param a es la bandera primer numero
 * \param b es la bandera del segundo numero
 * \return retorna 0 si las dos banderas estan en 1 y 0 en caso contrario, muestra un error en caso de que alguna sea 0
 *
 */
int comenzarOperacion(int a, int b)
{
    int operar=0;

    if(a==0 || b==0)
    {
        if(a==0)
        {
            printf("\nIngrese el 1er operando primero.\n");
            operar=1;
        }

        if(b==0)
        {
            printf("\nIngrese el 2do operando primero.\n");
            operar=1;
        }

        system("pause");
    }


    return operar;
}


/** \brief llama a las funciones de las operaciones para realizarlas todas y mostrar sus resultados
 *
 * \param numeroUno es el primer numero a operar
 * \param numeroDos es el segundo numero a operar
 * \param resultado es el resultado de cada operacion
 * \return retorna 1 para informar de que pudo completar su tarea con exito
 *
 */
int hacerTodas(float numeroUno, float numeroDos, float resultado)
{
    resultado= sumar(numeroUno,numeroDos);
    printf("\nEl resultado de la suma es: %.2f",resultado);

    resultado=restar(numeroUno,numeroDos);
    printf("\nEl resultado de la resta es: %.2f",resultado);

    if(!dividir(numeroUno,numeroDos,&resultado))
    {
        printf("\nEl resultado de la division es: %.2f",resultado);
    }

    resultado=multiplicar(numeroUno,numeroDos);
    printf("\nEl resultado de la multiplicacion es: %.2f",resultado);

    resultado=sacarFactorial(numeroUno);

    if(resultado!=0)
    {
        printf("\nEl factorial de %.2f es: %.2f\n",numeroUno,resultado);
    }
    system("pause");

    return 1;
}
