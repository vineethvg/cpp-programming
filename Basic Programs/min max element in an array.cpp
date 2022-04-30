#include <iostream>
using namespace std;

void printMax(int arr[]);
void printMin(int arr[]);

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    printMax(arr);
    printMin(arr);
}

void printMax(int arr[])
{
    int max = arr[0];
    for (int i = 0; i < 5; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    cout << "Maximum : " << endl;
    cout << max << endl;
}

void printMin(int arr[])
{
    int min = arr[0];
    for (int i; i < 5; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    cout << "Minimum :" << endl;
    cout << min << endl;
}