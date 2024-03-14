/*PROYECTO DE 3 EN LINEA

ALUMNO:
Lorenzo Parra
*/

#include <iostream>
#include <ctime>
#include <fstream>
#include <chrono>

using namespace std;

/*----------------------------------------------------------------------------------------------
										CLASE TABLERO
-------------------------------------------------------------------------------------------------*/
class Tablero{
	private: 
	char tabla[3][3];  // Matriz que representa el estado actual del tablero
	char ficha1, ficha2; // Ficha del jugador (X o O)
	int turno_actual, turnoj;
	int fj, cj; //donde se colocó la ficha en el último turno
	
	
	public:
		// Constructor de la clase
		Tablero(){
			
			// Inicializar el tablero con todas las casillas vacías
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					tabla[i][j]='-';
				}
			}
			
			// Inicializar las fichas de los jugadores
        	ficha1 = 'X';
        	ficha2 = 'O';
        	
        	turno_actual= 'X';
        	turnoj=0;
	}
			
		// Métodos para obtener y establecer la ficha del jugador 1
		char getficha1()const{
			return ficha1;
		}
		
		// Métodos para obtener y establecer la ficha del jugador 2
		char getficha2()const{
			return ficha2;
		}
		
		// Métodospara obtener y establecer el estado de una casilla en el tablero
		char getcasilla(int i, int j)const{
			return tabla[i][j];
		}
		
		void setcasilla(int i, int j, char valor){
			tabla[i][j]= valor;
		}
		
		// Métodos para obtener y establecer el turno actual
		char getturno()const{
			return turno_actual;
		}
		
		int gerturnoJ(){
			return turnoj;
		}
		
		void aumentaJ(){
			turnoj++;
		}

		// Métodos para obtener y establecer la fila y columna de la última jugada
		char getfila()const{
			return fj;
		}
		void setfila(int i){
			fj= i;
		}
		
		char getcolumna()const{
			return cj;
		}
		
		void setcolumna(int j){
			cj= j;
		}
		
		// Método para mostrar el estado actual del tablero
		void mostrar()const{  //Mostrar (Linea 17 hasta la 25)
			cout<<endl<<endl<<endl;
			cout<<"\t\t\t\t "<<tabla[0][0]<<" | "<<tabla[0][1]<<" | "<<tabla[0][2]<<" ";  //      - | - | - 
			cout<<"\n\t\t\t\t---|---|---\n";                                              //    ----|---|-----  
			cout<<"\t\t\t\t "<<tabla[1][0]<<" | "<<tabla[1][1]<<" | "<<tabla[1][2]<<" ";  //      - | - | -
			cout<<"\n\t\t\t\t---|---|---\n";                                              //    ----|---|-----
			cout<<"\t\t\t\t "<<tabla[2][0]<<" | "<<tabla[2][1]<<" | "<<tabla[2][2]<<" ";  //      - | - | -
			cout<<"\n\t\t\t\t---|---|---\n";
			cout<<endl<<endl<<endl;
		}
		
		// Método para verificar si una casilla está vacía

    bool casilla_vacia(int i, int j){
        return tabla[i][j] == '-';
    }

    // Método para verificar si el tablero está lleno

    bool tablero_lleno(){
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tabla[i][j] == '-') {
                    return false;
                }
            }
        }
        return true;
    }

		int Ganador(){   //Funcion que permite analizar si ha terminado la partida.
			
			//Jugador X
			for(int i=0; i<3; i++){   //Comprobar filas
				if((tabla[i][0]== ficha1) && tabla[i][0]== tabla[i][1] && tabla[i][1]== tabla[i][2]){
					return ficha1; //Existe ganador en supuesta fila i
				}
			}
			
			for(int j=0; j<3; j++){  //Comprobar columnas
				if((tabla[0][j]== ficha1) && tabla[0][j]== tabla[1][j] && tabla[1][j]== tabla[2][j]){
					return ficha1; //Existe ganador en supuesta columnas j
				}
			}
			
			//Comprobar diagonales
			
			if((tabla[0][0]== ficha1) && tabla[0][0]== tabla[1][1] && tabla[1][1]== tabla[2][2]){
				return ficha1; //Existe ganador en la primera diagonal
			}
			
			if((tabla[2][0]== ficha1) && tabla[2][0]== tabla[1][1] && tabla[1][1]== tabla[0][2]){
				return ficha1; //Existe ganador en la segunda diagonal
			}
			
			//Jugador O
			for(int i=0; i<3; i++){   //Comprobar filas
				if(( tabla[i][0]== ficha2) && tabla[i][0]== tabla[i][1] && tabla[i][1]== tabla[i][2]){
					return ficha2; //Existe ganador en supuesta fila i
				}
			}
			
			for(int j=0; j<3; j++){  //Comprobar columnas
				if((tabla[0][j]== ficha2) && tabla[0][j]== tabla[1][j] && tabla[1][j]== tabla[2][j]){
					return ficha2; //Existe ganador en supuesta columnas j
				}
			}
			
			//Comprobar diagonales
			
			if((tabla[0][0]== ficha2) && tabla[0][0]== tabla[1][1] && tabla[1][1]== tabla[2][2]){
				return ficha2; //Existe ganador en la primera diagonal
			}
			
			if((tabla[2][0]== ficha2) && tabla[2][0]== tabla[1][1] && tabla[1][1]== tabla[0][2]){
				return ficha2; //Existe ganador en la segunda diagonal
			}
			
			return 0; //No hay ganador	
			}
		
    // Método para hacer una jugada

    void hacer_jugada(int i, int j) {
        // Colocar la ficha del jugador en la casilla correspondiente
        if (turno_actual == ficha1) {
            tabla[i][j] = ficha1;
            fj = i;
            cj = j;
        } else {
            tabla[i][j] = ficha2;
            fj = i;
            cj = j;
        }
        // Cambiar el turno al siguiente jugador
        if (turno_actual == ficha1) {
            turno_actual = ficha2;
        } else {
            turno_actual = ficha1;
        }
    }
    
    void tutorial(){
  //  	cout<<"================================================================================\n";
    	cout<<"\n\n\tA continuacion se le muestra todas las posiciones a elegir:  "<<endl<<endl;
    	cout<<"\t\t\t[0][0] | [0][1] | [0][2] ";  //      - | - | - 
		cout<<"\n\t\t\t-------|--------|-------\n";                                              //    ----|---|-----  
		cout<<"\t\t\t[1][0] | [1][1] | [1][2] ";  //      - | - | -
		cout<<"\n\t\t\t-------|--------|-------\n";                                              //    ----|---|-----
		cout<<"\t\t\t[2][0] | [2][1] | [2][2] ";  //      - | - | -
		cout<<"\n\t\t\t-------|--------|-------\n";
		cout<<endl<<endl;
//		cout<<"================================================================================\n";
		system ("pause");
	}
};

