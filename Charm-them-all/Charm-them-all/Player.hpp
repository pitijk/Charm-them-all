//
//  Player.hpp
//  Charm-them-all
//
//  Created by Piotrek Kiełek on 10/10/17.
//  Copyright © 2017 Piotrek Kiełek. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <SFML/Graphics.hpp>
#include "Charm.hpp"

class Player {
public:
    int hp;
    sf::CircleShape body;
    int speed;
    sf::Font font;
    sf::Text text;
    sf::Texture texture;
    sf::Texture texture2;
    std::vector<Charm*> charms;
    int charm_cooldown;
    Player(sf::Vector2f position);
    ~Player();
    void Update();
    void Draw(sf::RenderWindow& window);
    void hurt();
    int hurt_cooldown;
    bool immune;
};
#endif /* Player_hpp */
