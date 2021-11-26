#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef INPUTS_H_
#define INPUTS_H_

/**
 * @fn int pedirEntero(int*, char*, char*, int, int)
 * @brief pido un entero, con un mensaje, un mensaje de error por si no cumple las condiciones, un minimo y un maximo del rango de numero
 *
 * @param entero paso un puntero de entero
 * @param mensaje paso un mensaje
 * @param mensajeError paso un mensaje de error
 * @param min el minimo numero que puede ingresar
 * @param max un maximo numero que puede ingresar
 * @return devuelve si tuvo exito o no el pedido
 */
int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max);

/**
 * @fn int pedirFlotante(float*, char*, char*, float, float)
 * @brief pido un flotante, con un mensaje, un mensaje de error por si no cumple las condiciones, un minimo y un maximo del rango de numero
 *
 * @param flotante paso un puntero de flotante
 * @param mensaje paso un mensaje
 * @param mensajeError paso un mensaje de error
 * @param min  el minimo numero que puede ingresar
 * @param max un maximo numero que puede ingresar
 * @return devuelve si tuvo exito o no el pedido
 */
int pedirFlotante(float* flotante, char* mensaje, char* mensajeError, float min, float max);

/**
 * @fn int pedirCadena(char*, char*, char*, int)
 * @brief
 *
 * @param cadena paso un puntero de cadena
 * @param mensaje paso un mensaje
 * @param mensajeError paso un mensaje de error
 * @param max maxima cantidad de caracteres que pueda ingresar
 * @return devuelve si tuvo exito o no el pedido
 */
int pedirCadena(char* cadena, char* mensaje, char* mensajeError, int max);

/**
 * @fn int pedirCaracter(char*, char*)
 * @brief
 *
 * @param caracter paso un caracter
 * @param mensaje paso un mensaje
 * @return
 */
int pedirCaracter(char* caracter, char* mensaje);

/**
 * @fn int pedirConfirmacion(char*)
 * @brief pido la confirmacion del usuario
 *
 * @param mensaje paso un mensaje
 * @return devuelve si tuvo exito o no el pedido
 */
int pedirConfirmacion(char* mensaje);


#endif /* INPUTS_H_ */
