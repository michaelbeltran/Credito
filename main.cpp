#include <iostream>
#include "Credito.h"
using namespace std;

int main(){
	Credito ob, *raiz=NULL;
	long int id;
	int i, caso;
	do{
		i=0;
		cout<<++i<<") Crear lista de clientes."<<endl;
		cout<<++i<<") Mostrar clientes."<<endl;
		cout<<++i<<") Borrar cliente por codigo."<<endl;
		cout<<++i<<") Salir"<<endl;
		cout<<">> ";
		cin>>caso;
		switch(caso){
			case 1:
				ob.crearArbol(raiz);
				break;
			case 2:
				cout<<"Usuarios"<<endl;
				ob.mostrar(raiz);
				break;
			case 3:
				cout<<"Ingrese id, del usuario: ";
				cin>>id;
				ob.eliminarXId(raiz, id);
				break;
			case 4:
				//ob
				break;
			case 5:
				//ob
				break;
			case 6:
				//ob
				break;
			case 7:
				//ob
				break;
			case 8:
				cout<<"Adios"<<endl;
				break;
		}
	}while(caso != 8);
	return 0;
}
