/*
 ============================================================================
 Name        : 1C_PPLABO.c
 Author      : Giovanni Lucchetta
 Version     :
 Copyright   : Tano�
 Description :

 Una empresa de recolecci�n y reciclado de pl�sticos requiere un sistema que les permita administrar
sus clientes y pedidos de recolecci�n. El programa contar� con el siguiente men�:
1) Alta de cliente: Se da de alta un cliente con nombre de la empresa, cuit direcci�n y localidad. Se generar�
un ID �nico para este cliente que se imprimir� por pantalla si el alta es correcta.
2) Modificar datos de cliente: Se ingresa el ID de cliente y se permitir� cambiar la direcci�n y la localidad.
3) Baja de cliente: Se ingresa el ID del cliente. Luego se preguntar� si se quiere confirmar la eliminaci�n.
4) Crear pedido de recolecci�n: Se imprimir�n los clientes por pantalla y se pedir� que se ingrese el ID de un
cliente existente y la cantidad de kilos totales que se recolectar�n del cliente. Se generar� un ID para el pedido y
el mismo quedar� en estado �Pendiente� hasta que se obtengan los residuos del cliente y se trasladen a la
empresa.
5) Procesar residuos: Se elegir� esta opci�n cuando los residuos que volvieron a la empresa se hayan
procesado y separado en los diferentes tipos de pl�stico que la empresa puede reciclar. Se imprimir�n los
pedidos por pantalla y se pedir� seleccionar el ID de uno de ellos. Luego deber�n ingresarse la cantidad de kilos
de pl�stico de cada uno de los 3 tipos que la empresa puede procesar que se obtuvieron de los kilos totales que
se recolectaron. Por �ltimo, se marcar� al pedido como �Completado�.
6) Imprimir Clientes: Se imprimir� una lista de clientes con todos sus datos junto con la cantidad de �pedidos
de recolecci�n� que posee en estado �Pendiente�.
7) Imprimir Pedidos pendientes: Se imprimir� una lista de los pedidos que se encuentren en estado
�Pendiente� con la informaci�n: Cuit del cliente, direcci�n del cliente, cantidad de kilos a recolectar.
8) Imprimir Pedidos procesados: Se imprimir� una lista de los pedidos que se encuentren en estado
�Completado� con la informaci�n: Cuit del cliente, direcci�n del cliente, cantidad de kilos reciclados de cada tipo
de pl�stico.
9) Ingresar una localidad e indicar la cantidad de pedidos pendientes para dicha localidad.
10) Cantidad de kilos de polipropileno reciclado promedio por cliente. (kilos totales / cantidad de clientes)
11) Cliente con m�s pedidos pendientes.
12) Cliente con m�s pedidos completados.
13) Cliente con m�s pedidos.
14) Ingresar una localidad para filtrar la cantidad de HDPE - LDPE - PP - Desechable Trash y as� mostrar el total reciclado de esa zona.
15) Mostrar Lista de clientes
Los tipos de pl�stico que la empresa puede reciclar son:

� HDPE: Polietileno de alta densidad (Envases para l�cteos, perfumes, detergentes l�quidos, etc.)
� LDPE: Polietileno de baja densidad (Bolsas de congelaci�n de alimentos, tapas flexibles o bolsas de
basura.)
� PP: Polipropileno (Pl�sticos utilizados en la industria automovil�stica y en la construcci�n.)
El resto de la basura recolectada es desechada
Recomendaciones:
� Agregar al campo �isEmpty� a cada entidad.
� Generar un ID auto incrementable para cada entidad.
� Antes de comenzar, realizar un diagrama con las entidades, todos sus campos y c�mo se
relacionan.
� Antes de comenzar, realizar las funciones para imprimir cada uno de los arrays con todos sus
campos (sin relacionarlos con los otros arrays) para poder probar los ABM.
� Para poder probar los informes, realizar funciones que carguen con datos falsos los arrays de
las entidades, y ejecutarlas al comenzar el programa.

Nota 0: El sistema soportar� una capacidad m�xima de 100 clientes y 1000 pedidos
Nota 1: Se deber�n desarrollar bibliotecas por cada entidad (Cliente y Pedido) las cuales contendr�n las funciones (Alta,
Baja, Modificar, etc.).Los informes deber�n estar en una biblioteca aparte.
Nota 2: El c�digo deber� tener comentarios con la documentaci�n de cada una de las funciones y respetar las reglas de estilo
de la c�tedra.
 ============================================================================
 */


#include "Nexus.h"

