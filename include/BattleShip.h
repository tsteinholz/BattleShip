//-----------------------------------------------------------------------------
//
// The MIT License (MIT)
//
// Copyright (c) 2016 Thomas Steinholz
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
//-----------------------------------------------------------------------------

#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_physfs.h>
#include <allegro5/allegro_ttf.h>

#include <stdio.h>

#include "Grid.h"

//-----------------------------------------------------------------------------
// Purpose: Main Game Class
//-----------------------------------------------------------------------------
class BattleShip
{
    public:
        BattleShip(ALLEGRO_DISPLAY* display);
        virtual ~BattleShip();

        //-----------------------------------------------------------------------------
        // Purpose: Set the current game mode and have the game act accordingly
        //-----------------------------------------------------------------------------
        typedef enum {
            MAINMENU,
            INSTRUCTIONS,
            GAME,
            CONCLUSION,
        } GameMode;

        //-----------------------------------------------------------------------------
        // Purpose: Update the game events
        //-----------------------------------------------------------------------------
        void Update(ALLEGRO_EVENT *event);

        //-----------------------------------------------------------------------------
        // Purpose: Render the game
        //-----------------------------------------------------------------------------
        void Render();

        //-----------------------------------------------------------------------------
        // Purpose: Called when resizing the game
        //-----------------------------------------------------------------------------
        void Resize();

        //-----------------------------------------------------------------------------
        // Purpose: Set to true to quit the game
        //-----------------------------------------------------------------------------
        bool Quit;

    protected:
        ALLEGRO_DISPLAY *_Display;
        Grid *_PlayerGrid;
        Grid *_ComputerGrid;
};

#endif // BATTLESHIP_H
