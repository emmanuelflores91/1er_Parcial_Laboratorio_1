#include "informes.h"

int ImprimirLocalidades(eLocalidad listaLocalidades[], int lenLocalidades)
{
	int estado;
	estado = -1;

	if (listaLocalidades !=NULL && lenLocalidades > 0 && HayUnaLocalidad(listaLocalidades, lenLocalidades))
	{
		for(int i = 0; i < lenLocalidades; i++)
		{
			if(i==0)
			{
				printf("\n\tID\t DESCRIPCION\n"
				"________________________________________________\n");
			}
			if(!listaLocalidades[i].isEmpty)
			{
				printf("\t%-7d %-17s\n",listaLocalidades[i].idLocalidad, listaLocalidades[i].descripcionLocalidad);

				estado = 0;
			}
		}
	}
	return estado;
}

int HayEspacioVacioLocalidad (eLocalidad list[], int len)
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

int EncontrarUltimoIdLocalidad(eLocalidad list[], int len)
{
	int lastId;
	lastId = 0;

	if (list != NULL && len > 0 && HayUnaLocalidad(list, len))
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].idLocalidad > lastId)
			{
				lastId = list[i].idLocalidad;
			}
		}
	}
	return lastId;
}

int CargarLocalidad (eLocalidad list[], int len)
{
	int estado;
	estado = -1;

	if (list != NULL && len > 0 && HayEspacioVacioLocalidad(list, len))
	{
		system("cls");
		printf("\tCARGAR LOCALIDAD\n"
				"_________________________________\n\n");

		for(int i = 0; i< len; i++)
		{
			if(list[i].isEmpty)
			{
				list[i].idLocalidad = EncontrarUltimoIdLocalidad(list, len) + 1;

				while(PedirCadena(" Ingrese nombre de la localidad: ", list[i].descripcionLocalidad, sizeof(list[i].descripcionLocalidad))==-1)
				{
					system("cls");
					printf("\n Nombre invalido\n");
				}

				list[i].isEmpty = 0;

				estado = 0;
				break;
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

	if (list != NULL && len > 0 && HayUnaLocalidad(list, len))
	{
		estado = 0;

		while(PedirCadena("\n Ingrese localidad: ", list[index].descripcionLocalidad, sizeof(list[index].descripcionLocalidad))==-1)
		{
			system("cls");
			printf("\n Datos erroneos.\n");
		}
	}

	return estado;
}

int EncontrarLocalidadPorId(eLocalidad list[], int len, int id)
{
	int indexID;
	indexID = -1;

	if (list != NULL && len > 0 && HayUnaLocalidad(list, len))
	{
		for(int i = 0; i < len; i++)
		{
			if(!list[i].isEmpty && list[i].idLocalidad == id)
			{
				indexID = i;
			}
		}
	}
	return indexID;
}
