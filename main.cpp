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
    double topLeftX;
    double topLeftY;
public:
    Square(double len, double x, double y) : length(len), topLeftX(x), topLeftY(y) {}

    void print() override {
        std::cout << "Square with side length " << length << " and top left corner at (" << topLeftX << ", " << topLeftY << ")" << std::endl;
    }

    double getSquare() override {
        return length * length;
    }
};

class Rectangle : public Shape {
protected:
    double length;
    double width;
    double topLeftX;
    double topLeftY;
public:
    Rectangle(double len, double wid, double x, double y) : length(len), width(wid), topLeftX(x), topLeftY(y) {}

    void print() override {
        std::cout << "Rectangle with length " << length << ", width " << width << " and top left corner at (" << topLeftX << ", " << topLeftY << ")" << std::endl;
    }

    double getSquare() override {
        return length * width;
    }
};

class Circle : public Shape {
protected:
    int radius;
    double centerX;
    double centerY;
public:
    Circle(int rad, double x, double y) : radius(rad), centerX(x), centerY(y) {}

    void print() override {
        std::cout << "Circle with radius " << radius << " and center at (" << centerX << ", " << centerY << ")" << std::endl;
    }

    double getSquare() override {
        return 3.14159 * radius * radius;
    }
};

class Triangle : public Shape {
protected:
    double side;
    double height;
    double point1X;
    double point1Y;
    double point2X;
    double point2Y;
    double point3X;
    double point3Y;
public:
    Triangle(double s, double h, double x1, double y1, double x2, double y2, double x3, double y3)
        : side(s), height(h), point1X(x1), point1Y(y1), point2X(x2), point2Y(y2), point3X(x3), point3Y(y3) {}

    void print() override {
        std::cout << "Triangle with side length " << side << ", height " << height << " and points at ("
            << point1X << ", " << point1Y << "), (" << point2X << ", " << point2Y << "), ("
            << point3X << ", " << point3Y << ")" << std::endl;
    }

    double getSquare() override {
        return 0.5 * side * height;
    }
};

int main() {
    Shape* shapes[] = {
        new Square(5, 0, 0),
        new Rectangle(4, 6, 0, 0),
        new Circle(3, 0, 0),
        new Triangle(4, 5, 0, 0, 0, 0, 0, 0)
    };

    for (auto shape : shapes) {
        shape->print();
        std::cout << "Area: " << shape->getSquare() << std::endl;
        delete shape;
    }

    return 0;
}
