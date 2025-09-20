#include <gtest/gtest.h>

#include "Three.h"


TEST(TestThree, BasicConv) {
    int aD = 10;
    Three a(aD);
    Three ansa({1, 0, 1});
    a.print();
    ansa.print();
    EXPECT_EQ(eq(a, ansa), true);

    int bD = 3;
    Three b(bD);
    Three ansb({1, 0});

    EXPECT_EQ(eq(b, ansb), true);
}

TEST(TestThree, BasicAdding) {
    int aD = 10, bD = 2;
    Three a(aD), b(bD);
    auto res = add(a, b);
    auto ans = Three(aD + bD);
    EXPECT_EQ(eq(res, ans), true);
}

TEST(TestThree, LargeAdding) {
    int aD = 1500, bD = 50000;
    Three a(aD), b(bD);
    auto res = add(a, b);
    auto ans = Three(aD + bD);
    EXPECT_EQ(eq(res, ans), true);
}


TEST(TestThree, BasicSublime) {
    int aD = 10, bD = 2;
    Three a(aD), b(bD);
    auto res = sub(a, b);
    auto ans = Three(aD - bD);
    EXPECT_EQ(eq(res, ans), true);
}

TEST(TestThree, LargeSublime) {
    int aD = 500000, bD = 1500;
    Three a(aD), b(bD);
    auto res = sub(a, b);
    auto ans = Three(aD - bD);
    EXPECT_EQ(eq(res, ans), true);
}

TEST(TestThree, WrongSublime) {
    int aD = 0, bD = 1500;
    Three a(aD), b(bD);
    auto res = sub(a, b);
    auto ans = Three(aD - bD);
    EXPECT_EQ(eq(res, ans), true);
}

TEST(TestThree, CorrectEquals) {
    int aD = 500000, bD = 500000;
    Three a(aD), b(bD);
    auto e = eq(a, b);
    auto neq = noteq(a, b);
    EXPECT_EQ(e, true);
    EXPECT_EQ(neq, false);
}

TEST(TestThree, IncorrectEquals) {
    int aD = 500000, bD = 50000;
    Three a(aD), b(bD);
    auto e = eq(a, b);
    auto neq = noteq(a, b);
    EXPECT_EQ(e, false);
    EXPECT_EQ(neq, true);
}


TEST(TestThree, CorrectLargerTest) {
    int aD = 500000, bD = 50000;
    Three a(aD), b(bD);
    auto e = bigger_or_eq(a,b);
    auto neq = less(a, b);
    EXPECT_EQ(e, true);
    EXPECT_EQ(neq, false);
}

TEST(TestThree, IncorrectLargerTest) {
    int aD = 1000, bD = 50000;
    Three a(aD), b(bD);
    auto e = bigger_or_eq(a,b);
    auto neq = less(a, b);
    EXPECT_EQ(e, false);
    EXPECT_EQ(neq, true);
}

TEST(TestThree, CorrectSmallerTest) {
    int aD = 1500, bD = 50000;
    Three a(aD), b(bD);
    auto e = less_or_eq(a, b);
    auto neq = bigger(a, b);
    EXPECT_EQ(e, true);
    EXPECT_EQ(neq, false);
}

TEST(TestThree, IncorrectSmallerTest) {
    int aD = 20000, bD = 500;
    Three a(aD), b(bD);
    auto e = less_or_eq(a, b);
    auto neq = bigger(a, b);
    EXPECT_EQ(e, false);
    EXPECT_EQ(neq, true);
}
