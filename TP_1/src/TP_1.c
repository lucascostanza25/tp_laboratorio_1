/*
 TP Nro 1: Calculadora

 Costanza, Lucas
 División 1B
*/

#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"

int main(void)
{
	setbuf(stdout, NULL);
	int menu;
	float resSuma;
	float resResta;
	float resDivision;
	float resMultiplicacion;
	float resFactorialPrimerOperando;
	float resFactorialSegundoOperando;
	float primerOperando;
	float segundoOperando;
	int flagPrimerOperando;
	int flagSegundoOperando;
	int flagCase3;
	//Inicialización de banderas
	flagPrimerOperando=0;
	flagSegundoOperando=0;
	flagCase3=0;

	do
	{
		printf("----------CALCULADORA----------\n");
		printf("by Lucas Costanza - Division 1B\n");
		printf("\n1.Ingresar el primer operando\n");
		if(flagPrimerOperando==1)
		{
			printf("(El primer operando es: %.2f)\n", primerOperando);
		}
		else
		{
			printf("(Todavia no se ingreso el primer operando)\n");
		}
		printf("\n2.Ingresar el segundo operando\n");
		if(flagSegundoOperando==1)
		{
			printf("(El segundo operando es: %.2f)\n", segundoOperando);
		}
		else
		{
			printf("(Todavia no se ingreso el segundo operando)\n");
		}
		printf("\n3.Calcular todas las operaciones (suma - resta - division - multiplicacion - factorial)\n");
		printf("\n4.Mostrar resultados de las operaciones\n");
		printf("\n0.Salir\n");
		printf("\nIngrese una opcion: ");
		scanf("%d", &menu);
		system("CLS");

		switch(menu)
		{
			case 1:
				printf("Ingrese el primer operando: ");
				scanf("%f", &primerOperando);
				printf("El primer operando es: %.2f\n", primerOperando);
				printf("-------------------------------\n");
				printf("1.Reingresar primer operando\n");
				printf("\n9.Volver al menu principal\n");
				printf("\nIngrese una opcion: ");
				scanf("%d", &menu);
				system("CLS");
				while(menu==1)
				{
					printf("Reingrese el primer operando: ");
					scanf("%f", &primerOperando);
					printf("\nEl operando reingresado es: %2.f\n", primerOperando);
					printf("-------------------------------\n");
					printf("Desea reingresarlo nuevamente?\n");
					printf("\n1=SI\n2=NO\n");
					printf("\nIngrese una opcion: ");
					scanf("%d", &menu);
					system("CLS");
				}
				flagPrimerOperando=1;
			break;

			case 2:
				printf("Ingrese el segundo operando: ");
				scanf("%f", &segundoOperando);
				printf("El segundo operando es: %.2f\n", segundoOperando);
				printf("-------------------------------\n");
				printf("1.Reingresar segundo operando\n");
				printf("\n9.Volver al menu principal\n");
				printf("\nIngrese una opcion: ");
				scanf("%d", &menu);
				system("CLS");
				while(menu==1)
				{
					printf("Reingrese el segundo operando: ");
					scanf("%f", &segundoOperando);
					printf("\nEl operando reingresado es: %2.f\n", segundoOperando);
					printf("-------------------------------\n");
					printf("Desea reingresarlo nuevamente?\n");
					printf("\n1=SI\n2=NO\n");
					printf("\nIngrese una opcion: ");
					scanf("%d", &menu);
					system("CLS");
				}
				flagSegundoOperando=1;
			break;

			case 3:
				if(flagPrimerOperando==1 && flagSegundoOperando==1)
				{
					resSuma=suma(primerOperando, segundoOperando);
					resResta=resta(primerOperando, segundoOperando);
					resDivision=division(primerOperando, segundoOperando);
					resMultiplicacion=multiplicacion(primerOperando, segundoOperando);
					resFactorialPrimerOperando=factorialPrimerOperando(primerOperando);
					resFactorialSegundoOperando=factorialSegundoOperando(segundoOperando);
					printf("¡Se realizaron las operaciones!\n");
					flagCase3=1;
					system("pause");
					system("CLS");
				}
				else
				{
					printf("No se ingresaron operandos.\n");
					printf("Vuelva al menu presionando ENTER y elija la opcion 1 y 2.\n");
					system("pause");
					system("CLS");
				}
			break;

			case 4:
				if(flagCase3==1)
				{
					printf("\nLa suma de los dos operandos es %2.f\n", resSuma);
					printf("\nLa resta de los dos operandos es %2.f\n", resResta);
					if(segundoOperando==0)
					{
						printf("\nERROR. No se completo la division\n");
						printf("No es posible dividir por 0\n");
					}
					else
					{
						printf("\nLa division de los dos operandos es %2.f\n", resDivision);
					}
					printf("\nLa multiplicacion de los dos operandos es %2.f\n", resMultiplicacion);
					printf("\nEl factorial del primer operando es: %2.f\n", resFactorialPrimerOperando);
					printf("\nEl factorial del segundo operando es: %2.f\n", resFactorialSegundoOperando);
					system("pause");
					system("CLS");
				}
				else
				{
					printf("Todavia no se realizaron las operaciones.\n");
					printf("Vuelva al menu presionando ENTER y elija la opcion 3.\n");
					system("pause");
					system("CLS");
				}
			break;
		}
	}while(menu!=0);

	return EXIT_SUCCESS;
}
