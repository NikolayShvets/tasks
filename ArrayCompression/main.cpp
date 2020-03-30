#include <iostream>
#include <vector>
#include <string>

/*на вход дан массив целых чисел.
массив необходимо отсротировать и
вывести строку диапазонов
вход: {3,2,1,5,6,-1,10}
ыход: "-1, 1 - 3, 5 - 6, 10"
*/

using namespace std;

int main()
{
    vector<int> inputVector{3, 2, 1, 5, 6, -1, 10};
    bool isSorted{false};
    while(!isSorted){
        isSorted = true;
        for(int i = inputVector.size() - 1; i > 0; i--){
            if(inputVector.at(i) > inputVector.at(i-1)){
                inputVector.at(i) ^= inputVector.at(i-1);
                inputVector.at(i-1) ^= inputVector.at(i);
                inputVector.at(i) ^= inputVector.at(i-1);
                isSorted = false;
            }
        }
    }
    for(const auto &elem : inputVector){
        cout<<elem<<" ";
    }
    string outputStr{""};
    bool isRight{false}, isLeft{false};
    for(int i = inputVector.size() - 1; i > 0; i--){
        if(abs(inputVector.at(i) - inputVector.at(i - 1)) == 1)
        {
            if(isRight)
                continue;
            isRight = true;
            isLeft = false;
            outputStr += to_string(inputVector.at(i)) + " - ";
        }
        else
        {
            isLeft = true;
            isRight = false;
            outputStr += to_string(inputVector.at(i)) + ", ";
        }
    }
    outputStr += to_string(inputVector.at(0));
    cout<<"\n"<<outputStr<<"\n";
}
