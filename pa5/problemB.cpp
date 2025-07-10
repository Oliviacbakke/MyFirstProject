// Olivia Bakke 
// Computer Systems 
// Programming Assignment 5 
// Problem B 

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void doThing(int numRows, int numColumns, int arrayMax) {
    srand(time(0)); 
    ofstream fout; 
    fout.open("randArray.txt"); 
    int arrayMax1 = arrayMax - (2*arrayMax); 
    for(int i=0; i<numRows; i++) {
        for(int j=0; j<numColumns; j++) {
            int num = (rand()%((arrayMax) - arrayMax1 + 1) + arrayMax1);
            cout << num << " ";
            fout << num << " "; 
        }
        cout << endl; 
        fout << endl;  }}

int main(int argc, char* argv[]) {
    if(argv[1] == NULL || argv[2] == NULL || argv[3] == NULL || argv[4] != NULL) {
        cout << "Incorrect number of arguments! Please become better :)" << endl; 
        return 0;}
    else {
        int numRows = stoi(argv[1]);
        int numColumns = stoi(argv[2]);
        int arrayMax = stoi(argv[3]);
        doThing(numRows, numColumns, arrayMax); 
    }}