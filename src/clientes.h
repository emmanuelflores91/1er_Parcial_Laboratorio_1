
#ifndef CLIENTES_H_
#define CLIENTES_H_
#define LC 5 //Cantidad de clientes.

typedef struct
{
	int idCliente;
	char nombreEmpresa[41];
	char cuit[12];
	char direccion[41];
	int idLocalidad;
	int isEmpty;

}eCliente;

/// @brief Completa todos los campos isEmpty de cada cliente con el valor 1, y así eliminar los datos basura
///
/// @param list = vector con listado de clientes
/// @param len = largo del vector
/// @return -1 en caso de error. 0 en caso que se haya podido realizar la operación.
int InicializarClientes(eCliente list[], int len);

/// @brief Busca un campo con el valor isEmpty en 1, y en la primer coincidencia termina la búsqueda
///
/// @param list = vector con listado de clientes
/// @param len = largo del vector
/// @return -1 en caso de error y en caso que se haya podido realizar la operación, retorna el índice de la posición que está en isEmpty
int HayEspacioVacioCliente (eCliente list[], int len);

/// @brief Busca que exista al menos un cliente cargado.
///
/// @param list = vector con listado de clientes.
/// @param len = largo del vector.
/// @return retorna 1 si existe y 0 en caso contrario.
int HayUnCliente (eCliente list[], int len);


/// @brief Encuentra a un cliente en base al ID que recibe como parámetro.
///
/// @param list = vector con listado de clientes.
/// @param len = largo del vector.
/// @param id = ID del cliente buscado.
/// @return retorna el índice del ID encontrado.
int EncontrarClientePorId(eCliente list[], int len, int id);















#endif /* CLIENTES_H_ */
