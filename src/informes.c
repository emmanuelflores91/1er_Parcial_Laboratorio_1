#include "informes.h"

static int NuevoIdCliente();

static void InicializarListaAuxiliares (eAuxiliar listaAuxiliares[], eCliente listaClientes[], int lenClientes);

static void IncrementarContador (eAuxiliar listaAuxiliares[], eCliente listaClientes[], int lenClientes, ePedido listaPedidos[], int lenPedidos, int estadoPedido);

static int EncontrarMayorCantidadPedidos (eAuxiliar listaAuxiliares[], eCliente listaClientes[], int lenClientes);

static int ImprimirMayoresCantidadesDePedidos (eAuxiliar listaAuxiliares[], eCliente listaClientes[], int lenClientes, int MayorCantidadPedidos);


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
				" 10 - Cantidad de kilos reciclados promedio por cliente.\n"
				" 11 - Alta de localidad.\n"
				" 12 - Baja de localidad.\n"
				" 13 - Modificar localidad.\n"
				" 14 - Clientes con mas pedidos pendientes.\n"
				" 15 - Clientes con mas pedidos completados.\n"
				" 0 - Salir.\n");
		printf("\n.......................................................\n");

		if(PedirEnteroEnRango(&opcion,"\n Ingrese una opcion: ","\n Opcion incorrecta", 0, 15,2)== -1)
		{
			printf("\n No se puedo acceder. ");
		}


		return opcion;
}

static int NuevoIdCliente()
{
	static int id;
	id = 5;
	id ++;

	return id;
}

int CargarCliente (eCliente listaClientes[], int lenClientes, eLocalidad listaLocalidades[], int lenLocalidades)
{
	int estado;
	int index;

	estado = -1;

	if (listaClientes != NULL && lenClientes > 0)
	{
		index = HayEspacioVacioCliente(listaClientes, lenClientes);


			if(index != -1)
			{
				if(PedirCadena("\n Ingrese nombre de la empresa: ", "\n Nombre incorrecto", listaClientes[index].nombreEmpresa,
					sizeof(listaClientes[index].nombreEmpresa), 2) == 0 &&
					PedirCadena("\n Ingrese CUIT sin guiones ni espacios: ", "\n CUIT incorrecto", listaClientes[index].cuit,
					sizeof(listaClientes[index].cuit), 3) == 0 &&
					PedirCadena("\n Ingrese direccion: ", "\n Direccion incorrecta", listaClientes[index].direccion,
					sizeof(listaClientes[index].direccion), 3) == 0 &&
					PedirLocalidad(listaLocalidades, "\n ID incorrecto", lenLocalidades, 2, &listaClientes[index].idLocalidad) == 0)
				{
					listaClientes[index].idCliente = NuevoIdCliente();
					listaClientes[index].isEmpty = 0;
					estado = listaClientes[index].idCliente;
				}
			}
	}
		system("cls");

		return estado;
}

int ImprimirUnClientePorId (eCliente listaClientes[], int lenClientes, eLocalidad listaLocalidades[], int lenLocalidades, int id)
{
	int estado;
	int index;
	estado = -1;

	if (listaClientes !=NULL && listaLocalidades !=NULL && lenClientes > 0 && lenLocalidades > 0)
	{
		index = EncontrarClientePorId(listaClientes, lenClientes, id);

		if (index != -1)
		{
			printf("\n\tID\tEMPRESA\t\tCUIT\t\t DIRECCION\t  LOCALIDAD\n"
					"_____________________________________________________________________________\n");

			for(int j = 0; j < lenLocalidades; j++)
			{
				if (!listaLocalidades[j].isEmpty && listaClientes[index].idLocalidad == listaLocalidades[j].idLocalidad)
				{
					printf("\t%-7d %-15s %-16s %-17s %-15s\n",
					listaClientes[index].idCliente, listaClientes[index].nombreEmpresa, listaClientes[index].cuit,
					listaClientes[index].direccion, listaLocalidades[j].descripcionLocalidad);

					estado = 0;
					break;
				}
			}
		}
	}
	return estado;
}

