#include <iostream>
using namespace std;

class Shape {
   protected:
      double width, height;

   public:
      // konstruktor	
      Shape(int a = 0, int b = 0) { 
         width = a;
         height = b;
      }

      // funkcja czysto wirtualna
      virtual double getArea() = 0;

	friend ostream& operator<<(ostream& os, Shape& shape) {
		return os << "Field is: " << shape.getArea();
	}
};

class Square : public Shape
{
public:
	Square(int a) : Shape(a, a) {}
	virtual ~Square() {}
	
	virtual double getArea() {
		return this->width * this->height;
	}

};


int main(){
    Square t(10);
    cout << t << endl;
}
