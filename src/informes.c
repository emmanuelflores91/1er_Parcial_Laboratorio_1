#include "informes.h"

int MostrarMenuDeOpciones ()
{
	int opcion;

		printf("\n.......................................................\n");
		printf(" 1 - Alta de cliente.\n"
				" 2 - Modificar datos de cliente.\n"
				" 3 - Baja de cliente.\n"
				" 4 - Crear pedido de recoleccion.\n"
				" 5 - Procesar residuos.\n"
				" 6 - Imprimir clientes.\n"
				" 7 - Imprimir pedidos pendientes.\n"
				" 8 - Imprimir pedidos procesados.\n"
				" 9 - Pedidos pendientes por localidad.\n"
				" 10 - Cantidad de kilos reciclados promedio por cliente.\n");
		printf("\n.......................................................\n");

		opcion = PedirEnteroEnRango("\n Ingrese una opcion: ", 0, 100);

		return opcion;
}

int CargarCliente (eCliente listaClientes[], int lenClientes, eLocalidad listaLocalidades[], int lenLocalidades)
{
	int estado;
	estado = -1;

	if (listaClientes != NULL && lenClientes > 0 && HayEspacioVacioCliente(listaClientes, lenClientes))
	{
		system("cls");
		printf("\tALTA DE CLIENTE\n"
				"_________________________________\n\n");

		for(int i = 0; i< lenClientes; i++)
		{
			if(listaClientes[i].isEmpty)
			{
				listaClientes[i].idCliente = EncontrarUltimoIdCliente(listaClientes, lenClientes) + 1;

				while(PedirCadena("\n Ingrese nombre de la empresa: ", listaClientes[i].nombreEmpresa, sizeof(listaClientes[i].nombreEmpresa))==-1)
				{
					system("cls");
					printf("\n Nombre invalido\n");
				}

				while (PedirCadenaEnRango("\n Ingrese CUIT (sin guiones): ", listaClientes[i].cuit, sizeof(listaClientes[i].cuit),11)==-1)
				{
					system("cls");
					printf("\n CUIT invalido\n");
				}

				while (PedirCadena("\n Ingrese direccion: ", listaClientes[i].direccion, sizeof(listaClientes[i].direccion))==-1)
				{
					system("cls");
					printf("\n Direccion invalida\n");
				}


				listaClientes[i].idLocalidad = PedirEntero("\n Ingrese ID localidad: ");

				while(EncontrarLocalidadPorId(listaLocalidades, lenLocalidades, listaClientes[i].idLocalidad)==-1)
				{
					printf("\n ID incorrecto.");
					listaClientes[i].idLocalidad = PedirEntero("\n Ingrese ID localidad: ");
				}

				listaClientes[i].isEmpty = 0;
				estado = 0;
				break;
			}
		}
	}
		system("cls");

	return estado;
}

int ImprimirUnClientePorId (eCliente listaClientes[], int lenClientes, eLocalidad listaLocalidades[], int lenLocalidades, int id)
{
	int estado;
	estado = -1;

	if (listaClientes !=NULL && listaLocalidades !=NULL && lenClientes && lenLocalidades > 0 && EncontrarClientePorId(listaClientes, lenClientes, id)!=-1)
	{
		printf("\n\tID\tEMPRESA\t\tCUIT\t\t DIRECCION\t  LOCALIDAD\n"
				"_____________________________________________________________________________\n");

		for(int i = 0; i < lenClientes; i++)
		{
			if (!listaClientes[i].isEmpty && listaClientes[i].idCliente == id)
			{
				for(int j = 0; j < lenLocalidades; j++)
				{
					if (!listaLocalidades[j].isEmpty && listaClientes[i].idLocalidad == listaLocalidades[j].idLocalidad)
					{
						printf("\t%-7d %-15s %-16s %-17s %-15s\n",
						listaClientes[i].idCliente, listaClientes[i].nombreEmpresa, listaClientes[i].cuit, listaClientes[i].direccion, listaLocalidades[j].descripcionLocalidad);

						estado = 0;
						break;
					}
				}

			}
		}
	}
	return estado;
}

