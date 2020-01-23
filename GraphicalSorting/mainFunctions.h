#include <iostream>
#include "sorting.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

//Function pre declarations
void displaySort(ALLEGRO_FONT *add_font, vector<int> step, int pointerPos, int comparissons, int switches, int time, int memory);
void displaySearch(ALLEGRO_FONT *add_font, vector<int> arr, int leftPos, int midPos, int rightPos, int comparissons, int time, int returnValue);
void wordAddInt (string &word);

//Button class which allows user to make various buttons
class Button {
    public:
        Button();
        ~Button();
        void setParameters(int buttonXPos, int buttonYPos, int width, int height, string text);
        bool checkClick(int mouseX, int mouseY);
        void drawButton();

    private:
        string buttonText;
        int xPos;
        int yPos;
        int bWidth;
        int bHeight;
};

//Displays the menu, allows user to select what they want to do with sorting
char displayMenu(ALLEGRO_FONT *title_font, vector<Button> &menu, vector<int> &arr);

//Displays the bubble sort
void displayBsort(ALLEGRO_FONT *title_font, vector<int> arr, Button backs);

//Displays the quick sort
void displayQsort(ALLEGRO_FONT *title_font, vector<int> arr, Button backs);

//Displays the merge sort
void displayMsort(ALLEGRO_FONT *title_font, vector<int> arr, Button backs);

//Displays the binary search
void displayBsearch(ALLEGRO_FONT *title_font, vector<int> arr, Button backs);


