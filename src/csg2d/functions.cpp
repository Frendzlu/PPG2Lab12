#include "functions.h"
#include "shape.h"
#include "Circle.h"
#include "ComplexShape.h"
#include "Rectangle.h"
// #include "circle.h"
// #include "rectangle.h"
// #include "complexshape.h"

sf::Vector2f rotate(const sf::Vector2f &v, float angle_rad)
{
	const float cs = std::cos(angle_rad);
	const float sn = std::sin(angle_rad);

	return { v.x*cs - v.y*sn, v.x*sn + v.y*cs };
}

void updateTexture(sf::Texture &t, const CSG2D::Shape &s, const sf::Color &foreground_color, const sf::Color &background_color)
{
	const auto tex_size = t.getSize();
	std::vector<sf::Uint8> tex_data(tex_size.x*tex_size.y*4u, 0u);
	const sf::Vector2f center = sf::Vector2f(tex_size)/2.f - sf::Vector2f(0.5f, 0.5f);
    for(std::size_t py = 0u; py < tex_size.y; ++py)
    {
	    for(std::size_t px = 0u; px < tex_size.x; ++px)
	    {
	        auto pos = sf::Vector2f(px, py) - center;
	        pos.y = -pos.y;
	        
	        const auto color = s.isIn(pos) ? foreground_color : background_color;

	        const std::size_t pi = py*tex_size.x + px;
	        const auto i = pi*4u;
	        tex_data[i] = color.r;
	        tex_data[i + 1u] = color.g;
	        tex_data[i + 2u] = color.b;
	        tex_data[i + 3u] = color.a;
	    }
    }
    t.update(tex_data.data());
}

std::shared_ptr<CSG2D::Shape> createCShape()
{
    auto circle_i = std::make_shared<CSG2D::Circle>(125.f, sf::Vector2f());
    auto circle_o = std::make_shared<CSG2D::Circle>(250.f, sf::Vector2f());
    auto letter_o = std::make_shared<CSG2D::ComplexShape>(circle_o, circle_i, CSG2D::OPERATION::DIFFERENCE);
    //return letter_o;
    auto ru = std::make_shared<CSG2D::Rectangle>(180.f, 150.f, sf::Vector2f(175, 25), std::numbers::pi/6.f);
    auto rd = std::make_shared<CSG2D::Rectangle>(180.f, 150.f, sf::Vector2f(175.f, -25.f), -std::numbers::pi/6.f);
    auto un = std::make_shared<CSG2D::ComplexShape>(ru, rd, CSG2D::OPERATION::UNION);
    //return un;
    auto letter_c = std::make_shared<CSG2D::ComplexShape>(letter_o, un, CSG2D::OPERATION::DIFFERENCE);

    return letter_c;
}

std::shared_ptr<CSG2D::Shape> createCSG2DScene()
{
    auto nothing = std::make_shared<CSG2D::Circle>(0.f, sf::Vector2f(0.f, 0.f));
    // hexagon
    auto middle_part = std::make_shared<CSG2D::Rectangle>(720.f, 420.f, sf::Vector2f(0.f, 0.f), 0.f);
    auto top_right_part = std::make_shared<CSG2D::Rectangle>(720.f, 420.f, sf::Vector2f(0.f, 0.f), std::numbers::pi / 3.0);
    auto top_left_part = std::make_shared<CSG2D::Rectangle>(720.f, 420.f, sf::Vector2f(0.f, 0.f), -std::numbers::pi / 3.0);
    auto hexagon = std::make_shared<CSG2D::ComplexShape>(top_left_part, top_right_part, CSG2D::OPERATION::UNION);
    hexagon = std::make_shared<CSG2D::ComplexShape>(hexagon, middle_part, CSG2D::OPERATION::UNION);

    auto c_hex = std::make_shared<CSG2D::ComplexShape>(hexagon, createCShape(), CSG2D::OPERATION::DIFFERENCE);
    //pluses
    auto pv1 = std::make_shared<CSG2D::Rectangle>(75.f, 25.f, sf::Vector2f(200.f, 0.f), 0);
    auto ph1 = std::make_shared<CSG2D::Rectangle>(25.f, 75.f, sf::Vector2f(200.f, 0.f), 0);
    auto pv2 = std::make_shared<CSG2D::Rectangle>(75.f, 25.f, sf::Vector2f(300.f, 0.f), 0);
    auto ph2 = std::make_shared<CSG2D::Rectangle>(25.f, 75.f, sf::Vector2f(300.f, 0.f), 0);
    auto p1 = std::make_shared<CSG2D::ComplexShape>(pv1, ph1, CSG2D::OPERATION::UNION);
    auto p2 = std::make_shared<CSG2D::ComplexShape>(pv2, ph2, CSG2D::OPERATION::UNION);
    auto p = std::make_shared<CSG2D::ComplexShape>(p1, p2, CSG2D::OPERATION::UNION);

    auto c_logo = std::make_shared<CSG2D::ComplexShape>(c_hex, p, CSG2D::OPERATION::DIFFERENCE);
    //letter m
    auto m1 = std::make_shared<CSG2D::Rectangle>(25.f, 125.f, sf::Vector2f(-350.f, -400.f), 0);
    auto m2 = std::make_shared<CSG2D::Rectangle>(25.f, 125.f, sf::Vector2f(-250.f, -400.f), 0);
    auto m3 = std::make_shared<CSG2D::Rectangle>(25.f, 75.f, sf::Vector2f(-319.f, -375.f), std::numbers::pi / 4);
    auto m4 = std::make_shared<CSG2D::Rectangle>(25.f, 75.f, sf::Vector2f(-281.f, -375.f), -std::numbers::pi / 4);

    auto m = std::make_shared<CSG2D::ComplexShape>(m1, m2, CSG2D::OPERATION::UNION);
    m = std::make_shared<CSG2D::ComplexShape>(m, m3, CSG2D::OPERATION::UNION);
    m = std::make_shared<CSG2D::ComplexShape>(m, m4, CSG2D::OPERATION::UNION);

    //letter f
    auto f1 = std::make_shared<CSG2D::Rectangle>(25.f, 125.f, sf::Vector2f(300.f, -400.f), 0);
    auto f2 = std::make_shared<CSG2D::Rectangle>(75.f, 25.f, sf::Vector2f(325.f, -350.f), 0);
    auto f3 = std::make_shared<CSG2D::Rectangle>(75.f, 25.f, sf::Vector2f(325.f, -400.f), 0);

    auto f = std::make_shared<CSG2D::ComplexShape>(f1, f2, CSG2D::OPERATION::UNION);
    f = std::make_shared<CSG2D::ComplexShape>(f, f3, CSG2D::OPERATION::UNION);

    auto letters = std::make_shared<CSG2D::ComplexShape>(f, m, CSG2D::OPERATION::UNION);
    return std::make_shared<CSG2D::ComplexShape>(c_logo, letters, CSG2D::OPERATION::UNION);

};