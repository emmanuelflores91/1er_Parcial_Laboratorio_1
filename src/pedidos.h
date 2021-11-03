
#ifndef PEDIDOS_H_
#define PEDIDOS_H_
#define PENDIENTE 1
#define COMPLETADO 2
#define LP 10 //Cantidad de pedidos.

typedef struct
{
	int idPedido;
	int idCliente;
	float cantidadKilosTotal;
	float kilosHDPE;
	float kilosLDPE;
	float kilosPP;
	int estado;
	int isEmpty;

}ePedido;

/// @brief Completa todos los campos isEmpty de cada pedido con el valor 1, y así eliminar los datos basura
///
/// @param list = vector con listado de pedidos.
/// @param len = largo del vector
/// @return -1 en caso de error. 0 en caso que se haya podido realizar la operación.
int InicializarPedidos(ePedido list[], int len);

/// @brief Busca que exista al menos un pedido cargado.
///
/// @param list = vector con listado de pedidos.
/// @param len = largo del vector.
/// @return retorna 1 si existe y 0 en caso contrario.
int HayUnPedido (ePedido list[], int len);

/// @brief verifica que exista al menos un pedido completado.
///
/// @param list = vector con listado de pedidos.
/// @param len = largo del vector.
/// @return retorna 1 si existe y 0 en caso contrario.
int HayPedidosCompletados (ePedido list[], int len);


/// @brief Encuentra una pedido en base al ID que recibe como parámetro.
///
/// @param list = vector con listado de pedidos.
/// @param len = largo del vector.
/// @param id = ID del pedido buscado.
/// @return retorna el índice del ID encontrado.
int EncontrarPedidoPorId(ePedido list[], int len, int id);

/// @brief Busca un campo con el valor isEmpty en 1, y en la primer coincidencia termina la búsqueda.
///
/// @param list = vector con listado de pedidos.
/// @param len = largo del vector.
/// @return -1 en caso de error y en caso que se haya podido realizar la operación, retorna el índice de la posición que está en isEmpty.
int HayEspacioVacioPedido (ePedido list[], int len);


/// @brief agrega un nuevo pedido en la primer posición vacía del vector.
///
/// @param list = vector con listado de pedidos.
/// @param len = largo del vector.
/// @return -1 en caso de error, 0 en caso que se haya podido realizar la operación.
int CargarPedido (ePedido list[], int len, int idCliente);


/// @brief cuenta la cantidad de pedidos pendientes en base al ID.
///
/// @param list = vector con listado de pedidos.
/// @param len = largo del vector.
/// @param idCliente = el ID buscado
/// @param cantidadPendientes = puntero que devuelve la cantidad de pedidos pendientes-
/// @return -1 en caso de error, 0 en caso que se haya podido realizar la operación.
int ContarPedidosPendientePorID(ePedido list[], int len, int idCliente, int* cantidadPendientes);

/// @brief acumula la cantidad de kilos de los pedidos procesados.
///
/// @param listaPedidos = vector con listado de pedidos.
/// @param lenPedidos = largo del vector.
/// @return retorna -1 en caso de error o si salío bien la operación, retorna la cantidad de kilos
float SumarKilosProcesados (ePedido listaPedidos[], int lenPedidos);








#endif /* PEDIDOS_H_ */
