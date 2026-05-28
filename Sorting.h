#ifndef SORTING_H
#define SORTING_H

#include "Visualizer.h"

class SortingVisualizer : public DSAVisualizer {
private:
    void merge(int left, int mid, int right);
    void mergeSortInternal(int left, int right);
    int partition(int low, int high);
    void quickSortInternal(int low, int high);

public:
    void runBubbleSort();
    void runSelectionSort();
    void runInsertionSort();
    void runMergeSort();
    void runQuickSort();
};

#endif