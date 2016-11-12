#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "lib.h"


/**
 *  Premite modificar una pelicula del archivo binario
 *  @param movieList el array de estructuras EMovie en el que se buscara y modificara la pelicula
 *  @param lenMovies es la cantidad maxima posible de peliculas en el sistema
 *  @return void
 */
int EMovie_modificarPelicula(EMovie* movieList,int lenMovies)
{
    char aux[401];
    EMovie auxMovie;
    int indice;
    int retorno=-1;

    fflush(stdin);

    if(EMovie_pedirTitulo(&auxMovie,aux)==0 && (indice = EMovie_buscarPelicula(movieList,lenMovies,aux))!= -1)
    {
        modificar(&movieList[indice],aux,&retorno);
    }
    return retorno;
}


/**
 *  Premite modificar una pelicula del archivo binario
 *  @param movie la estructura a ser modificada al archivo
 *  @param aux es la variable en la que se realizan las distintas validaciones
 *  @return void
 */
void modificar(EMovie* movie, char* aux,int* retorno)
{
    char seguir = 's';
    int opcion;
    do
    {
        system("cls");
        fflush(stdin);
        EMovie_mostrarPeliculaEnt(*movie);
        opcion=mostrarMenu("\n\n1-Titulo\n2-Genero\n3-Duracion\n4-Puntaje\n5-Descripcion\n6-Link de imagen\n7-Salir");
        switch(opcion)
        {
        case 1:
            *retorno = EMovie_pedirTitulo(movie,aux);
            break;
        case 2:
            *retorno = EMovie_pedirGenero(movie,aux);
            break;
        case 3:
            *retorno = EMovie_pedirDuracion(movie);
            break;
        case 4:
            *retorno = EMovie_pedirPuntaje(movie);
            break;
        case 5:
            *retorno = EMovie_pedirDescripcion(movie,aux);
            break;
        case 6:
            *retorno = EMovie_pedirLink(movie,aux);
            break;
        case 7:
            seguir = 'n';
            break;
        default:
            printf("\n\nError.Debe ser un numero entre 1 y 3.\n\n");
            system("pause");
            fflush(stdin);
        }
    }while(seguir=='s');
}


/**
 *  Busca una pelicula por nombre y retorna su indice
 *  @param movieList el array de estructuras EMovie en el que se raliza la busqueda
 *  @param lenMovies es la canidad maxima posible de peliculas en el sistema
 *  @param titulo es el titulo por el que se buscara la pelicula
 *  @return retorna -1 si la pelicula no se encuentra en el sistema y el indice de la pelicula si la encuentra
 */
int EMovie_buscarPelicula(EMovie* movieList, int lenMovies, char* titulo)
{
    int retorno = -1;
    int i;

    for(i=0; i<lenMovies; i++)
    {
        if(strcmp(stringToGenericCase(titulo),stringToGenericCase(movieList[i].titulo))==0)
        {
            retorno = i;
            break;
        }
        else if(i == lenMovies)
        {
            printf("\nLa pelicula no se encuentra en el sistema.\n\n");
            system("pause");
        }
    }
    return retorno;
}


/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int EMovie_borrarPelicula(EMovie* movieList,int lenMovies ,int* cantPeliculas)
{
    char opcion;
    int retorno=-1;
    int indice;
    char aux[256];
    EMovie movieAux;

    printf("\n");
    EMovie_pedirTitulo(&movieAux,aux);

    indice = EMovie_buscarPelicula(movieList,lenMovies,movieAux.titulo);
    if(indice==-1)
    {
        printf("\n\nLa pelicula no esta en el sistema.\n\n");
        system("pause");
    }
    else
    {
        printf("\n");
        EMovie_mostrarPelicula(movieList[indice]);
        printf("\n\nEste es la pelicula que desea dar de baja?: ");
        fflush(stdin);
        scanf("%c",&opcion);
        if(opcion=='s')
        {
            movieList[indice].isEmpty = 1;
            *cantPeliculas = *cantPeliculas-1;
            printf("\n\nBaja realizada con exito.\n\n");
            system("pause");
            retorno=0;
        }
        else
        {
            printf("\n\nBaja cancelada por el usuario.\n\n");
            system("pause");
        }
    }

    return retorno;

}


/**
 *  Muestra una pelicula que le llega por parametro
 *  @param this es la pelicula a mostrar
 *  @return void
 */
