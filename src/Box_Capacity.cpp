#include "Box_Capacity.h"

int Box_Capacity(const int width, const int lenth, const int height) {
    if (width <= 0 || lenth <= 0 || height <= 0) {
        return 0;
    }
    return (width / 16) * (lenth / 16) * (height / 16);
}
