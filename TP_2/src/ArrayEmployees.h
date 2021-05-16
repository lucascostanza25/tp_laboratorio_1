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
 * \brief Pide los datos del la estructura de un empleado al usuario
 *
 * \pre
 * \post
 * \return Retorna los valores ingresados por el usuario de un empleado
 */
eEmployee pedirDatosEmpleado();

/**
 * \brief inicializa todos los espacios del array en disponibles. Es la primera funcion que se ejecuta
 * cuando se inicia el programa.
 *
 * \pre
 * \post
 * \param se le pasa mediante pasaje de referencia la estructura de los empleados
 * \param se le pasa el tamaño del array a recorrer
 */
void inicializarEmpleados(eEmployee *listaDeEmpleados,  int tam);

/**
 * \brief imprime un empleado
 *
 * \pre
 * \post
 * \param se le pasa la estructura del empleado
 */
void mostrarUnEmpleado(eEmployee);

/**
 * \brief muestra en el array a los empleados
 *
 * \pre
 * \post
 * \param se le pasa la lista de los empleados
 * \param se le pasa el tamaño del array
 * \return retorna 0 en caso de que pudo mostrar empleados o -1 si dio error
 */
int mostrarListadoDeEmpleados(eEmployee *listaDeEmpleados, int tam);

/**
 * \brief genera una baja logica de un empleado solicitando el ingreso del ID de alguno ya en el sistema.
 * Primero se verificara si hay empleados disponibles, si es asi, se le mostrara una lista de empleados habilitados para dar de baja.
 * El usuario ingresa el ID que desee y se le pedira que confirme por ultima vez si desea dar la baja del empleado.
 *
 * \pre
 * \post
 * \param se le pasa la lista de los empleados
 * \param se le pasa el tamaño del array
 * \return retorna 0 en caso de que pudo dar de baja al empleado o -1 si dio error.
 */
int darDeBajaEmpleado(eEmployee *listaDeEmpleados, int tam);

/**
 * \brief Permite al usuario modificar a algun empleado ingresado. Primero se verificara si hay
 * empleados disponibles, si es asi, se le mostrara una lista de empleados habilitados para modificar.
 * El usuario ingresa el ID que desee y podra acceder al menu de modificacion eligiendo que campo que quiera cambiar.
 *
 * \pre
 * \post
 * \param se le pasa la lista de los empleados
 * \param se le pasa el tamaño del array
 * \return retorna 0 en caso de que pudo modificar al empleado o -1 si dio error.
 */
int modificarEmpleado(eEmployee *listaDeEmpleados, int tam);

/**
 * \brief Permite al usuario agregar nuevos empleados. Primero se verificara si hay usuario disponibles y de ser asi
 * pasara a la funcion "eEmployee pedirDatosEmpleado()" donde ingresara los datos y luego de eso aumentara automaticamente
 * el ID del empleado.
 *
 * \pre
 * \post
 * \param se le pasa la lista de los empleados
 * \param se le pasa el tamaño del array
 * \param se le pasa por pasaje de referencia el idAutomatico del empleado y este lo aumenta por 1 cada vez que se cargue un nuevo empleado
 * \return retorna 0 en caso de que se dio de alta al empleado o -1 si dio error y no hay mas espacio.
 */
int cargarEmpleados(eEmployee *listaDeEmpleados, int tam, int *idAutomatico);

/**
 * \brief Permite buscar empleados libres mediando el campo isEmpty.
 *
 * \pre
 * \post
 * \param se le pasa la lista de los empleados
 * \param se le pasa el tamaño del array
 * \return retorna la ubicacion de campo habilitado para rellenar
 */
int buscarEmpleadosLibres(eEmployee *listaDeEmpleados, int tam);

/**
 * \brief Permite al usuario ordenar los empleados por apellido o por sector
 *
 * \pre
 * \post
 * \param se le pasa la lista de los empleados
 * \param se le pasa el tamaño del array
 * \return retorna 0 en caso de que se pudo ordenar a los empleados o -1 si dio error.
 */
int ordenarEmpleados(eEmployee *listaDeEmpleados, int tam);

/**
 * \brief Le muestra al usuario la suma de sueldos, el promedio y la cantidad de personas que superan el promedio de sueldos
 *
 * \pre
 * \post
 * \param se le pasa la lista de los empleados
 * \param se le pasa el tamaño del array
 * \return retorna 0 en caso de que se pudo mostrar la informacion o -1 si dio error.
 */
int totalSueldos(eEmployee *listaDeEmpleados, int tam);

#endif /* ARRAYEMPLOYEES_H_ */
