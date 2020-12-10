#include <iostream>
#include <conio.h>
#include <stdlib.h>



using namespace std;

struct Nodo{ // se agrega una estructura para agregar los tipos de datos de las variables
	int dato; // se declara el tipo de variable
	Nodo *der; // este funcion nos indica donde va almacenar los dastos a insertar
	Nodo *izq;	
};

// prototipos
void menu();
Nodo *crearNodo(int);
void insertarNodo(Nodo *&,int);
void mostrarArbol(Nodo *,int);// esta funcion va tener dos parametros uno para el arbol y otro para el contador
bool busqueda(Nodo *,int); // prototipo para la busqueda
void preOrden(Nodo *); // de tipo puntero

Nodo *arbol = NULL;

int main() { // el inicio de la ejecucion 
	menu();
	
	getch(); // nos permitira guardar un valor en una variable 
	return 0;
}

//funcion de menu
void menu(){
	int dato,opcion,contador=0;
	
	do{
	    cout<<"\t.:MENU:."<<endl;
		cout<<"1. Insertar un nuevo nodo"<<endl;
		cout<<"2. Mostar el arbol completo"<<endl;
		cout<<"3. Buscar un elemento en el arbol"<<endl;
		cout<<"4. Recorrer el arbol en preorden"<<endl;
		cout<<"5. Salir"<<endl;
		cout <<"opcion: ";
		
		cin>>opcion;
		
	    switch(opcion){
			case 1: cout<<"\nDigite un numero: "; // se solicita el numero desde el teclado
			        cin>>dato;// guardamos la variable introdocida 
			        insertarNodo(arbol,dato);// insertamos un nuevo nodo
			        cout<<"\n"; // salto de linea
			        system("pause"); // hace una pausa, hasta que presionan la tecla, vuelve a solicitar
			        break;
			case 2: cout<<"\nMostrando el arbol completo:\n\n"; // se manda imprimir los nodos insertados en el arbol
			        mostrarArbol(arbol,contador);
			        cout<<"\n"; // salto de linea
			        system ("pause");// para que nos permita ver el arbol plasmado
			        break;
			case 3: cout<<"\nDijite el elemento a buscar en el arbol: "; 
			        cin>>dato;
			        if(busqueda(arbol,dato) == true){
			        	cout<<"\nElemento "<<dato<<" ha sido encontrado en el arbol\n";
					}
					else{
						cout<<"\nElemento no encontrado\n";
							
					}
					cout<<"\n";
					system ("pause");
					break;
			case 4:	cout<<"\nRecorrido en preorden: ";	
			        preOrden(arbol);
			        cout<<"\n\n";
			        system("pause");
			        break;
		}
		system("cls");
	}while(opcion != 5);
}

//funcion para crear un nuevo nodo
Nodo *crearNodo(int n){ // se declara el tipo de variable 
	Nodo *nuevo_nodo = new Nodo(); // se hace una instanciacion 
	
	nuevo_nodo->dato = n; // el nuevo nodo va almacenar en dato
	nuevo_nodo->der = NULL;// decimos que el nuevo nodo esta vacio
	nuevo_nodo->izq = NULL;// decimos que el nuevo nodo esta vacio
	
	return nuevo_nodo;
}
//funcion para insertar elemntos en el arbol
void insertarNodo(Nodo *&arbol,int n){
	if(arbol == NULL){ // si el arbol esta vacio
		Nodo *nuevo_nodo = crearNodo(n);
		arbol = nuevo_nodo;	
	}
	else{// si el arbol tiene un nodo o mas
	    int valorRaiz = arbol->dato;// obtenemos el valor de la raiz
	    if(n < valorRaiz){// si el elemento es menor a la raiz, insertamos en zq
		    insertarNodo(arbol->izq,n);    
		}
		else{//si el elemento es mayor a la raiz,insertamos en derecha
		    insertarNodo(arbol->der,n);
		}
	}

}
//funcion para mostrar el arbol completo
void mostrarArbol(Nodo *arbol,int cont){
	if(arbol == NULL){// si el arbol esta vacio
		return;
	}  
	else{// si no, nos immprimira los datos que contiene el arbol
	    mostrarArbol(arbol->der,cont+1); // esta funcion nos sirve para imprimir todos los datos del arbol 
	    for(int i=0;i<cont;i++){// utilizamos un bucle desde que cero hasta que sea menor a contaador
		    cout<<"   " ;// espacio para separar los datos del arbol
	   }
	   cout<<arbol->dato<<endl;// se imprime todo los lados del lado derecho
    	mostrarArbol(arbol->izq,cont+1);
   }

}
//Funcion pra buscar un elemento en el arbol
bool busqueda (Nodo *arbol,int n){
	if(arbol == NULL){// si el arbol esta vacio
	   return false;	
	}
	else if(arbol->dato == n){// si no encuentra el elmento en el arbol entonces accedera otro caso
	    return true;
	}
	else if(n < arbol->dato){ // otro caso que se puede presentar al buscar
	    return busqueda(arbol->izq,n);	
	}  
	   
    else{
	    return busqueda(arbol->der,n);
	   	
	} 
 }
// funcion para recorrido en profundidad preorden
void preOrden(Nodo *arbol){
	if(arbol == NULL){ // si la lista esta vacia 
		return;
	}
	else{// en el caso contrario
		cout<<arbol->dato<<" - "; // se imprime la raiz 
		preOrden(arbol->izq); // se llama de nuevo la funcion preorden pra recorrer el lado izquierdo del arbol
		preOrden(arbol->der);
	}
}	         
	   


