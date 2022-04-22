#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> vS;
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {6, 7, 8, 9, 10};
    vector<int> v3 = {100, 200, 300, 400};

    // push_back() adds new element at the end
    vS.push_back("Hello");
    vS.push_back("World");
    vS.push_back("!");

    // back() gives reference to the last element
    cout << vS.back() << endl;

    // pop_back() removes last element
    vS.push_back("!");
    vS.pop_back();

    // insert() inserts an element at specified postion
    vS.insert(vS.begin() + 1, "Stupid");
    // adds "😒" twice
    vS.insert(vS.begin() + 2, 2, "😒");

    for (vector<string>::iterator itr = vS.begin(); itr != vS.end(); ++itr)
        cout << *itr << " ";

    cout << "\n";

    // swap() used to swap elements between two vectors
    v1.swap(v2);
    cout << "After Swap - v1 : ";
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";
    cout << "\n";
    cout << "After Swap - v2 : ";
    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";

    cout << "\n";

    for (int i = 0; i < v3.size(); i++)
        cout << v3[i] << " ";
    cout << "\n";

    // clear() removes all elements from vector
    v3.clear();
    for (int i = 0; i < v3.size(); i++)
        cout << v3[i] << " ";

    // This function inserts a new element just before the position pos and size of the vector container increases
    vector<int>::iterator it = v2.emplace(v2.begin() + 2, 8);
    v2.emplace(it, 9);

    cout << "\n";
    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";

        return 0;
}