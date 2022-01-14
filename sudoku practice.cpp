#include<bits/stdc++.h>
using namespace std;
#define n 9


bool findEmptyLocation(int board[n][n],int &row, int &col)
{
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == 0)
            {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}
bool isSafeGrid(int board[n][n], int row, int col, int num)
{
    int rowFactor = row - (row%3), colFactor = col - (col%3);
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3 ; j++)
        {
            if(board[i + rowFactor][j + colFactor] == num)
            {
                return false;
            }
        }
    }
    return true;
}
bool isSafeCol(int board[n][n], int col, int num)
{
    for(int i = 0; i < n; i++)
    {
        if(board[i][col] == num)
        {
            return false;
        }
    }
    return true;
}
bool isSafeRow(int board[n][n], int row, int num)
{
    for(int i = 0; i < n; i++)
    {
        if(board[row][i] == num)
        {
            return false;
        }
    }
    return true;
}
bool isSafe(int board[n][n], int row, int col, int num)
{
    if(isSafeRow(board,row,num) && isSafeCol(board, col, num) && isSafeGrid(board, row, col, num))
    {
        return true;
    }
}

bool solveSudoku(int board[n][n])
{
    int row,col;
    if(!findEmptyLocation(board,row,col))
    {
        return true;
    }
    for(int x = 1; x <=9; x++)
    {
        if(isSafe(board,row,col,x))
        {
            board[row][col] = x;
            if(solveSudoku(board))
            {
                return true;
            }
            board[row][col] = 0;

        }
    }
    return false;

}
int main()
{
    int board[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <n; j++)
        {

            cin>>board[i][j];
            cout<<" ";
        }

        cout<<endl;
    }
    solveSudoku(board);
    cout<<endl<<endl<<endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <n; j++)
        {
            if(j%3 == 0 && j!=0)
            {
                cout<<"\t";
            }
            cout<<board[i][j]<<" ";
        }
        if((i+1)%3==0 && i!=0)
        {
            cout<<endl;
        }
        cout<<endl;
    }

}
