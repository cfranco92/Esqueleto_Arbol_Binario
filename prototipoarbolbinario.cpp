#include <iostream>
#include <string>
using namespace std;

class Nodo{
   private:
     string valor;
     Nodo *izq;
     Nodo *der;

   friend class ArbolBB;

   public:
     Nodo(string valor, Nodo *izq=NULL, Nodo *der=NULL){
         this->valor = valor;
         this->izq = izq;
         this->der = der;
     }
};

typedef Nodo *NodoArbol; //Arbol Binario de Busqueda

class ArbolBB{
   private:
     NodoArbol raiz;
   public:
     //NodoArbol raiz;
     ArbolBB(){
        this->raiz = NULL;
     }
     ~ArbolBB(){};
     NodoArbol getRaiz();
     void insertar(NodoArbol &subArbol, string valor);
     void verArbol(NodoArbol subArbol, int nivel=0);
     void preOrden(NodoArbol subArbol);
     void enOrden(NodoArbol subArbol);
     void postOrden(NodoArbol subArbol);
};

NodoArbol crearNodo(string valor){
     NodoArbol nuevoNodo = new Nodo(valor);
     return nuevoNodo;
}


NodoArbol ArbolBB::getRaiz(){
    return this->raiz;
}

void ArbolBB::insertar(NodoArbol &subArbol, string valor){
     if (this->raiz == NULL){ //el arbol esta vacio
         this->raiz = crearNodo(valor);
         return;
     }
     if(subArbol==NULL){ //el nodo es una hoja
           subArbol = crearNodo(valor);
     }
     else if(valor < subArbol->valor)
          insertar(subArbol->izq, valor);
     else if(valor > subArbol->valor)
          insertar(subArbol->der, valor);
}

void ArbolBB::borrar(NodoArbol &subArbol, string valor){
  if(this->raiz != NULL){
    if(subArbol == NULL){
      this->raiz == NULL:
    }
  }

}

void ArbolBB::preOrden(NodoArbol subArbol){
     if(subArbol!=NULL){
          cout << subArbol->valor <<" ";
          preOrden(subArbol->izq);
          preOrden(subArbol->der);
     }
}


void ArbolBB::enOrden(NodoArbol subArbol){
     if(subArbol!=NULL){
          enOrden(subArbol->izq);
          cout << subArbol->valor << " ";
          enOrden(subArbol->der);
     }
}

void ArbolBB::postOrden(NodoArbol subArbol){
     if(subArbol!=NULL){
          postOrden(subArbol->izq);
          postOrden(subArbol->der);
          cout << subArbol->valor << " ";
     }
}

void ArbolBB::verArbol(NodoArbol subArbol, int nivel){
     if(subArbol==NULL)
          return; //el arbol esta vacio
     verArbol(subArbol->der, nivel+1);
     for(int i=0; i<nivel; i++)
         cout<<"   ";  //espacios que ayudan a visualizar el arbol
     cout<< subArbol->valor <<endl;
     verArbol(subArbol->izq, nivel+1);
}

int main(){
    ArbolBB arbol;
    int nNodos;  // numero de nodos del arbol
    string valor; // elemento a insertar en cada nodo

    cout << "\n====[ ARBOL BINARIO DE BUSQUEDA ]======================\n" << endl;
    cout << " Numero de nodos del arbol:  ";
    cin >> nNodos;
    cout << endl;

    for(int i=0; i<nNodos; i++){
        cout << " Valor del nodo " << i+1 << ": ";
        cin >> valor;

        NodoArbol raizArbol = arbol.getRaiz();
        arbol.insertar(raizArbol, valor);
    }

    cout << "\n Mostrando ABB \n\n";
    arbol.verArbol( arbol.getRaiz());

    cout << "\n Recorridos del ABB";
    cout << "\nEn orden   :  ";
       arbol.enOrden(arbol.getRaiz());
    cout << "\nPre Orden  :  ";
       arbol.preOrden(arbol.getRaiz());
    cout << "\nPost Orden :  ";
       arbol.postOrden(arbol.getRaiz());

    cout << endl << endl;
    return 0;
}
