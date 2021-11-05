#pragma once
#include "NonPlayer.h"
class Enemy :
    public NonPlayer
{
    float enemyBaseSpeed = 5;

public:
    void setSpeed(sf::Vector2f playerPos);

    void die();

    Enemy() : NonPlayer(sf::Vector2f(30, 30)) {}
};

