#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones.h"

#define PERSONAS 20

int main()
{
    ePersona lista[PERSONAS];
    char grafico[21][16];
    char auxNombres[256];
    char auxDni[256];
    char auxEdad[256];
    char seguir='s';
    int edad;
    int dni;
    int lugar; //se le asigna el indice al buscar un lugar libre en particular
    int opcion;
    int lugarLibre; //se le asigna el indice al buscar un lugar libre
    int paramUno=0;
    int paramDos=0;
    int paramTres=0;
    int maximo;

    inicializarArrayInt(lista,PERSONAS,-1);

    while(seguir=='s')
    {
        opcion=mostrarMenu("1- Agregar persona\n2- Borrar persona\n3- Imprimir lista ordenada por  nombre\n"
                           "4- Imprimir grafico de edades\n5- Salir\n");

        switch(opcion)
        {
            case 1:
                lugarLibre=buscarLugar(lista, PERSONAS, -1);
                if(lugarLibre==-1)
                {
                    printf("No hay espacios disponibles.\n\n");
                    system("pause");
                    break;
                }

                printf("\n**** Alta ****\n\n");
                if(pedirDni(lista,PERSONAS,auxDni))
                {
                    break;
                }

                if(pedirNombre(auxNombres,50))
                {
                    system("pause");
                    break;
                }

                if(pedirEdad(auxEdad,3))
                {
                    system("pause");
                    break;
                }

                dni = atoi(auxDni);
                edad = atoi(auxEdad);
                strcpy(lista[lugarLibre].nombre,auxNombres);
                lista[lugarLibre].edad=edad;
                lista[lugarLibre].dni=dni;
                lista[lugarLibre].estado=1;

                if(lista[lugarLibre].edad<=18)  //se suman elementos al grafico
                {
                    paramUno++;
                }
                else if(lista[lugarLibre].edad>=36)
                {
                    paramTres++;
                }
                else
                {
                    paramDos++;
                }

                break;
            case 2:
                if (!getStringNumeros("Ingrese D.N.I a dar de baja: ",auxDni))
                {
                    printf ("El D.N.I debe ser numerico\n");
                    system("pause");
                    break;
                }

                lugar = buscarDni(lista,PERSONAS,atoi(auxDni));
                if(lugar == -1)
                {
                    printf("\nEl D.N.I no se ingreso anteriormente\n\n");
                    system("pause");
                    break;
                }

                lista[lugar].estado=-1;

                if(lista[lugar].edad<=18) //asi como en el case uno se suman, aqui se restan elementos del grafico
                {
                    paramUno--;
                }
                else if(lista[lugar].edad>=36)
                {
                    paramTres--;
                }
                else
                {
                    paramDos--;
                }

                printf("\nBaja ejecutada con exito.\n\n");
                system("pause");
                break;
            case 3:

                ordenar(lista,PERSONAS);
                mostrarPersonas(lista,PERSONAS);
                system("pause");
                break;
            case 4:

                maximo=sacarMaximo(paramUno,paramDos,paramTres);
                graficar(grafico,maximo,paramUno,paramDos,paramTres);
                break;
            case 5:

                seguir = 'n';
                break;
            default:
                printf("\nError.Debe ser un numero entre 1 y 5.\n\n");
                fflush(stdin);
                system("pause");
        }
        system("cls");
    }
    return 0;
}


