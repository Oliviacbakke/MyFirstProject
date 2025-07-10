// Olivia Bakke
// Computer Systems
// Programming Assignment 5
// Problem C 

#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int k; 

void doArray(char* argv[], int array[300][300]) {
    string thing = argv[1]; 
    ifstream fin; 
    fin.open(thing);
    int i; 
    int j; 
    int m = 0; 
    int q = 0; 
    int s = 0; 
    string thing1; 
    getline(fin, thing1); 
    k = thing1.length(); 

    for(int l=0; l<k;) { 
        if((thing1[l]==' ')) { 
            m++; } 
        else if((thing1[l]=='-')) { 
            m++; } 
        l++; } 

    for(int p=0; p<k; p++) { 
        if(thing1[p]!=' '&&thing1[p]!='-') { 
            array[0][q] = (thing1[p]-48); 
            q++;  }} 

    for(int r=0; r<k; r++) { 
        if(thing1[r]!=' '&&thing1[r]!='-') { 
            s++; } 
        if(thing1[r]=='-') { 
            array[0][s] = -(array[0][s]); }} 
    k = k - m; 
    for(i=1; i<k; i++) {
        for(j=0; j<k; j++) {
            fin >> array[i][j]; } } 
    for(int t=0; t<k; t++) {
        for(int u=0; u<k; u++) {
            std::cout << array[t][u] << " ";
        }
        std::cout << endl; }
    std::cout << k << endl;}

void regular(int array[300][300], int i, int j, int array1[100][100]) { //checked
    array1[i][j] = ((array[i][j] + array[i+1][j] + array[i-1][j] + array[i+1][j+1] + array[i+1][j-1] + array[i-1][j-1] + array[i-1][j+1] + array[i][j+1] + array[i][j-1]) / 9);}

void tlcorn(int array[300][300], int i, int j, int array1[100][100]) { //checked 
    array1[i][j] = (array[j][i] + array[i+1][j] + array[i+1][j+1] + array[i][j+1]) / 4; }

void trcorn(int array[300][300], int i, int j, int array1[100][100]) { //checked
    array1[i][j] = (array[i][j] + array[i][j-1] + array[i+1][j-1] + array[i+1][j]) / 4;}

void topRow(int array[300][300], int i, int j, int array1[100][100]) { //checked
    array1[i][j] = (array[i][j] + array[i+1][j] + array[i+1][j+1] + array[i][j+1] + array[i+1][j-1] + array[i][j-1]) / 6;}

void blcorn(int array[300][300], int i, int j, int array1[100][100]) { //checked
    array1[i][j] = (array[i][j] + array[i-1][j] + array[i-1][j+1] + array[i][j+1]) / 4;}

void brcorn(int array[300][300], int i, int j, int array1[100][100]) { //checked
    array1[i][j] = (array[i][j] + array[i][j-1] + array[i-1][j-1] + array[i-1][j]) / 4; }

void botRow(int array[300][300], int i, int j, int array1[100][100]) { //checked
    array1[i][j] = (array[i][j] + array[i-1][j] + array[i-1][j-1] + array[i][j-1] + array[i-1][j+1] + array[i][j+1]) / 6; }

void lCol(int array[300][300], int i, int j, int array1[100][100]) { //checked 
    array1[i][j] = (array[i][j] + array[i][j+1] + array[i+1][j] + array[i-1][j] + array[i-1][j+1] + array[i+1][j+1]) / 6; }

void rCol(int array[300][300], int i, int j, int array1[100][100]) { //checked
    array1[i][j] = (array[i][j] + array[i-1][j] + array[i+1][j] + array[i][j-1] + array[i+1][j-1] + array[i-1][j-1]) / 6;}

void fixArray(int array[300][300], int array1[100][100]) {
    for(int i=0; i<k; i++) {
        for(int j=0; j<k; j++) {
            if(j==0&&i==0) { //top left corner
                tlcorn(array, i, j, array1); } 
            else if(j==k-1&&i==0) { //top right corner
                trcorn(array, i, j, array1);} 
            else if(i==0&&j!=0&&j!=k-1) { //top row
                topRow(array, i, j, array1);}
            else if(j==0&&i==k-1) { //bottom left corner
                blcorn(array, i, j, array1);}  
            else if(j==k-1&&i==k-1) { // bottom right corner 
                brcorn(array, i, j, array1);} 
            else if(i==k-1&&j!=k-1&&j!=0) { //bottom row
                botRow(array, i, j, array1);}
            else if(j==0&&i!=0&&i!=k-1) { //left column 
                lCol(array, i, j, array1); }
            else if(j==k-1&&i!=0&&i!=k-1) { //right column
                rCol(array, i, j, array1);}
            else {
                regular(array, i, j, array1);  }}}
    std::cout << endl; 


    for(int i=0; i<k; i++) {
        for(int j=0; j<k; j++) { 
            std::cout << array1[i][j] << " "; }
        std::cout << endl; 
    }}   


int main(int argc, char* argv[]) {
    int array[300][300];
    int array1[100][100]; 
    doArray(argv, array); 
    fixArray(array, array1); 
        }