

void initXo (Game* game) {
    int sx, sy;
    sx = sy = 0;
    for (int i=0; i<3; i++) {
        sx = 0;
        sy += 200;
        for (int j=0; j<3; j++) {
            game->xo.board[i][j].carre = IMG_Load ("carre.png");
            game->xo.board[i][j].x = IMG_Load ("x.png");
            game->xo.board[i][j].o = IMG_Load ("o.png");

            sx += 280;
            
            game->xo.board[i][j].pos.x = sx;
            game->xo.board[i][j].pos.y = sy - 100;
            game->xo.board[i][j].pos.w = game->xo.board[i][j].carre->w;
            game->xo.board[i][j].pos.h = game->xo.board[i][j].carre->h;

            game->xo.board[i][j].holder = 0;
        }
    }

    game->xo.done = 1;
    game->xo.currentPlayer = 0;

    srand(time(NULL));
}

void showXo (Game game) {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            SDL_BlitSurface (game.xo.board[i][j].carre, NULL, game.screen, &game.xo.board[i][j].pos);
            if (game.xo.board[i][j].holder == 1) {
                SDL_BlitSurface (game.xo.board[i][j].x, NULL, game.screen, &game.xo.board[i][j].pos);
            } else if (game.xo.board[i][j].holder == 2) {
                SDL_BlitSurface (game.xo.board[i][j].o, NULL, game.screen, &game.xo.board[i][j].pos);
            }
        }
    }
}

int checkFreeSpace (Game* game, int x, int y) {
    return (game->xo.board[x][y].holder == 0);
}

void placeXo (Game* game) {
    if (game->xo.currentPlayer == 0) {
        while(SDL_PollEvent(&event)) {
        switch (event.type) {
            case (SDL_MOUSEBUTTONDOWN): {
                SDL_GetMouseState(&mouseX,&mouseY);
                for (int i=0; i<3; i++) {
                    for (int j=0; j<3; j++) {
                        if (checkMouseInside(game->xo.board[i][j].pos, mouseX, mouseY) && checkFreeSpace(game, i,j) == 1) {
                            game->xo.board[i][j].holder = 1;
                            game->xo.currentPlayer = 1;
                        }
                    }
                }
            }
            case (SDL_KEYDOWN): {
                int key = event.key.keysym.sym;

                switch (key) {
                    case (SDLK_ESCAPE): 
                        game->done = 0;
                }
                break;
            }
        }
    }
    } else {
        int r = rand() % 3;
        int k = rand() % 3;
        if (checkFreeSpace(game, r, k) == 1) {
            game->xo.board[r][k].holder = 2;
            game->xo.currentPlayer = 0;
        }
    }
}

int checkFreeSpaces (Game* game) {
    int freeSpace = 9;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (game->xo.board[i][j].holder != 0) {
                freeSpace--;
            }
        }
    }
    return freeSpace;
}

int checkWinner (Game* game) {
    for (int i=0; i<3; i++){
        if (game->xo.board[i][0].holder == 1 && game->xo.board[i][1].holder == 1 && game->xo.board[i][2].holder == 1) {
             //printf("yo\n");
            return 1;
        } else if (game->xo.board[i][0].holder == 2 && game->xo.board[i][1].holder == 2 && game->xo.board[i][2].holder == 2) {
            // printf("yo\n");
            return 2;
        }
        if (game->xo.board[0][i].holder == 1 && game->xo.board[1][i].holder == 1 && game->xo.board[2][i].holder == 1) {
             //printf("yo1\n");
            return 1;
        } else if (game->xo.board[0][i].holder == 2 && game->xo.board[1][i].holder == 2 && game->xo.board[2][i].holder == 2) {
            // printf("yo\n");
            return 2;
        } else {
            return 0;
        }
    }
    
}

void manageXo (Game* game) {
    if (checkWinner (game) == 1 || checkFreeSpaces(game) == 0) {
        game->currentMenu = LEVELTWO;
        game->bg.camera.x += 20;
    } else if (checkWinner (game) == 2 || checkFreeSpaces(game) == 0) {
        // data
    }
}