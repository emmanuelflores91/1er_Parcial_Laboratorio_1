
#ifndef INFORMES_H_
#define INFORMES_H_
#include "clientes.h"
#include "pedidos.h"
#include "localidades.h"
#include "myFunctions.h"

typedef struct
{
	int idCliente;
	int contador;

}eAuxiliar;

/// @brief muetra el menú de opciones y pide que se ingrese una opción-
///
/// @return retorna la opción ingresada.
int MostrarMenuDeOpciones ();


/// @brief agrega un nuevo cliente en la primer posición vacía del vector.
///
/// @param listaClientes = vector con listado de clientes.
/// @param lenClientes = largo del vector de clientes.
/// @param listaLocalidades = vector con listado de localidades.
/// @param lenLocalidades = largo del vector de localidades.
/// @return retorna -1 en caso de error o el índice del ID del cliente cargado.
int CargarCliente (eCliente listaClientes[], int lenClientes, eLocalidad listaLocalidades[], int lenLocalidades);


/// @brief imprime los datos de un cliente en base al ID-
///
/// @param listaClientes = vector con listado de clientes.
/// @param lenClientes = largo del vector de clientes.
/// @param listaLocalidades = vector con listado de localidades.
/// @param lenLocalidades = largo del vector de localidades.
/// @param id = el ID buscado.
/// @return -1 en caso de error, 0 en caso que se haya podido realizar la operación.
int ImprimirUnClientePorId (eCliente listaClientes[], int lenClientes, eLocalidad listaLocalidades[], int lenLocalidades, int id);


/// @brief imprime listado de clientes con todos sus datos.
///
/// @param listaClientes = vector con listado de clientes.
/// @param lenClientes = largo del vector de clientes.
/// @param listaLocalidades = vector con listado de localidades.
/// @param lenLocalidades = largo del vector de localidades.
/// @return -1 en caso de error, 0 en caso que se haya podido realizar la operación.
int ImprimirClientes(eCliente listaClientes[], int lenClientes, eLocalidad listaLocalidades[], int lenLocalidades);



/// @brief imprime los pedidos pendientes junto con el ID del cliente correspondiente.
/// @param listaPedidos = vector con listado de clientes.
/// @param lenPedidos = largo del vector de pedidos.
/// @param listaClientes = vector con listado de clientes.
/// @param lenClientes = largo del vector de clientes.
/// @return -1 en caso de error, 0 en caso que se haya podido realizar la operación.
int ImprimirPedidosPendientes(ePedido listaPedidos[], int lenPedidos, eCliente listaClientes[], int lenClientes);

/// @brief permite cargar los kilos de los tres tipos de plástico y luego marcar el pedido como completado
///
/// @param list = vector con listado de pedidos.
/// @param len = largo del vector.
/// @param idCliente = ID buscado al que se desear procesar residuos.
/// @return -1 en caso de error, 0 en caso que se haya podido realizar la operación.
int ProcesarResiduos (ePedido list[], int len, int idCliente);


/// @brief imprime todos los cliente que tengan pedidos pendientes.
///
/// @param listaClientes = vector con listado de clientes.
/// @param lenClientes = largo del vector de clientes.
/// @param listaLocalidades = vector con listado de localidades.
/// @param lenLocalidades = largo del vector de localidades.
/// @param listaPedidos = vector con listado de pedidos.
/// @param lenPedidos = largo del vector de pedidos.
/// @return -1 en caso de error, 0 en caso que se haya podido realizar la operación.
int ImprimirClientesConPedidosPendientes(eCliente listaClientes[], int lenClientes, eLocalidad listaLocalidades[], int lenLocalidades, ePedido listaPedidos[], int lenPedidos);


/// @brief imprime los pedidos pendientes con los datos de los clientes.
///
/// @param listaPedidos = vector con listado de pedidos.
/// @param lenPedidos = largo del vector de pedidos.
/// @param listaClientes = vector con listado de clientes
/// @param lenClientes = largo del vector de clientes
/// @return -1 en caso de error, 0 en caso que se haya podido realizar la operación.
int ImprimirPedidosPendientesConDatosCliente(ePedido listaPedidos[], int lenPedidos, eCliente listaClientes[], int lenClientes);


/// @brief imprime los pedidos completados con los datos de los clientes.
///
/// @param listaPedidos = vector con listado de pedidos.
/// @param lenPedidos = largo del vector de pedidos.
/// @param listaClientes = vector con listado de clientes
/// @param lenClientes = largo del vector de clientes
/// @return -1 en caso de error, 0 en caso que se haya podido realizar la operación.
int ImprimirPedidosCompletadosConDatosCliente(ePedido listaPedidos[], int lenPedidos, eCliente listaClientes[], int lenClientes);


