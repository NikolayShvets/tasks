#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

int main()
{
    char buffer[255];
    cin.getline(buffer, 255);
    stack<char> brakets;
    for(short index = 0; index < strlen(buffer); index++)
    {
        if(buffer[index] == '(' || buffer[index] == '[' || buffer[index] == '{')
            brakets.push(buffer[index]);
        else if(buffer[index] == ')')
        {
            if(brakets.top() == '(')
            {
                brakets.pop();
            }
            else break;
        }
        else if(buffer[index] == ']')
        {
            if(brakets.top() == '[')
            {
                brakets.pop();
            }
            else break;
        }
        if(buffer[index] == '}')
        {
            if(brakets.top() == '{')
            {
                brakets.pop();
            }
            else break;
        }
    }
    if(brakets.empty())
        cout<<"True\n";
    else
        cout<<"False\n";
}
