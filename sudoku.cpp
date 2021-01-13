#include<bits/stdc++.h>
using namespace std;
/*To check whether the number to be assigned is already present in entire row or not*/
bool NuminRow(int SudMatrix[9][9], int num, int row)
{
	int a=0;
	for(int column=0; column<9; column++)
		if(SudMatrix[row][column]==num)
			return true;
	return false;
}

/*To check whether the number to be assigned is already present in that column or not*/
bool NuminCol(int SudMatrix[9][9], int num, int column)
{
	for(int row=0; row<9; row++)
		if(SudMatrix[row][column]==num)
			return true;
	return false;
}

/*To check whether the number to be assigned is already present in entire 3 X 3 box or not*/
bool Box(int SudMatrix[9][9], int num, int SRow, int SCol)
{
	for(int row=0; row<3; row++)
		for(int column=0; column<3; column++)
			if(SudMatrix[row+SRow][column+SCol]==num)
				return true;
	return false;
}

/*To check whether the number is safe to assign at that index*/
bool isSafe(int SudMatrix[9][9], int row, int column, int n)
{
	return !NuminRow(SudMatrix, n, row) && !NuminCol(SudMatrix, n, column) && !Box(SudMatrix, n, row-row%3, column-column%3);
}

/*To check whether the position/index is Assigned or Unassigned*/
bool UnassignedLocation(int SudMatrix[9][9], int &row, int &column)
{
	for(row=0; row<9; row++)
		for(column=0; column<9; column++)
			if(SudMatrix[row][column]==0)
				return true;
	return false;
}

/*To solve Sudoku*/
bool SudSolve(int SudMatrix[9][9])
{
	int row,column;
	if(!UnassignedLocation(SudMatrix, row, column))
		return true;
	for(int n=1; n<10; n++)
		if(isSafe(SudMatrix, row, column, n))
		{
			SudMatrix[row][column]=n;
			if(SudSolve(SudMatrix))
				return true;
			SudMatrix[row][column]=0;
		}
	return false;
}

/*To print SudMatrix*/
void printSudMatrix(int SudMatrix[9][9])
{
	for(int row=0; row<9; row++)
	{
		for(int column=0; column<9; column++)
			cout<<SudMatrix[row][column]<<" ";
		cout<<"\n";
	}
}

int main()
{
	int SudMatrix[9][9] = {{0, 5, 0, 3, 1, 4, 0, 6, 0},
					  		  {8, 7, 0, 0, 0, 9, 4, 0, 3},
					  		  {6, 4, 3, 5, 0, 7, 1, 9, 2},
					  		  {0, 0, 7, 8, 0, 5, 2, 1, 0},
					  		  {4, 1, 0, 9, 0, 0, 0, 0, 0},
					  	   	  {0, 2, 5, 0, 6, 1, 9, 0, 7},
					  		  {7, 9, 0, 2, 5, 0, 8, 4, 0},
					  		  {0, 0, 4, 0, 9, 6, 0, 0, 5},
					  		  {0, 3, 0, 1, 0, 8, 6, 7, 0}};
	if(SudSolve(SudMatrix)==true)
		printSudMatrix(SudMatrix);
	else
		cout<<"No Solution of this Sudoku Exists"<<endl;
	return 0;
}
