#ifndef INIT_H
#define INIT_H
#include "Truck.h"
#include "Shipment.h"
#include "mapping.h"

struct Map* baseMap;
struct Truck trucks[3];

/**
 * Function: init
 * Purpose: Initializes global variables that will be used throughout the project:
 *	struct Map* baseMap: will contain the map featuring our delivery range, building, and base.
 *	struct Truck* trucks: will contain our 3 trucks, each assigned to the blue, green, or yellow route.
 * 
 * This function has no return values.
 * This function accepts no parameters.
 */
void init(void);

#endif