void EMovie_mostrarPelicula(EMovie this)
{
    printf("Titulo: %s Genereo: %s Duracion: %d Puntaje: %d",EMovie_getTitulo(&this),EMovie_getGenero(&this),EMovie_getDuracion(&this),EMovie_getPuntaje(&this));
}


/**
 *  Muestra una pelicula y todos sus campos que le llega por parametro
 *  @param this es la pelicula a mostrar
 *  @return void
 */
void EMovie_mostrarPeliculaEnt(EMovie this)
{
    printf("Titulo: %s Genereo: %s Duracion: %d Puntaje: %d",EMovie_getTitulo(&this),EMovie_getGenero(&this),EMovie_getDuracion(&this),EMovie_getPuntaje(&this));
    printf("\n\nDescripcion: %s\n",EMovie_getDescripcion(&this));
    printf("\nLink: %s\n",EMovie_getLinkImagen(&this));
}

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param movieList es la pelicula que contiene la informacion para generar la pagina correctamente
 *  @param cantMovies es la cantidad maxima posible de pelculas en el sistema
 */
void generarPagina(EMovie movieList[],int cantMovies)
{
    FILE* fArchivo;
    int i;

    fArchivo = fopen("template/index.html","w+");

    fprintf(fArchivo,"<!DOCTYPE html>\n");
    fprintf(fArchivo,"<html lang='en'>\n");
    fprintf(fArchivo,"<head>\n");
    fprintf(fArchivo,"\t<meta charset='utf-8'>\n");
    fprintf(fArchivo,"\t<meta http-equiv='X-UA-Compatible' content='IE=edge'>\n");
    fprintf(fArchivo,"\t<meta name='viewport' content='width=device-width, initial-scale=1'>\n");
    fprintf(fArchivo,"\t<title>Lista peliculas</title>\n");
    fprintf(fArchivo,"\t<link href='css/bootstrap.min.css' rel='stylesheet'>\n");
    fprintf(fArchivo,"\t<link href='css/custom.css' rel='stylesheet'>\n");
    fprintf(fArchivo,"</head>\n");
    fprintf(fArchivo,"<body>\n");
    fprintf(fArchivo,"\t<div class='container'>\n");
    fprintf(fArchivo,"\t\t<div class='row'>\n\n");

    for(i=0; i<cantMovies; i++)
    {
        fprintf(fArchivo,"\t\t\t<article class='col-md-4 article-intro'>\n");
        fprintf(fArchivo,"\t\t\t\t<a href='#'>\n");
        fprintf(fArchivo,"\t\t\t\t\t<img class='' src='%s",movieList[i].linkImagen);
        fprintf(fArchivo,"' alt=''>\n\t\t\t\t</a>\n");
        fprintf(fArchivo,"\t\t\t\t<h3>\n");
        fprintf(fArchivo,"\t\t\t\t\t<a href='#'>%s</a>\n",movieList[i].titulo);
        fprintf(fArchivo,"\t\t\t\t</h3>\n");
        fprintf(fArchivo,"\t\t\t\t<ul>\n");
        fprintf(fArchivo,"\t\t\t\t\t<li>Genero: %s</li>\n",movieList[i].genero);
        fprintf(fArchivo,"\t\t\t\t\t<li>Puntaje: %d</li>\n",movieList[i].puntaje);
        fprintf(fArchivo,"\t\t\t\t\t<li>Duracion: %d</li>\n",movieList[i].duracion);
        fprintf(fArchivo,"\t\t\t\t</ul>\n");
        fprintf(fArchivo,"\t\t\t\t<p>%s</p>\n",movieList[i].descripcion);
        fprintf(fArchivo,"\t\t\t</article>\n\n");
    }

    fprintf(fArchivo,"\t\t</div>\n");
    fprintf(fArchivo,"\t</div>\n");
    fprintf(fArchivo,"\t<script src='js/jquery-1.11.3.min.js'></script>\n");
    fprintf(fArchivo,"\t<script src='js/bootstrap.min.js'></script>\n");
    fprintf(fArchivo,"\t<script src='js/ie10-viewport-bug-workaround.js'></script>\n");
    fprintf(fArchivo,"\t<script src='js/holder.min.js'></script>\n");
    fprintf(fArchivo,"</body>\n");
    fprintf(fArchivo,"</html>");

    fclose(fArchivo);

    printf("\nPagina generada, para vizualizarla dirijase a la carpeta template del proyecto y abra el archivo index.html\n\n");
    system("pause");
}


