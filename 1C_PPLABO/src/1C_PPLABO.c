/*
 ============================================================================
 Name        : 1C_PPLABO.c
 Author      : Giovanni Lucchetta
 Version     :
 Copyright   : Tano™
 Description :

 Una empresa de recolección y reciclado de plásticos requiere un sistema que les permita administrar
sus clientes y pedidos de recolección. El programa contará con el siguiente menú:
1) Alta de cliente: Se da de alta un cliente con nombre de la empresa, cuit dirección y localidad. Se generará
un ID único para este cliente que se imprimirá por pantalla si el alta es correcta.
2) Modificar datos de cliente: Se ingresa el ID de cliente y se permitirá cambiar la dirección y la localidad.
3) Baja de cliente: Se ingresa el ID del cliente. Luego se preguntará si se quiere confirmar la eliminación.
4) Crear pedido de recolección: Se imprimirán los clientes por pantalla y se pedirá que se ingrese el ID de un
cliente existente y la cantidad de kilos totales que se recolectarán del cliente. Se generará un ID para el pedido y
el mismo quedará en estado “Pendiente” hasta que se obtengan los residuos del cliente y se trasladen a la
empresa.
5) Procesar residuos: Se elegirá esta opción cuando los residuos que volvieron a la empresa se hayan
procesado y separado en los diferentes tipos de plástico que la empresa puede reciclar. Se imprimirán los
pedidos por pantalla y se pedirá seleccionar el ID de uno de ellos. Luego deberán ingresarse la cantidad de kilos
de plástico de cada uno de los 3 tipos que la empresa puede procesar que se obtuvieron de los kilos totales que
se recolectaron. Por último, se marcará al pedido como “Completado”.
6) Imprimir Clientes: Se imprimirá una lista de clientes con todos sus datos junto con la cantidad de “pedidos
de recolección” que posee en estado “Pendiente”.
7) Imprimir Pedidos pendientes: Se imprimirá una lista de los pedidos que se encuentren en estado
“Pendiente” con la información: Cuit del cliente, dirección del cliente, cantidad de kilos a recolectar.
8) Imprimir Pedidos procesados: Se imprimirá una lista de los pedidos que se encuentren en estado
“Completado” con la información: Cuit del cliente, dirección del cliente, cantidad de kilos reciclados de cada tipo
de plástico.
9) Ingresar una localidad e indicar la cantidad de pedidos pendientes para dicha localidad.
10) Cantidad de kilos de polipropileno reciclado promedio por cliente. (kilos totales / cantidad de clientes)
11) Cliente con más pedidos pendientes.
12) Cliente con más pedidos completados.
13) Cliente con más pedidos.
Los tipos de plástico que la empresa puede reciclar son:

• HDPE: Polietileno de alta densidad (Envases para lácteos, perfumes, detergentes líquidos, etc.)
• LDPE: Polietileno de baja densidad (Bolsas de congelación de alimentos, tapas flexibles o bolsas de
basura.)
• PP: Polipropileno (Plásticos utilizados en la industria automovilística y en la construcción.)
El resto de la basura recolectada es desechada
Recomendaciones:
• Agregar al campo “isEmpty” a cada entidad.
• Generar un ID auto incrementable para cada entidad.
• Antes de comenzar, realizar un diagrama con las entidades, todos sus campos y cómo se
relacionan.
• Antes de comenzar, realizar las funciones para imprimir cada uno de los arrays con todos sus
campos (sin relacionarlos con los otros arrays) para poder probar los ABM.
• Para poder probar los informes, realizar funciones que carguen con datos falsos los arrays de
las entidades, y ejecutarlas al comenzar el programa.

Nota 0: El sistema soportará una capacidad máxima de 100 clientes y 1000 pedidos
Nota 1: Se deberán desarrollar bibliotecas por cada entidad (Cliente y Pedido) las cuales contendrán las funciones (Alta,
Baja, Modificar, etc.).Los informes deberán estar en una biblioteca aparte.
Nota 2: El código deberá tener comentarios con la documentación de cada una de las funciones y respetar las reglas de estilo
de la cátedra.
 ============================================================================
 */


#include "Nexus.h"

