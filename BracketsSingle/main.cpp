#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char buffer[255];//буффер ввода строки
    short bracketsCodesSummator{0};//сумма кодов скобок в строке (код '(' = 40, код ')' = 41)
    cin.getline(buffer, 255);
    for(short index = 0; index < strlen(buffer); index++)
    {
        if(buffer[index] == '(' || buffer[index]==')')//нашли скобку - прибавили ее код в сумматор
            bracketsCodesSummator += static_cast<short>(buffer[index]);
    }
    if(bracketsCodesSummator - 41 * strlen(buffer)/2 == 40*strlen(buffer)/2)
        cout<<"True\n";
    else cout<<"False\n";
}
