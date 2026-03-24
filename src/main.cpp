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

    Component input_list = Container::Vertical({});
    std::vector<std::string> items(5, "");
    for (size_t i = 0; i < items.size(); ++i) {
        input_list->Add(Input(&(items[i]), "To-Do " + std::to_string(i)));
    }

    Component body = Container::Vertical({
        input_list, 
        menu,
    });

    ScreenInteractive screen = ScreenInteractive::Fullscreen();

    auto app = Renderer(body, [&] {
        auto dim = Terminal::Size();
        width = dim.dimx;
        height = dim.dimy;

        return vbox({
            HeaderLayout(width, height),
            hbox({  
                MenuView(width, height, menu),
                window(text("To-Do List"), ToDoView(width, height, input_list))
            })
        });

    });



    auto component = CatchEvent(app, [&](Event event) {
        if (event == Event::Character('q') || event == Event::Escape) {
            screen.ExitLoopClosure()(); // Note the double parenthesis: it returns a closure, then we call it.
            return true;
        }
        return false;
    });
    
    screen.Loop(component);
    std::cout << width << " " << height << std::endl;
    }
    else if (std::string(argv[1]) == "test"){
       testAsciiFunction("../assets/ascii_arts/ascii_2"); 
    }
    return 0;
}