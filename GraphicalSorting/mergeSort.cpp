#include <iostream>
#include "sorting.h"
#include <vector>

using namespace std;

//Mergesort constructor
MergeSort::MergeSort() {

}

//MergeSort destructor
MergeSort::~MergeSort() {

}

//Recrusive section of merge sort
vector<int> MergeSort::mergeSort(vector<int> values, vector<int> &storeValues, vector<vector<int>> &steps, int elementBegin, int elementEnd, vector<int> &comparissons, vector<int> &swaps) {
    //Returns the index of the vector if its size is one
    if (values.size() < 2){
        return values;
    } else {
        //Finds the middle where the mergesort will split the arrays
        int middle = values.size() / 2;

        //Keep track of the array index start and end positions while in the recursive algorithm
        int start1 = elementBegin;
        int end1 = elementBegin + middle - 1;
        int start2 = elementBegin + middle;
        int end2 = elementEnd;

        //Split a vector into two vectors and fill them with the two halves of the array
        vector<int> vectorOne(values.begin(), values.begin() + middle);
        vector<int> vectorTwo(values.begin() + middle , values.end());
        vectorOne = mergeSort(vectorOne, storeValues, steps, start1, end1, comparissons, swaps);
        vectorTwo = mergeSort(vectorTwo, storeValues, steps, start2, end2, comparissons, swaps);

        //Return the merged vector
        return sortMerge(storeValues, steps, vectorOne, vectorTwo, start1, end2, comparissons, swaps);
    }
}

//Merge sort combination function
vector<int> MergeSort::sortMerge(vector<int> &modifyArr, vector<vector<int>> &steps, vector<int> values1, vector<int> values2, int elementBegin, int elementEnd, vector<int> &comparissons, vector<int> &swaps) {
    //Set a temporary vector equal to the combined vectors
    vector <int> newArr;

    int i = 0;
    int j = 0;
    int k = elementBegin;

    //Combines the two vectors by order
    while (i < (values1.size()) && j < (values2.size())) {
        //Increment the number of comparisons
        compares++;
        //Push back the number of comparisons at a given time to a vector
        comparissons.push_back(compares);
        //Compares to see which value is
        if (values1[i] <= values2[j]) {
            //Push back the array to steps array
            newArr.push_back(values1[i]);
            modifyArr[k] = values1[i];
            steps.push_back(modifyArr);
            swaps.push_back(moves);
            i++;
            //Increment the number of moves
            moves++;
        } else {
            //Push the other elemnt to the new vector as it is the smaller number
            newArr.push_back(values2[j]);
            modifyArr[k] = values2[j];
            steps.push_back(modifyArr);
            swaps.push_back(moves);
            j++;
            moves++;
        }
        k++;
    }

    //Push the remaining values into the new vector
    while (i < (values1.size())){
        moves++;
        newArr.push_back(values1[i]);
        modifyArr[k] = values1[i];
        steps.push_back(modifyArr);
        swaps.push_back(moves);
        comparissons.push_back(compares);
        i++;
        k++;
    }

    //Push the remaining values into the new vector
    while (j < (values2.size())){
        moves++;
        newArr.push_back(values2[j]);
        modifyArr[k] = values2[j];
        steps.push_back(modifyArr);
        swaps.push_back(moves);
        comparissons.push_back(compares);
        j++;
        k++;
    }

    //Return the combined array for recursion
    return newArr;
}
