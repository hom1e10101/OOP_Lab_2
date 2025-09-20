#include <iostream>

#include "Three.h"

int main(int argc, char** argv) {
    unsigned int aD, bD;
    std::cin >> aD >> bD;
    
    Three a(aD);
    Three b(bD);
    
    Three res1 = add(a, b);
    // std::cout << res1 << std::endl;
    res1.print();
    std::cout << "\n";
    
    Three res2 = sub(a, b);
    // std::cout << res2 << std::endl;
    res2.print();
    std::cout << "\n";
    return 0;
}