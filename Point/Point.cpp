#include<iostream>
using namespace std;

class Point // создание типа !!

{
private: // реализация, состояние объекта, закрытая часть объекта

    char name;
    int x;
    int y;

public: //интерфейс объекта, доступная часть для клиента!! функции

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
	Point(int x, int y) : x(x), y(y) {} // Конструктор с параметрами (инициализирующий список
	Point() : Point(0, 0) {} // Конструктор по умолчанию, делегирующий конструктор
    Point& AddX(int _x)
    {
        this->x += _x; // this-> x  - обращение к члену объекта, через указатель на объект this
        return *this; // Возвращаем объект, для которого был вызван метод AddX.
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

};

int main()

{
    Point a; // объект класса!!!
    a.Init('A', 4, 5);
    a.Print();
    /*a = a.AddX(10);
    a.Print()*/;
    Point b;
    b.Init('B', 1, 2);
    Point rez = a.Sum(b);
    rez.Print();
    //Point c;
    //c.Init('C', 5, 1);
    //c.Print();
    //Point k;
    //k.Init('K', 1, 0);
    //k.Print();
    //Point rez1 = c.Subtraction(k);
    //rez1.Print();

    Point sum = a.Sum(b);
	Point sum2 = a + b; // перегрузка оператора +
	sum = a - b; // перегрузка оператора -
	sum = a * b; // перегрузка оператора *
	sum = a / b; // перегрузка оператора /

}
