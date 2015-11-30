#include <iostream>
#include <stdio.h>
#include "Credito.h"
using namespace std;

void Credito::crearRaiz(Credito *&raiz, long int d){
	raiz = new Credito;
	raiz->id = d;
	cout<<"ingrese nombre: ";
	scanf(" %[^\n]", raiz->nombre);
	cout<<"fecha de nacimiento(DD/MM/AAAA): ";
	scanf(" %[^\n]", raiz->fecha_nac);
	cout<<"salario: ";
	scanf("%f", &raiz->salario);
	cout<<"estado civil: ";
	scanf(" %[^\n]", raiz->estado_civil);
	cout<<"valor Credito: ";
	scanf("%f", &raiz->valor_Credito);
	cout<<"fecha del préstamo: ";
	scanf(" %[^\n]", raiz->fecha_Credito);
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
	
