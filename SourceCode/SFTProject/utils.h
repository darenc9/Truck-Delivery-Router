#ifndef UTILS_H
#define UTILS_H

#include "mapping.h"
#include "Shipment.h"
#include "Truck.h"

/**
* Function: getAllTruckPaths
* - populates "routes" array with routes that reach the shipment
* @param s - Shipment struct, containing the Shipment destination
* @param truck - Truck struct, containing the route the truck travels on the map
* @param map - Map struct, containing all inbound points in the map
* @param routes - holds all valid routes (i.e. struct Route)
* @returns - void, populates the "routes" array
*/
void getAllTruckPaths(struct Shipment s, struct Truck truck, const struct Map* map, struct Route* routes[MAX_ROUTES], int* size);

/**
* Function: getBestRoute
* - loops through all valid routes in "routes" array, returns index of route with the shortest distance
* @param routes - holds all valid routes (i.e. struct Route)
* @param s - Shipment struct, containing the Shipment destination
* @returns - int, index of route in "routes" array with the shortest route
*/
int getBestRoute(struct Route routes[MAX_ROUTES], int s0, struct Shipment s);

/**
* Function: containsDestination
* - checks if the given route is valid, if it reaches the destination
* @param route - the shortest route calculated at ith point of a trucks route
* @param s - Shipment struct, containing the Shipment destination
* @returns - int, 1 if the destination is in the route, 0 if not
*/
int containsDestination(struct Route* route, struct Shipment s);

/**
* Function: printRoute
* - print a routes points to console
* @param route - route struct containing the points in given route
* @returns - void, does not return a value, only prints to console
*/
void printRoute(struct Route route, struct Shipment s);


int isBuilding(const struct Route r, const struct Map* map);

#endif