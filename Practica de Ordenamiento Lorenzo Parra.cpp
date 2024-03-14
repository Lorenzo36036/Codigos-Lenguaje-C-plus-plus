/*PRACTICA DE ORDENAMIENTO 

ALUMNO:
Lorenzo Parra
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <time.h>

int TAMANO = 30000; //TAMAÑO DE LOS ARREGLOS AQUI SE MODIFICA LA CANTIDAD DE BUCLE DEL FOR
using namespace std;
/*---------------------------------------------------------------------------------------------
					FUNCION QUE VERIFICA SI HAY NUMEROS REPETIDOS
----------------------------------------------------------------------------------------------*/
int verificar_repetido(int arreglo[],int num) { //Verificar si hay un numero repetido

	for(int i=0; i< TAMANO ; i++) {
		if(arreglo[i] == num) {
			return 1; //Si existe numeros repetidos regresa 1
		}
	}

	return 0; //Si no detecta un numero repetido repetido retorna 0
}
/*---------------------------------------------------------------------------------------------
				FUNCION QUE RELLENA EL ARREGLO CON NUMEROS ALEATORIOS
----------------------------------------------------------------------------------------------*/
void llenar_arreglo(int arreglo1[], int arreglo2[]) {
	int numero=0;
	int repetido=0;

	srand(time(NULL)); //Habilitando los numeros aleatorios
	for(int i=0; i< TAMANO ; i++) {

		do { //Hacer cuando exista un numero repetido
			numero = rand() % 30001;
			repetido=verificar_repetido(arreglo1,numero);
		} while(repetido);

		arreglo1[i] = arreglo2[i] = numero; //los 6 arreglos seran igual al contenido de numero en la posicion `i`
	}
}

/*---------------------------------------------------------------------------------------------
				FUNCION QUE INVIERTE EL ARREGLO
----------------------------------------------------------------------------------------------*/
void invertirArreglo(int arreglo[]) {
	int aux, j = TAMANO-1;
	for(int i=0; i < j; i++) {
		aux = arreglo[i];
		arreglo[i]=arreglo[j];
		arreglo[j]=aux;
		j--;
	}
}

/*---------------------------------------------------------------------------------------------
				FUNCION QUE PASA LOS ELEMENTOS AL ARRAY ORIGINAL
----------------------------------------------------------------------------------------------*/
void copiar_arreglo(int copia[], int original[]) {
	
	for (int i=0; i < TAMANO ; i++) {
		copia[i] = original[i];		// Copia el arreglo con los datos desordenados
	}
}

/*---------------------------------------------------------------------------------------------
				FUNCION ORDENAMIENTO POR INSERCION
----------------------------------------------------------------------------------------------*/
void ordenamientoInserccion(int arreglo[]) {
	int aux,pos;
	for(int i = 0; i < TAMANO; i++) {
		pos = i;
		aux = arreglo[i];

		while((pos>0) && (arreglo[pos-1] > aux)) {
			arreglo[pos] = arreglo[pos-1];
			pos--;
		}

		arreglo[pos] = aux;
	}
}

/*---------------------------------------------------------------------------------------------
				FUNCION ORDENAMIENTO POR SELECCION
----------------------------------------------------------------------------------------------*/
void ordenamientoSeleccion(int arreglo[]) {
	int aux, num;
	for(int i = 0; i < TAMANO-1; i++) {
		num = i;
		for(int j = i+1; j < TAMANO; j++) {
			if(arreglo[num] > arreglo[j]) {
				num = j;
			}
		}
		if(i != num) {
			aux = arreglo[i];
			arreglo[i] = arreglo[num];
			arreglo[num] =aux;
		}
	}
}

/*---------------------------------------------------------------------------------------------
				FUNCION ORDENAMIENTO BURBUJA
----------------------------------------------------------------------------------------------*/
void ordenamientoBurbuja(int arreglo[]) {
	int aux;
	for(int i = 1; i < TAMANO; i++) {
		for(int j= TAMANO-1; j >= i; j--) {
			if(arreglo[j-1] > arreglo[j]) {
				aux = arreglo[j-1];
				arreglo[j-1] = arreglo[j];
				arreglo[j] = aux;
			}
		}
	}
}

