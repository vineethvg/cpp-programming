#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> li1 = {1, 2, 3, 4};
    list<int> li2 = {5, 10, 9, 6, 7, 8};
    list<int> li3 = {5, 6, 7, 8};

    list<int>::iterator itr = li1.begin();
    li1.insert(itr, 0);

    for (itr = li1.begin(); itr != li1.end(); ++itr)
        cout << *itr << " ";

    // sort() to sort elements in increasing order
    cout << "\n";
    li2.sort();
    cout << "Sorted list : "
         << "\n";
    for (itr = li2.begin(); itr != li2.end(); ++itr)
        cout << *itr << " ";

    // reverse() to reverse the list
    cout << "\n";
    li2.reverse();
    cout << "Reversed list : "
         << "\n";
    for (itr = li2.begin(); itr != li2.end(); ++itr)
        cout << *itr << " ";

    // merge() merge two lists
    cout << "\n";
    li1.merge(li2);
    cout << "Merged list : "
         << "\n";
    for (itr = li1.begin(); itr != li1.end(); ++itr)
        cout << *itr << " ";

    // splice()
    cout << "\n";
    list<int>::iterator itr1 = li2.begin();
    li2.splice(itr1, li3);
    for (itr1 = li2.begin(); itr1 != li2.end(); ++itr1)
        cout << *itr1 << " ";
    return 0;
}