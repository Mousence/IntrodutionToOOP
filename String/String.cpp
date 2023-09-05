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
            this->str[i] = other.size;
    }
    ~String() {
        delete[] str;
        cout << "Destructor: " << this << endl;
    }
    
    //              operators:

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
    //               Methods:
    void print() const {
        cout << "Size:\t" << size << endl;
        cout << "Str:\t" << str << endl;
    }
};

std::ostream& operator<<(std::ostream& os, const String& obj) {
    return os << obj.get_str();
}

int main()
{
    setlocale(LC_ALL, "");
    String str1 = "Hello";
    String str2 = "World";
    String str3 = str1 + str2;
    cout << str3 << endl;

}