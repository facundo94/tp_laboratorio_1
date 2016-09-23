

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}ePersona;

int mostrarMenu(char[]);

void inicializarArrayInt(ePersona[],int ,int);

int esSoloLetras(char []);

int getStringLetras(char[],char []);

int getStringNumeros(char[],char[]);

void getString(char [],char[]);

int esNumerico(char[]);

int ordenar(ePersona[],int );

int cambiarOrden(ePersona datos[], int i, int j);

int mostrarPersona(ePersona);

int mostrarPersonas(ePersona[],int);

int buscarLugar(ePersona[],int ,int);

int buscarDni(ePersona[],int,int);

int pedirDni(ePersona[],int,char[]);

int pedirNombre(char[],int);

int pedirEdad(char[],int);

int validarTamArray(char[],int);

int graficar(char grafico[][16],int maximo,int aMenor, int aMedio, int aMayor);

int sacarMaximo(int, int, int);
