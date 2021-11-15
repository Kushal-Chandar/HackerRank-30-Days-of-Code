#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main()
{
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";

    // Declare second integer, double, and String variables.
    int i1;
    double d2;
    string s2;
    cin >> i1 >> d2;
    cin.ignore();
    getline(cin, s2);

    cout << i + i1 << '\n'
         << fixed << setprecision(1) << d + d2 << '\n'
         << s + s2 << '\n';

    // Read and save an integer, double, and String to your variables.
    // Note: If you have trouble reading the entire string, please go back and review the Tutorial closely.

    // Print the sum of both integer variables on a new line.

    // Print the sum of the double variables on a new line.

    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.

    return 0;
}