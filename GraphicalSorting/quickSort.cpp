#include <iostream>
#include "sorting.h"
#include <vector>

using namespace std;

//Constructor
QuickSort::QuickSort() {

}

//De constructor
QuickSort::~QuickSort() {

}

//Part of quick sort partition algorithm that switches elements greater than the partition to one side and the others to the other side
int QuickSort::subdivide(vector<int> &arr, vector<vector<int>> &steps, vector<int> &pointerPos, int start, int ends, vector<int> &comparissons, vector<int> &swaps) {
    //Set the pivot value equal to the last index of the array
    int pivot = arr[ends];
    int compared = start;

    //Compares elements of the array with pivot values
    for(int i = start; i < ends; i++) {
        compares++;
        //Moves an index of the array if it smaller than the pivot value
        if (arr[i] <= pivot) {
            moves++;
            swap(arr[i], arr[compared]);
            compared++;
        }
        //Pushes the steps back to the arrays storing the steps for the draw function
        steps.push_back(arr);
        pointerPos.push_back(ends);
        comparissons.push_back(compares);
        swaps.push_back(moves);
    }
    //Pushes the steps back to the arrays storing the steps for the draw function
    swap(arr[compared], arr[ends]);
    steps.push_back(arr);
    pointerPos.push_back(ends);
    comparissons.push_back(compares);
    swaps.push_back(moves);
    //Returns the final index of the pivot
    return compared;
}

//Recursive section of the quick sort algorithm
void QuickSort::quickSort(vector<int> &arr, vector<vector<int>> &steps, vector<int> &pointerPos, int start, int ends, vector<int> &comparissons, vector<int> &swaps) {
    if(start < ends) {
        //Calls the partition function
        int position = subdivide(arr, steps, pointerPos, start, ends, comparissons, swaps);

        //Quick sorts both arrays on each side of the pivot
        quickSort(arr, steps, pointerPos, start, position - 1, comparissons, swaps);
        quickSort(arr, steps, pointerPos, position + 1, ends, comparissons, swaps);
    }
}
