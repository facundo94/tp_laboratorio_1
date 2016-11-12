#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "movie.h"

#define MAX_MOVIES 5

int main()
{
    char seguir='s';
    EMovie movieList[MAX_MOVIES];
    int cantPeliculas = 0;

    EMovie_initIsEmpty(movieList, MAX_MOVIES);

    while(seguir=='s')
    {
        system("cls");
        switch(mostrarMenu("1- Agregar pelicula\n2- Borrar pelicula\n3- Modificar Pelicula\n4- Generar pagina web\n5- Salir\n"))
        {
            case 1:
                EMovie_agregarPelicula(movieList,MAX_MOVIES,&cantPeliculas);
                break;
            case 2:
                if(!iniciarFuncion(cantPeliculas))
                    EMovie_borrarPelicula(movieList,MAX_MOVIES,&cantPeliculas);
                break;
            case 3:
                if(!iniciarFuncion(cantPeliculas))
                    EMovie_modificarPelicula(movieList,MAX_MOVIES);
               break;
            case 4:
                if(!iniciarFuncion(cantPeliculas))
                    generarPagina(movieList,cantPeliculas);
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                fflush(stdin);
                printf("\nDebe ingresarse un numero entre 1 y 4\n\n");
                system("pause");
        }
    }

    return 0;
}
