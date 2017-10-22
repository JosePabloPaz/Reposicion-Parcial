/*
 * Problema4.cpp
 *
 *  Created on: 20 oct. 2017
 *      Author: Jose Paz
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

/*                        Lista Doblemente Enlazada
---------------------------------------------------------------------*/
#define ASCENDENTE 1
#define DESCENDENTE 0

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


class nodos {
   public:
    nodos(int v, nodos *sig = NULL, nodos *ant = NULL) :  valor(v), siguiente(sig), anterior(ant) {}

   private:
      int valor;
      nodos *siguiente;
      nodos *anterior;

   friend class lista;
};

typedef nodos *pnodo;

class lista {
   public:
    lista() : plista(NULL) {}
    ~lista();

    void Insertar(int v);
    void Borrar(int v);
    bool ListaVacia() { return plista == NULL; }
    string Mostrar(int);
    void Siguiente();
    void Anterior();
    void Primero();
    void Ultimo();
    bool Actual() { return plista != NULL; }
    int ValorActual() { return plista->valor; }

   private:
    pnodo plista;
};

lista::~lista()
{
   pnodo aux;

   Primero();
   while(plista) {
      aux = plista;
      plista = plista->siguiente;
      delete aux;
   }
}

void lista::Insertar(int v)
{
   pnodo nuevo;

   Primero();
   // Si la lista está vacía
   if(ListaVacia() || plista->valor > v) {
      // Asignamos a lista un nuevo nodo de valor v y
      // cuyo siguiente elemento es la lista actual
      nuevo = new nodos(v, plista);
      if(!plista) plista = nuevo;
      else plista->anterior = nuevo;
   }
   else {
      // Buscar el nodo de valor menor a v
      // Avanzamos hasta el último elemento o hasta que el siguiente tenga
      // un valor mayor que v
      while(plista->siguiente && plista->siguiente->valor <= v) Siguiente();
      // Creamos un nuevo nodo después del nodo actual
      nuevo = new nodos(v, plista->siguiente, plista);
      plista->siguiente = nuevo;
      if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
   }
}

void lista::Borrar(int v)
{
   pnodo nodo;

   nodo = plista;
   while(nodo && nodo->valor < v) nodo = nodo->siguiente;
   while(nodo && nodo->valor > v) nodo = nodo->anterior;

   if(!nodo || nodo->valor != v) return;
   // Borrar el nodo

   if(nodo->anterior) // no es el primer elemento
      nodo->anterior->siguiente = nodo->siguiente;
   if(nodo->siguiente) // no el el último nodo
      nodo->siguiente->anterior = nodo->anterior;
   delete nodo;
}

string lista::Mostrar(int orden)
{
	string a;
   pnodo nodo;
   if(orden == ASCENDENTE) {
      Primero();
      nodo = plista;
      while(nodo) {
         a +=  nodo->valor + "\n";
         nodo = nodo->siguiente;
      }
   }
   else {
      Ultimo();
      nodo = plista;
      while(nodo) {
         a +=  nodo->valor + "\n";
         nodo = nodo->anterior;
      }
   }
   return a;
}

void lista::Siguiente()
{
   if(plista) plista = plista->siguiente;
}

void lista::Anterior()
{
   if(plista) plista = plista->anterior;
}

void lista::Primero()
{
   while(plista && plista->anterior) plista = plista->anterior;
}

void lista::Ultimo()
{
   while(plista && plista->siguiente) plista = plista->siguiente;
}


/*                        Lista Enlazada
---------------------------------------------------------------------*/

typedef struct nodo *Tlista;

void insertarInicio(Tlista &lista, int valor)
{
    Tlista q;
    q = new(struct nodo);
    q->nro = valor;
    q->sgte = lista;
    lista  = q;
}

void insertarFinal(Tlista &lista, int valor)
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

void buscarElemento(Tlista lista, int valor)
{
    Tlista q = lista;
    int i = 1, band = 0;

    while(q!=NULL)
    {
        if(q->nro==valor)
        {
            cout<<endl<<" Encontrada en posicion "<< i <<endl;
            band = 1;
        }
        q = q->sgte;
        i++;
    }

    if(band==0)
        cout<<"\n\n Numero no encontrado..!"<< endl;
}

string reportarLista(Tlista lista)
{
	string a;
     int i = 0;

     while(lista != NULL)
     {

          a += ' ' + (i+1) +  ")" + lista->nro;
          lista = lista->sgte;
          i++;
     }
     return a;
}


void eliminarElemento(Tlista &lista, int valor)
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

/*     Lista Enlazada Contenida en Lista Doblemente Enlazada
---------------------------------------------------------------------*/

bool listaContenida(){
	Tlista lista = NULL;
	lista l;
	if(reportarLista(lista) == l.Mostrar(1)){
		return true;
	}else if(reportarLista(lista) == l.Mostrar(0)){
		return true;
	}else
		return false;
}










