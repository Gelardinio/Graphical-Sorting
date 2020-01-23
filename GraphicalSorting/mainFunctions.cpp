#include <iostream>
#include "mainFunctions.h"
#include <algorithm>
#include "sorting.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <string>
#include <chrono>

//Extern global variables and constants
extern ALLEGRO_DISPLAY *display;
extern ALLEGRO_TIMER *timer;
extern ALLEGRO_EVENT_QUEUE *event_queue;
extern ALLEGRO_FONT *button_font;

extern const int valueCount = 200;

using namespace std::chrono;

//Function that displays a certain instance of the array based on the size and indexis of the induvidual elements
void displaySort(ALLEGRO_FONT *add_font, vector<int> step, int pointerPos, int comparissons, int switches, int time, int memory) {

    //Declare strings that will be displayec on the string
    string compCount;
    string switchCount;
    string compTime;
    string memorys;

    //Set the strings based on variables inputed into the function
    compCount = "Comparisons: " + to_string(comparissons);
    switchCount = "Switches: " + to_string(switches);
    compTime = "Total function calculation time (Microseconds): " + to_string(time);
    memorys = "Total memory: " + to_string(memory);

    //Clear the display
    al_clear_to_color(al_map_rgb(0, 0, 0));

    //Draw the comparisons and other data
    al_draw_text(add_font, al_map_rgb(255, 255, 255), 90, 20, ALLEGRO_ALIGN_CENTER, compCount.c_str());
    al_draw_text(add_font, al_map_rgb(255, 255, 255), 220, 20, ALLEGRO_ALIGN_CENTER, switchCount.c_str());
    al_draw_text(add_font, al_map_rgb(255, 255, 255), 450, 20, ALLEGRO_ALIGN_CENTER, compTime.c_str());
    al_draw_text(add_font, al_map_rgb(255, 255, 255), 690, 20, ALLEGRO_ALIGN_CENTER, memorys.c_str());

    //Draws the induvidual elemnts of the array based on the value fo each element
    for (int i = 0; i < step.size(); i++) {
        //Draws based on index and size
        al_draw_filled_rectangle((1600/valueCount) * i, 900 - ((9/4) * step[i]), (1600/valueCount) + ((1600/valueCount) * i), 900, al_map_rgb(0, (205 * step[i] / 400) + 50, 1));
        //Highlights the inde being moved/compared
        if (i == (pointerPos - 1)) {
            al_draw_filled_rectangle((1600/valueCount) * i, 900 - ((9/4) * step[i]), (1600/valueCount) + ((1600/valueCount) * i), 900, al_map_rgb(221, 55, 240));
        }
    }

    al_flip_display();
}

//Function that displays the binary search
void displaySearch(ALLEGRO_FONT *add_font, vector<int> arr, int leftPos, int midPos, int rightPos, int comparissons, int time, int returnValue) {

    //Declare strings that will be displayec on the string
    string compCount;
    string compTime;
    string found;

    //Check if the index has been found or not
    if(returnValue == -1) {
        found = "Index not found";
    } else {
        found = "Element found at index: " + to_string(returnValue);
    }

    //Display the statistics
    compCount = "Comparisons: " + to_string(comparissons);
    compTime = "Total function calculation time (Microseconds): " + to_string(time);


    al_clear_to_color(al_map_rgb(0, 0, 0));

    //Display the statistics
    al_draw_text(add_font, al_map_rgb(255, 255, 255), 90, 20, ALLEGRO_ALIGN_CENTER, compCount.c_str());
    al_draw_text(add_font, al_map_rgb(255, 255, 255), 320, 20, ALLEGRO_ALIGN_CENTER, compTime.c_str());
    al_draw_text(add_font, al_map_rgb(255, 255, 255), 600, 20, ALLEGRO_ALIGN_CENTER, found.c_str());

    //Colouors the induvidual indexies of the vector based on their size compared to the number that is looked for
    for (int i = 0; i < arr.size(); i++) {
        al_draw_filled_rectangle((1600/valueCount) * i, 900 - ((9/4) * arr[i]), (1600/valueCount) + ((1600/valueCount) * i), 900, al_map_rgb(141, 141, 141));
        if (i >= leftPos && i <= rightPos) {
            al_draw_filled_rectangle((1600/valueCount) * i, 900 - ((9/4) * arr[i]), (1600/valueCount) + ((1600/valueCount) * i), 900, al_map_rgb(10, 241, 6));
        }
        if (i == midPos) {
            al_draw_filled_rectangle((1600/valueCount) * i, 900 - ((9/4) * arr[i]), (1600/valueCount) + ((1600/valueCount) * i), 900, al_map_rgb(221, 55, 240));
        }
    }
}

