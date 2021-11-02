
#ifndef LOCALIDADES_H_
#define LOCALIDADES_H_
#define LL 10 // cantidad de localidades

typedef struct
{
	int idLocalidad;
	char descripcionLocalidad[51];
	int isEmpty;

}eLocalidad;

int HayUnaLocalidad (eLocalidad list[], int len);

int ImprimirLocalidades(eLocalidad listaLocalidades[], int lenLocalidades);

int HayEspacioVacioLocalidad (eLocalidad list[], int len);

int EncontrarUltimoIdLocalidad(eLocalidad list[], int len);

int CargarLocalidad (eLocalidad list[], int len);

int EncontrarLocalidadPorId(eLocalidad list[], int len, int id);

int EditarLocalidad(eLocalidad list[], int len, int index);

int PedirLocalidad (eLocalidad list[], char mensajeError[], int len, int cantidadReintentos, int* idEncontrado);








#endif /* LOCALIDADES_H_ */
