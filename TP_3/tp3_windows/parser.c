#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	char bufferDatos[4][128];
	int cantidadDatos;
	Employee* auxEmpleado;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		//fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferDatos[0], bufferDatos[1], bufferDatos[2], bufferDatos[3]);

		while(!feof(pFile))
		{
			cantidadDatos=fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferDatos[0], bufferDatos[1], bufferDatos[2], bufferDatos[3]);

			if(cantidadDatos==4)
			{
				auxEmpleado=employee_newParametros(bufferDatos[0], bufferDatos[1], bufferDatos[2], bufferDatos[3]);
				if(auxEmpleado!=NULL)
				{
					ll_add(pArrayListEmployee, auxEmpleado);
					retorno=0;
				}
			}
		}
	}

	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	Employee* auxEmpleado;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		while(!feof(pFile))
		{
			auxEmpleado=employee_new();
			if(fread(auxEmpleado, sizeof(Employee), 1, pFile)!=0)
			{
				ll_add(pArrayListEmployee, auxEmpleado);
				retorno=0;
			}
		}
	}

    return retorno;
}
