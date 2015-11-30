#include <iostream>
#include <stdio.h>
#include "Credito.h"
using namespace std;

void Credito::crearRaiz(Credito *&raiz, long int d){
	raiz = new Credito;
	raiz->id = d;
	cout<<"ingrese nombre: ";
	scanf(" %[^\n]", raiz->nombre);
	do{
		cout<<"fecha de nacimiento(DD/MM/AAAA): ";
		scanf(" %[^\n]", raiz->fecha_nac);
	}while();
	cout<<"salario: ";
	scanf("%f", &raiz->salario);
	cout<<"estado civil: ";
	scanf(" %[^\n]", raiz->estado_civil);
	cout<<"valor Credito: ";
	scanf("%f", &raiz->valor_Credito);
	do{
		cout<<"fecha del préstamo(DD/MM/AAAA): ";
		scanf(" %[^\n]", raiz->fecha_Credito);
	}while();
	cout<<"duración del préstamo(en meses): ";
	scanf("%d", &raiz->duracion_Credito);
	cout<<"tipo de crédito:";
	scanf(" %[^\n]", raiz->tipo_credito);
	raiz->izq = raiz->der = NULL;
}
void Credito::insIzq(Credito *&aux, long int d){
	crearRaiz(aux->izq, d);
}
void Credito::insDer(Credito *&aux, long int d){
	crearRaiz(aux->der, d);
}
void Credito::crearArbol(Credito *&raiz){
	Credito *aux1, *aux2;
	long int id = 666;
	while(id>0){
		cout<<"identificador: ";
		cin>>id;
		if(id>0){
			if(!raiz)
				crearRaiz(raiz, id);
			else{
				aux1=raiz;
				aux2=raiz;
				while(aux2 && id != aux1->id){
					aux1=aux2;
					if(	id < aux1->id)
						aux2 = aux2->izq;
					else 
						aux2 = aux2->der;
				}
				if(id == aux1->id)
					cout<<"id repetido";
				else if(id < aux1->id)
					insIzq(aux1, id);
				else
					insDer(aux1, id);
			}
			
		}
	}
}
void Credito::mostrar(Credito *raiz){
	cout<<raiz->id<<endl;
	cout<<raiz->nombre<<endl;
	cout<<raiz->fecha_nac<<endl;
	cout<<raiz->salario<<endl;
	cout<<raiz->estado_civil<<endl;
	cout<<raiz->valor_Credito<<endl;
	cout<<raiz->fecha_Credito<<endl;
	cout<<raiz->duracion_Credito<<endl;
	cout<<raiz->tipo_credito<<endl;
	cout<<"#############################"<<endl;
	if(raiz->izq){
		mostrar(raiz->izq);
	}
	if(raiz->der){
		mostrar(raiz->der);
	}
}
void Credito::eliminarXId(Credito *&raiz, long int id){
	if(raiz->id == id){
		cout<<"eliminando usuario "<<id<<endl;
		Credito *aux=NULL;
		if(raiz->der){
			aux = raiz->der;
			while(true){
				if(aux->izq){
					aux = aux->izq;	
				}else{
					aux->izq = raiz->izq;
					break;
				}
			}
			aux = raiz->der;
		}else if(raiz->izq){
			aux = raiz->izq;
		}
		cout<<"eliminado."<<endl;
		delete raiz;
		raiz=aux;
			
	}else if(raiz && raiz->izq){
		eliminarXId(raiz->izq, id);
	}
	if(raiz && raiz->der){
		eliminarXId(raiz->der, id);
	}
}
void Credito::mostrarMaxMin(Credito *&raiz){
	float *max, *min;
	max=min=&raiz->valor_Credito;
	maxMin(raiz, max, min);
	cout<<"El valor maximo es: "<<*max<<endl;
	cout<<"El valor minimo es: "<<*min<<endl;
}
void Credito::maxMin(Credito *&raiz, float *&max, float *&min){
	/*
	*Verifica el maximo y el minimo de la estructura
	*
	*/
	if(raiz->valor_Credito > *max)
		max = &raiz->valor_Credito;
	if(raiz->valor_Credito < *min)
		min = &raiz->valor_Credito;
	if(raiz->izq)
		maxMin(raiz->izq, max, min);
	if(raiz->der)
		maxMin(raiz->der, max, min);
}
void Credito::edadCliente(Credito *raiz, long int id){
	if(raiz->id == id){
		cout<<"el cliente tiene "
	}
	if(raiz->izq)
		edadCliente(raiz->izq, id);
	if(raiz->der)
		edadCliente(raiz->der, id);
}
void Credito::estadoCivilCliente(Credito *raiz, long int id){
	if(raiz->id == id){
		cout<<raiz->nombre<<" es "<<raiz->estado_civil;
	}
	if(raiz->izq)
		estadoCivilCliente(raiz->izq, id);
	if(raiz->der)
		estadoCivilCliente(raiz->der, id);
}
void Credito::tipoCreditoCliente(Credito *raiz, long int id){
	if(raiz->id == id){
		cout<<"El tipo de credito de "<<raiz->nombre<<" es "<<raiz->tipo_credito;
	}
	if(raiz->izq)
		estadoCivilCliente(raiz->izq, id);
	if(raiz->der)
		estadoCivilCliente(raiz->der, id);

}

