# Video Game Hacking Template
A template for video-game hacking using C.

[ display image of default ]

## Overview
This template hooks into an x86 process by default and displays a basic rendering  
of a cheat menu.

The menu is very modular and is only limited by your creativity.

## Structure
#### Hacks
The hacks section is responsible for hacks API that the event handler relies on.
#### Drawing
The drawing section is responsible for drawing API that the renderer relies on.
#### Events
The events section is responsible for listening for keyboard input and  
performing operations based on that input.
#### Render
The render section is responsible for the initialization, format, and rendering  
of the cheat menu for the end user.

### TODO:
- [ ] External
- [ ] Kernel Driver
- [x] Internal (DLL)
