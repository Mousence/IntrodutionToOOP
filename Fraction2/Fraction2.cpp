#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);
std::ostream& operator<<(std::ostream& os, const Fraction& obj);
std::istream& operator>>(std::istream& is, Fraction& obj);

class Fraction
{
	int integer;		//Целая часть
	int numerator;		//Числитель
	int denominator;	//Знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	void set_values(int integer, int numerator, int denominator) {
		this->integer = integer;
		this->numerator = numerator;
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//				Constructors:
	Fraction() {
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstruct:\t" << this << endl;
	}
	Fraction(int integer){
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator) {
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
	}
	Fraction(int integer, int numerator, int denominator){
	this->integer = integer;
	this->numerator = numerator;
	set_denominator(denominator);
	cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other){
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction(){
		cout << "Destructor:\t" << this << endl;
	}

	//					Operators:
	Fraction& operator=(const Fraction& other){
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	Fraction& operator*=(const Fraction& other){
		return *this = *this * other;
	}
	Fraction& operator/=(const Fraction& other){
		return *this = *this / other;
	}
	Fraction& operator+=(const Fraction& other) {
		(*this).to_improper();
		Fraction otherCopy = other;
		otherCopy.to_improper();
		(*this).set_numerator((*this).get_numerator() * otherCopy.get_denominator() + otherCopy.get_numerator() * (*this).get_denominator());
		(*this).set_denominator((*this).get_denominator() * otherCopy.get_denominator());
		return *this;
	}
	Fraction& operator-=(const Fraction& other) {
		(*this).to_improper();
		Fraction otherCopy = other;
		otherCopy.to_improper();
		(*this).set_numerator((*this).get_numerator() * otherCopy.get_denominator() - otherCopy.get_numerator() * (*this).get_denominator());
		(*this).set_denominator((*this).get_denominator() * otherCopy.get_denominator());
		return *this;
	}

	//					Increment/Decrement:
	Fraction& operator++(){
		integer++;
		return *this;
	}
	Fraction operator++(int){
		Fraction old = *this;
		integer++;
		return old;
	}

	//					Methos:
	Fraction& to_improper(){
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper() {
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()const{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	Fraction& reduce(){
		if (numerator == 0)return *this;
		int more, less, rest;
		if (numerator > denominator)more = numerator, less = denominator;
		else less = numerator, more = denominator;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
	void print()const{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
};

Fraction operator*(Fraction left, Fraction right){
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator/(const Fraction& left, const Fraction& right){
	return left * right.inverted();
}

bool operator==(Fraction left, Fraction right){
	left.to_improper();
	right.to_improper();
	/*if (left.get_numerator()*right.get_denominator() == right.get_numerator()*left.get_denominator())
		return true;
	else
		return false;*/
	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
}
bool operator!=(const Fraction& left, const Fraction& right){
	return !(left == right);
}
bool operator>(Fraction left, Fraction right){
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() > right.get_numerator() * left.get_denominator();
}
bool operator<(Fraction left, Fraction right){
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() < right.get_numerator() * left.get_denominator();
}
bool operator>=(const Fraction& left, const Fraction& right){
	return !(left < right);
}
bool operator<=(const Fraction& left, const Fraction& right){
	return !(left > right);
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj){
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}
std::istream& operator>>(std::istream& is, Fraction& obj){
	const int SIZE = 256;
	char sz_buffer[SIZE]{};
	is >> sz_buffer;
	int number[3]{}; int n = 0;
	char delimiters[] = "()/";
	for (char* pch = strtok(sz_buffer, delimiters); pch; pch = strtok(NULL, delimiters)) {
		number[n++] = std::atoi(pch); // atoi() - означает ascii-string to integer.
	}
	switch (n) {
	case 1: obj = Fraction(number[0]);
		break;
	case 2: obj = Fraction(number[0], number[1]);
		break;
	case 3: obj = Fraction(number[0], number[1], number[2]);
		break;
	}
    return is;
}

void main()
{
	setlocale(LC_ALL, "");

	Fraction A(2,3,4);
	cout << "Введите простую дробь: ";
	cin >> A;
	cout << A << endl;
}