//Function that takes in keyboard input and adds it to a string
void wordAddInt (string &word) {

    ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, &ev);

    char input;

    //Detect if the number is between 1 and 9 and add to input string
    if (ev.keyboard.keycode >= ALLEGRO_KEY_0 && ev.keyboard.keycode <= ALLEGRO_KEY_9) {
        input = '0' + (ev.keyboard.keycode - ALLEGRO_KEY_0);

    //Detect if the key is a dot to add to floats
    } else if (ev.keyboard.keycode == ALLEGRO_KEY_FULLSTOP) {
        input = '.';
    } else if (ev.keyboard.keycode == ALLEGRO_KEY_BACKSPACE) {
        input = '~';
    }

    //Read in the word length of the string that will be edited
    int wordLength = word.length();

    //Check if there is more than one character so that the delete key can be used
    if (input == '~'){
        if (wordLength > 0) {
            word.erase(wordLength - 1);
        }
    } else {
        word += input;
    }
}

//Default constructer
Button::Button() {

}

//Default deconstructer
Button::~Button() {

}

//Draws a buttom
void Button::drawButton() {
    //Turn button text into a const char
    const char *c = buttonText.c_str();
    al_draw_filled_rounded_rectangle(xPos, yPos, xPos + bWidth, yPos + bHeight, 20, 20, al_map_rgb(180,180,180));
    al_draw_text(button_font, al_map_rgb(0, 0, 0), xPos + (bWidth / 2), yPos + (bHeight / 2) - 20, ALLEGRO_ALIGN_CENTER, c);
}

//Checks if the button has been clicked
bool Button::checkClick(int mouseX, int mouseY) {
    if (mouseX >= xPos && mouseX <= xPos + bWidth && mouseY >= yPos && mouseY <= yPos + bHeight) {
        return true;
    } else {
        return false;
    }
}

//Sets the parameters of a button
void Button::setParameters(int buttonXPos, int buttonYPos, int width, int height, string text) {
    xPos = buttonXPos;
    yPos = buttonYPos;
    bWidth = width;
    bHeight = height;
    buttonText = text;
}

//Displays the menuy and goes to different pages based on user input
char displayMenu(ALLEGRO_FONT *title_font, vector<Button> &menu, vector<int> &arr) {

    //Draw buttons
    al_clear_to_color(al_map_rgb(196, 116, 4));
    al_draw_text(title_font, al_map_rgb(0, 0, 0), 800, 200, ALLEGRO_ALIGN_CENTER, "Sorting");
    menu[0].setParameters(80, 680, 300, 140, "Bubble Sort");
    menu[1].setParameters(460, 680, 300, 140, "Merge Sort");
    menu[2].setParameters(840, 680, 300, 140, "Quick Sort");
    menu[3].setParameters(587, 530, 427, 110, "Get Different Values");
    menu[4].setParameters(1220, 680, 300, 140, "Binary Search");

    menu[0].drawButton();
    menu[1].drawButton();
    menu[2].drawButton();
    menu[3].drawButton();
    menu[4].drawButton();

    al_flip_display();

    int mouse_x;
    int mouse_y;

    while(true) {

        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        //Wait for user to select an option
        if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
            mouse_x = ev.mouse.x;
            mouse_y = ev.mouse.y;

            //Goes into different menus based on user selection
            if(menu[0].checkClick(mouse_x, mouse_y)) {
                al_clear_to_color(al_map_rgb(196, 116, 4));
                return 'a';
                break;
            } else if(menu[1].checkClick(mouse_x, mouse_y)) {
                al_clear_to_color(al_map_rgb(196, 116, 4));
                return 'b';
                break;
            } else if(menu[2].checkClick(mouse_x, mouse_y)) {
                al_clear_to_color(al_map_rgb(196, 116, 4));
                return 'c';
                break;
            } else if(menu[4].checkClick(mouse_x, mouse_y)) {
                al_clear_to_color(al_map_rgb(196, 116, 4));
                return 'd';
                break;
            }

            //Check if the user wants to rerandomize the values
            if(menu[3].checkClick(mouse_x,mouse_y)) {
                arr.erase(arr.begin(), arr.end());
                //Rerandomize values
                for (int i = 0; i < valueCount; i++) {
                    arr.push_back(rand() % 400 + 1);
                }
                menu[3].setParameters(587, 530, 427, 110, "Re-Randomized");
                menu[3].drawButton();
                al_flip_display();
            }
        }
    }
}

//Function that displays the bubble sort
void displayBsort(ALLEGRO_FONT *title_font, vector<int> arr, Button backs) {

    //Vectors that will store instances of the main arr vector
    vector<int> swaps;
    vector<int> comparissons;
    vector<vector<int>> steps;

    backs.setParameters(30, 80, 200, 70, "Back");

    int mouse_x;
    int mouse_y;

    //Start a timer and run the bubble sort algorithm
    auto start = high_resolution_clock::now();
    bubbleSort(arr, steps, comparissons, swaps);
    //Stop the timer and calculate the number of microseconds elapsed
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    //Displays each instance of the array, creating a sort
    for(int i = 0; i < steps.size(); i++) {
        arr = steps[i];
        displaySort(title_font, arr, 999, comparissons[i], swaps[i], duration.count(), 1);
        al_rest(0.00001);
    }

    //Wait for the user to exit
    while(true) {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        //Check if mouse has been clicked
        if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
            mouse_x = ev.mouse.x;
            mouse_y = ev.mouse.y;

            if(backs.checkClick(mouse_x, mouse_y)) {
                break;
            }
        }

        backs.drawButton();
        al_flip_display();
    }
}

