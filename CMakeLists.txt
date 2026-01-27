cmake_minimum_required(VERSION 3.10)
find_package(ftxui REQUIRED)
add_executable(main src/main.cpp)
target_link_libraries(main
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component
)
