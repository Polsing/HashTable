#include "HashTable.h"
#include <iostream>
using namespace std;

int main()
{
    HashTable h;
    h.display();
    h.addkey(1);
    h.addkey(5);
    h.addkey(6);
    h.addkey(8);
    h.display();
    h.addkey(9);
    h.display();
    return 0;
}
