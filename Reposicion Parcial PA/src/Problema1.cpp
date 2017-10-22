/*
 * Problema1.cpp
 *
 *  Created on: 17 oct. 2017
 *      Author: Jose Paz
 */
#include <iostream>
#include <stdlib.h>
using namespace std;

/*                        Lista Circular
---------------------------------------------------------------------*/

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


void insertarInicio()
{
   nodo *nuevo;
   nuevo=new struct nodo;

   cout<<"\n***INSERTA AL INICIO*****\n";
   cout<<"\nINGRESE DATO:";
   cin>>nuevo->nro;
   nuevo->sgte=NULL;

   if(lista==NULL)
    {
        cout<<"PRIMER ELEMENTO..!!!";
        lista=nuevo;
        lista->sgte=lista;
        fin=nuevo;
      }
   else
     {
        nuevo->sgte = lista;
        lista = nuevo;
        fin->sgte = lista;
     }

}

void insertarFinal()
{
    nodo *nuevo;
    nuevo=new struct nodo;
    cout<<"\n***INSERTA AL INICIO*****\n";
    cout<<"\nINGRESE DATO:";
    cin>>nuevo->nro;
    nuevo->sgte=NULL;

     if(lista==NULL)
        {
             cout<<"PRIMER ELEMENTO..!!!";
             lista=nuevo;
             lista->sgte=lista;
             fin=nuevo;
        }
     else
        {
          fin->sgte = nuevo;
          nuevo->sgte = lista;
          fin = nuevo;
        }
}

void mostrar()
{   nodo *aux;
    aux=lista;
    int i=1;

    if(lista!=NULL)
     {
          do
          {    cout<<"  "<<aux->nro;
               aux = aux->sgte;
               i++;
          }while(aux!=lista);
      }
     else
         cout<<"\n\n\tLista vacia...!"<<endl;


}

void buscarElemento() //esta funcion muestra la posicion del primer dato coincidente
                      //encontrado en la lista
{
     nodo *aux;
     int i = 1, valor , flag = 0;

     cout<<"\nINGRESE ELEMENTO A BUSCAR:";
     cin>>valor;
     if(lista !=NULL)
     {
          aux = lista;

          do
          {
               if(aux->nro == valor)
               {
                   cout<<"\n\n Encontrado en posicion "<< i <<endl;
                   flag=1;
               }
               else
               {
                   aux = aux->sgte;
                   i++;
               }
          }while(aux!=lista);

          if(flag==0) cout<<"\n\n\tNumero no econtrado..!"<<endl;

     }
     else
         cout<<"\n\n\tLista vacia...!"<<endl;

}

void eliminarElemento()
{
    nodo *aux, *r, *q;
    int i = 1, flag = 0,valor;

    cout<<"\n INGRESE ELEMENTO A ELIMINAR:";
    cin>>valor;

    if(lista !=NULL)
     {
          aux = lista;

          do
          {
               if(aux->nro == valor)
                {
                    if(aux==lista)//si es que el dato a eliminar es el primero
                    {   r=lista;
                        lista=lista->sgte;
                        aux=aux->sgte;
                        fin->sgte=lista;
                        r->sgte=NULL;
                        if(fin->sgte==NULL)
                        {
                            lista=NULL;
                            aux=NULL;
                            delete(r);
                            cout<<"\nELEMENTO ELIMINADO...!!!\n";
                            return;
                        }
                        else
                        {
                            delete(r);
                            cout<<"\nELEMENTO ELIMINADO...!!!\n";
                            return;
                        }
                    }
                   else
                    {
                        if(aux==fin)//si es que el dato a eliminar es al que apunta a fin
                            {
                            r=aux;
                            aux=aux->sgte;
                            q->sgte=aux;
                            fin=q;
                            r->sgte=NULL;
                            delete(r);
                            cout<<"\nELEMENTO ELIMINADO...!!!\n";
                            return;
                            }
                        else
                        {
                            r=aux;
                            aux=aux->sgte;
                            q->sgte=aux;
                            r->sgte=NULL;
                            delete(r);
                            cout<<"\nELEMENTO ELIMINADO...!!!\n";
                            return;
                        }
                  }
                  flag=1;
                }
                else
                {   q=aux;
                    aux = aux->sgte;
                    i++;
                }
          }while(aux!=lista);

          if(flag==0)
          cout<<"\n\n\tNumero no econtrado..!"<<endl;


    }
    else
      cout<<"LISTA VACIA...!!!!";


}