int main(void)
{
	setbuf(stdout,NULL);

	eClients clientList[MAX];
	sOrders ordersList[MAX2];

	sLocality localitiesList[MAX];
	sPlastics plasticsList[MAX2];

	int uniqueID;
	int uniqueOrderID;
	int uniqueLocalityID;

	int menuOption;
	int subMenu;

	int maxHardcodeLocalitiesFlag;
	int clientsCounter;
	int ordersCounter;
	int firstObligatoryLocality;

	/// Flags
	ordersCounter = 0;
	firstObligatoryLocality = 0;
	clientsCounter = 0;
	maxHardcodeLocalitiesFlag = 0;

	/// Id's Generators
	uniqueOrderID = 0;
	uniqueID = 0;
	uniqueLocalityID = 0;

	/// Init Arrays
	initOrders(ordersList, MAX2);
	initClients(clientList, MAX);
	LOC_init(localitiesList,MAX);
	PLA_initArray(plasticsList, MAX2);

	do
	{
		printMenu();
		menuOption = getValidInt("\n\t\t\t\t\t\t\tIngrese una opcion del menu para realizar del 1 al 7: ",
		"\n\n\t\t\t\t      ERROR - (Has ingresado un numero no contemplado en el menu reintente) - ERROR\n\n", 1, 7);

		switch(menuOption)
		{
			case 1:
				do
				{
					printSubMenu();
					subMenu = getValidInt("\n\t\t\t\t\t\t\tIngrese una opcion del menu para realizar del 1 al 7: ",
					 "\n\n\t\t\t\t\tERROR - (Has ingresado un numero no contemplado en el menu reintente) - ERROR\n\n",
					 1, 7);
					switch(subMenu)
					{
						case 1:
							if(firstObligatoryLocality > 0)
							{
								newClient(clientList, localitiesList, MAX, &uniqueID, &uniqueLocalityID);
								printf("\n\n\t\t\t\t\t\t\t\t\tMostrando nuevo cliente");

								CLI_printClientsListWithLocalities(clientList, localitiesList, MAX, MAX);
								clientsCounter++;
							}
							else
							{
								printf("\n\n\t\t\t\t\t\t\tERROR - (Debe crear al menos una localidad) - ERROR");
							}
						break;

						case 2:
							LOC_newLocality(localitiesList, MAX, &uniqueLocalityID);
							firstObligatoryLocality++;
						break;

						case 3:
							if(firstObligatoryLocality > 0)
							{
								LOC_withdrawal(localitiesList, MAX);
								firstObligatoryLocality--;
							}
							else
							{
								printf("\n\n\t\t\t\t\t\tERROR - (Debe crear al menos una localidad antes de poder dar de baja) - ERROR");
							}
						break;
						case 4:
							LOC_hardcodeLocalities(localitiesList,MAX,&uniqueLocalityID);
							firstObligatoryLocality = 12;
						break;
						case 5:
								LOC_printListOfLocalities(localitiesList, MAX);
						break;
						case 6:
							if(maxHardcodeLocalitiesFlag == 0)
							{
								LOC_hardcodeLocalities(localitiesList,MAX,&uniqueLocalityID);
								CLI_createRandomClients(clientList, MAX, &uniqueID);
								arrayChargeOrders(ordersList,clientList,MAX,&uniqueOrderID); /// Ordenes
								CLI_printClientsListWithLocalities(clientList, localitiesList, MAX, MAX);

								maxHardcodeLocalitiesFlag = 1;
								clientsCounter+=clientsCounter+12;
								ordersCounter+=ordersCounter+12;
							}
							else
							{
								printf("\n\t\t\tLas localidades ya fueron cargadas,"
										" cargarlas mas de una vez podria ocasionar un problema en el programa\n"
										"\n\t\t\t\t\t\t Volviendo al menu\n\n");
							}
						break;
					}
				}while(subMenu != 7);
			break;

			case 2:
				if(clientsCounter > 0)
				{
					modifyClient(clientList, localitiesList, MAX, &uniqueLocalityID);
				}
				else
				{
					printf("\n\t\t\t\t\t\t\tNo hay ningun cliente existente, cree uno antes de poder modificarlo!");
				}
			break;
			case 3:
				if(clientsCounter > 0)
				{
					withdrawalClient(clientList, localitiesList, MAX);
					clientsCounter--;
				}
				else
				{
					printf("\n\t\t\t\t\t\t\tNo hay ningun cliente existente, cree uno antes de poder modificarlo!");
				}
			break;
			case 4:
				if(clientsCounter > 0)
				{
					newOrder(clientList, ordersList, localitiesList, MAX, &uniqueOrderID);
					ordersCounter++;
				}
				else
				{
					printf("\n\t\t\t\t\t\t\tNo hay ningun cliente existente, cree uno antes de poder asignarle un pedido!");
				}
			break;
			case 5:
				if(ordersCounter > 0)
				{
					processingOrder(clientList, ordersList, plasticsList, MAX, MAX2);
				}
				else
				{
					printf("\n\t\t\t\t\t\t\tNo hay ninguna orden creada, cree una antes de poder procesarla!");
				}
			break;
			case 6:
				do
				{
					printInformsMenu();
					menuOption = getValidInt("\n\t\t\t\t\t\t\tIngrese una opcion del menu para realizar del 1 al 11: ",
					"\n\n\t\t\t\t      ERROR - (Has ingresado un numero no contemplado en el menu reintente) - ERROR\n\n", 1, 11);

					switch(menuOption)
					{
						case 1:
							if(clientsCounter > 0 && ordersCounter > 0)
							{
								showClientsWithPendingOrders(clientList, ordersList, localitiesList, MAX, MAX2, MAX);
							}
							else
							{
								printf("\n\t\t\t\t\t\t\tNo hay clientes o ordenes creadas, cree uno de ambos para poder entrar a esta opcion");
							}
						break;
						case 2:
							if(clientsCounter > 0 && ordersCounter > 0)
							{
								showPedingOrdersWithClientsInfo(clientList, ordersList, MAX, MAX2);
							}
							else
							{
								printf("\n\t\t\t\t\t\t\tNo hay clientes o ordenes creadas, cree uno de ambos para poder entrar a esta opcion");
							}
						break;
						case 3:
							if(clientsCounter > 0 && ordersCounter > 0)
							{
								showCompleteOrdersWithWeight(clientList, ordersList, plasticsList, MAX, MAX2);
							}
							else
							{
								printf("\n\t\t\t\t\t\t\tNo hay clientes o ordenes creadas, cree uno de ambos para poder entrar a esta opcion");
							}
						break;
						case 4:
							if(clientsCounter > 0 && ordersCounter > 0)
							{
								showPendingOrdersByLocality(localitiesList,clientList, ordersList,MAX,MAX2,&uniqueLocalityID);
							}
							else
							{
								printf("\n\t\t\t\t\t\t\tNo hay clientes o ordenes creadas, cree uno de ambos para poder entrar a esta opcion");
							}
						break;
						case 5:
							if(clientsCounter > 0 && ordersCounter > 0)
							{
								averagePPRecicledByClient(clientList, ordersList, plasticsList, MAX, MAX2);
							}
							else
							{
								printf("\n\t\t\t\t\t\t\tNo hay clientes o ordenes creadas, cree uno de ambos para poder entrar a esta opcion");
							}
						break;
						case 6:
							if(clientsCounter > 0 && ordersCounter > 0)
							{
								clientWithMostOrders(clientList, localitiesList,ordersList, MAX, MAX2, PENDING);
							}
							else
							{
								printf("\n\t\t\t\t\t\t\tNo hay clientes o ordenes creadas, cree uno de ambos para poder entrar a esta opcion");
							}
						break;
						case 7:
							if(clientsCounter > 0 && ordersCounter > 0)
							{
								clientWithMostOrders(clientList, localitiesList,ordersList, MAX, MAX2, COMPLETED);
							}
							else
							{
								printf("\n\t\t\t\t\t\t\tNo hay clientes o ordenes creadas, cree uno de ambos para poder entrar a esta opcion");
							}
						break;
						case 8:
							if(clientsCounter > 0 && ordersCounter > 0)
							{
								clientWithMostOrders(clientList, localitiesList,ordersList, MAX, MAX2, ALL);
							}
							else
							{
								printf("\n\t\t\t\t\t\t\tNo hay clientes o ordenes creadas, cree uno de ambos para poder entrar a esta opcion");
							}
						break;
						case 9:
							if(clientsCounter > 0 && ordersCounter > 0)
							{
								plasticRecicledByLocality(clientList, localitiesList, ordersList, plasticsList, MAX, MAX2, &uniqueLocalityID);
							}
							else
							{
								printf("\n\t\t\t\t\t\t\tNo hay clientes o ordenes creadas, cree uno de ambos para poder entrar a esta opcion");
							}

						break;
						case 10:
							if(clientsCounter > 0)
							{
								CLI_printClientsListWithLocalities(clientList, localitiesList, MAX, MAX);
							}
							else
							{
								printf("\n\t\t\t\t\t\t\tNo hay clientes creados, cree uno poder entrar a esta opcion");
							}
						break;
					}
				}while (menuOption != 11);
			break;
			}
		}while(menuOption!= 7);




}
