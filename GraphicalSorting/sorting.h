#pragma once
#include <iostream>
#include <vector>

using namespace std;

//Pre-declaration for the bubble sort
void bubbleSort(vector<int> arr, vector<vector<int>> &steps, vector<int> &comparissons, vector<int> &swaps);

//Class for merge sort
class MergeSort {
    public:
        MergeSort();
        ~MergeSort();
        vector<int> mergeSort(vector<int> values, vector<int> &storeValues, vector<vector<int>> &steps, int elementBegin, int elementEnd, vector<int> &comparissons, vector<int> &swaps);
        vector<int> sortMerge(vector<int> &modifyArr, vector<vector<int>> &steps, vector<int> values1, vector<int> values2, int elementBegin, int elementEnd, vector<int> &comparissons, vector<int> &swaps);
    private:
        int moves = 0;
        int compares = 0;
};

//Class for quick sort
class QuickSort {
    public:
        QuickSort();
        ~QuickSort();
        void quickSort(vector<int> &arr, vector<vector<int>> &steps, vector<int> &pointerPos, int start, int end, vector<int> &comparissons, vector<int> &swaps);
        int subdivide(vector<int> &arr, vector<vector<int>> &steps, vector<int> &pointerPos, int start, int end, vector<int> &comparissons, vector<int> &swaps);
    private:
        int moves = 0;
        int compares = 0;
};

//Pre-declaration for the binary search
int binarySearch(vector<int> arr, int &comparisons, int leftBound, int rightBound, int toSearch, vector<int> &leftPos, vector<int> &midPos, vector<int> &rightPos);
