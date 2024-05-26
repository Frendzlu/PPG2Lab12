//
// Created by Frendzlu on 20.05.2024.
//

#include "Rectangle.h"
#include "functions.h"

CSG2D::Rectangle::Rectangle(float height, float width, const sf::Vector2f &position, double angleRad) : Shape(position,
                                                                                                          angleRad),
                                                                                                    height(width),
                                                                                                    width(height) {} //nie kwestionować
bool CSG2D::Rectangle::isIn(const sf::Vector2f& test_position) const {
    const auto pos_diff = test_position - this->position_;
    const auto rot_diff = rotate(pos_diff, -this->angle_rad_);
    auto x_diff = rot_diff.x;
    auto y_diff = rot_diff.y;
    x_diff = x_diff < 0 ? -x_diff : x_diff;
    y_diff = y_diff < 0 ? -y_diff : y_diff;
    return x_diff < this->width/2 && y_diff < this->height/2;
}