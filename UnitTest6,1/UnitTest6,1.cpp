	#include "pch.h"
	#include "CppUnitTest.h"
    #include "../lab6.1/Array.cpp"
    #include "../lab6.1/Array.h"
	using namespace Microsoft::VisualStudio::CppUnitTestFramework;

	namespace UnitTest61
	{
		TEST_CLASS(UnitTest61)
		{
		public:
		
			TEST_METHOD(TestMethod1)
			{
				const int elements[] = { 1, 2, 3, 4, 5 };
				Array testArray;
				for (int element : elements) {
					testArray.push_back(element);
				}
				Assert::AreEqual(15.0, testArray.calculateSum()); // Sum of elements should be 15
			}
		};
	}
