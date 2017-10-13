//
//  GameEngine.cpp
//  Charm-them-all
//
//  Created by Piotrek Kiełek on 10/10/17.
//  Copyright © 2017 Piotrek Kiełek. All rights reserved.
//

#include "GameEngine.hpp"

GameEngine* GameEngine::_Instance = NULL;



GameEngine* GameEngine::Instance()
{
    if (!_Instance)
        _Instance = new GameEngine;
    
    return _Instance;
}

GameEngine::GameEngine() {
    _player = new Player(sf::Vector2f(400, 400));
    _enemies = std::vector<Enemy*>();
    _enemies.push_back(new Enemy(sf::Vector2f(1000, 1000)));    
}

Player* GameEngine::getPlayer() {
    return _player;
}

void GameEngine::Update() {
    _player->Update();
    for(Enemy* enemy: _enemies) {
        enemy->Update(_player->getPosition());
    }
}


void GameEngine::Draw(sf::RenderWindow& window) {
    _player->Draw(window);
    for(Enemy* enemy: _enemies) {
        enemy->Draw(window);
    }
}
