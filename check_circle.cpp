#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node *prev;

    Node(int n)
    {
        value = n;

        next = nullptr;
        prev = nullptr;
    }
};
void traverse(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->value << "->";
        temp = temp->next;
    }
    cout << endl;
}
int circular(Node *head)
{
    Node *slw = head;
    Node *fast = head;
    while (slw && fast&&fast->next)
    {
        if (fast->next != nullptr)
        {
            fast = fast->next->next;
        }
        slw=slw->next;
        if(fast==slw)return 1;
    }
    return 0;
}
int main()
{

    int n;
    cin >> n;
    int k = n;
    Node *temp = nullptr;
    Node *pre = nullptr;
    Node *tail = nullptr;
    Node *head = nullptr;
    while (n)
    {
        int a;
        cin >> a;
        n--;
        temp = new Node(a);
        if (n == k - 1)
        {
            head = temp;
            tail = head;
            temp->prev = nullptr;
        }
        else // Use else to ensure pre exists before calling pre->next
        {
            pre->next = temp;
            temp->prev = pre;
        }

        if (!n)
        {
          //  temp->next = head->next->next;
            tail = temp;

            // temp->next = nullptr;
        }
        pre = temp;
    }

    // traverse(head);
    if (circular(head))
        cout << "yeah circle" << endl;
    else
        cout << "No circle" << endl;
}
