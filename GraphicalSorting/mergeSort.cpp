#include <iostream>
#include "sorting.h"
#include <vector>

using namespace std;

MergeSort::MergeSort() {

}

MergeSort::~MergeSort() {

}

vector<int> MergeSort::mergeSort(vector<int> values) {
    if (values.size() < 2){
        return values;
    } else {
        int middle = values.size() / 2;

        vector<int> vectorOne(values.begin(), values.begin() + middle);
        vector<int> vectorTwo(values.begin() + middle , values.end());
        vectorOne = mergeSort(vectorOne);
        vectorTwo = mergeSort(vectorTwo);

        return sortMerge(vectorOne, vectorTwo);
    }
}

vector<int> MergeSort::sortMerge(vector<int> values1, vector<int> values2) {
    vector <int> newArr;

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < (values1.size()) && j < (values2.size())) {
        if (values1[i] <= values2[j]) {
            newArr.push_back(values1[i]);
            i++;
        } else {
            newArr.push_back(values2[j]);
            j++;
        }
    }

    while (i < (values1.size())){
        newArr.push_back(values1[i]);
        i++;
    }

    while (j < (values2.size())){
        newArr.push_back(values2[j]);
        j++;
    }

    return newArr;
}
