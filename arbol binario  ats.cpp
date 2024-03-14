#include <iostream>


using namespace std;

struct Nodo{
int dato;
Nodo *der;
Nodo *izq;
};

Nodo *crearNodo(int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->der=NULL;
	nuevo_nodo->izq=NULL;
	
	return nuevo_nodo;
}

void insertar(Nodo *&arbol, int n){
	if(arbol== NULL){ //si null creamos un nodo
		Nodo *nuevo_nodo = crearNodo(n);
		arbol = nuevo_nodo;
	}else{
		int valorRaiz = arbol->dato;
		
	    if(n < valorRaiz){
	    	insertar(arbol->izq,n);
		}else{
			insertar(arbol->der,n);
		}
	}
}

void mostrarArbol(Nodo *arbol,int contador){
	if(arbol == NULL){
		return;
	}else{
		mostrarArbol(arbol->der,contador+1);
		for(int i=0; i< contador;i++){
			cout << "   ";
		}
	 cout << arbol->dato << endl;
	 mostrarArbol(arbol->izq,contador+1);
	}
	
}



int main(){
	Nodo *arbol = NULL;
	Nodo* abuelo = NULL;
	
	
	int contador = 0;
	
	insertar(arbol,6);
	insertar(arbol,11);
	insertar(arbol,23);
	insertar(arbol,1);
   	insertar(arbol,24);
   	insertar(arbol,10);
	insertar(arbol,4);

	mostrarArbol(arbol,contador);
	



return 0;
}