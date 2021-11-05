#pragma once
#include "Entity.h"


class NonPlayer :
    public Entity
{

public:
    // void destroyed(bool colliding) {}; All nonPlayer entities will eventually
    // be destructable

    NonPlayer(sf::Vector2f size) : Entity(size) {}
    //NonPlayer(sf::Vector2f size, sf::Color color) : Entity(size, color) {}

};

