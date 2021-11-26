/*
 * ValidacionesPersonalizadas.h
 *
 *  Created on: 13 oct. 2021
 *      Author: PCNEW
 */

#ifndef VALIDACIONESPERSONALIZADO_H_
#define VALIDACIONESPERSONALIZADO_H_

/**
 * @fn int validacion_Numero(char[])
 * @brief valida si es un numero o no
 *
 * @param numero le paso el numero que quiera validar
 * @return devuelve 0 o 1, si es o no un numero
 */
int validacion_Numero(char numero[]);

/**
 * @fn int validacion_Cadena(char[])
 * @brief valida si es o no una cadena
 *
 * @param cadena le paso una cadena de letras para que la valide
 * @return devuelve 0 o 1 si es o no una cadena de solo letras
 */
int validacion_Cadena(char cadena[]);

/**
 * @fn int validacion_AlfaNumerica(char[])
 * @brief valida si es o no una cadena alfanumerica
 *
 * @param cadena le paso la cadena para validarla
 * @return me devuelve 0 o 1 si es o no una cadena alfanumerica
 */
int validacion_AlfaNumerica(char cadena[]);

/**
 * @fn int validacion_Espacio(char*)
 * @brief valida si tiene o no espacio
 *
 * @param cadena le paso una cadena
 * @return me devuelve 0 o -1 si tiene o no espacios
 */
int validacion_Espacio(char* cadena);

/**
 * @fn int esNumeroSimbolo(char*)
 * @brief valida si tiene o no simbolos
 *
 * @param cadena paso una cadena
 * @return me devuelve 0 o -1 si tiene o no simbolos
 */
int esNumeroSimbolo(char* cadena);

#endif /* VALIDACIONESPERSONALIZADO_H_ */
