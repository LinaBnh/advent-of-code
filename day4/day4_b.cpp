#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//function to count the accessible papers
//for each '@' we increment the counter of its 8 neighbors
void countPapers(vector<vector<int>>& counter, const vector<string>& grid){
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i=1; i<rows-1; i++){
        for (int j=1; j<cols-1; j++){
            if (grid[i][j] != '@') continue;
            counter[i-1][j-1]++; 
            counter[i-1][j]++; 
            counter[i-1][j+1]++;
            counter[i][j-1]++; 
            counter[i][j+1]++;
            counter[i+1][j-1]++;
            counter[i+1][j]++;
            counter[i+1][j+1]++;
        }
    }
}

//added a function to remove accessible rolls and return how many were removed
int removePapers(const vector<vector<int>>& counter, vector<string>& grid){
    int rows = grid.size();
    int cols = grid[0].size();
    int removed = 0;

    for (int i=1; i<rows-1; i++){
        for (int j=1; j<cols-1; j++){
            if(grid[i][j]=='@' && counter[i][j]<4){
                grid[i][j] = '.';
                removed++;
            }
        }
    }
    return removed;
}

int main(){
    ifstream file("input.txt");
    string line;

    //here i added a border of '.' around the grid to avoid checking out of bounds
    vector<string> grid;
    grid.emplace_back();
    while (getline(file, line)){
        if (line.empty()) continue;
        grid.push_back('.' + line + '.');
    }
    grid[0] = string(grid[1].size(), '.');
    grid.push_back(grid[0]);

    int rows = grid.size();
    int cols = grid[0].size();

    int papers = 0;
    int removed = 0;

    do {
        //counter must be reset at each iteration since the grid has changed
        vector<vector<int>> counter(rows, vector<int>(cols, 0));
        countPapers(counter, grid);
        removed = removePapers(counter, grid);
        papers += removed;
    } while (removed > 0);

    cout << "Solution part2: " << papers << endl;

    return 0;
}