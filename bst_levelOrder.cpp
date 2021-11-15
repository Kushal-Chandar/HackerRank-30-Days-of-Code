#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
class Solution
{
public:
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node *cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }
            return root;
        }
    }

    void levelOrder(Node *root)
    {
        //Write your code here
        queue<Node *> BFS;
        BFS.push(root);

        while (!BFS.empty())
        {
            Node *nodecurr = BFS.front();
            BFS.pop();

            cout << nodecurr->data << ' ';

            if (nodecurr->left != NULL)
            {
                BFS.push(nodecurr->left);
            }
            if (nodecurr->right != NULL)
            {
                BFS.push(nodecurr->right);
            }
        }
    }
    void inOrder(Node *root)
    {
        if (!root)
        {
            //? not root (!root) (root will have a pointer value(non - zer0) or NULL)
            //? if root has a value then it represents true but we use '!' which flips it to false(the body will not be executed)
            //? if root becomes NULL then it represents false but we use '!' which flips it to true(the body of if statement is executed)
            return;
        }
        inOrder(root->left);
        cout << root->data << ' ';
        inOrder(root->right);
    }

}; //End of Solution
int main()
{
    Solution myTree;
    Node *root = NULL;
    int T, data;
    cin >> T;
    while (T-- > 0)
    {
        cin >> data;
        root = myTree.insert(root, data);
    }
    myTree.levelOrder(root);
    return 0;
}