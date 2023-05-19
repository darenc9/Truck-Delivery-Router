//Author: Hephzibah Nick-Oshomah and Devon Chan
//Document: MILESTONE 3 blackbox test for the Validate function.
#include "pch.h"
#include "CppUnitTest.h"
#include "assert.h"
#include "mapping_r.h"
#include "Shipment_r.h"
#include "Truck_r.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BlackboxTest
{
	TEST_CLASS(ValidateTest)
	{
	public:
		//Test 1a-1c: tests all valid shipment size inputs
		TEST_METHOD(ValidateTest01a)
		{
			struct Point dest = { 2, 2 };
			int result = validate(0.5, 500, dest);
			Assert::AreEqual(1, result);
		}
		TEST_METHOD(validateTest01b)
		{
			struct Point dest = { 2, 2 };
			int result = validate(0.25, 500, dest);
			Assert::AreEqual(1, result);
		}
		TEST_METHOD(validateTest01c)
		{
			struct Point dest = { 2, 2 };
			int result = validate(1, 500, dest);
			Assert::AreEqual(1, result);

		}

		//Test 2a-2e: tests a variety of invalid shipment size inputs
		TEST_METHOD(validateTest02a)
		{
			struct Point dest = { 2, 2 };
			int result = validate(-1, 500, dest);
			Assert::AreEqual(-1, result);
		}
		TEST_METHOD(validateTest02b)
		{
			struct Point dest = { 2, 2 };
			int result = validate(NULL, 500, dest);
			Assert::AreEqual(-1, result);
		}
		TEST_METHOD(validateTest02c)
		{
			struct Point dest = { 2, 2 };
			int result = validate(2, 500, dest);
			Assert::AreEqual(-1, result);
		}
		TEST_METHOD(validateTest02d)
		{
			struct Point dest = { 2, 2 };
			int result = validate(0.5678, 500, dest);
			Assert::AreEqual(-1, result);
		}
		TEST_METHOD(validateTest02e)
		{
			struct Point dest = { 2, 2 };
			int result = validate(1234567890, 500, dest);
			Assert::AreEqual(-1, result);
		}

		//Test 3a-3c: tests a variety of valid shipment weight inputs
		TEST_METHOD(validateTest03a)
		{
			struct Point dest = { 2, 2 };
			int result = validate(0.5, 1, dest);
			Assert::AreEqual(1, result);
		}
		TEST_METHOD(validateTest03b)
		{
			struct Point dest = { 2, 2 };
			int result = validate(0.5, 1000, dest);
			Assert::AreEqual(1, result);
		}
		TEST_METHOD(validateTest03c)
		{
			struct Point dest = { 2, 2 };
			int result = validate(0.5, 300, dest);
			Assert::AreEqual(1, result);
		}

		//Test 4a-4e: tests a variety of invalid shipment weight inputs
		TEST_METHOD(validateTest04a)
		{
			struct Point dest = { 2, 2 };
			int result = validate(0.5, 0, dest);
			Assert::AreEqual(-2, result);
		}
		TEST_METHOD(validateTest04b)
		{
			struct Point dest = { 2, 2 };
			int result = validate(0.5, 100000000, dest);
			Assert::AreEqual(-2, result);
		}
		TEST_METHOD(validateTest04c)
		{
			struct Point dest = { 2, 2 };
			int result = validate(0.5, NULL, dest);
			Assert::AreEqual(-2, result);
		}
		TEST_METHOD(validateTest04d)
		{
			struct Point dest = { 2, 2 };
			int result = validate(0.5, -1, dest);
			Assert::AreEqual(-2, result);
		}
		TEST_METHOD(validateTest04e)
		{
			struct Point dest = { 2, 2 };
			int result = validate(0.5, 1001, dest);
			Assert::AreEqual(-2, result);
		}

		//Test 5a-5d: tests a variety of valid destination inputs
		TEST_METHOD(validateTest05a)
		{
			struct Point dest2 = { 2, 2 };
			int result = validate(0.5, 1, dest2);
			Assert::AreEqual(1, result);
		}
		TEST_METHOD(validateTest05b)
		{
			struct Point dest3 = { 25, 25 };
			int result = validate(0.5, 1, dest3);
			Assert::AreEqual(1, result);
		}
		TEST_METHOD(validateTest05c)
		{
			struct Point dest4 = { 2, 2 };
			int result = validate(0.5, 1, dest4);
			Assert::AreEqual(1, result);
		}
		TEST_METHOD(validateTest05d)
		{
			struct Point dest5 = { 8, 24 };
			int result = validate(0.5, 1, dest5);
			Assert::AreEqual(1, result);
		}

		//Test 6a-6j: tests a variety of invalid destination inputs
		TEST_METHOD(validateTest06a)
		{
			struct Point dest6 = { NULL, 1 };
			int result = validate(0.5, 400, dest6);
			Assert::AreEqual(-3, result);
		}
		TEST_METHOD(validateTest06b)
		{
			struct Point dest7 = { 25, NULL };
			int result = validate(0.5, 400, dest7);
			Assert::AreEqual(-3, result);
		}
		TEST_METHOD(validateTest06c)
		{
			struct Point dest8 = { 0, 26 };
			int result = validate(0.5, 400, dest8);
			Assert::AreEqual(-3, result);
		}
		TEST_METHOD(validateTest06d)
		{
			struct Point dest9 = { 26, 0 };
			int result = validate(0.5, 400, dest9);
			Assert::AreEqual(-3, result);
		}
		TEST_METHOD(validateTest06e)
		{
			struct Point dest10 = { 0, 0 };
			int result = validate(0.5, 400, dest10);
			Assert::AreEqual(-3, result);
		}
		TEST_METHOD(validateTest06f)
		{
			struct Point dest11 = { 10, 50 };
			int result = validate(0.5, 400, dest11);
			Assert::AreEqual(-3, result);
		}
		TEST_METHOD(validateTest06g)
		{
			struct Point dest12 = { -2, 20 };
			int result = validate(0.5, 400, dest12);
			Assert::AreEqual(-3, result);
		}
		TEST_METHOD(validateTest06h)
		{
			struct Point dest13 = { 50, 10 };
			int result = validate(0.5, 400, dest13);
			Assert::AreEqual(-3, result);
		}
		TEST_METHOD(validateTest06i)
		{
			struct Point dest13 = { 2, -1 };
			int result = validate(0.5, 400, dest13);
			Assert::AreEqual(-3, result);
		}
		TEST_METHOD(validateTest06j)
		{
			struct Point dest13 = { -1, -1 };
			int result = validate(0.5, 400, dest13);
			Assert::AreEqual(-3, result);
		}
		//Test7a-7c Inputs with special characters
		TEST_METHOD(validateTest07a)
		{
			struct Point dest13 = { 10, 10 };
			int result = validate('B', 10, dest13);
			Assert::AreEqual(-1, result);
		}
		TEST_METHOD(validateTest07b)
		{
			struct Point dest13 = { 10, 10 };
			int result = validate(0.5, '@', dest13);
			Assert::AreEqual(-3, result);
		}
		TEST_METHOD(validateTest07c)
		{
			struct Point dest13 = { 'A','Z'};
			int result = validate(0.5, 10, dest13);
			Assert::AreEqual(-3, result);
		}
	};
	TEST_CLASS(ValidateWhiteTest)
	{
	public:
		//Test 08a
		TEST_METHOD(ValidateTest08a)
		{
			struct Point dest = { 2,2 };
			int result = validate(0.25, 200, dest);
			Assert::AreEqual(1, result);
		}
		//Test 08b
		TEST_METHOD(ValidateTest08b)
		{
			struct Point dest = { 18,8 };
			int result = validate(0.5, 20, dest);
			Assert::AreEqual(1, result);
		}
		//Test 08c
		TEST_METHOD(ValidateTest08c)
		{
			struct Point dest = { 23,11 };
			int result = validate(1, 20, dest);
			Assert::AreEqual(1, result);
		}
		//Test 09a
		TEST_METHOD(ValidateTest09a)
		{
			struct Point dest = { 22, 22 };
			int result = validate(0.4, 20, dest);
			Assert::AreEqual(-1, result);
		}
		//Test 09b
		TEST_METHOD(ValidateTest09b)
		{
			struct Point dest = { 22, 22 };
			int result = validate(0.9999999, 20, dest);
			Assert::AreEqual(-1, result);
		}
		//Test 09c
		TEST_METHOD(ValidateTest09c)
		{
			struct Point dest = { 1, 21 };
			int result = validate(1.000000001, 75, dest);
			Assert::AreEqual(-1, result);
		}
		//Test 09d
		TEST_METHOD(ValidateTest09d)
		{
			struct Point dest = { 1, 21 };
			int result = validate(0.251, 30, dest);
			Assert::AreEqual(-1, result);
		}
		//Test 09e
		TEST_METHOD(ValidateTest09e)
		{
			struct Point dest = { 22, 22 };
			int result = validate(0.500000001, 90, dest);
			Assert::AreEqual(-1, result);
		}
		//Test 09f
		TEST_METHOD(ValidateTest09f)
		{
			struct Point dest = { 1, 21 };
			int result = validate(-0.25, 30, dest);
			Assert::AreEqual(-1, result);
		}
		//Test 09g
		TEST_METHOD(ValidateTest09g)
		{
			struct Point dest = { 1, 21 };
			int result = validate(-0.50, 40, dest);
			Assert::AreEqual(-1, result);
		}
		//Test 10a
		TEST_METHOD(ValidateTest10a)
		{
			struct Point dest = { 1, 7 };
			int result = validate(0.50, 999, dest);
			Assert::AreEqual(1, result);
		}
		//Test 10b
		TEST_METHOD(ValidateTest10b)
		{
			struct Point dest = { 1, 7 };
			int result = validate(0.25, 2, dest);
			Assert::AreEqual(1, result);
		}
		//Test 10c
		TEST_METHOD(ValidateTest10c)
		{
			struct Point dest = { 1, 7 };
			int result = validate(0.5, 1000.1, dest);
			Assert::AreEqual(1, result);
		}
		//Test 11a
		TEST_METHOD(ValidateTest11a)
		{
			struct Point dest = { 1, 7 };
			int result = validate(1, -1000, dest);
			Assert::AreEqual(-2, result);
		}
		//Test 11b
		TEST_METHOD(ValidateTest11b)
		{
			struct Point dest = { 1, 21 };
			int result = validate(0.25, 0.9, dest);
			Assert::AreEqual(-2, result);
		}
		//Test 11c
		TEST_METHOD(ValidateTest11c)
		{
			struct Point dest = { 1, 21 };
			int result = validate(0.25, (int)"ABXZ", dest);
			Assert::AreEqual(-2, result);
		}
		//Test 11d
		TEST_METHOD(ValidateTest11d)
		{
			struct Point dest = { 1, 7 };
			int result = validate(1, -500, dest);
			Assert::AreEqual(-2, result);
		}
		//Test 11e
		TEST_METHOD(ValidateTest11e)
		{
			struct Point dest = { 1, 7 };
			int result = validate(0.25, 11111111111, dest);
			Assert::AreEqual(-2, result);
		}
		//Test 12a
		TEST_METHOD(ValidateTest12a)
		{
			struct Point dest = { 1, 4 };
			int result = validate(0.25, 30, dest);
			Assert::AreEqual(1, result);
		}
		//Test 12b
		TEST_METHOD(ValidateTest12b)
		{
			struct Point dest = { 24, 14};
			int result = validate(1, 500, dest);
			Assert::AreEqual(1, result);
		}
		//Test 12c
		TEST_METHOD(ValidateTest12c)
		{
			struct Point dest = { 2, 10 };
			int result = validate(1, 90, dest);
			Assert::AreEqual(1, result);
		}
		//Test 13a
		TEST_METHOD(ValidateTest13a)
		{
			struct Point dest = { 1, 3 };
			int result = validate(.5, 200, dest);
			Assert::AreEqual(-3, result);
		}
		//Test 13b
		TEST_METHOD(ValidateTest13b)
		{
			struct Point dest = { 24, 24 };
			int result = validate(1, 300, dest);
			Assert::AreEqual(-3, result);
		}
		//Test 13c
		TEST_METHOD(ValidateTest13c)
		{
			struct Point dest = { -14, 20 };
			int result = validate(1, 59, dest);
			Assert::AreEqual(-3, result);
		}
		//Test 13d
		TEST_METHOD(ValidateTest13d)
		{
			struct Point dest = { 'B', 2};
			int result = validate(1, 99, dest);
			Assert::AreEqual(-3, result);
		}
		//Test 13e
		TEST_METHOD(ValidateTest13e)
		{
			struct Point dest = { 14, -20 };
			int result = validate(1, 99, dest);
			Assert::AreEqual(-3, result);
		}
		//Test 13f
		TEST_METHOD(ValidateTest13f)
		{
			struct Point dest = { 1, '@'};
			int result = validate(1, 99, dest);
			Assert::AreEqual(-3, result);
		}
		//Test 13g
		TEST_METHOD(ValidateTest13g)
		{
			struct Point dest = { 13, 10 };
			int result = validate(1, 99, dest);
			Assert::AreEqual(-3, result);
		}
		//Test 14
		TEST_METHOD(ValidateTest14)
		{
			struct Point dest = {'x', 0};
			int result = validate(0, 0, dest);
			Assert::AreEqual(0, result);
		}
	};
}