//
//  Spike.hpp
//  Charm-them-all
//
//  Created by Piotrek Kiełek on 10/10/17.
//  Copyright © 2017 Piotrek Kiełek. All rights reserved.
//

#ifndef Spike_hpp
#define Spike_hpp

#include <SFML/Graphics.hpp>

class Spike {
public:
    sf::CircleShape body;
    
    Spike(sf::Vector2f position);
    void Draw(sf::RenderWindow& window);
};

#endif /* Spike_hpp */
