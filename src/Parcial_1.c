
#include "informes.h"

int main()
{
	setbuf(stdout, NULL);
	int opcion;
	char salir[2];
	int idBuscado;
	char respuesta[2];
	int pendientesPorLocalidad;
	float kilosTotales;
	int cantidadClientes;
	float promedioReciclado;

	eCliente listaClientes [LC] =
	{{10, "empresa 1", "20123456789", "calle 1", 1, 0},{11, "empresa 2", "20123456790", "calle 2", 2, 0},
    {12, "empresa 3", "20123456791", "calle 3", 3, 0},{13, "empresa 4", "20123456792", "calle 4", 4, 0},
    {14, "empresa 5", "20123456793", "calle 5", 5, 0}};

	eLocalidad listaLocalidades[LL] =
	{{1,"localidad 1", 0},{2,"localidad 2", 0},{3,"localidad 3", 0},{4,"localidad 4", 0},{5,"localidad 5", 0},
	{0,"x",1},{0,"x",1},{0,"x",1},{0,"x",1},{0,"x",1}};

	ePedido listaPedidos [LP]
	= {{1, 10,2500,0,0,0,1,0},{2, 10,500,0,0,0,1,0},{3, 10, 4500,0,0,0,1,0},{4, 11, 50,0,0,0,1,0},{5, 11, 500,0,0,0,1,0},
	{6, 10, 100,0,0,0,1,0},{7, 12, 500,0,0,0,1,0},{8, 14, 5000,0,0,0,1,0},{9, 14, 800,0,0,0,1,0},{10, 14, 5400,0,0,0,1,0}};



	//if (InicializarPedidos(listaPedidos, LP)!=-1)
	//{
		do
		{
			opcion = MostrarMenuDeOpciones();

			switch (opcion)
			{
				case 1: // OPCION 1 - ALTA DE CLIENTE

					system("cls");
					if(CargarCliente(listaClientes, LC)!=-1)
					{
						printf("Cliente cargado con exito. Se le asigno el Numero de ID: %d", EncontrarUltimoIdCliente(listaClientes, LC));
					}

					else
					{
						printf("ERROR. No se puede cargar");
					}

				break;

				case 2: // OPCION 2 - MODIFICAR DATOS DE CLIENTE

					system("cls");
					if(HayUnCliente(listaClientes, LC)==1)
					{
						ImprimirClientes(listaClientes, LC, listaLocalidades, LL);
						idBuscado = PedirEnteroPositivo("\n\n Ingrese ID del cliente que desear modificar: ");
						system("cls");
						printf("\t\tMODIFICACION DE CLIENTE\n"
								"___________________________________________________________________\n\n");

						ImprimirUnClientePorId(listaClientes, LC, listaLocalidades, LL, idBuscado);

						ImprimirConOpciones(EditarCliente(listaClientes, LC, EncontrarClientePorId(listaClientes, LC, idBuscado)),
															"\n No se pudo editar.", "\n Datos actualizados.");
					}
					else

					{
						printf("\n No hay cargas realizadas");
					}
				break;


				case 3: // OPCION 3 - BAJA DE CLIENTE
					system("cls");
					if(HayUnCliente(listaClientes, LC)==1)
					{
						ImprimirClientes(listaClientes, LC, listaLocalidades, LL);
						idBuscado = PedirEnteroPositivo("\n\n Ingrese ID del cliente que desear eliminar: ");
						system("cls");
						printf("\t\tBAJA DE CLIENTE\n"
								"__________________________________________________________________________________\n\n");

						if(ImprimirUnClientePorId(listaClientes, LC, listaLocalidades, LL, idBuscado)!=-1)
						{
							PedirCadena("\n\n Seguro desea eliminar el cliente seleccionado?. S/N: ", respuesta, sizeof(respuesta));

							if (stricmp(respuesta, "S")==0)
							{
								ImprimirConOpciones(EliminarCliente(listaClientes, LC, listaPedidos, LP, idBuscado), "\n No se pudo eliminar.", "\n Cliente eliminado.");
							}
							else
							{
								printf("\n Baja cancelada");
							}
						}
						else
						{
							printf("\n Error en ID");
						}

					}
					else
					{
						printf("\n No hay cargas realizadas");
					}
				break;

				case 4: // OPCION 4 - CREAR PEDIDO DE RECOLECCIÓN

					if(HayUnCliente(listaClientes, LC)==1)
					{
						if (HayEspacioVacioPedido(listaPedidos, LP)==1)
						{
							ImprimirClientes(listaClientes, LC, listaLocalidades, LL);

							idBuscado = PedirEnteroPositivo("\n\n Ingrese ID del cliente para cargar pedido: ");

							if(EncontrarClientePorId(listaClientes, LC, idBuscado)!=-1)
							{
								ImprimirConOpciones(CargarPedido(listaPedidos, LP, idBuscado), "\n ERROR. No se puede cargar", "\n Pedido cargado con exito.");
							}
							else
							{
								printf("\n ID no encontrado.");
							}
						}
						else
						{
							printf("\n No se pueden cargar mas pedidos.");
						}
					}
					else
					{
						printf("\n No hay cargas realizadas");
					}
				break;

				case 5: // OPCION 5 - PROCESAR RESIDUOS
					if(HayUnPedido(listaPedidos, LP)==1)
					{
						ImprimirPedidosPendientes(listaPedidos, LP, listaClientes, LC);

						idBuscado = PedirEnteroPositivo("\n\n Ingrese ID del pedido para procesar residuos: ");

						ImprimirConOpciones(ProcesarResiduos(listaPedidos, LP, idBuscado), "\n ERROR. No se puede procesar.", "\n Pedido procesado.");
					}
					else
					{


					}

				break;

				case 6: // OPCION 6 - IMPRIMIR CLIENTES

					ImprimirClientesConPedidosPendientes(listaClientes, LC, listaLocalidades, LL, listaPedidos, LP);

				break;

				case 7: // OPCION 7 - IMPRIMIR PENDIENTES
					system("cls");
					printf("\t\tPEDIDOS PENDIENTES\n"
							"___________________________________________________________________\n\n");

				ImprimirPedidosPendientesConDatosCliente(listaPedidos, LP, listaClientes, LC);

				break;

				case 8: // OPCION 8 - IMPRIMIR PROCESADOS
					system("cls");
					printf("\t\tPEDIDOS COMPLETADOS\n"
							"___________________________________________________________________\n\n");


					ImprimirPedidosCompletadosConDatosCliente(listaPedidos, LP, listaClientes, LC);

				break;

				case 9:
					ImprimirConOpciones(ImprimirLocalidades(listaLocalidades, LL), "\n ERROR", "");

					if(ContarPedidosPendientesPorLocalidad(listaPedidos, LP, listaClientes, LC, listaLocalidades, LL, &pendientesPorLocalidad)!=-1)
					{
						printf("\n La localidad tiene %d pedidos pendientes", pendientesPorLocalidad);
					}
				break;

				case 10:
					kilosTotales = SumarKilosProcesados(listaPedidos, LP);

					cantidadClientes = ContarClientes(listaClientes, LC);

					ImprimirConOpciones(promedioReciclado = CalcularPromedioKilosReciclados(kilosTotales, cantidadClientes),
							"\n No se pudo calcular promedio.", "\n El promedio por cliente de los kilos procesados es: ");
					printf("%.2f kg", promedioReciclado);
				break;

				case 20:
					ImprimirConOpciones(ImprimirLocalidades(listaLocalidades, LL), "\n ERROR", "");

					idBuscado = PedirEnteroPositivo("\n\n Ingrese ID de la localidad que desear eliminar: ");

					PedirCadena("\n\n Seguro desea eliminar el cliente seleccionado?. S/N: ", respuesta, sizeof(respuesta));

					if (stricmp(respuesta, "S")==0)
					{
						ImprimirConOpciones(BajaLocalidad(listaClientes, LC, listaPedidos, LP, listaLocalidades, LL, idBuscado),
											"\n No se pudo eliminar.", "\n Localidad eliminada.");
					}
					else
					{
						{
							printf("\n Baja cancelada");
						}
					}
				break;


			}

		}while(opcion != 0);

		system ("cls");
		printf("\n Hasta pronto. Que tenga un lindo dia.");

		PedirCadena("\n\n Toque una tecla para cerrar la ventana: ", salir, sizeof(salir)); //Esta linea es para dejar la consola a la espera y que no se cierre automaticamente
		printf("%s",salir); //Esta linea es para evitar el warning por no utilizar la variable "salir".
	/*}
	else
	{
		printf("\n No se pudo inicializar");
	}*/

	return 0;
}
