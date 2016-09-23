#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones.h"


/** \brief Muestra un menu por pantalla y retorna la opcion elegida
 *
 * \param recibe el array con las opciones a mostrar
 * \return retorna la opcion elegida entre las mostradas al usuario
 *
 */
int mostrarMenu(char opciones[])
{
    int opcion;

    printf("%s",opciones);
    scanf("%d",&opcion);

    return opcion;
}


/** \brief inicializa un array de numeros asignando el mismo valor en todas las pociciones
 *
 * \param lista es un array del tipo ePersona con los campos a inicializar
 * \param cantidadDeElementos es el valor que indica hasta cuando iterar
 * \param valor es el valor a asignar en todas las pocisiones del array
 * \return void
 */
void inicializarArrayInt(ePersona lista[],int cantidadDeElementos,int valor)
{
    int i;

    for(i=0;i<cantidadDeElementos;i++)
    {
        lista[i].estado=valor;
    }

}


/** \brief busca un lugar en el array y retorna el lugar o -1 si no hay ninguno disponible
 *
 * \param lista es el array del tipo ePersona en el que se realiza la busqueda
 * \param cantidadDeElementos es el valor que indica hasta cuando iterar
 * \param valor es el valor a buscar en el array
 * \return retorna el el indice del lugar o -1 si no hay ninguno disponible
 *
 */
int buscarLugar(ePersona lista[],int cantidadDeElementos,int valor)
{
    int i;

    for(i=0;i<cantidadDeElementos;i++)
    {
        if(lista[i].estado==valor)
        {
            return i;
        }
    }

    return -1;
}


/** \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/** \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}


/** \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/** \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}


/** \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}


/** \brief compara mediante burbujeo y envia a cambiarOrden si es necesesario
 *
 * \param datos es el array del tipo ePersona a ordenar
 * \param tam indica hasta cuando iterar
 * \return 0
 *
 */
int ordenar(ePersona datos[],int tam)
{
    int i;
    int j;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(datos[i].estado==1 && datos[j].estado==1)
            {
                if(strcmp(datos[i].nombre,datos[j].nombre)==1)
                {
                    cambiarOrden(datos,i,j);
                }
                else if(strcmp(datos[i].nombre,datos[j].nombre)==0)
                {
                    if(datos[i].dni>datos[j].dni)
                    {
                        cambiarOrden(datos,i,j);
                    }
                }
            }
        }

    }

    return 0;
}


/** \brief cambia el orden de los datos que recibe por parametro
 *
 * \param datos es el array del tipo ePersona a cambiar de orden
 * \param i indica el primer elemento a cambiar de lugar
 * \param j indica el segundo elemento a cambiar de lugar
 * \return 0
 *
 */
int cambiarOrden(ePersona datos[], int i, int j)
{
    char auxTexto[256];
    int auxNum;

    strcpy(auxTexto,datos[i].nombre);
    strcpy(datos[i].nombre,datos[j].nombre);
    strcpy(datos[j].nombre,auxTexto);

    auxNum=datos[i].edad;
    datos[i].edad=datos[j].edad;
    datos[j].edad=auxNum;

    auxNum=datos[i].dni;
    datos[i].dni=datos[j].dni;
    datos[j].dni=auxNum;

    return 0;
}


/** \brief muestra por pantalla la informacion de una persona
 *
 * \param datos es la estructura ePersona con los datos a mostrar
 * \return 0
 *
 */
int mostrarPersona(ePersona datos)
{
    printf("%15s %9d %10d\n",datos.nombre,datos.edad,datos.dni);
    return 0;
}


/** \brief recorre un array del tipo ePersona eligiendo cuales se mostraran por pantalla
 *
 * \param datos es el array del tipo ePersona a mostrar
 * \param tam indica hasta donde iterar
 * \return 0
 *
 */
int mostrarPersonas(ePersona datos[],int tam)
{
    int i;

    printf("         Nombre      Edad        DNI\n\n");

    for(i=0;i<tam;i++)
    {
        if(datos[i].estado==1)
        {
            mostrarPersona(datos[i]);
        }
    }

    printf("\n\n");
    return 0;
}


/** \brief pide al usuario su numero de dni, lo valida y verifica que haya espacio para guardarlo
 *
 * \param datos es el array de tipo ePersona en el que se guardara el dni en caso de haber un lugar disponible
 * \param tam indica el tamaño del array
 * \param auxDni es la variable char que contiene el dni a ingresar
 * \param lugarLibre
 * \return
 *
 */
int pedirDni(ePersona datos[],int tam,char auxDni[])
{
    int funciona=0;

    if (!getStringNumeros("Ingrese D.N.I: ",auxDni))
    {
        printf ("\n\nEl D.N.I debe ser numerico\n");
        funciona=1;
        system("pause");
    }
    else if(auxDni<0)
    {
        printf("\n\nEl numero debe ser positivo.\n\n");
    }
    else if(buscarDni(datos,tam,atoi(auxDni))!=-1)
    {
        printf("\nEl D.N.I ya se ingreso anteriormente.\n\n");
        funciona=1;
        system("pause");
    }

    return funciona;
}