int ImprimirClientes(eCliente listaClientes[], int lenClientes, eLocalidad listaLocalidades[], int lenLocalidades)
{
	int estado;
	estado = -1;

	if (listaClientes !=NULL && listaLocalidades !=NULL && lenClientes && lenLocalidades > 0 && HayUnCliente(listaClientes, lenClientes))
	{
		for(int i = 0; i < lenClientes; i++)
		{
			if(i==0)
			{
				printf("\n\tID\tEMPRESA\t\tCUIT\t\t DIRECCION\t  LOCALIDAD\n"
				"_____________________________________________________________________________\n");
			}
			if(!listaClientes[i].isEmpty)
			{

				for(int j = 0; j < lenLocalidades; j++)
				{
					if(!listaLocalidades[j].isEmpty && listaClientes[i].idLocalidad == listaLocalidades[j].idLocalidad)
					{
						printf("\t%-7d %-15s %-16s %-17s %-15s\n",
						listaClientes[i].idCliente, listaClientes[i].nombreEmpresa, listaClientes[i].cuit, listaClientes[i].direccion, listaLocalidades[j].descripcionLocalidad);

						estado = 0;
					}
				}
			}
		}
	}

	return estado;
}

int ImprimirClientesConPedidosPendientes(eCliente listaClientes[], int lenClientes, eLocalidad listaLocalidades[], int lenLocalidades, ePedido listaPedidos[], int lenPedidos)
{
	int estado;
	int cantidadPendientes;

	estado = -1;

	if (listaClientes !=NULL && listaLocalidades !=NULL && lenClientes && lenLocalidades > 0 && HayUnCliente(listaClientes, lenClientes))
	{
		for(int i = 0; i < lenClientes; i++)
		{
			if(i==0)
			{
				printf("\n\tID\tEMPRESA\t\tCUIT\t\t DIRECCION\t  LOCALIDAD      PEDIDOS PENDIENTES\n"
				"______________________________________________________________________________________________\n");
			}
			if(!listaClientes[i].isEmpty && ContarPedidosPendientePorID(listaPedidos, lenPedidos, listaClientes[i].idCliente, &cantidadPendientes)!=-1)
			{

				for(int j = 0; j < lenLocalidades; j++)
				{
					if(!listaLocalidades[j].isEmpty && listaClientes[i].idLocalidad == listaLocalidades[j].idLocalidad)
					{
						printf("\t%-7d %-15s %-16s %-17s %-15s   %-7d\n",
						listaClientes[i].idCliente, listaClientes[i].nombreEmpresa, listaClientes[i].cuit,
						listaClientes[i].direccion, listaLocalidades[j].descripcionLocalidad, cantidadPendientes);

						estado = 0;
					}
				}
			}
		}
	}

	return estado;
}

int ImprimirUnPedidoPendientePorId (ePedido list[], int len, int id)
{
	int estado;
	estado = -1;

	if (list !=NULL && len > 0 && EncontrarPedidoPorId(list, len, id)!=-1)
	{
		printf("\n\tID PEDIDO    CLIENTE\t\tCANTIDAD TOTAL DE KG\n"
				"_______________________________________________________________\n");

		for(int i = 0; i < len; i++)
		{
			if (list[i].idPedido == id)
			{

				estado = 0;
				break;
			}
		}
	}
	return estado;
}

int ImprimirPedidosPendientes(ePedido listaPedidos[], int lenPedidos, eCliente listaClientes[], int lenClientes)
{
	int estado;
	estado = -1;

	if (listaPedidos !=NULL && listaClientes !=NULL && lenPedidos > 0 && lenClientes > 0 && HayUnPedido(listaPedidos, lenPedidos))
	{
		for(int i = 0; i < lenPedidos; i++)
		{
			if(i==0)
			{
				printf("\n\tID PEDIDO\tCLIENTE\t\tCANTIDAD TOTAL DE KG\n"
						"_______________________________________________________________\n");
			}
			if(!listaPedidos[i].isEmpty && listaPedidos[i].estado == PENDIENTE )
			{

				for( int j = 0; j < lenClientes; j++)
				{
					if(!listaClientes[j].isEmpty && listaPedidos[i].idCliente == listaClientes[j].idCliente)
					{
						printf("\t    %-12d %-15s       %.2f kg\n", listaPedidos[i].idPedido, listaClientes[j].nombreEmpresa, listaPedidos[i].cantidadKilosTotal);
						estado = 0;
					}
				}
			}
		}
	}
	return estado;
}

