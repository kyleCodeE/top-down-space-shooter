// --------------------------------------------------------
//   file: source.cpp
// author: K.Cote
//   desc: Top down space shooter
// 
// --------------------------------------------------------


#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Enemy.h"
#include "Bullet.h"
#include "Player.h"

// Global defines
// --------------------------------------------------------
const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 900;


//void refreshEntities(Player, Bullet[], Enemy, sf::Time, sf::Clock, int);


// main function
// --------------------------------------------------------
int main()
{
    // create our 2d graphics window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Shooter");

    sf::Clock clock2;
    sf::Time bulletCooldown;
    sf::Time bulletTime = sf::seconds(0.75);

    // TODO move all this into a starting function
    srand(time(NULL));

    sf::Clock clock;
    sf::Time time1;
    sf::Time time2 = sf::milliseconds(30);

    Player player;
    player.setOrigin(player.getSize().x / 2, 0);
    player.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

    // Create 10 bullets off screen for easy use later
    // TODO: create bullet on fire, delete when off screen
    Bullet bullets[10];
    for (int i = 0; i < 10; i++)
    {
        bullets[i].setPosition(-500, -500);
        bullets[i].setOrigin(bullets[i].getBulletWidth() / 2, bullets[i].getBulletLength() / 2);
    }
    int currentBullet = 0;

    Enemy firstEnemy;
    firstEnemy.setPosition(200, 200);
    firstEnemy.setFillColor(sf::Color::Red);
    firstEnemy.setOrigin(15, 15);

    while (window.isOpen())
    {
        time1 = clock.getElapsedTime();
        if (time1 >= time2)
        {

            !player; // update player pos, speed, rotation, etc.

            firstEnemy.setSpeed(player.getPosition());
            firstEnemy.move(firstEnemy.getXSpeed(), firstEnemy.getYSpeed());

            // Refresh all bullet locations
            for (int i = 0; i < 10; i++)
                bullets[i].move(bullets[i].getXSpeed(), -bullets[i].getYSpeed());


            bulletCooldown = clock2.getElapsedTime();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && bulletCooldown > bulletTime)
            {
                // Grab the next bullet in array and shoot from player
                currentBullet++;
                if (currentBullet == 10) currentBullet = 0;
                bullets[currentBullet].setSpeed(player.getXSpeed(), player.getYSpeed(), player.getRotation());
                bullets[currentBullet].setRotation(player.getRotation());
                bullets[currentBullet].setPosition(player.getPosition());
                clock2.restart();
            }

            if (abs(firstEnemy.getPosition().x - bullets[currentBullet].getPosition().x) < 18 && abs(firstEnemy.getPosition().y - bullets[currentBullet].getPosition().y) < 20)
            {
                firstEnemy.die();
            }

            clock.restart();

        }

        //process input
        // ------------------------------------------------
        sf::Event event;

        while (window.pollEvent(event))
        {
            //if (event.type == sf::Event::EventType::KeyPressed())

            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(); // swap next double display buffer
        window.draw(player); // draw to next
        for (int i = 0; i < 10; i++)
            window.draw(bullets[i]);
        window.draw(firstEnemy);
        window.display(); // display next
    }

    return 0;
} //end main

/*
void refreshEntities(Player player, Bullet bullets[10], Enemy firstEnemy, sf::Time bulletCooldown, sf::Clock clock2, int currentBullet)
{
    player.setAcceleration();
    player.setSpeed();
    player.move(player.getXSpeed(), player.getYSpeed());
    player.rotate();
    player.setRotation(player.getRotation());

    firstEnemy.setSpeed(player.getPosition());
    firstEnemy.move(firstEnemy.getXSpeed(), firstEnemy.getYSpeed());

    for (int i = 0; i < 10; i++)
        bullets[i].move(bullets[i].getXSpeed(), -bullets[i].getYSpeed());


    bulletCooldown = clock2.getElapsedTime();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && bulletCooldown > bulletTime)
    {
        currentBullet++;
        if (currentBullet == 10) currentBullet = 0;
        bullets[currentBullet].setSpeed(player.getXSpeed(), player.getYSpeed(), player.getRotation());
        bullets[currentBullet].setRotation(player.getRotation());
        bullets[currentBullet].setPosition(player.getPosition());
        clock2.restart();
    }

    if (abs(firstEnemy.getPosition().x - bullets[currentBullet].getPosition().x) < 18 && abs(firstEnemy.getPosition().y - bullets[currentBullet].getPosition().y) < 20)
    {
        firstEnemy.die();
    }
}*/