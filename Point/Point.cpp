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
	int GetX() {
		return x;
	}
	void SetX(int _x) {
		x = _x;
	}
	int GetY() {
		return y;
	}
	void SetY(int _y) {
		y = _y;
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
		return (x > obj.x) && (y > obj.y);
	}
	bool operator<(Point& obj) {
		return (x < obj.x) && (y < obj.y);
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

 //   Point& operator++() {
 //       x++;
 //       y++;
 //       return *this;
 //   }
 //   Point operator--() {
 //       x--;
 //       y--;
 //       return *this;
 //   }
 //   Point operator++(int){
	//	Point temp(x, y);
	//	x++;
	//	y++;
	//	return temp;
 //   }
	//Point operator--(int) {
	//	Point temp(x, y);
 //       x--;
 //       y--;
	//	return temp;
 //   }
  /*  Point& operator+=(int a) {
        x += a;
        y += a;
		return *this;
    }
    Point& operator-=(int a) {
		x -= a;
        y -= a;
        return *this;
    }
	Point& operator*=(int a) {
		x *= a;
		y *= a;
		return *this;
	}*/
	Point& operator/=(int a) {
		x /= a;
		y /= a;
		return *this;
	}
	Point& operator%=(int a) {
		x %= a;
		y %= a;
		return *this;
	}

};

Point operator+(int a, Point& b) {
	Point rez(a + b.GetX(), a + b.GetY());
	return rez;
}
Point operator-(int a, Point& b) {
	Point rez(a - b.GetX(), a - b.GetY());
	return rez;
}
Point operator++(Point& obj) {
	obj.SetX(obj.GetX() + 1);
	obj.SetY(obj.GetY() + 1);
	return obj;
}
Point operator++(Point& obj, int) {
	Point temp(obj.GetX(), obj.GetY());
	obj.SetX(obj.GetX() + 1);
	obj.SetY(obj.GetY() + 1);
	return temp;
}
Point operator--(Point& obj) {
	obj.SetX(obj.GetX() - 1);
	obj.SetY(obj.GetY() - 1);
	return obj;
}
Point operator--(Point& obj, int) {
	Point temp(obj.GetX(), obj.GetY());
	obj.SetX(obj.GetX() - 1);
	obj.SetY(obj.GetY() - 1);
	return temp;

}
Point operator-=(Point& obj1, Point& ob2) {
	obj1.SetX(obj1.GetX() - ob2.GetX());
	obj1.SetY(obj1.GetY() - ob2.GetY());
	return obj1;
}
Point operator+=(Point& obj1, Point& ob2) {
	obj1.SetX(obj1.GetX() + ob2.GetX());
	obj1.SetY(obj1.GetY() + ob2.GetY());
	return obj1;
}
Point operator*=(Point& obj1, Point& ob2) {
	obj1.SetX(obj1.GetX() * ob2.GetX());
	obj1.SetY(obj1.GetY() * ob2.GetY());
	return obj1;
}

int main()

{
 //   Point a; // объект класса!!!
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
	//Point sum2 = a + b; // перегрузка оператора +
	//sum = a - b; // перегрузка оператора -
	//sum = a * b; // перегрузка оператора *
	//sum = a / b; // перегрузка оператора /

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
	//Point d = ++a; // d = a.operator++();
 //   a.Print();
	//d.Print();

	Point a2(1, 2), b2(2, 3), c2(0, 0);
	Point d1 = a++; // d1 = a.operator++(int);
	c2 = 10 + b;
	a2 *= b;
	c2 = a2 -= b2;
	b2 += a2;
	b2.Print();
    
}
