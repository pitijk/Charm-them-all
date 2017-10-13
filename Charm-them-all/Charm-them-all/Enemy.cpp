//
//  Enemy.cpp
//  Charm-them-all
//
//  Created by Piotrek Kiełek on 10/10/17.
//  Copyright © 2017 Piotrek Kiełek. All rights reserved.
//

#include "Enemy.hpp"
#include "Settings.h"
#include <cmath>
#include <iostream>

using namespace std;
Enemy::Enemy(sf::Vector2f position){
    speed = NORMAL_ENEMY_SPEED;
    corp.setRadius(ENEMY_CORP_RADIUS);
    corp.setOrigin(corp.getRadius(), corp.getRadius());
    corp.setPosition(position);
    corp.setFillColor(sf::Color::Red);
    charmed = true;
    charm_time = CHARMP_LENGHT;
}

Enemy::~Enemy(){
    
}

void Enemy::Update(sf::Vector2f position){
    double angle = atan(fabs(position.x - corp.getPosition().x)/
                        fabs(position.y - corp.getPosition().y))*180/3.14;
    charm_time--;
    if(charm_time <= 0)
        charmed = false;
    if (charmed) {
        corp.setFillColor(sf::Color::Magenta);
    }else
        corp.setFillColor(sf::Color::Red);
    if(charmed)
        speed = CHARMED_ENEMY_SPEED;
    else
        speed = NORMAL_ENEMY_SPEED;
    
        if ((position.x - corp.getPosition().x)>0) {
            if ((position.y - corp.getPosition().y)>0) {
                corp.setRotation(90 - angle);
            }else
                corp.setRotation(270 + angle);
        }else{
            if ((position.y - corp.getPosition().y)>0) {
                corp.setRotation(90 + angle);
            }else
                corp.setRotation(270 - angle);
        }
        corp.move(cos(corp.getRotation()*3.14/180)*speed,sin(corp.getRotation()*3.14/180)*speed);
}
void Enemy::Draw(sf::RenderWindow& window){
    window.draw(corp);
}