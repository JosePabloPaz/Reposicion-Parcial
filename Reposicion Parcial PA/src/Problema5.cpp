/*
 * Problema5.cpp
 *
 *  Created on: 22 oct. 2017
 *      Author: Jose Paz
 */

/*                        Lista Enlazada
---------------------------------------------------------------------*/
#include <iostream>
#include <stdlib.h>
using namespace std;

struct nodo{
	int nro;    //los datos seran de tipo entero
	int info;
	nodo *sgte; //puntero
	nodo *nuevo;
	nodo *sig;
};


struct nodo; //definimos a nodo como un tipo de variable
nodo *fin; //puntero que ira siempre al final de la lista
nodo *lista; //puntero que para nosotros apuntara a la cabeza de nuestra lista
nodo *siguiente;
nodo *anterior;


typedef struct nodo *Tlista;

void insertarInicio(Tlista &lista, string valor)
{
    Tlista q;
    q = new(struct nodo);
    q->nro = valor;
    q->sgte = lista;
    lista  = q;
}

void insertarFinal(Tlista &lista, string valor)
{
    Tlista t, q = new(struct nodo);

    q->nro  = valor;
    q->sgte = NULL;

    if(lista==NULL)
    {
        lista = q;
    }
    else
    {
        t = lista;
        while(t->sgte!=NULL)
        {
            t = t->sgte;
        }
        t->sgte = q;
    }

}

int insertarAntesDespues()
{
    int _op, band;
    cout<<endl;
    cout<<"\t 1. Antes de la posicion           "<<endl;
    cout<<"\t 2. Despues de la posicion         "<<endl;

    cout<<"\n\t Opcion : "; cin>> _op;

    if(_op==1)
        band = -1;
    else
        band = 0;

    return band;
}

void insertarElemento(Tlista &lista, int valor, int pos)
{
    Tlista q, t;
    int i;
    q = new(struct nodo);
    q->nro = valor;

    if(pos==1)
    {
        q->sgte = lista;
        lista = q;
    }
    else
    {
        int x = insertarAntesDespues();
        t = lista;

        for(i=1; t!=NULL; i++)
        {
            if(i==pos+x)
            {
                q->sgte = t->sgte;
                t->sgte = q;
                return;
            }
            t = t->sgte;
        }
    }
    cout<<"   Error...Posicion no encontrada..!"<<endl;
}

Tlista buscarElemento(Tlista lista, int valor)
{
    Tlista q = lista;
    int i = 1, band = 0;

    while(q!=NULL)
    {
    	for (i = 0; i<valor; i++){
            q = q->sgte;
            i++;
    	}
    }


    if(band==0)
        cout<<"\n\n Numero no encontrado..!"<< endl;

    return q;
}

void reportarLista(Tlista lista)
{
     int i = 0;

     while(lista != NULL)
     {
          cout <<' '<< i+1 <<") " << lista->nro << endl;
          lista = lista->sgte;
          i++;
     }
}


void eliminarElemento(Tlista &lista, string valor)
{
    Tlista p, ant;
    p = lista;

    if(lista!=NULL)
    {
        while(p!=NULL)
        {
            if(p->nro==valor)
            {
                if(p==lista)
                    lista = lista->sgte;
                else
                    ant->sgte = p->sgte;

                delete(p);
                return;
            }
            ant = p;
            p = p->sgte;
        }
    }
    else
        cout<<" Lista vacia..!";
}

void eliminaRepetidos(Tlista &lista, int valor)
{
    Tlista q, ant;
    q = lista;
    ant = lista;

    while(q!=NULL)
    {
        if(q->nro==valor)
        {
            if(q==lista) // primero elemento
            {
                lista = lista->sgte;
                delete(q);
                q = lista;
            }
            else
            {
                ant->sgte = q->sgte;
                delete(q);
                q = ant->sgte;
            }
        }
        else
        {
            ant = q;
            q = q->sgte;
        }

    }// fin del while

    cout<<"\n\n Valores eliminados..!"<<endl;
}

int main(){
	Tlista listaParticipantes = NULL;
	Tlista listaPremios = NULL;
	int m, n;
	string par, pre;
	cout<<"Ingrese la cantidad de participantes"<<endl;
	cin>>m;
	cout<<"Ingrese la cantidad de Premios"<<endl;
	cin>>n;
	if(m>n){
		cout<<"Error";
	}else
	{
		while(m>0){
			cout<<"Ingrese un participante"<<endl; cin>>par;
			insertarInicio(listaParticipantes, par);
			m--;
		}

		while(n>0){
			cout<<"Ingrese un premio"<<endl; cin>>pre;
			insertarInicio(listaParticipantes, pre);
			n--;
		}

		int ind;
		while(n>0)
			{
			Tlista listaGanadores = NULL;
			string a;
				ind=rand()%n;

				a += buscarElemento(listaParticipantes, ind);
				eliminarElemento(listaParticipantes, a);
				a += buscarElemento(listaPremios,ind);
				string s = buscarElemento(listaPremios,ind);
				eliminarElemento(listaParticipantes, s);


				insertarInicio(listaGanadores, a);

				n--;

			}

		reportarLista(listaGanadores);
	}
	return 0;
}






