/*
 * Problema2.cpp
 *
 *  Created on: 19 oct. 2017
 *      Author: Jose Paz
 */

#include <stdlib.h>
#include <iostream>
using namespace std;

namespace std {

struct nodo {
    int info;
    struct nodo *sig;
};

nodo *ent;

void crear(struct nodo **tope) {
    *tope = NULL;
}

void poner(struct nodo **tope, int dato) {
    struct nodo *aux;
    aux = new nodo;  //new() devuelve un puntero
    if(aux == NULL) {
        cout<<"Memoria insuficiente..."<<endl;
        exit(1);
    }
    aux->info = dato;
    aux->sig = *tope;
    *tope = aux;
}

int sacar(struct nodo **tope) {
    struct nodo *aux;
    int dato;
    aux = *tope;
    dato = (*tope)->info;   //podria ser: dato = aux->info;
    *tope = (*tope)->sig;   //podria ser: *tope = aux->sig;
    delete aux;             //libero memoria
    return dato;
}

int ver(struct nodo **tope){
    return (*tope)->info;
}

int vacia(struct nodo **tope) {
    if(*tope == NULL)
        return 0;
    else
        return 1;
}

void recorrer(struct nodo **tope) {
    struct nodo *tope_aux;
    int dato;
    crear(&tope_aux);    //pila AUXILIAR, es LOCAL
    while(vacia(tope) != 0) {    //vacia(tope) = &(*tope)
        dato = sacar(tope);
        cout<<dato<<endl;
        poner(&tope_aux, dato);
    }
    //armoa nuevamente la pila:
    //quedo al reves y tope no apunta a nada ...
    while(vacia(&tope_aux) != 0) {
        poner(tope, sacar(&tope_aux));
    }
}

void Reemplazar(int nuevo, int viejo){
	    struct nodo *p;
	    struct nodo tope;
	        p = *ent;
	        while((p != NULL) && (p->info < viejo)) p = p->sig;
	        if(p->info == viejo){
	        	 p = nuevo;
	        }
	        recorrer(*p);
}

int main(void) {
    struct nodo *tope;
    int dato;
    int viejo, nuevo;
    crear(&tope);
    cout<<"\nIngrese un valor: ";
    cin>>dato;
    //cargo la pila
    while(dato != 0) {
        poner(&tope, dato);
        cout<<"\nIngrese un valor: ";
        cin>>dato;
    }
    //saco un elemento
    if(vacia(&tope) != 0) {
        dato = sacar(&tope);
        cout<<"\nTOPE de la pila: "<<dato<<endl;
    }

    cout<<"\nIngrese dato a reemplazar: "<<endl;
    cin>>viejo;
    cout<<"\nIngrese dato nuevo: "<<endl;
    cin>>nuevo;

    Reemplazar(nuevo, viejo);

    getchar();
    getchar();
    return 0;
}

} /* namespace std */
