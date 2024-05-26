//
// Created by Frendzlu on 20.05.2024.
//

#ifndef HUH_COMPLEXSHAPE_H
#define HUH_COMPLEXSHAPE_H

#include "shape.h"
#include "operation.h"

namespace CSG2D {
    class ComplexShape : public Shape {
    public:
        ComplexShape(std::shared_ptr<CSG2D::Shape> a, std::shared_ptr<CSG2D::Shape> b, OPERATION op);

        std::shared_ptr<Shape> a;
        std::shared_ptr<Shape> b;
        CSG2D::OPERATION op;
        ComplexShape(std::shared_ptr<CSG2D::Shape> a, std::shared_ptr<CSG2D::Shape> b, CSG2D::OPERATION op, const sf::Vector2f &position, double angle_rad);
        [[nodiscard]] virtual bool isIn(const sf::Vector2f& test_position) const override;
    };

} // CSG2D

#endif //HUH_COMPLEXSHAPE_H