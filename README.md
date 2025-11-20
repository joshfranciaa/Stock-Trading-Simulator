# 📈 Stock Trading Simulator  
A C++ simulation that models daily stock trading using a custom priority queue, dynamic price updates, portfolio tracking, and file-driven simulation. This project demonstrates data structures, OOP design, algorithmic trading logic, and clean, modular software design.

---

## 🎥 Demo Video  
Click below to watch the full demonstration:

[▶️ **Watch the Demo**](https://github.com/joshfranciaa/Stock-Trading-Simulator/raw/refs/heads/main/Stock%20Trading%20Simulator%20Demo%20Video.mov)

*(Video handled through Git LFS to support large file size.)*

---

## 🚀 Features  
- Automatic stock-buying logic based on lowest price  
- Daily price updates with gain/loss tracking  
- Priority-based stock selection using a **custom min-heap**  
- Tracks:
  - Stock name  
  - Daily price movement  
  - Purchase price  
  - Total spending and remaining funds  
- File-driven simulation  
- Clean separation of logic through classes and data structures  

---

## 🛠 Technologies Used  
- **C++ (C++11)**  
- **Binary Min-Heap Priority Queue (custom implementation)**  
- **File I/O (`ifstream`, `getline`)**  
- **std::unordered_map, std::vector**  
- **Git & Git LFS**  

---

## ▶️ How to Compile  

Use this command to compile the simulator:

g++ -std=c++11 -Wall -Wextra -pedantic main.cpp priorityQ.cpp -o tradingApp
(If test files exist, make sure they are not included when building the final program.)

## ▶️ How to Run the Program
This simulator requires four command-line arguments.
If you do not provide exactly four, the program exits immediately.

## Required Format:
./tradingApp *stockInputFile* *priceInputFile* *totalDays* *startingFunds*