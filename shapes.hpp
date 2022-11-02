#pragma once

#include <SFML/Graphics.hpp>

class Shape : public sf::ConvexShape
{
private:
    sf::Vector2f speed;

public:
    Shape();
    void setSpeed(sf::Vector2f _speed);
    void setSpeed(float _x, float _y);
    sf::Vector2f getSpeed(void);
    virtual void move(sf::Vector2i win, sf::Vector2f offset);
    virtual void move(int winX, int winY, float offsetX, float offsetY);
    virtual void move(sf::Vector2i win, float offsetX, float offsetY);
    virtual void move(int winX, int winY, sf::Vector2f offset);
    void rotate(float ang);
};

class Ellipse : public Shape
{
private:
    sf::Vector2f radius;
    const int pointCount = 90;
    void updatePoints(void);
    void setPointCount();
    void setPoint();

public:
    Ellipse(sf::Vector2f _radius);
    Ellipse(float _radiusX, float _radiusY);
    Ellipse();
    void setRadius(sf::Vector2f _radius);
    void setRadius(float _radiusX, float _radiusY);
    sf::Vector2f getRadius(void);
    void move(sf::Vector2i win, sf::Vector2f offset);
};

class Circle : public Shape
{
private:
    float radius;
    const int pointCount = 90;
    void updatePoints(void);
    void setPointCount();
    void setPoint();

public:
    Circle(float _radius = 40);
    void setRadius(float _radius);
    float getRadius(void);
    void move(sf::Vector2i win, sf::Vector2f offset);
};

class Point : public Circle
{
private:
    void setRadius(float _r);
    void setPointCount();
    void setPoint();

public:
    Point();
    float getRadius(void);
    void move(sf::Vector2i win, sf::Vector2f offset);
};

class Triangle : public Shape
{
private:
    float side;
    void updatePoints();
    void setPointCount();
    void setPoint();

public:
    Triangle(float _side);
    Triangle();
    void setSide(float _side);
    float getSide(void);
    void move(sf::Vector2i win, sf::Vector2f offset);
};

class Rectangle : public Shape
{
private:
    sf::Vector2f size;
    void updatePoints();
    void setPointCount();
    void setPoint();

public:
    Rectangle(sf::Vector2f _size);
    Rectangle(float _w, float _h);
    Rectangle();
    void setSize(sf::Vector2f _size);
    void setSize(float _w, float _h);
    sf::Vector2f getSize(void);
    void move(sf::Vector2i win, sf::Vector2f offset);
};

class Line : public Shape
{
private:
    float length;
    float thickness;
    void updatePoints();
    void setPointCount();
    void setPoint();

public:
    Line(float _length, float _thickness);
    Line(float _length);
    Line();
    void setLength(float _length);
    float getLength(void);
    void setThickness(float _thickness);
    float getThickness(void);
    void move(sf::Vector2i win, sf::Vector2f offset);
};

class Rhombus : public Shape
{
private:
    sf::Vector2f size;
    void updatePoints();
    void setPointCount();
    void setPoint();

public:
    Rhombus(sf::Vector2f _size);
    Rhombus(float _w, float _h);
    Rhombus();
    void setSize(sf::Vector2f _size);
    void setSize(float _w, float _h);
    sf::Vector2f getSize(void);
    void move(sf::Vector2i win, sf::Vector2f offset);
};