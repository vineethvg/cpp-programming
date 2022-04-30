#include <iostream>
using namespace std;
// Function overriding
class A
{
public:
    virtual void getName()
    {
        cout << "name is Roccky bhai!!!";
    }
};

class B : public A
{
public:
    void getName()
    {
        cout << "KGF hain boss!!!";
    }
};

int main()
{
    A *a;
    B b;
    a = &b;
    a->getName();
}