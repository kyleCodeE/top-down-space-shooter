#pragma once
#include "Entity.h"


class Player :
    public Entity
{
    float acceleration;
    short health;
    float radRotation;
    sf::Vector2f size{ 50, 75 };



public:
    short getHealth() { return health; }
    float getRadRotation() { return radRotation; }

    void setAcceleration();
    //void takeDamage(); // TODO implement health system
    void rotate();
    void setSpeed();
    int playerWidth = 50;
    int playerLength = 75;

    void operator!();

    Player() : acceleration{ 0 }, health{ 10 }, radRotation{ 0 }, Entity(sf::Vector2f(50, 75)) {}
};