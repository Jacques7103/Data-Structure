#include <iostream>
#include <array>

using namespace std;

//Creating call variable to count how many calls happened
int calls = 0;

//Creating a function that get 4 parameters which are the number of disks, the starting and ending position, and the pole that it will only pass through
void Tower_Of_Hanoi(int num, char start, char end, char pass){
    //Incrementing the calls
    calls++;
    //Base Case
    if (num == 1){      //If it's the only disk left in the pole, it will be moved into the "end" pole
        cout << "Top disk of " << start << " is moved into " << end << endl;    //Printing out what happened
    } 
    // General Case
    else {
        Tower_Of_Hanoi(num - 1, start, pass, end);      //Moving the rest of the disk beside the biggest disk into the passing pole
        Tower_Of_Hanoi(1, start, end, pass);            //Moving the biggest disk into the destination pole
        Tower_Of_Hanoi(num - 1, pass, end, start);      //Moving the rest of the disk from the passing pole into the destination pole
    }
}

void resetCalls(){
    calls = 0;
}

//Running the main function
int main(){
    Tower_Of_Hanoi(4, 'A', 'C', 'B');                   //Calling the function Tower_Of_Hanoi with 4 parameters which are number of disk, the starting
                                                        //and ending position, and the pole that it will only pass through
    cout << "Number of calls : " << calls << endl;      //Printing out how many calls happened
    resetCalls();                                       //Calling the function resetCalls to reset the calls
    cout << endl;                                       //Creating a new line
    Tower_Of_Hanoi(5, 'B', 'A', 'C');                   //Calling the function Tower_Of_Hanoi with 4 parameters which are number of disk, the starting
                                                        //and ending position, and the pole that it will only pass through
    cout << "Number of calls : " << calls << endl;      //Printing out how many calls happened
}