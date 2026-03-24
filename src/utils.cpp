#include "utils/utils.h"

Element LoadAsciiArt(std::string filepath) {
    std::ifstream file(filepath);
    std::string line;
    Elements lines; // This is a std::vector<Element>

    if (file.is_open()) {

        while (std::getline(file, line)) {
            // Each line from the file becomes a text element
            
            lines.push_back(text(line));

        }
        file.close();
    } else {
        return text("Error: Could not open file.");
    }

    // Stack them vertically
    return vbox(std::move(lines));
}

void getSystemTime(int& hour, int& minute) {
    // 1. Get the current time point from the system clock
    auto now = std::chrono::system_clock::now();

    // 2. Convert to a C-style time_t
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    // 3. Convert to local time structure
    // Note: std::localtime is not thread-safe. For thread-safety, 
    // use localtime_s (Windows) or localtime_r (POSIX).
    std::tm* localTime = std::localtime(&currentTime);

    // 4. Assign values to our variables
    hour = localTime->tm_hour;
    minute = localTime->tm_min;
}

void testAsciiFunction(std::string filepath) {
    std::ifstream file(filepath);
    std::string line;
    int max_width = 0;
    int max_height = 0;


    if (file.is_open()) {

        while (std::getline(file, line)) {
            // Each line from the file becomes a text element
            if (line.length() > max_width){
                max_width = line.length();
            }
            max_height++;
        }
        file.close();
    } 

    assert(("Test Failed ---- Ascii out of dimension",max_width <= 123 && max_height <= 25));

    std::cout << "Ascii bound Test -------------------- Passed :)" <<std::endl;
} 