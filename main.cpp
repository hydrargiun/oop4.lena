#include <iostream>
#include "Table.h"
using namespace oop4;
int main() {
    Table tab;
    tab = tab.Add(2);
    tab = tab.Add(4);
    tab = tab.Add(3);
    tab = tab.Add(1);
    tab = tab.Add(10);
    tab = tab.Add(5);
    tab = tab.Add(0);
    tab.Display();
    tab.Show_vec();
}