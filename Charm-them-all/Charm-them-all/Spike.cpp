//
//  Spike.cpp
//  Charm-them-all
//
//  Created by Piotrek Kiełek on 10/10/17.
//  Copyright © 2017 Piotrek Kiełek. All rights reserved.
//

#include "Spike.hpp"
#include "Settings.h"

Spike::Spike(sf::Vector2f position){
    body.setRadius(SPIKE_BODY_RADIUS);
    body.setOrigin(body.getRadius(), body.getRadius());
    body.setPosition(position);
    body.setFillColor(sf::Color::Black);
}

void Spike::Draw(sf::RenderWindow &window){
    window.draw(body);
}
