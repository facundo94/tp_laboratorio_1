/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ELEMENTS 5

#include "../testing/inc/main_test.h"
//#define TEST

#include "../inc/ArrayList.h"
#include "../inc/Employee.h"

void printArrayListEmployee(ArrayList* lista)
{
  int i=0;
  for(i=0;i<lista->len(lista);i++)
  {
      Employee* pAux = lista->get(lista,i);
      printf("%d) ",i);
      printEmployee(pAux);
  }
}


int run2(void);

int main(void)
{

    #ifdef TEST
        startTesting(1);    //
        startTesting(2);   //
        startTesting(3);    //
        startTesting(4);    //
        startTesting(5);    //
        startTesting(6);    //
        startTesting(7);    //
        startTesting(8);    //
        startTesting(9);    //
        startTesting(10);   //
        startTesting(11);   //
        startTesting(12);   //
        startTesting(13);   //
        startTesting(14);   //
        startTesting(15);
        startTesting(16);
        startTesting(17);
    #else
        //run();
        run2();
    #endif

    return 0;
}




int run2(void)
{
    // Genero personas para usar en el ArrayList
    Employee* p0 = newEmployee(14, "JUAN1" ,"LOPEZ", 133.22,5);
    Employee* p1 = newEmployee(14, "JUAN2" ,"LOPEZ", 233.22,5);
    Employee* p2 = newEmployee(14, "JUAN3" ,"LOPEZ", 333.22,5);
    Employee* p3 = newEmployee(14, "JUAN4" ,"LOPEZ", 433.22,5);

    printEmployee(p0);
    printEmployee(p1);
    printEmployee(p2);
    printEmployee(p3);
    //__________________________________________


    printf("\r\nCargo ArraList...\r\n");
    ArrayList* lista = al_newArrayList();
    lista->add(lista,p0);
    lista->add(lista,p1);
    lista->add(lista,p2);
    al_add(lista,p3); // forma no orientada a objetos
    printArrayListEmployee(lista);

    printf("\r\nRemuevo index 2\r\n");
    lista->remove(lista,2);
    printArrayListEmployee(lista);

    printf("\r\nContiene p0 ?\r\n");
    if(lista->contains(lista,p0))
        printf("SI");
    else
        printf("NO");

    printf("\r\nContiene p2 ?\r\n");
    if(lista->contains(lista,p2))
        printf("SI");
    else
        printf("NO");

    printf("\r\nAgrego p2 en la posicion 1\r\n");
    lista->set(lista,1,p2); // vuelvo a agregar p2
    printArrayListEmployee(lista);


    printf("\r\nClonamos array\r\n");
    ArrayList* lista2 = lista->clone(lista);
    printf("Lista original:%p\r\n",lista);
    printArrayListEmployee(lista);


    printf("Lista Clonada:%p\r\n",lista2);
    printArrayListEmployee(lista2);

    lista2->sort(lista2, compareEmployee,1);
    printf("Lista Clonada Ordenada por Edad (UP):%p\r\n",lista2);
    printArrayListEmployee(lista2);

    lista2->sort(lista2, compareEmployee,0);
    printf("Lista Clonada Ordenada por Edad (DOWN):%p\r\n",lista2);
    printArrayListEmployee(lista2);

    printf("\r\nlista clonada contiene lista?:");
    if(lista->containsAll(lista,lista2))
        printf("SI");
    else
        printf("NO");


    printf("\r\n\r\nPosicion de p2:");
    int index = lista->indexOf(lista,p2);
    printf("%d\r\n",index);
    printf("\r\nPosicion de p1:");
    index = lista->indexOf(lista,p1);
    printf("%d\r\n",index);


    printf("\r\n\r\nHacemos push de p1 en la posicion 1\r\n");
    lista->push(lista,1,p1);
    printArrayListEmployee(lista);


    printf("\r\nObtenemos sub-lista de 1 a 2\r\n");
    ArrayList* subLista = lista->subList(lista,1,2);
    printArrayListEmployee(subLista);


    printf("\r\n\r\nHacemos pop de p1 en la posicion 1\r\n");
    Employee* p1Aux = lista->pop(lista,1);
    printf("Elemento pop(): %s\r\n",p1Aux->name);
    printArrayListEmployee(lista);


    printf("\r\nClear array\r\n");
    lista->clear(lista);
    printArrayListEmployee(lista);

    printf("\r\nEsta vacio?\r\n");
    if(lista->isEmpty(lista))
        printf("SI");
    else
        printf("NO");

    // Test expansion/contraccion del size
    printf("\r\n\r\nTest size\r\n");
    int j;
    for(j=0; j<1100; j++)
    {
      Employee* pAux = malloc(sizeof(Employee));
      sprintf(pAux->name,"Juan %d",j);
      pAux->salary=j;
      lista->add(lista,pAux);
    }
    printf("Cantidad de elementos:%d\r\n",lista->len(lista));
    //printArrayListPersonas(lista);
    for(j=0; j<1100; j++)
    {
      lista->pop(lista,0);
    }
    printf("Cantidad de elementos:%d\r\n",lista->len(lista));
    //printArrayListPersonas(lista);
    //____________________________________

    printf("\r\nLibero memoria y termino\r\n");
    free(p0);
    free(p1);
    free(p2);
    free(p3);
    lista->deleteArrayList(lista);
    lista2->deleteArrayList(lista2);

    system("PAUSE");
    return 0;
}

