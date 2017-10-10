//
//  Player.cpp
//  Charm-them-all
//
//  Created by Piotrek Kiełek on 10/10/17.
//  Copyright © 2017 Piotrek Kiełek. All rights reserved.
//

#include "Player.hpp"
#include "Settings.h"
#include <string>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <cmath>

Player::Player(sf::Vector2f position){
    hp = HP;
    player_speed = PLAYER_SPEED;
    body.setRadius(PLAYER_BODY_RADIUS);
    body.setPosition(position);
    body.setOrigin(body.getRadius(), body.getRadius());
    body.setFillColor(sf::Color::Blue);
    //Hp display
    
    font.loadFromFile(resourcePath() + "sansation.ttf");
    text.setFont(font);
    text.setCharacterSize(70);
    text.setColor(sf::Color::Red);
    text.setString(std::to_string(hp));
    text.setPosition(20, 20);
}

Player::~Player(){

}

void Player::Update(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        body.move(-player_speed,0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        body.move(player_speed,0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        body.move(0,-player_speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        body.move(0,player_speed);
    }
}

void Player::Draw(sf::RenderWindow& window){
    window.draw(body);
    window.draw(text);
}