void eliminarElementos()
{
     nodo *aux, *r, *q;
     int  flag = 0,valor;

     cout<<"\n DATO REPETIDO A ELIMINAR:";
     cin>>valor;

     if(lista !=NULL)
        { aux=lista;

            while(aux->nro==valor)//si los primeros elementos son repetidos
                if(aux==lista)    //esta funcion borra a estos
                  {
                   r=lista;
                   aux=lista->sgte;
                   lista=lista->sgte;
                   fin->sgte=lista;
                   r->sgte=NULL;
                    if(fin->sgte==NULL)
                     {
                        lista = NULL;
                        aux=NULL;
                        delete(r);
                        flag=1;
                      }
                    else
                     {
                        delete(r);
                        flag=1;
                     }
                   }
          do
          {
               if(aux->nro == valor)
                {
                    while(aux==lista)
                    {
                         r=lista;
                         aux=lista->sgte;
                         lista=lista->sgte;
                         fin->sgte=lista;
                         r->sgte=NULL;
                        if(fin->sgte==NULL)
                        {
                            lista = NULL;
                            aux = NULL;
                            delete(r);
                        }
                      else
                        delete(r);

                    }

                   if(aux==fin)//para si el elemento a borrar es apuntado por *fin
                    {
                        r=aux;
                        aux=aux->sgte;
                        q->sgte=aux;
                        fin=q;
                        r->sgte=NULL;
                        delete(r);
                    }
                    else
                    {
                        r=aux;
                        aux=aux->sgte;
                        q->sgte=aux;
                        r->sgte=NULL;
                        delete(r);
                    }

                    flag=1;
               }
               else
               {   q=aux;
                   aux = aux->sgte;
               }
          }while(aux!= lista);

          if(flag==0)
            cout<<"\n\n\tNumero no econtrado..!"<<endl;
        }
          else
            cout<<"LISTA VACIA...!!!!";
}


/*                        Lista Doblemente Enlazada
---------------------------------------------------------------------*/
#define ASCENDENTE 1
#define DESCENDENTE 0

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
    void Mostrar(int);
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

