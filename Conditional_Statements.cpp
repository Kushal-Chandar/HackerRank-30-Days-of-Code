#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int main()
{
    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    //between this range, even numbers need to print weird and odd numbers need to print weird.(so we can use ||)
    /*
    if (N & 1 || (N >= 6 && N <= 20)) 
    {
        cout << "Weird\n";
    }
    else
    {
        cout << "Not Weird\n";
    }
    */
    cout << (N & 1 || (N >= 6 && N <= 20) ? "Weird" : "Not Weird");

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
