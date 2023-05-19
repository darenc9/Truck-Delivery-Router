#include "Truck.h"
#include "Shipment.h"
#include "mapping.h"
#include "init.h"
#include "utils.h"

int AssignTruck(struct Shipment s)
{
    int size = 0;
    int result = -1;
    struct Route routes[MAX_ROUTES] = { 0 };
    struct Route blueRoute = getBlueRoute();
    struct Route greenRoute = getGreenRoute();
    struct Route yellowRoute = getYellowRoute();
    trucks[0].route = &blueRoute;
    trucks[1].route = &greenRoute;
    trucks[2].route = &yellowRoute;
    double blueScore, greenScore, yellowScore;
    blueScore = calculateUtilizationScore(trucks[0].cargoWeight, trucks[0].cargoVol);
    greenScore = calculateUtilizationScore(trucks[1].cargoWeight, trucks[1].cargoVol);
    yellowScore = calculateUtilizationScore(trucks[2].cargoWeight, trucks[2].cargoVol);

    if ((blueScore + calculateUtilizationScore(s.weight, s.vol) > 0.0) &&
        (trucks[0].cargoWeight + s.weight <= MAX_CARGO_WEIGHT) && (trucks[0].cargoVol + s.vol <= MAX_CARGO_VOL))
        getAllTruckPaths(s, trucks[0], baseMap, &routes, &size);

    if ((greenScore + calculateUtilizationScore(s.weight, s.vol) > 0.0) &&
        (trucks[1].cargoWeight + s.weight <= MAX_CARGO_WEIGHT) && (trucks[1].cargoVol + s.vol <= MAX_CARGO_VOL))
        getAllTruckPaths(s, trucks[1], baseMap, &routes, &size);

    if ((yellowScore + calculateUtilizationScore(s.weight, s.vol) > 0.0) &&
        (trucks[2].cargoWeight + s.weight <= MAX_CARGO_WEIGHT) && (trucks[2].cargoVol + s.vol <= MAX_CARGO_VOL))
        getAllTruckPaths(s, trucks[2], baseMap, &routes, &size);

    int bestRoute = getBestRoute(routes, size, s);
    printRoute(routes[bestRoute], s);

    if (routes[bestRoute].routeSymbol == 2)
    {
        trucks[0].cargoVol += s.vol;
        trucks[0].cargoWeight += s.weight;
        result = 2;
    }
    else if (routes[bestRoute].routeSymbol == 4)
    {
        trucks[1].cargoVol += s.vol;
        trucks[1].cargoWeight += s.weight;
        result = 4;
    }
    else if (routes[bestRoute].routeSymbol == 8)
    {
        trucks[2].cargoVol += s.vol;
        trucks[2].cargoWeight += s.weight;
        result = 8;
    }
    return result;
}


float calculateUtilizationScore(int weight, double vol)
{
    
    float weightScore = 0, volumeScore = 0, score = 0;
    
    if (weight > 0)
        weightScore = (float)weight / MAX_CARGO_WEIGHT;
    if (vol > 0)
        volumeScore = (float)vol / MAX_CARGO_VOL;

    if (weight > 0 && vol > 0.0)
        score = weightScore / volumeScore;

    return score;
}