/*---------------------------------------------------------------------------------------------
				FUNCION ORDENAMIENTO BURBUJA MODIFICADO
----------------------------------------------------------------------------------------------*/
void ordenamientoBurbujaModificado(int arreglo[]) {
	bool band;
	int  aux;
	for (int i=1; i < TAMANO; i++) {
		band = false;
		for (int j=TAMANO-1; j>= i; j--) {

			if (arreglo[j-1] > arreglo[j]) {
				aux = arreglo[j-1];
				arreglo[j-1] = arreglo[j];
				arreglo[j] = aux;
				band = true;
			}
		}
		if (!band) break;
	}
}

/*---------------------------------------------------------------------------------------------
				FUNCION ORDENAMIENTO Shellsort
----------------------------------------------------------------------------------------------*/
void ordenamientoShellsort(int arreglo[]) {

	int aux;
	for(int brecha=TAMANO/2; brecha>0; brecha/=2)
		for(int i=brecha; i<TAMANO; i++)
			for(int j=i-brecha; j>=0 && arreglo[j+brecha]<arreglo[j]; j-=brecha) {

				aux=arreglo[j];
				arreglo[j]=arreglo[j+brecha];
				arreglo[j+brecha]=aux;
			}
}

/*---------------------------------------------------------------------------------------------
				FUNCION ORDENAMIENTO quick sort
----------------------------------------------------------------------------------------------*/
void swap(int array[], int a, int b) {
	int t;
	t = array[b];
	array[b] = array[a];
	array[a] = t;
}

int particion(int array[], int inicio, int fin) {
	int pivote = array[inicio];
	int inferior = inicio + 1;
	int superior = fin;

	while (inferior <= superior) {
		while (inferior <= superior && array[inferior] <= pivote)
			inferior++;

		while (inferior <= superior && array[superior] >= pivote)
			superior--;

		if (inferior < superior) {
			swap(array, inferior, superior);
			inferior++;
			superior--;
		}
	}

	swap(array, inicio, superior);
	return superior;
}

void ordenamientoQuickSort(int arreglo[],int inicio, int final) {
	int p;
	if(inicio < final) {
		p = particion(arreglo,inicio,final);
		ordenamientoQuickSort(arreglo,inicio,p-1);
		ordenamientoQuickSort(arreglo,p+1,final);
	}
}

/*---------------------------------------------------------------------------------------------
				FUNCION QUE MIDE EL TIEMPO  - Metodo de Ordenamiento Insercion
----------------------------------------------------------------------------------------------*/
double tiempo_insercion(int copia[]){
	
	auto t1 = std::chrono::high_resolution_clock::now(); //Comienza cronometro 
    ordenamientoInserccion(copia); //Se ordena por el metodo de inserccion
    auto t2 = std::chrono::high_resolution_clock::now(); //Finaliza cronometro
	double t_total = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count();  //Conversion y guarda
	
	return t_total;
}

double tiempo_seleccion(int copia[]){
	
	auto t1 = std::chrono::high_resolution_clock::now(); //Comienza cronometro 
	ordenamientoSeleccion(copia);
    auto t2 = std::chrono::high_resolution_clock::now(); //Finaliza cronometro
	double t_total = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count();  //Conversion y guarda
	
	return t_total;
}

double tiempo_burbuja(int copia[]){
	
	auto t1 = std::chrono::high_resolution_clock::now(); //Comienza cronometro 
	ordenamientoBurbuja(copia);
    auto t2 = std::chrono::high_resolution_clock::now(); //Finaliza cronometro
	double t_total = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count();  //Conversion y guarda
	
	return t_total;
}

double tiempo_burbujaModificado(int copia[]){
	
	auto t1 = std::chrono::high_resolution_clock::now(); //Comienza cronometro 
	ordenamientoBurbujaModificado(copia);
    auto t2 = std::chrono::high_resolution_clock::now(); //Finaliza cronometro
	double t_total = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count();  //Conversion y guarda
	
	return t_total;
}

