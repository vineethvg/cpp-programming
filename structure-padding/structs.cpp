// Datatypes and their sizes
//
// ------------------------------------
// | Data type    -      Size         |
// ------------------------------------
// |    char      -     1 byte        |
// |    int       -     2 or 4 bytes  |
// |   float      -     4 bytes       |
// |    double    -     8 bytes       |
// ------------------------------------

// Example 1:

#include <iostream>
using namespace std;

struct A
{
    int a = 10;   // 4
    char b = 'a'; // 1
};

int main()
{
    struct A s1;
    cout << sizeof(s1) << endl; // output is 8
}

// 4 bytes + 1 byte = 5 bytes ryt?
// Mathematically yes....4+1 is 5,
// but when it comes to memory allocation, additional three empty blocks are added!!!!
// why three additional blocks??
// Architecture of a computer processor is such a way that it can read 1 word (4 byte in 32 bit processor) from memory at a time.
// To make use of this advantage of processor, data are always aligned as 4 bytes package which leads to insert empty addresses between other member’s address.
// Since we are considering memory blocks....int datatype will fill 4 blocks and char datatype will fill 1 block,
// Now if I add three empty bytes after char...then it will be read as 1 word(4 bytes), hence the processor reads both data types in single CPU cycle.

// Example 2

#include <iostream>
using namespace std;

struct A
{
    int a = 10;     // 4
    char b = 'a';   // 1
    double c = 111; // 8
};

int main()
{
    struct A s1;
    cout << sizeof(s1) << endl; // output is 16
}

// double data type is considered as 4 + 4, so int(4) + char(1 + 3) + double(4 + 4) = 16

// Example 3

#include <iostream>
using namespace std;

struct A
{
    int a = 10;
    char b[20];
};

int main()
{
    struct A s1;
    cout << sizeof(s1) << endl; // guess the output???
}