#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
#include <sstream>
using namespace std; 
int mid; 
 

int binarySearch(int sortedArray[], int numVal, int leftBound, int rightBound) {
    int mid = leftBound + (rightBound - leftBound) / 2; 
    if (leftBound > rightBound) {
        return -1; }
    if(sortedArray[mid]==numVal) {
        return mid; }
    else if(sortedArray[mid]>numVal) {
        return binarySearch(sortedArray, numVal, leftBound, mid - 1);}
    else if(sortedArray[mid]<numVal){
        return binarySearch(sortedArray, numVal, mid  + 1, rightBound);}
    else {
        return -1; }}

int main() {
    string file; 
    cout << "What is the file with the array you want to search? ";
    cin >> file; 
    ifstream fin; 
    fin.open(file);
    if(fin.is_open()) {
        cout << "File is open!" << endl; }
    else {
        return -1; }
    int i = 0; 
    int array[1000];
    string line; 
    int count = 0; 
    istringstream ssin(line); 
    while(getline(fin, line)) { 
        istringstream ss(line); 
        int num; 
        while(ss>>num) {
            if(count <= 1000) {
                array[count++] = num; }
            else {
                break; }}}

    int number;  
    mid = sizeof(array) / 2;
    cout << "What is the number you want to find? Please provide an integer: ";
    cin >> number; 
    int index = binarySearch(array, number, 0, count-1); 
    if(index==-1) {
        cout << number << " is not in " << file << endl;
    }
    else {
        cout << number << " can be found at " << file << "[" << index << "]" << endl;
    }
}