#include <iostream>
#include <string>
#include <map>

using namespace std;

string press(const string &str);

int main()
{
    string str;
    cout<<"Input a string: \n";
    cin>>str;
    cout<<press(str);
}

string press(const string &str){
    map<char, int> chMap;
    string pressRes{""};
    int counter{1};
    for(const auto &ch : str){
        if(chMap.count(ch) == 0){
            counter = 1;
        }
        chMap[ch] = counter;
        ++counter;
    }
    for(const auto &elem: chMap){
        pressRes += elem.first;
        if(elem.second > 1)
            pressRes += to_string(elem.second);
    }
    return pressRes;
}
