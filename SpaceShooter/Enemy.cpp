#include "Enemy.h"
#include <iostream>

void Enemy::setSpeed(sf::Vector2f playerPos)
{
    // calc vertical and horizontal distance between enemy and player
    // Need xDiff as float, or to convert later to produce correct pathAngle
    float xDifference = getPosition().x - playerPos.x; 
    int yDifference = getPosition().y - playerPos.y;

    // calc angle of line for enemy to follow
    float pathAngle;
    if (yDifference != 0) {
        pathAngle = atan(xDifference / yDifference);
    }
    else pathAngle = M_PI;

    // 
    float xSpeed;
    float ySpeed;
    xSpeed = enemyBaseSpeed * sin(pathAngle);
    ySpeed = enemyBaseSpeed * cos(pathAngle);
    if (xDifference == 0) xSpeed = 0;
    //else if (xDifference < 0) xSpeed *= -1;

    if (yDifference == 0) ySpeed = 0;
    else if (yDifference > 0)
    {
        ySpeed *= -1;
        xSpeed *= -1;
    }
    setXSpeed(xSpeed);
    setYSpeed(ySpeed);
}

void Enemy::die()
{

    /*
     * Moves the enemy off screen, to attack again
     *
     * TODO make it actually die and create new object
     */
    int x = rand() % 1400 - 200;
    int y;
    if (x < -50 || x > 1250)
    {
        y = rand() % 1100 - 200;
    }
    else y = rand() % 1100 + 950;

    setPosition(x, y);
}