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
#include "ResourcePath.hpp"
#include <iostream>

using namespace std;

GameEngine::GameEngine(){
    player = new Player(sf::Vector2f(WINDOW_WIDTH/2,WINDOW_HEIGHT/2));
    spawn_cooldown = SPAWN_COOLDOWN;
    set_up_spikes();
    srand( time( NULL ) );
    conti = false;
    score = 0;
    font.loadFromFile(resourcePath() + "sansation.ttf");
    text.setFont(font);
    text.setCharacterSize(70);
    text.setColor(sf::Color::Red);
    text.setString("Your score: " + to_string(score));
    text.setPosition(WINDOW_WIDTH*0.7,20);
}

void GameEngine::Update(){
if(player->hp > 0){
    spawn_cooldown++;
    if (spawn_cooldown >= SPAWN_COOLDOWN) {
        enemies.push_back(new Enemy(giveRandom()));
        spawn_cooldown = 0;
        for (int i = 0; i < spikes.size(); i++) {
            while (isColliding(enemies[enemies.size()-1]->corp,spikes[i]->body) ||
                   isColliding(enemies[enemies.size()-1]->corp,player->body)) {
                enemies[enemies.size()-1]->corp.setPosition(giveRandom());
            }
        }
    }
    for (int i = 0; i < spikes.size(); i++) {
        if(isColliding(player->body, spikes[i]->body))
            player->hurt();
    }
    for (int i = 0; i < enemies.size(); i++) {
        for (int j = 0; j < player->charms.size(); j++) {
            if (isColliding(enemies[i]->corp, player->charms[j]->body)) {
                enemies[i]->charmed = true;
                enemies[i]->charm_time = CHARMP_LENGHT;
                player->charms[j]->lifetime = 0;
                break;
            }
        }
        if (isColliding(player->body, enemies[i]->corp) && !player->immune) {
            player->hurt();
            delete enemies[i];
            enemies.erase(enemies.begin() + i);
            score++;
            continue;
        }
        if (enemies[i]->charmed) {
            enemies[i]->target = player->body.getPosition();
        }else{
            if (is_near(enemies[i]->corp, enemies[i]->target))
                enemies[i]->target = giveRandom();
        }
        for (int j = 0; j < spikes.size(); j++) {
            if (isColliding(enemies[i]->corp,spikes[j]->body)) {
                if (enemies[i]->charmed) {
                    delete enemies[i];
                    enemies.erase(enemies.begin() + i);
                    score++;
                    conti = true;
                    break;
                }else{
                    sf::Vector2f position = enemies[i]->corp.getPosition();
                    while (isColliding(enemies[i]->corp,spikes[j]->body)) {
                        enemies[i]->corp.setPosition(position);
                        enemies[i]->target = giveRandom();
                        enemies[i]->Update();
                    }
                    enemies[i]->corp.setPosition(position);
                }
            }
        }
        if(!conti)
            enemies[i]->Update();
    }
    conti = false;
    text.setString("Your score: " + to_string(score));
    player->Update();
}else{//if (hp > 0)
    text.setString("             Your score: " + to_string(score) + "\nClick SPACE to playe again");
    text.setPosition(WINDOW_WIDTH*0.28,WINDOW_HEIGHT*0.4);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        restart();
}
    
}

void GameEngine::Draw(sf::RenderWindow& window){
    if (player->hp > 0) {
        for (int i = 0; i < enemies.size(); i++) {
            enemies[i]->Draw(window);
        }
        for (int i = 0; i < spikes.size(); i++) {
            spikes[i]->Draw(window);
        }
        player->Draw(window);
        window.draw(text);
    }else{
        window.draw(text);
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

void GameEngine::restart(){
    player->body.setPosition(WINDOW_WIDTH/2,WINDOW_HEIGHT/2);
    player->hp = HP;
    enemies.clear();
    player->charms.clear();
    conti = false;
    score = 0;
    text.setString("Your score: " + to_string(score));
    text.setPosition(WINDOW_WIDTH*0.7,20);
    spawn_cooldown = SPAWN_COOLDOWN;
}

void GameEngine::set_up_spikes(){
    int y = WINDOW_WIDTH/4;
    int x = (WINDOW_WIDTH - 15 * SPIKE_BODY_RADIUS - y)/2;
    int h = (WINDOW_HEIGHT - 7.5*SPIKE_BODY_RADIUS)/2 + WINDOW_HEIGHT*0.05;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            spikes.push_back(new Spike(sf::Vector2f(x + i*SPIKE_BODY_RADIUS*2.5,h+j*SPIKE_BODY_RADIUS*2.5) ));
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            spikes.push_back(new Spike(sf::Vector2f(WINDOW_WIDTH-x-7.5*SPIKE_BODY_RADIUS + i*SPIKE_BODY_RADIUS*2.5,h+j*SPIKE_BODY_RADIUS*2.5) ));
        }
    }
        
}


