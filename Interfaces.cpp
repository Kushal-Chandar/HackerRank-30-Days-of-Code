#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class AdvancedArithmetic
{
public:
    virtual int divisorSum(int n) = 0;
};
class Calculator : public AdvancedArithmetic
{
public:
    int divisorSum(int n)
    {
        vector<int> divisors;
        if (n != 1)
        {
            divisors.push_back(n);
        }
        divisors.push_back(1);
        int sum = 0;
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                divisors.push_back(i);
                if (i != n / i)
                {
                    divisors.push_back((n / i));
                }
            }
        }
        //? The same logic we used for a number being prime (we find its first divisor)
        //? but now we iterate through the entire loop it get all divisors
        for (int i = 0; i < divisors.size(); i++)
        {
            sum += divisors[i];
        }

        return sum;
    }
};

int main()
{
    int n;
    cin >> n;
    AdvancedArithmetic *myCalculator = new Calculator();
    int sum = myCalculator->divisorSum(n);
    cout << "I implemented: AdvancedArithmetic\n"
         << sum;
    return 0;
}