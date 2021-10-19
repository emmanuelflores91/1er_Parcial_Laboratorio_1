#include "informes.h"

int InicializarPedidos(ePedido list[], int len)
{
	int estado;
	estado = -1;

	if (list != NULL && len > 0)
	{
		for(int i=0; i<len; i++)
		{
			list[i].isEmpty = 1;
			list[i].idPedido = 0;
		}
		estado = 0;
	}
	return estado;
}

int HayEspacioVacioPedido (ePedido list[], int len)
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

int HayUnPedido (ePedido list[], int len)
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

int EncontrarPedidoPorId(ePedido list[], int len, int id)
{
	int indexID;
	indexID = -1;

	if (list != NULL && len > 0 && HayUnPedido(list, len))
	{
		for(int i = 0; i < len; i++)
		{
			if(!list[i].isEmpty && list[i].idPedido == id)
			{
				indexID = i;
			}
		}
	}
	return indexID;
}


int EncontrarUltimoIdPedido(ePedido list[], int len)
{
	int lastId;
	lastId = 0;

	if (list != NULL && len > 0 && HayUnPedido(list, len))
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].idPedido > lastId)
			{
				lastId = list[i].idPedido;
			}
		}
	}
	return lastId;
}

int CargarPedido (ePedido list[], int len, int idCliente)
{
	int estado;
	estado = -1;

	if (list != NULL && len > 0 && HayEspacioVacioPedido(list, len))
	{
		system("cls");
		printf("\tCREAR PEDIDO\n"
				"_________________________________\n\n");

		for(int i = 0; i< len; i++)
		{
			if(list[i].isEmpty)
			{
				list[i].idPedido = EncontrarUltimoIdPedido(list, len) + 1;
				list[i].idCliente = idCliente;
				list[i].cantidadKilosTotal = PedirFlotante("\n Ingrese cantidad total de kilos a recolectar: ");
				list[i].estado = PENDIENTE;
				list[i].isEmpty = 0;

				estado = 0;
				break;
			}
		}
	}
		system("cls");

	return estado;
}


int ContarPedidosPendientePorID(ePedido list[], int len, int idCliente, int* cantidadPendientes)
{
	int estado;
	int contadorAuxiliar;
	contadorAuxiliar = 0;
	estado = -1;

	if (list != NULL && len > 0)
	{
		for(int i=0; i<len; i++)
		{
			if(!list[i].isEmpty && list[i].estado == PENDIENTE && list[i].idCliente == idCliente)
			{
				contadorAuxiliar ++;
				estado = 0;
			}
		}

		*cantidadPendientes = contadorAuxiliar;
	}
	return estado;
}

int ContarPedidosProcesados (ePedido list[], int len)
{
	int count = -1;

	if (list != NULL && len > 0)
	{
		count = 0;
		for(int i = 0; i < len; i++)
			{
				if(list[i].estado == COMPLETADO)
				{
					count++;
				}
			}
	}
	return count;
}

int SumarKilosProcesados (ePedido list[], int len)
{
	float kilos = -1;

	if (list != NULL && len > 0)
	{
		kilos = 0;
		for(int i = 0; i < len; i++)
			{
				if(!list[i].isEmpty && list[i].estado == COMPLETADO)
				{
					 kilos = list[i].kilosHDPE + list[i].kilosLDPE + list[i].kilosPP;
				}
			}
	}
	return kilos;
}
