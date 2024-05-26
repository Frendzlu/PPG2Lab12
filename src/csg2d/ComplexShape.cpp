//
// Created by Frendzlu on 20.05.2024.
//

#include "ComplexShape.h"
#include "functions.h"

namespace CSG2D {
    ComplexShape::ComplexShape(std::shared_ptr<CSG2D::Shape> a, std::shared_ptr<CSG2D::Shape> b, CSG2D::OPERATION op, const sf::Vector2f &position, double angle_rad)
            : Shape(position, angle_rad) {
        this->a = a;
        this->b = b;
        this->op = op;

    }
    ComplexShape::ComplexShape(std::shared_ptr<CSG2D::Shape> a, std::shared_ptr<CSG2D::Shape> b, CSG2D::OPERATION op): ComplexShape(a, b, op, sf::Vector2f(0, 0), 0) {};

    bool ComplexShape::isIn(const sf::Vector2f &test_position) const {
        auto diff = test_position - this->position_;
        auto rot = rotate(diff, -this->angle_rad_);
        auto isA = this->a->isIn(rot);
        auto isB = this->b->isIn(rot);
        switch (this->op) {
            case CSG2D::OPERATION::DIFFERENCE:
                return isA && !isB;
            case CSG2D::OPERATION::UNION:
                return isA || isB;
            case CSG2D::OPERATION::INTERSECTION:
                return isA && isB;
        }
    }
} // CSG2D