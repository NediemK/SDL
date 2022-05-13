void initEnnemy (Game* game) {
    for (int i=0; i<5; i++) {
        game->npc[i].spriteSheet[RIGHT][WALK][0] = IMG_Load ("NPC/walk1.png");
        game->npc[i].spriteSheet[RIGHT][WALK][1] = IMG_Load ("NPC/walk2.png");
        game->npc[i].spriteSheet[RIGHT][WALK][2] = IMG_Load ("NPC/walk3.png");
        game->npc[i].spriteSheet[RIGHT][WALK][3] = IMG_Load ("NPC/walk4.png");
        game->npc[i].spriteSheet[RIGHT][ATTACK][2] = IMG_Load ("NPC/attack1.png");
        game->npc[i].spriteSheet[RIGHT][ATTACK][3] = IMG_Load ("NPC/attack2.png");
        game->npc[i].spriteSheet[RIGHT][ATTACK][4] = IMG_Load ("NPC/attack3.png");
        game->npc[i].spriteSheet[RIGHT][DEATH][6] = IMG_Load ("NPC/death1.png");
        game->npc[i].spriteSheet[RIGHT][DEATH][7] = IMG_Load ("NPC/death2.png");
        game->npc[i].spriteSheet[RIGHT][DEATH][8] = IMG_Load ("NPC/death3.png");
        game->npc[i].spriteSheet[RIGHT][DEATH][9] = IMG_Load ("NPC/death4.png");

        // game->npc[i].spriteSheet[LEFT][WALK][0] = IMG_Load ("npc[i]/WALK1l.png");
        // game->npc[i].spriteSheet[LEFT][WALK][1] = IMG_Load ("npc[i]/WALK2l.png");
        // game->npc[i].spriteSheet[LEFT][ATTACK][2] = IMG_Load ("npc[i]/attack1l.png");
        // game->npc[i].spriteSheet[LEFT][ATTACK][3] = IMG_Load ("npc[i]/attack2l.png");
        // game->npc[i].spriteSheet[LEFT][ATTACK][4] = IMG_Load ("npc[i]/attack3l.png");
        // game->npc[i].spriteSheet[LEFT][ATTACK][5] = IMG_Load ("npc[i]/attack4l.png");
        // game->npc[i].spriteSheet[LEFT][DEATH][6] = IMG_Load ("npc[i]/death1l.png");
        // game->npc[i].spriteSheet[LEFT][DEATH][7] = IMG_Load ("npc[i]/death2l.png");
        // game->npc[i].spriteSheet[LEFT][DEATH][8] = IMG_Load ("npc[i]/death3l.png");
        // game->npc[i].spriteSheet[LEFT][DEATH][9] = IMG_Load ("npc[i]/death4l.png");
    }
    

    game->npc[0].spritePos.x = 700;
    game->npc[1].spritePos.x = 1700;
    game->npc[2].spritePos.x = 3000;
    game->npc[3].spritePos.x = 4000;
    game->npc[4].spritePos.x = 5000;

    game->npc[0].limitR = 700;
    game->npc[1].limitR = 1700;
    game->npc[2].limitR = 3000;
    game->npc[3].limitR = 4000;
    game->npc[4].limitR = 5000;

    for (int p=0; p<5; p++) {
        game->npc[p].spritePos.y = game->currentFloor - 160;
    }


    for (int j=0; j<5; j++) {
        game->npc[j].currentSprite = 0;
        game->npc[j].currentDirection = RIGHT;
        game->npc[j].currentState = WALK;

    }
    
    game->npc[0].limit = 1270;
    game->npc[1].limit = 2100;
    game->npc[2].limit = 3500;
    game->npc[3].limit = 4600;
    game->npc[4].limit = 5500;

    for (int k=0; k<5; k++) {
        game->npc[k].velX = 5;
    }

}

void showEnnemy (Game game) {
    SDL_BlitSurface(game.npc[0].spriteSheet[game.npc[0].currentDirection][game.npc[0].currentState][game.npc[0].currentSprite], NULL, game.screen, &game.npc[0].spritePos);
}

Uint32 animateEnnemy(Uint32 interval, void* param) {
  Game* game = param;
    int limit = game->npc[0].currentState == DEATH || game->npc[0].currentState == WALK ? 4 : 6;
    game->npc[0].currentSprite++;
    if(game->npc[0].currentSprite >= limit) {
        if(game->npc[0].currentState == ATTACK)
        game->npc[0].currentState = WALK;
        game->npc[0].currentSprite = 0;
    }
  return interval;
}

// void animerEnnemy (Game* game) {
//     game->npc[0].currentSprite++;
//     if (game->npc[0].currentSprite >= 3) {
//         game->npc[0].currentSprite = 0;
//     }
// }

void moveEnnemy (Game* game) {
    for (int i=0; i<5; i++) {
        game->npc[i].spritePos.x += game->npc[i].velX;
        if(game->npc[i].spritePos.x+130 >= game->npc[i].limit || game->npc[i].spritePos.x <= game->npc[i].limitR) {
            game->npc[i].velX = game->npc[i].velX * -1;
        } 
    }
}