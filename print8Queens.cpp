#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> pii;
int board[8][8];
int rows[8];

void resetBoard()
{
	int i,j;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
			board[i][j]=0;
	}
}

void printBoard()
{
	int i,j;
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
			cout<<board[i][j]<<" ";
		cout<<endl;
	}
}

void fillBoard()
{
	int i;
	for(i=0;i<8;i++)
	{
		board[rows[i]][i]=1;
	}
}

bool check(int row,int col)
{
	int i,j;
	for(i=0;i<col;i++)
	{
		if(rows[i]==row || abs(i-col)==abs(row-rows[i]))
			return false;
	}
	return true;
}

void generateBoards(int col)
{
	int i,row;
	if(col==8)
	{
		cout<<"Solution found"<<endl;
		fillBoard();
		printBoard();
		resetBoard();
	}
	else
	{
		for(i=0;i<8;i++)
		{
			if(check(i,col))
			{
				rows[col]=i;
				generateBoards(col+1);
			}
		}
	}
	
}

int main()
{
	resetBoard();
	generateBoards(0);

}