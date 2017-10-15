//
//  Charm.hpp
//  Charm-them-all
//
//  Created by Piotrek Kiełek on 10/10/17.
//  Copyright © 2017 Piotrek Kiełek. All rights reserved.
//

#ifndef Charm_hpp
#define Charm_hpp

#include <SFML/Graphics.hpp>
class Charm {
public:
    int speed;
    int lifetime;
    int direction;
    sf::CircleShape body;
    sf::Texture texture;
    
    Charm(sf::CircleShape player,int direction);
    void Update();
    void Draw(sf::RenderWindow& window);
};

#endif /* Charm_hpp */
