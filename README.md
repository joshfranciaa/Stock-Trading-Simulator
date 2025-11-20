# 📈 Stock Trading Simulator  
A C++ simulation program that models daily stock trading using a custom priority queue, portfolio tracking, and dynamic data structures. This project demonstrates data structures, OOP design, algorithmic reasoning, and file-driven simulation.

---

## 🎥 Demo Video  
Click below to watch the full demonstration:

[▶️ **Watch the Demo**](Stock%20Trading%20Simulator%20Demo.mp4)

*(Make sure your video is added via Git LFS or GitHub may block large files.)*

---

## 🚀 Features  
- Automatic stock buying simulation based on price  
- Daily order execution with adjustable budget  
- Priority-based stock selection  
- Tracks:
  - Stock ticker  
  - Quantity purchased  
  - Purchase price  
  - Total portfolio value  
- File-driven input & output  
- Custom priority queue / heap implementation  
- Clean OOP design and modular structure  

---

## 🛠 Technologies Used  
- **C++ (C++11 or higher)**  
- **Priority Queues (binary heap)**  
- **Object-Oriented Programming**  
- **File I/O (`ifstream`, `ofstream`)**  
- **Git & Git LFS**  

---

## ▶️ How to Compile  
g++ -std=c++11 -Wall -Wextra -pedantic *.cpp -o tradingApp

## ▶️ How to Run the Program

This simulator requires **four command-line arguments**.  
If you do not provide exactly four, the program will exit immediately.

The format is:

./tradingApp <stockInputFile> <priceInputFile> <totalDays> <startingFunds>

