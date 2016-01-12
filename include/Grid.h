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

#ifndef GRID_H
#define GRID_H

#include <allegro5/allegro_font.h>
#include <allegro5/drawing.h>
#include <allegro5/allegro_primitives.h>

#include <vector>

#include "Button.h"
#include "GameObject.h"

//-----------------------------------------------------------------------------
// Purpose: Pretty much represents the board in the game
//-----------------------------------------------------------------------------
class Grid //: public GameObject
{
    public:

        //-----------------------------------------------------------------------------
        // Purpose: Where the grid is aligned on the screen
        //-----------------------------------------------------------------------------
        typedef enum
        {
            LEFT,
            RIGHT,
            CENTER,
        } ScreenAlignment;

        Grid(ALLEGRO_DISPLAY *display, ALLEGRO_FONT **font_set = NULL, ScreenAlignment alignment = CENTER);
        virtual ~Grid();

        //-----------------------------------------------------------------------------
        // Purpose: Resize the grid.
        //-----------------------------------------------------------------------------
        void Resize(unsigned int width, unsigned int height);

        void Render();// override;

        //void Update(ALLEGRO_EVENT *evnt) override;

    protected:
        ALLEGRO_FONT **_FontSet;
        ALLEGRO_DISPLAY *_Display;
        GameObject *_DataGrid[10][10];
        ScreenAlignment _Alignment;
        std::vector<Button> Buttons;
};

#endif // GRID_H
