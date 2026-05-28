#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <limits>

void wait(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void clearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

class DSAVisualizer {
private:
    std::vector<int> data;
    int size;

public:
    DSAVisualizer() : size(10) {
        std::srand(std::time(0));
        generateRandomArray();
    }

    void generateRandomArray() {
        data.clear();
        for (int i = 0; i < size; ++i) {
            data.push_back(std::rand() % 25 + 5); 
        }
    }

    void setCustomArray(const std::vector<int>& customData) {
        data = customData;
        size = customData.size();
    }

    void setSize(int newSize) {
        if (newSize >= 5 && newSize <= 25) {
            size = newSize;
            generateRandomArray();
        }
    }

    void displayArray(int activeIndex1 = -1, int activeIndex2 = -1, std::string status = "") {
        clearScreen();
        std::cout << "=================== DSA VISUALIZER ===================\n";
        std::cout << "Status: " << status << "\n\n";

        int maxElement = 0;
        for (int val : data) if (val > maxElement) maxElement = val;

        for (int i = maxElement; i > 0; --i) {
            for (int j = 0; j < size; ++j) {
                if (data[j] >= i) {
                    if (j == activeIndex1 || j == activeIndex2) {
                        std::cout << "[#] "; 
                    } else {
                        std::cout << " |  ";
                    }
                } else {
                    std::cout << "    ";
                }
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

    void runBubbleSort() {
        std::cout << "Bubble Sort simulation logic will be added next...\n";
        wait(2000);
    }
};

int getValidatedInput(int min, int max) {
    int choice;
    while (true) {
        std::cout << "Enter your choice (" << min << "-" << max << "): ";
        if (std::cin >> choice && choice >= min && choice <= max) {
            return choice;
        }
        std::cout << "Invalid input. Try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main() {
    DSAVisualizer visualizer;
    bool running = true;

    while (running) {
        clearScreen();
        std::cout << "=========================================\n";
        std::cout << "         DSA VISUALIZER MAIN MENU        \n";
        std::cout << "=========================================\n";
        std::cout << "1. Generate Random Array\n";
        std::cout << "2. Enter Custom Array\n";
        std::cout << "3. Open Sorting/Searching Simulation\n";
        std::cout << "4. Exit\n";
        std::cout << "=========================================\n";

        int choice = getValidatedInput(1, 4);

        switch (choice) {
            case 1: {
                std::cout << "Enter array size (5-25): ";
                int size = getValidatedInput(5, 25);
                visualizer.setSize(size);
                visualizer.displayArray(-1, -1, "New Random Array Generated");
                wait(1500);
                break;
            }
            case 2: {
                std::cout << "Enter size of custom array (5-15): ";
                int size = getValidatedInput(5, 15);
                std::vector<int> customData(size);
                std::cout << "Enter " << size << " numbers between 1 and 30:\n";
                for (int i = 0; i < size; ++i) {
                    customData[i] = getValidatedInput(1, 30);
                }
                visualizer.setCustomArray(customData);
                visualizer.displayArray(-1, -1, "Custom Array Loaded");
                wait(1500);
                break;
            }
            case 3:
                visualizer.runBubbleSort();
                break;
            case 4:
                running = false;
                break;
        }
    }
    return 0;
}