void lista::Mostrar(int orden)
{
   pnodo nodo;
   if(orden == ASCENDENTE) {
      Primero();
      nodo = plista;
      while(nodo) {
         cout << nodo->valor << "-> ";
         nodo = nodo->siguiente;
      }
   }
   else {
      Ultimo();
      nodo = plista;
      while(nodo) {
         cout << nodo->valor << "-> ";
         nodo = nodo->anterior;
      }
   }
   cout << endl;
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

/*                        Lista Estatica
---------------------------------------------------------------------*/

void crear(struct nodo **);
void insertar(struct nodo **, int);
void eliminar(struct nodo **, int);
void recorrerLista(struct nodo **);
int buscar(struct nodo **, int);  //true or false

void crearLista(struct nodo **ent)
{
    *ent = NULL;
}

void insertar(struct nodo **ent, int dato)
{
    struct nodo *aux, *p, *ant;
    aux = new nodo;
    if(!aux) { cout<<"error:memoria insuficiente"<<endl; exit(1);}
    aux->info = dato;
    ant = NULL;
    p = *ent; //p es el ptro aux que recorre la lista para insertar ORDENADO
    while((p != NULL) && (p->info < dato))
    {
        ant = p;
        p = p->sig;
    }
    if(ant == NULL)
    {
        aux->sig = *ent;
        *ent = aux;
    }
    else
    {
        ant->sig = aux;
        aux->sig = p;
    }
}

void eliminar(struct nodo **ent, int dato)
{
    struct nodo *p, *ant;
    p = *ent;
    ant = NULL;
    while((p != NULL) && (p->info < dato))
    //si pregunto p->info != dato recorro toda la lista sin sentido
    {
        ant = p;
        p = p->sig;
    }
    if(p->info != dato) cout<<"dato no existe "<<endl;
    else
    {
        if(ant == NULL) //1er nodo
                *ent = (*ent)->sig;
        else
                ant->sig = p->sig;

        delete p;
    }
}

void recorrerLista(struct nodo **ent)
{
    struct nodo *p;
    p = *ent;
    while(p != NULL)
    {
        cout<<p->info<<endl;
        p = p->sig;
    }
}

int buscar(struct nodo **ent, int dato)
{
    struct nodo *p;
    p = *ent;
    while((p != NULL) && (p->info < dato)) p = p->sig;
    if(p->info == dato)
        return 1;
    else
        return 0;
}


/*                        Pila Estatica
---------------------------------------------------------------------*/


void crearPila(struct nodo **);
void poner(struct nodo **, int);
int sacar(struct nodo **);
int ver(struct nodo **);  //veo pero NO elimino
int vacia(struct nodo **);      //vacia? booleano 0-1
void recorrerPila(struct nodo **);  //muestro lo que hay ... uso una pila aux

void crearPila(struct nodo **tope) {
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

void recorrerPila(struct nodo **tope) {
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

/*                        Cola Estatica
---------------------------------------------------------------------*/

void crearCola(struct nodo **, struct nodo **);
void ponerCola(struct nodo **, struct nodo **, int);
int sacarCola(struct nodo **, struct nodo **);
int vaciaCola(struct nodo **);
int verCola(struct nodo **);
void recorrerCola(struct nodo **, struct nodo **);

void crearCola(struct nodo **ent, struct nodo **sal) {
	*ent=NULL;
	*sal=NULL;
}

void ponerCola(struct nodo **ent, struct nodo **sal, int dato) {
	struct nodo *aux;                 //creo puntero auxiliar apuntando a nodo
	aux=new nodo;                     //pido memoria para un nodo
	if (aux==NULL) {
		cout << "Memoria insuficiente..." << endl;
		exit(1);
	}
	aux->info=dato;
	aux->sig=NULL;
	if(*ent==NULL)
		*sal=aux;
	else
		(*ent)->sig=aux;

	*ent=aux;
}

int sacarCola(struct nodo **sal, struct nodo **ent) {
	struct nodo *aux;
	int dato;
	aux=*sal;               // apunto aux al nodo que quiero sacar
	dato=(*sal)->info;
	*sal=(*sal)->sig;      // cambio *sal al siguiente nodo
	if(*sal==NULL)
		*ent=NULL;
	delete aux;
	return dato;
}


int vaciaCola(struct nodo **ent) {
	if(*ent==NULL)
		return 1;
	else
		return 0;
}


int verCola(struct nodo **sal) {
	return (*sal)->info;
}


void recorrerCola(struct nodo **ent, struct nodo **sal) {
	int dato, marca;
	if (vacia(ent)==1){
		cout<<"Cola vacia...";
	}
	else{
		dato=sacarCola(sal,ent);       // asigno nodo a variable aux dato
	}
		cout << dato; 			   // muestro elementos

		marca=dato;                // asigno a marca dato
		ponerCola(ent ,sal, dato);     // vuelvo a poner el dato al final de la cola
		dato=ver(sal);             // miro si llegue al dato de la marca
		while (dato!=marca) {
			dato=sacarCola(sal, ent);
			cout << dato << " ";
			ponerCola(ent, sal, dato);
			dato=ver(sal);
		}
}

/*                        Menus
---------------------------------------------------------------------*/

void menu1()
{
    cout<<"\n\t\tLISTA ENLAZADA SIMPLE\n\n";
    cout<<" 1. INSERTAR AL INICIO               "<<endl;
    cout<<" 2. INSERTAR AL FINAL                "<<endl;
    cout<<" 3. INSERTAR EN UNA POSICION         "<<endl;
    cout<<" 4. REPORTAR LISTA                   "<<endl;
    cout<<" 5. BUSCAR ELEMENTO                  "<<endl;
    cout<<" 6. ELIMINAR ELEMENTO 'V'            "<<endl;
    cout<<" 7. ELIMINAR ELEMENTOS CON VALOR 'V' "<<endl;
    cout<<" 8. SALIR                            "<<endl;

    cout<<"\n INGRESE OPCION: ";
}

void menu2()
{
    cout<<"\n\t\tLISTA ENLAZADA CIRCULAR\n\n";
    cout<<" 1. INSERTAR AL INICIO               "<<endl;
    cout<<" 2. INSERTAR AL FINAL                "<<endl;
    cout<<" 3. REPORTAR LISTA                   "<<endl;
    cout<<" 4. BUSCAR ELEMENTO                  "<<endl;
    cout<<" 5. ELIMINAR ELEMENTO 'V'            "<<endl;
    cout<<" 6. ELIMINAR ELEMENTOS CON VALOR 'V' "<<endl;
    cout<<" 7. SALIR                            "<<endl;

    cout<<"\n INGRESE OPCION: ";
}

/*                        Funcion Main
---------------------------------------------------------------------*/


int main() {

	Tlista lista = NULL;
	    int op;     // opcion del menu
	    int _dato;  // elemenento a ingresar
	    int pos;    // posicion a insertar
	    struct nodo *ent;
	    int dato;

	    system("color 0b");

	    cout<<"\n\t\tEstructura de Datos\n\n";
	        cout<<" 1. Lista Enlazada                   "<<endl;
	        cout<<" 2. Lista Doblemente Enlazada        "<<endl;
	        cout<<" 3. Lista Circular                   "<<endl;
	        cout<<" 4. Pila Estatica                   "<<endl;
	        cout<<" 5. Lista Estatica                    "<<endl;
	        cout<<" 6. Cola Estatica                    "<<endl;
	        cout<<" 7. SALIR                            "<<endl;

	        cout<<"\n INGRESE OPCION: ";


	        cin>> op;

	        	        switch(op)
	        	        {
	        	            case 1:

	        	            	 do
	        	            		    {
	        	            		        menu1();
	        	            		        cin>> op;

	        	            		        switch(op)
	        	            		        {
	        	            		            case 1:

	        	            		                 cout<< "\n NUMERO A INSERTAR: "; cin>> _dato;
	        	            		                 insertarInicio(lista, _dato);
	        	            		            break;


	        	            		            case 2:

	        	            		                 cout<< "\n NUMERO A INSERTAR: "; cin>> _dato;
	        	            		                 insertarFinal(lista, _dato );
	        	            		            break;


	        	            		            case 3:

	        	            		                 cout<< "\n NUMERO A INSERTAR: ";cin>> _dato;
	        	            		                 cout<< " Posicion : ";       cin>> pos;
	        	            		                 insertarElemento(lista, _dato, pos);
	        	            		            break;


	        	            		            case 4:

	        	            		                 cout << "\n\n MOSTRANDO LISTA\n\n";
	        	            		                 reportarLista(lista);
	        	            		            break;


	        	            		            case 5:

	        	            		                 cout<<"\n Valor a buscar: "; cin>> _dato;
	        	            		                 buscarElemento(lista, _dato);
	        	            		            break;

	        	            		            case 6:

	        	            		                cout<<"\n Valor a eliminar: "; cin>> _dato;

	        	            		                eliminarElemento(lista, _dato);
	        	            		            break;

	        	            		            case 7:

	        	            		                cout<<"\n Valor repetido a eliminar: "; cin>> _dato;

	        	            		                eliminaRepetidos(lista, _dato);
	        	            		            break;

	        	            		                    }

	        	            		        cout<<endl<<endl;
	        	            		        system("pause");  system("cls");

	        	            		    }while(op!=8);

	        	            	 break;


	        	            case 2:

	        	            	    cout<<"\n\t\tLISTA DOBLEMENTE ENLAZADA\n\n";
	        	            	    cout<<" 1. INSERTAR              "<<endl;
	        	            	    cout<<" 2. BORRAR                "<<endl;
	        	            	    cout<<" 3. MOSTRAR               "<<endl;
	        	            	    cout<<" 4. SIGUIENTE             "<<endl;
	        	            	    cout<<" 5. ANTERIOR              "<<endl;
	        	            	    cout<<" 6. PRIMER0               "<<endl;
	        	            	    cout<<" 7. ULTIMO               "<<endl;
	        	            	    cout<<" 8. ACTUAL               "<<endl;
	        	            	    cout<<" 9. VALOR ACTUAL             "<<endl;
	        	            	    cout<<" 10. SALIR                            "<<endl;

	        	            	    cin>> op;

	        	            	    switch(op)

	        	            	    {

	        	            	    case 1:

	        	            	    	cout<< "\n NUMERO A INSERTAR: "; cin>> _dato;



	        	            	    	break;

	        	            	    case 2:

	        	            	    	cout<< "\n NUMERO A BORRAR: "; cin>> _dato;



	        	            	    	break;

	        	            	    case 3:

	        	            	    	cout<< "\n MOSTRAR"<<endl;



	        	            	    	break;

	        	            	    case 4:

	        	            	    	cout << "\n\n MOSTRANDO LISTA\n\n";

	        	            	    	reportarLista(lista);

	        	            	    	break;

	        	            	    case 5:

	        	            	    	cout<<"\n Valor a buscar: "; cin>> _dato;

	        	            	    	buscarElemento(lista, _dato);

	        	            	    	break;

	        	            	    case 6:

	        	            	    	cout<<"\n Valor a eliminar: "; cin>> _dato;

	        	            	    	eliminarElemento(lista, _dato);

	        	            	    	break;

	        	            	    case 7:

	        	            	    	cout<<"\n Valor repetido a eliminar: "; cin>> _dato;

	        	            	    	eliminaRepetidos(lista, _dato);

	        	            	    	break;

	        	            	    }

	        	            	    break;


	        	            case 3:

	        	            	lista = NULL;
	        	            	    int op;     // opcion del menu


	        	            	    system("color 0a");

	        	            	    do
	        	            	    {
	        	            	        menu2();
	        	            	        cin>>op;

	        	            	        switch(op)
	        	            	        {
	        	            	            case 1:
	        	            	                    insertarInicio();
	        	            	                    break;

	        	            	            case 2:
	        	            	                    insertarFinal();
	        	            	                    break;
	        	            	            case 3:
	        	            	                    cout<<"\n\n Lista Circular \n\n";
	        	            	                    mostrar();
	        	            	                    break;

	        	            	            case 4:
	        	            	                    buscarElemento();
	        	            	                    break;

	        	            	            case 5:
	        	            	                    eliminarElemento();
	        	            	                    break;
	        	            	            case 6:
	        	            	                    eliminarElementos();
	        	            	                    break;

	        	            	            default: cout<<"OPCION NO VALIDA...!!!";
	        	            	                     break;


	        	            	        }

	        	            	        cout<<endl<<endl;
	        	            	        system("pause");
	        	            	    }while(op!=7);


	        	            	break;

	        	            case 4:
	        	            	cout<<"\n\t\tPILA ESTATICA\n\n";
	        	            	cout<<" 1. PONER                "<<endl;
	        	            	cout<<" 2. SACAR               "<<endl;
	        	            	cout<<" 3. PILA VACIA              "<<endl;
	        	            	cout<<" 4. ENSEÑAR LISTA               "<<endl;
	        	            	cout<<" 5. VACIAR LISTA                "<<endl;
	        	            	cout<<" 6. SALIR                "<<endl;
	        	            	cin>> op;
	        	            	struct nodo *tope;
	        	            	    crearPila(&tope);
	        	            	switch (op){
	        	            	case 1:
	        	            		cout<<"\nIngrese un valor: ";
	        	            		    cin>>dato;
	        	            		    poner(&tope, dato);
	        	            		break;
	        	            	case 2:
	        	            		if(vacia(&tope) != 0) {
	        	            		        dato = sacar(&tope);
	        	            		        cout<<"\nTOPE de la pila: "<<dato<<endl;
	        	            		    }
	        	            		break;
	        	            	case 3:
	        	            		//confirmo que esta vacia
	        	            		    if(vacia(&tope) == 0)
	        	            		        cout<<"Pila VACIA   "<<endl;
	        	            		    else
	        	            		        cout<<"Pila NO VACIA"<<endl;
	        	            		break;
	        	            	case 4:
	        	            		//recorro la píla
	        	            		recorrerPila(&tope);
	        	            		break;
	        	            	case 5:
	        	            		//vacio la pila
	        	            		    while(vacia(&tope) != 0) sacar(&tope);
	        	            		break;
	        	            	default: cout<<"OPCION NO VALIDA...!!!";
	        	                    }
	        	            	break;

	        	            case 5:
	        	            	cout<<"\n\t\tPILA ESTATICA\n\n";
	        	            	cout<<" 1. INSERTAR               "<<endl;
	        	            	cout<<" 2. ELIMINAR              "<<endl;
	        	            	cout<<" 3. ENSEÑAR LISTA               "<<endl;
	        	            	cout<<" 4. BUSCAR                "<<endl;
	        	            	cout<<" 5. SALIR                "<<endl;
	        	            	cin>> op;
	        	            	crear(&ent);
	        	            	switch (op){

	        	            	case 1:

	        	            		cout<<"\nIngrese un valor: ";

	        	            		cin>>dato;

	        	            		insertar(&tope, dato);

	        	            		break;

	        	            	case 2:

	        	            		cout<<"\nIngrese un valor a eliminar: ";
	        	            		cin>>dato;
	        	            		if(vacia(&tope) != 0) {

	        	            			dato = eliminar(&tope, dato);
	        	            			cout<<"Elemento eliminado: " << dato<<endl;
	        	            		}else{
	        	            			cout<<"Elemento no encontrado" <<endl;
	        	            		}

	        	            		break;

	        	            	case 3:
	        	            		//recorro la lista
	        	            		recorrerLista(&tope);
	        	            		break;
	        	            	case 4:

	        	            		cout<<"Ingrese dato a buscar: ";
	        	            		    cin>>dato;
	        	            		    if(buscar(&ent,dato) == 1)
	        	            		        cout<<"numero "<<dato<<" encontrado";

	        	            		break;


	        	            	default: cout<<"OPCION NO VALIDA...!!!";

	        	            	}

	        	            break;

	        	            case 6:

	        	            	cout<<"\n\t\tCOLA ESTATICA\n\n";
	        	                cout<<" 1. INSERTAR               "<<endl;
	        	                cout<<" 2. ELIMINAR              "<<endl;
	        	                cout<<" 3. VACIAR COLA               "<<endl;
	        	            	cout<<" 4. ENSEÑAR COLA                "<<endl;
	        	            	cout<<" 5. SALIR                "<<endl;
	        	            	cin>> op;
	        	            	struct nodo *sal;
	        	            		crearCola(&ent, &sal);

	        	            		switch (op){
	        	            		case 1:
	        	            			int dato;
	        	            			cout << "\nIngrese dato: ";
	        	            			cin >> dato;
	        	            			while(dato!=0) {
	        	            				ponerCola(&ent, &sal, dato);
	        	            				cout << "\nIngrese dato: ";
	        	            				cin >> dato;
	        	            			}
	        	            			break;
	        	            		case 2:
	        	            			sacarCola(&sal,&ent);
	        	            			break;

	        	            		case 3:

	        	            			if(vacia(&ent)==0) {
	        	            					dato=sacarCola(&sal,&ent);
	        	            					cout<<dato<<" ";
	        	            				}

	        	            			break;

	        	            		case 4 :

	        	            			recorrerCola(&ent, &sal);

	        	            			break;
	        	            		}

	        	            break;
	        	        }

	        	        cout<<endl<<endl;



	   return 0;
}
