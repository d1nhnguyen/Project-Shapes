#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const float pi = 3.14;
const int Max = 100;

enum Type {
    SQUARE,
    RECTANGLE,
    CIRCLE
};

struct Square {
    float side;
    float area;
    float perimeter;

    float calculateArea() const {
        return side * side;
    }

    float calculatePerimeter() const {
        return 4 * side;
    }
};

struct Rectangle {
    float width;
    float height;
    float area;
    float perimeter;

    float calculateArea() const {
        return width * height;
    }

    float calculatePerimeter() const {
        return 2 * (width + height);
    }
};

struct Circle {
    float radius;
    float area;
    float perimeter;

    float calculateArea() const {
        return pi * radius * radius;
    }

    float calculatePerimeter() const {
        return 2 * pi * radius;
    }
};

void* returnShapes(string s, Type& type);

void print(const Square* value);

void print(const Rectangle* value);

void print(const Circle* value);

void print(void* value, Type types);

void output(void* shapes[], Type* types, int n);

float returnArea(void* value, Type type);

int maxAreaIndex(void* shapes[], Type* types, int n);

int minAreaIndex(void* shapes[], Type* types, int n);

float returnPerimeter(void* value, Type type);

int maxPerimeterIndex(void* shapes[], Type* types, int n);

int minPerimeterIndex(void* shapes[], Type* types, int n);

void printAreaOnly(void* value, Type type);

void printPerimeterOnly(void* value, Type type);

void countShapes(int& countSquare, int& countRectangle, int& countCircle, Type* types, int n);
