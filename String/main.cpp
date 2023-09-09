#include "String.h"

int main()
{
    setlocale(LC_ALL, "");
    String str1 = "Hello";
    String str2 = "World";
    str1 = str2;
    cout << str1 << endl;
}