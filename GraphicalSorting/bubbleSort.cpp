#include <iostream>
#include "sorting.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

using namespace std;

extern ALLEGRO_FONT *button_font;
extern ALLEGRO_EVENT_QUEUE *event_queue;
extern ALLEGRO_DISPLAY *display;

//Bubblesort function
void bubbleSort(vector<int> arr, vector<vector<int>> &steps, vector<int> &comparissons, vector<int> &swaps) {
    //Declare comparison count and moves
    int compares = 0;
    int moves = 0;

    //Runs through the array and compares the elements. Swaps and runs again until aray is sorted
    for (int i = 0; i < arr.size() -  1; i++) {
        bool swapped = false;
        for (int j = 0; j < arr.size() - 1; j++) {
            compares++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                moves++;
                swapped = true;
                steps.push_back(arr);
                comparissons.push_back(compares);
                swaps.push_back(moves);
            }
        }
        //Check if the array is sorted
        if(!swapped) {
            break;
        }
    }
}

