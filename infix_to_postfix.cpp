#include <bits/stdc++.h>
using namespace std;
bool isoperator(char c)
{
    return c == '+' || c == '*' || c == '/' || c == '-';
}
int precendence(char c)
{
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

string infixToPostfix(string s)
{
    stack<char> ss;
    string post = "";
    for (int i = 0; i < s.length(); ++i)
    {
    
        char ch=s[i];
        if(isdigit(ch))post+=ch;
        else if(ch=='(') ss.push(ch);
        else if(ch==')')
        {
            while(ss.top()!='('&&!ss.empty())
            {
                post+=ss.top();
                ss.pop();
            }
            ss.pop();
        }
        else if(isoperator(ch))
        {
            while(!ss.empty()&&ss.top()!='('&&precendence(ss.top())>=precendence(ch))
            {
                post+=ss.top();
                ss.pop();
            }
            ss.push(ch);
        }
    }
     while (!ss.empty()) {
        post+= ss.top();
        ss.pop();
    }
    
    return post;
}

int main()
{
    cout << "=== Infix to Postfix Conversion ===" << endl << endl;
    
    string expr1 = "2+3";
    string expr2 = "2+3*4";
    string expr3 = "(2+3)*4";
    string expr4 = "5+3*8-2";
    string expr5 = "(5+3)*(8-2)";
    string expr6 = "6/2-3+4*5";
    string expr7 = "((2+3)*4-5)/6";
    string expr8 = "2+3-4*5/6";
    
    cout << "Infix:    " << expr1 << endl;
    cout << "Postfix:  " << infixToPostfix(expr1) << endl << endl;
    
    cout << "Infix:    " << expr2 << endl;
    cout << "Postfix:  " << infixToPostfix(expr2) << endl << endl;
    
    cout << "Infix:    " << expr3 << endl;
    cout << "Postfix:  " << infixToPostfix(expr3) << endl << endl;
    
    cout << "Infix:    " << expr4 << endl;
    cout << "Postfix:  " << infixToPostfix(expr4) << endl << endl;
    
    cout << "Infix:    " << expr5 << endl;
    cout << "Postfix:  " << infixToPostfix(expr5) << endl << endl;
    
    cout << "Infix:    " << expr6 << endl;
    cout << "Postfix:  " << infixToPostfix(expr6) << endl << endl;
    
    cout << "Infix:    " << expr7 << endl;
    cout << "Postfix:  " << infixToPostfix(expr7) << endl << endl;
    
    cout << "Infix:    " << expr8 << endl;
    cout << "Postfix:  " << infixToPostfix(expr8) << endl << endl;
    
    cout << "Done!" << endl;
    
    return 0;
}