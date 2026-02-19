# Rail-Maintenance-3D-OpenGL

A 3D OpenGL game built in C++ where the player controls a handcar (drezină) and must repair broken track segments to keep trains running. Designed as a university graphics programming assignment

---

## Overview

Two trains run autonomously on a looped rail track. Track segments break randomly over time — the player rides a handcar along the rails and must reach and repair broken segments before too many pile up or the express train derails. The game ends when 4 or more segments are broken simultaneously or the express train hits a broken track.

---

## Framework

This project is built on top of a **university-provided OpenGL framework** (GLFW + GLM + OpenGL 3.3). The framework exposes a base scene class with lifecycle callbacks such as `Init()`, `Update()`, `FrameStart()`, `FrameEnd()`, `OnInputUpdate()`, `OnMouseMove()`, `OnMouseBtnPress()`, `OnMouseBtnRelease()`, and `OnWindowResize()`.

All game logic, rendering, terrain generation, train movement, collision detection, and UI were implemented from scratch by me. The framework itself was provided by the university.

---

## Features

### Environment
- Procedurally generated 10×10 terrain grid with 3 terrain types: **plain** (green), **water** (blue), **mountain** (brown)
- 3 distinct rail types visually mapped to terrain: surface, bridge, tunnel — rendered with different colors
- 3 unique stations: a **box** (red), a **cylinder** (dark blue), and a **pyramid** (orange)

### Trains
- **Regular train**: locomotive + wagon, built from cylinders and boxes, moves autonomously along the track; stops at stations randomly for a short time; stops in front of broken segments
- **Express train**: gold-colored, moves faster; has 1 life — hitting a broken segment triggers game over

### Handcar (Drezină)
- Built from scratch: platform, 4 wheels, vertical post, animated rocking handle
- Controlled by the player using `↑` / `↓` keys along the rail path
- Handle animation uses `sin()` for realistic rocking motion while moving

### Broken Tracks
- Segments break randomly every 2–5 seconds
- Broken segments change color to black and are **translated + rotated** (geometric deformation via shader)
- Player repairs broken segments by pressing `F` while nearby (AABB-based proximity check)

### Camera
- Default: free-fly camera (WASD + mouse)
- TPS mode: toggleable with `G` — camera follows the handcar from behind

### UI (text rendered in-game)
- Live game timer
- Broken segment counter (turns red when ≥ 3)
- Express train lives counter
- **GAME OVER** screen on loss

---

## Controls

| Action | Key |
|---|---|
| Move handcar forward | `↑` |
| Move handcar backward | `↓` |
| Repair broken track | `F` (when near a broken segment) |
| Toggle TPS camera | `G` |
| Free camera move | `W` `A` `S` `D` `Q` `E` |
| Free camera rotate | Right mouse button + drag |

---

## Project Structure

```
Tema2/
├── Tema2.cpp              # All game logic — terrain, trains, handcar, collision, UI
├── Tema2.h                # Class declaration, structs, member variables
├── main.cpp               # Engine initialization and window setup
├── lab_list.h             # Framework include list (university-provided)
└── shaders/
    ├── VertexShader.glsl  # Standard 3D vertex shader (MVP transform)
    └── FragmentShader.glsl# Flat color fragment shader with broken track support
```

---

## Build & Run

This project runs within the university-provided OpenGL framework.

1. Place the `Tema2/` folder inside `src/lab_m1/`
2. Add `#include "lab_m1/Tema2/Tema2.h"` to `lab_list.h`
3. Build with Visual Studio (or CMake on Linux/macOS)
4. Run the resulting executable

> Requires: OpenGL 3.3+, GLFW, GLM

---

## Implementation Notes

- All 3D meshes (box, cylinder, pyramid, quad, track) are generated from scratch using raw vertex and index buffers
- Train movement uses linear interpolation (`glm::mix`) between rail segment endpoints
- Collision detection is AABB-based (proximity distance checks)
- Broken track deformation is applied via model matrix transformations (translate + rotate) passed to the shader
- The handcar handle animation uses `sin(handle_angle)` for smooth rocking
# Rail-Maintenance-3D-OpenGL
