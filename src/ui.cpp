#include "ui/ui.h"
#include "utils/utils.h"

Element HeaderLeft(int valuex, int valuey){
    return hbox({
        LoadAsciiArt("ascii_1.txt")

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

Element HeaderLayout(int valuex, int valuey){
    return hbox({
        HeaderLeft(valuex, valuey),
        HeaderRight(valuex, valuey)
    });
}



