#pragma once
#ifndef TRUCK_H
#define TRUCK_H
#define MAX_CARGO_WEIGHT 1000 // in KGs
#define MAX_CARGO_VOL 36      // in m^3
#include "mapping.h"

/**
 * Struct: Truck
 * Author: Jon Pablo and Devon Chan
 * Desc: Defines a Trucks state, determines if it can accept additional shipments, it includes:
 *   - current cargo weight
 *   - current cargo volume
 *   - path the truck will take
 */

struct Truck
{
    int cargoWeight;
    double cargoVol;
    struct Route* route;
    // set limit
    // struct Route *diversions[100];
};

/**
 * Function: AssignTruck
 * Determines which truck is best to assign shipment s to, and assigns the new route.
 * @param s - the Shipment to deliver
 * @returns - the truck assigned to shipment s by color code
 *          returns 2 if shipment is assigned to the blue truck
 *          returns 4 if shipment is assigned to the green truck
 *          returns 8 if shipment is assigned to the yellow truck
 *          returns -1 if shipment cannot be delivered today
 */
  int AssignTruck(struct Shipment s);

/***
* Function: calculateUtilizationScore
* Determines the utilization score based on defined weight and vol limit
* @param weight - the truck's current weight or shipment's weight
* @param vol - the truck's current volume or shipment's volume
* @returns - a utilization in float
*          - if the returned score is 0, then inputs were invalid
*          - otherwise, the inputs were valid.
*/
float calculateUtilizationScore(int weight, double vol);

#endif