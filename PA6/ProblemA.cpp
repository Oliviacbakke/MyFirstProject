#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std; 

class Dice {
    private:
        int min; 
        int max;
    public:
        Dice() {min = 1; max = 6;}
        Dice(int mi, int ma) {min = mi; max = ma;}
        int roll() {return rand()%(max - min + 1) + min;}
};

int main() {
    int minimum;
    int maximum;
    cout << "Let's set up a die to roll. WHat are the minimun and maximum values for this die?" << endl; 
    cout << "Minimum Value: ";
    cin >> minimum;
    cout << "Maximum Value: ";
    cin >> maximum; 
    Dice dice = Dice(minimum, maximum);
    for(int i=1; i<11; i++) {
        int value = dice.roll();
        cout << "Roll #" << i << " was: " << value << endl;}
}