double tiempo_ShellSort(int copia[]){
	
	auto t1 = std::chrono::high_resolution_clock::now(); //Comienza cronometro 
	ordenamientoShellsort(copia);
    auto t2 = std::chrono::high_resolution_clock::now(); //Finaliza cronometro
	double t_total = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count();  //Conversion y guarda
	
	return t_total;
}

double tiempo_QuickSort(int copia[]){
	
	auto t1 = std::chrono::high_resolution_clock::now(); //Comienza cronometro 
	ordenamientoQuickSort(copia,0,TAMANO-1);
    auto t2 = std::chrono::high_resolution_clock::now(); //Finaliza cronometro
	double t_total = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count();  //Conversion y guarda
	return t_total;
}

string tipo_ordenamiento(int i){
	
	if(i==0) return "Insercion  ";
	if(i==1) return "Seleccion  ";
	if(i==2) return "Burbuja  ";
	if(i==3) return "Burbuja.M  ";
	if(i==4) return "ShellShort   ";
	if(i==5) return "QuickSort  ";
	
	return 0;
}
	

/*---------------------------------------------------------------------------------------------
				FUNCION QUE DIBUJA LA TABLA
----------------------------------------------------------------------------------------------*/
void dibujarTabla(float tabla[][3]){
	cout<<"\n\t\tTiempos de ejecucion en segundos \n\n";
	cout <<  "-------------------------------------------------------------------------" << endl;
	cout <<  "	         Desordenado   :   Ordenado   : Orden Invertido     " << endl;
	cout <<  "-------------------------------------------------------------------------" << endl;
	
	for (int i= 0; i <=5; i++){
		
		cout<<tipo_ordenamiento(i); //Muestra el tipo de ordenamiento usado.
		
		for(int j=0;j<3;j++){
			cout <<"	    "<< std::fixed << std::setprecision(2) << tabla[i][j]<<"      ";	
		}
		cout<<endl;
	}
}

void metodos(int TAMANO, float tabla[6][3]){
	
	int original[TAMANO], copia[TAMANO];
	  //TABLA DONDE METEMOS LOS VALORES DE LOS SEGUNDOS
	llenar_arreglo(original,copia); //Se llena el arreglo sin numeros repetidos

	/*---------Ordenamiento por insercion - Arreglo desordenado------------*/
	
    tabla[0][0] = tiempo_insercion(copia);
    
    /*---------Ordenamiento por insercion - Arreglo ordenado------------*/

    tabla[0][1] = tiempo_insercion(copia);
    
    /*---------Ordenamiento por insercion - Arreglo Invertido------------*/
    
    invertirArreglo(copia); //Invertimos el arreglo
    tabla[0][2] = tiempo_insercion(copia);
    
    /*---------Ordenamiento por Seleccion - Arreglo Desordenado------------*/
    
    copiar_arreglo(copia,original); //Se pasa los valores del arreglo original a la copia
    tabla[1][0] = tiempo_seleccion(copia);
    
    /*---------Ordenamiento por Seleccion - Arreglo Ordenado------------*/
    
    tabla[1][1] = tiempo_seleccion(copia);
    
    /*---------Ordenamiento por Seleccion - Arreglo Invertido------------*/
    
    invertirArreglo(copia);
    tabla[1][2] = tiempo_seleccion(copia);
    
    /*---------Ordenamiento por Burbuja - Arreglo Desordenado------------*/
   	copiar_arreglo(copia,original);
   	
    tabla[2][0] = tiempo_burbuja(copia);
    
    /*---------Ordenamiento por Burbuja - Arreglo Ordenado------------*/
	 
    tabla[2][1] = tiempo_burbuja(copia);
    
    /*---------Ordenamiento por Burbuja - Arreglo Invertido------------*/
    invertirArreglo(copia);
    tabla[2][2] = tiempo_burbuja(copia);
    
    /*---------Ordenamiento por Burbuja Modificado - Arreglo Desordenado------------*/
    copiar_arreglo(copia,original);
    tabla[3][0] = tiempo_burbujaModificado(copia);
    
    /*---------Ordenamiento por Burbuja Modificado - Arreglo Ordenado------------*/
    
    tabla[3][1] = tiempo_burbujaModificado(copia);
    
	/*---------Ordenamiento por Burbuja Modificado - Arreglo Invertido------------*/
	invertirArreglo(copia);
	tabla[3][2] = tiempo_burbujaModificado(copia);
	
	/*---------Ordenamiento por ShellShort - Arreglo Desordenado------------*/
	
	copiar_arreglo(copia,original);
	tabla[4][0] = tiempo_ShellSort(copia);
	
    /*---------Ordenamiento por ShellShort - Arreglo Ordenado------------*/
    
    tabla[4][1] = tiempo_ShellSort(copia);
    
	/*---------Ordenamiento por ShellShort - Arreglo Invertido------------*/
	
	invertirArreglo(copia);
	tabla[4][2] = tiempo_ShellSort(copia);
	
	/*---------Ordenamiento por QuickSort - Arreglo Desordenado------------*/
	
	copiar_arreglo(copia,original);
	tabla[5][0] = tiempo_QuickSort(copia);
	
    /*---------Ordenamiento por QuickSort - Arreglo Ordenado------------*/
    
    tabla[5][1] = tiempo_QuickSort(copia);
    
	/*---------Ordenamiento por QuickSort - Arreglo Invertido------------*/
	invertirArreglo(copia);
	tabla[5][2] = tiempo_QuickSort(copia);
}

