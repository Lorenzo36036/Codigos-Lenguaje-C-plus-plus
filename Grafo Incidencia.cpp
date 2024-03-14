#include <iostream>
#define MAXVERTICES 3
#define MAXARCOS 5

typedef int VERTICE;
typedef int ARCO;



using namespace std;


class Grafo{
	private:
		int grafo[MAXVERTICES][MAXARCOS];
    public:
    	Grafo(){
    		for(VERTICE i = 0; i < MAXVERTICES; i++){
    			for(ARCO j = 0; j < MAXARCOS; j++){
    				grafo[i][j] = 0;
				}
			}
		};
		
      bool	insertarVertice(VERTICE v1, VERTICE v2,ARCO a){
		int v = 0;
		
		//Esta variable se utilizará para recorrer los vértices del grafo para verificar si ya existe un arco en la posición específica
		if(v1 >= MAXVERTICES || v2 >= MAXVERTICES || a >= MAXARCOS ){
			return false;
		}
		
		while(v < MAXVERTICES && grafo[v][a] == 0)
		 v++;
		 
		 if(v >= MAXVERTICES){
		 	grafo[v1][a]++;
		 	grafo[v2][a]++;
		 	return true;
		 }
		 
		 return false;
		
		}
		
	  bool adyacente(VERTICE v1, VERTICE v2){
	  	ARCO e = 1;
	  	if(v1 >=  MAXVERTICES || v2 >= MAXVERTICES )
	  	 return false;
	  	 
	  	 while(e < MAXARCOS){
	  	 	if(grafo[v1][e] > 0 && grafo[v2][e] > 0)
	  	 		return true;
			   
			  e++; 
		   }
		   return false;
		   
	  }
		
	  int	grado(VERTICE V){
	  	
	  	int grado = 0;
	  	
	  	for(ARCO e = 0; e < MAXARCOS; e++){
	  		if(grafo[V][e] > 0){
	  			grado++;
			  }
			  return grado;
		  }
		}
		
	 void imprimir(){
	 	    for (VERTICE i = 0; i < MAXVERTICES; i++) {
             for (ARCO j = 0; j < MAXARCOS; j++) {
            cout << grafo[i][j] << "  ";
          }
        cout << endl;
       }
	 	
	 }	
};


int main(){
    Grafo grafo;
    //FILA VERTICE, CONEXION DEL ARCO, COLUMNA DEL ARCO      
    grafo.insertarVertice(0, 1, 0);
    grafo.insertarVertice(1, 2, 1);
    grafo.insertarVertice(2, 2, 2);
    grafo.imprimir();
    
	return 0;
}

