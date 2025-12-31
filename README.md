# 🎮 Arkanoid Game (C++ | DSA)

A classic **Arkanoid / Brick Breaker** game developed in **C++** using **Data Structures & Algorithms** concepts and the **SFML library**.  
This project focuses on game logic, collision handling, and real-time rendering.

---

## 🕹️ Gameplay Demo

![Arkanoid Gameplay](assets/arkanoid-demo.gif)

---

## 🚀 Features
- Smooth paddle and ball movement
- Brick collision detection
- Score tracking
- Real-time rendering using SFML
- Object-oriented and DSA-based logic

---

## 🛠️ Tech Stack
- **Language:** C++
- **Library:** SFML 2.4.2
- **Concepts:** DSA, OOP, Collision Detection
- **Compiler:** Dev C++

---

## ⚙️ Setup & Run Guide (Dev C++)

### 📌 Follow these steps carefully:

1. Install **Dev C++ Compiler**
2. Download **SFML 2.4.2** from:  
   👉 https://www.sfml-dev.org/download/sfml/2.4.2/  
   - Choose: **GCC 4.9.2 TDM (SJLJ) – 64-bit**
   - Extract it in **C Drive**
3. Open **Dev C++ → Create New Project**
4. Go to **Project Options → Parameters**
   - Add this in **Linker**:
     ```
     -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-window
     ```
5. Go to **Directories**
   - Add SFML `lib` path in **Library Directories**
   - Add SFML `include` path in **Include Directories**
6. Open SFML → `bin` folder  
   - Copy all files
   - Paste them into your project folder
7. Copy the source code into `main.cpp`
8. Place all images in the **same folder** as the executable
9. Click **Rebuild All → Run**

🎉 **Enjoy playing Arkanoid!**

⚠️ **Important:**  
All images and SFML files must be in the same directory, otherwise the game will not run.

---

## 📚 Learning Outcomes
- Practical implementation of DSA concepts
- Game loop and event handling
- Collision detection logic
- Memory and resource management in C++

---

## 👨‍💻 Author

**Syed Muhammad Taha**  
Software Engineer | UI/UX Designer | Front-End Developer  

🔗 LinkedIn: https://linkedin.com/in/-syedmtaha-

---

⭐ If you like this project, consider giving it a star!
