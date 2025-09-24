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
	Point(int x, int y) : x(x), y(y) {} // ����������� � ����������� (���������������� ������
	Point() : Point(0, 0) {} // ����������� �� ���������, ������������ �����������
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
    Point Multi(Point& b){
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

	Point operator+(Point& b) {
		return Point(x + b.x, y + b.y);
	}
	Point operator-(Point& b) {
		return Point(x - b.x, y - b.y);
	}
	Point operator*(Point& b) {
		return Point(x * b.x, y * b.y);
	}
	Point operator/(Point& b) {
		return Point(x / b.x, y / b.y);
	}
	Point operator+(int val) {
		return Point(x + val, y + val);
	}
	Point operator-(int val) {
		return Point(x - val, y - val);
	}
	Point operator*(int val) {
		return Point(x * val, y * val);
	}
	Point operator/(int val) {
		return Point(x / val, y / val);
	}


    bool operator>(Point& obj) {
        if (*this > obj) {
            return true;
        }
        return false;
    }
	bool operator<(Point& obj) {
		if (*this < obj) {
			return true;
		}
		return false;
	}
	bool operator!=(Point& obj) {
		if (x != obj.x || y != obj.y) {
			return true;
		}
		return false;

	}
	bool operator==(Point& obj) {
		if (x == obj.x && y == obj.y) {
			return true;
		}
		return false;
	}
	bool operator>=(Point& obj) {
        if (x >= obj.x && y >= obj.y) {
            return true;
        }
		return false;
	}
    bool operator!(){
        if (x >= 0 && y >= 0) {
            return false;
        }
		return true;
    }

    Point& operator++() {
        x++;
        y++;
        return *this;
    }
    Point operator--() {
        x--;
        y--;
        return *this;
    }
    Point operator++(int){
		Point temp(x, y);
		x++;
		y++;
		return temp;
    }
	Point operator--(int) {
		Point temp(x, y);
        x--;
        y--;
		return temp;
    }

};

int main()

{
 //   Point a; // ������ ������!!!
 //   a.Init('A', 4, 5);
 //   a.Print();
 //   /*a = a.AddX(10);
 //   a.Print()*/;
 //   Point b;
 //   b.Init('B', 1, 2);
 //   Point rez = a.Sum(b);
 //   rez.Print();
 //   //Point c;
 //   //c.Init('C', 5, 1);
 //   //c.Print();
 //   //Point k;
 //   //k.Init('K', 1, 0);
 //   //k.Print();
 //   //Point rez1 = c.Subtraction(k);
 //   //rez1.Print();

 //   Point sum = a.Sum(b);
	//Point sum2 = a + b; // ���������� ��������� +
	//sum = a - b; // ���������� ��������� -
	//sum = a * b; // ���������� ��������� *
	//sum = a / b; // ���������� ��������� /

 //   Point sum = a + 10;
	//sum = a - 10;
	//sum = a * 10;
	//sum = a / 10;
	//sum.Print();

	Point a(4, 15), b(2, 5), c(1, 1);
    //logical operations
	if (a > b) cout << "a > b" << endl;
	if (a < b) cout << "a < b" << endl;
	if (a == c) cout << "a == c" << endl;
    //----------------------------------------------------------------------
    //overloading of unary operations
	Point d = ++a; // d = a.operator++();
    a.Print();
	d.Print();

	Point d1 = a++; // d1 = a.operator++(int);
    
    
}
