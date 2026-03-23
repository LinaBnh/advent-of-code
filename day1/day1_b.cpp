#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//fonction pour compter les passages par 0 pour une rotation

int countClicks(int position, int rotation, char direction){
    // un tour complet de 100 clics passe forcément par 0 une fois
    int clicks = rotation/100;
    
    // pour les tours qui ne sont pas complet
    int tour = rotation % 100;

    if (direction == 'L')
        clicks += (position == 0) ? 0 : (tour >= position);
    else
        clicks += (tour >= (100 - position));

    return clicks;
}

int main(){
    ifstream file("input.txt");
    string line;

    int position=50;
    int count=0;

    while (getline(file,line)){
        if (line.empty()) continue;

        char direction = line[0];
        int rotation = stoi(line.substr(1));

        count += countClicks(position, rotation, direction);

        if (direction == 'L')
            position = ((position - rotation) % 100 + 100) % 100;
        else
            position = (position + rotation) % 100;
    }

    cout << "Solution part2: " << count << endl;
}