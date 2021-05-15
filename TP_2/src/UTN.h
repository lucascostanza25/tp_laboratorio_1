/*
 * utn.h
 *
 *  Created on: 23 abr. 2021
 *      Author: Lucas
 */

#ifndef UTN_H_
#define UTN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief
 *
 * \pre
 * \post
 * \param pResultado
 * \param mensaje
 * \param mensajeError
 * \param minimo
 * \param maximo
 * \param reintentos
 * \return
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/**
 * \brief
 *
 * \pre
 * \post
 * \param pResultadoFlotante
 * \param mensaje
 * \param mensajeError
 * \param minimo
 * \param maximo
 * \param reintentos
 * \return
 */
float utn_getFlotante(float* pResultadoFlotante, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

/**
 * \brief
 *
 * \pre
 * \post
 * \param pResultado
 * \param mensaje
 * \param mensajeError
 * \param minimo
 * \param maximo
 * \param reintentos
 * \return
 */
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

/**
 * \brief
 *
 * \pre
 * \post
 * \param pResultado
 * \param mensaje
 * \param mensajeError
 * \param longitud
 * \param reintentos
 * \return
 */
int utn_getString(char* pResultado, char mensaje[], char mensajeError[], int longitud, int reintentos);

/**
 * \brief
 *
 * \pre
 * \post
 * \param cadena
 * \param longitud
 * \return
 */
int esString(char* cadena, int longitud);

/**
 * \brief
 *
 * \pre
 * \post
 * \param pCadena
 * \param longitud
 * \return
 */
int myGets(char* pCadena, int longitud);

#endif /* UTN_H_ */