/**
 *  Iniciliza el estado(isEmpty) de todos los elementos de un array del tipo EMvie en 1
 *  @param movieList es el array a inicializar
 *  @param len es la cantidad maxima posible de pelculas en el sistema
 *  @return void
 */
void EMovie_initIsEmpty(EMovie* movieList, int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        movieList[i].isEmpty = 1;
    }
}


/** \brief pone el titulo indicado en el campo titulo de la estructura que recibe
 *
 * \param this es el puntero a movie al que se copiara el titulo de ser valido
 * \param  titulo es el titulo a copiar
 * \return retorna -1 si this es null o 0 si se pudo realizar con exito
 *
 */
int EMovie_setTitulo(EMovie* this, char* titulo)
{
    int retorno = -1;

    if(this != NULL && titulo != NULL)
    {
        retorno = 0;
        strcpy(this->titulo,titulo);
    }
    return retorno;
}


/** \brief retorna el titulo de la estructura que recibe
 *
 * \param this es el puntero a movie del que se obtendra el dato
 * \return retorna null si this es null o el titulo si se pudo realizar con exito
 *
 */
char* EMovie_getTitulo(EMovie* this)
{
    char* retorno = NULL;
    if(this != NULL)
    {
        retorno = this->titulo;
    }
    return retorno;
}


/** \brief pone el genero indicado en el campo genero de la estructura que recibe
 *
 * \param this es el puntero a movie al que se copiara el genero de ser valido
 * \param  genero es el genero a copiar
 * \return retorna -1 si this es null o 0 si se pudo realizar con exito
 *
 */
int EMovie_setGenero(EMovie* this, char* genero)
{
    int retorno=-1;

    if(this != NULL && genero != NULL)
    {
        retorno = 0;
        strcpy(this->genero,genero);
    }
    return retorno;
}


/** \brief retorna el genero de la estructura que recibe
 *
 * \param this es el puntero a movie del que se obtendra el dato
 * \return retorna null si this es null o el genero si se pudo realizar con exito
 *
 */
char* EMovie_getGenero(EMovie* this)
{
    char* retorno = NULL;
    if(this != NULL)
    {
        retorno = this->genero;
    }
    return retorno;
}


/** \brief pone la descripcion indicado en el campo descripcion de la estructura que recibe
 *
 * \param this es el puntero a movie al que se copiara la descripcion de ser valido
 * \param  descripcion es la descripcion a copiar
 * \return retorna -1 si this es null o 0 si se pudo realizar con exito
 *
 */
int EMovie_setDescripcion(EMovie* this, char* descripcion)
{
    int retorno=-1;

    if(this != NULL && descripcion != NULL)
    {
        retorno = 0;
        strcpy(this->descripcion,descripcion);
    }
    return retorno;
}


/** \brief retorna la descripcion de la estructura que recibe
 *
 * \param this es el puntero a movie del que se obtendra el dato
 * \return retorna null si this es null o la descripcion si se pudo realizar con exito
 *
 */
char* EMovie_getDescripcion(EMovie* this)
{
    char* retorno = NULL;
    if(this != NULL)
    {
        retorno = this->descripcion;
    }
    return retorno;
}


/** \brief pone el linkImagen indicado en el campo linkImagen de la estructura que recibe
 *
 * \param this es el puntero a movie al que se copiara el linkImagen de ser valido
 * \param  linkImagen es el linkImagen a copiar
 * \return retorna -1 si this es null o 0 si se pudo realizar con exito
 *
 */
int EMovie_setLinkImagen(EMovie* this, char* linkImagen)
{
    int retorno=-1;

    if(this != NULL && linkImagen != NULL)
    {
        retorno = 0;
        strcpy(this->linkImagen,linkImagen);
    }
    return retorno;
}


/** \brief retorna  linkImagen de la estructura que recibe
 *
 * \param this es el puntero a movie del que se obtendra el dato
 * \return retorna null si this es null o el linkImagen si se pudo realizar con exito
 *
 */
char* EMovie_getLinkImagen(EMovie* this)
{
    char* retorno = NULL;
    if(this != NULL)
    {
        retorno = this->linkImagen;
    }
    return retorno;
}


/** \brief pone la duracion indicado en el campo duracion de la estructura que recibe
 *
 * \param this es el puntero a movie al que se copiara la duracion de ser valido
 * \param  duracion es la duracion a copiar
 * \return retorna -1 si this es null o e si se pudo realizar con exito
 *
 */