/// @brief
///
/// @param listaPedidos = vector con listado de pedidos.
/// @param lenPedidos = largo del vector de pedidos.
/// @param listaClientes = vector con listado de clientes
/// @param lenClientes = largo del vector de clientes
/// @param listaLocalidades = vector con listado de localidades
/// @param lenLocalidades = largo vector localidades
/// @param cantidadPendientes = puntero que devuelve la cantidad de pedidos pendientes.
/// @return -1 en caso de error, 0 en caso que se haya podido realizar la operación.
int ContarPedidosPendientesPorLocalidad (ePedido listaPedidos[], int lenPedidos, eCliente listaClientes[], int lenClientes, eLocalidad listaLocalidades[], int lenLocalidades, int* cantidadPendientes);


/// @brief calcula el promedio de kilos de Polipropileno reciclados por cliente.
///
/// @param listaClientes = vector con listado de clientes.
/// @param lenClientes = largo vector clientes.
/// @param listaPedidos = vector con listado de pedidos.
/// @param lenPedidos = largo vector pedidos.
/// @param promedio = puntero que devuelve el promedio calculado.
/// @return -1 en caso de error, 0 en caso que se haya podido realizar la operación.
int CalcularPromedioKilosReciclados (eCliente listaClientes[], int lenClientes, ePedido listaPedidos[], int lenPedidos, float* promedio );


/// @brief Elimina un cliente marcandolo como inactivo y elimina en cascada todos los pedidos de dicho cliente.
///
/// @param listaClientes = vector con listado de clientes.
/// @param lenClientes = largo vector clientes.
/// @param listaPedidos = vector con listado de pedidos.
/// @param lenPedidos = largo vector pedidos.
/// @param id = ID de cliente buscado para eliminar.
/// @return -1 en caso de error, 0 en caso que se haya podido realizar la operación.
int EliminarCliente(eCliente listaClientes[], int lenClientes, ePedido listaPedidos[], int lenPedidos, int id);


/// @brief elimina una localidad y llama a la función eliminar cliente para eliminar aquellos clientes que tenían la localidad eliminada.
///
/// @param listaClientes = vecto con listado de clientes.
/// @param lenClientes = largo vector clientes.
/// @param listaPedidos = vector con listado de pedidos.
/// @param lenPedidos = largo vector pedidos.
/// @param listaLocalidades = vector con listado de localidades.
/// @param lenLocalidades = largo vector localidades.
/// @param idLocalidad = ID de la localidad que se desea eliminar.
/// @return -1 en caso de error, 0 en caso que se haya podido realizar la operación.
int BajaLocalidad (eCliente listaClientes[], int lenClientes, ePedido listaPedidos[], int lenPedidos, eLocalidad listaLocalidades[], int lenLocalidades, int idLocalidad);


/// @brief identificar clientes con mayor cantidad de pedidos pendientes o completados.
///
/// @param listaPedidos = vector con listado de pedidos.
/// @param lenPedidos = largo vector pedidos.
/// @param listaClientes = vector con listado de clientes.
/// @param lenClientes = largo vector clientes.
/// @param estadoPedido = el criterio para mostrar los clientes. PENDIENTE o COMPLETADO.
/// @return -1 en caso de error, 0 en caso que se haya podido realizar la operación.
int ContarPedidosPorEstado (ePedido listaPedidos[], int lenPedidos, eCliente listaClientes[], int lenClientes, int estadoPedido);

/// @brief permite editar dirección o localidad de un cliente.
///
/// @param listaClientes = vector con listado de clientes.
/// @param lenClientes = largo vector clientes.
/// @param listaLocalidades = vector con listado de localidades.
/// @param lenPedidos = largo vector pedidos.
/// @param index = El índice del ID de la localidad.
/// @return -1 en caso de error, 0 en caso que se haya podido realizar la operación.
int EditarCliente(eCliente listaClientes[], int lenClientes, eLocalidad listaLocalidades[], int lenLocalidades, int index);

/// @brief comprueba que los kilos cargados no superen la cantidad de kilos cargados inicialmente.
///
/// @param kilosTotales = los kilos totales cargados al inicio.
/// @param kilosHDPE = cantidad de kilos de HDPE
/// @param kilosLDPE = cantidad de kilos de LDPE
/// @param kilosPP = cantidad de kilos de PP
/// @param mensajeError = mensaje en caso que los datos sean erroneos.
/// @param cantidadReintentos = cantidad de veces que se puede reintentar luego de un error.
/// @return -1 en caso de error, 0 en caso que se haya podido realizar la operación.
int VerificarCargaDeKilos (float kilosTotales, float* kilosHDPE, float* kilosLDPE, float* kilosPP, char mensajeError[], int cantidadReintentos);


/// @brief cuenta la cantidad de clientes con pedidos completados.
///
/// @param listaClientes = vector con listado de clientes.
/// @param lenClientes = largo vector clientes.
/// @param listaPedidos = vector con listado de pedidos.
/// @param lenPedidos = largo vector pedidos.
/// @return -1 en caso de error o la cantidad de clientes si se pudo realizar la operación.
int ContarClientes (eCliente listaClientes[], int lenClientes, ePedido listaPedidos[], int lenPedidos);










#endif /* INFORMES_H_ */
