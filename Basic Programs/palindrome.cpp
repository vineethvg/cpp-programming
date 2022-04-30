#include <iostream>
using namespace std;

int main()
{
    int n, temp, sum = 0, r;
    cout << "Enter the number : ";
    cin >> n;
    temp = n;

    while (n > 0)
    {
        r = n % 10;
        sum = (sum * 10) + r;
        n = n / 10;
    }

    if (temp == sum)
        cout << "The Number is a Palindrome!";
    else
        cout << "The Number is not a Palindrome";
    return 0;
}