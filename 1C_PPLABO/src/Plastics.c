/*
 * Plastics.c
 *
 *  Created on: 22 nov. 2021
 *      Author: giova
 */


#include "Nexus.h"
#include "Plastics.h"

int PLA_initArray (sPlastics* plasticsList, int plasticsLen)
{
	int state = -1;

	if(plasticsList != NULL && plasticsLen > 0)
	{
		for(int i = 0; i < plasticsLen; i++)
		{
			plasticsList[i].isEmpty = EMPTY;
		}
	}
	return state;
}

int PLA_freeArraySpot (sPlastics* plasticsList, int plasticsLen)
{
	int position;

	position = -1;

	if(plasticsList != NULL && plasticsLen > 0)
	{
		for(int i = 0; i < plasticsLen; i++)
		{
			if(plasticsList[i].isEmpty == EMPTY)
			{
				position = i;
				break;
			}
		}
	}

	return position;
}

int PLA_processPlastics (sPlastics* plasticsList, int plasticsLen, int id, int weightOfOrder)
{
	int state;
	int posToProcess;

	state = -1;

	if(plasticsList != NULL && plasticsLen > 0)
	{
		posToProcess = PLA_freeArraySpot(plasticsList, plasticsLen);

		printf("posToProcess = %d",posToProcess);

		plasticsList[posToProcess].orderId = id;

		if(weightOfOrder > 0)
		{

			printf("\n\nEl pedido pesa: %d Kl ",weightOfOrder);

			plasticsList[posToProcess].HDPE = getValidInt("Cuanto de este pedido de recoleccion le corresponde a HDPE?\n",
			"ERROR - Reingrese un peso correcto - ERROR ", 1, weightOfOrder);

			weightOfOrder = weightOfOrder - plasticsList[posToProcess].HDPE;
			printf("\nBasura restante: %d Kl", weightOfOrder);
		}

		if(weightOfOrder > 0)
		{
			printf("\n\nEl pedido pesa: %d Kl",weightOfOrder);

			plasticsList[posToProcess].LDPE = getValidInt("Cuanto de este pedido de recoleccion le corresponde a LDPE?\n",
			"ERROR - Reingrese un peso correcto - ERROR ", 1, weightOfOrder);

			weightOfOrder = weightOfOrder - plasticsList[posToProcess].LDPE;
			printf("\nBasura restante: %d Kl", weightOfOrder);
		}

		if(weightOfOrder > 0)
		{
			printf("\n\nEl pedido pesa: %d Kl",weightOfOrder);

			plasticsList[posToProcess].PP = getValidInt("Cuanto de este pedido de recoleccion le corresponde a PP?\n",
			"ERROR - Reingrese un peso correcto - ERROR ", 1, weightOfOrder);
			weightOfOrder = weightOfOrder - plasticsList[posToProcess].PP;

			printf("\nBasura restante: %d Kl", weightOfOrder);
		}

		plasticsList[posToProcess].desechableThrash = weightOfOrder;
		printf("\nEl plastico no reciclado será considerado basura y este es de: %d Kl", plasticsList[posToProcess].desechableThrash);

		state = 0;
		plasticsList[posToProcess].isEmpty = FULL;
	}


	return state;
}
