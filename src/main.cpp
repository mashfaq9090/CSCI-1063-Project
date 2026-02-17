#include <ftxui/component/component.hpp>         
#include <ftxui/component/screen_interactive.hpp>   
#include <ftxui/screen/terminal.hpp> 
#include "ui/ui.h"
#include "utils/utils.h"
#include <string>


using namespace ftxui;


int main(){
    int width{0};
    int height{0};

    auto app = Renderer([&] {
        auto dim = Terminal::Size();
        width = dim.dimx;
        height = dim.dimy;
        return HeaderLayout(width, height);
    });
    
    ScreenInteractive screen = ScreenInteractive::FitComponent();
    screen.Loop(app);
    return 0;
}