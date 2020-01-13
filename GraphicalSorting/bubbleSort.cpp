#include <iostream>
#include "sorting.h"

using namespace std;

void bubbleSort(vector<int> arr, vector<vector<int>> &steps) {
    int comparissons = 0;
    int moves = 0;

    for (int i = 0; i < arr.size() -  1; i++) {
        bool swapped = false;
        for (int j = 0; j < arr.size() - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                moves++;
                swapped = true;
                steps.push_back(arr);
            }
            comparissons++;
        }
        if(swapped == false) {
            break;
        }
    }
}


