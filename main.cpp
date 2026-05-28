#include <iostream>
#include <vector>
#include <limits>
#include "Searching.h"

int getValidatedInput(int min, int max) {
    int choice;
    while (true) {
        std::cout << "Enter your choice (" << min << "-" << max << "): ";
        if (std::cin >> choice && choice >= min && choice <= max) return choice;
        std::cout << "Invalid input. Try again.\n";
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main() {
    SearchingVisualizer visualizer;
    bool running = true;
    while (running) {
        visualizer.forceClearScreen();
        std::cout << "=========================================\n";
        std::cout << "         DSA VISUALIZER MAIN MENU        \n";
        std::cout << "=========================================\n";
        std::cout << "1. Generate Random Array\n";
        std::cout << "2. Enter Custom Array\n";
        std::cout << "3. Run Bubble Sort\n";
        std::cout << "4. Run Selection Sort\n";
        std::cout << "5. Run Insertion Sort\n";
        std::cout << "6. Run Merge Sort\n";
        std::cout << "7. Run Quick Sort\n";
        std::cout << "8. Run Linear Search\n";
        std::cout << "9. Run Binary Search\n";
        std::cout << "10. Exit\n";
        std::cout << "=========================================\n";

        int choice = getValidatedInput(1, 10);
        switch (choice) {
            case 1: {
                std::cout << "Enter array size (5-25): "; int size = getValidatedInput(5, 25);
                visualizer.setSize(size); 
                visualizer.forceClearScreen();
                visualizer.displayArray(-1, -1, "New Random Array Generated"); visualizer.wait(1000); break;
            }
            case 2: {
                std::cout << "Enter size of custom array (5-15): "; int size = getValidatedInput(5, 15);
                std::vector<int> customData(size);
                std::cout << "Enter " << size << " numbers between 1 and 30:\n";
                for (int i = 0; i < size; ++i) customData[i] = getValidatedInput(1, 30);
                visualizer.setCustomArray(customData); 
                visualizer.forceClearScreen();
                visualizer.displayArray(-1, -1, "Custom Array Loaded"); visualizer.wait(1000); break;
            }
            case 3: visualizer.runBubbleSort(); break;
            case 4: visualizer.runSelectionSort(); break;
            case 5: visualizer.runInsertionSort(); break;
            case 6: visualizer.runMergeSort(); break;
            case 7: visualizer.runQuickSort(); break;
            case 8: {
                std::cout << "Enter target number to search (1-30): "; int target = getValidatedInput(1, 30);
                visualizer.runLinearSearch(target); break;
            }
            case 9: {
                std::cout << "Enter target number to search (1-30): "; int target = getValidatedInput(1, 30);
                visualizer.runBinarySearch(target); break;
            }
            case 10: running = false; break;
        }
    }
    return 0;
}