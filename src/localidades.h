
#ifndef LOCALIDADES_H_
#define LOCALIDADES_H_
#define LL 10 // cantidad de localidades

typedef struct
{
	int idLocalidad;
	char descripcionLocalidad[51];
	int isEmpty;

}eLocalidad;

/// @brief Busca que exista al menos un cliente cargado.
///
/// @param list = vector con listado de clientes.
/// @param len = largo del vector.
/// @return retorna 1 si existe y 0 en caso contrario.
int HayUnaLocalidad (eLocalidad list[], int len);

/// @brief Imprime todas las localidades activas.
///
/// @param listaLocalidades = vector con listado de localidades.
/// @param lenLocalidades = largo del vector.
/// @return -1 en caso de error, 0 en caso que se haya podido realizar la operación.
///
int ImprimirLocalidades(eLocalidad listaLocalidades[], int lenLocalidades);

/// @brief Busca un campo con el valor isEmpty en 1, y en la primer coincidencia termina la búsqueda.
///
/// @param list = vector con listado de localidades.
/// @param len = largo del vector.
/// @return -1 en caso de error y en caso que se haya podido realizar la operación, retorna el índice de la posición que está en isEmpty.
int HayEspacioVacioLocalidad (eLocalidad list[], int len);

/// @brief agrega una nueva localidad en la primer posición vacía del vector.
///
/// @param list = vector con listado de localidades.
/// @param len = largo del vector.
/// @return -1 en caso de error, 0 en caso que se haya podido realizar la operación.
int CargarLocalidad (eLocalidad list[], int len);

/// @brief Encuentra una localidad  en base al ID que recibe como parámetro.
///
/// @param list = vector con listado de localidades.
/// @param len = largo del vector.
/// @param id = ID de la localidad buscada.
/// @return retorna el índice del ID encontrado.
int EncontrarLocalidadPorId(eLocalidad list[], int len, int id);

/// @brief permite editar una localidad.
///
/// @param list = vector con listado de localidades.
/// @param len = largo del vector.
/// @param index = índice de la localidad a editar
/// @return -1 en caso de error, 0 en caso que se haya podido realizar la operación.
int EditarLocalidad(eLocalidad list[], int len, int index);

/// @brief muestra un listado de localidades y permite elegir una por ID
///
/// @param list = vector con listado de localidades.
/// @param mensajeError = mensaje en caso de error.
/// @param len = largo del vector.
/// @param cantidadReintentos = la cantidad máxima de reintentos en caso de error.
/// @param idEncontrado = puntero al ID ingresado por el usuario.
/// @return -1 en caso de error, 0 en caso que se haya podido realizar la operación.
int PedirLocalidad (eLocalidad list[], char mensajeError[], int len, int cantidadReintentos, int* idEncontrado);

/// @brief Completa todos los campos isEmpty de cada localidad con el valor 1, y así eliminar los datos basura
///
/// @param list = vector con listado de localidades.
/// @param len = largo del vector
/// @return -1 en caso de error. 0 en caso que se haya podido realizar la operación.
int InicializarLocalidades(eLocalidad listaLocalidades[], int lenLocalidades);









#endif /* LOCALIDADES_H_ */
