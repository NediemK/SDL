int checkTurnedCards (Game* game) {
    int s = 0;
    for (int i=0; i<10; i++) {
        if (game->cards.card[i].state == 0) {
            s += 1;
        }
    }
    return s;
}

int checkCorrect (Game* game) {
    int x[2];
    int k = 0;
    for (int i=0; i<10; i++) {
        if (game->cards.card[i].state == 0) {
            x[k] = game->cards.card[i].id;
            k++;
        }
    }
    return (x[0] == x[1]);
}

void initCards (Game* game) {
    for (int i=0; i<10; i++) {
        game->cards.card[i].img[1] = IMG_Load ("Images/Cards/mask.png");
        game->cards.card[i].state = 1;
    }

    game->cards.card[0].img[0] = IMG_Load ("Images/Cards/card1.png");
    game->cards.card[0].id = 0;
    game->cards.card[0].pos.x = 101;
    game->cards.card[0].pos.y = 104;
    game->cards.card[0].pos.w = game->cards.card[0].img[0]->w;
    game->cards.card[0].pos.h = game->cards.card[0].img[0]->h;

    game->cards.card[1].img[0] = IMG_Load ("Images/Cards/card2.png");
    game->cards.card[1].id = 1;
    game->cards.card[1].pos.x = 363;
    game->cards.card[1].pos.y = 104;
    game->cards.card[1].pos.w = game->cards.card[1].img[0]->w;
    game->cards.card[1].pos.h = game->cards.card[1].img[0]->h;

    game->cards.card[2].img[0] = IMG_Load ("Images/Cards/card3.png");
    game->cards.card[2].id = 2;
    game->cards.card[2].pos.x = 570;
    game->cards.card[2].pos.y = 104;
    game->cards.card[2].pos.w = game->cards.card[2].img[0]->w;
    game->cards.card[2].pos.h = game->cards.card[2].img[0]->h;

    game->cards.card[3].img[0] = IMG_Load ("Images/Cards/card4.png");
    game->cards.card[3].id = 3;
    game->cards.card[3].pos.x = 804;
    game->cards.card[3].pos.y = 104;
    game->cards.card[3].pos.w = game->cards.card[3].img[0]->w;
    game->cards.card[3].pos.h = game->cards.card[3].img[0]->h;

    game->cards.card[4].img[0] = IMG_Load ("Images/Cards/card5.png");
    game->cards.card[4].id = 4;
    game->cards.card[4].pos.x = 1038;
    game->cards.card[4].pos.y = 104;
    game->cards.card[4].pos.w = game->cards.card[4].img[0]->w;
    game->cards.card[4].pos.h = game->cards.card[4].img[0]->h;


    game->cards.card[5].img[0] = IMG_Load ("Images/Cards/card1.png");
    game->cards.card[5].id = 0;
    game->cards.card[5].pos.x = 1038;
    game->cards.card[5].pos.y = 407;
    game->cards.card[5].pos.w = game->cards.card[5].img[0]->w;
    game->cards.card[5].pos.h = game->cards.card[5].img[0]->h;

    game->cards.card[6].img[0] = IMG_Load ("Images/Cards/card2.png");
    game->cards.card[6].id = 1;
    game->cards.card[6].pos.x = 570;
    game->cards.card[6].pos.y = 407;
    game->cards.card[6].pos.w = game->cards.card[6].img[0]->w;
    game->cards.card[6].pos.h = game->cards.card[6].img[0]->h;

    game->cards.card[7].img[0] = IMG_Load ("Images/Cards/card3.png");
    game->cards.card[7].id = 2;
    game->cards.card[7].pos.x = 363;
    game->cards.card[7].pos.y = 407;
    game->cards.card[7].pos.w = game->cards.card[7].img[0]->w;
    game->cards.card[7].pos.h = game->cards.card[7].img[0]->h;

    game->cards.card[8].img[0] = IMG_Load ("Images/Cards/card4.png");
    game->cards.card[8].id = 3;
    game->cards.card[8].pos.x = 804;
    game->cards.card[8].pos.y = 407;
    game->cards.card[8].pos.w = game->cards.card[8].img[0]->w;
    game->cards.card[8].pos.h = game->cards.card[8].img[0]->h;

    game->cards.card[9].img[0] = IMG_Load ("Images/Cards/card5.png");
    game->cards.card[9].id = 4;
    game->cards.card[9].pos.x = 101;
    game->cards.card[9].pos.y = 407;
    game->cards.card[9].pos.w = game->cards.card[9].img[0]->w;
    game->cards.card[9].pos.h = game->cards.card[9].img[0]->h;
}

void showCards (Game* game) {
    for (int i=0; i<10; i++) {
        SDL_BlitSurface (game->cards.card[i].img[game->cards.card[i].state], NULL, game->screen, &game->cards.card[i].pos);
    }
    SDL_Delay (500);
}



void manageCards (Game* game) {
    if (checkTurnedCards(game) >= 2) {
        if (checkCorrect(game)) {
            printf("Well Done!\n");
            game->currentLevel = 2;
            game->currentMenu = LEVELTHREE;
            game->character.spritePos.x = 0;
        } else {
            for (int i=0; i<10; i++) {
                game->cards.card[i].state = 1;
            }
        }
    }
    SDL_Event e;
    while(SDL_PollEvent(&e)) {
        switch (e.type) {
            case (SDL_MOUSEBUTTONDOWN): {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
                for (int i=0; i<10; i++) {
                    if (checkMouseInside (game->cards.card[i].pos, mouseX, mouseY) && checkTurnedCards(game) <= 2) {
                        game->cards.card[i].state = 0;
                    }
                }
            }
            case (SDL_KEYDOWN): {
                int key = e.key.keysym.sym;
                switch (key) {
                    case (SDLK_ESCAPE): {
                        game->done =1;
                        break;
                    }
                    break;
                }
            }
        }
    }
}