int ImprimirPedidosPendientesConDatosCliente(ePedido listaPedidos[], int lenPedidos, eCliente listaClientes[], int lenClientes)
{
	int estado;
	estado = -1;

	if (listaPedidos !=NULL && listaClientes !=NULL && lenPedidos > 0 && lenClientes > 0 && HayUnPedido(listaPedidos, lenPedidos))
	{

		for(int i = 0; i < lenPedidos; i++)
		{
			if(i==0)
			{
				printf("\n\tCUIT CLIENTE\tDIRECCION\t CANTIDAD TOTAL DE KG\n"
						"____________________________________________________________________\n");
			}
			if(!listaPedidos[i].isEmpty && listaPedidos[i].estado == PENDIENTE )
			{
				for( int j = 0; j < lenClientes; j++)
				{
					if(!listaClientes[j].isEmpty && listaPedidos[i].idCliente == listaClientes[j].idCliente)
					{
						printf("\t%-15s %-18s   %.2f kg\n", listaClientes[j].cuit, listaClientes[j].direccion, listaPedidos[i].cantidadKilosTotal);
						estado = 0;
					}
				}
			}
		}
	}

	return estado;
}

int ImprimirPedidosCompletadosConDatosCliente(ePedido listaPedidos[], int lenPedidos, eCliente listaClientes[], int lenClientes)
{
	int estado;
	estado = -1;

	if (listaPedidos !=NULL && listaClientes !=NULL && lenPedidos > 0 && lenClientes > 0 && HayUnPedido(listaPedidos, lenPedidos))
	{

		for(int i = 0; i < lenPedidos; i++)
		{
			if(i==0)
			{
				printf("\n\tCUIT CLIENTE\tDIRECCION\t CANTIDAD TOTAL DE KG\n"
						"____________________________________________________________________\n");
			}
			if(!listaPedidos[i].isEmpty && listaPedidos[i].estado == COMPLETADO )
			{
				for( int j = 0; j < lenClientes; j++)
				{
					if(!listaClientes[j].isEmpty && listaPedidos[i].idCliente == listaClientes[j].idCliente)
					{
						printf("\t%-15s %-18s   %.2f kg\n", listaClientes[j].cuit, listaClientes[j].direccion, listaPedidos[i].cantidadKilosTotal);
						estado = 0;
					}
				}
			}
		}
	}

	return estado;
}


int ProcesarResiduos (ePedido list[], int len, int idCliente)
{
	int estado;
	estado = -1;

	if (list != NULL && len > 0)
	{
		system("cls");
		printf("\tPROCESAR RESIDUOS\n"
				"_________________________________\n\n");

		for(int i = 0; i< len; i++)
		{
			if(!list[i].isEmpty && list[i].idPedido == idCliente && list[i].estado == PENDIENTE)
			{
				list[i].kilosHDPE = PedirFlotante("\n Ingrese cantidad de kilos de HDPE: ");
				list[i].kilosLDPE = PedirFlotante("\n Ingrese cantidad de kilos de LDPE: ");
				list[i].kilosPP = PedirFlotante("\n Ingrese cantidad de kilos de PP: ");

				while(list[i].cantidadKilosTotal < list[i].kilosHDPE + list[i].kilosLDPE  + list[i].kilosPP)
				{
					printf("\n ERROR. Supero la cantidad de kilos total");
					list[i].kilosHDPE = PedirFlotante("\n Ingrese cantidad de kilos de HDPE: ");
					list[i].kilosLDPE = PedirFlotante("\n Ingrese cantidad de kilos de LDPE: ");
					list[i].kilosPP = PedirFlotante("\n Ingrese cantidad de kilos de PP: ");
				}

				list[i].estado = COMPLETADO;
				estado = 0;
				break;
			}
		}
	}
		system("cls");

	return estado;
}

