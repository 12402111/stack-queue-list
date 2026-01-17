#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int val;
    node *next;
    node(int n)
    {
        val = n;
    }
};
class stacky
{
public:
    node *top;
    int size;

    stacky()
    {
        top = nullptr;
        size = 0;
    }

    void push(int n)
    {
        node *newnode = new node(n);
        newnode->next = top;
        top = newnode;
        size++;
    }
    bool isempty()
    {
        if (!top)
            return true;
        return false;
    }
    int pop()
    {
        if (!isempty())
        {
            node *tem = top;
            int valn = top->val;
            top = top->next;
            delete tem;
            size--;
            return valn;
        }
        cout << "error: stack is empty" << endl;
        return -1;
    }
    int peek()
    {
        if (!isempty())
        {
            return top->val;
        }
        cout << "empty" << endl;
        return -1;
    }
    void print()
    {
        if (!isempty())
        {
            node *temp = top;
            while (temp)
            {
                cout << temp->val << "->";
                temp = temp->next;
            }
            cout << endl;
            return;
        }
        cout << "Faka mama" << endl;
        return;
    }
    void check(string s)
    {
        int i = 0;
        while (s[i] != '\0')
        {
            if (s[i] == '(')
                push(10);
            else if (s[i] == '{')
                push(20);
            else if (s[i] == '[')
                push(30);

            else if (s[i] == ')')
            {
                if (peek() != 10)
                {
                    cout << "Not valid" << endl;
                    return;
                }
                    pop();
            }
              else if (s[i] == '}')
            {
                if (peek() != 20)
                {
                    cout << "Not valid" << endl;
                    return;
                }
                    pop();
            }
              else if (s[i] == ']')
            {
                if (peek() != 30)
                {
                    cout << "Not valid" << endl;
                    return;
                }
                    pop();
            }
            i++;
        }
        if (isempty())
            cout << "valid" << endl;
        else
            cout << "not valid" << endl;
        return;
    }
};

int main()
{
    cout << "=== Linked List-Based Stack Demo ===" << endl;

    stacky stack;
    stack.check("([](){(})");

    /*  // Test 1: Push elements
      cout << "1. Pushing elements: 10, 20, 30, 40, 50" << endl;
      stack.push(10);
      stack.push(20);
      stack.push(30);
      stack.push(40);
      stack.push(50);
      stack.print();
      cout << "   Size: " << stack.size << endl;

      // Test 2: Peek
      cout << "\n2. Peek at top element:" << endl;
      cout << "   Top: " << stack.peek() << endl;

      // Test 3: Pop elements
      cout << "\n3. Pop 2 elements:" << endl;
      cout << "   Popped: " << stack.pop() << endl;
      cout << "   Popped: " << stack.pop() << endl;
      stack.print();

      // Test 4: Push more
      cout << "\n4. Push 60 and 70:" << endl;
      stack.push(60);
      stack.push(70);
      stack.print();

      // Test 5: Stack info
      cout << "\n5. Stack info:" << endl;
      cout << "   Is empty? " << (stack.isempty() ? "Yes" : "No") << endl;
      cout << "   Size: " << stack.size << endl;

      // Test 6: Pop all elements
      cout << "\n6. Pop all elements:" << endl;
      while (!stack.isempty())
      {
          cout << "   Popped: " << stack.pop() << endl;
      }
      stack.print();

      // Test 7: Error handling
      cout << "\n7. Try to pop from empty stack:" << endl;
      stack.pop();
      stack.peek();

      // Test 8: Push after emptying
      cout << "\n8. Push 100 after emptying:" << endl;
      stack.push(100);
      stack.print();

      cout << "\nDone!" << endl;*/

    return 0;
}
