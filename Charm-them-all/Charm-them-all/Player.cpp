//
//  Player.cpp
//  Charm-them-all
//
//  Created by Piotrek Kiełek on 10/10/17.
//  Copyright © 2017 Piotrek Kiełek. All rights reserved.
//
#include <iostream>
#include "Player.hpp"
#include "Settings.h"
#include <string>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include "Charm.hpp"

Player::Player(sf::Vector2f position){
    hp = HP;
    speed = PLAYER_SPEED;
    body.setRadius(PLAYER_BODY_RADIUS);
    body.setOrigin(body.getRadius(), body.getRadius());
    body.setPosition(position);
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
        body.move(-speed,0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        body.move(speed,0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        body.move(0,-speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        body.move(0,speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && charm_cooldown <=0 ) {
        charms.push_back(new Charm(body,2));
        charm_cooldown = CHARM_COOLDOWN;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && charm_cooldown <=0) {
        charms.push_back(new Charm(body,4));
        charm_cooldown = CHARM_COOLDOWN;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && charm_cooldown <=0) {
        charms.push_back(new Charm(body,1));
        charm_cooldown = CHARM_COOLDOWN;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && charm_cooldown <=0) {
        charms.push_back(new Charm(body,3));
        charm_cooldown = CHARM_COOLDOWN;
    }
    charm_cooldown--;
    for (int i = 0; i < charms.size(); i++) {
        charms[i]->Update();
    }
    for (int i = 0; i < charms.size(); i++) {
        charms[i]->lifetime -= 1;
        if (charms[i]->lifetime <= 0) {
            delete charms[i];
            charms.erase(charms.begin() + i);
        }
    }
}

void Player::Draw(sf::RenderWindow& window){
    window.draw(body);
    window.draw(text);
    for (int i = 0; i < charms.size(); i++) {
        charms[i]->Draw(window);
    }
}