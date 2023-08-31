#include <iostream>
using namespace std;

class Fraction {
    int integer;
    int numerator;
    int denominator;
public:
    int get_integer()const {
        return integer;
    }
    int get_numerator()const {
        return numerator;
    }
    int get_denominator()const {
        return denominator;
    }

    void set_integer(int integer) {
        this->integer = integer;
    }
    void set_numerator(int numerator) {
        this->numerator = numerator;
    }
    void set_denominator(int denominator) {
        if (denominator == 0)denominator = 1;
        this->denominator = denominator;
    }

    //          Constructors:
    Fraction() {
        this->integer = 0;
        this->numerator = 0;
        this->denominator = 1;
        cout << "DefaultContructor:\t" << this << endl;
    }
    Fraction(int integer) {
        this->integer = 0;
        this->numerator = 0;
        set_denominator(denominator);
        cout << "1ArgContructor:\t" << this << endl;
    }
    Fraction(int integer, int numerator) {
        this->integer = 0;
        this->numerator = numerator;
        set_denominator(denominator);
        cout << "2ArgContructor:\t" << this << endl;
    }
    Fraction(int integer, int numerator, int denominator) {
        this->integer = integer;
        this->numerator = numerator;
        this->denominator = denominator;
        cout << "Contructor:\t" << this << endl;
    }

    Fraction(const Fraction& other) {
        this->integer = other.integer;
        this->numerator = other.numerator;
        this->denominator = other.denominator;
        cout << "CopyContructor:\t" << this << endl;
    }

    ~Fraction() {
        cout << "Destructor:\t" << this << endl;
    }
    //          Operators:
    Fraction& operator=(const Fraction& other) {
        this->integer = other.integer;
        this->numerator = other.numerator;
        this->denominator = other.denominator;
        cout << "CopyAssignment:\t" << this << endl;
        return *this;
    }

    //          Methods:
    void to_improper() {
        numerator += integer * denominator;
        integer = 0;
    }
    void to_proper() {
        integer += integer * numerator;
        numerator %= denominator;
    }
    void print()const {
        if (integer) cout << integer;
        if (numerator) {
            if (integer) cout << "(";
            cout << numerator << "/" << denominator;
            if (integer)cout << ")";
        }
        else if (integer == 0) cout << 0;
        cout << endl;
    }
};

Fraction& operator*(Fraction& left, Fraction& right) {
    left.to_improper();
    right.to_improper();
    Fraction result;
    result.set_numerator(left.get_numerator() * right.get_numerator());
    result.set_denominator(left.get_denominator() * right.get_denominator());
    return result;
}
Fraction& operator+=(Fraction& left, Fraction& right) {
    left.to_improper();
    right.to_improper();
    Fraction result;
    result.set_numerator(left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator());
    result.set_denominator(left.get_denominator() * right.get_denominator());
    return result;
}
Fraction& operator-=(Fraction& left, Fraction& right) {
    left.to_improper();
    right.to_improper();
    Fraction result;
    result.set_numerator(left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator());
    result.set_denominator(left.get_denominator() * right.get_denominator());
    return result;
}
Fraction& operator*=(Fraction& left, Fraction& right) {
    left.to_improper();
    right.to_improper();
    Fraction result;
    result.set_numerator(left.get_numerator() * right.get_numerator());
    result.set_denominator(left.get_denominator() * right.get_denominator());
    return result;
}
Fraction& operator/=(Fraction& left, Fraction& right) {
    left.to_improper();
    right.to_improper();
    Fraction result;
    result.set_numerator(left.get_numerator() * right.get_denominator());
    result.set_denominator(left.get_denominator() * right.get_numerator());
    return result;
}

#define CONSTRUCTORS_CHECK 

int main()
{
    setlocale(LC_ALL, "");

    Fraction A(2, 3, 4);

    Fraction B(3, 4, 5);
    B.print();

    A/=B;
    A.print();


}
