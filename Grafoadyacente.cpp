#include <iostream>
#define MAXVERTICES 3


typedef int VERTICE;




using namespace std;


class Grafo{
	private:
		int grafo[MAXVERTICES][MAXVERTICES];
    public:
    	Grafo(){
    		for(VERTICE i = 0; i < MAXVERTICES; i++){
    			for(VERTICE j = 0; j < MAXVERTICES; j++){
    				grafo[i][j] = 0;
				}
			}
		};
		
      bool	insertarVertice(VERTICE v1, VERTICE v2){
		int v = 0;
		//Esta variable se utilizará para recorrer los vértices del grafo para verificar si ya existe un arco en la posición específica
		if(v1 >= MAXVERTICES || v2 >= MAXVERTICES || grafo[v1][v2] > 0 ){
			return false;
		}
		 grafo[v1][v2]++;
		 if(v1 != v2)
		 	grafo[v2][v1]++;	
		 	return true;
		}
		
	
		
	  int	grado(VERTICE v){
	  	 int grado = 0;
	  	 
	  	 for(VERTICE v1 = 0; v1 = MAXVERTICES; v1++){
	  	 	if(grafo[v][v1] > 9){
	  	 		if(v == v1){
	  	 			grado += 2;
				   }else{
				   	grado++;
				   }
				   return grado;
			   }
		   }
	  
		}
		
	 void imprimir(){
	 	    for (VERTICE i = 0; i < MAXVERTICES; i++) {
             for (VERTICE j = 0; j < MAXVERTICES; j++) {
            cout << grafo[i][j] << "  ";
          }
        cout << endl;
       }
	 	
	 }	
};


int main(){
    Grafo grafo;
    //FILA VERTICE, CONEXION DEL ARCO, COLUMNA DEL ARCO      
    grafo.insertarVertice(0, 1); // Inserta un arco entre los vértices 0 y 1
    grafo.insertarVertice(1, 2); // Inserta un arco entre los vértices 1 y 2
    grafo.insertarVertice(0, 2); // Inserta un arco entre los vértices 0 y 2
    grafo.imprimir();
     


	return 0;
}

