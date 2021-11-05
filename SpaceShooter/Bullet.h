#pragma once
#include "NonPlayer.h"


class Bullet :
    public NonPlayer
{
    float baseBulletSpeed = 20;
    float bulletWidth = 5;
    float bulletLength = 10;
    sf::Vector2f size{ 5, 10 };
    sf::Color bulletColor = sf::Color::Green;
public:
    bool isOffScreen() {};
    void setSpeed(float, float, float);
    float getBulletWidth() { return bulletWidth; }
    float getBulletLength() { return bulletLength; }

    Bullet() : NonPlayer(sf::Vector2f(6, 8)) {}
    //Bullet() : NonPlayer(sf::Vector2f(5, 10), bulletColor) {}

};