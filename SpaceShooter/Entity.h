#pragma once

#define _USE_MATH_DEFINES

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>

class Entity :
    public sf::RectangleShape
{
    // These set to private to avoid direct access from subclasses or program
    // Controlled through public methods
    float xSpeed;
    float ySpeed;

public:
    // Public methods allow for access from subclasses and program. 
    void setXSpeed(float x) { xSpeed = x; }
    void setYSpeed(float y) { ySpeed = y; }
    float getXSpeed() { return xSpeed; }
    float getYSpeed() { return ySpeed; }

    Entity(sf::Vector2f size, float xspeed = 0, float yspeed = 0) : xSpeed{ xspeed }, ySpeed{ yspeed }, RectangleShape(size) {}
};