int main(void)
{
	setbuf(stdout,NULL);
	int menuOption;
	eClients clientList[MAX];
	sOrders ordersList[MAX2];
	sLocality localitiesList[MAX];
	sPlastics plasticsList[MAX2];
	int uniqueID;
	int uniqueOrderID;
	int uniqueLocalityID;
	int subMenu;
	int maxHardcodeLocalitiesFlag;

	maxHardcodeLocalitiesFlag = 0;
	uniqueOrderID = 0;
	uniqueID = 0;
	uniqueLocalityID = 0;

	initOrders(ordersList, MAX2);
	initClients(clientList, MAX);
	LOC_init(localitiesList,MAX);
	PLA_initArray(plasticsList, MAX2);
	do
	{
		printMenu();
		menuOption = getValidInt("\n\t\t\t\t\t\t\tIngrese una opcion del menu para realizar del 1 al 10: ",
				"\n\n\t\t\t\t      ERROR - (Has ingresado un numero no contemplado en el menu reintente) - ERROR\n\n", 1, 16);

		switch(menuOption)
		{
			case 1:
				do
				{
					printSubMenu();
					subMenu = getValidInt("\n\t\t\t\t\t\t\tIngrese una opcion del menu para realizar del 1 al 5: ",
					 "\n\n\t\t\t\t\tERROR - (Has ingresado un numero no contemplado en el menu reintente) - ERROR\n\n",
					 1, 5);
					switch(subMenu)
					{
						case 1:
							newClient(clientList, localitiesList, MAX, &uniqueID, &uniqueLocalityID);
						break;

						case 2:
							LOC_newLocality(localitiesList, MAX, &uniqueLocalityID);


						break;

						case 3:
							if(maxHardcodeLocalitiesFlag == 0)
							{
								LOC_hardcodeLocalities(localitiesList,MAX,&uniqueLocalityID);
								CLI_createRandomClients(clientList, MAX, &uniqueID);
								arrayChargeOrders(ordersList,clientList,MAX,&uniqueOrderID); /// Ordenes
								maxHardcodeLocalitiesFlag = 1;

							}
							else
							{
								printf("\n\t\t\tLas localidades ya fueron cargadas,"
										" cargarlas mas de una vez podria ocasionar un problema en el programa\n"
										"\n\t\t\t\t\t\t Volviendo al menu\n\n");
							}
						break;

						case 4:


						break;
					}
				}while(subMenu != 5);

			break;

			case 2:
				modifyClient(clientList, localitiesList, MAX, &uniqueLocalityID);
			break;
			case 3:
				withdrawalClient(clientList, localitiesList, MAX);
			break;
			case 4:
				newOrder(clientList, ordersList, localitiesList, MAX, &uniqueOrderID);
			break;
			case 5:
				processingOrder(clientList, ordersList, plasticsList, MAX, MAX2);
			break;
			case 6:
				showClientsWithPendingOrders(clientList, ordersList, localitiesList, MAX, MAX2, MAX);
			break;
			case 7:
				showPedingOrdersWithClientsInfo(clientList, ordersList, MAX, MAX2);
			break;
			case 8:
				showCompleteOrdersWithWeight(clientList, ordersList, plasticsList, MAX, MAX2);
			break;
			case 9:
				showPendingOrdersByLocality(localitiesList,clientList, ordersList,MAX,MAX2,&uniqueLocalityID);
			break;
			case 10:
				averagePPRecicledByClient(clientList, ordersList, plasticsList, MAX, MAX2);
			break;
			case 11:
				clientWithMostOrders(clientList, localitiesList,ordersList, MAX, MAX2, PENDING);
			break;
			case 12:
				clientWithMostOrders(clientList, localitiesList,ordersList, MAX, MAX2, COMPLETED);
			break;
			case 13:
				clientWithMostOrders(clientList, localitiesList,ordersList, MAX, MAX2, ALL);
			break;
			case 14:
				plasticRecicledByLocality(clientList, localitiesList, ordersList, plasticsList, MAX, MAX2, &uniqueLocalityID);
			break;
			case 15:

				arrayChargeOrders(ordersList,clientList,MAX,&uniqueOrderID); /// Ordenes
			break;

		}

	}while(menuOption!= 16);




}
