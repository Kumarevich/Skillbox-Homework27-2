#include <iostream>
#include <cmath>
#include <cassert>

struct  point
{
    double x = 0;
    double y = 0;
};

enum colors
{
    NONE,
    RED,
    BLUE,
    GREEN
};

class Figure
{
    point center;
    colors color = NONE;

public:
    double area = 0;
    double areaAround = 0;

    void message()
    {
        std::cout << "Area of your figure: " << area << std::endl;
        std::cout << "Area of the around rectangle: " << areaAround << std::endl;
    }

    void setCenter(point centerPoint)
    {
        center.x = centerPoint.x;
        center.y = centerPoint.y;
    }

    void setColor(colors colorSetter)
    {
         color = colorSetter;
    }

    void area_around (double a, double b)
    {
        areaAround = a * b;
    }
};

class Circle: public Figure
{
    double radius = 0;

    void areaCircle (double r)
    {
        const double PI = acos(-1.0);
        area = (PI * pow(r, 2));
    }

public:
    Circle(double inRadius, point inCenter, colors inColor): radius(inRadius)
    {
        assert(inRadius > 0);
        setCenter(inCenter);
        setColor(inColor);
        areaCircle(radius);
        area_around(2 * radius, 2 * radius);
        message();
    }
};

class Square: public Figure
{
    double length = 0;

    void areaSquare(double l)
    {
        area = pow(l, 2);
    }

public:
    Square(double inLength, point inCenter, colors inColor): length(inLength)
    {
        assert(inLength > 0);
        setCenter(inCenter);
        setColor(inColor);
        areaSquare(length);
        area_around(length + 1, length);
        message();
    }
};

class Triangle: public Figure
{
    double length = 0;

    void areaTriangle(double l)
    {
        area = pow(l, 2) * sqrt(3) / 4;
    }

public:
    Triangle(double inLength, point inCenter, colors inColor): length(inLength)
    {
        assert(inLength > 0);
        setCenter(inCenter);
        setColor(inColor);
        areaTriangle(length);
        area_around(length + 1, length);
        message();
    }
};

class Rectangle: public  Figure
{
    double height = 0;
    double width = 0;

    void areaRectangle(double a, double b)
    {
        area = a * b;
    }

public:
    Rectangle(double inHeight, double inWidth, point inCenter, colors inColor)
                                            : height(inHeight), width(inWidth)
    {
        assert(inHeight > 0 && inWidth > 0);
        setCenter(inCenter);
        setColor(inColor);
        areaRectangle(height, width);
        area_around(height + 1, width + 1);
        message();
    }
};

int main() {
    point centerTemp = {0, 0};
    colors colorTemp = NONE;
    std::string colorTempString = "none";
    std::string figure = "";

    std::cout << "Input center coordinates (x, y): ";
    std::cin >> centerTemp.x >> centerTemp.y;
    std::cout << "Input figure color: ";
    std::cin >> colorTempString;
    if (colorTempString == "red") colorTemp = RED;
    else if (colorTempString == "blue") colorTemp = BLUE;
    else if (colorTempString == "green") colorTemp = GREEN;
    else colorTemp = NONE;

    std::cout << "Input the figure name: ";
    std::cin >> figure;
    if (figure == "circle") {
        double radius;
        std::cout << "Input the radius: ";
        std::cin >> radius;
        Circle* circle = new Circle(radius, centerTemp,colorTemp);
        delete circle;
        circle = nullptr;
    } else if (figure == "square") {
        double length;
        std::cout << "Input the side length: ";
        std::cin >> length;
        Square* square = new Square(length, centerTemp, colorTemp);
        delete square;
        square = nullptr;
    } else if (figure == "triangle") {
        double length;
        std::cout << "Input the side length: ";
        std::cin >> length;
        Triangle* triangle = new Triangle(length, centerTemp, colorTemp);
        delete triangle;
        triangle = nullptr;
    } else if (figure == "rectangle") {
        double length, width;
        std::cout << "Input side A and side B: ";
        std::cin >> length >> width;
        Rectangle* rectangle = new Rectangle(length, width, centerTemp, colorTemp);
        delete rectangle;
        rectangle = nullptr;
    } else if (figure != "exit") {
        std::cout << "Wrong input." << std::endl;
    }
    return 0;
}
