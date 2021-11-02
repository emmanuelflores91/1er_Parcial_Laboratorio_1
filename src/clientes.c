#include "informes.h"


int InicializarClientes(eCliente list[], int len)
{
	int estado;
	estado = -1;

	if (list != NULL && len > 0)
	{
		for(int i=0; i<len; i++)
		{
			list[i].isEmpty = 1;
		}
		estado = 0;
	}

	return estado;
}

int HayEspacioVacioCliente (eCliente list[], int len)
{
	int index;
	index = -1;

		for (int i = 0; i < len; i++)
		{
			if(list[i].isEmpty)
			{
				index = i;
				break;
			}
		}

	return index;
}

int HayUnCliente (eCliente list[], int len)
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




int EncontrarClientePorId(eCliente list[], int len, int id)
{
	int indexID;
	indexID = -1;

	if (list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(!list[i].isEmpty && list[i].idCliente == id)
			{
				indexID = i;
				break;
			}
		}
	}
	return indexID;
}










