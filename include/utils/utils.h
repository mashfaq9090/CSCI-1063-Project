#pragma once

#include <ftxui/dom/elements.hpp>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <chrono>
#include <ctime>
#include <cassert>


using namespace ftxui;

Element LoadAsciiArt(std::string filepath);
void getSystemTime(int& hour, int& minute);
void testAsciiFunction(std::string filepath);
