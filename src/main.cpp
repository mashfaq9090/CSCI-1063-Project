#include <ftxui/dom/elements.hpp>                    // for static elements 
#include <ftxui/component/component.hpp>             // for Component, Button, Renderer
#include <ftxui/component/screen_interactive.hpp>    // for continuous screen loop and refresh function
#include <string>


using namespace ftxui;


int main() {

    int counter = 0;

    // Define a button that increments the counter when clicked.
    // The button is styled with an animated red color.
    // The main purpose of this button is to demonstrate interactivity in the UI.
    // And understand how to use FTXUI components.
    Component Button_1 = Button("Increment Value", [&] {counter += 1; }, ButtonOption::Animated(Color::Red));

    
    // Define the main application component that displays the counter and the button.
    // It uses a vertical box layout to arrange the text and button vertically.
    // The main purpose of this component is to encapsulate the UI elements and their layout.
    // This will help in understanding how to structure FTXUI applications.
    Component app = Renderer(Button_1, [&] {
        std::string current_s = std::to_string(counter);
        return vbox({
            text("Value: "+current_s) | bold | color(Color::Blue),
            separator(),
            Button_1->Render()
        }) | border;
    });


    // Start the interactive screen loop.
    // The screen will continuously refresh and respond to user interactions.
    // The main purpose of this loop is to keep the application running and interactive.
    // This will help in understanding the event-driven nature of FTXUI applications.
    ScreenInteractive screen = ScreenInteractive::FitComponent();
    screen.Loop(app);
    return 0;
  
}