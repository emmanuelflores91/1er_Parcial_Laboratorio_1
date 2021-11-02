#include "informes.h"

static int NuevoIdPedido();


static int NuevoIdPedido()
{
	static int id;
	id = 9;
	id ++;

	return id;
}

int InicializarPedidos(ePedido list[], int len)
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

int HayPedidosCompletados (ePedido list[], int len)
{
	int exist;
	exist = 0;
	if(list != NULL && len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if(!list[i].isEmpty && list[i].estado == COMPLETADO)
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


/*int EncontrarUltimoIdPedido(ePedido list[], int len)
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
}*/

int CargarPedido (ePedido list[], int len, int idCliente)
{
	int estado;
	estado = -1;

	if (list != NULL && len > 0)
	{
		system("cls");
		printf("\tCREAR PEDIDO\n"
				"_________________________________\n\n");

		for(int i = 0; i< len; i++)
		{
			if(list[i].isEmpty)
			{
				if(PedirFlotante(&list[i].cantidadKilosTotal,
				   "\n Ingrese cantidad total de kilos a recolectar: ","\n Error en datos.", 3)== 0)
				{
					list[i].idPedido = NuevoIdPedido();
					list[i].idCliente = idCliente;
					list[i].estado = PENDIENTE;
					list[i].isEmpty = 0;
					estado = 0;
				}
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

	for(int i=0; i<len; i++)
		{
			if(!list[i].isEmpty && list[i].estado == PENDIENTE && list[i].idCliente == idCliente)
			{
				contadorAuxiliar ++;
				estado = 0;
			}
		}

		*cantidadPendientes = contadorAuxiliar;

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

int SumarKilosProcesados (ePedido listaPedidos[], int lenPedidos)
{
	float acumuladorKilos;
	acumuladorKilos = -1;

	if (listaPedidos != NULL && lenPedidos > 0)
	{
		for(int i = 0; i < lenPedidos; i++)

		{
			if(!listaPedidos[i].isEmpty && listaPedidos[i].estado == COMPLETADO)
			{
				acumuladorKilos += listaPedidos[i].kilosPP;
			}
		}
	}

	return acumuladorKilos;
}
