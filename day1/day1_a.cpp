#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    std::ifstream file("input.txt");
    std::string line;

    int position=50;
    int count=0;

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        char direction = line[0];
        int rotation = std::stoi(line.substr(1));

        if (direction == 'L')
            position = ((position - rotation) % 100 + 100) % 100;
        else 
            position = (position + rotation) % 100;

        if (position == 0)
            count++;
    }

    cout << "Solution part1: " << count << endl;

    return 0;
}