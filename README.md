# 🧠 Low-Level Mastery: From Memory Basics to High-Performance C-Engines

This repository documents my comprehensive journey through the core of Computer Systems—**C Programming**. I have transitioned from understanding basic memory layouts to building complex data structures and optimizing Python performance using a custom-built C engine.

---

## 📌 Project Overview
The goal of this project was to master **Manual Memory Management** and leverage it to solve real-world performance bottlenecks. The development is divided into three major architectural milestones.

## 🏗️ Milestone 1: Dynamic Memory & The "Heap Corruption" 
* **Concepts:** Stack vs. Heap, `malloc()`, `free()`, `realloc()`.
* **The Challenge:** Built a dynamic array that grows its capacity by 2x when full (Amortized $O(1)$).
* **Lesson Learned:** Encountered **Heap Corruption** by accessing out-of-bounds memory. This experience taught me the criticality of memory boundaries and the responsibilities of a low-level architect.



---

## 🔗 Milestone 2: Linked List Implementation (Topology over Coordinates)
* **Concepts:** Self-referential structures, Pointers, Node Traversal.
* **The Challenge:** Developed a memory-efficient Linked List to manage data without contiguous memory blocks. 
* **The Logic:**
    * **Traversal:** Navigating through "next" pointers rather than array indices.
    * **Safe Deallocation:** Implemented a "Temp-Pointer" strategy to prevent memory leaks during `free()`, ensuring no "bridge" is burned before crossing it.



---

## 🚀 Milestone 3: Python Performance Booster (The Prime Engine)
The climax of the project: Solving the performance limitations of Python by integrating a **C-shared library (DLL)**.

### 🧪 The Experiment
* **Objective:** Identify all prime numbers up to 10,000,000.
* **Architecture:** * **Core Engine:** C-based `is_prime` logic compiled into an **x64 DLL**.
    * **Interface:** Python `ctypes` wrapper for high-level data handling and benchmarking.

### 📊 Performance Benchmark
| Implementation | Time Taken (Seconds) | Performance Gain |
| :--- | :--- | :--- |
| **Pure Python** | **107.54s** | Baseline |
| **My C Engine** | **5.59s** | **~1,920% Faster** |

> **Insight:** By offloading heavy loops to C, I achieved a **19x speedup**, proving that low-level optimization is the key to scalable software.

---

## 🧬 Future Vision: Bio-AI & Energy Efficiency
This project is a stepping stone toward building **Sustainable AI**. 
* **Energy Efficiency:** Reducing execution time by 19x directly correlates to 19x less CPU energy consumption for the same task.
* **Brain-Inspired Computing:** I plan to apply these optimization techniques to implement **Sparse Transformer** architectures, mimicking the energy-efficient "spiking" nature of the human brain.

---

## 🛠️ How to Build & Run
1. **Compile the C Engine (Windows x64):**
   Open `x64 Native Tools Command Prompt` and run:
   ```cmd
   cl /LD prime_lib.c
2. **Run the Python Wrapper:**
   ```bash
   python Pure Python vs Python with C Library.py

## Evidence
<img width="372" height="68" alt="소수 판별기 1억까지 소요시간" src="https://github.com/user-attachments/assets/a509169c-076b-479f-a4a2-c80f6728d097" />