int EMovie_setDuracion(EMovie* this, char* duracion)
{
    int retorno=-1;

    if(this != NULL && duracion != NULL)
    {
        retorno = 0;
        this->duracion = atoi(duracion);
    }
    return retorno;
}


/** \brief retorna la duracion de la estructura que recibe
 *
 * \param this es el puntero a movie del que se obtendra el dato
 * \return retorna -1 si this es null o la duracion si se pudo realizar con exito
 *
 */
int EMovie_getDuracion(EMovie* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = this->duracion;
    }
    return retorno;
}


/** \brief pone el puntaje indicado en el campo puntaje de la estructura que recibe
 *
 * \param this es el puntero a movie al que se copiara el puntaje de ser valido
 * \param  puntaje es el puntaje a copiar
 * \return retorna -1 si this es null o 0 si se pudo realizar con exito
 *
 */
int EMovie_setPuntaje(EMovie* this, char* puntaje)
{
    int retorno=-1;

    if(this != NULL && puntaje != NULL)
    {
        retorno = 0;
        this->puntaje = atoi(puntaje);
    }
    return retorno;
}


/** \brief retorna el puntaje de la estructura que recibe
 *
 * \param this es el puntero a movie del que se obtendra el dato
 * \return retorna -1 si this es null o el si puntaje se pudo realizar con exito
 *
 */
int EMovie_getPuntaje(EMovie* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = this->puntaje;
    }
    return retorno;
}


/** \brief pide un titulo al usuario, valida su tamaño, que solo sean letras y numeros, lo formatea y lo copia su destino
 *
 * \param this es el puntero a movie al que se copiara el titulo de ser valido
 * \param  buffer es una variable auxiliar con la que se realizan las validaciones
 * \return retorna 0 si se ingresa un titulo valido y -1 si no es asi
 *
 */
int EMovie_pedirTitulo(EMovie* this,char* buffer)
{
    int retorno = -1;

    fflush(stdin);

    if(getStringAlfaNumerico("Ingrese el titulo de la pelicula: ",buffer))
    {
        fflush(stdin);
        printf("\n\nSolo pueden ingresarse letras y numeros.\n\n");
        system("pause");
    }
    else if(validarTamArray(buffer,3,20))
    {
        printf("\nEl genero debe tener entre 3 y 20 caracteres.\n\n");
        system("pause");
    }
    else
    {
        formatSentence(buffer);
        EMovie_setTitulo(this,buffer);
        retorno = 0;
    }

    return retorno;
}


/** \brief pide un genero al usuario, valida su tamaño, que solo sean letras, lo formatea y lo copia su destino
 *
 * \param this es el puntero a movie al que se copiara el genero de ser valido
 * \param  buffer es una variable auxiliar con la que se realizan las validaciones
 * \return retorna 0 si se ingresa un titulo valido y -1 si no es asi
 *
 */
int EMovie_pedirGenero(EMovie* this,char* buffer)
{
    int retorno = -1;

    fflush(stdin);

    if(!getStringLetras("\nIngrese el genero de la pelicula: ",buffer))
    {
        fflush(stdin);
        printf("\n\nDeben ingresarse letras solamente.\n\n");
        system("pause");
    }
    else if(validarTamArray(buffer,3,20))
    {
        printf("\nEl genero debe tener entre 3 y 20 caracteres.\n\n");
        system("pause");
    }
    else
    {
        formatSentence(buffer);
        EMovie_setGenero(this,buffer);
        retorno=0;
    }

    return retorno;
}


/** \brief pide una duracion al usuario, valida que este dentro del rango y lo copia su destino
 *
 * \param this es el puntero a movie al que se copiara la duracion de ser valido
 * \return retorna 0 si se ingresa un titulo valido y -1 si no es asi
 *
 */
int EMovie_pedirDuracion(EMovie* this)
{
    int retorno = -1;
    char aux[256];

    if(validarIntYRango("\nIngrese la duracion (en minutos) de la pelicula: ",aux,30,180) == 0)
    {
        this->duracion = atoi(aux);
        retorno=0;
    }

    return retorno;
}


/** \brief pide un puntaje al usuario, valida que este dentro del rango y lo copia su destino
 *
 * \param this es el puntero a movie al que se copiara el puntaje de ser valido
 * \return retorna 0 si se ingresa un titulo valido y -1 si no es asi
 *
 */
