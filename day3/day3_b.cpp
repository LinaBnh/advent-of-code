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

        int n = line.size();
        string joltage = "";
        int pos = 0; //current search start position

        //build the 12 digit number one digit at a time
        for (int digit=12; digit>0; digit--){
            //search window: from pos to n-digit
            //n-digit ensures enough digits remain for the rest
            for (int i=pos+1; i<n-digit+1; i++){
                //strictly greater: keep leftmost if equal
                if (line[i] > line[pos]) pos = i;
            }
            
            joltage += line[pos];
            pos++; //next digit must come after current position
        }

        total_joltage += stoll(joltage);
    }

    cout << "Solution part2: " << total_joltage << endl;

    return 0;
}