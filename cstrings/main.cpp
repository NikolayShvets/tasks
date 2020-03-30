#include <iostream>
#include <cstring>

using namespace std;

/*Задача: найти количество слов в строке. Слова могут быть разделены 
любым количеством любых симоволов
Вход: "&*%    I|love    !@#!@# you"
Выход: 3
*/

int main()
{
    char buffer[255]; //буфер строки
    short wordCounter{0};
    cin.getline(buffer,255);//считываем строку с защитой от переполнения
    /*переменные, задающие ОДЗ символов*/
    short a{static_cast<short>('a')},z{static_cast<short>('z')}, A{static_cast<short>('A')}, Z{static_cast<short>('Z')};
    bool binArray[strlen(buffer) + 1];//бинарный массив признаков принадлежности символов стоки ОДЗ размером равным длине строки вместе с терминирующим нулем
    for(short index = 0; index < sizeof (binArray) - 1; index++)//последний элемент всегда имеет код 0, его можно не проверять
    {
        short temp{static_cast<short>(buffer[index])};//берем код символа
        if(((temp >= a)&&(temp <= z) )||((temp >= A)&&(temp <=Z)))//если код символа принадлежит ОДЗ
            binArray[index] = true;
        else binArray[index] = false;
    }
    for(short index = 0; index < sizeof (binArray) - 1; index++)
    {
        if(binArray[index] == binArray[index + 1])//если соседние элементы равны
            binArray[index]=0;//обращаем одни из них в 0
        wordCounter+=binArray[index];//сложим элементы массива
    }
    std::cout<<wordCounter;
}

