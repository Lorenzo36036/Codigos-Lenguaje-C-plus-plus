#include <iostream>\


using namespace std;


struct nodo{
	int dato;
	struct nodo *liga_vertice;
    struct nodo *liga_arista;
    
};

typedef struct nodo *registro;
registro sig_ver,ant_ver,cab_ver, sig_ari,ant_ari,dir1,dir2;



registro nuevo_vertice(int dato){
	
	registro reg_ver = new (struct nodo);
	reg_ver->dato = dato;
	reg_ver->liga_vertice = NULL;
	reg_ver->liga_arista = NULL;
	return reg_ver;
	
}


void insertarVertice(int dato){

	int sw = 0;
	ant_ver = cab_ver;
	sig_ver = cab_ver;
	
	// verifica si el elemento existe
	while(sig_ver != NULL && sw == 0){
		
		if(sig_ver->dato == dato){
			sw = 1;  //marca que existe
	
		}else{ //recorre el grafo
			ant_ver = sig_ver;
			sig_ver = sig_ver->liga_vertice;
		}
		
		
	}
	
	if(sw){
		cout << "\nvertice ya existe";
	}else{
		if(cab_ver == NULL){
			cab_ver =  nuevo_vertice(dato);
		}else{
			ant_ver->liga_vertice = nuevo_vertice(dato);
		}
	cout << "\nvertice adicionado";	
		
	}
}

registro recorrer_vertice(int dato){
	registro dir;
	dir = NULL;
	sig_ver = cab_ver;
	
	while(sig_ver != NULL){
		if(sig_ver->dato == dato){
		 dir = sig_ver;	
		}
		sig_ver = sig_ver->liga_arista;
	}
	return dir;
}

registro nueva_arista(int dato){
	registro reg_ari = new (struct nodo);
	reg_ari->dato = dato;
	reg_ari->liga_arista = NULL;
	reg_ari->liga_vertice = dir2;
	 return reg_ari;
}

void insertarArista(int datoArista){
int pes, sw2 = 0;
ant_ari = dir1;
sig_ari	= dir1;

while(sig_ari != NULL && sw2 != 1){
 if(sig_ari->dato == datoArista){
 	sw2 = 1;
 }else{
 	ant_ari = sig_ari;
 	sig_ari = sig_ari->liga_arista;
 }
 
 }

if(sw2){
	cout << "Arista ya existe no adiccionada";
}else{
	cout << "Digite el peso de arista";
	cin >> pes;
	ant_ari->liga_arista = nueva_arista(pes);
	
}




}


void verLista(){
	cout << "ver Nodo y sus aristas\n";
	sig_ver = cab_ver;
	 while(sig_ver != NULL){
	 	cout << "\n El NODO";
	 	cout << sig_ver->dato;
	 	cout << " tiene arista en sus siguientes vertices";
	 	sig_ari = sig_ari->liga_arista;
	 	
	 	while(sig_ari != NULL){
	    cout << " ";
	    dir1 = sig_ari->liga_vertice;
	 	cout << dir1->dato;
	 	sig_ari = sig_ari->liga_arista;
	 }
	 	
	 	sig_ver = sig_ver->liga_vertice;
	 }
	 
}




int main(){
	

		
		
	int vertice, verticeDestino;
	//para agregar el vertice
	cout << "\ninserta el vertice:"; 
	cin >> vertice;
	insertarVertice(vertice);
	
		cout << "\ninserta el vertice:"; 
	cin >> vertice;
	insertarVertice(vertice);
	
	
    // para agregar arista
	cout << "\ninserta el vertice de origen:"; 
	cin >> vertice;
	cout << "\nInsera la vertice  de destino:"; 
	cin >> verticeDestino;
	dir1 =  recorrer_vertice(verticeDestino);
	dir2 =  recorrer_vertice(verticeDestino);
	if(dir1 == NULL || dir2 == NULL ){
		cout << "\nNodo origen o destino no existe";
	}else{
		insertarArista(verticeDestino);
	}
	
	verLista();
	
	
	
	
	
	
	//para mostrar
	
	
	
	return 0;
}

