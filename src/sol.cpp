#include <iostream>
#include "Three.h"

int main(int argc, char** argv) {
    unsigned int aD, bD;
    std::cin >> aD >> bD;
    
    Three a(aD);
    Three b(bD);
    
    Three res1 = a - b;
    std::cout << res1 << std::endl;
    
    Three res2 = a - b;
    std::cout << res2 << std::endl;
    return 0;
}