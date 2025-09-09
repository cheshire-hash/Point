#include<iostream>

using namespace std;

class Point // �������� ���� !!

{

private: // ����������, ��������� �������, �������� ����� �������

    char name;
    int x;
    int y;

public: //��������� �������, ��������� ����� ��� �������!! �������

    void Init(char name, int _x, int  _y)
    {
        this->name = name;
        this->x = _x;
        this->y = _y;
    }

    void Print()
    {
        cout << name << " X: " << x << "\tY: " << y << endl;
    }

    Point& AddX(int _x)
    {
        this->x += _x; // this-> x  - ��������� � ����� �������, ����� ��������� �� ������ this
        return *this; // ���������� ������, ��� �������� ��� ������ ����� AddX.
    }

    Point Sum(Point& b) // a.Sum(b)
    {

        Point rez;
        rez.name = 'T';
        rez.x = this->x + b.x;
        rez.y = this->y + b.y;
        return rez;
    }

    Point Subtraction(Point& b) {
        Point rez;
        rez.name = 'T';
        rez.x = this->x - b.x;
        rez.y = this->y - b.y;
        return rez;
    }
    Point Multiplication(Point& b){
        Point rez;
        rez.name = 'T';
        rez.x = this->x * b.x;
        rez.y = this->y * b.y;
        return rez;
    }
    Point Division(Point& b) {
        Point rez;
        rez.name = 'T';
        rez.x = this->x / b.x;
        rez.y = this->y / b.y;
        return rez;
    }


};

int main()

{
    Point a; // ������ ������!!!
    a.Init('A', 4, 5);
    a.Print();
    /*a = a.AddX(10);
    a.Print()*/;
    Point b;
    b.Init('B', 1, 2);
    Point rez = a.Sum(b);
    rez.Print();
    Point c;
    a.Init('C', 4, 1);
    Point rez1 = c.Multiplication(a);


}
