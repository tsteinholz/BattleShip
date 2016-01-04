#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_physfs.h>
#include <allegro5/allegro_ttf.h>

#include <stdio.h>

ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *queue;
ALLEGRO_TIMER *timer;

const unsigned int SCREEN_W = 900, SCREEN_H = 600;

typedef enum
{
    MainMenu,
	HowToBlackJack,
	Instructions,
    Game,
    FinalMenu
} GameState;

GameState gameState = MainMenu;

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

	//background = Util::LoadB("res/table.jpeg");

    queue = al_create_event_queue();
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());
    timer = al_create_timer(1.0 / 60);
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_start_timer(timer);

    bool executing = true;
    while (executing)
    {
        ALLEGRO_EVENT event;
        al_wait_for_event(queue, &event);

        switch(event.type)
        {
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            executing = false;
            printf("debug: hit the close button");
            break;
        case ALLEGRO_EVENT_KEY_DOWN:
			if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) executing = false;
            break;
		case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
			break;
        case ALLEGRO_EVENT_MOUSE_AXES:
            break;
        case ALLEGRO_EVENT_TIMER:
            break;
        }

        if (al_is_event_queue_empty(queue))
        {
            //al_draw_scaled_bitmap(background, 0, 0, al_get_bitmap_width(background), al_get_bitmap_height(background), 0, 0 , SCREEN_W, SCREEN_H, 0);

            al_flip_display();
        }
    }
    al_destroy_display(display);

    return 0;
}
