## Release Notes
Very First release. Include the following functionality 

- [ ] Static Ascii art
- [ ] Clock
- [ ] Menu Window

See below for known limitation and upcoming updates

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

## Known Limitations

- [ ] Saving data and writing data has not been implemented
- [ ] ELements were not containerized
- [ ] New windows will be in the next release


## Run Instructions

- ### Requirements
  - Requires Linux system 
  - Make sure to have FTXUI libraries installed on your machine. Follow the official guide at -> https://arthursonzogni.github.io/FTXUI/installation.html. The recomened method is to do it manually and build from Source [5th option in the guide]
  - Alternatively you simply download the zip folder and jump to the next steps (not recomended for bleeding edge)


- Once FTXUI is installed run the following commands in the projects directory or if you are using the zip folder go to the FTXUI directory

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