/*----------------------------------------------------------------------------------------------
										CLASE ARCHIVO
-------------------------------------------------------------------------------------------------*/

class ArchivoTx{
	private:
		Tablero tab;
		string nombre_archivo;
		string historial;
		public:
			
			ArchivoTx(string nombre){
				nombre_archivo= nombre;
				historial= "";
			}
			
			// Método para escribir el estado actual del tablero en un archivo de texto
			void escribir(string texto){
				ofstream archivo(nombre_archivo, std::ios::app);
				if(archivo.is_open()){
					
					historial = historial + texto + "\n";
					archivo<<historial;
					
					archivo.close();
					
					cout<<"Se guardo el archivo "<<nombre_archivo<<endl;
				}else{
					cout<<"No se pudo abrir el archivo "<<nombre_archivo<<endl;
				}	
			}
			
			// Método para leer el estado actual del tablero desde un archivo de texto
			 void leer(){
				ifstream archivo(nombre_archivo);
				if(archivo.is_open()){
					string linea;
					while(getline(archivo, linea)){
						cout<<linea<<endl;
					}
					archivo.close();
					
					
					cout<<"Se cargo el archivo "<<nombre_archivo<<endl;
				}else{
					cout<<"No se pudo abrir el archivo "<<nombre_archivo<<endl;
				}
			}
			
