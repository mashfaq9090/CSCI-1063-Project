#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/dom/elements.hpp>

using namespace ftxui;
int main() {
    auto screen = ftxui::Screen::Create(
        ftxui::Dimension::Full(),   
        ftxui::Dimension::Full() 
    );

    Element document = border(text("Hello, FTXUI!") | bold | color(Color::Green)); // created a bordered responsive screen

    Render(screen, document); //Render before printing --- VERY IMPORTANT!!!
    screen.Print(); // Print the screen to the terminal
}