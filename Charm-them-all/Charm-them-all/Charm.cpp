//
//  Charm.cpp
//  Charm-them-all
//
//  Created by Piotrek Kiełek on 10/10/17.
//  Copyright © 2017 Piotrek Kiełek. All rights reserved.
//

#include "Charm.hpp"
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "Settings.h"

Charm::Charm(sf::CircleShape player,int direction){
    body.setRadius(CHARM_BODY_RADIUS);
    body.setPosition(player.getPosition());
    body.setOrigin(body.getRadius(), body.getRadius());
    body.setFillColor(sf::Color::Magenta);
    
    this->direction = direction;
    speed = CHARM_SPEED;
    lifetime = CHARM_LIFETIME;
}

void Charm::Update(){
    if (direction == 1) {
        body.move(-speed, 0);
    }
    if (direction == 2) {
        body.move(0,-speed);
    }
    if (direction == 3) {
        body.move(speed, 0);
    }
    if (direction == 4) {
        body.move(0,speed);
    }
}

void Charm::Draw(sf::RenderWindow& window){
    window.draw(body);
}