			static void guardart(Tablero& tab, string nombre_archivo){
				ofstream archivo1(nombre_archivo);
				if(archivo1.is_open()){
					for(int i=0; i<3; i++){
						for(int j=0; j<3; j++){
							
							char valor= tab.getcasilla(i, j);
							archivo1<<valor<<" ";
							
						}
						archivo1<<endl;
					}
					archivo1.close();
			}else{
				cout<<"No se pudo abrir el archivo"<<endl;
			}
			}
			
			static void cargart(Tablero& tab, string nombre_archivo){
				ifstream archivo1(nombre_archivo);
				char estado[3][3];
				if(archivo1.is_open()){
					for(int i=0; i<3; i++){
						for(int j=0; j<3; j++){
							
							char valor;
							archivo1>>valor;
							cout<<valor;
							if(valor=='X' || valor=='O'){
								tab.setcasilla(i, j, valor);
							}else{
								tab.casilla_vacia(i, j);
							}
							
						}
						cout<<endl;
					}
					
					archivo1.close();
				}else{
					cout<<"No se pudo abrir el archivo"<<endl;
				}
			}
			
			
};

/*----------------------------------------------------------------------------------------------
										CLASE MENU
-------------------------------------------------------------------------------------------------*/

class Menu{
	private: 
	int op;
	
	public:
		
		// Constructor de la clase
    Menu() {
        op = 0;
    }
    
    // Método para mostrar las opciones del menú
    
    void titulo_juego(){
    
		cout<<"   #######     ######## ##    ##    ########     ###    ##    ##    ###    \n";
		cout<<"  ##     ##    ##       ###   ##    ##     ##   ## ##    ##  ##    ## ##   \n";
		cout<<"         ##    ##       ####  ##    ##     ##  ##   ##    ####    ##   ##  \n";
		cout<<"   #######     ######   ## ## ##    ########  ##     ##    ##    ##     ## \n";
		cout<<"         ##    ##       ##  ####    ##   ##   #########    ##    #########  \n";
		cout<<"  ##     ##    ##       ##   ###    ##    ##  ##     ##    ##    ##     ## \n";
		cout<<"   #######     ######## ##    ##    ##     ## ##     ##    ##    ##     ## \n\n\n";
//		cout<<"----------------------------------------------------------------------------\n\n\n";
	}
    void mostrar_opciones(){
        cout << "======================      Seleccione una opcion      ======================" << endl << endl;
        cout << "\t\t1.-      Jugador vs Jugador" << endl;
        cout << "\t\t2.-      Jugador vs Computadora" << endl;
        cout << "\t\t3.-      Computadora vs Computadora" << endl;
        cout << "\t\t4.-      Instrucciones para jugar" << endl ;
        cout << "\t\t5.-      Salir" << endl << endl ;
        cout << "\t\t         Ingrese su opcion:  " ;
        cin >> op;
    }

    // Método para obtener la opción seleccionada por el usuario
    int obtener_opcion() const {
        return op;
    }
};

/*----------------------------------------------------------------------------------------------
										CLASE JUGADOR VS JUGADOR
-------------------------------------------------------------------------------------------------*/

class JugadorvsJugador: public Tablero{
	
	private:
		Tablero tab;
		
		public:
			
		void cargarJvsJ(){
			int conf;
		
    		cout<<"Desea cargar una partida anterior Si(1)/No(2)?"<<endl;
    		cin>>conf;
    		
    		ArchivoTx archivo1 ("JvsJ.txt");
    		
    		switch(conf){
    			case 1:
    		
    			archivo1.cargart(tab, "JvsJ.txt");
    			system("cls");
    			break;
    			
    			case 2:
    				
    				break;		
			}
			
		}
		
