#include <iostream>
using namespace std;

// SINGLE LEVEL INHERITANCE
// ----------------------------------------------------------
class Name
{
public:
    string name = "Vineeth";
};
class Age : public Name
{
public:
    float age = 22;
};

int main(void)
{
    Age a1;
    cout << "Name is : " << a1.name << endl;
    cout << "Age is : " << a1.age << endl;
    return 0;
}
// ----------------------------------------------------------

// MUTI LEVEL INHERITANCE
// ----------------------------------------------------------
class Animal
{
public:
    void eat()
    {
        cout << "Eating.." << endl;
    }
};

class Dog : public Animal
{
public:
    void bark()
    {
        cout << "Barking..." << endl;
    }
};

class babyDog : public Dog
{
public:
    void weeping()
    {
        cout << "Weeping..." << endl;
    }
};

int main(void)
{
    babyDog d1;
    d1.eat();
    d1.bark();
    d1.weeping();
    return 0;
}
// ----------------------------------------------------------

// MULTIPLE INHERITANCE
// ----------------------------------------------------------

class A
{
public:
    string name = "Vineeth";
};

class B
{
public:
    int age = 22;
};

class C : public A, public B
{
public:
    void display()
    {
        cout << "Name is : " << name << endl;
        cout << "Age is : " << age << endl;
    }
};

int main()
{
    C c1;
    c1.display();
}
// ----------------------------------------------------------

// HIERARCHIAL INHERITANCE

class shape
{
public:
    int a;
    int b;
    void get_data(int n, int m)
    {
        a = n;
        b = m;
    }
};

class rectangle : public shape
{
public:
    int rect_area()
    {
        int res = a * b;
        return res;
    }
};

class triangle : public shape
{
public:
    int tri_area()
    {
        float res = 0.5 * a * b;
        return res;
    }
};

int main()
{
    rectangle r;
    triangle t;

    int length, breadth, base, height;
    cout << "Enter the lenght and breadth of rectangle : " << endl;
    cin >> length >> breadth;
    r.get_data(length, breadth);
    int m = r.rect_area();
    cout << "Area of Rectangle is :" << m << endl;
    // simlarly fot triangle
}
//----------------------------------------------------------