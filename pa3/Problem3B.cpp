// Computer Systems
// CLI Lab 3
// Problem B
// Olivia Bakke 

#include <iostream> // cout, etc.
#include <stdlib.h> // srand, rand
#include <cmath> // pow
#include <iomanip> // setprecision
#include <ctime> // time
using namespace std; 

int range; 
int its; 
int num; 

int randWalk(int oldValue, int size) {
    int number;
    int size1 = size - (size*2);
    number = rand()%(size - size1 + 1) + size1;
    num = num + number; 
    if(num<0) {
        num = 0;
    }
    else if(num>250) {
        num = 250;
    }
    return num;
}

int main() {
    srand(time(0)); 
    cout << "Please enter an initial integer value in the range [0, 250]: ";
    cin >> num; 
    cout << "Please enter the desired number of iterations: ";
    cin >> its; 
    cout << "Please enter the size of each possible update for each iteration:";
    cin >> range; 
    int i;
    for(i=0; i<=its; i++) {
        randWalk(num, range); 
        cout << "Value at iteration # " << i << " is: " << num << endl; 
    }
}