Cpp Program to solve Sudoku.
Sudoku is 9x9 grid/matrix and each containing 3x3 subgrids in which for every unassigned position we have to fill a number ranging between 1-9 keeping in view the different conditions for solving the puzzle.
With the help of this program, different functions are created to solve and present the Sudoku puzzle correctly. 
bool NuminRow()
To check whether the number to be assigned is already present in entire row or not
bool NuminCol()
To check whether the number to be assigned is already present in that column or not.
bool Box()
To check whether the number to be assigned is already present in entire 3 X 3 box or not.
 bool isSafe()
To check whether the number is safe to assign at that index.
 bool UnassignedLocation()
To check whether the position/index is Assigned or Unassigned
 bool SudSolve()
To solve sudoku
void printSudMatrix()
To print Sudoku Matrix
In main function assigned values are already there whereas 0 denotes the unassigned value that has to be solved.
And if there will be no solution then a proper message will be displayed.
