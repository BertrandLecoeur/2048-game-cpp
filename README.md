# 2048 Game in C++

Implementation of the famous 2048 game developed in C++.

## Project Overview

This project recreates the 2048 game in a terminal environment using matrix transformations and modular game logic.

The player moves tiles across a 4x4 grid:
- identical tiles merge together,
- the score increases after each merge,
- the goal is to reach the value 2048.

---

## Features

- Complete 2048 gameplay
- Score management
- Random tile generation
- Win/loss detection
- Matrix transformations
- Console rendering
- Unit testing framework

---

## Game Mechanics

The project implements:
- left/right/up/down movement,
- tile aggregation,
- random 2/4 generation,
- board transposition,
- collision management,
- move validation.

---

## Technologies Used

- C++
- STL vectors
- Matrix manipulation
- Modular programming
- Unit testing

---

## Algorithmic Concepts

- 2D arrays and matrices
- Matrix transposition
- Vector manipulation
- Recursive aggregation
- Random generation
- Game state management

---

## File Structure

```text
.
├── 2048.cpp
├── modele.cpp
├── modele.h
├── test.cpp
├── rapport.md
└── README.md
```

---

## Compilation

```bash
g++ 2048.cpp modele.cpp -o 2048
```

Run the game:

```bash
./2048
```

---

## Controls

- `g` → left
- `d` → right
- `h` → up
- `b` → down

---

## Testing

The project includes unit tests for:
- tile aggregation,
- board transformations,
- movement logic,
- game state validation,
- win/loss detection. :contentReference[oaicite:3]{index=3}

---

## Author

Bertrand Lecoeur  
CY Tech / Paris-Saclay University
