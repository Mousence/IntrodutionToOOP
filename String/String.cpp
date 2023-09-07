#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class String {
    int size;
    char* str; //адрес строки в динам памяти
public:
    int get_size() const{
        return size;
    }
    const char* get_str() const {
        return str;
    }
     char* get_str() {
        return str;
    }

    //               Constructors:
    explicit String(int size = 80) {
        this->size = size;
        this->str = new char[size] {};
        cout << "DefaultConstructor: " << this << endl;
    }
    String(const char* str) {
        this->size = strlen(str)+1;
        this->str = new char[size] {};
        for (int i = 0; str[i]; i++) this->str[i] = str[i];
        cout << "1ArgConstructor: " << this << endl;
    }
    String(const String& other) {
        this-> size = other.size;
        this-> str = new char[size] {};
        for(int i = 0; i < size; i++)
            this->str[i] = other.str[i];
        cout << "CopyConstructor:\t" << this << endl;
    }
    String(String&& other) {
        this->size = other.size;
        this->str = other.str;
        other.size = 0;
        other.str = nullptr;
        cout << "MoveConstructor:\t" << this << endl;
    }
    ~String() {
        delete[] str;
        cout << "Destructor: " << this << endl;
    }
    
    //              operators:
    char operator[](int i) const {
        if (i >= size) throw::out_of_range("error: out of range!!!\n");
        return str[i];
    }
    char& operator[](int i) {
        return str[i];
    }

    String& operator=(const String& other) {
        if (this == &other)return *this;
        delete[] this->str;
        this->size = other.size;
        this->str = new char[size] {};
        for (int i = 0; i < size; i++) {
            this->str[i] = other.str[i];
        }
        cout << "CopyAssignment: " << this << endl;
        return *this;
    }
    String& operator=(String&& other) {
        if (this == &other) return *this;
        this->size = other.size;
        this->str = other.str;
        other.size = 0;
        other.str = nullptr;
        cout << "MoveAssignment:\t" << this << endl;
    }
    String& operator+=(const String& other) {
        int tempSize = this->get_size();
        this->size += other.get_size();
        char* newStr = new char[this->size + 1];
        for (int i = 0; i < tempSize; i++) {
            newStr[i] = this->get_str()[i];
        }
        for (int i = 0; i < other.get_size(); i++) {
            newStr[tempSize - 1 + i] = other.get_str()[i];
        }
        delete[] this->str;
        this->str = newStr;
        return *this;
    }

    /*
    String operator+(const String& other) const {
        int str_length = this->get_size() + other.get_size() - 1;
        String new_str = new char[str_length + 1];
        for (int i = 0; i < this->get_size(); i++) {
            new_str.str[i] = this->get_str()[i];
        }
        for (int i = 0; i < other.get_size(); i++) {
            new_str.str[this->get_size() - 1 + i] = other.get_str()[i];
        }
        return new_str;
    }
    */
    //               Methods:
    void print() const {
        cout << "Size:\t" << size << endl;
        cout << "Str:\t" << str << endl;
    }
};

std::ostream& operator<<(std::ostream& os, const String& obj) {
    return os << obj.get_str();
}

String operator+(const String& left, const String& right) {
    String cat(left.get_size() + right.get_size() - 1);
    for (int i = 0; i < left.get_size(); i++) cat[i] = left[i];
    for (int i = 0; i < right.get_size(); i++) cat[left.get_size()-1+i] = right[i];
    return cat;
}

int main()
{
    setlocale(LC_ALL, "");
    String str1 = "Hello";
    String str2 = "World";
    str1 += str2;
    cout << str1 << endl;

}
