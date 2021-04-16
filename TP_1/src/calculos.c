/*
 * calculos.c
 *
 *  Created on: 10 abr. 2021
 *      Author: Lucas
 */
float suma(float x, float y)
{
	float suma;
	suma=(float)x+y;
	return suma;
}

float resta(float x, float y)
{
	float resta;
	resta=(float)x-y;
	return resta;
}

float division(float x, float y)
{
	float division;
	if(y==0)
	{
		printf("No se pudo completar la division, no es posible dividir por 0\n");
	}
	else
	{
		division=(float)x/y;
	}
	return division;
}

float multiplicacion(float x, float y)
{
	float multiplicacion;
	multiplicacion=(float)x*y;
	return multiplicacion;
}

float factorialPrimerOperando(float x)
{
	float factorialUno;
	float i;
	factorialUno=1;
	for(i=x; i>1; i--)
	{
		factorialUno=factorialUno*i;
	}

	return factorialUno;
}

float factorialSegundoOperando(float y)
{
	float factorialDos;
	float i;
	factorialDos=1;

	for(i=y; i>1; i--)
	{
		factorialDos=factorialDos*i;
	}

	return factorialDos;
}
