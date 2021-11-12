#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7.1/lab7.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71
{
	TEST_CLASS(UnitTest71)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int r = 1, c = 3;
			int** T = new int* [r];
			for (int i = 0; i < r; i++)
				T[i] = new int[c];
			T[0][0] = 5; T[0][1] = 1; T[0][2] = 6;
			int t = Amount(T, r, c);
			Assert::AreEqual(t, 2);
		}
	};
}
