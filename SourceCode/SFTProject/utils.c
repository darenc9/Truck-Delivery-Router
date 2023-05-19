#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "mapping.h"
#include "init.h"

void printRoute(struct Route route, struct Shipment s)
{

    if (route.routeSymbol == 2)
    {
        printf("Ship on BLUE LINE, ");
    }
    else if (route.routeSymbol == 4)
    {
        printf("Ship on GREEN LINE, ");
    }
    else if (route.routeSymbol == 8)
    {
        printf("Ship on YELLOW LINE, ");
    }

    if (route.numPoints >= 1)
    {
        if (route.numPoints == 1)
        {
            printf("no diversion");
        }
        else {
            printf("divert: ");
            for (int i = 0; i < route.numPoints; i++)
            {
                // print last point - without "," at the end
                if (i == route.numPoints - 1)
                {
                    printf("%d%c", route.points[i].row + 1, 'A' + route.points[i].col);

                }
                else {
                    printf("%d%c, ", route.points[i].row + 1, 'A' + route.points[i].col);
                }
            }
            // if route does not contain the destination point, but goes to destination diagonally
            if (route.points[route.numPoints - 1].col != s.destination.col ||
                route.points[route.numPoints - 1].row != s.destination.row)
            {
                printf(", %d%c", s.destination.row + 1, 'A' + s.destination.col);
            }
        }
    }
    // if there are no trucks available
    else {
        printf("Ships tommorow");
    }
    printf("\n");
};

void getAllTruckPaths(struct Shipment s, struct Truck truck, const struct Map* map, struct Route routes[MAX_ROUTES], int* size)
{
    int j = 0;
    struct Map maps = populateMap();

    for (int i = 0; i < truck.route->numPoints; i++)
    {
        struct Route result = shortestPath(&maps, truck.route->points[i], s.destination);
        const struct Point resultDistance = result.points[result.numPoints - 1];

        // paths that reach the destination that have the previous point north, east, south, or west have destination in points array
        if (containsDestination(&result, s) == 1)
        {
            result.routeSymbol = truck.route->routeSymbol;
            routes[(*size)++] = result;

        }

        if (result.numPoints == 2)
        {
            for (int j = 0; j < truck.route->numPoints; j++)
            {
                if (result.points[0].row == truck.route->points[j].row &&
                    result.points[0].col == truck.route->points[j].col)
                {
                    result.points[0] = s.destination;
                    result.numPoints = 1;
                }
            }
            result.routeSymbol = truck.route->routeSymbol;
            routes[(*size)++] = result;
        }

        // paths that reach the destination diagonally do not have the destination in points array
        else if (distance(&resultDistance, &s.destination) == 1 && containsDestination(&result, s) == 0)
        {
            result.routeSymbol = truck.route->routeSymbol;
            routes[(*size)++] = result;
        }
    };
};

int getBestRoute(struct Route routes[MAX_ROUTES], int s0, struct Shipment s)
{
    int res = 0;
    int i = 0;

    // assumes all routes reach destination
    for (i = 0; i < s0; i++)
    {
        if ((routes[i].numPoints < routes[res].numPoints))
        {
            res = i;
        }
    }
    return res;
};

int isBuilding(struct Route r, const struct Map* map)
{
    int building = 0;
    int i = 0;
    struct Map maps = populateMap();
    baseMap = &maps;
    while (i < r.numPoints && building == 0)
    {
        int routerow = r.points[i].row;
        int routecol = r.points[i].col;

        if (baseMap->squares[(int)r.points[i].row][(int)r.points[i].col] == 1)
        {
            building = 1;
        }

        i++;
    }

    return building;
}

int containsDestination(struct Route* route, struct Shipment shipment)
{
    int contains = 0;
    int i = 0;


    while (i < route->numPoints && contains == 0)
    {
        if (route->points[i].col == shipment.destination.col &&
            route->points[i].row == shipment.destination.row)
        {
            contains = 1;
        }

        i++;
    }

    return contains;
};