#include "Array.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <cmath>

using namespace std;
typedef Array::value_type* TArray;

int main()
{
    int n;
    cout << "Enter the size of the regular array: ";
    cin >> n;

    // Create a regular array and fill it with random values
    int* regularArray = new int[n];
    srand(time(NULL));
    cout << "\nRegular Array before modification:\n[ ";
    for (int i = 0; i < n; ++i)
    {
        regularArray[i] = -50 + rand() % 101; // Random value between -50 and 50
        cout << regularArray[i] << " ";
    }
    cout << "]\n\n";

    // Create a dynamic array from the regular array
    Array dynamicArray = Array::dynamicArrayFromRegular(regularArray, n);

    // Output the sum and absolute average of dynamic array elements
    cout << "Sum of dynamic array elements: " << dynamicArray.calculateSum() << endl;
    cout << "Absolute average of dynamic array elements: " << dynamicArray.calculateAbsoluteAverage() << endl;

    // Output the dynamic array before modification
    cout << "\nDynamic Array before modification:\n" << dynamicArray << endl;

    // Divide odd numbers by the average and output the modified array
    dynamicArray.divideOddNumbersByAverage();
    cout << "Dynamic Array after modification:\n" << dynamicArray << endl;

    // Deallocate memory for the regular array
    delete[] regularArray;

    return 0;
}
