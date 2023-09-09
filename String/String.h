#pragma once

#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////
///////////           ќбъ€вление класса - class decloration                  ////////////////

class String {
    int size;
    char* str; //адрес строки в динам пам€ти
public:
    int get_size() const;
    const char* get_str() const;
    char* get_str();

    //               Constructors:
    explicit String(int size = 80);
    String(const char* str);
    String(const String& other);
    String(String&& other);
    ~String();

    //              operators:
    char operator[](int i) const;
    char& operator[](int i);

    String& operator=(const String& other);
    String& operator=(String&& other);
    String& operator+=(const String& other);

    //               Methods:
    void print() const;
};
std::ostream& operator<<(std::ostream& os, const String& obj);
String operator+(const String& left, const String& right);

///////////           ќбъ€вление класса - class decloration end              ////////////////
/////////////////////////////////////////////////////////////////////////////////////////////