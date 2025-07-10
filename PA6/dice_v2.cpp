#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_NUM_DICE=50;

void userInputParser(string s, int dice[], int maxNumDie) ;

int main() {
    int pairs[2 * MAX_NUM_DICE + 1] = {0};
    srand(time(0)); // DO NOT WRITE THIS LINE AGAIN OR ANYWHERE ELSE
    cout << "What die do you want to roll? (e.g. 4d3+2) ";
    string s;
    getline(cin, s);
    
    
    userInputParser(s, pairs, MAX_NUM_DICE);

    // == Replace the code below this line with your code. ==   

    // This example code will display the array of die information 
    // retrieved from user.

    // pairs[] is an array with the following format:
    // {num_dice,
    //  first_die_start,
    //  first_die_end,
    //  second_die_start,
    //  ... }
    int rounds;
    int total = 0; 
    int max = 0;
    int min = 100000000;
    cout << "How many rounds do you want to roll? ";
    cin >> rounds; 
    int num;
    for(int i=0; i<rounds; i++) {
        num = rand()%(pairs[2]-pairs[1]+1) + pairs[1];
        total = total + num;
        if(num>max) {
            max = num; }
        if(num<min){
            min = num; }}
    float average = total / rounds;
    int sample = rand()%(pairs[2]-pairs[1]+1) + pairs[1];
    cout << "Sample roll: " << sample << endl; 
    cout << "Minimum roll: " << min << endl; 
    cout << "Maximum roll: " << max << endl; 
    cout << "Average roll: " << average << endl; 
    // == Replace the code above this line with your code. ==
    
}


void userInputParser(string s, int dice[], int maxNumDie) {
    // static int dice[2*MAX_NUM_DICE+1] = {}; // array format:
    // {num_dice,
    //  first_die_start,
    //  first_die_end,
    //  second_die_start,
    //  ... }
    // max of MAX_NUM_DICE dice supported

    string data[4*maxNumDie];  // Intermediate storage for parsing input string

    // count how many '+'s or 'd's there are...
    int parts = 0;
    for(int i=0; i < s.length(); i++)
    {
        if(s[i] == 'd' || s[i] == '+')
        {
            parts++;
        }
    }
    // ... so we know the number of times to decode values

    int index=0;
    unsigned d = s.find('d');
    unsigned p = s.find('+');
    while(d != static_cast<unsigned>(-1) || p != static_cast<unsigned>(-1))
    {
        bool dFirst = d < p;
        if(dFirst)
        {
            string before = s.substr(0,d); // part before the 'd' (should be just one number)
            // figure out what number is after 'd'
            int count = 0;
            bool foundDigit=false;
            for(int i=0; i< static_cast<signed>(s.length()-d-1); i++)
            {
                if(isdigit(s[count+d+1]))
                {
                    foundDigit=true;
                }
                if(!isdigit(s[count+d+1]) && foundDigit)
                {
                    break;
                }
                count++;
            }
            string after = s.substr(d+1,count); //should be just the number after 'd'

            // store these two parts
            data[index] = before;
            data[index+1] = after;
            index+=2;


            // remove this part from the string s
            s = s.substr(d+count+1); // discard these two parts
        }
        else // same idea for the '+'
        {
            // figure out what number is after '+'
            int count = 0;
            bool foundDigit=false;
            for(int i=0; i< static_cast<signed>(s.length()-p-1); i++)
            {
                if(isdigit(s[count+p+1]))
                {
                    foundDigit=true;
                }
                if(!isdigit(s[count+p+1]) && foundDigit)
                {
                    break;
                }
                count++;
            }
            string after = s.substr(p+1,count); //should be just the number after '+'

            // store this part
            data[index] = "+";
            data[index+1] = after;
            index+=2;


            // remove this part from the string s
            s = s.substr(p+count+1); // discard these two parts
        }

        // update d and p for next loop interation
        d = s.find('d');
        p = s.find('+');

    }

    // now we need to figure out how many dice there are (as 2d4 is 2 dice)
    // we will treat "+2" as a die that rolls [2,2]
    int diceCount = 0;
    for(int i=0; i < parts*2; i+=2)
    {
        if(data[i][0] == '+')
        {
            diceCount++;
        }
        else
        {
            diceCount+=atoi(data[i].c_str());
        }
    }

    dice[0] = diceCount*2+1; // put size in first index

    int ind=1; // index for the "dice" array (as not same as data array)
    for(int i=0; i < parts*2; i+=2)
    {
        // if we have a +, add a "Dice" that has a range of 0
        if(data[i][0] == '+')
        {
            dice[ind] = atoi(data[i+1].c_str());
            dice[ind+1] = atoi(data[i+1].c_str());

            ind+=2;
        }
        else // otherwise add however many of the dice requested
        {
            for(int j=0; j < atoi(data[i].c_str()); j++)
            {
                dice[ind] = 1;
                dice[ind+1] = atoi(data[i+1].c_str());

                ind += 2;
            }
        }
    }

}
