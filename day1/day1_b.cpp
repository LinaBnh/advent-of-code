#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//function to count how many times the dial passes through 0 during a rotation
//idea: split the rotation into full loops (multiples of 100) + remaining rotations
int countClicks(int position, int rotation, char direction){
    // each full loop of 100 clicks always passes through 0 once
    int clicks = rotation / 100;
    
    // remaining clicks after removing full loops
    int remain = rotation % 100;

    if (direction == 'L')
        //if already on 0, it wont cross 0 again until nest full loop
        //otherwise, check if the remain in enough to reach 0
        clicks += (position == 0) ? 0 : (remain >= position);
    else
        //check if the remain is enough to cross 0 (distance to 0 going right = 100 - position)
        clicks += (remain >= (100 - position));

    return clicks;
}

int main(){
    ifstream file("input.txt");
    string line;

    int position=50; //dial starts at 50
    int count=0; //number of times the dial lands on 0

    while (getline(file,line)){
        if (line.empty()) continue;

        char direction = line[0]; //left or right
        int rotation = stoi(line.substr(1)); //number of clicks converted from string into int

        count += countClicks(position, rotation, direction);

        //update final position, wrapping around 0-99
        if (direction == 'L')
            //+100 before % handles negative values when going left
            position = ((position - rotation) % 100 + 100) % 100;
        else
            position = (position + rotation) % 100;
    }

    cout << "Solution part2: " << count << endl;
}