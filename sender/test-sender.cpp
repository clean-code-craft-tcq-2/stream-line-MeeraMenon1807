#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "../test/catch.hpp"
#include "sender.h"

SCENARIO("check random integer is generated within a given range")
{
    GIVEN("an upper limit and lower limit")
    {
        int upper = 10;
        int lower = 1;

        WHEN("getRandomIntegerInRange() is called with the lower and upper limit")
        {
            int randomInteger = getRandomIntegerInRange(lower, upper);
            THEN("a random integer between the range is returned")
            {
                REQUIRE(randomInteger <= upper);
                REQUIRE(randomInteger >= lower);
            }
        }
    }
}

SCENARIO("check array of random integers is generated within a given range and size")
{
    GIVEN("an upper limit and lower limit and and array of size")
    {
        int upper = 10;
        int lower = 1;
        int size = 10;
        int *arr = (int *)malloc(size * sizeof(int));

        WHEN("setArrayWithValuesInRange() is called with the lower limit, upper limit, size and array")
        {
            setArrayWithValuesInRange(lower, upper, size, arr);
            THEN("array is set with random integers within in given range")
            {
                for (int i = 0; i < size; i++)
                {
                    REQUIRE(arr[i] <= upper);
                    REQUIRE(arr[i] >= lower);

                    free(arr);
                }
            }
        }
    }
}

TEST_CASE("check generateAndPrintDataToConsole() does not throw")
{
    REQUIRE_NOTHROW(generateAndPrintDataToConsole());
}
