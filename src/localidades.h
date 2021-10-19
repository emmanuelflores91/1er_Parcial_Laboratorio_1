
#ifndef LOCALIDADES_H_
#define LOCALIDADES_H_
#define LL 10 // Lista de localidades

typedef struct
{
	int idLocalidad;
	char descripcionLocalidad[51];
	int isEmpty;

}eLocalidad;

int HayUnaLocalidad (eLocalidad list[], int len);

int ImprimirLocalidades(eLocalidad listaLocalidades[], int lenLocalidades);



#endif /* LOCALIDADES_H_ */