		void iniciarJvsJ(){
			
			int  f, c;
			char ganador, l;
			
			
			ArchivoTx archivo("Jugadas.txt");
			
			ArchivoTx archivo1 ("JvsJ.txt");
			
			cargarJvsJ();
    		
    		system("cls");
    		
			while(true){
				
				do{
					
					tab.mostrar();
					
					cout<<"\t\t\tJugador  "<<tab.getturno()<<", es su turno\n"<<endl;
					auto t1= std::chrono::high_resolution_clock::now();
					
					if(tab.getturno()=='X'){
						
					cout<<"\t\t\tIngrese la fila(0-2): "; cin>>f; 
					cout<<"\t\t\tIngrese la columna(0-2): "; cin>>c; 
					
					if(tab.casilla_vacia(f, c)){
					tab.hacer_jugada(f, c);
					
					
					auto t2= std::chrono::high_resolution_clock::now();
					// Medir el tiempo que tarda el jugador 1 en hacer la jugada
					double time1= std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1).count(); 
					double time2= 0.0;
					
					int nJ= 0;
					nJ= tab.gerturnoJ();
					
		
	string texto= "Mov " + to_string(tab.gerturnoJ()) + " t1: " + to_string(time1) + "  1  HUMANO "    +  "X (" + to_string(f) + ", " + to_string(c) + ")" + "\n";
					
					tab.aumentaJ();
					
					archivo.escribir(texto);
					
					}else{
						cout<<"\t\t\tingrese de nuevo"<<endl;
						cout<<"\t\t\t";system("pause");
					}
					}else{
					
					auto t1= std::chrono::high_resolution_clock::now();
						
					cout<<"\t\t\tIngrese la fila(0-2): "; cin>>f; 
					cout<<"\t\t\tIngrese la columna(0-2): "; cin>>c; 
					
					if(tab.casilla_vacia(f, c)){
					tab.hacer_jugada(f, c);
					
					auto t2= std::chrono::high_resolution_clock::now();
					double time1= 0.0;
					// Medir el tiempo que tarda el jugador 2 en hacer la jugada
					double time2= std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1).count();
					
					int nJ= 0;
					nJ= tab.gerturnoJ();
					
		
	string texto= "Mov " + to_string(tab.gerturnoJ()) + " t2: " + to_string(time2) + "  2  HUMANO "    +  "O (" + to_string(f) + ", " + to_string(c) + ")" + "\n";
					
					tab.aumentaJ();
					
					archivo.escribir(texto);
					
					}else{
						cout<<"\t\t\tingrese de nuevo"<<endl;
						cout<<"\t\t\t";system("pause");
					}
					
					}
					
					archivo1.guardart(tab, "JvsJ.txt");
					
					system("cls");
					
					
					if(tab.tablero_lleno()){
					cout<<"\t\t\tHa sido un empate"<<endl;
					cout<<"\t\t\t";system("pause");
							break;
					}
					
				}while(!tab.Ganador());
				
					system("cls");
				
					l= tab.tablero_lleno();
					ganador= tab.Ganador();
					
					if(ganador){
						cout<<"\t\t\tEl jugador  "<<ganador<<" ha ganado"<<endl;
						cout<<"\t\t\t";system("pause");
							break;
					}
			
					if(l!= '-'){
						break;
					}
				}
			}
};

/*----------------------------------------------------------------------------------------------
										CLASE JUGADOR VS COMPUTADOR
-------------------------------------------------------------------------------------------------*/

class JugadorvsComputador : public Tablero{
	private:
		Tablero tab; // para tener  mejor acceso
		
		public:
			
			void cargarJvsC(){
			int conf;
		
    		cout<<"Desea cargar una partida anterior Si(1)/No(2)?"<<endl;
    		cin>>conf;
    		
    		ArchivoTx archivo1 ("JvsC.txt");
    		
    		switch(conf){
    			case 1:
    		
    			archivo1.cargart(tab, "JvsC.txt");
    			system("cls");
    			break;
    			
    			case 2:
    				
    				break;		
			}
			
		}
		
