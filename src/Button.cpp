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

#include "Button.h"

Button::Button(int x, int y, int x2, int y2, char *text) :
    X(x), Y(y), X2(x2), Y2(y2), Text(text)
{ }

Button::~Button()
{

}

void Button::Render()
{
    al_draw_rectangle(X, Y, X2, Y2, al_map_rgb(255, 255, 0), 3);
    if (Hover)
        al_draw_rectangle(X, Y, X2, Y2, al_map_rgb(255, 0, 255), 3);
    if (Active)
        al_draw_rectangle(X, Y, X2, Y2, al_map_rgb(0, 255, 255), 3);
}

void Button::Update(ALLEGRO_EVENT *evnt)
{
    if (evnt->type == ALLEGRO_EVENT_MOUSE_AXES)
    {
        if (evnt->mouse.x >= X && evnt->mouse.x <= X2)
        {
            if (evnt->mouse.y >= Y && evnt->mouse.y <= Y2)
            {
                Hover = true;
            } else Hover = false;
        } else Hover = false;
    } else Hover = false;

    if (evnt->type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
    {
        if (evnt->mouse.x >= X && evnt->mouse.y <= Y)
        {
            if (evnt->mouse.y >= Y && evnt->mouse.y <= Y2)
            {
                Active = true;
            } else Active = false;
        } else Active = false;
    } else Active = false;
}
