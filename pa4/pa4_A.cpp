// Olivia Bakke
// Computer Systems
// Programming Assignment 4
// Problem A

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string garbage; 
    double number; 
    int a = 0;
    int b = 0;
    int c = 0; 
    int d = 0; 
    int f = 0; 
    
    ofstream fout; 
    ifstream fin; 

    fin.open("grades.txt");
    fout.open("statistics.csv");

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

    int x; 

    while(!fin.eof()) {
        fin >> garbage >> garbage >> number; 
        if(number>=90.0) {
            a = a+1; }
        if(number>=80.0 && number<90.0) {
            b = b+1; }
        if(number>=70.0 && number<80.0) {
            c = c+1; }
        if(number>=60.0 && number<70.0) {
            d = d+1; }
        if(number<60.0) {
            f = f+1; }}

    if(number>=90.0) {
        a = a-1; }
    if(number>=80.0 && number<90.0) {
        b = b-1; }
    if(number>=70.0 && number<80.0) {
        c = c-1; }
    if(number>=60.0 && number<70.0) {
        d = d-1; }
    if(number<60.0) {
        f = f-1;}

    
    
    cout << a << " A" << endl; 
    cout << b << " B" << endl;
    cout << c << " C" << endl;
    cout << d << " D" << endl;
    cout << f << " F" << endl; 

    fout << "Grade,NumStudents" << endl;
    fout << "A," << a << endl; 
    fout << "B," << b << endl;
    fout << "C," << c << endl;
    fout << "D," << d << endl;
    fout << "F," << f << endl;
    
    fout.close();
    fin.close(); }