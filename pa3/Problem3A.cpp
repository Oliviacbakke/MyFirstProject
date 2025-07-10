// Computer Systems
// CLI Lab 3
// Problem A
// Olivia Bakke 

#include <iostream> // cout, etc.
#include <stdlib.h> // srand, rand
#include <cmath> // pow
#include <iomanip> // setprecision
#include <ctime> // time
using namespace std; 


int main() {
    int num;
    cout << "Enter an integer from -50 to 50: ";
    cin >> num; 
    while(num!=0) {
        if(num<=50&&num>0) {
            int i; 
            int j; 
            for(i=1; i<=num;) {
                for(j=1; j<=i;) {
                    cout << i; 
                    j++;}
                cout << endl;
                i++;} }

        else if(num<0&&num>=(-50)) {
            int i; 
            int j; 
            int a = num + (num*(-2));
            for(i=a; i>=1; i--) {
                for(j=i; j>=1; j--) {
                    cout << i;}
                cout << endl;}} 

        else {
            cout << "Sorry, you have entered an out of bounds input! Please enter a valid value." << endl; }

        cout << "Enter an integer from -50 to 50: ";
        cin >> num; 
    }

    cout << "Goodbye" << endl; 
}

