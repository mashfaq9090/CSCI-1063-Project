# CSCI-1063 — Project Description

The goal of this project is to create a **schedule tracking system** that allows users to manage important dates, deadlines, and daily activities.  
Users will be able to build and interact with their schedules using a **terminal-based user interface (TUI)**.

The final system architecture is **currently undecided** and will be refined during development.

---

## Tech Stack

- **Language:** C++  
  Chosen because all team members have prior experience with it.

- **UI Library:** FTXUI  
  Used to create an interactive terminal user interface. FTXUI is beginner-friendly and well-suited for terminal-based graphical applications.

---

## Project Creators

- Mohammad Mahrus Bin Ashfaq  
- Krishnath Sirivel  
- Alex Hansler  

---

## Tasks / To-Do List

- [ ] Create Calendar View
- [ ] Connect with internet
- [ ] Add Email funtionality

---

## Known Limitations
- [ ] Minor glitches when changing window size

---

## Project Design

- Project will utilize a graphical interface to allow a user to add their task and deadlines.
- Project will display a calender using the graphical interface.
- Project will utilize a json/txt file to save all recorded data.
- Project will utilize a notepad system to allow users to record specific information about their tasks.

---

## Project structure

- include folder will store all UI, core, and utility header files.
- data folder will store all saved data of the user.
- assets folder will store all design elements.
- src folder will store the main file.

---

## Run Instructions

- ### Requirements
  - Requires Linux system 
  - Make sure to have FTXUI libraries installed on your machine. Follow the official guide at -> https://arthursonzogni.github.io/FTXUI/installation.html. The recomened method is to do it manually and build from Source [5th option in the guide]



- Once FTXUI is installed run the following commands in the projects directory

```bash
mkdir build
cd build
cmake ..
make
```
- The commands above will create the executable which you can run simply with `./ftxui_app` in the build folder 

- ### Test Instructions
  Include the `test` flag in the executable as follow
  `./ftxui_app test`

  As of now the test suite covers the following domain: 
    - `Ascii bound check`

## Docker Containerization 
The provided docker file can be used to run the app in a containerized environmet
- ### Requirements
  - Requires docker engine (follow the official installation guide according to your machine at ----> https://www.docker.com/)

- Once docker engine is pressent follow the instructions bellow: 

```bash
docker build -t ftxui_app .
docker run -it ftxui_app
```
P.S. Change `ftxui_app` to any container tag you preffer.

## Benchmarking 

For our benchmarking and analysis we have used `gprof` which comes pre-installed with the `g++` compiler. To use `gprof` the `-pg` flag must be added while compilation. This outputs a `gmon.out` file. To view it we have to use the `gprof "program_binary" "gmon.out"` and pipe that to a text file viewer. 

### Analysis

For the analysis we are specifically using individual function run time in seconds as our metric. 

Based on our gmon.out file, the bottelneck of our application in the `FTXUI` library itself. The program 
UpdatePixelStyle and Pixel::operator functions were called in the majority of run time (13.2% combined), which is as expected since FTXUI is spending most of its effort calculating colors and moving "pixels" (characters) around to draw your UI.

In comparison our own function doesn't hold up as much resources since most of them are a derivative of the library functions. That being said following metrics were noatable: 

- LoadAsciiArt --> was called 356 times. The main variable in this function is the size of our Ascii art
- ScreenInteractive ---> has a cumilative run time of 0.76 seconds. The main variable is the number of times the terminal is being refreshed. 

`we have include our gmon.out file for the current release in the assets folder`

### Optimization 

We have improved our benchmark. Now `LoadAsciiArt` is static and creates the visual assest before the main loop and uses it instead of re-rendering the static art indefinitely in the main loop.

- As per our initial report, `LoadAsciiArt` is being called once instead of 356 times as noted before. 

- We have also optimized our codebase in-terms of readability and modularity, removing extra  DOM tree structure UI components.

## Reflection

This one a rewarding experience for us working on a modular project. We learned about C++ design patterns, optimizing our code through multiple files, and most importantly learning new C++ library and reading through the source code of the library iteself to better familiarize ourself. 

In terms of new software technologies, this project was our first exposure to virtualization and x-platform technologies like docker, which allowed us to run our application in any environment in any cpu architecture. 

Finaly, we were exposed to industry standards in software developing and benchmarking to iteratively improve our software.

### Future vision

Altough we completed most of our milestones, due to time complexity we were unable to add a funtional TUI calendar to our program. It's definitely something we will be working on in the future. We also have plans to integrate networking capabilities and add email functionality to make our app more holistic. 