#include <iostream>

using namespace std;

class Point {
    double x;
    double y;
public:
    double get_x() const {
        return x;
    }
    double get_y() const {
        return y;
    }
    void set_x(double x) {
        this->x = x;
    }
    void set_y() {
        this->y = y;
    }

    //               constructors:

    Point() {
        x = y = double();
        cout << "DefaultConstructor:\t" << this << endl;
    }
    Point(double x) {
        this->x = x;
        this->y = double();
        cout << "1ArgConstructor:\t" << this << endl;
    }
    Point(double x, double y) {
        this->x = x;
        this->y = y;
        cout << "2ArgConstructor:\t" << this << endl;
    }
    ~Point() {
        cout << "Destructor:\t" << this << endl;
    }

    //              methods:

    double distance(Point& other) {
        return sqrt(pow(get_x() - other.get_x(), 2) + pow(get_y() - other.get_y(), 2));
    }
};

double distance(Point& FirstPoint, Point& SecondPoint) {
    return sqrt(pow(FirstPoint.get_x() - SecondPoint.get_x(), 2) + pow(FirstPoint.get_y() - SecondPoint.get_y(), 2));
}

int main()
{
    setlocale(LC_ALL, "");
    Point A(2, 3);
    Point B(5, 6);

    cout << "Растояние расстояние до указанной точки равно: " << A.distance(B) << endl;
    cout << "Растояние между двумя точками: " << distance(A, B) << endl;



}