//
// Created by Frendzlu on 20.05.2024.
//

#include "Circle.h"

CSG2D::Circle::Circle(float radius, const sf::Vector2f &position) : Shape(position, 2*std::numbers::pi),
radius(radius) {};
float length(const sf::Vector2f v2f) {
    return std::sqrt(v2f.x * v2f.x + v2f.y * v2f.y);
}
bool CSG2D::Circle::isIn(const sf::Vector2f &test_position) const {
    const auto x = test_position - this->position_;
    return length(x) < this->radius;
}