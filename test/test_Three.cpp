#include "Three.h"
#include <gtest/gtest.h>


TEST(TestThree, BasicConv) {
    int aD = 10;
    Three a(aD);
    Three ans({1, 0, 1});
    EXPECT_EQ(a, ans);
}

TEST(TestThree, BasicAdding) {
    int aD = 10, bD = 2;
    Three a(aD), b(bD);
    auto res = a + b;
    auto ans = Three(aD + bD);
    EXPECT_EQ(res, ans);
}

TEST(TestThree, LargeAdding) {
    int aD = 1500, bD = 50000;
    Three a(aD), b(bD);
    auto res = a + b;
    auto ans = Three(aD + bD);
    EXPECT_EQ(res, ans);
}


TEST(TestThree, BasicSublime) {
    int aD = 10, bD = 2;
    Three a(aD), b(bD);
    auto res = a - b;
    std::cerr << res << "\n";
    auto ans = Three(aD - bD);
    std::cerr << ans << "\n";
    EXPECT_EQ(res, ans);
}

TEST(TestThree, LargeSublime) {
    int aD = 500000, bD = 1500;
    Three a(aD), b(bD);
    auto res = a - b;
    auto ans = Three(aD - bD);
    EXPECT_EQ(res, ans);
}

TEST(TestThree, WrongSublime) {
    int aD = 0, bD = 1500;
    Three a(aD), b(bD);
    auto res = a - b;
    auto ans = Three(aD - bD);
    EXPECT_EQ(res, ans);
}

TEST(TestThree, CorrectEquals) {
    int aD = 500000, bD = 500000;
    Three a(aD), b(bD);
    auto eq = a == b;
    auto neq = a != b;
    EXPECT_EQ(eq, true);
    EXPECT_EQ(neq, false);
}

TEST(TestThree, IncorrectEquals) {
    int aD = 500000, bD = 50000;
    Three a(aD), b(bD);
    auto eq = a == b;
    auto neq = a != b;
    EXPECT_EQ(eq, false);
    EXPECT_EQ(neq, true);
}


TEST(TestThree, CorrectLargerTest) {
    int aD = 500000, bD = 50000;
    Three a(aD), b(bD);
    auto eq = a >= b;
    auto neq = a < b;
    EXPECT_EQ(eq, true);
    EXPECT_EQ(neq, false);
}

TEST(TestThree, IncorrectLargerTest) {
    int aD = 1000, bD = 50000;
    Three a(aD), b(bD);
    auto eq = a >= b;
    auto neq = a < b;
    EXPECT_EQ(eq, false);
    EXPECT_EQ(neq, true);
}

TEST(TestThree, CorrectSmallerTest) {
    int aD = 1500, bD = 50000;
    Three a(aD), b(bD);
    auto eq = a <= b;
    auto neq = a > b;
    EXPECT_EQ(eq, true);
    EXPECT_EQ(neq, false);
}

TEST(TestThree, IncorrectSmallerTest) {
    int aD = 20000, bD = 500;
    Three a(aD), b(bD);
    auto eq = a <= b;
    auto neq = a > b;
    EXPECT_EQ(eq, false);
    EXPECT_EQ(neq, true);
}
