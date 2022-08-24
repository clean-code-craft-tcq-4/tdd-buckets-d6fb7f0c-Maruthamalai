#include <vector>
#include <string>
using namespace std;

#define RANGE_THRESHOLD 1

typedef int tCinA;      //Current in Amps - integer values
typedef enum
{
    E_OK,
    E_NO_MIN_ELEMENTS,
    E_INVALID_RANGE
}t_currentRangeErrorCodes;

typedef struct
{
    string range;
    unsigned short rangeCount;
}t_rangeInfo;


typedef struct 
{
    tCinA start;
    tCinA end;
    unsigned short count;
}t_rangeCalcParams;

class CurrentRange
{
    private:
    vector <t_rangeCalcParams> rangeInfo;

    void startNewRange(t_rangeCalcParams& rangeCalcParams, tCinA rangeFirst);
    void endCurrentRange(t_rangeCalcParams& rangeCalcParams, tCinA rangeLast);
    void printRange(vector <t_rangeInfo>& rangePtr);

    public:
    CurrentRange();
    ~CurrentRange();
    t_currentRangeErrorCodes getCurrentRanges(vector <tCinA> currentRange, vector <t_rangeInfo>& rangePtr);
};