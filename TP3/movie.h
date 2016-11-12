#ifndef MOVIE_H
#define MOVIE_H

typedef struct
{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[400];
    int puntaje;
    char linkImagen[150];
    int isEmpty;
}EMovie;

int EMovie_agregarPelicula(EMovie* movie,int lenMovies,int* pCantPeliculas);
int EMovie_borrarPelicula(EMovie* ,int,int*);
void generarPagina(EMovie [],int );
int EMovie_pedirTitulo(EMovie* ,char* buffer);
int EMovie_setTitulo(EMovie* , char* titulo);
char* EMovie_getTitulo(EMovie* );
int EMovie_setGenero(EMovie* , char* genero);
char* EMovie_getGenero(EMovie* );
int EMovie_setDescripcion(EMovie* , char* descripcion);
char* EMovie_getDescripcion(EMovie* );
int EMovie_setLinkImagen(EMovie* , char* linkImagen);
char* EMovie_getLinkImagen(EMovie* );
int EMovie_setDuracion(EMovie* , char* duracion);
int EMovie_getDuracion(EMovie* );
int EMovie_setPuntaje(EMovie* , char* puntaje);
int EMovie_getPuntaje(EMovie* );
void EMovie_listarPeliculas(EMovie* );
int EMovie_findPlace(EMovie* movieList,int lenMovies,int);
void EMovie_initIsEmpty(EMovie* movieList, int len);
int EMovie_pedirDuracion(EMovie* );
int EMovie_buscarPelicula(EMovie* , int , char* );
int EMovie_pedirPuntaje(EMovie* );
void EMovie_mostrarPelicula(EMovie);
void EMovie_mostrarPeliculaEnt(EMovie );
int EMovie_modificarPelicula(EMovie*, int );
void modificar(EMovie* , char*,int* );
int EMovie_pedirGenero(EMovie* ,char* );
int EMovie_pedirDescripcion(EMovie* ,char* );
int EMovie_pedirLink(EMovie* ,char* );

#endif // MOVIE_H
