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

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <allegro5/events.h>

//-----------------------------------------------------------------------------
// Purpose: Represents a Game Object
//-----------------------------------------------------------------------------
class GameObject
{
    public:

        GameObject();
        virtual ~GameObject();

        //-----------------------------------------------------------------------------
        // Purpose: Renders the Game Object
        //-----------------------------------------------------------------------------
        virtual void Render();

        //-----------------------------------------------------------------------------
        // Purpose: Updates the Game Object
        //-----------------------------------------------------------------------------
        virtual void Update(ALLEGRO_EVENT *event);

        //-----------------------------------------------------------------------------
        // Purpose: The X Coordinate value of the Game Object
        //-----------------------------------------------------------------------------
        int X;

        //-----------------------------------------------------------------------------
        // Purpose: The Y Coordinate value of the Game Object
        //-----------------------------------------------------------------------------
        int Y;
};

#endif // GAMEOBJECT_H
