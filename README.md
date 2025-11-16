# algorithm_analyzer

# 🚀 algorithm_analyzer

A comprehensive C++ algorithm visualization and analysis system that provides real-time visualization of common search and sort algorithms, with advanced performance measurement and comparison features.

---

## 📖 Introduction

**algorithm_analyzer** helps you understand and compare the performance of search and sorting algorithms in C++. With interactive real-time visualization and detailed metrics, it’s an ideal tool for both students and professionals seeking to analyze algorithmic behavior and efficiency.

---

## ✨ Features

- **Real-Time Visualization:**  
  Animates sorting and searching algorithms to illustrate their step-by-step operation.

- **Performance Measurement:**  
  Measures execution time and displays theoretical complexity for each algorithm.

- **Algorithm Comparison:**  
  Easily compare multiple algorithms across different input sizes and types.

- **Extensible Framework:**  
  Plug in your own algorithms for measurement and visualization.

---

## 🛠️ Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/your-username/algorithm_analyzer.git
   ```

2. **Build the project:**
   ```bash
   cd algorithm_analyzer
   g++ -std=c++11 -o analyzer main.cpp
   ```

   > ℹ️ Requirements: C++11 compatible compiler (e.g., GCC, Clang).

---

## 🚦 Usage

1. **Run the analyzer:**
   ```bash
   ./analyzer
   ```

2. **Follow the prompts:**  
   - Select an algorithm (e.g., Bubble Sort, Quick Sort, Binary Search, etc.)
   - Input array size, type, or custom data.
   - View real-time visualization and performance metrics.

3. **Sample code snippet:**
   ```cpp
   // Measuring execution time of Bubble Sort
   AlgorithmVisualizer visualizer;
   visualizer.loadArray({3, 1, 4, 1, 5});
   visualizer.visualizeSort("BubbleSort");
   visualizer.measurePerformance("BubbleSort");
   ```

---

## 🤝 Contributing

Contributions are welcome! Please follow these steps:

1. **Fork the repository**
2. **Create a feature branch**
3. **Commit your changes**
4. **Open a pull request**

Read our [Contributing Guidelines](CONTRIBUTING.md) for details.

---

## 📄 License

This project is licensed under the [MIT License](LICENSE).

---

**Happy Analyzing!** 🎉

## License
This project is licensed under the **MIT** License.

---
🔗 GitHub Repo: https://github.com/Imranch4/algorithm_analyzer
