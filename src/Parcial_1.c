
#include "informes.h"

int main()
{
	setbuf(stdout, NULL);
	int opcion;
	int idBuscado;
	int idCargado;
	char respuesta[2];
	int pendientesPorLocalidad;
	float promedioReciclado;

	eCliente listaClientes [LC] =
	{{10, "empresa 1", "20123456789", "calle 1", 1, 0},{11, "empresa 2", "20123456790", "calle 2", 2, 0},
    {12, "empresa 3", "20123456791", "calle 3", 3, 0},{13, "empresa 4", "20123456792", "calle 4", 4, 0},
    {14, "empresa 5", "20123456793", "calle 5", 5, 1}};

	eLocalidad listaLocalidades[LL] =
	{{1,"localidad 1", 0},{2,"localidad 2", 0},{3,"localidad 3", 0},{4,"localidad 4", 0},{5,"localidad 5", 0},
	{0,"x",1},{0,"x",1},{0,"x",1},{0,"x",1},{0,"x",1}};

	ePedido listaPedidos [LP] = {{1, 10,2500,0,0,0,1,0},{2, 10,500,0,0,0,1,0},{3, 10, 4500,0,0,0,1,0},{4, 11, 50,0,0,0,1,0},{5, 11, 500,0,0,0,1,0},
	{6, 11, 100,95,1,1,2,0},{7, 11, 500,15,6,8,2,0},{8, 14, 5000,1,2,36,2,1},{9, 14, 800,0,0,0,1,1},{10, 10, 5400,0,0,0,1,1}};



	//if (InicializarPedidos(listaPedidos, LP)!=-1)
	//{
		do
		{
			opcion = MostrarMenuDeOpciones();

			switch (opcion)
			{
				case 1: // OPCION 1 - ALTA DE CLIENTE
					system("cls");
					printf("\tALTA DE CLIENTE\n"
							"_________________________________\n\n");

					idCargado = CargarCliente(listaClientes, LC, listaLocalidades, LL);

					if(idCargado != -1)
					{
						printf("Cliente cargado con exito. Se le asigno el Numero de ID: %d", idCargado);
					}

					else
					{
						printf("ERROR. No se puede cargar");
					}

				break;

				case 2: // OPCION 2 - MODIFICAR DATOS DE CLIENTE

					system("cls");
					if(ImprimirClientes(listaClientes, LC, listaLocalidades, LL) == 0)
					{
						if(PedirEnteroPositivo(&idBuscado,"\n\n Ingrese ID del cliente que desear modificar: ",
											"Error en ID", 3)==0)
						{
						ImprimirUnClientePorId(listaClientes, LC, listaLocalidades, LL, idBuscado);

						ImprimirDosMensajes(EditarCliente(listaClientes, LC, listaLocalidades, LL,
											EncontrarClientePorId(listaClientes, LC, idBuscado)),
											"\n No se pudo editar.", "\n Datos actualizados.");
						}
					}
					else
					{
						printf("\n No hay cargas realizadas");
					}
				break;


				case 3: // OPCION 3 - BAJA DE CLIENTE
				system("cls");

					if(ImprimirClientes(listaClientes, LC, listaLocalidades, LL) == 0)
					{
						if(PedirEnteroPositivo(&idBuscado, "\n\n Ingrese ID del cliente que desear eliminar: ",
												"Error en ID.",3)==0)
						{
							if(ImprimirUnClientePorId(listaClientes, LC, listaLocalidades, LL, idBuscado)== 0)
							{
								if(PedirCadena("\n\n Seguro desea eliminar el cliente seleccionado?. S/N: ","\n Error en respuesta.", respuesta, sizeof(respuesta),3)== 0)
								{

									if (stricmp(respuesta, "S")==0)
									{
										ImprimirDosMensajes(EliminarCliente(listaClientes, LC, listaPedidos, LP, idBuscado),
															"\n No se pudo eliminar.", "\n Cliente eliminado.");
									}
									else
									{
										printf("\n Baja cancelada");
									}
								}
							}
						}
					}
					else
					{
						printf("\n No hay cargas realizadas");
					}
				break;

				case 4: // OPCION 4 - CREAR PEDIDO DE RECOLECCIÓN
				system("cls");

				if(ImprimirClientes(listaClientes, LC, listaLocalidades, LL)== 0)
				{
					if(PedirEnteroPositivo(&idBuscado,"\n\n Ingrese ID del cliente para cargar pedido: ","Error en ID.",3)== 0)
					{

						if(EncontrarClientePorId(listaClientes, LC, idBuscado)!=-1)
						{
							ImprimirDosMensajes(CargarPedido(listaPedidos, LP, idBuscado),
												"\n ERROR. No se puede cargar", "\n Pedido cargado con exito.");
						}
						else
						{
							printf("\n ID no encontrado.");
						}
					}
				}
				else
				{
					printf("\n No se puede crear pedido.");
				}
				break;

				case 5: // OPCION 5 - PROCESAR RESIDUOS
				system("cls");
					if(ImprimirPedidosPendientes(listaPedidos, LP, listaClientes, LC)== 0)
					{
						if(PedirEnteroPositivo(&idBuscado,"\n\n Ingrese ID del pedido para procesar residuos: ",
												"\n Error en ID.", 3)== 0)
						{
							ImprimirDosMensajes(ProcesarResiduos(listaPedidos, LP, idBuscado),
												"\n ERROR. No se puede procesar.", "\n Pedido procesado.");
						}
					}
					else
					{
						printf("\n No se puede procesar.");
					}

				break;

				case 6: // OPCION 6 - IMPRIMIR CLIENTES
				system("cls");
					if(ImprimirClientesConPedidosPendientes(listaClientes, LC, listaLocalidades, LL, listaPedidos, LP)== -1)
					{
						printf("\n No se pudo imprimir.");
					}

				break;

				case 7: // OPCION 7 - IMPRIMIR PENDIENTES

				system("cls");
				if(HayUnPedido(listaPedidos, LP))
				{
					printf("\t\tPEDIDOS PENDIENTES\n");

					if(ImprimirPedidosPendientesConDatosCliente(listaPedidos, LP, listaClientes, LC) == -1)
					{
						printf("\n Error en impresion.");

					}
				}
				else
				{
					printf("\n No hay pedidos pendientes.");
				}

				break;

				case 8: // OPCION 8 - IMPRIMIR PROCESADOS
				system("cls");

					if (ImprimirPedidosCompletadosConDatosCliente(listaPedidos, LP, listaClientes, LC)== -1)
					{
						printf("\n No hay pedidos procesados.");
					}

				break;

				case 9: //PEDIDOS PENDIENTES POR LOCALIDAD
				system("cls");

					if(HayUnaLocalidad(listaLocalidades, LC))
					{
						if(ContarPedidosPendientesPorLocalidad(listaPedidos, LP, listaClientes, LC, listaLocalidades, LL, &pendientesPorLocalidad)== 0)
						{
							printf("\n La localidad tiene %d pedidos pendientes", pendientesPorLocalidad);
						}
						else
						{
							printf("\n La localidad no tiene pedidos pendientes");
						}
					}
					else
					{
						printf("\n No se pudo obtener informacion");
					}

				break;

				case 10: // CANTIDAD DE PP PROMEDIO POR CLIENTE
				system("cls");

				if (CalcularPromedioKilosReciclados(listaClientes, LC, listaPedidos, LP, &promedioReciclado) != -1)
				{
					printf("\n El promedio por cliente de los kilos procesados es: %.2f kg", promedioReciclado);
				}
				else
				{
				printf("\n No se pudo calcular promedio.");

				}

				break;

				case 11: //ALTA LOCALIDAD
				system("cls");

					if(CargarLocalidad(listaLocalidades, LL)== -1)
					{
						printf("\n No se pudo cargar localidad.");
					}
					else
					{
						printf("\n Se cargo la localidad con exito.");
					}

				break;

				case 12: //BAJA LOCALIDAD
				system("cls");

					if(PedirLocalidad(listaLocalidades, "Error en ID", LL, 3, &idBuscado) == 0)
					{

						if (PedirCadena("\n\n Seguro desea eliminar la localidad seleccionado?. S/N: ","Error en datos.",
							respuesta, sizeof(respuesta),3)== 0)
						{

							if (stricmp(respuesta, "S")==0)
							{
								ImprimirDosMensajes(BajaLocalidad(listaClientes, LC, listaPedidos, LP, listaLocalidades, LL, idBuscado),
													"\n No se pudo eliminar.", "\n Localidad eliminada.");
							}
							else
							{

								printf("\n Baja cancelada");

							}
						}
						else
						{
							printf("\n No se pudo acceder a baja.");
						}
					}
				break;

				case 13: // MODIFICAR LOCALIDAD
				system("cls");

					if(PedirLocalidad(listaLocalidades, "Error en ID", LL, 3, &idBuscado) == 0)
					{

					ImprimirDosMensajes(EditarLocalidad(listaLocalidades, LL,
										EncontrarLocalidadPorId(listaLocalidades, LL, idBuscado)),
										"\n No se pudo Editar", "\n Localidad editada");
					}
					else
					{
						printf("\n No se pudo acceder a modificacion");
					}
				break;

				case 14: // MAS PEDIDOS PENDIENTES
				system("cls");


				if (HayUnPedido(listaPedidos, LP))
				{
					printf("\n Los clientes con mas pedidos pendientes son: ");

					printf("\n\tID\tEMPRESA\n"
							"__________________________________________\n");

					if (ContarPedidosPorEstado(listaPedidos, LP, listaClientes, LC, PENDIENTE)== -1)
					{
						printf("\n No se pudo calcular.");
					}
				}
				else
				{
					printf("\n No hay pedidos pendientes");
				}


				break;

				case 15: // MAS PEDIDOS COMPLETADOS
				system("cls");

					if (HayPedidosCompletados(listaPedidos, LP))
					{
						printf("\n Los clientes con mas pedidos completados son: ");

						printf("\n\tID\tEMPRESA\n"
								" __________________________________________________\n");
						if(ContarPedidosPorEstado(listaPedidos, LP, listaClientes, LC, COMPLETADO)== -1)
						{
							printf("\n No se pudo calcular.");
						}
					}
					else
					{
						printf("\n No hay pedidos completados.");
					}
				break;
			}

		}while(opcion != 0);

		system ("cls");
		printf("\n Hasta pronto. Que tenga un lindo dia.\n\n");
		system(" pause");

	/*}
	else
	{
		printf("\n No se pudo inicializar");
	}*/

	return 0;
}
