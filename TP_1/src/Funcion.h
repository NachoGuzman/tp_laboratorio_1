
#include <stdio.h>
#include <stdlib.h>


/** \brief funcion para pedir numero.
 *
 * \param char mensaje[] se escribe el mensaje
 * \return El numero ingresado
 */
float pedirNumero (char mensaje[]);




/** \brief Funcion de costo con tarjeta de debito
 *
 * \param El precio ingresado
 * \return El resultado del descuento con Tarjeta de Debito
 */
float tarjetaDebitoCalcular (float precioBruto);



/** \brief Funcion de costo con tarjeta de credito
 *
 * \param El precio ingresado
 * \return El resultado del aumento con Tarjeta de Credito
 */
float tarjetaCreditoCalcular (float precioBruto);




/** \brief Funcion de conversor de peso a BITCOIN
 *
 * \param El precio ingresado
 * \return El resultado en BITCOIN
 */
float bitcoinCalcular (float precioBruto);



/** \brief Funcion de costo por KM
 *
 * \param El precio ingresado
 * \return El resultado del costo por KM
 */
float precioUnitarioCalcular (float precioBruto, int x);



/** \brief Funcion de diferencia de precio
 *
 * \param Los precios ingresados
 * \return El resultado de la diferencia de precio entre latam y aerolineas
 */
float diferenciaPrecioTotal (float y, float z );


/** \brief función para encapsular el menu de opciones.
*/
void cargaForzada5 (void);



