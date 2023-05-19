#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "Truck.h"
#include "Shipment.h"
#include "init.h"
#include "utils.h"
void read()
{
	double size;
	int weight, scanned, len, row, col, i;
	char point[4], c;
	struct Point destination;
	int loop = 1;
	int check;
	struct Shipment shipment = { 0 };
	init();
	printf("=================\n");
	printf("Seneca Deliveries\n");
	printf("=================\n");

	do {
		row = col = size = weight = scanned = len = 0;
		destination.row = destination.col = -1;
		printf("Enter shipment weight, box size and destination (0 0 x to stop): ");
		scanned = scanf("%d %lf %s", &weight, &size, point);
		len = strlen(point);

		//checks if user input for point is "x"
		if (!strcmp(point, "x"))
		{
			destination.row = 'x';
			destination.col = 0;
		}

		else
		{
			//Checks if user followed correct format (3 inputs separated by space)
			if (scanned != 3)
			{
				printf("Invalid input. Follow this example: 1 1 1A\n");
				while (getchar() != '\n') {}
				continue;
			}
			//breaks down string "point" to col and row variables
			for (i = 0; i < len; i++)
			{
				c = point[i];
				if (c >= '0' && c <= '9')
				{
					row = row * 10 + (c - '0');
				}
				else if (c >= 'A' && c <= 'Z')
				{
					col = col * 26 + (c - 'A');
				}
			}
			//Assigns the broken down row and col into the Point struct
			destination.row = --row;
			destination.col = col;
		}

		//Uses validate function
		check = validate(size, weight, destination);

		//If valid, creates a shipment struct and passes it to AssignTruck
		if (check == 1)
		{
			shipment.weight = weight;
			shipment.vol = size;
			shipment.destination.row = destination.row;
			shipment.destination.col = destination.col;
			AssignTruck(shipment);
		}

		//If user input is detected to be '0 0 x' then exits loop
		else if (check == 0)
			loop = 0;
		
	} while (loop);
}


int validate(double size, int weight, struct Point destination)
{
	struct Map map = populateMap();
	struct Map* testMap = &map;
	int check = 1;
	int min = 0; int max = 26;
	if (weight == 0 && size == 0 && destination.row == 'x')
	{
		printf("Thank you for shipping with Seneca!\n");
		check = 0;
	}
	else if (destination.row == NULL || destination.col == NULL || destination.row > max || destination.col > max)
		destination.row = destination.col = -1;

	if (check != 0)
	{
		if (weight > 1000 || weight < 1)
		{
			check = -2;
			printf("Invalid weight (must be 1-1000 Kg.)\n");
		}
		else if (size != SMALL_BOX_VOL && size != MED_BOX_VOL && size != LARGE_BOX_VOL)
		{
			check = -1;
			printf("Invalid size\n");
		}
		else if ((destination.row < min || destination.row > max) || (destination.col < min || destination.row > max))
		{
			check = -3;
			printf("Invalid destination\n");
		}
		else if (testMap->squares[(int)destination.row][(int)destination.col] == 0)
		{
			check = -3;
			printf("Invalid destination\n");
		}
	}
	return check;
}

