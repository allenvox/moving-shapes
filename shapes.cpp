#include "shapes.hpp"
#include <cmath>
#include <SFML/Graphics/ConvexShape.hpp>

// shape
Shape::Shape() : sf::ConvexShape()
{
    speed.x = 0;
    speed.y = 0;
}
void Shape::setSpeed(sf::Vector2f _speed)
{
    speed = _speed;
}
void Shape::setSpeed(float _x, float _y)
{
    setSpeed(sf::Vector2f(_x, _y));
}
sf::Vector2f Shape::getSpeed(void)
{
    return speed;
}
void Shape::move(sf::Vector2i win, sf::Vector2f offset)
{
    setFillColor(sf::Color::Black);
}

void Shape::move(int winX, int winY, float offsetX, float offsetY)
{
    move(sf::Vector2i(winX, winY), sf::Vector2f(offsetX, offsetY));
}
void Shape::move(sf::Vector2i win, float offsetX, float offsetY)
{
    move(win, sf::Vector2f(offsetX, offsetY));
}
void Shape::move(int winX, int winY, sf::Vector2f offset)
{
    move(sf::Vector2i(winX, winY), offset);
}

void Shape::rotate(float _ang)
{
    setRotation(getRotation() + _ang);
}

// ellipse
Ellipse::Ellipse(sf::Vector2f _radius) : Shape()
{
    setRadius(_radius);
}

Ellipse::Ellipse(float _radiusX, float _radiusY) : Shape()
{
    setRadius(_radiusX, _radiusY);
}

Ellipse::Ellipse() : Shape()
{
    setRadius(50, 15);
}

void Ellipse::updatePoints()
{
    if (getPointCount() != pointCount)
        Shape::setPointCount(pointCount);

    float rad, x, y;
    for (int i = 0; i < pointCount; i++)
    {
        rad = (360 / pointCount * i) / (360 / M_PI / 2);
        x = cos(rad) * radius.x;
        y = sin(rad) * radius.y;
        Shape::setPoint(i, sf::Vector2f(x, y));
    }
}

void Ellipse::setRadius(sf::Vector2f _radius)
{
    radius.x = (_radius.x) ? _radius.x : 0;
    radius.y = (_radius.y) ? _radius.y : 0;

    updatePoints();
}

void Ellipse::setRadius(float _radiusX, float _radiusY)
{
    setRadius(sf::Vector2f(_radiusX, _radiusY));
}

sf::Vector2f Ellipse::getRadius(void)
{
    return radius;
}

void Ellipse::move(sf::Vector2i win, sf::Vector2f offset)
{
    setFillColor(sf::Color::Red);
    setPosition(getPosition() + offset);
    sf::FloatRect bound = getGlobalBounds();
    if (bound.left + bound.width > win.x || bound.left < 0)
    {
        setSpeed(getSpeed().x * (-1), getSpeed().y);
        offset.x *= -1;
        offset.y = 0;
    }
    if (bound.top + bound.height > win.y || bound.top < 0)
    {
        setSpeed(getSpeed().x, getSpeed().y * (-1));
        offset.y *= -1;
        offset.x = 0;
    }
}

// circle
Circle::Circle(float _radius) : Shape()
{
    setRadius(_radius);
}

void Circle::updatePoints()
{
    if (getPointCount() != pointCount)
        Shape::setPointCount(pointCount);

    float rad, x, y;
    for (int i = 0; i < pointCount; i++)
    {
        rad = (360 / pointCount * i) / (360 / M_PI / 2);
        x = cos(rad) * radius;
        y = sin(rad) * radius;
        Shape::setPoint(i, sf::Vector2f(x, y));
    }
}

void Circle::setRadius(float _radius)
{
    radius = (_radius) ? _radius : 0;
    updatePoints();
}

float Circle::getRadius(void)
{
    return radius;
}

