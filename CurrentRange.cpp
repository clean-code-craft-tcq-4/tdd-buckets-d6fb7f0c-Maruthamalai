#include "CurrentRange.hpp"
#include "algorithm"
#include <iostream>

CurrentRange::CurrentRange() {}
CurrentRange::~CurrentRange() {}

void CurrentRange::startNewRange(t_rangeCalcParams &rangeCalcParams, tCinA rangeFirst)
{
    rangeCalcParams.start = rangeFirst;
    rangeCalcParams.end = 0;
    rangeCalcParams.count = 1;
}
void CurrentRange::endCurrentRange(t_rangeCalcParams &rangeCalcParams, tCinA rangeLast)
{
    rangeCalcParams.end = rangeLast;
    rangeInfo.push_back(rangeCalcParams);
}
void CurrentRange::printRange(vector<t_rangeInfo> &rangePtr)
{
    for (size_t i = 0; i < rangeInfo.size(); i++)
    {
        if (rangeInfo.at(i).count > 1)
        {
            cout << rangeInfo.at(i).start + "-" + to_string(rangeInfo.at(i).end) << endl;

            rangePtr.push_back({to_string(rangeInfo.at(i).start) + "-" + to_string(rangeInfo.at(i).end), rangeInfo.at(i).count});
        }
    }
}

t_currentRangeErrorCodes CurrentRange::getCurrentRanges(vector<tCinA> currentRange, vector<t_rangeInfo> &rangePtr)
{
    bool isNewRangeStart = true;
    size_t i = 0;
    t_rangeCalcParams rangeCalcParams = {0, 0, 0};

    sort(currentRange.begin(), currentRange.end());

    cout << "CurrRange size:" << currentRange.size() << endl;

    if (currentRange.size() < 2)
    {
        return E_NO_MIN_ELEMENTS;
    }

    for (i = 1; i < currentRange.size(); i++)
    {
        if (isNewRangeStart)
        {
            cout << "new range start:" << currentRange.size() << endl;
            isNewRangeStart = false;
            startNewRange(rangeCalcParams, currentRange.at(i-1));
        }

        if ((currentRange.at(i) - currentRange.at(i - 1)) <= RANGE_THRESHOLD)
        {
            cout << "CurrRange size:" << currentRange.size() << endl;
            rangeCalcParams.count++;
        }
        else
        {
            isNewRangeStart = true;
            endCurrentRange(rangeCalcParams, currentRange.at(i-1));
        }
    }

    if (isNewRangeStart == false)
    {
        endCurrentRange(rangeCalcParams, currentRange.at(i - 1));
    }
    printRange(rangePtr);

    return E_OK;
}
