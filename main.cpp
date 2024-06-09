#include <iostream>

class Shape {
public:
    virtual void print() = 0;
    virtual double getSquare() = 0;
    virtual ~Shape() {}
};

class Square : public Shape {
protected:
    double length;
public:
    Square(double len) : length(len) {}

    void print() override {
        std::cout << "Square with side length " << length << std::endl;
    }

    double getSquare() override {
        return length * length;
    }
};

class Rectangle : public Square {
protected:
    double width;
public:
    Rectangle(double len, double wid) : Square(len), width(wid) {}

    void print() override {
        std::cout << "Rectangle with length " << length << " and width " << width << std::endl;
    }

    double getSquare() override {
        return length * width;
    }
};

class Circle : public Shape {
protected:
    int radius;
public:
    Circle(int rad) : radius(rad) {}

    void print() override {
        std::cout << "Circle with radius " << radius << std::endl;
    }

    double getSquare() override {
        return 3.14159 * radius * radius;
    }
};

class Triangle : public Shape {
protected:
    double side;
    double height;
public:
    Triangle(double s, double h) : side(s), height(h) {}

    void print() override {
        std::cout << "Triangle with side length " << side << " and height " << height << std::endl;
    }

    double getSquare() override {
        return 0.5 * side * height;
    }
};

int main() {
    Shape* shapes[] = { new Square(5), new Rectangle(4, 6), new Circle(3), new Triangle(4, 5) };

    for (auto shape : shapes) {
        shape->print();
        std::cout << "Area: " << shape->getSquare() << std::endl;
        delete shape;
    }

    return 0;
}
