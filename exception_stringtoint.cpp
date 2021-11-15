#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;
    getline(cin, S);
    try
    {
        cout << stoi(S) << '\n';
    }
    catch (const std::exception &e)
    {
        cout << "Bad String\n";
    }

    return 0;
}
