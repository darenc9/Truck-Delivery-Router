#include "init.h"
#include "utils.h"
void init(void) {
	struct Map map = populateMap();
	baseMap = &map;

	struct Route blueRoute = getBlueRoute();
	struct Route greenRoute = getGreenRoute();
	struct Route yellowRoute = getYellowRoute();

	struct Route test;
	int i;
	for (i = 19; i <= 26; i++)
	{
		const struct Point start = { 9, i };
		const struct Point dest = { 7, 24 };
		const struct Shipment s = { 500, .5, dest };
		test = shortestPath(&map, start, dest);
		int result = containsDestination(&test, s);
		if (result == 1) printf("CONTAINS DESTINATION!\n");
	}



	struct Truck truck[3] = {
	{0, 0, &blueRoute},
	{0, 0, &greenRoute},
	{0, 0, &yellowRoute}
	};
	trucks[0].cargoVol = 0;
	trucks[0].cargoWeight = 0;
	trucks[1].cargoVol = 0;
	trucks[1].cargoWeight = 0;
	trucks[2].cargoVol = 0;
	trucks[2].cargoWeight = 0;

}