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

- [ ] Create header files  
- [ ] Finalize project goals
- [ ] Get used to the API 
- [ ] Finalize the homepage interface
- [✔] finalize project design

---

## Known Limitations
- [ ] UI has not been properly set up
- [ ] Saving data and writing data has not been implemented
- [ ] Header files have not been utilized 
- [ ] Design assets have not been implemented

---

## Project Design

- Project will utilize a graphical interface to allow a user to add their task and deadlines.
- Project will display a calender using the graphical interface.
- Project will utilize a json file to save all recorded data.
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

