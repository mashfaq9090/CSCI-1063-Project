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
- The commands above will create the executable which you can run simply with `./main` in the build folder 





