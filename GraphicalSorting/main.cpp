/****************************************************************************
 * Name:    Gerald Liu                                                      *
 * Course:  ICS4U                                                           *
 * Date:    Janurary 22, 2020                                               *
 * File     Graphical Sorting                                               *
 * Release Notes:                                                           *
 1. al_init_font_addon(); cannot be checked if opened due to                *
 different Allegro installation                                             *
 2. Different Allegro installation used. Includes build files               *
 (Removed upon submission)                                                  *
 ****************************************************************************/
//Initializations
#include <iostream>
#include "sorting.h"
#include <vector>
#include <time.h>
#include "allegro.h"
#include "mainFunctions.h"
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>

//Globals
ALLEGRO_DISPLAY *display;
ALLEGRO_TIMER *timer;
ALLEGRO_EVENT_QUEUE *event_queue;
ALLEGRO_FONT *button_font;

//Const global
const int valueCount = 200;

int main() {
    //Call Allegro initiazliation
    initialize_allegro();

    //Declare Fonts
    ALLEGRO_FONT *button_font = al_load_ttf_font("SF_Cartoonist_Hand.ttf", 20, 0);
    ALLEGRO_FONT *title_font = al_load_ttf_font("SF_Cartoonist_Hand.ttf", 300, 0);

    //Declare variables
    vector<int> arr;
    vector<Button> menu(5);
    Button back;

    srand(time(0));

    //Initialize random array
    for (int i = 0; i < valueCount; i++) {
        arr.push_back(rand() % 400 + 1);
    }

    //Switch between different menu selections
    while (true) {
        //Switch between different displays
        char selection = displayMenu(title_font, menu, arr);

        if(selection == 'a') {
            displayBsort(button_font, arr, back);
        } else if(selection == 'c') {
            displayQsort(button_font, arr, back);
        } else if(selection == 'b') {
            displayMsort(button_font, arr, back);
        } else if(selection == 'd') {
            displayBsearch(button_font, arr, back);
        }
    }
}
