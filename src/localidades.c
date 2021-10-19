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
