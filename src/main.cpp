#include <ftxui/component/component.hpp>         
#include <ftxui/component/screen_interactive.hpp>   
#include <ftxui/screen/terminal.hpp> 
#include "ui/ui.h"
#include "utils/utils.h"
#include <string>


using namespace ftxui;

int main(int argc, char* argv[]){
    if (argc == 1){
    int width{0}; // value x
    int height{0}; //value y 

    Component menu;
    int selected;
    std::vector<std::string> entries;

    entries = {
        "Note Pad",
        "Calendar",
        "To Do",
    };

    selected = 0;

    menu = Menu(&entries, &selected);

    
    auto app = Renderer(menu, [&] {
        auto dim = Terminal::Size();
        width = dim.dimx;
        height = dim.dimy;

        return vbox({
            HeaderLayout(width, height),
            MenuView(width, height, menu),

        });

    });
    
    ScreenInteractive screen = ScreenInteractive::Fullscreen();
    screen.Loop(app);
    std::cout << width << " " << height << std::endl;
    }
    else if (std::string(argv[1]) == "test"){
       testAsciiFunction("../assets/ascii_arts/ascii_2"); 
    }
    return 0;
}