			void iniciarJvsC(){
				int  f, c;
			char ganador, l;
			
			ArchivoTx archivo1 ("JvsC.txt");
			
			cargarJvsC();
			
			system ("cls");
			
			while(true){
				
				do{
					 ArchivoTx archivo("Jugadas.txt");
					 
					tab.mostrar();
					
					cout<<"\t\t\tJugador  "<<tab.getturno()<<", es su turno"<<endl;
					auto t1= std::chrono::high_resolution_clock::now();
					
					if(tab.getturno()=='X'){
						
					cout<<"\t\t\tIngrese la fila(0-2): "; cin>>f; 
					cout<<"\t\t\tIngrese la columna(0-2): "; cin>>c; 
					
					if(tab.casilla_vacia(f, c)){
					tab.hacer_jugada(f, c);
					
					
					auto t2= std::chrono::high_resolution_clock::now();
					// Medir el tiempo que tarda el jugador 1 en hacer la jugada
					double time1= std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1).count();
					double time2= 0.0;
					
					int nJ= 0;
					nJ= tab.gerturnoJ();
					
		
	string texto= "Mov " + to_string(tab.gerturnoJ()) + " t1: " + to_string(time1) + "  1  HUMANO "    +  "X (" + to_string(f) + ", " + to_string(c) + ")" + "\n";
					
					tab.aumentaJ();
					
					archivo.escribir(texto);
					
					}else{
						cout<<"\t\t\tingrese de nuevo"<<endl;
						cout<<"\t\t\t";system("pause");
					}
					}else{
						
						
						cout<<"\t\t\tLa computadora esta pensando.."<<endl;
						auto t1 = std::chrono::high_resolution_clock::now();
						cout<<"\t\t\t";system("pause");
						do{
							f= rand()%3;
							c= rand()%3;
							
						}while(!tab.casilla_vacia(f, c));
						
						tab.hacer_jugada(f, c);
						
						auto t2= std::chrono::high_resolution_clock::now();
						double time1= 0.0;
						// Medir el tiempo que tarda el jugador 2 en hacer la jugada
						double time2= std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1).count();
						
						int nJ= 0;
						 nJ= tab.gerturnoJ();
						
		string texto= "Mov " + to_string(nJ) + " t2: " + to_string(time2) + "  2  COMPUTADORA "    +  "O (" + to_string(f) + ", " + to_string(c) + ")" + "\n";
					
					tab.aumentaJ();
					archivo.escribir(texto);
					
					}
					
					archivo1.guardart(tab, "JvsC.txt");
					
					system("cls");
					
					
					if(tab.tablero_lleno()){
					cout<<"\t\t\tHa sido un empate"<<endl;
					cout<<"\t\t\t";system("pause");
							break;
					}
					
				}while(!tab.Ganador());
				
				l= tab.tablero_lleno();
					ganador= tab.Ganador();
					
					if(ganador){
						cout<<"\t\t\tEl jugador  "<<ganador<<" ha ganado"<<endl;
						cout<<"\t\t\t";system("pause");
							break;
					}
			
					if(l!= '-'){
						break;
					}
			}
			}
};

/*----------------------------------------------------------------------------------------------
								CLASE COMPUTADOR VS COMPUTADOR
-------------------------------------------------------------------------------------------------*/

class ComputadorvsComputador: public Tablero{
	private:
		Tablero tab;
		
		public:
			
			void cargarCvsC(){
			int conf;
		
    		cout<<"Desea cargar una partida anterior Si(1)/No(2)?"<<endl;
    		cin>>conf;
    		
    		ArchivoTx archivo1 ("CvsC.txt");
    		
    		switch(conf){
    			case 1:
    		
    			archivo1.cargart(tab, "CvsC.txt");
    			system("cls");
    			break;
    			
    			case 2:
    				
    				break;		
			}
			
		}
			
