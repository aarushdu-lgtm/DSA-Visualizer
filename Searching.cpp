#include "Searching.h"
#include <algorithm>
#include <chrono>
#include <limits>
#include <string>

void SearchingVisualizer::runLinearSearch(int target) {
    int steps = 0; bool found = false;
    auto start = std::chrono::high_resolution_clock::now();
    forceClearScreen();
    for (int i = 0; i < size; ++i) {
        steps++;
        displayArray(i, -1, "Linear Search: Checking index " + std::to_string(i), steps, 0); wait(400);
        if (data[i] == target) {
            found = true; displayArray(i, -1, "Linear Search: Target FOUND!", steps, 0); break;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    if (!found) displayArray(-1, -1, "Linear Search: Target NOT found.", steps, 0);
    std::cout << "Execution Time: " << elapsed.count() << " ms | Time Complexity: O(N)\n\nPress Enter...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); std::cin.get();
}

void SearchingVisualizer::runBinarySearch(int target) {
    forceClearScreen();
    displayArray(-1, -1, "Binary Search: Sorting array first..."); wait(1000);
    std::sort(data.begin(), data.end());
    int steps = 0; int low = 0; int high = size - 1; bool found = false;
    auto start = std::chrono::high_resolution_clock::now();
    while (low <= high) {
        steps++; int mid = low + (high - low) / 2;
        displayArray(mid, -1, "Binary Search: Checking midpoint", steps, 0, low, high); wait(500);
        if (data[mid] == target) {
            found = true; displayArray(mid, -1, "Binary Search: Target FOUND!", steps, 0, low, high); break;
        }
        if (data[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    if (!found) displayArray(-1, -1, "Binary Search: Target NOT found.", steps, 0);
    std::cout << "Execution Time: " << elapsed.count() << " ms | Time Complexity: O(log N)\n\nPress Enter...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); std::cin.get();
}