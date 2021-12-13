#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
//store data of different data types
struct Data 
{ 
string name;
int scores[5]; 
int averageScore;
};
//Defining num_of_score
double num_of_score = 5.0;
//Declairing function
bool GetBowlingData(string file, Data bowlers[], int& r);
void GetAverageScore(Data bowlers[], int r);
void PrettyPrintResults(Data bowlers[], int r);
//defining GetBowlingData() function
bool GetBowlingData(string file, Data bowlers[], int& r) {
	//opening Bowling.txt file
	ifstream In("BowlingScores.txt");

	// if the file doesn't open 
	if (In.fail() == true) {
		// return value false 
		return false;
	}
	//If the file opens
	else
	{
		// Countinuing untill end value
		while (In >> bowlers[r].name) 
		{
			// Initializing i
			int i = 0;
			// Using a do-while loop 
			do {
				In >> bowlers[r].scores[i];
				i++;
			} 
			while (i < 5);
			// increasing r by 1
			r++;
		}
		
	}
	return true;
}
//Defining GetAverageScore() function
void GetAverageScore(Data bowlers[], int r)
{
	//Defining and initializing total_score and x
	double total_score = 0;
	int x = 0;
	//Continue while loop untill x<r
	while (x < r)
	{ //initializing y and total_score
		double total_score = 0;
		int y = 0;
		//continue while loop untill y<5
		while (y < 5)
		{
			//calculating total score
			total_score = total_score + bowlers[x].scores[y];
			y++;
		}
		//calculating average score
		bowlers[x].averageScore = total_score / num_of_score;
		bowlers[x].averageScore = (int)bowlers[x].averageScore;
		//increasing x by 1
		x++;
	}
}
//Defining PrettyPrintResults() function
void PrettyPrintResults(Data bowlers[], int r)
{
	//printing the hearder aligned to the left
	cout << left << setw(10) << "Name      1st_score     2nd_score       3rd_score       4th_score      5th_score       Average_score" << endl;
	//for loop continues untill i<r
	for (int i = 0; i < r; i++)
	{
		//printing result aligned to left
		cout << setw(10) << left << bowlers[i].name;
		//continuing for loop untill j<5
		for (int j = 0; j <5; j++)
		{
			//pritng scores
			cout << bowlers[i].scores[j] << "\t\t";
		}
		//printing averagescore
		cout << setw(5) << bowlers[i].averageScore << endl;
	}
}
//Defining the main() function
int main()
{
	//defining variables and initial value
    int r = 0;
	string file = "BowlingScores.txt";
	Data bowlers[10];
	//	//if GetBowlingData has values then do the follwings
	if (GetBowlingData(file, bowlers, r))
	{
		GetAverageScore(bowlers, r);
		PrettyPrintResults(bowlers, r);
	}
	//else print "No file found"
	else {
		cout << "No File Found" << endl;
	}
	return 0;
}