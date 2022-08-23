#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "CurrentRange.hpp"

TEST_CASE("Cooling status email alert normal") {
    vector <int> currentRange = {4,5};
    CurrentRange testCurrentRange(currentRange);

    REQUIRE(testCurrentRange.getCurrentRanges().at(0).range.compare("4-5") == 0);
    REQUIRE(testCurrentRange.getCurrentRanges().at(0).rangeCount == 2);
}