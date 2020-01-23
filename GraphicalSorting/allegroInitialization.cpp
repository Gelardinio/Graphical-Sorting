#include <iostream>
#include "allegro.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>

extern ALLEGRO_DISPLAY *display;
extern ALLEGRO_TIMER *timer;
extern ALLEGRO_EVENT_QUEUE *event_queue;
extern ALLEGRO_FONT *button_font;

//Initializes allegro, includes proper events needed
int initialize_allegro() {

    //Initialize allegro
    al_init();

    //Create and check if display opens
    display = al_create_display(1600, 900);
    al_clear_to_color(al_map_rgb(196, 116, 4));

    if (!display) {
        al_show_native_message_box(display, "Error", "Error", "failed to initialize the display!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    al_set_window_title(display, "Graphical Soring - Gerald Liu");

        // Initialize keyboard routines
    if (!al_install_keyboard()) {
        al_show_native_message_box(display, "Error", "Error", "failed to initialize the keyboard!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    // Timer setup
    timer = al_create_timer(1.0 / 60);
    if (!timer) {
        al_show_native_message_box(display, "Error", "Error", "Failed to create timer!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    if(!al_init_primitives_addon()) {
        al_show_native_message_box(display, "Error", "Error", "failed to initialize primitives addon!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    // set up event queue
    event_queue = al_create_event_queue();
    if (!event_queue) {
        al_show_native_message_box(display, "Error", "Error", "Failed to create event_queue!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));


     if (!al_install_mouse()){
        al_show_native_message_box(display, "Error", "Error",
        "Failed to initialize mouse!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return false;
     }

    //Include font addon
    al_init_font_addon();

    if (!al_init_ttf_addon()) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize ttf addon!", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    button_font = al_load_ttf_font("SF_Cartoonist_Hand.ttf", 40, 0);

    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_start_timer(timer);

    return 0;

}

