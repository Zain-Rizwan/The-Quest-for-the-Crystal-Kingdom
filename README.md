# The-Quest-for-the-Crystal-Kingdom
The Quest for the Crystal Kingdom is a fantasy adventure game implemented in C++, where players navigate an enchanted forest using advanced search algorithms to retrieve a legendary crystal while managing resources and overcoming challenges.

## Project Overview
**Project Title:** The Quest for the Crystal Kingdom

**Scenario:**
The player embarks on a thrilling journey through an enchanted and perilous forest to retrieve the legendary crystal. Along the way, they must navigate obstacles, defeat enemies, and gather rewards to aid their quest. The forest is mapped with unique entities and challenges that require strategic decisions and efficient algorithms to overcome.

---

## Key Features

### 1. **Data Structures and Algorithms**
#### **AVL Tree for Inventory Management**
- Stores the player's reward scores.
- Supports addition and removal of item scores.
- Node Structure:
  ```cpp
  class Node {
      int id;             // Randomly generated ID
      int reward_score;   // Score of the obtained reward
      int count;          // To track duplicates
      Node* next;         // Pointer to the next node
  };
  ```
- IDs are generated randomly between 0-200, with the first ID starting at 100.
- Nodes (except the root) are inserted based on the value of the ID.

#### **Shortest Path Calculation (Floyd's Algorithm)**
- Computes the shortest path between any two areas in the forest.
- Accounts for the locations of enemies and obstacles.

#### **Minimum Spanning Tree**
- **Prim's Algorithm:**
  - Builds the MST considering enemy and obstacle locations.
- **Kruskal's Algorithm:**
  - Finds the MST by sorting edges by weight and applying the union-find technique.

#### **Pathfinding (Dijkstra's Algorithm)**
- Determines the shortest path from the player's current location to the crystal.
- Edge weights:
  - Obstacles: 100
  - Others: 1

---

### 2. **Game Map**
The game map uses the following legend:

| Symbol | Description       |
|--------|-------------------|
| `C`    | Clear path        |
| `J`    | Jewel             |
| `P`    | Potion            |
| `W`    | Weapon            |
| `%`    | Death point       |
| `#`    | Obstacle          |
| `&`    | Dragon            |
| `$`    | Goblin            |
| `@`    | Werewolf          |
| `*`    | Crystal (goal)    |

#### **Entities:**
1. **Safe Paths:** Movement nodes with no restrictions.
2. **Obstacles:** High-weight nodes requiring alternate paths.
3. **Rewards:**
   - Jewel: +50 points
   - Weapon: +30 points
   - Potion: +70 points
4. **Enemies:**
   - Werewolf: Removes a weapon.
   - Goblin: Removes a potion.
   - Dragon: Removes a jewel.
   - Decreases score accordingly.
5. **Death Points:** Instant game over.

---

## Expected Outcomes
1. Calculate the shortest path between any two areas using Floyd's Algorithm.
2. Determine the shortest path from the current location to the crystal using Dijkstra's Algorithm.
3. Generate the minimum spanning tree of the forest using Prim's and Kruskal's Algorithms.
4. Track and update the player's score at each step, displaying the final score at the end.

---

## Menu Features
- Shortest path using the default location (0,0) or custom coordinates (user-input).
- Minimum Spanning Tree generation using Prim's and Kruskal's Algorithms.
- Score management and tracking.

---

## Implementation Details
1. **Programming Language:** C++
2. **Restrictions:**
   - All algorithms must be implemented from scratch.
   - No use of pre-built libraries or APIs.
3. **Documentation:**
   - The code is thoroughly documented for ease of understanding.

---

## Restrictions and Assumptions
- Obstacles are assigned a weight of 100; all other edges have a weight of 1.
- Players must strategically avoid death points and high-cost paths.
- Enemies affect the inventory, reducing both the count and the score of specific rewards.

---

## How to Run
1. Clone this repository:
   ```bash
   git clone https://github.com/Zain-Rizwan/The-Quest-for-the-Crystal-Kingdom.git
2. Compile the code using a C++ compiler.
3. Run the program and follow the on-screen menu for navigation.
