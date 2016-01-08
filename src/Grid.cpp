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

#include "Grid.h"

Grid::Grid(ALLEGRO_DISPLAY *display, ALLEGRO_FONT **font_set, ScreenAlignment alignment) :
    _FontSet(font_set),
    _Display(display),
    _Alignment(alignment)
{ }

Grid::~Grid()
{
    //dtor
}

void Grid::Render()
{
    switch(_Alignment)
    {
    case LEFT:
        for (float i = 0; i < (al_get_display_width(_Display) / 2); i += ((al_get_display_width(_Display) / 2.0) / 11.0))
            al_draw_line(i, 0, i, al_get_display_height(_Display), al_map_rgb(0,255,255), 3);
        for (float i = 0; i < al_get_display_height(_Display); i += (al_get_display_height(_Display) / 11.0))
            al_draw_line(0, i, (al_get_display_width(_Display) / 2), i, al_map_rgb(0,255,255), 3);
        break;
    case RIGHT:
        for (float i = (al_get_display_width(_Display) / 2); i < al_get_display_width(_Display); i += ((al_get_display_width(_Display) / 2.0)/ 11.0))
            al_draw_line(i, 0, i, al_get_display_height(_Display), al_map_rgb(255,0,5), 3);
        for (float i = 0; i < al_get_display_height(_Display); i += (al_get_display_height(_Display) / 11.0))
            al_draw_line((al_get_display_width(_Display) / 2), i, al_get_display_width(_Display), i, al_map_rgb(255,0,5), 3);
        break;
    case CENTER:
    default:
        for (float i = 0; i < al_get_display_width(_Display); i += (al_get_display_width(_Display) / 10))
            al_draw_line(i, 0, i, al_get_display_height(_Display), al_map_rgb(0,0,255), 3);
        for (float i = 0; i < al_get_display_height(_Display); i += (al_get_display_height(_Display) / 10))
            al_draw_line(0, i, al_get_display_width(_Display), i, al_map_rgb(255,0,255), 3);
        break;
    }
}

void Grid::Resize(unsigned int width, unsigned int height)
{

}
