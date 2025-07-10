// Computer Systems
// CLI Lab 3
// Problem C
// Olivia Bakke 

#include <iostream> // cout, etc.
#include <stdlib.h> // srand, rand
#include <cmath> // pow
#include <iomanip> // setprecision
#include <ctime> // time
using namespace std;

double n = 1000000;

int spin_the_wheels(int d, int w) {
    int b = 0; 
    int count = 0; 
    for(int i=0; i<w; i++) {
        int a = rand()%(d - 1 + 1) + 1;
        if(a==b) {
            count = count + 1; }
        b = a;  }
    if(count==(w-1)) {
        return 1;}
    else {
        return 0;}} 

double pow(int d, int w) {
    double a = 1;
    for(int i=1; i<=w; i++) {
        a = a*d; } 
    return a; }
// w=3, d=9: Simulated probability = m/n = 1.2323%. Theoretical Probability = 1.23457%.

int main() {
    srand(time(0));
    int m; 
    int w = 3;
    int d = 9; 
    for(int j=w; j<=6; j++) {
        for(int k=d; k<=27;) {
            for(int i=0; i<=n; i++) { 
                m = m + spin_the_wheels(k, j); }
            double theor = (k / pow(k, j)) * 100;
            double e = (m/n) * 100;
            m = 0;
            cout << "w=" << j << ", d=" << k << ": Simulatd probability = m/n = " << e << "%. Theoretically Probability = " << theor << "%." << endl; 
            k = k+3; }} 
}