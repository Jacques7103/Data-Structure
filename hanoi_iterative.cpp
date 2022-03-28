#include <iostream>
#include <stack>

using namespace std;

int calls = 0;      //Create variable calls to count how many calls happened

class Stack{        //Creating public class "Stack" to declare variable n, first, last, and go
    public:
        int n;
        char first;
        char last;
        char go;
};

void resetCalls(){          //Creating resetCalls function to reset the calls
    calls = 0;
}

//Creating a function that get 4 parameters which are number of disks, the starting and ending position, and the pole that it will only pass through
void Tower_Of_Hanoi(int num, char start, char end, char pass){
    stack<Stack> TOH;       //Creating a stack

    Stack current;          //Creating current variable in Stack class

    while (num >= 1 or !TOH.empty()){       //Creating a while loop with condition num >= 1 and TOH stack isn't empty
        while (num >= 1){                   //Creating a while loop with condition num >= 1 -> to get the function of "(num - 1, start, pass, end)"
            Stack current;                  //Creating current variable in Stack class

            //Setting the variable with data
            current.n = num;                
            current.first = start;
            current.last = end;
            current.go = pass;

            //Push the data into the stack
            TOH.push(current);
            swap(end, pass);                //Swapping the ending position and the passing position
            num--;                          //Decrementing the num
            calls++;                        //Incrementing the calls
        }

        Stack current = TOH.top();          //Getting the latest inserted data into the stack
        TOH.pop();                          //Take out the data from the stack
        cout << "Move disk " << current.n << " from rod " << current.first << " to rod " << current.last << endl;       //Print out what happened

        if (current.n >= 1){                //Creating the function of "(num - 1, pass, end, start)" -> Refer to the one in recursive
            start = current.go;
            pass = current.first;
            end = current.last;
            num = current.n - 1;
        }
    }
}

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