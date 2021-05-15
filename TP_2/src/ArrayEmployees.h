/*
 * ArrayEmployees.h
 *
 *  Created on: 8 may. 2021
 *      Author: Lucas
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_


typedef struct
{
	int idEmployee;
	char nameEmployee[51];
	char lastNameEmployee[51];
	float salaryEmployee;
	int sectorEmployee;

	int isEmpty;
}eEmployee;

/**
 * \brief
 *
 * \pre
 * \post
 * \return
 */
eEmployee pedirDatosEmpleado();

/**
 * \brief
 *
 * \pre
 * \post
 * \param listaDeEmpleados
 * \param tam
 */
void inicializarEmpleados(eEmployee *listaDeEmpleados,  int tam);

/**
 * \brief
 *
 * \pre
 * \post
 * \param
 */
void mostrarUnEmpleado(eEmployee);

/**
 * \brief
 *
 * \pre
 * \post
 * \param listaDeEmpleados
 * \param tam
 * \return
 */
int mostrarListadoDeEmpleados(eEmployee *listaDeEmpleados, int tam);

/**
 * \brief
 *
 * \pre
 * \post
 * \param listaDeEmpleados
 * \param tam
 * \return
 */
int darDeBajaEmpleado(eEmployee *listaDeEmpleados, int tam);

/**
 * \brief
 *
 * \pre
 * \post
 * \param listaDeEmpleados
 * \param tam
 * \return
 */
int modificarEmpleado(eEmployee *listaDeEmpleados, int tam);

/**
 * \brief
 *
 * \pre
 * \post
 * \param listaDeEmpleados
 * \param tam
 * \param idAutomatico
 * \return
 */
int cargarEmpleados(eEmployee *listaDeEmpleados, int tam, int *idAutomatico);

/**
 * \brief
 *
 * \pre
 * \post
 * \param listaDeEmpleados
 * \param tam
 * \return
 */
int buscarEmpleadosLibres(eEmployee *listaDeEmpleados, int tam);

/**
 * \brief
 *
 * \pre
 * \post
 * \param listaDeEmpleados
 * \param tam
 * \return
 */
int buscarEmpleadosOcupados(eEmployee *listaDeEmpleados, int tam);

/**
 * \brief
 *
 * \pre
 * \post
 * \param listaDeEmpleados
 * \param tam
 * \return
 */
int ordenarEmpleados(eEmployee *listaDeEmpleados, int tam);

#endif /* ARRAYEMPLOYEES_H_ */
