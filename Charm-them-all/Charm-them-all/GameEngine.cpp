//
//  GameEngine.cpp
//  Charm-them-all
//
//  Created by Piotrek Kiełek on 10/10/17.
//  Copyright © 2017 Piotrek Kiełek. All rights reserved.
//

#include "GameEngine.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Charm.hpp"
#include "Settings.h"
#include <iostream>

using namespace std;

GameEngine::GameEngine(){
    player = new Player(sf::Vector2f(WINDOW_WIDTH/2,WINDOW_HEIGHT/2));
    enemies.push_back(new Enemy(sf::Vector2f(1000,1000)));
    spawn_cooldown = 0;
    srand( time( NULL ) );
}

void GameEngine::Update(){
    spawn_cooldown++;
    if (spawn_cooldown >= SPAWN_COOLDOWN) {
        enemies.push_back(new Enemy(giveRandom()));
        
        spawn_cooldown = 0;
    }
    player->Update();
    for (int i = 0; i < enemies.size(); i++) {
        if (enemies[i]->charmed) {
            enemies[i]->target = player->body.getPosition();
        }else{
            if (is_near(enemies[i]->corp, enemies[i]->target)) { //enemies[i]->time_to_chane_direction <= 0 ||
                enemies[i]->target = giveRandom();
                //enemies[i]->time_to_chane_direction = ((rand() % 60) + 60);
            }
        }
            enemies[i]->Update();
    }
}

void GameEngine::Draw(sf::RenderWindow& window){
    player->Draw(window);
    for (int i = 0; i < enemies.size(); i++) {
        enemies[i]->Draw(window);
    }
}

sf::Vector2f GameEngine::giveRandom(){
    return sf::Vector2f((rand() % (WINDOW_WIDTH - ENEMY_CORP_RADIUS) + ENEMY_CORP_RADIUS),
                        (rand() % (WINDOW_HEIGHT - ENEMY_CORP_RADIUS) + ENEMY_CORP_RADIUS));
}

bool GameEngine::isColliding(sf::CircleShape one,sf::CircleShape two){
    float distance = sqrt(pow(fabs(one.getPosition().x-two.getPosition().x), 2)+
                          pow(fabs(one.getPosition().y-two.getPosition().y), 2));
    if(distance >= one.getRadius() + two.getRadius())
        return false;
    else
        return true;
}

bool GameEngine::is_near(sf::CircleShape enemy, sf::Vector2f point){
    float distance = sqrt(pow(fabs(enemy.getPosition().x - point.x), 2)+
                          pow(fabs(enemy.getPosition().y - point.y), 2));
    if(distance >= enemy.getRadius())
        return false;
    else
        return true;
}




