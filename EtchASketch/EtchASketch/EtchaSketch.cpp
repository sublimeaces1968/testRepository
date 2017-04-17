#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <stdlib.h>
using namespace std;

// CONSTANTS
const int HEIGHT = 100;
const int WIDTH = 200;
const int MAX_TESTS = 100;
const int MAX_MOVES = 100;
//VARIABLES
int etchArray [WIDTH][HEIGHT];
int posX, posY;



//Methods
int NumOfTests();
int NumOfMoves();
int StylusMove(char, int);
int ArrayMove(int,int);
void ArrayClear();
void resultPrint(int testResults[], int tests);
void ArrayPrint();

int main()
{
	int testResults[MAX_TESTS];
    int tests = NumOfTests();
	for(int x=0;x<tests;x++)
	{
	    ArrayClear();
	    int squareCount = 1;
	    int moves = NumOfMoves();
	    string moveInput;
	    getline(cin, moveInput);
	    stringstream ss(moveInput);
	    for(int i = 0; i < moves; i++)
	    {
	    	char direction;
	    	int distance;
	    	ss >> direction >> distance;
    	    int count = StylusMove(direction, distance);
    	    squareCount += count;
	    }//end for num of moves
	    testResults[x] = squareCount;
		ArrayPrint();
    }//end for num of tests
	resultPrint(testResults,tests);
}///end main
    
void resultPrint(int testResults[], int tests)
{
    for(int i=0; i < tests; i++)
    {
    	int count = testResults[i];
    	cout << "Test Case " << i+1 << " total moves : " << count << endl; 
    }
	system("pause");

}//end print

void ArrayPrint(){
	for(int x=0; x<WIDTH+2; x++){
		cout << "-";
	}
	cout << endl;
	for(int y=HEIGHT-1; y >= 0; y--){
		cout << "|";
		for(int x=0; x<WIDTH; x++){
			int square = etchArray[x][y];
			if(square == 1){
				cout << "X";
			}
			else{
				cout << " ";
			}
		}
		cout << "|" << endl;
	}
	for(int x=0; x<WIDTH+2; x++){
		cout << "-";
	}
	cout << endl;
}

void ArrayClear()
{
    for(int y=0; y < HEIGHT; y++)
    {
    	for(int x=0; x < WIDTH; x++)
    	{
    	    etchArray[x][y] = 0;
    	}//end for
    }//end for
    etchArray[0][0] = 1;
    posX = posY = 0;
    return;
}//end setArray

int ArrayMove(int deltaX, int deltaY)
{
    int count = 0;
    
    int signX = (deltaX > 0) - (deltaX < 0);
	int onePastDestinationX = posX+deltaX+signX;
	for(int x=posX; x < WIDTH && x >= 0 && x != onePastDestinationX; x += signX)
    {
		posX = x;
        if(etchArray[x][posY] == 0)
        {
        	count++;
        	etchArray[x][posY] = 1;
        }
    }
    
    int signY = (deltaY > 0) - (deltaY < 0);
	int onePastDestinationY = posY+deltaY+signY;
	for(int y=posY; y < HEIGHT && y >= 0 && y != onePastDestinationY; y += signY)
    {
		posY = y;
        if(etchArray[posX][y] == 0)
        {
        	count++;
        	etchArray[posX][y] = 1;
        }
    }
    return count;
}//end arrayMove

int StylusMove(char direction, int distance){
    int deltaX=0;
    int deltaY=0;
    direction = char(toupper(direction));
    switch(direction)
    {
        case ('U'):
            deltaY+=distance;
            break;
        case ('D'):
            deltaY-=distance;
            break;
        case ('L'):
            deltaX-=distance;
            break;
        case ('R'):
            deltaX+=distance;
            break;
        default:
            cout << "Unsupported direction entered, try again!" << endl;
            system("Pause");
             exit(1);
    }//end switch
    
    return ArrayMove(deltaX,deltaY);
    
}//end stylusmove

int NumOfTests(){
    string numTests;
	cout << "Enter the amount of tests you want to perform" << endl;
	getline(cin, numTests);
	int tests = atoi(numTests.c_str());
	if (tests < 0 || tests > 100)
	{
		cout << "Tests not within exeptable ranges" << endl;
		system("pause");
		exit(1);
	}//end if out of range

	return tests;
}//end moves 

int NumOfMoves(){
    string numMoves;
    getline(cin,numMoves,' ');
    int numofMoves = atoi(numMoves.c_str());
    if(numofMoves < 0 || numofMoves > MAX_MOVES)
    {
        cout << "Please enter a number of moves within the accepted range" <<endl;
        system("pause");
        exit(1);
	}//end if out of range
	return numofMoves;
}
