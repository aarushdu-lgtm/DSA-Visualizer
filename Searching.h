#ifndef SEARCHING_H
#define SEARCHING_H

#include "Sorting.h"

class SearchingVisualizer : public SortingVisualizer {
public:
    void runLinearSearch(int target);
    void runBinarySearch(int target);
};

#endif