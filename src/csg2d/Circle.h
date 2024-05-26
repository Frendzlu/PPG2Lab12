//
// Created by Frendzlu on 20.05.2024.
//

#ifndef HUH_CIRCLE_H
#define HUH_CIRCLE_H

#include "shape.h"
namespace CSG2D {
    class Circle : public CSG2D::Shape {
        public: float radius;
        Circle(float radius, const sf::Vector2f &position);
        public:
            [[nodiscard]] bool isIn(const sf::Vector2f& test_position) const override;
    };
}



#endif //HUH_CIRCLE_H