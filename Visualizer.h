#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <iostream>
#include <vector>
#include <string>

class DSAVisualizer {
protected:
    std::vector<int> data;
    int size;
    int recursiveComparisons;
    int recursiveSwaps;

public:
    DSAVisualizer();
    void wait(int milliseconds);
    void clearScreen();
    void forceClearScreen();
    void generateRandomArray();
    void setCustomArray(const std::vector<int>& customData);
    void setSize(int newSize);
    void displayArray(int active1 = -1, int active2 = -1, std::string status = "", int comps = 0, int swaps = 0, int low = -1, int high = -1);
};

#endif