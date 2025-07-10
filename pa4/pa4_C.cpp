// Olivia Bakke
// Computer Systems
// Programming Assignment 4
// Problem C

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream fout;
    ifstream fin; 

    fin.open("input_files/blahblah.txt"); 
    fout.open("output_files/election_results.txt");
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

    char letter; 
    int a = 0;
    int e = 0;
    int i = 0;
    int o = 0;
    int u = 0;
    while(!fin.eof()){
        fin >> letter;
        if(letter == 'a' || letter == 'A') {
            a = a +1;
        }
        if(letter == 'e' || letter == 'E') {
            e = e +1;
        }
        if(letter == 'i' || letter == 'I') {
            i = i +1;
        }
        if(letter == 'o' || letter == 'O') {
            o = o +1;
        }
        if(letter == 'u' || letter == 'U') {
            u = u +1;
        }
    }
    if(letter == 'a' || letter == 'A') {
        a = a +1;
    }
    if(letter == 'e' || letter == 'E') {
        e = e +1;
    }
    if(letter == 'i' || letter == 'I') {
        i = i +1;
    }
    if(letter == 'o' || letter == 'O') {
        o = o +1;
    }
    if(letter == 'u' || letter == 'U') {
        u = u +1;
    }
    char letter1; 
    if(a>e && a>i && a>o && a>u) {
        letter1 = 'A';
    }
    if(e>a && e>i && e>o && e>u) {
        letter1 = 'E';
    }
    if(i>e && i>a && i>o && i>u) {
        letter1 = 'I';
    }
    if(o>e && o>i && o>a && o>u) {
        letter1 = 'O';
    }
    if(u>e && u>i && u>o && u>a) {
        letter1 = 'U';
    }
    cout << "The results are in!" << endl; 
    cout << "A/a recieved " << a << " votes" << endl;
    cout << "E/e recieved " << e << " votes" << endl;
    cout << "I/i recieved " << i << " votes" << endl;
    cout << "O/o recieved " << o << " votes" << endl;
    cout << "U/u recieved " << u << " votes" << endl;
    cout << "The winner is the letter " << letter1 << endl; 

    fout << "A," << a << endl; 
    fout << "E," << e << endl; 
    fout << "I," << i << endl; 
    fout << "O," << o << endl;
    fout << "U," << u << endl;
}