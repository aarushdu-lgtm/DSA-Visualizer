#include "Sorting.h"
#include <algorithm>
#include <chrono>
#include <limits>

void SortingVisualizer::runBubbleSort() {
    int comparisons = 0; int swaps = 0;
    auto start = std::chrono::high_resolution_clock::now();
    forceClearScreen();
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            comparisons++;
            displayArray(j, j + 1, "Bubble Sort: Comparing elements", comparisons, swaps); wait(150);
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]); swaps++;
                displayArray(j, j + 1, "Bubble Sort: Swapping elements", comparisons, swaps); wait(150);
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    displayArray(-1, -1, "Bubble Sort Complete!", comparisons, swaps);
    std::cout << "Execution Time: " << elapsed.count() << " ms | Time Complexity: O(N^2)\n\nPress Enter...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); std::cin.get();
}

void SortingVisualizer::runSelectionSort() {
    int comparisons = 0; int swaps = 0;
    auto start = std::chrono::high_resolution_clock::now();
    forceClearScreen();
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            comparisons++;
            displayArray(j, minIndex, "Selection Sort: Finding minimum element", comparisons, swaps); wait(150);
            if (data[j] < data[minIndex]) minIndex = j;
        }
        if (minIndex != i) {
            std::swap(data[i], data[minIndex]); swaps++;
            displayArray(i, minIndex, "Selection Sort: Swapping minimum into place", comparisons, swaps); wait(150);
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    displayArray(-1, -1, "Selection Sort Complete!", comparisons, swaps);
    std::cout << "Execution Time: " << elapsed.count() << " ms | Time Complexity: O(N^2)\n\nPress Enter...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); std::cin.get();
}

void SortingVisualizer::runInsertionSort() {
    int comparisons = 0; int swaps = 0;
    auto start = std::chrono::high_resolution_clock::now();
    forceClearScreen();
    for (int i = 1; i < size; ++i) {
        int key = data[i]; int j = i - 1;
        while (j >= 0) {
            comparisons++;
            displayArray(j, j + 1, "Insertion Sort: Comparing elements", comparisons, swaps); wait(150);
            if (data[j] > key) {
                data[j + 1] = data[j]; swaps++;
                displayArray(j, j + 1, "Insertion Sort: Shifting right", comparisons, swaps); wait(150);
                j--;
            } else break;
        }
        data[j + 1] = key;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    displayArray(-1, -1, "Insertion Sort Complete!", comparisons, swaps);
    std::cout << "Execution Time: " << elapsed.count() << " ms | Time Complexity: O(N^2)\n\nPress Enter...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); std::cin.get();
}

void SortingVisualizer::merge(int left, int mid, int right) {
    int n1 = mid - left + 1; int n2 = right - mid;
    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = data[left + i];
    for (int j = 0; j < n2; j++) R[j] = data[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        recursiveComparisons++;
        displayArray(left + i, mid + 1 + j, "Merge Sort: Merging sub-arrays", recursiveComparisons, recursiveSwaps); wait(150);
        if (L[i] <= R[j]) { data[k] = L[i]; i++; }
        else { data[k] = R[j]; j++; }
        recursiveSwaps++; k++;
    }
    while (i < n1) { data[k] = L[i]; recursiveSwaps++; displayArray(k, -1, "Merge Sort: Clean left sub-array", recursiveComparisons, recursiveSwaps); wait(150); i++; k++; }
    while (j < n2) { data[k] = R[j]; recursiveSwaps++; displayArray(k, -1, "Merge Sort: Clean right sub-array", recursiveComparisons, recursiveSwaps); wait(150); j++; k++; }
}

void SortingVisualizer::mergeSortInternal(int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortInternal(left, mid);
        mergeSortInternal(mid + 1, right);
        merge(left, mid, right);
    }
}

void SortingVisualizer::runMergeSort() {
    recursiveComparisons = 0; recursiveSwaps = 0;
    auto start = std::chrono::high_resolution_clock::now();
    forceClearScreen();
    mergeSortInternal(0, size - 1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    displayArray(-1, -1, "Merge Sort Complete!", recursiveComparisons, recursiveSwaps);
    std::cout << "Execution Time: " << elapsed.count() << " ms | Time Complexity: O(N log N)\n\nPress Enter...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); std::cin.get();
}

int SortingVisualizer::partition(int low, int high) {
    int pivot = data[high]; int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        recursiveComparisons++;
        displayArray(j, high, "Quick Sort: Comparing to Pivot", recursiveComparisons, recursiveSwaps); wait(150);
        if (data[j] < pivot) {
            i++; std::swap(data[i], data[j]); recursiveSwaps++;
            displayArray(i, j, "Quick Sort: Swapping element", recursiveComparisons, recursiveSwaps); wait(150);
        }
    }
    std::swap(data[i + 1], data[high]); recursiveSwaps++;
    displayArray(i + 1, high, "Quick Sort: Placing Pivot", recursiveComparisons, recursiveSwaps); wait(150);
    return (i + 1);
}

void SortingVisualizer::quickSortInternal(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        quickSortInternal(low, pi - 1);
        quickSortInternal(pi + 1, high);
    }
}

void SortingVisualizer::runQuickSort() {
    recursiveComparisons = 0; recursiveSwaps = 0;
    auto start = std::chrono::high_resolution_clock::now();
    forceClearScreen();
    quickSortInternal(0, size - 1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    displayArray(-1, -1, "Quick Sort Complete!", recursiveComparisons, recursiveSwaps);
    std::cout << "Execution Time: " << elapsed.count() << " ms | Time Complexity: O(N log N)\n\nPress Enter...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); std::cin.get();
}