int EMovie_pedirPuntaje(EMovie* this)
{
    int retorno = -1;
    char aux[256];

    if(validarIntYRango("\nIngrese el puntaje de la pelicula: ",aux,1,10) == 0)
    {
        this->puntaje = atoi(aux);
        retorno=0;
    }

    return retorno;
}


/** \brief pide una descripcion al usuario, valida su tamaño, que solo sean letras y numeros, lo formatea y lo copia su destino
 *
 * \param this es el puntero a movie al que se copiara la descripcion de ser valido
 * \param  buffer es una variable auxiliar con la que se realizan las validaciones
 * \return retorna 0 si se ingresa un titulo valido y -1 si no es asi
 *
 */
int EMovie_pedirDescripcion(EMovie* this,char* buffer)
{
    int retorno = -1;

    fflush(stdin);

    if(getStringAlfaNumerico("\nIngrese la descripcion de la pelicula: ",buffer))
    {
        fflush(stdin);
        printf("\n\nDeben ingresarse letras solamente.\n\n");
        system("pause");
    }
    else if(validarTamArray(buffer,100,400))
    {
        printf("\nLa descripcion debe tener entre 100 y 400 caracteres.\n\n");
        system("pause");
    }
    else
    {
        formatSentence(buffer);
        EMovie_setDescripcion(this,buffer);
        retorno=0;
    }

    return retorno;
}

/** \brief pide un link al usuario, valida su tamaño y lo copia su destino
 *
 * \param this es el puntero a movie al que se copiara el link de ser valido
 * \param  buffer es una variable auxiliar con la que se realizan las validaciones
 * \return retorna 0 si se ingresa un titulo valido y -1 si no es asi
 *
 */
int EMovie_pedirLink(EMovie* this,char* buffer)
{
    int retorno = -1;

    fflush(stdin);

    printf("\nIngrese el link de la imagen: ");
    gets(buffer);
    if(validarTamArray(buffer,20,150))
    {
        printf("\nLa descripcion debe tener entre 20 y 150 caracteres.\n\n");
        system("pause");
    }
    else
    {
        EMovie_setLinkImagen(this,buffer);
        retorno=0;
    }

    return retorno;
}

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @param lenMovies es la cantidad maxima posible de pelculas en el sistema
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int EMovie_agregarPelicula(EMovie* this,int lenMovies,int* pCantPeliculas)
{
    char bufferTitulo[256];
    char buffer[401];
    int retorno = -1;
    int place;

    place=EMovie_findPlace(this,lenMovies,1);
    if(place==-1)
    {
        printf("\n\nNo quedan lugares disponibles.\n\n");
        system("pause");
    }
    else
    {
        printf("\n--- Alta pelicula ---\n");
        if((EMovie_pedirTitulo(this+place,bufferTitulo)==0) && (EMovie_pedirGenero(this+place,buffer)==0)
            && (EMovie_pedirDescripcion(this+place,buffer)==0) && (EMovie_pedirLink(this+place,buffer)==0)
            && (EMovie_pedirDuracion(this+place)==0) && (EMovie_pedirPuntaje(this+place)==0))
        {
            this[place].isEmpty=0;
            *pCantPeliculas=*pCantPeliculas+1;
            retorno=0;
            printf("\n\n-Alta realizada con exito-\n\n");
            system("pause");
        }
    }
    return retorno;
}


/** \brief lista las peliculas
 *
 * \param this es el puntero a movie del que se obtendrar las peliculas a mostrar
 * \return void
 *
 */
void EMovie_listarPeliculas(EMovie* this)
{
    int i;

    for(i=0; i<5; i++)
    {
        if(this[i].isEmpty == 0)
        {
            printf("%s %s",this->titulo,this->genero);
        }
    }

}

/** \brief encuentra un lugar en el array EMovie
 *
 * \param movieList es el puntero a movie del que se obtendrar las peliculas a mostrar
 * \param lenMovies es la cantidad maxima posible de pelculas en el sistema
 * \param valor es el numero usado para buscar un lugar vacio
 * \return void
 *
 */
int EMovie_findPlace(EMovie* movieList,int lenMovies,int valor)
{
    int i;

    for(i=0;i<lenMovies;i++)
    {
        if(movieList[i].isEmpty == valor)
        {
            return i;
        }
    }

    return -1;
}

