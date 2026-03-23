#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    std::ifstream file("input.txt");
    std::string line;

    int position=50; //dial starts at 50
    int count=0; //number of times the dial lands on 0

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        char direction = line[0]; //left or right
        int rotation = std::stoi(line.substr(1)); //number of clicks converted from string into int

        //the dial has 100 positions (0-99) so i used modulo 100 to wrap around
        if (direction == 'L')
            //+100 before % handles negative values when going left
            position = ((position - rotation) % 100 + 100) % 100;
        else 
            position = (position + rotation) % 100;

        if (position == 0)
            count++;
    }

    cout << "Solution part1: " << count << endl;

    return 0;
}