void ordenarTime(float tabla[][3], int columna){
	float array[6], aux;
	string tipo_metodo[6],pos_met;
	int i=0, f;
	
	for(f=0; f<6; f++){
		array[i]= tabla[f][columna];		// Se pasa los valores de la tabla en array
		tipo_metodo[i]=tipo_ordenamiento(i);
		i++;
	}
	
	
	for(i=0; i<6; i++){
		for(int j=0; j<6-1; j++){
			if(array[j]> array[j+1]){		// Ordena el array de menor a mayor
				aux= array[j];
				array[j]= array[j+1];
				array[j+1]= aux;
				
				pos_met= tipo_metodo[j];
				tipo_metodo[j]=tipo_metodo[j+1];
				tipo_metodo[j+1]=pos_met;
			}
		}
	}
	
	float mejorTime= array[0];
	
	for(i=0; i<6; i++){
		
		cout<<"  "<<i+1<<".-"<<tipo_metodo[i]<<"  "<< std::fixed << std::setprecision(2)<<array[i]<<" (+"<<array[i]-mejorTime<<")"<<endl;
	}

}                         	
								//	FUNCION MAIN
/*----------------------------------------------------------------------------------------------*/

int main () {
	float tabla[6][3];
	
	metodos(TAMANO, tabla);
   	          
   	dibujarTabla(tabla);
   	
   	cout<<endl<<endl<<" Arreglo Desordenado"<<endl;
   	ordenarTime(tabla, 0);
   	
   	cout<<endl<<endl<<"  Arreglo Ordenado"<<endl;
   	ordenarTime(tabla, 1);
   	
   	cout<<endl<<endl<<"  Arreglo Invertido"<<endl;
   	ordenarTime(tabla, 2);
   	
   	TAMANO= 3000;
   	
   	cout<<"\n Primeros 3000 Elementos"<<endl;
   	
   	metodos(TAMANO, tabla);
   	dibujarTabla(tabla);
   	
   	cout<<endl<<endl<<" Primeros 3000 Elementos Arreglo Desordenado"<<endl;
   	ordenarTime(tabla, 0);
   	
   	cout<<endl<<endl<<"  Primeros 3000 Elementos Arreglo Ordenado"<<endl;
   	ordenarTime(tabla, 1);
   	
   	cout<<endl<<endl<<" Primeros 3000 Elementos Arreglo Invertido"<<endl;
   	ordenarTime(tabla, 2);

return 0;
}