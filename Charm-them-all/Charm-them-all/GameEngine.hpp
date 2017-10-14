//
//  GameEngine.hpp
//  Charm-them-all
//
//  Created by Piotrek Kiełek on 10/10/17.
//  Copyright © 2017 Piotrek Kiełek. All rights reserved.
//

#ifndef GameEngine_hpp
#define GameEngine_hpp

#include <SFML/Graphics.hpp>
#include "Charm.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
class GameEngine {
public:
    int spawn_cooldown;
    Player* player;
    std::vector<Charm*> charms;
    std::vector<Enemy*> enemies;
    
    GameEngine();
    sf::Vector2f giveRandom();
    void Update();
    void Draw(sf::RenderWindow& window);
    bool isColliding(sf::CircleShape one,sf::CircleShape two);
    bool is_near(sf::CircleShape enemy, sf::Vector2f point);
};

#endif /* GameEngine_hpp */
