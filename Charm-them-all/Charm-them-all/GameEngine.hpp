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
#include "Spike.hpp"
class GameEngine {
public:
    int spawn_cooldown;
    Player* player;
    std::vector<Enemy*> enemies;
    std::vector<Spike*> spikes;
    GameEngine();
    sf::Vector2f giveRandom();
    void set_up_spikes();
    void Update();
    void Draw(sf::RenderWindow& window);
    bool isColliding(sf::CircleShape one,sf::CircleShape two);
    bool is_near(sf::CircleShape enemy, sf::Vector2f point);
    bool conti;
    int score;
    sf::Font font;
    sf::Text text;
    void restart();
    
};

#endif /* GameEngine_hpp */
