#include <iostream>
#include "sorting.h"
#include <vector>

using namespace std;

QuickSort::QuickSort() {

}

QuickSort::~QuickSort() {

}

int QuickSort::subdivide(vector<int> &arr, vector<vector<int>> &steps, vector<int> &pointerPos, int start, int end) {
    int pivot = arr[end];
    int compared = start;

    for(int i = start; i < end; i++) {
        if (arr[i] <= pivot) {
            swap(arr[i], arr[compared]);
            compared++;
            steps.push_back(arr);
            pointerPos.push_back(end);
            switches++;
        }
        comparissons++;
    }
    swap(arr[compared], arr[end]);
    return compared;
}

void QuickSort::quickSort(vector<int> &arr, vector<vector<int>> &steps, vector<int> &pointerPos, int start, int end) {

    if(start < end) {
        int position = subdivide(arr, steps, pointerPos, start, end);

        quickSort(arr, steps, pointerPos, start, position - 1);
        quickSort(arr, steps, pointerPos, position + 1, end);
    }
}

