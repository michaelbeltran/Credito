#ifndef _CREDITO_
#define _CREDITO_
class Credito{
	long int id;
	char nombre[30];
	char fecha_nac[10];
	float salario;
	char estado_civil[10];
	float valor_Credito;
	char fecha_Credito[10];
	int duracion_Credito;
	char tipo_credito[5];
	Credito *izq;
	Credito *der;
	public:
		void crearRaiz(Credito *&, long int);
		void insIzq(Credito *&, long int);
		void insDer(Credito *&, long int);
		void crearArbol(Credito *&);
		void mostrar(Credito *);
		void eliminarXId(Credito *&, long int);
};
#endif
