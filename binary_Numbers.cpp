#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    list<int> binary;
    while (n != 0)
    {
        int rem = n % 2;
        n /= 2;
        binary.push_front(rem);
    }
    //? Intuitive Understanding?
    // lets take 29 and convert it into binary: fill this binary array -> [][][][][]
    // 29 % 2 = 1 -> [][][][][1]; 29/2 = 14; [][][][]||[1] //left shift >> 1
    //? binary number divide by 2(to divide a binary number by 2 we can >> shift the array)
    // 14 % 2 = 0 -> [][][][0]; 14/2 = 7; [][][]||[0][1] //left shift binary number >> 1
    // 7 % 2 = 1 -> [][][1]; 7/2 = 3; [][]||[1][0][1] //left shift binary >> 1
    // 3 % 2 = 1 -> [][1]; 3/2 = 1; []||[1][1][0][1] // left shift >> 1
    // 1 % 2 = 1 -> [1]; 1/2 = 0; ||[1][1][1][0][1]// left shift >> 1
    //? we left shifted 5 times now we will right shift 5 times to get the number
    //[1][1][1][0][1]||

    //? What are we working with?
    //todo: when we are given a decimal we can check if it divisible by 2 (even or odd)
    // binary number -> base 2 ->  32 16 8 4 2 1
    // if the remainder is 1 we know the number is odd and 1th place of the binary is filled with 1
    // if the remainder is 0 it will be with 0
    //? we check remainder fill it in 1th place of binary number
    //? we can divide the number by 2 -> decimal/2 , binary >> 1
    //? we have a new number to check for the remainder and a new 1th place to fill
    // we can keep repeating the process until the given number becomes 0
    // and now if we right shift the number the amount of time it was left shifted we get our binary form of given decimal number

    int max_len_1 = 0;
    int count = 0;
    for (auto &&i : binary)
    {
        if (i == 1)
        {
            count++;
        }
        else
        {
            max_len_1 = count > max_len_1 ? count : max_len_1;
            count = 0;
        }
    }
    if (count > max_len_1)
    {
        max_len_1 = count;
    }

    cout << max_len_1 << '\n';

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
