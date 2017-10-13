//
//  GameEngine.hpp
//  Charm-them-all
//
//  Created by Piotrek Kiełek on 10/10/17.
//  Copyright © 2017 Piotrek Kiełek. All rights reserved.
//

#ifndef GameEngine_hpp
#define GameEngine_hpp

#include <stdio.h>

#include "Player.hpp"
#include "Enemy.hpp"

class GameEngine{
public:
    static GameEngine* Instance();
    Player* getPlayer();
    void Draw(sf::RenderWindow& window);
    void Update();
    
private:
    Player* _player;
    std::vector<Enemy*> _enemies;
    GameEngine();
    GameEngine(GameEngine const&){};
    GameEngine& operator=(GameEngine const&){};
    static GameEngine* _Instance;
};

#endif /* GameEngine_hpp */
