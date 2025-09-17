#include "Box_Capacity.h"
#include <gtest/gtest.h>

TEST(BoxCapacityTest, BasicTest) {
    int w = 16, l = 16, h = 16;
    int res = Box_Capacity(w, l, h);
    EXPECT_EQ(res, 1);
}

TEST(BoxCapacityTest, AllNegative) {
    int w = -16, l = -16, h = -16;
    int res = Box_Capacity(w, l, h);
    EXPECT_EQ(res, 0);
}

TEST(BoxCapacityTest, AllZeros) {
    int w = 0, l = 0, h = 0;
    int res = Box_Capacity(w, l, h);
    EXPECT_EQ(res, 0);
}

TEST(BoxCapacityTest, LargeNumbers) {
    int w = 1000, l = 1000, h = 1000;
    int res = Box_Capacity(w, l, h);
    EXPECT_EQ(res, 238328);
}
