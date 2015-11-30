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
		void mostrarMaxMin(Credito *&);
		void maxMin(Credito *&, float *&, float *&);
		void edadCliente(Credito *, long int);
		void estadoCivilCliente(Credito *, long int);
		void tipoCreditoCliente(Credito *, long int);
};
#endif
