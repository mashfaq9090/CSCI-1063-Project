#pragma once

#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/captured_mouse.hpp>

using namespace ftxui;



Element HeaderLeft(int valuex, int valuey);
Element HeaderRight(int valuex, int valuey);
Element MenuView(int valuex, int valuey, Component& menu);
Element TodoView();
Element CalendarView();
Element MainLayout(int valuex, int valuey);
Element HeaderLayout(int valuex, int valuey);
Element BodyLayout();