			void iniciarCvsC(){
				int  f, c;
			char ganador, l, x, o;
			
			ArchivoTx archivo("Jugadas.txt");
			ArchivoTx archivo1 ("CvsC.txt");
			
			cargarCvsC();
			
				while(true){
					
					do{
						tab.mostrar();
					
					cout<<"\t\t\tJugador  "<<tab.getturno()<<", es su turno"<<endl;
					auto t1= std::chrono::high_resolution_clock::now();
					
					if(tab.getturno()=='X'){
						
						cout<<"\t\t\tLa computadora 1 esta pensando.."<<endl;
						cout<<"\t\t\t";system("pause");
						
						do{
							
							f= rand()%3;
							c= rand()%3;
							
						}while(!tab.casilla_vacia(f, c));
						
						tab.hacer_jugada(f, c);
						
					auto t2= std::chrono::high_resolution_clock::now();
					// Medir el tiempo que tarda el jugador 1 en hacer la jugada
					double time1= std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1).count();
					double time2= 0.0;
					
					int nJ= 0;
					nJ= tab.gerturnoJ();
					
		
	string texto= "Mov " + to_string(tab.gerturnoJ()) + " t1: " + to_string(time1) + "  1  COMPUTADORA "    +  "X (" + to_string(f) + ", " + to_string(c) + ")" + "\n";
					
					tab.aumentaJ();
					
					archivo.escribir(texto);
					
					}else{
						
						cout<<"\t\t\tLa computadora 2 esta pensando.."<<endl;
						auto t1= std::chrono::high_resolution_clock::now();
						cout<<"\t\t\t";system("pause");
						do{
							f= rand()%3;
							c= rand()%3;
							
						}while(!tab.casilla_vacia(f, c));
						
						tab.hacer_jugada(f, c);
						
						auto t2= std::chrono::high_resolution_clock::now();
						double time1= 0.0;
						// Medir el tiempo que tarda el jugador 2 en hacer la jugada
						double time2= std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1).count();
						
						int nJ= 0;
						 nJ= tab.gerturnoJ();
						
		string texto= "Mov " + to_string(nJ) + " t2: " + to_string(time2) + "  2  COMPUTADORA "    +  "O (" + to_string(f) + ", " + to_string(c) + ")" + "\n";
					
					tab.aumentaJ();
					archivo.escribir(texto);
					
					}
					
					archivo1.guardart(tab, "CvsC.txt");
						system("cls");
					
					if(tab.tablero_lleno()){
					cout<<"\t\t\tHa sido un empate"<<endl;
					cout<<"\t\t\t";system("pause");
							break;
					}
					
					}while(!tab.Ganador());
				
					l= tab.tablero_lleno();
					ganador= tab.Ganador();
					
					if(ganador){
						cout<<"\t\t\tEl jugador  "<<ganador<<" ha ganado"<<endl;
						cout<<"\t\t\t";system("pause");
							break;
					}
					
					if(l!= '-'){
						break;
					}
				}
			}
};

/*----------------------------------------------------------------------------------------------
										 MAIN
-------------------------------------------------------------------------------------------------*/
int main(){
	Menu m;
	Tablero tab;
	JugadorvsJugador t;
	JugadorvsComputador b;
	ComputadorvsComputador c;
	
	
	do{
		m.titulo_juego();
		m.mostrar_opciones();
		
		system("cls");
		
		switch(m.obtener_opcion()){
			
			case 1:
				t.iniciarJvsJ();
				system("cls");
				break;
			case 2:
				b.iniciarJvsC();
				system("cls");
				break;
			case 3:
				c.iniciarCvsC();
				system("cls");
				break;
			case 4:
				tab.tutorial();
				system ("cls");
				break;
			case 5:
				cout<<"Hasta luego! \n";
				break;
			default:
				system("cls");
                break;
                
		}
		
	}while(m.obtener_opcion()!= 5);
	
	return 0;
}