#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int n;
    string query;
    cin >> n;
    map<string, int> mp;
    while (n--)
    {
        string key;
        int value;
        cin >> key >> value;
        mp.insert(make_pair(key, value));
    }
    while (cin >> query)
    {
        if (mp.find(query) == mp.end())
        {
            cout << "Not found\n";
        }
        else
        {
            cout << query << "=" << mp[query] << '\n';
        }
    }

    return 0;
}