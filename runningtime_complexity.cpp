#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        bool f = false;
        cin >> n;
        //? 1 is considered non prime
        if (n == 1)
        {
            cout << "Not prime\n";
            continue;
        }

        for (i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                f = true;
                break;
            }
        }
        cout << (f ? "Not prime" : "Prime") << '\n';
    }

    return 0;
}
