# AVL Tree & Splay Tree Comparison

This C program implements **AVL Trees** and **Splay Trees**, allowing insertion and search operations. It reads integer values from an input file, inserts them into both tree structures, and calculates the total cost of operations.

## Features
- **AVL Tree Implementation**
  - Self-balancing using **rotations** (left, right, left-right, right-left)
  - Maintains a balanced structure for efficient searches
- **Splay Tree Implementation**
  - Uses **splaying** to move accessed nodes closer to the root
  - Optimizes frequently accessed elements
- **Performance Comparison**
  - Counts the number of operations performed during insertions

## Requirements
- **C Compiler** (e.g., `gcc`)
- **Input File** containing integer values

## Compilation & Execution
### **Compile the program**
```bash
gcc -o tree_comparison tree_comparison.c
