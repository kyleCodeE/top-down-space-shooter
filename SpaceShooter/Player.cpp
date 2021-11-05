#include "Player.h"



void Player::setAcceleration()
{
    // Acceleration is more fun than a flat speed
    // Check for keyboard input // WASD controls
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
        sf::Keyboard::isKeyPressed(sf::Keyboard::S)) acceleration = 0;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) acceleration = -.5;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) acceleration = .5;
    else acceleration = 0;
}



void Player::rotate()
{
    float rotation = getRotation();

    // Check for keyboard input // WASD controls
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
        sf::Keyboard::isKeyPressed(sf::Keyboard::A)) return;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) setRotation(rotation += 5);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) setRotation(rotation -= 5);

    radRotation = rotation * M_PI / 180;
}



void Player::setSpeed()
{
    // Player speed needs to run through multiple checks, in a specific order

    float xSpeed = getXSpeed();
    xSpeed += acceleration * sin(getRotation() * M_PI / 180); // Set speed in x direction using trig

    float ySpeed = getYSpeed();
    ySpeed -= acceleration * cos(getRotation() * M_PI / 180); // Set speed in y direction using trig

    // If LSHIFT (brakes) is pressed, slow down. Can hit gas and brakes at the same time.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
    {
        xSpeed *= 0.95;
        ySpeed *= 0.95;

        // stop once below a certain speed, otherwise it will never stop (in a reasonable time)
        if (abs(xSpeed) < .005 && abs(ySpeed) < .005) {
            xSpeed = 0;
            ySpeed = 0;
        }
    }

    // Prevent from leaving border // Temporary until removing borders
    float cellX = getPosition().x;
    float cellY = getPosition().y;
    if ((cellX >= 1150 && xSpeed > 0) || (cellX <= 50 && xSpeed < 0)) xSpeed = 0;
    if ((cellY >= 850 && ySpeed > 0) || (cellY <= 50 && ySpeed < 0)) ySpeed = 0;

    setXSpeed(xSpeed);
    setYSpeed(ySpeed);
}



void Player::operator!()
{
    setAcceleration();
    setSpeed();
    move(getXSpeed(), getYSpeed());
    rotate();
    setRotation(getRotation());
}