
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

int InicializarPedidos(ePedido list[], int len);


int HayUnPedido (ePedido list[], int len);

int EncontrarPedidoPorId(ePedido list[], int len, int id);


int EncontrarUltimoIdPedido(ePedido list[], int len);


int HayEspacioVacioPedido (ePedido list[], int len);

int CargarPedido (ePedido list[], int len, int idCliente);

int ContarPedidosPendientePorID(ePedido list[], int len, int idCliente, int* cantidadPendientes);

int SumarKilosProcesados (ePedido list[], int len);








#endif /* PEDIDOS_H_ */
