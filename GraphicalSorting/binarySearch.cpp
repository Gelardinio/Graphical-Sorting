#include <iostream>
#include "sorting.h"

//Binary search function
int binarySearch(vector<int> arr, int &comparisons, int leftBound, int rightBound, int toSearch, vector<int> &leftPos, vector<int> &midPos, vector<int> &rightPos) {
    //Check if the right bound is greater or equal than the leftbound so that the function can continue
    if (rightBound  >= leftBound) {
        int middle = (leftBound + rightBound) / 2;

        //Push back the different bounds so that the array can be graphically displayed
        leftPos.push_back(leftBound);
        midPos.push_back(middle);
        rightPos.push_back(rightBound);

        //Check if the index is equal to the value of the value being searched for
        if (arr[middle] == toSearch) {
            //Push back for grphical displaying
            leftPos.pop_back();
            rightPos.pop_back();
            leftPos.push_back(-1);
            rightPos.push_back(-1);
            comparisons++;
            return middle;
        }else if (arr[middle] > toSearch) {
            //Search the right side
            comparisons++;
            return binarySearch(arr, comparisons, leftBound, middle - 1, toSearch, leftPos, midPos, rightPos);
        } else if (arr[middle] < toSearch) {
            //Search the left side
            comparisons++;
            return binarySearch(arr, comparisons, middle + 1, rightBound, toSearch, leftPos, midPos, rightPos);
        }
    }
    //Push back for grphical displaying
    midPos.pop_back();
    leftPos.pop_back();
    rightPos.pop_back();
    leftPos.push_back(-1);
    rightPos.push_back(-1);
    midPos.push_back(99999);
    return -1;
}
