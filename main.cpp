#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <memory>
#include <random>

using namespace std;

class AlgorithmVisualizer {
private:
    vector<int> originalArray;
    vector<int> currentArray;
    vector<double> algorithmTimes;
    
    // Algorithm names for display
    const vector<string> algorithmNames = {
        "Linear Search", "Binary Search", "Bubble Sort", 
        "Merge Sort", "Quick Sort", "Selection Sort", "Insertion Sort"
    };

public:
    AlgorithmVisualizer() = default;
    
    void setArray(const vector<int>& arr) {
        originalArray = arr;
        currentArray = arr;
    }
    
    void resetArray() {
        currentArray = originalArray;
    }
    
    void displayArray(const vector<int>& arr, const string& label = "") const {
        if (!label.empty()) {
            cout << label << ": ";
        }
        cout << "[";
        for (size_t i = 0; i < arr.size(); ++i) {
            cout << arr[i];
            if (i < arr.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    
    void displayArrayWithHighlight(const vector<int>& arr, int highlightIndex = -1, const string& label = "") const {
        if (!label.empty()) {
            cout << label << ": ";
        }
        cout << "[";
        for (size_t i = 0; i < arr.size(); ++i) {
            if (static_cast<int>(i) == highlightIndex) {
                cout << ">" << arr[i] << "<";
            } else {
                cout << arr[i];
            }
            if (i < arr.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    
    void delay(int ms) const {
        clock_t start_time = clock();
        while (clock() < start_time + ms * (CLOCKS_PER_SEC / 1000));
    }
    
    // Enhanced Linear Search with step-by-step visualization
    int linearSearch(int target, bool verbose = true) {
        resetArray();
        if (verbose) {
            cout << "\n--- Linear Search Process ---" << endl;
            cout << "Searching for: " << target << endl;
        }
        
        clock_t start = clock();
        
        for (size_t i = 0; i < currentArray.size(); ++i) {
            if (verbose) {
                displayArrayWithHighlight(currentArray, i, "Step " + to_string(i + 1));
                delay(500);
            }
            
            if (currentArray[i] == target) {
                clock_t end = clock();
                double timeTaken = double(end - start) / CLOCKS_PER_SEC;
                algorithmTimes[0] = timeTaken;
                
                if (verbose) {
                    cout << "✓ Found at index: " << i << endl;
                    cout << "Time taken: " << fixed << setprecision(6) << timeTaken << " seconds" << endl;
                }
                return i;
            }
        }
        
        clock_t end = clock();
        double timeTaken = double(end - start) / CLOCKS_PER_SEC;
        algorithmTimes[0] = timeTaken;
        
        if (verbose) {
            cout << "✗ Element not found" << endl;
            cout << "Time taken: " << fixed << setprecision(6) << timeTaken << " seconds" << endl;
        }
        return -1;
    }
    
    // Enhanced Binary Search
    int binarySearch(int target, bool verbose = true) {
        resetArray();
        vector<int> sortedArray = currentArray;
        sort(sortedArray.begin(), sortedArray.end());
        
        if (verbose) {
            cout << "\n--- Binary Search Process ---" << endl;
            cout << "Searching for: " << target << endl;
            cout << "Sorted array: ";
            displayArray(sortedArray);
        }
        
        clock_t start = clock();
        int left = 0, right = sortedArray.size() - 1;
        int step = 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (verbose) {
                cout << "\nStep " << step++ << ":" << endl;
                cout << "Search range: indices " << left << " to " << right << endl;
                cout << "Middle index: " << mid << " → Value: " << sortedArray[mid] << endl;
                delay(500);
            }
            
            if (sortedArray[mid] == target) {
                clock_t end = clock();
                double timeTaken = double(end - start) / CLOCKS_PER_SEC;
                algorithmTimes[1] = timeTaken;
                
                if (verbose) {
                    cout << "✓ Found at index: " << mid << endl;
                    cout << "Time taken: " << fixed << setprecision(6) << timeTaken << " seconds" << endl;
                }
                return mid;
            }
            else if (sortedArray[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        clock_t end = clock();
        double timeTaken = double(end - start) / CLOCKS_PER_SEC;
        algorithmTimes[1] = timeTaken;
        
        if (verbose) {
            cout << "✗ Element not found" << endl;
            cout << "Time taken: " << fixed << setprecision(6) << timeTaken << " seconds" << endl;
        }
        return -1;
    }
    
    // Enhanced Bubble Sort with optimization
    void bubbleSort(bool verbose = true) {
        resetArray();
        if (verbose) {
            cout << "\n--- Bubble Sort Process ---" << endl;
            displayArray(currentArray, "Original array");
        }
        
        clock_t start = clock();
        bool swapped;
        int pass = 1;
        
        for (size_t i = 0; i < currentArray.size() - 1; ++i) {
            swapped = false;
            
            if (verbose) {
                cout << "\n--- Pass " << pass++ << " ---" << endl;
            }
            
            for (size_t j = 0; j < currentArray.size() - i - 1; ++j) {
                if (currentArray[j] > currentArray[j + 1]) {
                    swap(currentArray[j], currentArray[j + 1]);
                    swapped = true;
                    
                    if (verbose) {
                        displayArrayWithHighlight(currentArray, j, "Swapped " + to_string(j) + " and " + to_string(j + 1));
                        delay(300);
                    }
                }
            }
            
            if (!swapped) break; // Optimization: stop if no swaps occurred
        }
        
        clock_t end = clock();
        double timeTaken = double(end - start) / CLOCKS_PER_SEC;
        algorithmTimes[2] = timeTaken;
        
        if (verbose) {
            cout << "\n✓ Sorting completed!" << endl;
            displayArray(currentArray, "Sorted array");
            cout << "Time taken: " << fixed << setprecision(6) << timeTaken << " seconds" << endl;
        }
    }
    
    // Enhanced Selection Sort
    void selectionSort(bool verbose = true) {
        resetArray();
        if (verbose) {
            cout << "\n--- Selection Sort Process ---" << endl;
            displayArray(currentArray, "Original array");
        }
        
        clock_t start = clock();
        
        for (size_t i = 0; i < currentArray.size() - 1; ++i) {
            size_t minIdx = i;
            
            if (verbose) {
                cout << "\n--- Iteration " << i + 1 << " ---" << endl;
                cout << "Finding minimum from index " << i << " to " << currentArray.size() - 1 << endl;
            }
            
            for (size_t j = i + 1; j < currentArray.size(); ++j) {
                if (currentArray[j] < currentArray[minIdx]) {
                    minIdx = j;
                }
            }
            
            if (minIdx != i) {
                swap(currentArray[i], currentArray[minIdx]);
                
                if (verbose) {
                    cout << "Minimum found at index " << minIdx << " → " << currentArray[i] << endl;
                    displayArrayWithHighlight(currentArray, i, "Placed minimum at position " + to_string(i));
                    delay(300);
                }
            }
        }
        
        clock_t end = clock();
        double timeTaken = double(end - start) / CLOCKS_PER_SEC;
        algorithmTimes[5] = timeTaken;
        
        if (verbose) {
            cout << "\n✓ Sorting completed!" << endl;
            displayArray(currentArray, "Sorted array");
            cout << "Time taken: " << fixed << setprecision(6) << timeTaken << " seconds" << endl;
        }
    }
    
    // Enhanced Insertion Sort
    void insertionSort(bool verbose = true) {
        resetArray();
        if (verbose) {
            cout << "\n--- Insertion Sort Process ---" << endl;
            displayArray(currentArray, "Original array");
        }
        
        clock_t start = clock();
        
        for (size_t i = 1; i < currentArray.size(); ++i) {
            int key = currentArray[i];
            int j = i - 1;
            
            if (verbose) {
                cout << "\nInserting element " << key << " at position " << i << endl;
            }
            
            while (j >= 0 && currentArray[j] > key) {
                currentArray[j + 1] = currentArray[j];
                --j;
                
                if (verbose) {
                    displayArrayWithHighlight(currentArray, j + 1, "Shifting");
                    delay(300);
                }
            }
            currentArray[j + 1] = key;
            
            if (verbose) {
                displayArrayWithHighlight(currentArray, j + 1, "Inserted " + to_string(key));
                delay(300);
            }
        }
        
        clock_t end = clock();
        double timeTaken = double(end - start) / CLOCKS_PER_SEC;
        algorithmTimes[6] = timeTaken;
        
        if (verbose) {
            cout << "\n✓ Sorting completed!" << endl;
            displayArray(currentArray, "Sorted array");
            cout << "Time taken: " << fixed << setprecision(6) << timeTaken << " seconds" << endl;
        }
    }
    
    // Quick Sort implementation
    void quickSort(bool verbose = true) {
        resetArray();
        if (verbose) {
            cout << "\n--- Quick Sort Process ---" << endl;
            displayArray(currentArray, "Original array");
        }
        
        clock_t start = clock();
        quickSortHelper(0, currentArray.size() - 1, verbose);
        clock_t end = clock();
        
        double timeTaken = double(end - start) / CLOCKS_PER_SEC;
        algorithmTimes[4] = timeTaken;
        
        if (verbose) {
            cout << "\n✓ Sorting completed!" << endl;
            displayArray(currentArray, "Sorted array");
            cout << "Time taken: " << fixed << setprecision(6) << timeTaken << " seconds" << endl;
        }
    }
    
private:
    void quickSortHelper(int low, int high, bool verbose) {
        if (low < high) {
            int pi = partition(low, high, verbose);
            quickSortHelper(low, pi - 1, verbose);
            quickSortHelper(pi + 1, high, verbose);
        }
    }
    
    int partition(int low, int high, bool verbose) {
        int pivot = currentArray[high];
        int i = low - 1;
        
        if (verbose) {
            cout << "\nPartitioning from " << low << " to " << high << " with pivot " << pivot << endl;
        }
        
        for (int j = low; j < high; ++j) {
            if (currentArray[j] < pivot) {
                ++i;
                swap(currentArray[i], currentArray[j]);
                
                if (verbose) {
                    displayArrayWithHighlight(currentArray, i, "Swapped");
                    delay(200);
                }
            }
        }
        swap(currentArray[i + 1], currentArray[high]);
        
        if (verbose) {
            displayArrayWithHighlight(currentArray, i + 1, "Final pivot position");
            delay(200);
        }
        
        return i + 1;
    }
    
public:
    // Merge Sort implementation
    void mergeSort(bool verbose = true) {
        resetArray();
        if (verbose) {
            cout << "\n--- Merge Sort Process ---" << endl;
            displayArray(currentArray, "Original array");
        }
        
        clock_t start = clock();
        mergeSortHelper(0, currentArray.size() - 1, verbose);
        clock_t end = clock();
        
        double timeTaken = double(end - start) / CLOCKS_PER_SEC;
        algorithmTimes[3] = timeTaken;
        
        if (verbose) {
            cout << "\n✓ Sorting completed!" << endl;
            displayArray(currentArray, "Sorted array");
            cout << "Time taken: " << fixed << setprecision(6) << timeTaken << " seconds" << endl;
        }
    }
    
private:
    void mergeSortHelper(int left, int right, bool verbose) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            
            if (verbose) {
                cout << "\nDividing: [" << left << " - " << mid << "] and [" << (mid + 1) << " - " << right << "]" << endl;
            }
            
            mergeSortHelper(left, mid, verbose);
            mergeSortHelper(mid + 1, right, verbose);
            merge(left, mid, right, verbose);
        }
    }
    
    void merge(int left, int mid, int right, bool verbose) {
        if (verbose) {
            cout << "Merging: [" << left << " - " << mid << "] and [" << (mid + 1) << " - " << right << "]" << endl;
        }
        
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        vector<int> L(n1), R(n2);
        
        for (int i = 0; i < n1; ++i) L[i] = currentArray[left + i];
        for (int j = 0; j < n2; ++j) R[j] = currentArray[mid + 1 + j];
        
        int i = 0, j = 0, k = left;
        
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                currentArray[k++] = L[i++];
            } else {
                currentArray[k++] = R[j++];
            }
        }
        
        while (i < n1) currentArray[k++] = L[i++];
        while (j < n2) currentArray[k++] = R[j++];
        
        if (verbose) {
            displayArrayWithHighlight(currentArray, -1, "After merge");
            delay(300);
        }
    }
    
public:
    // Performance comparison feature
    void compareAlgorithms() {
        cout << "\n=== ALGORITHM PERFORMANCE COMPARISON ===" << endl;
        displayArray(originalArray, "Test Array");
        cout << endl;
        
        // Initialize times
        algorithmTimes.resize(7, 0.0);
        
        // Test each algorithm
        linearSearch(originalArray[0], false);
        binarySearch(originalArray[0], false);
        bubbleSort(false);
        mergeSort(false);
        quickSort(false);
        selectionSort(false);
        insertionSort(false);
        
        // Display results
        cout << "┌──────────────────────┬──────────────────┐" << endl;
        cout << "│     Algorithm        │    Time (sec)    │" << endl;
        cout << "├──────────────────────┼──────────────────┤" << endl;
        
        double minTime = *min_element(algorithmTimes.begin(), algorithmTimes.end());
        
        for (size_t i = 0; i < algorithmNames.size(); ++i) {
            cout << "│ " << setw(20) << left << algorithmNames[i] << " │ " 
                 << setw(12) << right << fixed << setprecision(6) << algorithmTimes[i];
            if (algorithmTimes[i] == minTime) {
                cout << " ⭐ │" << endl;
            } else {
                cout << "   │" << endl;
            }
        }
        cout << "└──────────────────────┴──────────────────┘" << endl;
        
        // Find fastest algorithm
        auto minIt = min_element(algorithmTimes.begin(), algorithmTimes.end());
        int fastestIndex = distance(algorithmTimes.begin(), minIt);
        
        cout << "\n🏆 Fastest Algorithm: " << algorithmNames[fastestIndex] 
             << " (" << fixed << setprecision(6) << *minIt << " seconds)" << endl;
    }
    
    // Generate random array
    vector<int> generateRandomArray(int size, int minVal = 1, int maxVal = 100) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(minVal, maxVal);
        
        vector<int> randomArray(size);
        for (int i = 0; i < size; ++i) {
            randomArray[i] = dis(gen);
        }
        return randomArray;
    }
};

class MenuSystem {
private:
    AlgorithmVisualizer visualizer;
    
public:
    void displayMainMenu() {
        cout << "\n==========================================" << endl;
        cout << "      ALGORITHM VISUALIZER & ANALYZER" << endl;
        cout << "==========================================" << endl;
        cout << "1. Linear Search" << endl;
        cout << "2. Binary Search" << endl;
        cout << "3. Bubble Sort" << endl;
        cout << "4. Merge Sort" << endl;
        cout << "5. Quick Sort" << endl;
        cout << "6. Selection Sort" << endl;
        cout << "7. Insertion Sort" << endl;
        cout << "8. Compare All Algorithms" << endl;
        cout << "9. Generate Random Array" << endl;
        cout << "0. Exit" << endl;
        cout << "==========================================" << endl;
        cout << "Enter your choice (0-9): ";
    }
    
    void run() {
        vector<int> currentArray;
        int choice;
        
        do {
            displayMainMenu();
            cin >> choice;
            
            if (choice >= 1 && choice <= 8 && currentArray.empty()) {
                cout << "No array data! Please generate or enter an array first (option 9)." << endl;
                continue;
            }
            
            switch (choice) {
                case 1: {
                    int target;
                    cout << "Enter target value to search: ";
                    cin >> target;
                    visualizer.linearSearch(target);
                    break;
                }
                case 2: {
                    int target;
                    cout << "Enter target value to search: ";
                    cin >> target;
                    visualizer.binarySearch(target);
                    break;
                }
                case 3:
                    visualizer.bubbleSort();
                    break;
                case 4:
                    visualizer.mergeSort();
                    break;
                case 5:
                    visualizer.quickSort();
                    break;
                case 6:
                    visualizer.selectionSort();
                    break;
                case 7:
                    visualizer.insertionSort();
                    break;
                case 8:
                    visualizer.compareAlgorithms();
                    break;
                case 9:
                    handleArrayInput();
                    break;
                case 0:
                    cout << "Thank you for using Algorithm Visualizer!" << endl;
                    break;
                default:
                    cout << "Invalid choice! Please try again." << endl;
            }
            
            if (choice != 0) {
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
            }
            
        } while (choice != 0);
    }
    
private:
    void handleArrayInput() {
        cout << "\n=== ARRAY INPUT OPTIONS ===" << endl;
        cout << "1. Generate random array" << endl;
        cout << "2. Enter array manually" << endl;
        cout << "Choose option: ";
        
        int option;
        cin >> option;
        
        vector<int> array;
        
        if (option == 1) {
            int size;
            cout << "Enter array size: ";
            cin >> size;
            array = visualizer.generateRandomArray(size);
        } else if (option == 2) {
            int size;
            cout << "Enter array size: ";
            cin >> size;
            cout << "Enter " << size << " elements separated by spaces: ";
            array.resize(size);
            for (int i = 0; i < size; ++i) {
                cin >> array[i];
            }
        } else {
            cout << "Invalid option!" << endl;
            return;
        }
        
        visualizer.setArray(array);
        cout << "Array set successfully: ";
        visualizer.displayArray(array);
    }
};

int main() {
    MenuSystem menu;
    menu.run();
    return 0;
}