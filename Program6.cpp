/*

Name:	Gulnoza Khakimova
Course: CS 201R
Program: Teddy Bear Game
Due Date:	04/24/2016
Description: Program that uses a recursive function to carry out a depth-first search.
Inputs:	User input the number of teddy bears.
Outputs: Steps to get 17 teddy bears.
Algorithm:
1. Start the game with N teddy bears, 0 < N <= 10,000.
2. Ask for or give back teddy bears according to these rules:
   a) If the number of teddy bears you have is an even number, you can turn in (remove) 
   exactly half the teddy bears you have.
   b) If the number of teddy bears you have is a multiple of 3, you can ask for (receive) 
   one third as many teddy bears as you currently have. (So if you have 33, you can ask for another 11.)
   c) You can always ask for (receive) exactly 23 teddy bears.
3. There is no priority among the rules; you may choose any rule that applies in a given situation.
4. The number of teddy bears you hold must always be greater than 0 and can never be more than 10,000.
5. The object of the game is to end with exactly 17 teddy bears in no more than 20 turns.


*/


#include <iostream>
#include <string>
using namespace std;

bool TeddyBears(int n);
int turns = 0;
string steps = "";

int main()
{ // initialize variables;
    int numberOfBears;
    char answer;
    do
    {// ask user input number of teddy bears
        cout << "How many bears are you starting with?" << endl;
        cin >> numberOfBears;
        if (numberOfBears < 0 || numberOfBears > 10000)
        { // loop while user will not enter correct value
            do
            {
                cout << "Number of bears should be more than 0 and less than 10000" << endl;
                cout << "How many bears are you starting with?" << endl;
                cin >> numberOfBears;
            } while (numberOfBears < 0 || numberOfBears > 10000);
        }
        // output result
        cout << "Searching for a solution within 20 moves..." << endl;
        steps = "";
        turns = 0;
        //call funstion to find a solution
        if (TeddyBears(numberOfBears) == true)
        {
           cout << steps;
        }
        
        cout << "Would you like to try againg [Y/N]?" << endl;
        cin >> answer;
    } while (answer != 'N' && answer != 'n');

    system("pause");
    return 0;
}
// recursive functipon
bool TeddyBears(int n)
{// allow to do 20 steps
    if (n > 0 && n < 10000)
    {
        for (; turns <= 20; turns++)
        {// if not =17 reduce the value by half
            if (n != 17)
            {
                if (n % 2 == 0)
                {
                    steps = "Reduce " + (to_string)(n)+" by half to get " + (to_string)(n / 2) + "\n" + steps;
                    n = n / 2;
                    if (n != 17)
                    {//recursive call
                        turns++;
                        return TeddyBears(n);
                    }
                    else
                    {// output the result
                        turns++;
                        cout << "Found solution. I have exactly 17 bears, with " << 20 - turns << " left" << endl;
                        return true;
                    }
                }
                // If the number of teddy bears you have is a multiple of 3, 
                //you can ask for (receive) one third as many teddy bears as you currently have.
                else if (n % 3 == 0)
                {
                    steps = "With " + (to_string)(n)+", add 1/3 to get " + (to_string)(n + (n / 3)) + "\n" + steps;
                    n = n + (n / 3);
                    if (n != 17)
                    {
                        turns++;
                        return TeddyBears(n);
                    }
                    else
                    {
                        turns++;
                        cout << "Found solution. I have exactly 17 bears, with " << 20 - turns << " left" << endl;
                        return true;
                    }
                }
                // always cann ask for 23 teddy bears
                else if (n % 2 != 0 && n / 3 != 0)
                {
                    steps = "With " + (to_string)(n)+", add 23 to get " + (to_string)(n + 23) + "\n" + steps;
                    n = n + 23;
                    if (n != 17)
                    {
                        turns++;
                        return TeddyBears(n);
                    }
                }
            }
            //if found solution with in 20 moves
            else if (n == 17)
            {
                cout << "Found solution. I have exactly 17 bears, with " << 20 - turns << " left" << endl;
                return true;
            }
        }
    }
    // if number of teddy bears are greater that 10000 and less than 0
    else if (n < 0 || n>10000)
    {
        cout << "The number of teddy bears you hold must always be greater than 0 and can never be more than 10,000." << endl;
        return false;
    }
    // if did not find a solution within 20 moves
    cout << "No solution found within 20 moves. Sorry." << endl;
    return false;
}