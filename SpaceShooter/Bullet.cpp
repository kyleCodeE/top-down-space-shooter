#include "Bullet.h"

void Bullet::setSpeed(float playerX, float playerY, float rotation)
{
	// Calculate bullet speed based on current player rotation, 
	// and add current player speed for more fun bullets than just flat speed
	setXSpeed(baseBulletSpeed * sin(rotation * M_PI / 180) + playerX);

	setYSpeed(baseBulletSpeed * cos(rotation * M_PI / 180) - playerY);
}