/*
 * Problema3.cpp
 *
 *  Created on: 20 oct. 2017
 *      Author: Jose Paz
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

struct elemento
{
	int dato;
	struct elemento * sig;
};

void crear(struct elemento **lista);
void InsertaOrdenada(struct elemento **lista, int elemento);
void MuestraOrdenada(struct elemento *lista);
void JuntarListas(struct elemento **listaU, struct elemento **list1, struct elemento **list2);



int main()
{
int opcion,x;
struct elemento *lista1, *lista2, *lista_unida;
crear(&lista1);
crear(&lista2);
crear(&lista_unida);

	do{
   	cout<<"\n\nMENU OPCIONES LISTA ENLAZADA SIMPLE";
      cout<<"\n___________________________________________";
		cout<<"\n\n 1.-Insertar elemento en la lista 1";
      cout<<"\n 2.-Insertar elemento en la lista 2";
		cout<<"\n 3.-Unir listas.";
		cout<<"\n 4.-Listar elementos\n";
		cout<<"\n 0.-SALIR\n";
		cout<<"\nIntroduce la opcion: ";
		cin<<opcion;
		switch(opcion)
      	{
		case 1:  cout<<"Introduce el elemento que quieras introducir en la lista 1: ";
         			cin<<x;
         			InsertaOrdenada(&lista1, x);
                  break;

			case 2:
				cout<<"Introduce el elemento que quieras introducir en la lista 2: ";
         			cin<<x;
         			InsertaOrdenada(&lista2, x);
                  break;

         case 3:

         		  cout<<"Uniendo listas....\n\n";
                  JuntarListas(&lista_unida,&lista1,&lista2);
                  MuestraOrdenada(lista_unida);

                  break;
			case 4:
         		MuestraOrdenada(lista1);
                  MuestraOrdenada(lista2);
                  break;
			}

		}
   while(opcion!=0);
return 0;
system("pause");

}

void crear(struct elemento **lista)
{
	*lista=NULL;
}

void InsertaOrdenada(struct elemento **lista, int elemento)
{
	struct elemento *aux,*ant,*nuevo;
	nuevo=(struct elemento*)(sizeof(struct elemento));

	nuevo->dato=elemento;
   nuevo->sig=NULL;
   aux=(*lista);
   ant=(*lista);

   if(aux==NULL || aux->dato > nuevo->dato)
   {
   	nuevo->sig=aux;
   	(*lista)=nuevo;
   }
   else
   {
   	while(aux!=NULL && aux->dato < nuevo->dato)
         {
    			ant=aux;
            aux=aux->sig;
         }
      nuevo->sig=aux;
      ant->sig=nuevo;
   }
}

void JuntarListas(struct elemento **listaU, struct elemento **list1, struct elemento **list2)
{
	struct elemento *aux,*ant2,*aux2;

   aux=(*list1);
   aux2=(*listaU);
   ant2=(*listaU);

   while(aux!=NULL)
   {
   	if(aux2==NULL)
      {
      	aux->sig=aux2;
      	(*listaU)=aux;
      }
      else
      {
      	while(aux2!=NULL)
         {
         	ant2=aux2;
            aux2=aux2->sig;
         }
      	aux->sig=aux2;
         ant2->sig=aux;
      }
      aux=aux->sig;
  }
   MuestraOrdenada(*listaU);

   aux=(*list2);

   while(aux!=NULL)
   {
   	aux2=(*listaU);
   	ant2=(*listaU);

   	if(aux2==NULL || aux2->dato > aux->dato)
   	{
   		aux->sig=aux2;
   		(*listaU)=aux;
   	}
   	else
   	{
   		while(aux2!=NULL && aux2->dato < aux->dato)
         	{
    				ant2=aux2;
            	aux2=aux2->sig;
         	}
      	aux->sig=aux2;
      	ant2->sig=aux;
   	}
      aux=aux->sig;
   }

}

void MuestraOrdenada(struct elemento *lista)
{
	struct elemento *aux;
	int i=1;
   if(lista==NULL)
   {
   	cout<<"No se ha encontrado ningun elemento en la lista\n\n";
   }
   else
   {

		aux=lista;
		while(aux)
   	{
			cout<<"\nElemento:"<<i<<""<<aux<<endl;
			aux=aux->sig;
      	i++;
		}
   	cout<<"\n\n";
   }
}




