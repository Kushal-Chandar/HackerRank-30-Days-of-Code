#include <iostream>
#include <list>
using namespace std;

//? Need to use list implementation as the size of the queue is not provided
class Solution
{
private:
    list<char> stack;
    list<char> queue;

public:
    //stack
    void pushCharacter(char);
    char popCharacter();
    //queue
    void enqueueCharacter(char);
    char dequeueCharacter();
};

void Solution::pushCharacter(char a)
{
    stack.push_back(a);
}
char Solution::popCharacter()
{
    char ret = stack.back();
    stack.pop_back();
    return ret;
}

void Solution::enqueueCharacter(char a)
{
    queue.push_back(a);
}
char Solution::dequeueCharacter()
{
    char ret = queue.front();
    queue.pop_front();
    return ret;
}

int main()
{
    // read the string s.
    string s;
    getline(cin, s);

    // create the Solution class object p.
    Solution obj;

    // push/enqueue all the characters of string s to stack.
    //? The below part is return to save space and time
    int len_half = s.length() / 2;
    for (int i = 0; i < len_half; i++)
    {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i + len_half + 1]);
    }

    bool isPalindrome = true;

    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for (int i = 0; i < s.length() / 2; i++)
    {
        if (obj.popCharacter() != obj.dequeueCharacter())
        {
            isPalindrome = false;
            break;
        }
    }

    // finally print whether string s is palindrome or not.
    if (isPalindrome)
    {
        cout << "The word, " << s << ", is a palindrome.";
    }
    else
    {
        cout << "The word, " << s << ", is not a palindrome.";
    }

    return 0;
}