/** \brief busca un numero de dni y retorna la pocision del array donde se encuentra o -1 si no lo encuentra
 *
 * \param lista es el array del tipo ePersona en el que se buscara el dni
 * \param cantidadDeElementos es el valor que indica hasta cuando iterar
 * \param dni es el dni a buscar
 * \return retorna la pocision del array donde se encuentra el dni buscado o -1 si no lo encuentra
 *
 */
int buscarDni(ePersona lista[],int cantidadDeElementos,int dni)
{
    int i;
    int lugar=-1;

    for(i=0;i<cantidadDeElementos;i++)
    {
        if(lista[i].dni==dni && lista[i].estado==1)
        {
            lugar=i;
        }
    }

    return lugar;
}


/** \brief pide un nombre al usuario y lo valida
 *
 * \param auxNombres es el array en el que se recibe el nombre a validar
 * \param int tam indica el tamaño del array
 * \return retorna 0 si el dato no es valido o 1 si lo es
 *
 */
int pedirNombre(char auxNombres[],int tam)
{
    int valido=0;

    if(!getStringLetras("Ingrese el nombe: ",auxNombres))
    {
        printf("\nSolo deben ser letras.\n\n");
       valido=1;
    }
    else if(validarTamArray(auxNombres,tam))
    {
        printf("\nEl nombre debe tener como maximo 50 caracteres.\n\n");
        valido=1;
    }

    return valido;
}


/** \brief pide una edad al usuario y la valida
 *
 * \param auxEdad es el array en el que se recibe la edad a validar
 * \param int tam indica el tamaño del array
 * \return retorna 0 si el dato no es valido o 1 si lo es
 *
 */
int pedirEdad(char auxEdad[],int tam)
{
    int valido=0;

    if(!getStringNumeros("Ingrese la edad: ",auxEdad))
    {
        printf("\nSolo deben ser numeros.\n\n");
        valido=1;
    }
    else if(auxEdad<0)
    {
        printf("\nLa edad no puede ser menor a 0.\n\n");
        valido=1;
    }
    else if(validarTamArray(auxEdad,tam))
    {
        printf("\n\nEl nombre debe tener como maximo 50 caracteres.\n\n");
        valido=1;
    }
    else if(atoi(auxEdad)>150)
    {
        printf("\n\nDebe ingresar una edad menor.\n\n");
        valido=1;
    }

    return valido;
}


/** \brief valida que el contanido de un array no exceda un cierto tamaño
 *
 * \param aux es el array que se recibe para validar
 * \param tam indica el tamaño maximo que puede tener el array
 * \return retorna 0 si el dato no es valido o 1 si lo es
 *
 */
int validarTamArray(char aux[],int tam)
{
    int valido=0;

    if(strlen(aux)>tam)
    {
        valido=1;
    }

    return valido;
}


/** \brief Crea y muestra el grafico de edades.
 *
 * \param grafico es la matriz que se usa para el graficar
 * \param maximo es el numero maximo entre los tres parametros del grafico
 * \param paramUno es la cantidad de numeros del primer parametro a graficar
 * \param paramDos es la cantidad de numeros del segundo parametro a graficar
 * \param paramTres es la cantidad de numeros del tercer parametro a graficar
 * \return 0
 *
 */
int graficar(char grafico[][16],int maximo,int paramUno, int paramDos, int paramTres)
{
    int i;

    for(i=0;i<maximo;i++)
    {
        if(paramUno>i)
        {
            strcpy(grafico[i],"   x");
        }
        else
        {
            strcpy(grafico[i],"    ");
        }

        if(paramDos>i)
        {
            strcat(grafico[i],"    x");
        }
        else
        {
            strcat(grafico[i],"     ");
        }

        if(paramTres>i)
        {
            strcat(grafico[i],"   x");
        }
        else
        {
            strcat(grafico[i],"    ");
        }
    }

    printf("\n\n");
    for(i=maximo-1;i>=0;i--)
    {
        printf("%s\n",grafico[i]);
    }
    printf("  <19 19-35 >35");
    printf("\n\n");

    system("pause");

    return 0;
}


/** \brief saca el el maximo entre tres numeros  pasados por parametros y lo retorna
 *
 * \param numUno es el primer numero a comparar
 * \param numDos es el primer segundo a comparar
 * \param numTres es el primer tercer a comparar
 * \return retorna el numero maximo entre los tres
 *
 */
int sacarMaximo(int numUno, int numDos, int numTres)
{
    int maximo=numUno;

    if(numDos>maximo)
    {
        maximo=numDos;
    }

    if(numTres>maximo)
    {
        maximo=numTres;
    }

    return maximo;
}
