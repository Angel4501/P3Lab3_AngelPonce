#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<time.h>
using namespace std;

int menu(); //funcion menu

char* descomprimir(char*,int);//FUNCION EJERCICIO 1
int char_to_int(char c);

char** matrizObstaculos(int,int,int);//FUNCION EJERCICIO 2

void laberinto(char* array, char** matriz, int x, int y, int n, int m);//FUNCION EJERCICIO 3

int acum=0;//variable global, para ejercicio 1 y 3

int main(int argc, char** argv) {
	int opcion=0;
	int a = 0;
	while(a!=4){
		switch(a = menu()){
			case 1:{
				int size = 0; char c;
				cout<<"Ingrese el size de la cadena: ";
				cin>>size;
				char* array = new char[size];
				for(int i=0; i<size; i++){
					cout<<(i+1)<<". Ingrese digito, luego letra 'U,D,L,R' (caracter por caracter): ";
					cin>>c;
					array[i]=c;
				}
				descomprimir(array,size);
				delete[] array; // liberando memoria
				break;
			}	
			case 2:{
				int n=0,m=0,k=0;
				cout<<"Ingrese un N (filas): ";
				cin>>n;
				cout<<"Ingrese un M (columnas): ";
				cin>>m;
				cout<<"Ingrese un k (cantidad de obstaculos): ";
				cin>>k;
				char** matriz = matrizObstaculos(n,m,k);
				//HACER EL RESPECTIVO DELETE;
				for(int i=0; i<n; i++){
					if(matriz)//if(matriz) es como decir: if(matriz!=NULL). Si no es nulo, o sea hay algo, entonces borro la memoria
					delete[] matriz[i];
					//matriz[i]=0;
				}	
				break;
			}	
			case 3:{
				acum=0;
				int fila=0, columna=0;
				cout<<"\nEJERCICIO 3"<<endl;
				//Case 1:
				int size = 0; char c;
				cout<<"Ingrese el size de la cadena: ";
				cin>>size;
				char* array = new char[size];
				for(int i=0; i<size; i++){
					cout<<(i+1)<<". Ingrese digito, luego letra 'U,D,L,R' (caracter por caracter): ";
					cin>>c;
					array[i]=c;
				}
				//char* arreglo = descomprimir(array,size);
				//fin case 1
				
				//Case 2:
				int n=0,m=0,k=0;
				cout<<"Ingrese un N (filas): ";
				cin>>n;
				cout<<"Ingrese un M (columnas): ";
				cin>>m;
				cout<<"Ingrese un k (cantidad de obstaculos): ";
				cin>>k;
				//char** matriz = matrizObstaculos(n,m,k);
				//fin case 2
				
				cout<<"Ingrese la posicion inicial, fila: ";
				cin>>fila;
				cout<<"Columna: ";
				cin>>columna;
				laberinto(descomprimir(array, size),matrizObstaculos(n,m,k),fila,columna,n,m);
				break;
			}	
			case 4:{
				break;			
			}
			default: 
				cout<<"Opcion no valida, ingresela nuevamente"<<endl;
	    }
   }//FIN DEL WHILE
	
	return 0;
}//FIN DEL MAIN

int menu(){//funcion menu
	int opc=0;
	while(opc!=4){
		cout<<"MENU"<<endl
		<<"1. Ejercicio 1"<<endl
		<<"2. Ejercicio 2"<<endl
		<<"3. Ejercicio 3"<<endl
		<<"4. Salir"<<endl
		<<"Opcion: ";
		cin>>opc;
		if(opc>=1&&opc<=4){
			break;
		}			
   }
   return opc;	
}//fin de la funcion menu

char* descomprimir(char* array, int size){//funcion del ejercicio 1

	//int acum=0;

	string cadena="";
	for(int i=0; i<size; i++){//primero hay que obtener el size del nuevo array
		int a = array[i];
		if(a>=48 && a<=57){
			cadena+=array[i];	
		}
		else{
			//acum+=char_to_int(array[i]);
			acum+=stoi(cadena);
			cadena="";
		}
	}
	
	char* arreglo = new char[acum];//el nuevo char*
	string numb="";
	int aux=0;
	
	//cout<<"El size del nuevo array es: "<<acum<<endl;
	int j=0;
	for(int i=0; i<size; i++){
		int a = array[i];
		if(a>=48 && a<=57){
			numb+=array[i];
		}
		else{
			//int j;
			int numero = stoi(numb);
			for(j=0; j<numero ; j++){
				arreglo[aux]=array[i];
				aux++;
				//aux=j;
			}
			//aux=aux+1;
			//cout<<"J es: "<<j<<endl;
			//cout<<"aux es: "<<aux<<endl;
			numb="";
		}
	}
	
	cout<<"\nLa secuencia es: "<<endl;
	for(int i=0; i<acum;i++){
		cout<<arreglo[i]<<" ";
	}
	cout<<endl<<endl;
	
	return arreglo;
	//delete[] arreglo;
}//fin de la funcion del ejercicio 1

char** matrizObstaculos(int n,int m,int k){//funcion del ejercicio 2
	
	char** matriz = 0;
	matriz = new char*[n];
	
	for(int i=0; i<n; i++){
		matriz[i] = new char[m]; //aquí se están creando las otras filas, o sea, un arreglo de arreglos. En cada posición [i], un arreglo
	}
	
	//llenando toda la matriz con '-'
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			matriz[i][j]='-';
			//cout<<matriz[i][j]<<" ";
		}
		//cout<<endl;
	}
	
	int cont=0;
	srand(time(NULL));
	while(cont<k){ //generando los numerales
		int r1=0,r2=0;
		r1=0+rand()%(n-1);
		r2=0+rand()%(m-1);
		if(matriz[r1][r2] != '#'){
			matriz[r1][r2]='#';
			cont++;
		}
	}
	
	for(int i=0; i<n; i++){ //imprimiendo la matriz
		for(int j=0; j<m; j++){
			//matriz[i][j]='-';
			cout<<matriz[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return matriz;
}//fin de la funcion ejercicio 2

void laberinto(char* array, char** matriz, int x, int y, int n, int m){
	char c;
	/*cout<<"Estas en el metodo laberinto: "<<endl;
	for(int i=0; i<sizeof(array); i++){
		cout<<array[i]<<" ";
    }
    cout<<endl;*/
	for(int i=0; i<acum; i++){
		//cout<<"hola"<<endl;
		/*switch(array[i]){
			case 'U':
			case 'u':
				c = 186;
				matriz[x][y]=c;
				x++;
				break;	
		}
		for(int ii; ii<n; ii++){
			for(int jj=0; jj<m; jj++){
				cout<<matriz[ii][jj]<<" ";
			}
			cout<<endl;
		}
		//system("pause");
		//system("cls");
		
		*/
	}
}


int char_to_int(char c){
	switch(c){
		case '0':
			return 0;
			break;
		case '1':
			return 1;
			break;
		case '2':
			return 2;
			break;
		case '3':
			return 3;
			break;
		case '4':
			return 4;
			break;
		case '5':
			return 5;
			break;
		case '6':
			return 6;
			break;
		case '7':
			return 7;	
			break;
		case '8':
			return 8;
			break;
		case '9': 
			return 9;
			break;
		default: 
			return 0;
			break;							
	}
}

