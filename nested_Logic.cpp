#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Date
{
private:
    short int day;
    short int month;
    short int year;
    friend int fineCal(Date &, Date &);

public:
    Date();
};

Date::Date()
{
    cin >> day >> month >> year;
}
int fineCal(Date &a, Date &b)
{
    if (a.year >= b.year)
    {
        if (a.year == b.year)
        {
            if (a.month >= b.month)
            {
                if (a.month == b.month)
                {
                    if (a.day >= b.day)
                    {
                        if (a.day == b.day)
                        {
                            return 0;
                        }
                        return 15 * (a.day - b.day);
                    }
                    return 0;
                }
                return 500 * (a.month - b.month);
            }
            return 0;
        }
        return 10000;
    }
    return 0;
}

int main()
{
    Date returned;
    Date expected;
    cout << fineCal(returned, expected) << '\n';
    return 0;
}