int ContarPedidosPendientesPorLocalidad (ePedido listaPedidos[], int lenPedidos, eCliente listaClientes[], int lenClientes, eLocalidad listaLocalidades[], int lenLocalidades, int* cantidadPendientes)
{
	int estado;
	int contadorPedidosPendientes;
	int idLocalidad;

	estado = -1;
	contadorPedidosPendientes = 0;

	idLocalidad = PedirEnteroPositivo("\n Ingrese ID localidad: ");

	if (listaPedidos !=NULL && listaLocalidades !=NULL && lenPedidos > 0 && lenLocalidades > 0 && HayUnPedido(listaPedidos, lenPedidos))
	{
		for(int i= 0; i< lenPedidos; i++)
		{
			if(!listaPedidos[i].isEmpty && listaPedidos[i].estado == PENDIENTE)
			{
				for(int j = 0; j < lenClientes; j++)
				{
					if(!listaClientes[j].isEmpty && listaClientes[j].idCliente == listaPedidos[i].idCliente)
					{
						for(int k = 0; k < lenLocalidades; k++)
						{
							if(!listaLocalidades[k].isEmpty && listaLocalidades[k].idLocalidad == idLocalidad &&
								listaLocalidades[k].idLocalidad == listaClientes[j].idLocalidad)
							{
								contadorPedidosPendientes ++;
								estado = 0;
							}
						}
					}
				}
			}
		}
	}
	*cantidadPendientes = contadorPedidosPendientes;
	return estado;
}

int CalcularPromedioKilosReciclados (float kilosTotales, int cantidadClientes)
{
	float promedio;
	promedio = -1;

	if(cantidadClientes > 0)
	{
		promedio = kilosTotales / cantidadClientes;
	}

	return promedio;
}

int EliminarCliente(eCliente listaClientes[], int lenClientes, ePedido listaPedidos[], int lenPedidos, int id)
{
	int estado;
	estado = -1;

	if (listaClientes != NULL && lenClientes > 0 && listaPedidos != NULL && lenPedidos > 0 && HayUnCliente(listaClientes, lenClientes))
	{
		for(int i = 0; i < lenClientes; i++)
		{
			if(!listaClientes[i].isEmpty && listaClientes[i].idCliente == id)
			{
				for(int j = 0; j < lenPedidos; j++ )
				{
					if(!listaPedidos[j].isEmpty && listaClientes[i].idCliente == listaPedidos[j].idCliente)
					{
						listaClientes[i].isEmpty = 1;
						listaPedidos[j].isEmpty = 1;
						estado = 0;
					}
				}
			}
		}
	}
	return estado;
}

int BajaLocalidad (eCliente listaClientes[], int lenClientes, ePedido listaPedidos[], int lenPedidos, eLocalidad listaLocalidades[], int lenLocalidades, int idLocalidad)
{
	int estado;
	estado = -1;

	if (listaClientes != NULL && lenClientes > 0 && listaPedidos != NULL && lenPedidos > 0 &&
		listaLocalidades != NULL && lenLocalidades > 0 && HayUnaLocalidad(listaLocalidades, lenLocalidades))
	{
		for(int i = 0; i < lenLocalidades; i++)
		{
			if(!listaLocalidades[i].isEmpty && idLocalidad == listaLocalidades[i].idLocalidad)
			{
				for(int j = 0; j < lenClientes; j++)
				{
					if(!listaClientes[j].isEmpty && listaClientes[j].idLocalidad == listaLocalidades[i].idLocalidad)
					{
						listaLocalidades[i].isEmpty = 1;
						EliminarCliente(listaClientes, lenClientes, listaPedidos, lenPedidos, listaClientes[i].idCliente);
						estado = 0;
					}
				}
			}
		}
	}
	return estado;
}

