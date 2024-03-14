#include <stdio.h>
#include <conio.h>
#include <windows.h>


int leerPosicion(int *y,int *x,int *y2, int *x2){
	 fflush(stdin);
	 printf("\n \n Escribe el primer numero de fila y columna a elegir \n");
	 
     scanf("%d",&*y);
     if(*y == 120){
     system("cls");		
     return 0;
     }
     scanf("%d",&*x);
      if(*x2 == 120){
      system("cls");	
      return 0;
     }
     printf("\n \n Escribe el segundo numero de fila y columna a elegir \n");
     scanf("%d",&*y2);
      if(*y2 == 120){
    system("cls");	
      return 0;
     }
     scanf("%d",&*x2);
	 if(*x2 == 120){
	 system("cls");		
     return 0;
     }  
	 
}

void imprimirVector(int vector1[7][6], int num,char vector2[7][7]){	
int i,j;
for(i = 0; i <  2 + num ; i++){
	printf ("\n\n");
    for(j = 0; j < 1 + num; j++){
	  printf("  ");
	  
	 if (vector1[i][j] == vector2[i][j]){
   	 printf("\t[%c]",vector2[i][j]);
   }
	else{
      printf("\t[%d]", vector1[i][j]);
   }
     }
   }
 }
 
 void imprimirVector2(char vectorcpy[7][7],int num){
	     printf("\t!!Memoriza!! \n \n");
         for(int i = 0; i < 2 + num; i++){
        	printf("\n\n");
          for(int j = 0; j < 1 + num ; j++){
          printf("\t[%c]", vectorcpy[i][j]);
       }
    }
}
 
 void contador(int segundos){
     int result = 1;
	 result = segundos;
	printf("\n \n \n TIEMPO:");
	while(result != 0){
    result -= 1;
    printf(" %d",result);
    Sleep(1000);
	}  
}

int validacion(int validar, int *intentos, int puntuaje){  
	  if(validar == -1){	
       *intentos -= 1;
	   if(*intentos == 0){
	   system("cls");
	   printf("JUEGO TERMINADO TU PUNTUACION FUE DE %d \n\n",puntuaje); 
	   system("pause");
	   system("cls");   
	   return 0;    
	   } 	
    }
  }
  
void puntuacion(int *puntos, int limite){
     *puntos +=  100; 	
     printf("Points:%d \n\n", *puntos);	
     system("pause");
	if(*puntos == limite){
		system("cls");
		printf("FELICIDADES JUGADOR POR PASAR EL NIVEL \n EN HORA BUENA PUNTUACION PERFECTA \n");	  
		system("pause");
		system("cls");	
	}
	
}



int mostrarPosicion(char vector2[7][7],int vector[7][6],int f,int c,int f2,int c2,int num, int *validar, char vectorCPY[7][7]){
	 int i,j;
	 char var1,var2;
	 for(i = 0; i < 2 + num; i++){
	 printf("\n\n");
     for(j = 0; j < 1 + num;j++){ 	 		 
	  if (i + 1 == f && j + 1 == c){		
	  var1 = vector2[i][j];	  
 	  printf("\t[%c]", var1);    
     }
      else if(i + 1 == f2  && j + 1 == c2){	
	   var2 = vector2[i][j];	    
	   printf("\t[%c] ",var2);
	   }	 
	
	  else if (vector[i][j] == vector2[i][j]){
	  
	  printf("\t[%c]", vector[i][j]);
	  }
	 
	  else{
	   	printf("\t[%d]", vector[i][j]);
	  }
	  
	   
	
   }
}

  for( i = 0; i < 2 + num; i++){
   	
       for( j = 0; j < 1 + num; j++){ 	    
		 if(var1 == vector[i][j] && var2 == vector[i][j]){	
        printf("\n\n  insertastes el mismo par \n");
        *validar = 2;
		system("pause");		   
        return 0;
        }
  }
}

       for( i = 0; i < 2 + num; i++){	
       for( j = 0; j < 1 + num; j++){ 	    	
		if(var1 == var2){ 
	    printf("\n\n Correcto ");
	    *validar = 1;
	    break;
       }        	
        else{
        printf("\n\n Incorrecto \n "); 
        *validar = -1;  
		system("pause");    	
	    break; 
	    }    
	  
   }
   break;
}
      
      
      
       for( i = 0; i < 2 + num; i++){ 	
       for( j = 0; j < 1 + num; j++){ 
       
       
       
        if(var1 == var2 && i + 1 == f && j + 1 == c){      	 
   	     vector[i][j] = var1 ; 	    
   	     
         }           
        else if(var1 == var2 && i + 1 == f2 && j + 1 == c2)      
         vector[i][j] = var2;
   
	     }
	   }
        
       
       for( i = 0; i < 2 + num; i++){ 	
       for( j = 0; j < 1 + num; j++){ 
        if(var1 == var2 && i + 1 == f && j + 1 == c){
   	       vectorCPY[i][j] = ' ';
         }  
         
         else if(var1 == var2 && i + 1 == f2 && j + 1 == c2) 
         vectorCPY[i][j] = ' ';
	     
		 }
    
	   }
         
  }
  
 
 
 

