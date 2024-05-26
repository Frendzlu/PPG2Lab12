//
// Created by Frendzlu on 20.05.2024.
//

#ifndef HUH_RECTANGLE_H
#define HUH_RECTANGLE_H

#include "shape.h"

namespace CSG2D {
    class Rectangle : public CSG2D::Shape {
    public:
        float height;
        float width;
        Rectangle(float height, float width, const sf::Vector2f &position, double angleRad);
        [[nodiscard]] bool isIn(const sf::Vector2f& test_position) const override;
    };
}



#endif //HUH_RECTANGLE_H