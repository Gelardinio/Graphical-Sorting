#include <iostream>
#include "sorting.h"
#include <vector>
#include <time.h>

int main() {

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

}
