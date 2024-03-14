#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#include <conio.h>


enum {MINA_ENCONTRADA = 1, ESPACIO_DESCUBIERTO = 2};

enum {FILAS = 9, COLUMNAS = 9};

const char CASILLAS_SINDESCUBIR = '#', CASILLAS_DESCUBIERTAS = ' ', MINA = 'X';



int jugarNivel(int, int,int,int);

int imprimirArchivo();


int aleatorio(int,int);

void llenarTablero(char[FILAS][COLUMNAS],int,int,int);


void encabezadoDeTablero(int,int);

void imprimirTablero(char[FILAS][COLUMNAS], int,int,int);

int verificarMinas(char[FILAS][COLUMNAS],int,int,int,int);


int interactuarConCasillas(int,int,char[FILAS][COLUMNAS]);


int noHayCasillas(char[FILAS][COLUMNAS],int,int);
	
	




int main(){ 
  int totalMinas = 1,f = 2,c = 2;
  
  int opcion = 0;
   	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("  BY :ParraLorenzo\n");
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);  
   
  
  	printf("\n\n\t\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("\t\t ****** BUSCA MINAS ****\n");
	printf("\t\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
	

	printf("\t\t\t NIveles \n\n");
	printf("\t\t\t1.-nivel 1 \n \t\t\t2.-nivel 2 \n \t\t\t3.-nivel 3");
    printf("\n\n\n\t\tDigite el nivel:[ ]\b\b");
    scanf("%d",&opcion);
	 			 
   

	 if(opcion == 1){
	 	totalMinas += 2;
	  f += 3;c += 3;
	  jugarNivel(1,totalMinas,f,c);		
	 }
	 
	 
	 if(opcion == 2){
	 	totalMinas += 5;
	  f += 4;  c += 4;	 	
	 jugarNivel(2,totalMinas,f,c);		
		
	 	
	 } 
	
	
	 if(opcion == 3){
	 	totalMinas += 7;
	  f += 7; c += 7;	
	 jugarNivel(3,totalMinas,f,c);		
	 }
	

 
  return 0;
}






int jugarNivel(int nivel, int totalMinas,int f ,int c){
	system("cls");
	imprimirArchivo();
	printf("\n\nERES UNO DE LOS ESCUADRONES ANTI TERRORISTAS DEBES DESPEJAR TODAS LAS ZONAS DEL EDIFICIO Y EVITAR LAS MINAS  QUE ESTAN UBICADAS EN LA PLANTA NUCLEAR [%c] \nDEBES EVITAR QUE EXPLOTEN O SINO...MILLONES DE PERSONAS,,,, MORIRAN\n\n",64 + nivel);
	system("pause");
	int mostrarMinas = 0,fila,columna,estado;
	char tablero[FILAS][COLUMNAS]; 
	system("cls");
	printf("\nPLANTA [%c]\n\n\n\n",64+nivel);
	srand(getpid());
    llenarTablero(tablero,totalMinas, f, c);


     system("color 0E");
   

	while(1){		
	 
	  if(getch() == 27) {
	  system("cls");
	  system("color 0f");
	  return main();
      }
      
    imprimirTablero(tablero,mostrarMinas,f,c);
	if(mostrarMinas == 1){
		break;
	}

    printf("\n\nDigite la fila:");
    fflush(stdin);
    scanf("%d",&fila);

    printf("\n\nDigite la columna:");  
    fflush(stdin);
    scanf("%d",&columna);
    system("cls");
    
	estado = interactuarConCasillas(fila,columna,tablero);
    
   
	if(noHayCasillas(tablero,f,c)){
	    system("cls");
	    system("color 0A");
      printf("!SOBREVIVISTE! \n\n ");
      mostrarMinas = 1;
	}
	
	 else if(estado == MINA_ENCONTRADA){
	 	system("cls");
		system("color 0c");
		printf("!EXLOTASTES LAS MINAS! \n\n");		
	    mostrarMinas = 1;
	}
		 
		
		}
		
		
  	  
    return 0;
    

 }
 
 
 
 
 int imprimirArchivo(){
FILE * flujo = fopen("plantaNuclear.txt","r");
   if(flujo == NULL){
   	perror("ERROR EN LA APERTURA DEL ARCHIVO");
   	return 1;
   }

char  caracter[100];
while(!feof(flujo)){
    fgets(caracter,100,flujo);
	printf("\t\t%s",caracter);
}
system("color 0E");
fclose(flujo);

}


 

int aleatorio(int minimo,int maximo){
	return rand() % ((maximo + minimo) + 1);
	
}
  


void llenarTablero(char tablero[FILAS][COLUMNAS],int totalMinas,int f,int c){

	for(int i = 0; i < f; i++){	
		for(int j = 0; j < c; j++){
		tablero[i][j] = CASILLAS_SINDESCUBIR;	
	
		}
	}
	


  	int fila,columna;
	for(int i = 0; i < totalMinas; i++){
		fila =  aleatorio(0, f - 1) ;
		columna = aleatorio(0, c - 1);
		tablero[fila][columna] = MINA;
		
	}


		
}



void encabezadoDeTablero(int f,int c){
      printf("  ");
	for(int i = 0; i < c; i++){
		printf(" | %d",i + 1);
	  if(i + 1 == c)
	  printf(" | ");	
     

	}
	printf("\n");
	
	for(int i = 0; i <= f; i++ ){
    	printf("----");
		}
		
	
	
}

 void imprimirTablero(char tablero[FILAS][COLUMNAS],int mostrarMinas,int f, int c){
     printf("\n");
	encabezadoDeTablero(f,c);
    
    
   	for(int i = 0; i < f ; i++){
   	printf("\n %d ", i + 1);
   	
    for(int j = 0; j < c ; j++){
    	

 	char sinDescubrir = CASILLAS_SINDESCUBIR;
	  
	char letraActual = tablero[i][j];
 	
 	if(letraActual == MINA)
	sinDescubrir = CASILLAS_SINDESCUBIR;
	
	else if(letraActual == CASILLAS_DESCUBIERTAS){
		int minasCercanas = verificarMinas(tablero,i,j,f,c);
		 sinDescubrir =  minasCercanas + '0';
		
		
	}
    if(letraActual == MINA && mostrarMinas)
   	sinDescubrir = MINA;
     
     
    printf("| %c ",sinDescubrir);
    
    
    if(j + 1 == c){
     printf("|");	
    	
	
	 }

	}
	
	printf("\n");
  

   
      }
   
   }
   
    
   
   
 int verificarMinas(char tablero[FILAS][COLUMNAS],int fila,int columna,int f, int c){
 	
 	int cont = 0, filaI, filaF,columnaI,columnaF;
 	
 	if(fila == 0)
 	  filaI = 0;
 	else
 	    filaI = fila - 1;
 	    
 	    
 	    
  if(fila + 1 >= f)
    filaF = f - 1;
	else
	filaF = fila + 1;	
	
	
  if(columna == 0)
  columnaI = 0;
  else
  columnaI = columna - 1;	
  
	if(columna + 1 >= c)
	columnaF = c - 1;
	else
		columnaF = columna + 1;
	
	
	for(int i = filaI; i <= filaF; i++){
		for(int j = columnaI; j <= columnaF; j++){
			if(tablero[i][j] == MINA)
			cont++;
		}
	}
 	
 	
 	return cont;
 	
 }  
   
   
   
   
 int interactuarConCasillas(int fila,int columna, char tablero[FILAS][COLUMNAS]){
 
 columna--;	
 fila--;

 	
 
  if(tablero[fila][columna] == MINA){
  	return MINA_ENCONTRADA;
  	
  }
  
  else{
  tablero[fila][columna] = CASILLAS_DESCUBIERTAS;
  return 0;
  }
 	
 }  
 
 
 
 
 int noHayCasillas(char tablero[FILAS][COLUMNAS],int f,int c){
 	for(int i = 0; i < f; i++){
 		for(int j = 0; j < c; j++){
	    if(tablero[i][j] == CASILLAS_SINDESCUBIR)
	     return 0;	 
	 }
	}
	return 1;
 }
   
