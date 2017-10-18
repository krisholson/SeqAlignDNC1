#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <time.h>

using namespace std;

string x, y;
int row=0;
int col=0;
int cost=0;
int penalty=0;
vector<vector<int>> arr;
char letters [4] = {'A','C','T','G'};
const int MIN_LENGTH = 3;
const int MAX_LENGTH = 7;
const int COUNT_LETTERS = 4;
string aSequence;


string sequence()
{
	srand(12345);
	srand(rand());
	int ltrIndex;
	int lengthIndex = rand() % (MAX_LENGTH - MIN_LENGTH) + MIN_LENGTH;
	for (int length = 0; length < lengthIndex; length++)
	{
		ltrIndex = rand() % COUNT_LETTERS;
		aSequence += letters[ltrIndex];
	}
	return aSequence;
}

int opt(int i, int j)
{
	if (i == row)
	
	cost = 2 * (col - j);
	
	else if (j == col)
	
	cost = 2 * (row - i);
	
	else
	{
		if (x[i] == y[j])
		{
			penalty = 0;
		}
		else
		{
			penalty = 1;
		}
		cost = min({ opt(i + 1, j + 1) + penalty, opt(i + 1, j) + 2, opt(i, j + 1) + 2 });
	}
	return cost;
}

void createTable(int r, int c)
{
	for (int ro = 0; ro < r+1; ro++)
	{
		arr.push_back(vector<int>());
		for (int co = 0; co < c+1; co++)
		{
			arr.at(ro).push_back(-1);
		}
	}
}

void optDP(int m, int n)
{
	for (int i = m; i >= 0; i--)
	{
		for (int j = n; j >= 0; j--)
		{
			if (i == row)
			{
				cost = 2 * (col - j);
			}
			else if (j == col)
			{
				cost = 2 * (row - i);
			}
			else
			{
				if (x[i] == y[j])
				{
					penalty = 0;
				}
				else
				{
					penalty = 1;
				}
				cost = min({ arr[i + 1][j + 1] + penalty, arr[i + 1][j] + 2,
					arr[i][j + 1] + 2 });
			}
			arr[i][j] = cost;
		}
	}
}

int main()
{
	/*cout << "Input your first DNA sequence: ";
	cin >> x;
	
	cout << "Input your second DNA sequence: ";
	cin >> y;*/
	/*x = "AACAGTTACC";
	y = "TAAGGTCA";*/
	/*x = "aaca";
	y = "taag";*/
	x = sequence();
	y = sequence();
	row= x.size();
	col= y.size();
	for (size_t i = 0; i < x.size(); i++)//print out string
	{
		cout << x[i];
	}
	cout << endl;
	for (size_t i = 0; i < y.size(); i++)//print out string
	{
		cout << y[i];
	}
	cout << endl;
	createTable(row, col);
	optDP(row, col);
	cout << "The cost of an optimal alignment is: " << arr[0][0] << endl;
	cout << "OR recursively:" << opt(0,0) << endl;
	system("Pause");
	return 0;
}