#include <ftxui/dom/elements.hpp>                    // for static elements 
#include <ftxui/component/component.hpp>             // for Component, Button, Renderer
#include <ftxui/component/screen_interactive.hpp>    // for continuous screen loop and refresh function
#include <string>


using namespace ftxui;


int main() {

    int counter = 0;

    // Define a button that increments the counter when clicked.
    Component Button_1 = Button("Increment Value", [&] {counter += 1; }, ButtonOption::Animated(Color::Red));

    
    // Define the main application component that displays the counter and the button.
    Component app = Renderer(Button_1, [&] {
        std::string current_s = std::to_string(counter);
        return vbox({
            text("Value: "+current_s) | bold | color(Color::Blue),
            separator(),
            Button_1->Render()
        }) | border;
    });

    
    // Start the interactive screen loop.
    ScreenInteractive screen = ScreenInteractive::FitComponent();
    screen.Loop(app);
    return 0;
  
}