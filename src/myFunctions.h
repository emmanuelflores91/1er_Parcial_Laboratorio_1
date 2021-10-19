
#ifndef MYFUNCTIONS_H_
#define MYFUNCTIONS_H_
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


/// @brief = Pide un entero y lo retorna.
/// @param mensaje = El mensaje deseado para pedir el número.
/// @return = Retorna el número ingresado.
int PedirEntero (char mensaje []);

/// @brief = Pide un entero mayor a cero y lo retorna.
/// @param mensaje = El mensaje deseado para pedir el número.
/// @return = Retorna el número ingresado.
int PedirEnteroPositivo (char mensaje[]);


/// @brief = Pide un flotante y lo retorna.
/// @param mensaje = El mensaje deseado para pedir el número.
/// @return = Retorna el número ingresado.
float PedirFlotante (char mensaje []);

/// @brief = Pide un double y lo retorna.
/// @param mensaje = El mensaje deseado para pedir el numero.
/// @return = Retorna el numero ingresado.
double PedirFlotanteGrande (char mensaje[]);


/// @brief = Pide un caracter que será la respuesta que elija el usuario.
/// @param mensaje = El mensaje deseado al pedir la respuesta.
/// @return = Retorna el caracter ingresado convertido a mayusculas.
char PedirCaracter (char mensaje []);

/// @brief Pide una cadena de caracteres validando que no supere la longitud límite.
/// @param cadena = La variable donde se almacena la cadena.
/// @param longitud = el tamaño máximo del vector de caracteres.
/// @return = -1 en caso de error, 0 si se pudo realizar.
int PedirCadena(char mensaje [], char cadena[], int longitud);

/// @brief Pide una cadena de caracteres validando que no supere la longitud límite y que el largo no sea menor al mínimo.
/// @param cadena = La variable donde se almacena la cadena.
/// @param longitud = el tamaño máximo del vector de caracteres.
/// @param minimo = tamaño minimo de la cadena.
/// @return = -1 en caso de error, 0 si se pudo realizar.
int PedirCadenaEnRango(char mensaje [], char cadena[], int longitud, int minimo);

/// @brief = Imprime un numero flotante.
/// @param mensaje = El mensaje que se muestra junto con el número.
/// @param flotanteParaImprimir = El número flotante que recibe como parametro.
void ImprimirFlotante (char mensaje [], float flotanteParaImprimir);


/// @brief = Imprime un numero entero.
/// @param mensaje = El mensaje que se muestra junto con el número.
/// @param enteroParaImprimir = El número entero que recibe como parametro.
void ImprimirEntero (char mensaje [], int enteroParaImprimir);

/// @brief = Imprime un caracter.
/// @param mensaje = El mensaje que se muestra junto con el caracter.
/// @param caracterParaImprimir = El caracter que recibe como parametro.
void ImprimirCaracter (char mensaje [], char caracterParaImprimir);

/// @brief Imprime un mensaje u el otro en base a un número que recibe.
/// @param mensajeError = el mensaje en caso de error.
/// @param mensajeOk = el mensaje en caso de realizar la operación.
/// @param estado = rebibe los valores para mostrar un mensaje o el otro.
void ImprimirConOpciones( int estado, char mensajeError[], char mensajeOk[]);


/// @brief = Pide un entero y se asegura que esté en un rango deseado.
/// @param mensaje = El mensaje al pedir el entero.
/// @param minimo = El valor mínimo aceptado.
/// @param maximo = El valor máximo aceptado.
/// @return = Retorna el entero validado.
int PedirEnteroEnRango (char mensaje [], int minimo, int maximo);

/// @brief = Pide un flotante y se asegura que esté en un rango deseado.
/// @param mensaje = El mensaje al pedir el flotante.
/// @param minimo = El valor mínimo aceptado.
/// @param maximo = El valor máximo aceptado.
/// @return = Retorna el flotante validado.
float PedirFlotanteEnRango (char mensaje [], float minimo, float maximo);

/// @brief = No permite el ingreso de un número entero específico.
/// @param numeroIngresado = El número que se ingresa el cual se va a comparar con el número excluido.
/// @param numeroExcluido = El número que no se permite ingresar
/// @return = Retorna el número ingresado siempre y cuando sea distinto al excluido.
int ExcluirEntero (int numeroIngresado, int numeroExcluido);