//Function that displays the quick sort
void displayQsort(ALLEGRO_FONT *title_font, vector<int> arr, Button backs) {
    //Create an object using class
    QuickSort sort;

    //Vectors that will store instances of the main arr vector
    vector<int> swaps;
    vector<int> comparissons;
    vector<int> pointerPos;
    vector<vector<int>> steps;

    backs.setParameters(30, 80, 200, 70, "Back");

    int mouse_x;
    int mouse_y;

    //Start a timer and run the bubble sort algorithm
    auto start = high_resolution_clock::now();
    sort.quickSort(arr, steps, pointerPos, 0, arr.size(), comparissons, swaps);
    //Stop the timer and calculate the number of microseconds elapsed
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    //Displays each instance of the array, creating a sort
    for (int i = 0; i < steps.size(); i++) {
        displaySort(title_font, steps[i], pointerPos[i], comparissons[i], swaps[i], duration.count(), 1);
        al_rest(0.005);
    }

    //Wait for the user to exit
    while(true) {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        //Check if mouse has been clicked
        if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
            mouse_x = ev.mouse.x;
            mouse_y = ev.mouse.y;

            if(backs.checkClick(mouse_x, mouse_y)) {
                break;
            }
        }

        backs.drawButton();
        al_flip_display();
    }
}

//Function that displays the merge sort
void displayMsort(ALLEGRO_FONT *title_font, vector<int> arr, Button backs) {
    //Declare an object for the class
    MergeSort Merge;

    //Set vectors that will keep track of the array instances during the merge sort
    vector<int> startValues;
    vector<int> midValues;
    vector<vector<int>> steps;
    vector<int> comparisons;
    vector<int> swaps;

    //Set parameters of the back button
    backs.setParameters(30, 80, 200, 70, "Back");

    int mouse_x;
    int mouse_y;

    //Start a timer
    auto start = high_resolution_clock::now();
    //Run merge sort function
    Merge.mergeSort(arr,arr, steps, 0, arr.size() - 1, comparisons, swaps);
    //Stop the timer and get the total time elapsed
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    //Displays each instance of the array, creating a sort
    for (int i = 0; i < steps.size(); i++) {
        displaySort(title_font, steps[i], 999, comparisons[i], swaps[i], duration.count(), arr.size());
        al_rest(0.01);
    }

    //Waits for the user to exit
    while(true) {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        //Check if mouse has been clicked
        if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
            mouse_x = ev.mouse.x;
            mouse_y = ev.mouse.y;

            if(backs.checkClick(mouse_x, mouse_y)) {
                break;
            }
        }

        backs.drawButton();
        al_flip_display();
    }
}

//Displays the binary search
void displayBsearch(ALLEGRO_FONT *title_font, vector<int> arr, Button backs) {

    //Use std sort to sort the array as it is the most efficient
    sort(arr.begin(), arr.end());
    string text;

    int returnValue;

    //Set vectors that will keep track of the array instances during the merge sort
    vector<int> leftPos;
    vector<int> midPos;
    vector<int> rightPos;
    int comparisons = 0;

    int searchNumber = 30;

    Button Input;
    Button Input2;

    //Set parameters for buttons
    backs.setParameters(30, 80, 200, 70, "Back");
    Input2.setParameters(700, 700, 200, 80, "Search");

    int mouse_x;
    int mouse_y;

    //Wait for user to input a number to search for
    while(true) {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        Input.setParameters(700, 800, 200, 80, text);

        //Check if mouse has been clicked
        if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
            mouse_x = ev.mouse.x;
            mouse_y = ev.mouse.y;

            if(backs.checkClick(mouse_x, mouse_y)) {
                return;
            }

            if(Input2.checkClick(mouse_x, mouse_y)) {
                break;
            }
        }

        //Get user input for number being searched for
        if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            wordAddInt(text);
        }

        displaySearch(title_font, arr, 9999,0000, 0000, 0, 0, 0);
        backs.drawButton();
        Input.drawButton();
        Input2.drawButton();
        al_flip_display();
    }

    //Sets the number to be searched as the number inputed
    searchNumber = stoi(text);

    //Start timer
    auto start = high_resolution_clock::now();
    //Run serach algorithm
    returnValue = binarySearch(arr, comparisons, 0, (valueCount - 1), searchNumber, leftPos, midPos, rightPos);
    //Stop timer and calcualte duration passed
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    //Displays each instance of the array, creating a search simuulation
    for (int i = 0; i < leftPos.size(); i++) {
        displaySearch(title_font, arr, leftPos[i], midPos[i], rightPos[i], comparisons, duration.count(), returnValue);
        al_flip_display();
        al_rest(0.5);
    }

    while (true) {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        //Check if mouse has been clicked
        if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
            mouse_x = ev.mouse.x;
            mouse_y = ev.mouse.y;

            if(backs.checkClick(mouse_x, mouse_y)) {
                return;
            }
        }
        backs.drawButton();
        al_flip_display();
    }
}
