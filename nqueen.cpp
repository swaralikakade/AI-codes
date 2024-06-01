#include<iostream>
using namespace std;

bool isSafe(int** arr, int x, int y, int n){
    //checking if there's already a queen in the same column
    for(int row=0; row<x; row++)
    {
        if(arr[row][y]==1)
        {
            return false;
        }
    }
    
    int row =x;
    int col =y;
    //checking the upper-left diagonal to ensure there's no queen there
    while(row>=0 && col>=0)
    {
        if(arr[row][col]==1)
        {
            return false;
        }
        row--;
        col--;
    }
    
    row =x;
    col=y;
    //checking the upper-right diagonal to ensure there's no queen there
    while(row>=0 && col<n){
        if(arr[row][col]==1)
        {
            return false;
        }
        row--;
        col++;
    }
    
    return true;
}

bool nQueen(int** arr, int x, int n)
{
    if(x>=n){ //queens are already filled
        return true;
    }
    
    for(int col=0; col<n; col++)
    {
        if(isSafe(arr, x, col, n))
        {
            arr[x][col]=1;
            if(nQueen(arr, x+1, n)){
                //moving to the next row (x+1) by calling nQueen(arr, x+1, n)
                return true;
            }
            arr[x][col]=0;//if no solution is found backtrack by resetting arr[x][col] to 0 to remove the queen from current position
        }
    }
    
    return false;
    
}




int main(){
    int n;
    cout<<"Enter the size of the chessboard: "<<endl;
    cin>>n;
    
    int** arr= new int*[n];
    for(int i=0; i<n; i++)
    {
        arr[i] = new int[n]; //to allocate the memory for an array of integers of size 'n'
        for(int j=0; j<n; j++)
        {
            arr[i][j]=0;//initializing cells on chessboard to 0
        }
    }
    

    //printing the output
    if(nQueen(arr,0,n)){//starting from 0th row
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<< arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}










/*

Using arrays

#include <iostream>
#include <cmath>
using namespace std;

// Function to check if it is safe to place a queen at position (row, col)
bool isSafe(int board[], int row, int col) {
    // Check if there's a queen in the same column
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

// Function to solve N-Queens using backtracking
bool solveNQueensBacktracking(int board[], int row, int n) {
    if (row == n) {
        // All queens are successfully placed
        return true;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            if (solveNQueensBacktracking(board, row + 1, n)) {
                return true;
            }
            // Backtrack if placing the queen at (row, col) doesn't lead to a solution
            board[row] = -1;
        }
    }
    return false;
}

// Function to solve N-Queens using branch and bound
bool solveNQueensBranchBound(int board[], int row, int n) {
    if (row == n) {
        // All queens are successfully placed
        return true;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            // Check if the current configuration can lead to a solution
            if (solveNQueensBranchBound(board, row + 1, n)) {
                return true;
            }
            // If not, backtrack
            board[row] = -1;
        }
    }
    return false;
}

// Function to print the N-Queens solution
void printSolution(int board[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}

// Main function
int main() {
    int n;
    cout << "Enter the size of the chessboard (N x N): ";
    cin >> n;
    
    int* board = new int[n]; // Dynamically allocate memory for the board
    
    // Initialize board with -1 (no queen placed)
    for (int i = 0; i < n; i++) {
        board[i] = -1;
    }
    
    // Solve using backtracking
    cout << "Solving N-Queens using Backtracking:\n";
    if (solveNQueensBacktracking(board, 0, n)) {
        cout << "Solution found:\n";
        printSolution(board, n);
    } else {
        cout << "No solution exists.\n";
    }
    
    // Solve using branch and bound
    cout << "\nSolving N-Queens using Branch and Bound:\n";
    if (solveNQueensBranchBound(board, 0, n)) {
        cout << "Solution found:\n";
        printSolution(board, n);
    } else {
        cout << "No solution exists.\n";
    }
    
    delete[] board; // Deallocate memory
    
    return 0;
}


*/








/*

sagle solutions dakhavnara code




#include<iostream>
using namespace std;
#define MAX_N 10

void printSolution(bool board[MAX_N][MAX_N],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]){
                cout<<"Q ";
            }
            else{
                cout<<". ";
            }
        }
        cout<<endl;
    }

    
}

bool isSafe(bool board[MAX_N][MAX_N],int row,int col,int n){
    for(int i=0;i<col;i++){
        if(board[row][i]){
            return false;
        }
    }

    for(int i=row,j=col;j>=0 && i>=0;i--,j--){
        if(board[i][j]){
            return false;
        }
    }

    for(int i=row,j=col;j>=0 && i<n;i++,j--){
        if(board[i][j]){
            return false;
        }
    }


    return true;
}


bool solveNQueensUtil(bool board[MAX_N][MAX_N],int col,int n){
    if(col==n){
        printSolution(board,n);
        cout<<endl;
         return true;
    }
   

    bool res=false;
    for(int i=0;i<n;i++){
        if(isSafe(board,i,col,n)){
            board[i][col]=true;
            res=solveNQueensUtil(board,col+1,n) || res;
            board[i][col]=false;
        }
    }

    return res;

}

void solveNQueens(int n){

    bool board[MAX_N][MAX_N]={false};

    if(!solveNQueensUtil(board,0,n)){
        cout<<"solution does not exist:";
        cout<<endl;
    }
}


int main(){
    int n;
    cout<<"enter total no  of queens:";
    cin>>n;
    cout<<endl;
    solveNQueens(n);
}

*/