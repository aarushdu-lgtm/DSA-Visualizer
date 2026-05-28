# 📊 Advanced Data Structures & Algorithms (DSA) Visualizer

A robust, cross-platform console application built using Standard Object-Oriented C++ to step-by-step visualize fundamental sorting and searching algorithms. This project utilizes an adaptive textual bar-graph engine to render memory configurations instantly inside the terminal workspace.

---

## 🚀 Key Features

* **Modular Architecture:** Structured across clear header (`.h`) and implementation (`.cpp`) files to ensure high code quality, reusability, and maintainability.
* **Interactive Data Modes:** Allows generation of fully randomized arrays (with user-defined constraints) or ingestion of custom, hardcoded array elements.
* **Real-Time Operational Analytics:** Tracks and displays true step comparisons, element swaps/shifts, current state loops, and high-accuracy runtime processing metrics using `std::chrono`.
* **Zero-Flicker Graphics:** Engineered with smooth ANSI escape-sequence overrides (`\033[H`) to deliver fluid, seamless text animations on any web-based or native Unix console.
* **Input-Validation Engine:** Protected globally by defensive data-trap loops that automatically isolate incorrect keystrokes or overflow numbers.

---

## 🛠️ Algorithms Implemented

### 1. Sorting Suite
* **Bubble Sort:** Stable, elementary array exchange sort tracking adjacent evaluations — $O(N^2)$ Complexity.
* **Selection Sort:** Linear scan algorithm parsing remaining unsorted windows for absolute minima — $O(N^2)$ Complexity.
* **Insertion Sort:** Adaptive processing mechanism injecting items step-by-step into pre-evaluated sub-vectors — $O(N^2)$ Complexity.
* **Merge Sort:** Advanced recursive divide-and-conquer strategy managing stable sub-array unions — $O(N \log N)$ Complexity.
* **Quick Sort:** High-performance unstable recursion utilizing rightmost element pivot partitioning — $O(N \log N)$ Complexity.

### 2. Searching Suite
* **Linear Search:** Simple sequential index traversal checking arrays element-by-element — $O(N)$ Complexity.
* **Binary Search:** High-efficiency logarithmic bounds-shrinking lookup. *(Enforces a Quick-Sort precondition automatically prior to initiation)* — $O(\log N)$ Complexity.

---

## 📁 Repository File Structure

```text
├── main.cpp            # Application Entry Point, Main Loop & Menu Handler
├── Visualizer.h        # Base Class definitions for Data Storage & Rendering
├── Visualizer.cpp      # Implementation of Core Engine & Graphic Bars Pipeline
├── Sorting.h           # Derived Class definitions for the 5 Sorting Algorithms
├── Sorting.cpp         # Complete Implementation of Sorting Animations
├── Searching.h         # Derived Class definitions for Searching Algorithms
├── Searching.cpp       # Complete Implementation of Searching Logic
└── README.md           # Project Documentation & Specifications
```

---

## ⚙️ Technologies Used

* **Language Standard:** C++11 / C++14 / C++17 (Standard C++)
* **Standard Template Library (STL):** `std::vector`, `std::string`, `std::chrono`, `std::thread`, `std::algorithm`
* **Programming Concept:** Object-Oriented Programming (OOP), Inheritance, Polymorphism, Encapsulation

---

## 🏃 Steps to Run the Project

Since the architecture is cleanly split into individual files, you can compile it natively on your machine or run it instantly using any multi-file browser environment:

### Method A: Running Online (Quickest)
1. Head over to [OnlineGDB's C++ Compiler](https://onlinegdb.com).
2. Click the **"New File"** icon (little page symbol with a plus sign) located on the top bar of the code editor.
3. Create all corresponding header (`.h`) and source (`.cpp`) files matching the **Repository File Structure** list above.
4. Copy the matching code sections from this repository into each tab.
5. Click the green **Run** button to begin executing the application!

### Method B: Native Compilation (Command Line)
If compiling locally on your machine via standard terminal inputs, navigate to your directory and run:
```bash
g++ -std=c++11 main.cpp Visualizer.cpp Sorting.cpp Searching.cpp -o dsa_visualizer
./dsa_visualizer
```

---

## 📸 Sample Output Screenshots

### 1. Main Menu
<img width="1514" height="413" alt="image" src="https://github.com/user-attachments/assets/a9d99092-f0dc-497a-bf7a-3aff0b1eecb4" />


### 2. Sorting Animation in Progress
<img width="1512" height="899" alt="image" src="https://github.com/user-attachments/assets/28f4f2aa-d44d-408b-9b69-4a5401b40e48" />


### 3. Searching Match Found
<img width="1514" height="848" alt="image" src="https://github.com/user-attachments/assets/263574c2-461b-4cdb-81ac-05d3845cc549" />

