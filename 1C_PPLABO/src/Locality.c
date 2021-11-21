/*
 * Locality.c
 *
 *  Created on: 18 nov. 2021
 *      Author: giova
 */

#include "Locality.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int LOC_hardcodeLocalities (sLocality* localitiesList, int len, int* uniqueLocalityID)
{
	int state;
	state = -1;

	char localidades[][MAX] = { "Abasto", "Agronomía", "Almagro",
	"Balvanera", "Barracas", "Barrio Norte", "Belgrano", "Boedo", "Caballito", "Capital Federal", "Chacarita", "Coghlan",
	"Colegiales", "Constitución", "Flores", "Floresta", "La Boca", "Liniers", "Mataderos", "Microcentro", "Monte Castro",
	"Montserrat","Nueva Pompeya", "Núñez", "Palermo", "Palermo Viejo", "Parque Avellaneda",	"Parque Chacabuco", "Parque Patricios",
	"Paternal", "Puerto Madero", "Recoleta", "Retiro", "Saavedra", "San Cristobal","San Nicolás", "San Telmo", "Velez Sarsfield",
	"Versalles", "Villa Crespo", "Villa del Parque", "Villa Devoto","Villa General Mitre", "Villa Lugano", "Villa Luro",
	"Villa Ortúzar", "Villa Pueyrredón" };

	for (int i = 0; i < 47; i++)
	{
		if(localitiesList[i].isEmpty == EMPTY)
		{
			strcpy((localitiesList + i)->locality, *(localidades + i));
			(localitiesList + i)->localityId = *uniqueLocalityID = *uniqueLocalityID+1;
			(localitiesList + i)->isEmpty = FULL;
		}
	}

	return state;
}

int LOC_init (sLocality* localitiesList, int localitiesLen)
{
	int state = -1;

	if(localitiesList != NULL && localitiesLen > 0)
	{
		for(int i = 0; i < localitiesLen; i++)
		{
			localitiesList[i].isEmpty = EMPTY;
		}
	}
	return state;

}

int LOC_newLocality(sLocality* localitiesList, int len, int* uniqueLocalityID)
{
	sLocality newLocality;
	int state;
	int aux;

	state = -1;

	getValidLocality("\n\t\t\t\t\t\t\tIngrese la localidad de su compañia :) : ",
	"\t\t\t\t\t\tERROR - (RE-Ingrese la localidad de su compañia) - ERROR : \n",
	newLocality.locality);

	FormartearCadena(newLocality.locality);

	aux = LOC_search(localitiesList, len, newLocality.locality, uniqueLocalityID);

	if(aux == 0)
	{
		*uniqueLocalityID = *uniqueLocalityID+1;

		LOC_chargeLocalitiesList(localitiesList, uniqueLocalityID, MAX, newLocality.locality);
	}
	else
	{
		newLocality.localityId = *uniqueLocalityID;
	}

	state = 0;

	return state;
}

int LOC_freeSpot (sLocality* localitiesList, int localitiesLen)
{
	int position;

	position = -1;

	if(localitiesList != NULL && localitiesLen > 0)
	{
		for(int i = 0; i < localitiesLen; i++)
		{
			if(localitiesList[i].isEmpty == EMPTY)
			{
				position = i;
				break;
			}
		}
	}

	return position;
}



int LOC_search (sLocality* localitiesList, int localitiesLen, char auxLocality [], int* uniqueLocalityID)
{
	int foundId;

	foundId = 0;

	for(int i = 0; i < localitiesLen; i++)
	{
		if(strcmp(localitiesList[i].locality, auxLocality) == 0)
		{
			foundId = localitiesList[i].localityId; /// devuelvo el id con el state asignado mas abajo en el return
		}
	}

	return foundId;
}

int LOC_chargeLocalitiesList(sLocality* localitiesList, int* uniqueLocalityID, int localitiesLen, char auxLocality [])
{
	int state;

	state = -1;

	if(localitiesList != NULL)
	{
		for(int i = 0; i < localitiesLen; i++)
		{
			if(localitiesList[i].isEmpty == EMPTY)
			{
				localitiesList[i].isEmpty = FULL;
				localitiesList[i].localityId = *uniqueLocalityID;
				strcpy(localitiesList[i].locality, auxLocality);
				break;
			}
		}
	}



	return state;
}

int LOC_printOneLocality(sLocality localitiesList)
{
	int state;
	state = -1;

	printf("%20s - %10d\n",
	localitiesList.locality,
	localitiesList.localityId);

	state = 0;

	return state;
}

int LOC_printListOfLocalities(sLocality* localitiesList, int len)
{
	int state;

	state = -1;

	printf("\n|Localidad | ID de Localidad |\n");
		printf("|____________|_____________|\n");

	if(localitiesList != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(localitiesList[i].isEmpty == FULL)
			{
				LOC_printOneLocality(localitiesList[i]);
			}
		}
	}

	return state;
}





