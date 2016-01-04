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

#include "BattleShip.h"

ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *queue;
ALLEGRO_TIMER *timer;

const unsigned int SCREEN_W = 900, SCREEN_H = 600;

int main(int argc, char **argv)
{
    srand((unsigned int) time(NULL));
    if(!al_init())
    {
        fprintf(stderr, "Failed to initialize allegro!\n");
    }
    display = al_create_display(SCREEN_W, SCREEN_H);
    if(!display)
    {
        fprintf(stderr, "Failed to create display!\n");
    }
    al_init_image_addon();
    if(!al_install_audio())
    {
        fprintf(stderr, "Failed to initialize audio!\n");
        return -1;
    }

    if(!al_init_acodec_addon())
    {
        fprintf(stderr, "Failed to initialize audio codecs!\n");
        return -1;
    }

    if (!al_reserve_samples(1))
    {
        fprintf(stderr, "Failed to reserve samples!\n");
        return -1;
    }
    if(!al_install_mouse())
    {
        fprintf(stderr, "Failed to initialize the mouse!\n");
        return -1;
    }
    if(!al_init_primitives_addon())
    {
        fprintf(stderr, "Failed to initialize primitives!\n");
    }
    al_init_font_addon();
    al_init_ttf_addon();
    al_install_keyboard();
    al_clear_to_color(al_map_rgb(0,0,0));

    al_set_window_title(display, "BattleShip by Thomas Steinholz");

    queue = al_create_event_queue();
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());
    timer = al_create_timer(1.0 / 60);
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_start_timer(timer);

    BattleShip *battleShip = new BattleShip();

    bool executing = true;
    while (executing)
    {
        ALLEGRO_EVENT event;
        al_wait_for_event(queue, &event);

        executing = !battleShip->Quit;
        battleShip->Update(&event);

        switch(event.type)
        {
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            executing = false;
            printf("debug: hit the close button");
            // TODO : Fix
            break;
        case ALLEGRO_EVENT_KEY_DOWN:
			if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) executing = false;
            break;
        }

        if (al_is_event_queue_empty(queue))
        {
            battleShip->Render();
            al_flip_display();
        }
    }
    delete battleShip;
    al_destroy_display(display);

    return 0;
}