void Circle::move(sf::Vector2i win, sf::Vector2f offset)
{
    setFillColor(sf::Color::Yellow);
    setPosition(getPosition() + offset);
    sf::FloatRect bound = getGlobalBounds();
    if (bound.left + bound.width > win.x || bound.left < 0)
    {
        setSpeed(getSpeed().x * (-1), getSpeed().y);
        offset.x *= -1;
        offset.y = 0;
    }
    if (bound.top + bound.height > win.y || bound.top < 0)
    {
        setSpeed(getSpeed().x, getSpeed().y * (-1));
        offset.y *= -1;
        offset.x = 0;
    }
}

// point
Point::Point() : Circle()
{
    Circle::setRadius(10);
}

float Point::getRadius()
{
    return 10;
}

void Point::move(sf::Vector2i win, sf::Vector2f offset)
{
    setFillColor(sf::Color::Magenta);
    setPosition(getPosition() + offset);
    sf::FloatRect bound = getGlobalBounds();
    if (bound.left + bound.width > win.x || bound.left < 0)
    {
        setSpeed(getSpeed().x * (-1), getSpeed().y);
        offset.x *= -1;
        offset.y = 0;
    }
    if (bound.top + bound.height > win.y || bound.top < 0)
    {
        setSpeed(getSpeed().x, getSpeed().y * (-1));
        offset.y *= -1;
        offset.x = 0;
    }
}

// triangle
Triangle::Triangle(float _side) : Shape()
{
    setSide(_side);
}

Triangle::Triangle() : Shape()
{
    setSide(40);
    setOrigin(getSide() / 2, getSide() / 2);
}

void Triangle::updatePoints()
{
    if (getPointCount() != 3)
        Shape::setPointCount(3);
    Shape::setPoint(0, sf::Vector2f(0, side));
    Shape::setPoint(1, sf::Vector2f(side / 2, 0));
    Shape::setPoint(2, sf::Vector2f(side, side));
}

void Triangle::setSide(float _side)
{
    side = (_side) ? _side : 0;
    updatePoints();
}

float Triangle::getSide(void)
{
    return side;
}

void Triangle::move(sf::Vector2i win, sf::Vector2f offset)
{
    setFillColor(sf::Color::Green);
    setPosition(getPosition() + offset);
    sf::FloatRect bound = getGlobalBounds();
    if (bound.left + bound.width > win.x || bound.left < 0)
    {
        setSpeed(getSpeed().x * (-1), getSpeed().y);
        offset.x *= -1;
        offset.y = 0;
    }
    if (bound.top + bound.height > win.y || bound.top < 0)
    {
        setSpeed(getSpeed().x, getSpeed().y * (-1));
        offset.y *= -1;
        offset.x = 0;
    }
}

// rectangle
Rectangle::Rectangle(sf::Vector2f _size) : Shape()
{
    setSize(_size);
}

Rectangle::Rectangle(float _w, float _h) : Shape()
{
    setSize(_w, _h);
}

Rectangle::Rectangle() : Shape()
{
    setSize(60, 40);
    setOrigin(getSize().x / 2, getSize().y / 2);
}

void Rectangle::updatePoints()
{
    if (getPointCount() != 4)
        Shape::setPointCount(4);
    Shape::setPoint(0, sf::Vector2f(0, 0));
    Shape::setPoint(1, sf::Vector2f(size.x, 0));
    Shape::setPoint(2, sf::Vector2f(size.x, size.y));
    Shape::setPoint(3, sf::Vector2f(0, size.y));
}

void Rectangle::setSize(sf::Vector2f _size)
{
    size.x = (_size.x) ? _size.x : 0;
    size.y = (_size.y) ? _size.y : 0;

    updatePoints();
}

void Rectangle::setSize(float _w, float _h)
{
    size.x = (_w) ? _w : 0;
    size.y = (_h) ? _h : 0;

    updatePoints();
}

sf::Vector2f Rectangle::getSize(void)
{
    return size;
}