int ImprimirClientes(eCliente listaClientes[], int lenClientes, eLocalidad listaLocalidades[], int lenLocalidades)
{
	int estado;
	int flag;
	flag = 1;
	estado = -1;

	if (listaClientes !=NULL && listaLocalidades !=NULL && lenClientes > 0 && lenLocalidades > 0)
	{
		for(int i = 0; i < lenClientes; i++)
		{

			if(!listaClientes[i].isEmpty)
			{
				if(flag)
				{
					printf("\n\tID\tEMPRESA\t\tCUIT\t\t DIRECCION\t  LOCALIDAD\n"
					"_____________________________________________________________________________\n");
					flag = 0;
				}

				for(int j = 0; j < lenLocalidades; j++)
				{
					if(!listaLocalidades[j].isEmpty && listaClientes[i].idLocalidad == listaLocalidades[j].idLocalidad)
					{
						printf("\t%-7d %-15s %-16s %-17s %-15s\n",
						listaClientes[i].idCliente, listaClientes[i].nombreEmpresa, listaClientes[i].cuit,
						listaClientes[i].direccion, listaLocalidades[j].descripcionLocalidad);

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
	int flag;

	flag = 1;
	estado = -1;

	if (listaClientes !=NULL && listaLocalidades !=NULL && lenClientes > 0 && lenLocalidades > 0)
	{
		for(int i = 0; i < lenClientes; i++)
		{

			if(!listaClientes[i].isEmpty && ContarPedidosPendientePorID(listaPedidos, lenPedidos, listaClientes[i].idCliente, &cantidadPendientes)!=-1)
			{
				if(flag)
				{
					printf("\n\tID\tEMPRESA\t\tCUIT\t\t DIRECCION\t  LOCALIDAD      PEDIDOS PENDIENTES\n"
					"______________________________________________________________________________________________\n");
					flag = 0;
				}

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

/*int ImprimirUnPedidoPendientePorId (ePedido list[], int len, int id)
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
}*/

int ImprimirPedidosPendientes(ePedido listaPedidos[], int lenPedidos, eCliente listaClientes[], int lenClientes)
{
	int estado;
	int flag;
	flag = 1;
	estado = -1;

	if (listaPedidos !=NULL && listaClientes !=NULL && lenPedidos > 0 && lenClientes > 0)
	{
		for(int i = 0; i < lenPedidos; i++)
		{

			if(!listaPedidos[i].isEmpty && listaPedidos[i].estado == PENDIENTE )
			{
				if(flag)
				{
					printf("\n\tID PEDIDO\tCLIENTE\t\tCANTIDAD TOTAL DE KG\n"
							"_______________________________________________________________\n");
					flag = 0;
				}
				for( int j = 0; j < lenClientes; j++)
				{
					if(!listaClientes[j].isEmpty && listaPedidos[i].idCliente == listaClientes[j].idCliente)
					{
						printf("\t    %-12d %-15s       %.2f kg\n", listaPedidos[i].idPedido, listaClientes[j].nombreEmpresa,
								listaPedidos[i].cantidadKilosTotal);
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
	int flag;
	flag = 1;
	estado = -1;

	if (listaPedidos !=NULL && listaClientes !=NULL && lenPedidos > 0 && lenClientes > 0)
	{

		for(int i = 0; i < lenPedidos; i++)
		{

			if(!listaPedidos[i].isEmpty && listaPedidos[i].estado == PENDIENTE )
			{
				if(flag)
				{
					printf("\n\tCUIT CLIENTE\tDIRECCION\t CANTIDAD TOTAL DE KG\n"
							"____________________________________________________________________\n");
					flag = 0;
				}
				for( int j = 0; j < lenClientes; j++)
				{
					if(!listaClientes[j].isEmpty && listaPedidos[i].idCliente == listaClientes[j].idCliente)
					{
						printf("\t%-15s %-18s   %.2f kg\n", listaClientes[j].cuit, listaClientes[j].direccion,
								listaPedidos[i].cantidadKilosTotal);
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
	int flag;
	flag = 1;
	estado = -1;

	if (listaPedidos !=NULL && listaClientes !=NULL && lenPedidos > 0 && lenClientes > 0)
	{
		for(int i = 0; i < lenPedidos; i++)
		{
			if(!listaPedidos[i].isEmpty && listaPedidos[i].estado == COMPLETADO )
			{
				if(flag)
				{
					printf("\t\tPEDIDOS COMPLETADOS\n"
							"___________________________________________________________________\n\n");

					printf("\n\tCUIT CLIENTE\tDIRECCION\t CANTIDAD TOTAL DE KG\t CANTIDAD DE KG DE HDPE\t CANTIDAD DE KG DE LDPE\t CANTIDAD DE KG DE PP\n"
							"____________________________________________________________________\n");

					flag = 0;
				}
				for( int j = 0; j < lenClientes; j++)
				{
					if(!listaClientes[j].isEmpty && listaPedidos[i].idCliente == listaClientes[j].idCliente)
					{
						printf("\t%-15s %-18s   %.2f kg   %.2f kg   %.2f kg   %.2f kg\n", listaClientes[j].cuit, listaClientes[j].direccion,
								listaPedidos[i].cantidadKilosTotal,listaPedidos[i].kilosHDPE,listaPedidos[i].kilosLDPE,listaPedidos[i].kilosPP);
						estado = 0;
					}
				}
			}
		}
	}

	return estado;
}

int ProcesarResiduos (ePedido list[], int len, int idPedido)
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
			if(!list[i].isEmpty && list[i].idPedido == idPedido && list[i].estado == PENDIENTE)
			{
				if(VerificarCargaDeKilos(list[i].cantidadKilosTotal, &list[i].kilosHDPE, &list[i].kilosLDPE, &list[i].kilosPP,
				"\n Error, cantidad kilos incorrecta.", 3) == 0)
				{
					list[i].estado = COMPLETADO;
					estado = 0;
				}
				break;
			}
		}
	}
		system("cls");

	return estado;
}

int VerificarCargaDeKilos (float kilosTotales, float* kilosHDPE, float* kilosLDPE, float* kilosPP, char mensajeError[], int cantidadReintentos)
{
	int estado;
	float auxHDPE;
	float auxLDPE;
	float auxPP;

	estado = -1;

	do
	{
		if(PedirFlotante(&auxHDPE,"\n Ingrese cantidad de kilos de HDPE: ", "\n Error en datos.", 2) == 0 &&
		PedirFlotante(&auxLDPE,"\n Ingrese cantidad de kilos de LDPE: ", "\n Error en datos.", 2) == 0 &&
		PedirFlotante(&auxPP,"\n Ingrese cantidad de kilos de PP: ","\n Error en datos.", 2) == 0 &&
		kilosTotales >= auxHDPE + auxLDPE  + auxPP)
		{
			*kilosHDPE = auxHDPE;
			*kilosLDPE = auxLDPE;
			*kilosPP = auxPP;
			estado = 0;
			break;
		}
		printf("%s",mensajeError);

		cantidadReintentos--;


	}while(cantidadReintentos >= 0);

	return estado;
}

int ContarPedidosPendientesPorLocalidad (ePedido listaPedidos[], int lenPedidos, eCliente listaClientes[], int lenClientes, eLocalidad listaLocalidades[], int lenLocalidades, int* cantidadPendientes)
{
	int estado;
	int contadorPedidosPendientes;
	int idLocalidad;

	estado = -1;
	contadorPedidosPendientes = 0;

	if (listaPedidos !=NULL && listaLocalidades !=NULL && lenPedidos > 0 && lenLocalidades > 0)
	{
		if(PedirLocalidad(listaLocalidades, "Error en ID", lenLocalidades, 3, &idLocalidad) == 0)

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
	}
	*cantidadPendientes = contadorPedidosPendientes;
	return estado;
}

int CalcularPromedioKilosReciclados (float kilosTotales, int cantidadClientes, float* promedio)
{
	int estado;
	estado = -1;

	if(cantidadClientes > 0)
	{
		*promedio = kilosTotales / cantidadClientes;
		estado = 0;
	}

	return estado;
}

int EliminarCliente(eCliente listaClientes[], int lenClientes, ePedido listaPedidos[], int lenPedidos, int id)
{
	int estado;
	estado = -1;

	if (listaClientes != NULL && lenClientes > 0 && listaPedidos != NULL && lenPedidos > 0)
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
		listaLocalidades != NULL && lenLocalidades > 0)
	{
		for(int i = 0; i < lenLocalidades; i++)
		{

			if(!listaLocalidades[i].isEmpty && idLocalidad == listaLocalidades[i].idLocalidad)
			{
				listaLocalidades[i].isEmpty = 1;
				estado = 0;

				for(int j = 0; j < lenClientes; j++)
				{
					if(!listaClientes[j].isEmpty && listaClientes[j].idLocalidad == listaLocalidades[i].idLocalidad)
					{
						EliminarCliente(listaClientes, lenClientes, listaPedidos, lenPedidos, listaClientes[i].idCliente);
					}
				}
			}
		}
	}
	return estado;
}

int ContarPedidosPorEstado (ePedido listaPedidos[], int lenPedidos, eCliente listaClientes[], int lenClientes, int estadoPedido)
{
	int estado;
	estado = -1;
	int MayorCantidadPedidos;

	eAuxiliar listaAuxiliares[lenClientes];

	if (listaAuxiliares != NULL && lenClientes > 0 && listaPedidos != NULL && lenPedidos > 0)
	{

		InicializarListaAuxiliares (listaAuxiliares, listaClientes, lenClientes);

		IncrementarContador(listaAuxiliares, listaClientes, lenClientes, listaPedidos, lenPedidos, estadoPedido);

		MayorCantidadPedidos = EncontrarMayorCantidadPedidos(listaAuxiliares, listaClientes, lenClientes);

		estado = ImprimirMayoresCantidadesDePedidos(listaAuxiliares, listaClientes, lenClientes, MayorCantidadPedidos);

	}
	return estado;
}

static void InicializarListaAuxiliares (eAuxiliar listaAuxiliares[], eCliente listaClientes[], int lenClientes)
{
	for (int i = 0; i < lenClientes; i++)
	{
		if(!listaClientes[i].isEmpty)
		{
			listaAuxiliares[i].idCliente = listaClientes[i].idCliente;
			listaAuxiliares[i].contador = 0;
		}
	}
}

static void IncrementarContador (eAuxiliar listaAuxiliares[], eCliente listaClientes[], int lenClientes, ePedido listaPedidos[], int lenPedidos, int estadoPedido)
{
	for(int i=0; i<lenClientes; i++)
	{
		if(!listaClientes[i].isEmpty)

		for (int j = 0; j < lenPedidos; j++)
		{
			if(!listaPedidos[j].isEmpty  && listaPedidos[j].idCliente == listaAuxiliares[i].idCliente && listaPedidos[j].estado == estadoPedido)
			{
				listaAuxiliares[i].contador ++;
			}
		}
	}
}

static int EncontrarMayorCantidadPedidos (eAuxiliar listaAuxiliares[], eCliente listaClientes[], int lenClientes)
{
	int MayorCantidadPedidos;
	int banderaPedidos;
	banderaPedidos = 1;

	for(int i=0; i<lenClientes; i++)
	{
		if (!listaClientes[i].isEmpty && (banderaPedidos || listaAuxiliares[i].contador > MayorCantidadPedidos))
		{
			MayorCantidadPedidos = listaAuxiliares[i].contador;
			banderaPedidos = 0;
		}
	}

	return MayorCantidadPedidos;
}

static int ImprimirMayoresCantidadesDePedidos (eAuxiliar listaAuxiliares[], eCliente listaClientes[], int lenClientes, int MayorCantidadPedidos)

{
	int estado;
	estado = -1;

	for(int i = 0; i < lenClientes; i++)
	{
		if (!listaClientes[i].isEmpty && listaAuxiliares[i].contador == MayorCantidadPedidos)
		{
			printf("\t%-7d %-15s\n", listaClientes[i].idCliente, listaClientes[i].nombreEmpresa);
			estado = 0;
		}
	}

	return estado;
}

int EditarCliente(eCliente listaClientes[], int lenClientes, eLocalidad listaLocalidades[], int lenLocalidades, int index)
{
	int estado;
	estado = -1;
	int opcion;


	if (listaClientes != NULL && lenClientes > 0)
	{

			if(PedirEnteroEnRango(&opcion,"\n 1 - Direccion."
										"\n 2 - Localidad."
										"\n\n Ingrese la opcion que desea editar: ",
										"\n Error en opcion",1, 2, 3) == 0)
			{
				if (opcion == 1)
				{
					if(PedirCadena("\n Ingrese direccion: ", "\n Error en datos.", listaClientes[index].direccion,
									sizeof(listaClientes[index].direccion),3) == 0)
					{
						estado = 0;
					}
				}
				else
				{
					if(PedirLocalidad(listaLocalidades, "Error en ID", lenLocalidades, 3, &listaClientes[index].idLocalidad) == 0)
					{
						estado = 0;
					}
				}
			}
	}
	system("cls");
	return estado;
}







