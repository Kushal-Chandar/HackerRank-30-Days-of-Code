#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
class Solution
{
public:
    Node *removeDuplicates(Node *head)
    {
        //Write your code here
        //? according to constraints we are given a sorted list
        /*   
        if (!head)
        {
            return head;
        }

        Node *temp = head;

        while (temp->next)
        {
            while (temp->next && (temp->data != temp->next->data))
            {
                temp = temp->next;
            }
            cout << "ran\n";
            while (temp->next && (temp->data == temp->next->data))
            {
                cout << "ran1\n";
                Node *t = temp->next;
                temp->next = t->next;
                delete t;
            }
            //? Had a lot of Segmentation faults
            // mistake both inner while loops could access temp->next even if it was NULL
            // solution -> make it so that each while loop checks if temp->next is NULL for each iteration
        }
        return head;
        */
        //better sol
        if (!head)
        {
            return head;
        }
        Node *temp = head;
        while (temp->next)
        {
            if (temp->data == temp->next->data)
            {
                Node *t = temp->next;
                temp->next = t->next;
                delete t;
            }
            else
            {
                temp = temp->next;
            }
        }
        return head;
    }

    Node *insert(Node *head, int data) //inserting at tail
    {
        Node *p = new Node(data);
        if (head == NULL)
        {
            head = p;
        }
        else if (head->next == NULL)
        {
            head->next = p;
        }
        else
        {
            Node *start = head;
            while (start->next != NULL)
            {
                start = start->next;
            }
            start->next = p;
        }
        return head;
    }
    void display(Node *head)
    {
        Node *start = head;
        while (start)
        {
            cout << start->data << " ";
            start = start->next;
        }
    }
};

int main()
{
    Node *head = NULL;
    Solution mylist;
    int T, data;
    cin >> T;
    while (T-- > 0)
    {
        cin >> data;
        head = mylist.insert(head, data);
    }
    head = mylist.removeDuplicates(head);

    mylist.display(head);
}