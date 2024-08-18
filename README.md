# So_long Game

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)
- [Requirements](#requirements)
- [Project Details](#project-details)
- [Screenshots](#screenshots)
- [Credits](#credits)

## Introduction
**So_long** is a 2D game developed using the C programming language and Minilibx graphics library. The objective is to guide your character through a maze-like map, collecting items and reaching the exit while navigating obstacles. This project was created as part of the 42 School curriculum and demonstrates foundational skills in graphics programming, game logic, and map handling.

**Note**: This game currently works only on macOS as the version of Minilibx used is compatible only with macOS.

## Features
- Intuitive 2D gameplay.
- Character movement via both WASD keys and arrow keys.
- Item collection and exit navigation.
- Map parsing from `.ber` files for dynamic gameplay.
- Custom win and loss conditions.

## Installation
To run the game on macOS:

1. Clone the repository:
   ```bash
   git clone https://github.com/username/so_long.git
   cd so_long
2. Compile the game:
   ```bash
   make
3. Start the game:
   ```bash
    ./so_long maps/map1.ber

## Usage
To play the game, you'll need a valid `.ber` map file. Sample maps are available in the `maps` directory. The game automatically parses the map to set up the walls, player position, collectible items, and exit. You can also create custom maps in a text editor.

### Map Components:
- Walls: `1`
- Empty spaces: `0`
- Player start: `P`
- Collectible items: `C`
- Exit: `E`

## Controls
- **W / Up Arrow**: Move Up
- **A / Left Arrow**: Move Left
- **S / Down Arrow**: Move Down
- **D / Right Arrow**: Move Right
- **ESC**: Quit the game

## Requirements
- **Operating System**: macOS only (due to Minilibx compatibility).
- **Libraries**: Minilibx (macOS version) and the standard C library.
- **Compiler**: GCC or compatible C compiler.

## Project Details
- **Language**: C
- **Graphics Library**: Minilibx
- **42 School Project**: So_long

The game features basic event-driven programming using the Minilibx library to render a window and handle keyboard input. The map is dynamically loaded from `.ber` files, and the gameplay adjusts accordingly.

> **Note**: Enemies are not implemented in the current version of the game.

## Credits
Developed by Adhil as part of the 42 School curriculum.
