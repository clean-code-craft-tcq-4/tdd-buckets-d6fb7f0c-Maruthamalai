#include <vector>
#include <string>
using namespace std;

typedef struct
{
    string range;
    unsigned short rangeCount;
}rangeInfo;

class CurrentRange
{
    private:
    vector <int> currentRange;

    public:
    CurrentRange();
    CurrentRange(vector <int> rangeInfo);
    ~CurrentRange();
    void SetCurrentRange(vector <int> rangeInfo);
    vector <rangeInfo> getCurrentRanges();
}