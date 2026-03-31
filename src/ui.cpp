#include "ui/ui.h"
#include "utils/utils.h"

Element HeaderLeft(int valuex, int valuey, Element acsii_art){
    return hbox({
        acsii_art
    }) | border | size(WIDTH, EQUAL, 0.7 * valuex) | size(HEIGHT, EQUAL, 0.5 * valuey);
}

Element HeaderRight(int valuex, int valuey){
    int hour{0};
    int minute{0};
    getSystemTime(hour, minute);
    return hbox({
        text("Current Time: " + std::to_string(hour) + ":" + std::to_string(minute))
        
    }) | border | size(HEIGHT, EQUAL, 0.5 * valuey);
}

Element HeaderLayout(int valuex, int valuey, Element ascii_art){
    return hbox({
        HeaderLeft(valuex, valuey, ascii_art),
        HeaderRight(valuex, valuey)
    });
}

Element MenuView(int valuex, int valuey, Component& menu){ 
    return vbox({
        menu->Render()
    })|border | size(WIDTH, EQUAL, 0.25 * valuex);
};

Element ToDoView(int valuex, int valuey, Component& todo){ 
    return vbox({
        todo->Render()
    })| vscroll_indicator | frame | border;
};



