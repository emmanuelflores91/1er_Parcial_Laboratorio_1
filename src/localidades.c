#include "informes.h"

static int NuevoIdLocalidad();

static int NuevoIdLocalidad()
{
	static int id;
	id = 5;
	id ++;

	return id;
}

int ImprimirLocalidades(eLocalidad listaLocalidades[], int lenLocalidades)
{
	int estado;
	int flag;
	flag = 1;
	estado = -1;

	if (listaLocalidades !=NULL && lenLocalidades > 0)
	{
		for(int i = 0; i < lenLocalidades; i++)
		{
			if(!listaLocalidades[i].isEmpty)
			{
				if(flag)
				{
					printf("\n\tID\t DESCRIPCION\n"
					"________________________________________________\n");
					flag = 0;
				}
				printf("\t%-7d %-17s\n",listaLocalidades[i].idLocalidad, listaLocalidades[i].descripcionLocalidad);

				estado = 0;
			}
		}
	}
	return estado;
}



int CargarLocalidad (eLocalidad list[], int len)
{
	int estado;
	estado = -1;

	if (list != NULL && len > 0)
	{

		for(int i = 0; i< len; i++)
		{
			if(list[i].isEmpty)
			{
				if(PedirCadena("\n Ingrese nombre de la localidad: ","Error en datos",
								list[i].descripcionLocalidad, sizeof(list[i].descripcionLocalidad), 3)== 0)
				{
					list[i].idLocalidad = NuevoIdLocalidad();
					list[i].isEmpty = 0;
					estado = 0;
					break;
				}
			}
		}
	}

	system("cls");

	return estado;
}

int EditarLocalidad(eLocalidad list[], int len, int index)
{
	int estado;
	estado = -1;

	if (list != NULL && len > 0)
	{
		if(PedirCadena("\n Ingrese localidad: ", "\n Error en datos.",
			list[index].descripcionLocalidad, sizeof(list[index].descripcionLocalidad),3)== 0)
		{
			estado = 0;
		}
	}

	return estado;
}

int EncontrarLocalidadPorId(eLocalidad list[], int len, int id)
{
	int indexID;
	indexID = -1;


	if (list != NULL && len > 0 )
	{
		for(int i = 0; i < len; i++)
		{
			if(!list[i].isEmpty && list[i].idLocalidad == id)
			{
				indexID = i;
				break;
			}
		}
	}
	return indexID;
}

int PedirLocalidad (eLocalidad list[], char mensajeError[], int len, int cantidadReintentos, int* idEncontrado)
{
	int estado;
	int idIngresado;

	estado = -1;


	if (ImprimirLocalidades(list, len) == 0)

	{ 	do
		{
			if(PedirEntero(&idIngresado, "\n Ingrese ID localidad: ", "\n Error en dato", 2) == 0 &&
				EncontrarLocalidadPorId(list, len, idIngresado) != -1)
			{
				*idEncontrado = idIngresado;
				estado = 0;
				break;
			}

			printf("%s",mensajeError);

			cantidadReintentos --;

		}while(cantidadReintentos >= 0);
	}
	return estado;
}





/*int HayEspacioVacioLocalidad (eLocalidad list[], int len)
{
	int exist;
	exist = -1;
	if(list != NULL && len > 0)
	{
		exist = 0;
		for (int i = 0; i < len; i++)
		{
			if(list[i].isEmpty)
			{
				exist = 1;
				break;
			}
		}
	}

	return exist;
}
*/
int HayUnaLocalidad (eLocalidad list[], int len)
{
	int exist;
	exist = 0;
	if(list != NULL && len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if(!list[i].isEmpty)
			{
				exist = 1;
				break;
			}
		}
	}
	return exist;
}