int main(){	 

char seleccion1,seleccion2;	
int vector1[7][6] ={{1,2,3,4,5,6},{7,8,9,10,11,12}, {13,14,15,16,17,18},{19,20,21,22,23,24},{25,26,27,28,29,30},{31,32,33,34,35,36},{37,38,39,40,41,42}};
char vector2[7][7] ={"AEFLYJ","WQXZUS","FEAGIJ","QWXOPK","LGZOUK", "IPGZYV","MNMSVN"};
char vectorCPY[7][7] ={"AEFLYJ","WQXZUS","FEAGIJ","QWXOPK","LGZOUK", "IPGZYV","MNMSVN"};
while (seleccion1 != '4'){	
int puntuaje = 0;
int y,x,y2,x2,validar, intentos = 0;

char atras = '\0';
printf("Play Of Memorize \n\n");	
printf("1-Jugar \n");	   
printf("2-Instrucciones \n");
printf("3-Creditos \n");
printf("4-salir \n");
fflush(stdin);
seleccion1 = getche();
system("cls");	
    if(seleccion1 == '1'){
	printf("Seleccione el nivel \n");
	printf("0-Nivel 0 \n");
	printf("1-Nivel 1 \n");
	printf("2-Nivel 2 \n");
	printf("3-Nivel 3 \n");
	printf("4-Volver");
	fflush(stdin);
    seleccion2 = getche();
    system("cls");
      if(seleccion2 == '4'){
       continue;
      }
    } 
     if(seleccion2 == '0'){  
	   intentos = 3;
	  do{  	 	  
     system("cls"); 
     printf(" Nivel 0 \n\n\n "); 
     imprimirVector2(vectorCPY,2);
	 contador(5);
	 system("cls");   
	 printf("para regresar al menu escribe 120 \n");
	 printf("Tienes %d intentos \n",intentos);
	 printf("Tienes %d Points  Objetivo a conseguir:600 \n\n",puntuaje); 
	 imprimirVector(vector1,2,vector2);
     if(leerPosicion(&y,&x,&y2,&x2) == 0){
      return main();	 
	 }
     mostrarPosicion(vector2,vector1,y,x,y2,x2,2,&validar,vectorCPY); 
	 
	 
	 if(validar == 1){
     puntuacion(&puntuaje,600);
     }
     
    if(validacion(validar,&intentos,puntuaje) == 0){
    	return main();
	}
   	
        
     }while(puntuaje < 600);  
      return main();       		
	
	}
	
    if (seleccion2 == '1'){
      intentos = 4;
	
	do{
  	system("cls"); ; 	
    printf("Nivel 1 \n\n\n "); 
      imprimirVector2(vectorCPY,3);   
      contador(5);
	  system("cls"); 
	  printf("Escribe 120 para regresar al menu \n");
      printf("Tienes %d intentos \n",intentos);
	  printf("Tienes %d Points Objetivo a conseguir:1000 \n\n",puntuaje);
      imprimirVector(vector1,3,vector2);
      if(leerPosicion(&y,&x,&y2,&x2) == 0){
       return main();	
	   }	   
      mostrarPosicion(vector2,vector1,y,x,y2,x2,3,&validar,vectorCPY); 
      if(validar == 1){
       puntuacion(&puntuaje,1000);
         }
         
         
       if(validacion(validar,&intentos,puntuaje) == 0){
    	return main();
	    }
   	  
	   } while(puntuaje < 1000);   
   
	 
	 }
  
    if(seleccion2 == '2'){
  	 int  intentos = 6;
  	do{
  	 system("cls");
  	 printf("Nivel 2 \n\n\n");
     imprimirVector2(vectorCPY,4);   
     contador(5);
	 system("cls"); 
	 printf("para regresar al menu escribe 120 \n");
     printf("Tienes %d intentos \n",intentos);
	 printf("Tienes %d Points Objetivo a conseguir:1600 \n\n",puntuaje);
     imprimirVector(vector1,4,vector2);
     if(leerPosicion(&y,&x,&y2,&x2) == 0){
      return main();	
	 }
     mostrarPosicion(vector2,vector1,y,x,y2,x2,4,&validar,vectorCPY); 
     if(validar == 1){
     puntuacion(&puntuaje,1600);
     }
      if(validacion(validar,&intentos,puntuaje) == 0){
    return main();
	 }
   	   	
     }while(puntuaje < 1600);  
    }

    
  if(seleccion2 == '3'){
  	 int  intentos = 8;
  	do{
  	 system("cls");
  	 printf("Nivel 3 \n\n\n");
     imprimirVector2(vectorCPY,5); 
	 contador(5);
	 system("cls");  
	 printf(" Para regresar al menu escribe 120 \n");
     printf("\n Tienes %d intentos \n",intentos);
	 printf("Tienes %d Points Objetivo a conseguir:2100 \n\n",puntuaje);
     imprimirVector(vector1,5,vector2);
     if(leerPosicion(&y,&x,&y2,&x2) == 0){
      	return main();
	 }
     mostrarPosicion(vector2,vector1,y,x,y2,x2,5,&validar,vectorCPY); 
     
     if(validar == 1){
     puntuacion(&puntuaje,2100);
      }
     
	 if(validacion(validar,&intentos,puntuaje) == 0){
    	return main();
	}
   	
	 
    }while(puntuaje < 2100); 
    return main(); 
  }  
  system("cls");
  

if(seleccion1 == '2'){
	while(atras != 'a'){
	printf(" 1.-Para seleccionar el numero que esta ocultando la letra se le pedira \n la fila y luego la columna para mostrar la letra y lo mismo para mostrar \n el otro numero.");	
    printf("\n\n 2.-Tendras 4s para memorizar los pares.");
    printf("\n\n 3.- Si colocas una fila o columna que no existe se te deduce intentos.");
    printf("\n\n 4.- si acertastes los pares hiran desapareciendo y a su vez \n  los  numeros hiran mostrando los pares encontrados.");
    printf("\n\n 5.- Para seleccionar la fila se selecciona de 1 pa bajo la coulumnas de 1 pa derecha");
    printf("\n\n 6.- Para que se te haga facil  utliza el mouse \n como un guia para recordar un par.");
	printf("\n\n A.-atras");
	fflush(stdin);
    atras = getche();  
    system("cls");
	  }
}

if(seleccion1 == '3'){
	while(atras != 'a'){
  	printf("\n ********Desarrolladores********** \n LorenzoParra \n Daniel Nunez \n\n\n\n");
  	printf("A.-atras");
     atras = getche();
     system("cls");
    }
  }
 
if (seleccion1 == '4'){
printf(" \n Presiona cualquier boton para salir! :)");
return 0;
   }

 }
 
}
  

