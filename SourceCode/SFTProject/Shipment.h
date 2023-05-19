#ifndef SHIPMENT_H
#define SHIPMENT_H
// all box volumes are of units m^3
#define SMALL_BOX_VOL 0.25
#define MED_BOX_VOL 0.50
#define LARGE_BOX_VOL 1.0
#include "mapping.h"
/**
 * Struct: Shipment
 * Author: Jon Pablo and Devon Chan
 * Desc: Defines customer package/shipment, includes:
 *   - shipment weight
 *   - shipment volume
 *   - shipment destination
 */
struct Shipment
{
    int weight;
    double vol;
    struct Point destination;
};

/**
 * Function: validate
 * Validates parameters for shipment, and sends valid shipment to AssignTrucks function.
 * @param size - size of shipment: SMALL_BOX_VOL, MED_BOX_VOL, or LARGE_BOX_VOL
 * @param weight - weight of shipment in kgs (1 - 1000)
 * @param destination - shipment's deilvery destination from {0,0} to {25,25}
 * @returns  1 if valid,
 *          -1 if invalid size,
 *          -2 if invalid weight,
 *          -3 if invalid destination, or
 *           0 if exit code is entered.
 */
int validate(double size, int weight, struct Point destination);

/**
* Function:  read
* Reads user input for new shipments, and sends the input into validate function.
*/
void read();
#endif