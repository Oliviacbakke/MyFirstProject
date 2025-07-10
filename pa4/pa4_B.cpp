// Olivia Bakke
// Computer Systems
// Programming Assignment 4
// Problem B

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream fout;
    ifstream fin; 

    fin.open("statistics.csv");
    fout.open("histogram.txt");

    if(fin.is_open()) {
        cout << "Working!" << endl; 
    }
    else {
        cout << "Not Working" << endl; 
        return 0;
    }
    if(fout.is_open()) {
        cout << "Working!" << endl;  
    }
    else {
        cout << "Not Working" << endl; 
        return 0; }

    char garbage;
    string garbage1;
    int a = 0, b = 0, c = 0, d = 0, f = 0; 

    getline(fin, garbage1); 
    fin >> garbage >> garbage >> a;
    fin >> garbage >> garbage >> b;
    fin >> garbage >> garbage >> c;
    fin >> garbage >> garbage >> d;
    fin >> garbage >> garbage >> f;

    // include <sstream>
    // getline(fin, garbage);
    // istringstream ssin(garbage); 
    // int i = 0;
    // string value; 
    // while(getline(ssin, value, ',')) {
    //    cout << "value " << i << " is:" << value << endl;
    //    i++;}
    
    fout << "A ";
    for(int i=0; i<a; i++) {
        fout << "X "; 
    }
    fout << endl << "B ";
    for(int i=0; i<b; i++) {
        fout << "X "; 
    }
    fout << endl << "C ";
    for(int i=0; i<c; i++) {
        fout << "X "; 
    }
    fout << endl << "D ";
    for(int i=0; i<d; i++) {
        fout << "X "; 
    }
    fout << endl << "F ";
    for(int i=0; i<f; i++) {
        fout << "X "; 
    }

    int number; 
    if(a>b && a>c && a>d && a>f) {
        number = a; 
    }
    if(b>a && b>c && b>d && b>f) {
        number = b; 
    }
    if(c>b && c>a && c>d && c>f) {
        number = c; 
    }
    if(d>b && d>c && d>a && d>f) {
        number = d; 
    }
    if(f>b && f>c && f>d && f>a) {
        number = f; 
    }

    fout << endl << "==";
    for(int i=0; i<number; i++) {
        fout << "=="; 
    }
    fout << endl << "  "; 
    for(int i=0; i<number; i++) {
        fout << i+1 << " "; 
    }
    

    fin.close();
    fout.close(); 
    
}