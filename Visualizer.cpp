#include "Visualizer.h"
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

DSAVisualizer::DSAVisualizer() : size(10), recursiveComparisons(0), recursiveSwaps(0) {
    std::srand(std::time(0));
    generateRandomArray();
}

void DSAVisualizer::wait(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void DSAVisualizer::clearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::cout << "\033[H";
#endif
}

void DSAVisualizer::forceClearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

void DSAVisualizer::generateRandomArray() {
    data.clear();
    for (int i = 0; i < size; ++i) {
        data.push_back(std::rand() % 25 + 5); 
    }
}

void DSAVisualizer::setCustomArray(const std::vector<int>& customData) {
    data = customData;
    size = customData.size();
}

void DSAVisualizer::setSize(int newSize) {
    if (newSize >= 5 && newSize <= 25) {
        size = newSize;
        generateRandomArray();
    }
}

void DSAVisualizer::displayArray(int active1, int active2, std::string status, int comps, int swaps, int low, int high) {
    clearScreen();
    std::cout << "=================== DSA VISUALIZER ===================\n";
    std::string padStatus = status;
    if(padStatus.length() < 50) padStatus.append(50 - padStatus.length(), ' ');
    std::cout << "Status: " << padStatus << "\n";
    std::cout << "Comparisons/Steps: " << comps << "   |   Swaps: " << swaps << "          \n\n";

    int maxElement = 0;
    for (int val : data) if (val > maxElement) maxElement = val;

    for (int i = maxElement; i > 0; --i) {
        for (int j = 0; j < size; ++j) {
            if (data[j] >= i) {
                if (j == active1 || j == active2) std::cout << "[#] "; 
                else if (low != -1 && high != -1 && (j < low || j > high)) std::cout << " .  "; 
                else std::cout << " |  "; 
            } else std::cout << "    ";
        }
        std::cout << "\n";
    }
    for (int j = 0; j < size; ++j) std::cout << "====";
    std::cout << "\n";
    for (int val : data) {
        if (val < 10) std::cout << " 0" << val << " ";
        else std::cout << " " << val << " ";
    }
    std::cout << "\n\n";
}