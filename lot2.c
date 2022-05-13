void initE (Game* game) {
    game->entity.spriteSheet[0][0][0] = IMG_Load ("Ennemy/lightning1.png");
    game->entity.spriteSheet[0][1][0] = IMG_Load ("Ennemy/lightning1.png");
    game->entity.spriteSheet[0][2][0] = IMG_Load ("Ennemy/lightning2.png");
    game->entity.spriteSheet[0][3][0] = IMG_Load ("Ennemy/lightning3.png");
    game->entity.spriteSheet[0][4][0] = IMG_Load ("Ennemy/lightning4.png");
    game->entity.spriteSheet[0][5][0] = IMG_Load ("Ennemy/lightning5.png");
    game->entity.spriteSheet[0][6][0] = IMG_Load ("Ennemy/lightning6.png");
    game->entity.spriteSheet[0][7][0] = IMG_Load ("Ennemy/lightning7.png");
    game->entity.spriteSheet[0][8][0] = IMG_Load ("Ennemy/lightning8.png");
    game->entity.spriteSheet[0][9][0] = IMG_Load ("Ennemy/lightning9.png");
    game->entity.spriteSheet[0][10][0] = IMG_Load ("Ennemy/lightning10.png");
    game->entity.spriteSheet[0][11][0] = IMG_Load ("Ennemy/lightning11.png");
    game->entity.spriteSheet[0][12][0] = IMG_Load ("Ennemy/lightning12.png");
    game->entity.spriteSheet[0][13][0] = IMG_Load ("Ennemy/lightning13.png");

    game->entity.spritePos.x = 914;
    game->entity.spritePos.y = 309;
    game->entity.spritePos.w = game->entity.spriteSheet[0][0][0]->w;
    game->entity.spritePos.h = game->entity.spriteSheet[0][0][0]->h;

    game->entity.currentSprite = 1;
}

void showE (Game game) {
    SDL_BlitSurface (game.entity.spriteSheet[0][game.entity.currentSprite][0], NULL, game.bg.img[0], &game.entity.spritePos);
}

// Uint32 bounceBack(Uint32 interval, int *param){
//   *param = 2;
//   return 0;
// }

Uint32 animateE(Uint32 interval, void* param) {
    Game* game = param;
    int limit = 14;
    game->entity.currentSprite++;
    if (game->entity.currentSprite>=limit){
      game->entity.currentSprite = 1;
      //SDL_BlitSurface(game->bg.img[0], &game->bg.camera, game->screen, &game->bg.pos);
    }
        
    //
    //showBg(game);
    // game->entity.spritePos.x += 100;
    // if(game->entity.spritePos.x >= game.game->screenw) {
    //     game->entity.spritePos.x = 0;
    // }
  return interval;
}
