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
        string in, even = "", odd = "";
        cin >> in;
        for (int i = 0; i < in.length(); i++)
        {
            if (i % 2 == 0)
            {
                even += in[i];
            }
            else
            {
                odd += in[i];
            }
        }
        cout << even << ' ' << odd << '\n';
    }

    return 0;
}
