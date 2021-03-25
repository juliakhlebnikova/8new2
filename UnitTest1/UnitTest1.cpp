#include "pch.h"
#include "CppUnitTest.h"
#include "../Project8/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			list <int> A = { 0 };
			list <int> B = { 4,2 };
			list <int> C = { 8,4 };
			list <int> D = { 1, 1 };

			Assert::IsTrue(5 * A == A);
			Assert::IsTrue(2 * B == C);
			Assert::IsTrue(1 * D == D);
		}

		TEST_METHOD(TestMethod2)
		{
			list <int> B = { 4,2 };
			list <int> C = { 4,2,0 };

			Assert::IsTrue(xit(B) == C);
		}


		TEST_METHOD(TestMethod3)
		{
			list <int> B = { 4, 1 };
			list <int> C = { -4, -1 };
			list <int> A = { 0 };

			Assert::IsTrue(-B == C);
			Assert::IsTrue(-A == A);
		}
		
		TEST_METHOD(TestMethod4)
		{
			list <int> A = { 0, 0, 0 };
			list <int> B = { 0 };
			list <int> C = { 0, 0, 4, -2 };
			list <int> D = { 8, -4 };
			list <int> E = { 0, 0, 12, -6 };

			Assert::IsTrue(A + B == A);
			Assert::IsTrue(C + D == E);
			Assert::IsTrue(A - B == A);
			Assert::IsTrue(E - D == C);

		}

		TEST_METHOD(TestMethod5)
		{
			list<int> P1 = { 1 }, P2 = { 1, -2, 3, 0, -4 }, R1 = { 1, -2, 3, 0, -4 };
			list<int> P3 = { 0, 0, 3 }, P4 = { 1, 1 }, R2 = { 0, 0, 3, 3 };
			list<int> P5 = { 0 }, P6 = { 1, -2, 3, 0, -4 }, R3 = { 0 };
			list<int> P7 = { 3 }, P8 = { 1, 5 }, R4 = { 3, 15 };

			Assert::IsTrue(P1 * P2 == R1);
			Assert::IsTrue(P1 * P2 == P2 * P1);
			Assert::IsTrue(P3 * P4 == R2);
			Assert::IsTrue(P3 * P4 == P4 * P3);
			Assert::IsTrue(P5 * P6 == R3);
			Assert::IsTrue(P5 * P6 == P6 * P5);
			Assert::IsTrue(P7 * P8 == R4);
			Assert::IsTrue(P7 * P8 == P8 * P7);
		}
	};
}
