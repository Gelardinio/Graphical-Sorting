/****************************************************************************
 * Name:    Gerald Liu                                                      *
 * Course:  ICS4U                                                           *
 * Date:    October 9, 2019                                                 *
 * File     IMDb Assignment                                                 *
 * Release Notes:                                                           *
 1. al_init_font_addon(); cannot be checked if opened due to                *
 different Allegro installation                                             *
 2. Different Allegro installation used. Includes build files               *
 (Removed upon submission)                                                  *
 ****************************************************************************/

#include <iostream>
#include "sorting.h"
#include <vector>
#include <time.h>
#include "allegro.h"
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>

ALLEGRO_DISPLAY *display;
ALLEGRO_TIMER *timer;
ALLEGRO_EVENT_QUEUE *event_queue;
ALLEGRO_FONT *button_font;

int main() {
    initialize_allegro();

    vector<int> arr;
    vector<vector<int>> steps;

    srand(time(0));

    for (int i = 0; i < 10; i++) {
        arr.push_back(rand() % 400 + 1);
    }

    bubbleSort(arr, steps);

    for(int i = 0; i < steps.size(); i++) {
        for (int j = 0; j <arr.size(); j++) {
            cout << steps[i][j] << " ";
        }
        cout << endl;
    }

    while (true) {

    }

}
