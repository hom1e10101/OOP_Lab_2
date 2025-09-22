#include <gtest/gtest.h>

#include "Three.h"


TEST(TestThree, BasicConv) {
    int aD = 10;
    Three a(aD);
    Three ansa({1, 0, 1});
    EXPECT_TRUE(eq(a, ansa));

    int bD = 3;
    Three b(bD);
    Three ansb({1, 0});
    EXPECT_TRUE(eq(b, ansb));
}

TEST(TestThree, BasicAdding) {
    int aD = 10, bD = 2;
    Three a(aD), b(bD);
    auto res = Three(add(a, b));
    auto ans = Three(aD + bD);
    EXPECT_TRUE(eq(res, ans));
}

TEST(TestThree, LargeAdding) {
    int aD = 1500, bD = 50000;
    Three a(aD), b(bD);
    auto res = add(a, b);
    auto ans = Three(aD + bD);
    EXPECT_TRUE(eq(res, ans));
}


TEST(TestThree, BasicSublime) {
    int aD = 10, bD = 2;
    Three a(aD), b(bD);
    auto res = sub(a, b);
    auto ans = Three(aD - bD);
    EXPECT_TRUE(eq(res, ans));
}

TEST(TestThree, LargeSublime) {
    int aD = 500000, bD = 1500;
    Three a(aD), b(bD);
    auto res = sub(a, b);
    auto ans = Three(aD - bD);
    EXPECT_TRUE(eq(res, ans));
}

TEST(TestThree, WrongSublime) {
    int aD = 0, bD = 1500;
    Three a(aD), b(bD);
    auto res = sub(a, b);
    auto ans = Three(aD - bD);
    EXPECT_TRUE(eq(res, ans));
}

TEST(TestThree, CorrectEquals) {
    int aD = 500000, bD = 500000;
    Three a(aD), b(bD);
    auto e = eq(a, b);
    auto neq = noteq(a, b);
    EXPECT_TRUE(e);
    EXPECT_FALSE(neq);
}

TEST(TestThree, IncorrectEquals) {
    int aD = 500000, bD = 50000;
    Three a(aD), b(bD);
    auto e = eq(a, b);
    auto neq = noteq(a, b);
    EXPECT_FALSE(e);
    EXPECT_TRUE(neq);
}


TEST(TestThree, CorrectLargerTest) {
    int aD = 500000, bD = 50000;
    Three a(aD), b(bD);
    auto e = bigger_or_eq(a,b);
    auto neq = less(a, b);
    EXPECT_TRUE(e);
    EXPECT_FALSE(neq);
}

TEST(TestThree, IncorrectLargerTest) {
    int aD = 1000, bD = 50000;
    Three a(aD), b(bD);
    auto e = bigger_or_eq(a,b);
    auto neq = less(a, b);
    EXPECT_FALSE(e);
    EXPECT_TRUE(neq);
}

TEST(TestThree, CorrectSmallerTest) {
    int aD = 1500, bD = 50000;
    Three a(aD), b(bD);
    auto e = less_or_eq(a, b);
    auto neq = bigger(a, b);
    EXPECT_TRUE(e);
    EXPECT_FALSE(neq);
}

TEST(TestThree, IncorrectSmallerTest) {
    int aD = 20000, bD = 500;
    Three a(aD), b(bD);
    auto e = less_or_eq(a, b);
    auto neq = bigger(a, b);
    EXPECT_FALSE(e);
    EXPECT_TRUE(neq);
}
