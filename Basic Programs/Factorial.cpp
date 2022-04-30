#include <iostream>
using namespace std;

int main()
{
    int i, number, fact = 1;
    cout << "Enter the number to find factorial : ";
    cin >> number;

    for (i = 1; i <= number; i++)
    {
        fact = fact * i;
    }
    cout << "Factorial of " << number << " is : " << fact << endl;
    return 0;
}