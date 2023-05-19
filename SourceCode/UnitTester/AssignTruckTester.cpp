//Author: Devon Chan
//Document: MILESTONE 3 blackbox test for the AssignTruck function.
#include "pch.h"
#include "CppUnitTest.h"
#include "assert.h"
#include "mapping_r.h"
#include "Shipment_r.h"
#include "init_r.h"
#include "Truck_r.h"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCases
{
	
	//BLACKBOX FOR THE ASSIGNTRUCK FUNCTION
	TEST_CLASS(AssignTruckTest)
	{
		const struct Map baseMap = populateMap();
	public:
		//Testing destination closest to green route
		TEST_METHOD(AssignTruckTest01)
		{
			init();
			struct Point destination = { 7,24 };
			struct Shipment package = { 10, 0.5, destination };
			int result = AssignTruck(package);
			Assert::AreEqual(4, result);
		}
		//Testing destination closest to blue route
		TEST_METHOD(AssignTruckTest02)
		{
			init();
			struct Point destination = { 10,12 };
			struct Shipment package = { 100, 0.5, destination };
			int result = AssignTruck(package);
			Assert::AreEqual(2, result);
		}
		//Testing destination closest to yellow route
		TEST_METHOD(AssignTruckTest03)
		{
			init();
			struct Point destination = { 15,0 };
			struct Shipment package = { 40, 1, destination };
			int result = AssignTruck(package);
			Assert::AreEqual(8, result);
		}
		//Testing if trucks are full
		TEST_METHOD(AssignTruckTest04)
		{
			init();
			struct Point destination = { 22,1 };
			trucks[0].cargoWeight = trucks[1].cargoWeight = trucks[2].cargoWeight = 500;
			struct Shipment package = { 1000, 1, destination };
			int result = AssignTruck(package);
			Assert::AreEqual(-1, result);
		}
		//Testing destination closest to yellow route but full
		TEST_METHOD(AssignTruckTest05)
		{
			init();
			trucks[2].cargoWeight = 1000;
			struct Point destination = { 15,0 };
			struct Shipment package = { 40, 1, destination };
			int result = AssignTruck(package);
			Assert::AreEqual(2, result);
		}
		//Testing destination closest to yellow route but full
		TEST_METHOD(AssignTruckTest06)
		{
			init();
			trucks[2].cargoVol = 36;
			struct Point destination = { 15,0 };
			struct Shipment package = { 40, 1, destination };
			int result = AssignTruck(package);
			Assert::AreEqual(2, result);
		}
		//Testing destination closest to blue route but full
		TEST_METHOD(AssignTruckTest07)
		{
			init();
			trucks[0].cargoWeight = 1000;
			trucks[1].cargoWeight = 1000;
			struct Point destination = { 10,12 };
			struct Shipment package = { 100, 0.5, destination };
			int result = AssignTruck(package);
			Assert::AreEqual(8, result);
		}
		//Testing destination closest to blue route but full
		TEST_METHOD(AssignTruckTest08)
		{
			init();
			trucks[0].cargoVol = 36;
			trucks[1].cargoVol = 36;
			struct Point destination = { 10,12 };
			struct Shipment package = { 100, 0.5, destination };
			int result = AssignTruck(package);
			Assert::AreEqual(8, result);
		}
		//Testing destination closest to green route but full
		TEST_METHOD(AssignTruckTest09)
		{
			init();
			trucks[1].cargoWeight = 1000;
			struct Point destination = { 7,24 };
			struct Shipment package = { 10, 0.5, destination };
			int result = AssignTruck(package);
			Assert::AreEqual(2, result);
		}
		//Testing destination closest to green route but full
		TEST_METHOD(AssignTruckTest10)
		{
			init();
			trucks[1].cargoVol = 36;
			struct Point destination = { 7,24 };
			struct Shipment package = { 10, 0.5, destination };
			int result = AssignTruck(package);
			Assert::AreEqual(2, result);
		}
		//WHITEBOX TEST
		//Testing destination closest to yellow and blue
		TEST_METHOD(AssignTruckWTest05)
		{
			init();
			struct Point destination = { 6,1 };
			struct Shipment package = { 500, 0.5, destination };
			int result = AssignTruck(package);
			Assert::AreEqual(2, result);
		}
		//Testing destination closest to green route
		TEST_METHOD(AssignTruckWTest06)
		{
			init();
			struct Point destination = { 1,21 };
			struct Shipment package = { 900, 1, destination };
			int result = AssignTruck(package);
			Assert::AreEqual(4, result);
		}
		//Testing destination closest to Yellow route 
		TEST_METHOD(AssignTruckWTest07a)
		{
			init();
			struct Point destination = { 14,4 };
			struct Shipment package = { 40, 0.25, destination };
			int result = AssignTruck(package);
			Assert::AreEqual(8, result);
		}
		//Testing destination closest blue and green
		TEST_METHOD(AssignTruckWTest08)
		{
			init();
			struct Point destination = { 13,20 };
			struct Shipment package = { 900, 1, destination };
			int result = AssignTruck(package);
			Assert::AreEqual(2, result);
		}
	};

	TEST_CLASS(getBestRouteBB)
	{
		const struct Map *baseMap = &(populateMap());
		struct Shipment shipment = { 10,1,{7,24} };
		struct Route blueRoute = getBlueRoute();
		struct Route greenRoute = getGreenRoute();
		struct Route yellowRoute = getYellowRoute();
		struct Truck truck[3] = {
			{0, 0, &blueRoute},
			{0, 0, &greenRoute},
			{0, 0, &yellowRoute}
		};

	public:
		//GetBestRoute BB: Test1
		TEST_METHOD(getBestRouteBBT01)
		{
			struct Route testRoutes[100];
			int size = 0;
			int result = getBestRoute(testRoutes, size, shipment);
			Assert::AreEqual(0, result);
		}

		//GetBestRoute BB: Test2
		TEST_METHOD(getBestRouteBBT02)
		{
			struct Route routes[100];
			int size = -1;
			int result = getBestRoute(routes, size, shipment);
			Assert::AreEqual(0, result);
		}
		//GetBestRoute BB: Test3
		TEST_METHOD(getBestRouteBBT03)
		{
			struct Route routes[100];
			int size = NULL;
			int result = getBestRoute(routes, size, shipment);
			Assert::AreEqual(0, result);
		}
		//GetBestRoute BB: Test4
		TEST_METHOD(getBestRouteBBT04)
		{
			struct Route routes[10];
			int size = 10;
			routes[0].numPoints = 3;
			routes[0].points[0] = {7,24};
			int result = getBestRoute(routes, size, shipment);
			Assert::AreEqual(1, result);
		}
		//GetBestRoute BB: Test5
		TEST_METHOD(getBestRouteBBT05)
		{
			struct Route routes[10];
			int result = 7;
			int size = 10;
			struct Shipment s{ 500,0.5, {7,9} };
			struct Point p1[2] = { {8,10}, {7,10} };
			struct Route r1 = { *p1, 2, 2 };
			r1.numPoints = 3;
			struct Point p2[4] = { {4,10}, {5,10}};
			struct Route r2 = { *p2, 4, 4 };
			r2.numPoints = 4;
			struct Point p3[7] = { {10,5}, {10,6}, {10,7}, {9,7}, {9,8}, {8,8}, {8,9} };
			struct Route r3 = { *p3,7,8 };
			r3.numPoints = 9;
			struct Route routesTest[3] = { r1,r2,r3 };

			result = (getBestRoute(routesTest, size, shipment) ? 7 : result);
			Assert::AreEqual(7, result);
		}
		//GetBestRoute BB: Test6
		TEST_METHOD(getBestRouteBBT06)
		{
			int size = 3;
			init();
			//blue
			struct Point p1[2] = { {9,4}, {10,4} };
			struct Route r1 = { *p1, 2, 2 };
			r1.numPoints = 2;
			//yellow
			struct Point p2[10] = { {3,5}, {3,4}, {4,4}, {5,4}, {6,4}, {7,4}, {8,4}, {9,4}, {10,4}, {10,3} };
			struct Route r2 = { *p2, 10, 4 };
			r2.numPoints = 10;
			//green
			struct Point p3[1] = { {10,4} };
			struct Route r3 = { *p3, 1,8 };
			r3.numPoints = 1;
			struct Route routesT[3] = { r1,r2,r3 };
			struct Shipment s { 500, 0.5, { 10,3 } };
			int result = getBestRoute(routesT, size, s);
			Assert::AreEqual(2, result);
		}
		//GetBestRoute BB: Test7
		TEST_METHOD(getBestRouteBBT07)
		{
			int size = 3;
			init();
			//blue
			struct Point p1[3] = { {2,6}, {2,7}, {2,8} };
			struct Route r1= { *p1, 3, 2};
			r1.numPoints = 3;
			//yellow
			struct Point p2[1] = { {2,8} };
			struct Route r2 = { *p2, 1, 4 };
			r2.numPoints = 1;
			//green
			struct Point p3[11] = { {10,6}, {9,6}, {8,6}, {7,6}, {6,6}, {5,6}, {4,6}, {3,6}, {2,6}, {2,7}, {2,8} };
			struct Route r3 = { *p3, 11,8 };
			r3.numPoints = 11;
			struct Route routesT[3] = { r1,r2,r3 };
			struct Shipment s { 500, 0.5, { 1,8 } };
			int result = getBestRoute(routesT, size, s);
			Assert::AreEqual(1, result);
		}
	};

	TEST_CLASS(containsDestinationTest)
	{
		struct Shipment shipment = { 10,1,{7,24} };
	public:
		//containsDestination blackbox test 1
		TEST_METHOD(containsDestinationBB01)
		{
			struct Point destination = { 20, 10 };
			shipment.destination = destination;
			struct Route testRoute = { 0 };
			for (int i = 0; i < 20; i++) {
				char a = i+1;
				testRoute.points[i] = { a, 10 };
			}
			testRoute.numPoints = 20;
			testRoute.points[20] = { 20, 10 };
			int result = containsDestination(&testRoute, shipment);
			Assert::AreEqual(1, result);
		}
		//containsDestination blackbox test 1a
		TEST_METHOD(containsDestinationBB01a)
		{
			struct Point destination = { 20, 10 };
			shipment.destination = destination;
			struct Route testRoute = { 0 };
			for (int i = 0; i < 20; i++) {
				char a = i+1;
				testRoute.points[i] = { 10, a };
			}
			testRoute.numPoints = 20;
			testRoute.points[20] = { 10, 20 };
			int result = containsDestination(&testRoute, shipment);
			Assert::AreEqual(0, result);
		}
		//containsDestination blackbox test 1b
		TEST_METHOD(containsDestinationBB01b)
		{
			struct Point destination = { 20, 10 };
			shipment.destination = destination;
			struct Route testRoute = { 0 };
			testRoute.points[20] = { NULL, 10 };
			int result = containsDestination(&testRoute, shipment);
			Assert::AreEqual(0, result);
		}
		//containsDestination blackbox test 1c
		TEST_METHOD(containsDestinationBB01c)
		{
			struct Point destination = { 10, 10 };
			shipment.destination = destination;
			struct Route testRoute = { 0 };
			testRoute.points[20] = { 29, 50 };
			int result = containsDestination(&testRoute, shipment);
			Assert::AreEqual(0, result);
		}
		//containsDestination Whitebox test 3
		TEST_METHOD(containsDestinationWB03)
		{
			struct Route testRoute = { 0 };
			testRoute.points[0] = { 8, 21 };
			testRoute.points[1] = { 9, 21 };
			testRoute.points[2] = { 9, 22 };
			testRoute.points[3] = { 7, 21 };
			testRoute.points[4] = { 8, 22 };
			testRoute.points[5] = { 7, 22 };
			testRoute.numPoints = 5;
			struct Point destination = { 8, 22 };
			shipment.destination = destination;

			int result = containsDestination(&testRoute, shipment);
			Assert::AreEqual(1, result);
		}
		//containsDestination Whitebox test 4a
		TEST_METHOD(containsDestinationWB04a)
		{
			struct Route testRoute = { 0 };
			testRoute.points[0] = { 7, 17 };
			testRoute.points[1] = { 8, 17 };
			testRoute.points[2] = { 7, 18 };
			testRoute.points[3] = { 7, 19 };
			testRoute.points[4] = { 8, 19 };
			testRoute.points[5] = { 9, 19 };
			testRoute.numPoints = 5;
			struct Point destination = { 7, 18 };
			shipment.destination = destination;

			int result = containsDestination(&testRoute, shipment);
			Assert::AreEqual(1, result);
		}
		//containsDestination Whitebox test 4b
		TEST_METHOD(containsDestinationWB04b)
		{
			struct Route testRoute = { 0 };
			testRoute.points[0] = { 7, 17 };
			testRoute.points[1] = { 8, 17 };
			testRoute.points[2] = { 8, 19 };
			testRoute.points[3] = { 7, 19 };
			testRoute.points[4] = { 8, 18 };
			testRoute.points[5] = { 9, 19 };
			testRoute.numPoints = 5;
			struct Point destination = { 7, 18 };
			shipment.destination = destination;

			int result = containsDestination(&testRoute, shipment);
			Assert::AreEqual(0, result);
		}
		//containsDestination Whitebox test 4c
		TEST_METHOD(containsDestinationWB04c)
		{
			struct Route testRoute = { 0 };
			testRoute.points[0] = { 7, 17 };
			testRoute.points[1] = { 8, 17 };
			testRoute.points[2] = { 8, 19 };
			testRoute.points[3] = { 7, 19 };
			testRoute.points[4] = { 7, 20 };
			testRoute.points[5] = { 9, 19 };
			testRoute.numPoints = 5;
			struct Point destination = { 7, 18 };
			shipment.destination = destination;

			int result = containsDestination(&testRoute, shipment);
			Assert::AreEqual(0, result);
		}

	};
	//Utilization Score Test Codes
	TEST_CLASS(UtilizationScoreTest)
	{
	public:
		//Black Box Test1
		TEST_METHOD(UtilizationBBT01)
		{
			int result = 0;
			result = calculateUtilizationScore(-1, 0.5);
			Assert::AreEqual(0, result);
		}
		//Black Box Test2
		TEST_METHOD(UtilizationBBT02)
		{
			int result = 0;
			result = calculateUtilizationScore(400, -1);
			Assert::AreEqual(0, result);
		}
		//Black Box Test3
		TEST_METHOD(UtilizationBBT03)
		{
			int result = 0;
			result = calculateUtilizationScore(NULL, 0.25);
			Assert::AreEqual(0, result);
		}
		//Black Box Test4
		TEST_METHOD(UtilizationBBT04)
		{
			int result = 0;
			result = calculateUtilizationScore(300, NULL);
			Assert::AreEqual(0, result);
		}
		//Black Box Test5
		TEST_METHOD(UtilizationBBT05)
		{
			int result = 0;
			result = calculateUtilizationScore(0, 1.0);
			Assert::AreEqual(0, result);
		}
		//Black Box Test6
		TEST_METHOD(UtilizationBBT06)
		{
			int result = 0;
			result = calculateUtilizationScore(300, 0);
			Assert::AreEqual(0, result);
		}
		//Black Box Test7
		TEST_METHOD(UtilizationBBT07)
		{
			int result = 0;
			result = calculateUtilizationScore(0, 0);
			Assert::AreEqual(0, result);
		}
		//Black Box Test8
		TEST_METHOD(UtilizationBBT08)
		{
			int result = 0;
			result = calculateUtilizationScore(-1, -1);
			Assert::AreEqual(0, result);
		}
		//Black Box Test9
		TEST_METHOD(UtilizationBBT09)
		{
			int result = 0;
			result = calculateUtilizationScore(NULL, NULL);
			Assert::AreEqual(0, result);
		}
		//Black Box Test10
		TEST_METHOD(UtilizationBBT10)
		{
			int result = 0;
			result = calculateUtilizationScore(300, 40);
			Assert::AreEqual(0, result);
		}
		//Black Box Test11
		TEST_METHOD(UtilizationBBT11)
		{
			int result = 0;
			result = calculateUtilizationScore(1200, 0.5);
			Assert::AreEqual(86, result);
		}
		//Black Box Test12
		TEST_METHOD(UtilizationBBT12)
		{
			double result = 0;
			result = calculateUtilizationScore(1200, 0.5);
			Assert::AreEqual(86, (int)result);
		}
		//Black Box Test13
		TEST_METHOD(UtilizationBBT13)
		{
			int result = 0;
			result = calculateUtilizationScore(500, 1);
			Assert::AreEqual(18, result);
		}
		//White Box Test1
		TEST_METHOD(UtilizationWBT01)
		{
			int result = 0;
			result = calculateUtilizationScore(0, 0);
			Assert::AreEqual(0, result);
		}
		//White Box Test2
		TEST_METHOD(UtilizationWBT02)
		{
			double check = 0; 
			int result = 0;
			check = calculateUtilizationScore(800, 20);
			check = std::ceil(check * 100.0) / 100.0;
			result = check;
			Assert::AreEqual(1, result);
		}
		//White Box Test3
		TEST_METHOD(UtilizationWBT03)
		{
			double check = 0;
			int result = 0;
			check = calculateUtilizationScore(2000, 20);
			check = std::ceil(check * 100.0) / 100.0;
			result = check;
			Assert::AreEqual(3, result);
		}
		//White Box Test4
		TEST_METHOD(UtilizationWBT04)
		{
			double check = 0;
			int result = 0;
			check = calculateUtilizationScore(800, 72);
			check = std::ceil(check * 100.0) / 100.0;
			result = check;
			Assert::AreEqual(0, result);
		}
		//White Box Test5
		TEST_METHOD(UtilizationWBT05)
		{
			double check = 0;
			int result = 0;
			check = calculateUtilizationScore(3000, 80);
			check = std::ceil(check * 100.0) / 100.0;
			result = check;
			Assert::AreEqual(1, result);
		}
		//White Box Test6
		TEST_METHOD(UtilizationWBT06)
		{
			double check = 0;
			int result = 0;
			check = calculateUtilizationScore(1200, 0);
			check = std::ceil(check * 100.0) / 100.0;
			result = check;
			Assert::AreEqual(0, result);
		}
		//White Box Test7
		TEST_METHOD(UtilizationWBT07)
		{
			double check = 0;
			int result = 0;
			check = calculateUtilizationScore(0, 40);
			check = std::ceil(check * 100.0) / 100.0;
			result = check;
			Assert::AreEqual(0, result);
		}
	};

	//IntegrationTests
	TEST_CLASS(IntegrationTest)
	{
	public:
		//Testing valid package with destination closest to green route
		TEST_METHOD(IntegrationTest01)
		{
			init();
			int result = 0;
			struct Point destination = { 7,24 };//8Y
			struct Shipment package = { 10, 0.5, destination };
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(4, result);
		}
		//Testing valid package with destination closest to blue route
		TEST_METHOD(IntegrationTest02)
		{
			init();
			int result = 0;
			struct Point destination = { 11,11 };//12L
			struct Shipment package = { 10, 0.5, destination };
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(2, result);
		}
		//Testing valid package with destination closest to yellow route
		TEST_METHOD(IntegrationTest03)
		{
			init();
			int result = 0;
			struct Point destination = { 14,3 };//15C
			struct Shipment package = { 10, 0.5, destination };
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(8, result);
		}
		//Testing with invalid package weight
		TEST_METHOD(IntegrationTest04)
		{
			init();
			int result = 0;
			struct Point destination = { 14,3 };//15C
			struct Shipment package = { 2000, 0.5, destination };
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(-1, result);
		}
		//Testing with invalid package volume
		TEST_METHOD(IntegrationTest05)
		{
			init();
			int result = 0;
			struct Point destination = { 14,3 };//15C
			struct Shipment package = { 400, 0.3, destination };
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(-1, result);
		}
		//Testing with invalid package destination
		TEST_METHOD(IntegrationTest06)
		{
			init();
			int result = 0;
			struct Point destination = { 20,0 };//21A
			struct Shipment package = { 400, 0.5, destination };
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(-1, result);
		}
		//Testing with valid package 
		TEST_METHOD(IntegrationTest07)
		{
			init();
			trucks[1].cargoWeight = 999;
			int result = 0;
			struct Point destination = { 7,24 };//8Y
			struct Shipment package = { 400, 0.5, destination };
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(2, result);
		}
		//Testing with valid package 
		TEST_METHOD(IntegrationTest08)
		{
			init();
			trucks[2].cargoWeight = 999;
			int result = 0;
			struct Point destination = { 14,3 };//15C
			struct Shipment package = { 400, 0.5, destination };
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(2, result);
		}
		//Testing with valid package 
		TEST_METHOD(IntegrationTest09)
		{
			init();
			trucks[0].cargoWeight = 999;
			int result = 0;
			struct Point destination = { 15,11 };//15L
			struct Shipment package = { 400, 0.5, destination };
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(8, result);
		}
		//Testing with valid package 
		TEST_METHOD(IntegrationTest10)
		{
			init();
			trucks[0].cargoWeight = 999;
			trucks[1].cargoWeight = 999;
			trucks[2].cargoWeight = 999;
			int result = 0;
			struct Point destination = { 15,11 };//15L
			struct Shipment package = { 400, 0.5, destination };
			if (validate(package.vol, package.weight, package.destination) == 1)
			{
				result = AssignTruck(package);
				result = (result == 0 ? -1 : result);
			}
			else
				result = -1;
			Assert::AreEqual(-1, result);
		}
	};
	// Acceptance Tests
	TEST_CLASS(AcceptanceTest)
	{
	public:
		//Testing valid package with destination closest to green route
		TEST_METHOD(AcceptanceTest01a)
		{
			init();
			int result = 0;
			struct Point destination = { 7,24 };//8Y
			struct Shipment package = { 10, 0.5, destination };
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(4, result);
		}
		TEST_METHOD(AcceptanceTest01b)
		{
			init();
			int result = 0;
			struct Point destination = { 7,24 };//8Y
			struct Shipment package = { 10, 0.25, destination };
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(4, result);
		}
		TEST_METHOD(AcceptanceTest01c)
		{
			init();
			int result = 0;
			struct Point destination = { 7,24 };//8Y
			struct Shipment package = { 10, 1, destination };
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(4, result);
		}
		TEST_METHOD(AcceptanceTest01d)
		{
			init();
			int result = 0;
			struct Point destination = { 7,24 };//8Y
			struct Shipment package = { 10, 0.75, destination };
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(-1, result);
		}
		TEST_METHOD(AcceptanceTest02a)
		{
			init();
			int result = 0;
			struct Point destination = { 7,24 };//8Y
			struct Shipment package = { 999, 0.5, destination };
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(4, result);
		}
		TEST_METHOD(AcceptanceTest02b)
		{
			init();
			int result = 0;
			struct Point destination = { 7,24 };//8Y
			struct Shipment package = { 1, 0.5, destination };
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(4, result);
		}
		TEST_METHOD(AcceptanceTest02c)
		{
			init();
			int result = 0;
			struct Point destination = { 7,24 };//8Y
			struct Shipment package = { 0, 0.5, destination };
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(-1, result);
		}
		TEST_METHOD(AcceptanceTest02d)
		{
			init();
			int result = 0;
			struct Point destination = { 7,24 };//8Y
			struct Shipment package = { 1001, 0.5, destination };
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(-1, result);
		}
		TEST_METHOD(AcceptanceTest03a)
		{
			init();
			int result = 0;
			struct Point destination = { 11,11 }; //12L
			struct Shipment package = { 10, 0.5, destination };
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(2, result);
		}
		TEST_METHOD(AcceptanceTest03b)
		{
			init();
			int result = 0;
			struct Point destination = { 11,10 }; //12L
			struct Shipment package = { 10, 0.5, destination };
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(-1, result);
		}
		TEST_METHOD(AcceptanceTest4)
		{
			init();
			int result = 0;
			struct Point destination = { 7,24 };//8Y
			struct Shipment package = { 10, 0.5, destination };
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(4, result);
		}
		TEST_METHOD(AcceptanceTest5)
		{
			init();
			int result = 0;
			trucks[1].cargoWeight = 500;
			struct Point destination = { 7,24 };//8Y
			struct Shipment package = { 510, 0.5, destination };
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(2, result);
		}
		TEST_METHOD(AcceptanceTest6)
		{
			init();
			int result = 0;
			trucks[1].cargoWeight = 300;
			trucks[1].cargoVol = 35.5;
			struct Point destination = { 7,24 };//8Y
			struct Shipment package = { 510, 1, destination };
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(2, result);
		}
		TEST_METHOD(AcceptanceTest7)
		{
			init();
			int result = 0;
			struct Point destination = { 7,24 };//8Y
			struct Shipment package = { 10, 0.5, destination };
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(4, result);
		}
		TEST_METHOD(AcceptanceTest8)
		{
			init();
			int result = 0;
			trucks[1].cargoWeight = 500;
			struct Point destination = { 7,23 };//8Y
			struct Shipment package = { 510, 0.5, destination };
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(2, result);
		}
		TEST_METHOD(AcceptanceTest9)
		{
			init();
			int result = 0;
			trucks[1].cargoWeight = 300;
			trucks[1].cargoVol = 35.5;
			struct Point destination = { 7,23 };//8Y
			struct Shipment package = { 510, 1, destination };
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(2, result);
		}
		TEST_METHOD(AcceptanceTest10)
		{
			init();
			int result = 0;
			struct Point destination = { 1,1 };//8Y
			struct Shipment package = { 510, 1, destination };
			if (validate(package.vol, package.weight, package.destination) == 1)
				result = AssignTruck(package);
			else
				result = -1;
			Assert::AreEqual(2, result);
		}
		TEST_METHOD(AcceptanceTest11)
		{
			init();
			int result = 0;
			trucks[0].cargoWeight = 700;
			trucks[1].cargoWeight = 700;
			trucks[2].cargoWeight = 700;
			struct Point destination = { 1,1 };//8Y
			struct Shipment package = { 510, 1, destination };
			if (validate(package.vol, package.weight, package.destination) == 1)
			{
				result = AssignTruck(package);
				result = (result == -1 ? 0 : result);
			}
			else
				result = -1;
			Assert::AreEqual(0, result);
		}
	};
}