/// @brief = No permite el ingreso de un número flotante específico.
/// @param numeroIngresado = El número que se ingresa el cual se va a comparar con el número excluido.
/// @param numeroExcluido = El número que no se permite ingresar
/// @return = Retorna el número ingresado siempre y cuando sea distinto al excluido.
float ExcluirFlotante (float numeroIngresado, float numeroExcluido);

/// @brief = Comprueba si un numero ingresado es un entero o un decimal.
/// @param numeroIngresado = El numero a comprobar.
/// @return = Retorna el valor 1 si el numero es entero, y el valor 0 si el numero es decimal.
int DistinguirEnteroDeFlotante (float numeroIngresado);

/// @brief verifica que un numero sea un entero válido.
/// @param datoIngresado = el número ingresado.
/// @return = = -1 en caso de error, 0 si se pudo realizar.
int ComprobarSiEsEntero (char datoIngresado[]);

/// @brief verifica que un numero sea un decimal válido.
/// @param datoIngresado = el número ingresado.
/// @return = = -1 en caso de error, 0 si se pudo realizar.
int ComprobarSiEsFlotante (char datoIngresado[]);

/// @brief = Realiza la suma de dos numeros y retorna el resultado.
/// @param A = El primer numero ingresado.
/// @param B = El segundo numero ingresado.
/// @return = El resultado de la suma.
double SumarDosNumeros (double A, double B);

/// @brief = Realiza la resta de dos numeros y retorna el resultado.
/// @param A = El primer numero ingresado.
/// @param B = El segundo numero ingresado.
/// @return = El resultado de la resta.
double RestarDosNumeros (double A, double B);

/// @brief = Realiza la división de un numero por otro y retorna el resultado.
/// @param A = El primer numero ingresado.
/// @param B = El segundo numero ingresado.
/// @return = El resultado de la división.
double DividirUnNumeroPorOtro (double A, double B);

/// @brief = Realiza la multiplicación de dos números y retorna el resultado.
/// @param A = El primer numero ingresado.
/// @param B = El segundo numero ingresado.
/// @return = El resultado de la multiplicación.
double MultiplicarDosNumeros (double A, double B);

/// @brief = Calcula el factorial de un numero y lo retorna.
/// @param numero = El numero ingresado.
/// @return = Retorna el resultado del factorial.
double CalcularFactorialDeUnNumero (double numero);

/// @brief = Asigna valor a todos las posiciones de un vector.
/// @param vector = El nombre del vector que se quiere inicializar.
/// @param longitud = La cantidad de posiciones del vector anterior.
/// @param valorParaInicializar = El valor deseado que se le quiere asignar a cada posición del vector.
void InicializarVectorDeEnteros (int vector[], int longitud, int valorParaInicializar);


/// @brief = Permite cargar un vector con numeros enteros de forma secuencial.
/// @param vector = La variable de tipo array que se desea cargar.
/// @param longitud = La longitud del vector a cargar.
/// @param mensaje = El mensaje que se muestra al pedir los valores.
void CargaSecuencialVectorDeEnteros (int vector[], int longitud, char mensaje[]);


/// @brief = Permite cargar un vector con numeros racionales de forma secuencial.
/// @param vector = La variable de tipo array que se desea cargar.
/// @param longitud = La longitud del vector a cargar.
/// @param mensaje = El mensaje que se muestra al pedir los valores.
void CargaSecuencialVectorDeFlotantes (float vector[], int longitud, char mensaje[]);


/// @brief = Permite eligir posición del vector y luego asiganarle un valor a dicha posición.
/// @param vector = El nombre del vector que se desea cargar.
/// @param longitud = La cantidad de posiciones del vector.
void CargaAleatoriaVectorDeEnteros (int vector [], int longitud);

/// @brief = Imprime todas las posiciones y valores de un vector.
/// @param vector = El nombre del vector que se desea imprimir.
/// @param longitud = La cantidad de posiciones del vector.
void ImprimirVectorDeEnteros (int vector [], int longitud);

/// @brief = Permite eligir posición del vector y luego asiganarle un valor validado en un rango, a dicha posición.
/// @param vector = El nombre del vector que se desea cargar.
/// @param longitud = La cantidad de posiciones del vector.
/// @param minimo = El valor mínimo aceptado.
/// @param maximo = El valor máximo aceptado.
void CargaAleatoriaVectorDeEnterosLimitada (int vector [], int longitud, int minimo, int maximo);








#endif /* MYFUNCTIONS_H_ */
