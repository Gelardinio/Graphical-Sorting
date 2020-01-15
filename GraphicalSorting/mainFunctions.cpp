#include <iostream>
#include "mainFunctions.h"
#include "sorting.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

void displaySort(ALLEGRO_FONT *add_font, vector<int> step, int pointerPos) {

    al_clear_to_color(al_map_rgb(0, 0, 0));

    for (int i = 0; i < step.size(); i++) {
        al_draw_filled_rectangle(8 * i, 900 - ((9/4) * step[i]), 8 + (8 * i), 900, al_map_rgb(255, 255, 255));
        if (i == (pointerPos - 1)) {
            al_draw_filled_rectangle(8 * i, 900 - ((9/4) * step[i]), 8 + (8 * i), 900, al_map_rgb(49, 168, 81));
        }
    }

    al_flip_display();
}
