#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream file("input.txt");
    string line;

    long long total_joltage = 0;

    while (getline(file, line)){
        if (line.empty()) continue;

        int joltage = 0;

        //try all pairs (i,j) where i<j ro preserve order
        for (int i=0; i<line.size(); i++){
            for (int j=i+1; j<line.size(); j++) {
                //line[i] - '0' converts a char to a digit using ASCII
                int value = (line[i] - '0') * 10 + (line[j] - '0');
                if (value > joltage) joltage = value;
            }
        }
        total_joltage += joltage;
    }

    cout << "Solution part1: " << total_joltage << endl;

    return 0;
}