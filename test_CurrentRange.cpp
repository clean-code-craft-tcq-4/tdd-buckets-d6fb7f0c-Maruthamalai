#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "CurrentRange.hpp"

TEST_CASE("RangeCheck") {
    CurrentRange testCurrentRange;
    vector <tCinA> currentRange = {4,5};
    vector <t_rangeInfo> rangeInfo;

    REQUIRE(testCurrentRange.getCurrentRanges(currentRange, rangeInfo) == E_OK);
    REQUIRE(rangeInfo.at(0).range.compare("4-5") == 0);
    REQUIRE(rangeInfo.at(0).rangeCount == 2);
}

TEST_CASE("RangeCheck2") {
    CurrentRange testCurrentRange;
    vector <tCinA> currentRange = {4,5,7,9,7,7,8};
    vector <t_rangeInfo> rangeInfo;

    REQUIRE(testCurrentRange.getCurrentRanges(currentRange, rangeInfo) == E_OK);
    REQUIRE(rangeInfo.at(0).range.compare("4-5") == 0);
    REQUIRE(rangeInfo.at(0).rangeCount == 2);
    REQUIRE(rangeInfo.at(1).range.compare("7-9") == 0);
    REQUIRE(rangeInfo.at(1).rangeCount == 5);
}

TEST_CASE("InvalidRangeCheck") {
    CurrentRange testCurrentRange;
    vector <tCinA> currentRange = {4};
    vector <t_rangeInfo> rangeInfo;

    REQUIRE(testCurrentRange.getCurrentRanges(currentRange, rangeInfo) == E_NO_MIN_ELEMENTS);
}