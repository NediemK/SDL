void initPause(Game* game) {
    game->pauseMenu.bg = IMG_Load("Images/Bg/Menu.png");

    game->pauseMenu.bgPos.x = -100;
    game->pauseMenu.bgPos.y = -70;
    game->pauseMenu.bgPos.w = game->screen->w;
    game->pauseMenu.bgPos.h = game->screen->h;

    game->pauseMenu.btn[0].button[0] = IMG_Load("Images/Buttons/continue.png");
    
    game->pauseMenu.btn[0].pos.x = 429;
    game->pauseMenu.btn[0].pos.y = 251;
    game->pauseMenu.btn[0].pos.w = game->pauseMenu.btn[0].button[0]->w;
    game->pauseMenu.btn[0].pos.h = game->pauseMenu.btn[0].button[0]->h;

    game->pauseMenu.btn[1].button[0] = IMG_Load("Images/Buttons/save.png");

    game->pauseMenu.btn[1].pos.x = 429;
    game->pauseMenu.btn[1].pos.y = 347;
    game->pauseMenu.btn[1].pos.w = game->pauseMenu.btn[1].button[0]->w;
    game->pauseMenu.btn[1].pos.h = game->pauseMenu.btn[1].button[0]->h;

    game->pauseMenu.btn[2].button[0] = IMG_Load("Images/Buttons/quit.png");

    game->pauseMenu.btn[2].pos.x = 429;
    game->pauseMenu.btn[2].pos.y = 443;
    game->pauseMenu.btn[2].pos.w = game->pauseMenu.btn[2].button[0]->w;
    game->pauseMenu.btn[2].pos.h = game->pauseMenu.btn[2].button[0]->h;
}

void showPause (Game game) {
    SDL_BlitSurface (game.pauseMenu.bg, NULL, game.screen, &game.pauseMenu.bgPos);
    for(int i=0; i<3; i++) {
        SDL_BlitSurface (game.pauseMenu.btn[i].button[0], NULL, game.screen, &game.pauseMenu.btn[i].pos);
    }
}

void managePause (Game* game) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case(SDL_MOUSEBUTTONDOWN): {
                int mouseX, mouseY;

                SDL_GetMouseState(&mouseX, &mouseY);

                int check1 = checkMouseInside(game->pauseMenu.btn[0].pos, mouseX, mouseY);
                int check2 = checkMouseInside(game->pauseMenu.btn[1].pos, mouseX, mouseY);
                int check3 = checkMouseInside(game->pauseMenu.btn[2].pos, mouseX, mouseY);

                if (check1) {
                    game->currentMenu = LEVELONE;
                    break;
                }
                if (check2) {
                    saveGame(&game, "Process.txt");
                    break;
                }
                if (check3) {
                    game->currentMenu = MAIN_MENU;
                    break;
                }
            }
        }
    }
}