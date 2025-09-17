#include <iostream>
#include "Box_Capacity.h"

int main(int argc, char** argv) {
    int w, l, h;
    std::cin >> w >> l >> h;

    std::cout << Box_Capacity(w, l, h) << "\n";
    return 0;
}