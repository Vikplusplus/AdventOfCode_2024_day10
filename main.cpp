#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
using namespace std;

//part 1
int trailheadScore(int i, int j, vector<vector<int>>& map, int mapSize, int height) {

    //if 9 has been found after 9 steps, mark that 9 as visited and increase score
    if(height == 9) {
        map[i][j] = -1;
        return 1;
    }

    int score = 0;

    //DFS-traversal to all positions with height increased by one
    if(i != 0) {
        if(map[i-1][j] == height + 1) {
            score += trailheadScore(i-1, j, map, mapSize, height + 1);
        }
    }
    if(i != mapSize - 1) {
        if(map[i+1][j] == height + 1) {
            score += trailheadScore(i+1, j, map, mapSize, height + 1);
        }
    }
    if(j != 0) {
        if(map[i][j-1] == height + 1) {
            score += trailheadScore(i, j-1, map, mapSize, height + 1);
        }
    }
    if(j != mapSize - 1) {
        if(map[i][j+1] == height + 1) {
            score += trailheadScore(i, j+1, map, mapSize, height + 1);
        }
    }

    return score;
}
//part 2
int trailheadRating(int i, int j, vector<vector<int>>& map, int mapSize, int height) {

    //if 9 has been found after 9 steps, increase rating
    if(height == 9) {
        return 1;
    }

    int score = 0;

    //DFS-traversal to all positions with height increased by one
    if(i != 0) {
        if(map[i-1][j] == height + 1) {
            score += trailheadRating(i-1, j, map, mapSize, height + 1);
        }
    }
    if(i != mapSize - 1) {
        if(map[i+1][j] == height + 1) {
            score += trailheadRating(i+1, j, map, mapSize, height + 1);
        }
    }
    if(j != 0) {
        if(map[i][j-1] == height + 1) {
            score += trailheadRating(i, j-1, map, mapSize, height + 1);
        }
    }
    if(j != mapSize - 1) {
        if(map[i][j+1] == height + 1) {
            score += trailheadRating(i, j+1, map, mapSize, height + 1);
        }
    }

    return score;
}

int main() {

    ifstream f;
    f.open("../input.txt");

    if (!f.is_open()) {
        cerr << "Error opening the file!";
        return 0;
    }

    string s;
    string fileContent;

    int lines = 0;

    while(getline(f,s)) {
        fileContent.append(s);
        lines++;
    }

    f.close();


    //convert string to 2D-array
    vector<vector<int>> mapArray(lines, vector<int>(lines));

    int row = 0;
    int col = 0;

    for(char & c : fileContent) {

        mapArray[row][col] = c - '0';

        col++;
        if(col >= lines) {
            col = 0;
            row++;
        }
    }
    // part 1
    /*
    //copy map to put it back to its initial state
    vector<vector<int>> mapArrayCopy = mapArray;

    //iterate over 2d-array to calculate sum of trailhead scores
    int trailheadSum = 0;

    for(int i=0; i < lines; i++) {
        for(int j=0; j < lines; j++) {
            if(mapArray[i][j] == 0) {
                trailheadSum += trailheadScore(i,j,mapArray,lines,0);
                mapArray = mapArrayCopy;
            }
        }
    }

    return trailheadSum
    */

    // part 2
    int trailheadSum = 0;

    //iterate over 2d-array to calculate sum of trailhead ratings
    for(int i=0; i < lines; i++) {
        for(int j=0; j < lines; j++) {
            if(mapArray[i][j] == 0) {
                trailheadSum += trailheadRating(i,j,mapArray,lines,0);
            }
        }
    }

    return trailheadSum;

}