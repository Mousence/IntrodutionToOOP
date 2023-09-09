#include "String.h"

/////////////////////////////////////////////////////////////////////////////////////////////
///////////           Определение класса - class definition                  ////////////////



int String::get_size() const {
    return size;
    }
const char* String::get_str() const {
    return str;
    }
char* String::get_str() {
    return str;
    }

// :: - Scope operator (оператор разрешения видимости)
 
//               Constructors:
// Ключевое слово explicit можно написать только внутри класса.
String::String(int size) :size(size), str(new char[size] {}) {
    //this->size = size;
    //this->str = new char[size] {};
    cout << "DefaultConstructor: " << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1) {
    //this->size = strlen(str)+1;
    //this->str = new char[size] {};
    for (int i = 0; str[i]; i++) this->str[i] = str[i];
    cout << "1ArgConstructor: " << this << endl;
}
String::String(const String& other) :String(other.str) {
    //this-> size = other.size;
    //this-> str = new char[size] {};
    //for(int i = 0; i < size; i++)
       //this->str[i] = other.str[i];
    cout << "CopyConstructor:\t" << this << endl;
}
String::String(String&& other) :size(other.size), str(other.str) {
    //this->size = other.size;
    //this->str = other.str;
    other.size = 0;
    other.str = nullptr;
    cout << "MoveConstructor:\t" << this << endl;
}
String::~String() {
    delete[] str;
    cout << "Destructor: " << this << endl;
}

//              operators:
char String::operator[](int i) const {
    if (i >= size) throw::out_of_range("error: out of range!!!\n");
    return str[i];
}
char& String::operator[](int i) {
    return str[i];
}

//type     name   (   parameters   )
String& String::operator=(const String& other) {
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
String& String::operator=(String&& other) {
    if (this == &other) return *this;
    this->size = other.size;
    this->str = other.str;
    other.size = 0;
    other.str = nullptr;
    cout << "MoveAssignment:\t" << this << endl;
}
String& String::operator+=(const String& other) {
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
//               Methods:
void String::print() const {
    cout << "Size:\t" << size << endl;
    cout << "Str:\t" << str << endl;
}

std::ostream& operator<<(std::ostream& os, const String& obj) {
    return os << obj.get_str();
}

String operator+(const String& left, const String& right) {
    String cat(left.get_size() + right.get_size() - 1);
    for (int i = 0; i < left.get_size(); i++) cat[i] = left[i];
    for (int i = 0; i < right.get_size(); i++) cat[left.get_size()-1+i] = right[i];
    return cat;
}


///////////           Конец определения класса - class definition end              //////////
/////////////////////////////////////////////////////////////////////////////////////////////