int ContarPedidosPendientes (ePedido listaPedidos[], int lenPedidos, eCliente listaClientes[], int lenClientes)
{
	int estado;
	estado = -1;
	int MayorCantidadPedidos;
	int banderaPedidos;
	banderaPedidos = 1;

	eAuxiliar listaAuxiliares[LC];

	if (listaAuxiliares != NULL && LC > 0 && listaPedidos != NULL && lenPedidos > 0 && HayUnPedido(listaPedidos, lenPedidos))
	{
		for (int i = 0; i < lenClientes; i++)
		{
			if(!listaClientes[i].isEmpty)
			{
				listaAuxiliares[i].idCliente = listaClientes[i].idCliente;
				listaAuxiliares[i].contador = 0;
			}
		}

		for(int i=0; i<LC; i++)
		{
			if(!listaClientes[i].isEmpty)

			for (int j = 0; j < lenPedidos; j++)
			{
				if(!listaPedidos[j].isEmpty  && listaPedidos[j].idCliente == listaAuxiliares[i].idCliente && listaPedidos[j].estado == PENDIENTE)
				{
					listaAuxiliares[i].contador ++;
				}
			}
		}

		for(int i=0; i<LC; i++)
		{
			if (!listaClientes[i].isEmpty && (banderaPedidos || listaAuxiliares[i].contador > MayorCantidadPedidos))
			{
				MayorCantidadPedidos = listaAuxiliares[i].contador;
				banderaPedidos = 0;
			}
		}

		printf("\n Los clientes con mas pedidos pendientes son: ");


		printf("\n\tID\tEMPRESA\t\tCUIT\t\t DIRECCION\t  LOCALIDAD\n"
				"_____________________________________________________________________________\n");

			for(int i = 0; i < lenClientes; i++)
			{
				if (!listaClientes[i].isEmpty && listaAuxiliares[i].contador == MayorCantidadPedidos)
				{
					printf("\t%-7d %-15s\n", listaClientes[i].idCliente, listaClientes[i].nombreEmpresa);
				}
			}

	}
	return estado;
}


int ContarPedidosCompletados (ePedido listaPedidos[], int lenPedidos, eCliente listaClientes[], int lenClientes)
{
	int estado;
	estado = -1;
	int MayorCantidadPedidos;
	int banderaPedidos;
	banderaPedidos = 1;

	eAuxiliar listaAuxiliares[LC];

	if (listaAuxiliares != NULL && LC > 0 && listaPedidos != NULL && lenPedidos > 0 && HayUnPedido(listaPedidos, lenPedidos))
	{
		for (int i = 0; i < lenClientes; i++)
		{
			if(!listaClientes[i].isEmpty)
			{
				listaAuxiliares[i].idCliente = listaClientes[i].idCliente;
				listaAuxiliares[i].contador = 0;
			}
		}

		for(int i=0; i<LC; i++)
		{
			if(!listaClientes[i].isEmpty)

			for (int j = 0; j < lenPedidos; j++)
			{
				if(!listaPedidos[j].isEmpty  && listaPedidos[j].idCliente == listaAuxiliares[i].idCliente && listaPedidos[j].estado == COMPLETADO)
				{
					listaAuxiliares[i].contador ++;
				}
			}
		}

		for(int i=0; i<LC; i++)
		{
			if (!listaClientes[i].isEmpty && (banderaPedidos || listaAuxiliares[i].contador > MayorCantidadPedidos))
			{
				MayorCantidadPedidos = listaAuxiliares[i].contador;
				banderaPedidos = 0;
			}
		}

		printf("\n Los clientes con mas pedidos completados son: ");

		printf("\n\tID\tEMPRESA\t\tCUIT\t\t DIRECCION\t  LOCALIDAD\n"
				"_____________________________________________________________________________\n");

			for(int i = 0; i < lenClientes; i++)
			{
				if (!listaClientes[i].isEmpty && listaAuxiliares[i].contador == MayorCantidadPedidos)
				{
					printf("\t%-7d %-15s\n", listaClientes[i].idCliente, listaClientes[i].nombreEmpresa);
				}
			}

	}
	return estado;
}








