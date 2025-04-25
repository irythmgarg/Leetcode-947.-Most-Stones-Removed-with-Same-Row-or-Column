# Leetcode-947.-Most-Stones-Removed-with-Same-Row-or-Column

# Remove Stones to Minimize Remaining - Multiple Approaches

This repository provides multiple approaches to solve the popular problem of removing the maximum number of stones from a 2D plane such that at least one stone remains in each connected component (sharing the same row or column).

---

## Problem Statement
You are given a 2D array `stones` where each `stones[i] = [xi, yi]` represents the position of a stone. A stone can be removed if there is **another stone** in the **same row or the same column**.

Return the **maximum number of stones** you can remove.

---

## 🔍 Approaches Covered

### ✅ Approach 1: DFS (Depth First Search)
- Treat each stone as a node and connect it to other stones in the same row or column.
- Use DFS to count the number of connected components.
- In each component, all but one stone can be removed.
- **Time Complexity:** O(N^2)
- **Space Complexity:** O(N)

### ✅ Approach 2: Union-Find (Disjoint Set Union)
- Each stone is a node; connect those with the same row or column.
- Use Union-Find to identify and merge components.
- Count total components after union operations.
- The result is `total stones - components`.
- **Time Complexity:** O(N^2 · α(N)) where α is the inverse Ackermann function.
- **Space Complexity:** O(N)

---

## 🧠 Comparison Table
| Approach     | Concept       | Data Structure | Time       | Space      |
|--------------|---------------|----------------|------------|------------|
| DFS          | Connected Components | `vector<bool>` | O(N^2)     | O(N)       |
| Union-Find   | Disjoint Sets       | `vector<int>`  | O(N^2 · α(N)) | O(N)       |

---

## ✅ Example
**Input:**
```cpp
stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
```
**Output:**
```cpp
5
```
**Explanation:**
One possible way to remove 5 stones is:
- Remove (0,0), (0,1), (1,0), (1,2), and (2,2)
- Only (2,1) remains

---

## 🤝 Contributions
Feel free to fork, suggest optimizations, or add new approaches via pull requests!

---

## 📜 License
MIT License

---

Happy Coding! 🚀
