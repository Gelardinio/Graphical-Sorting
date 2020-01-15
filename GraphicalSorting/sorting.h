#pragma once
#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> arr, vector<vector<int>> &steps);

class MergeSort {
    public:
        MergeSort();
        ~MergeSort();
        vector<int> mergeSort(vector<int> values);
        vector<int> sortMerge(vector<int> values1, vector<int> values2);
    private:
        vector<int> arr;
        static vector<vector<int>> steps;
};

class QuickSort {
    public:
        QuickSort();
        ~QuickSort();
        void quickSort(vector<int> &arr, vector<vector<int>> &steps, vector<int> &pointerPos, int start, int end);
        int subdivide(vector<int> &arr, vector<vector<int>> &steps, vector<int> &pointerPos, int start, int end);
    private:
        int switches = 0;
        int comparissons = 0;
        vector<vector<int>> steps;
};
