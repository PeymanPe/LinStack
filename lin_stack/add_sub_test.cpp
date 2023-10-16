#include "CppUTest/TestHarness.h"
#include "../lin_stack/includes/add_sub.h"

TEST_GROUP(AdditionTestGroup)
{
    void setup()
    {
    }
    void teardown()
    {
    }
};

TEST_GROUP(SUBTestGroup)
{
};

TEST(SUBTestGroup, Testsub1)
{
    int result = sub(5, 2);
    CHECK_EQUAL(3, result);
}

TEST(SUBTestGroup, Testsub2)
{
    int result = sub(5, 6);
    CHECK_EQUAL(-1, result);
}

TEST(AdditionTestGroup, TestAddition)
{
    int result = add(2, 3);
    CHECK_EQUAL(5, result);
}

TEST(AdditionTestGroup, TestAdditionWithNegativeNumbers)
{
    int result = add(-2, 3);
    CHECK_EQUAL(1, result);
}

TEST(AdditionTestGroup, TestAdditionWithZero)
{
    int result = add(0, 3);
    CHECK_EQUAL(3, result);
}