void Rectangle::move(sf::Vector2i win, sf::Vector2f offset)
{
    setFillColor(sf::Color::Blue);
    setPosition(getPosition() + offset);
    sf::FloatRect bound = getGlobalBounds();
    if (bound.left + bound.width > win.x || bound.left < 0)
    {
        setSpeed(getSpeed().x * (-1), getSpeed().y);
        offset.x *= -1;
        offset.y = 0;
    }
    if (bound.top + bound.height > win.y || bound.top < 0)
    {
        setSpeed(getSpeed().x, getSpeed().y * (-1));
        offset.y *= -1;
        offset.x = 0;
    }
}

// line
Line::Line(float _length, float _thickness) : Shape()
{
    length = (_length) ? _length : 0;
    thickness = (_thickness) ? _thickness : 0;
    updatePoints();
}

Line::Line(float _l) : Shape()
{
    length = (_l) ? _l : 0;
    thickness = 3;
    updatePoints();
}

Line::Line() : Shape()
{
    length = 30;
    thickness = 5;
    setOrigin(getLength() / 2, getThickness() / 2);
    updatePoints();
}

void Line::updatePoints()
{
    if (getPointCount() != 4)
        Shape::setPointCount(4);
    Shape::setPoint(0, sf::Vector2f(0, 0));
    Shape::setPoint(1, sf::Vector2f(length, 0));
    Shape::setPoint(2, sf::Vector2f(length, thickness));
    Shape::setPoint(3, sf::Vector2f(0, thickness));
}

void Line::setLength(float _l)
{
    length = (_l) ? _l : 0;
    updatePoints();
}

float Line::getLength(void)
{
    return length;
}

void Line::setThickness(float _thickness)
{
    thickness = (_thickness) ? _thickness : 0;
    updatePoints();
}

float Line::getThickness(void)
{
    return thickness;
}

void Line::move(sf::Vector2i win, sf::Vector2f offset)
{
    setFillColor(sf::Color::Cyan);
    setPosition(getPosition() + offset);
    sf::FloatRect bound = getGlobalBounds();
    if (bound.left + bound.width > win.x || bound.left < 0)
    {
        setSpeed(getSpeed().x * (-1), getSpeed().y);
        offset.x *= -1;
        offset.y = 0;
    }
    if (bound.top + bound.height > win.y || bound.top < 0)
    {
        setSpeed(getSpeed().x, getSpeed().y * (-1));
        offset.y *= -1;
        offset.x = 0;
    }
}

// rhombus
Rhombus::Rhombus(sf::Vector2f _size) : Shape()
{
    setSize(_size);
}

Rhombus::Rhombus(float _w, float _h) : Shape()
{
    setSize(_w, _h);
}

Rhombus::Rhombus() : Shape()
{
    setSize(60, 40);
    setOrigin(getSize().x / 2, getSize().y / 2);
}

void Rhombus::updatePoints()
{
    if (getPointCount() != 4)
        Shape::setPointCount(4);
    Shape::setPoint(0, sf::Vector2f(size.x / 2, 0));
    Shape::setPoint(1, sf::Vector2f(size.x, size.y / 2));
    Shape::setPoint(2, sf::Vector2f(size.x / 2, size.y));
    Shape::setPoint(3, sf::Vector2f(0, size.y / 2));
}

void Rhombus::setSize(sf::Vector2f _size)
{
    size.x = (_size.x) ? _size.x : 0;
    size.y = (_size.y) ? _size.y : 0;

    updatePoints();
}

void Rhombus::setSize(float _w, float _h)
{
    size.x = (_w) ? _w : 0;
    size.y = (_h) ? _h : 0;

    updatePoints();
}

sf::Vector2f Rhombus::getSize(void)
{
    return size;
}

void Rhombus::move(sf::Vector2i win, sf::Vector2f offset)
{
    setFillColor(sf::Color::White);
    setPosition(getPosition() + offset);
    sf::FloatRect bound = getGlobalBounds();
    if (bound.left + bound.width > win.x || bound.left < 0)
    {
        setSpeed(getSpeed().x * (-1), getSpeed().y);
        offset.x *= -1;
        offset.y = 0;
    }
    if (bound.top + bound.height > win.y || bound.top < 0)
    {
        setSpeed(getSpeed().x, getSpeed().y * (-1));
        offset.y *= -1;
        offset.x = 0;
    }
}