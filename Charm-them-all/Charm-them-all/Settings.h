//
//  Settings.h
//  Charm-them-all
//
//  Created by Piotrek Kiełek on 10/10/17.
//  Copyright © 2017 Piotrek Kiełek. All rights reserved.
//

#ifndef Settings_h
#define Settings_h

// PLAYER
static int HP = 3;
static int PLAYER_SPEED = 8;
static int PLAYER_BODY_RADIUS = 50;
static int PLAYER_HURT_COOLDOWN = 60;

// CHARM
static int CHARM_BODY_RADIUS = 20;
static int CHARM_SPEED = 35;
static int CHARM_COOLDOWN = 40;
static int CHARM_LIFETIME = 20;

// ENEMY
static int ENEMY_CORP_RADIUS = 50;
static int NORMAL_ENEMY_SPEED = 5;
static int CHARMED_ENEMY_SPEED = 3;
static int CHARMP_LENGHT = 120;
static int SPAWN_COOLDOWN = 170; //200

// SPIKE
static int SPIKE_BODY_RADIUS = 30;

// WINDOW
static int WINDOW_WIDTH = 1920;
static int WINDOW_HEIGHT = 1080;
static int FRAME_RATE= 60;
#endif /* Settings_h */
