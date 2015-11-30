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
		cout<<++i<<") Mostrar clientes con creditos."<<endl;
		cout<<++i<<") Borrar cliente por codigo."<<endl;
		cout<<++i<<") Mostrar monto maximo y minimo otorgado."<<endl;
		cout<<++i<<") Mostrar edad del cliente."<<endl;
		cout<<++i<<") Mostrar estado civil."<<endl;
		cout<<++i<<") Mostrar tipo de credito."<<endl;
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
				ob.mostrarMaxMin(raiz);
				break;
			case 5:
				cout<<"Ingrese id, del usuario: ";
				cin>>id;
				ob.edadCliente(raiz, id);
				break;
			case 6:
				cout<<"Ingrese id, del usuario: ";
				cin>>id;
				ob.estadoCivilCliente(raiz, id);
				break;
			case 7:
				cout<<"Ingrese id, del usuario: ";
				cin>>id;
				ob.tipoCreditoCliente(raiz, id);
				break;
			case 8:
				cout<<"Adios"<<endl;
				break;
		}
	}while(caso != 8);
	return 0;
}
