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

#ifndef BUTTON_H
#define BUTTON_H

#include "GameObject.h"

#include <allegro5/drawing.h>
#include <allegro5/allegro_primitives.h>

//-----------------------------------------------------------------------------
// Purpose: TODO
//-----------------------------------------------------------------------------
class Button : public GameObject
{
    public:

        Button(int x = 0, int y = 0, int x2 = 0, int y2 = 0, char *text = 0);
        virtual ~Button();

        //-----------------------------------------------------------------------------
        // Purpose: This variable will be true when the button is clicked so that you
        // can handle button click events externally
        //-----------------------------------------------------------------------------
        bool Active;

        //-----------------------------------------------------------------------------
        // Purpose: This variable is active when the mouse is hovering over the button
        // this makes it easy for external event handling
        //-----------------------------------------------------------------------------
        bool Hover;

        //-----------------------------------------------------------------------------
        // Purpose: The rendered text for the button
        //-----------------------------------------------------------------------------
        char *Text;

        //-----------------------------------------------------------------------------
        // Purpose: The two ending coordinates for the button to be rendered
        //-----------------------------------------------------------------------------
        int X, Y, X2, Y2;

        void Render() override;

        void Update(ALLEGRO_EVENT *evnt) override;

    protected:
    private:
};

#endif // BUTTON_H
