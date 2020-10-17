#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

using namespace std;

void drawsym(char c,int i)  //parameters: character to print,number of prints
{
	for(int j=0;j<i;j++)
	{
		cout<<c;
	}
	cout<<"\n";
}
int toss() //to generate a random number between 1-100
{
	int i=rand();
	if(i%2==0)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}
void display_board(char board[3][3]) //parameters: board
{
	system("cls");
	cout<<"\n\t\t\t\tTIC-TAC-TOE\n";
	drawsym('-',80);
	cout<<"\n__________ __________ __________";
	cout<<"\n          |          |";
	for(int i=0;i<3;i++)
	{
		cout<<"\n    "<<board[i][0]<<"     |    "<<board[i][1]<<"     |    "<<board[i][2]<<"\n";
		for(int j=0;j<3;j++)
		{
			cout<<"___"<<"_______|";
		}
		if(i!=2)
		{
			cout<<"\n          |          |";
			cout<<"\n          |          |";
		}
	}
	cout<<"\n";
}
int check_horizontal(char c,char board[3][3]) //parameters: character x or o and board
{
	int count;
	for(int i=0;i<3;i++)
	{
		count=0;
		for(int j=0;j<3;j++)
		{
			if(board[i][j]==c)
			{
				count++;
			}
			if(count==3)
			{
				return 1;
				break;

			}
		}
	}

}
int check_vertical(char c,char board[3][3]) //parameters: x or o and board
{
	int count;
	for(int i=0;i<3;i++)
	{
		count=0;
		for(int j=0;j<3;j++)
		{
			if(board[j][i]==c)
			{
				count++;
			}
			if(count==3)
			{
				return 1;
				break;
			}
		}
	}
}
int check_diagonal(char c,char board[3][3]) //parameters: x or o and board
{
	int count=0;
	for(int i=0;i<3;i++)
	{
		if(board[i][i]==c || board[i][2-i]==c)
		{
			count++;
		}
		if(count==3)
		{
			return 1;
			break;
		}
	}
}
void input(char board[3][3],char p1[20],char p2[20],int e,char x)
{
	char move,y;
	int p;
	char *player1[20],*player2[20];
	int tracker,rch1,rcv1,rcd1,rch2,rcv2,rcd2;
	if(x=='X' || x=='x')
	{
		y='O';
	}
	else if(x=='O' || x=='o')
	{
		y='X';
	}
	if(e==1)
	{
		*player1=p1;
		*player2=p2;
	}
	else if(e==2)
       {
		*player1=p2;
		*player2=p1;
	}
	for(p=1;p<10;p++)
	{
		tracker=0;
		if(p%2!=0)
		{
			cout<<"\n"<<*player1<<" please enter your move: ";
			move=getch();
			cout<<move;
		}
		if(p%2==0)
		{
			cout<<"\n"<<*player2<<" please enter your move: ";
			move=getch();
			cout<<move;
		}
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(move==board[i][j] && p%2!=0)
				{
					board[i][j]=x;
					tracker+=1;
				       rch1=check_horizontal(x,board);
				       rcv1=check_vertical(x,board);
				       rcd1=check_diagonal(x,board);
				}
				if(move==board[i][j] && p%2==0)
				{
					board[i][j]=y;
					tracker+=1;
				       rch2=check_horizontal(y,board);
				       rcv2=check_vertical(y,board);
				       rcd2=check_diagonal(y,board);
				}
			}
		}
		if(tracker==0)
		{
			p--;
			cout<<"Unacceptable input!! Please try again....";
		}
		else
		{
			display_board(board);
		}
		if(rch1==1 || rcv1==1 || rcd1==1)
		{
			drawsym('-',80);
			cout<<*player1<<" WINS THE GAME!!\n";
			drawsym('-',80);
			break;
		}
		if(rch2==1 || rcv2==1 || rcd2==1)
		{
			drawsym('-',80);
			cout<<*player2<<" WINS THE GAME!!\n";
			drawsym('-',80);
			break;
		}
	}
	if(p==10)
	{
		cout<<"\n\nHey!! Game over.... No winner, no loser!";
	}
}
main()
{
	system("cls");
	char board[3][3]={'1','2','3',
			 '4','5','6',
			 '7','8','9'};
	int won,i=1,x1=1,x2=1;
	char p1[20]={0},p2[20]={0},x;
	cout<<"\n\t\t\t\tTIC-TAC-TOE\n";
	drawsym('-',80);
	while(x1<2)
	{
		if(strlen(p1)==0)
		{
			cout<<"\nPlayer 1: Please enter your name: ";
			gets(p1);
			x1=1;
		}
		else
		{
			cout<<"\n";
			drawsym('*',80);
			x1=2;
		}
	}
	while(x2<2)
	{
		if(strlen(p2)==0)
		{
			cout<<"\nPlayer 2: Please enter your name: ";
			gets(p2);
			x2=1;
		}
		else
		{
			cout<<"\n";
			drawsym('*',80);
			x2=2;
		}
	}
	won=toss();
	if(won==1)
	{
		cout<<p1<<" wins the toss!";
	while(i<2)
	{
		cout<<"\nPlease enter your Choice(X or O): ";
		cin>>x;
		if(x=='X' || x=='O' || x=='x' || x=='o')
		{
		     i=2;
		}
		else
		{
			i=1;
		}
	}
	}
	else if(won==2)
	{
		cout<<p2<<" wins the toss!";
	while(i<2)
	{
		cout<<"\nPlease enter your Choice(X or O): ";
		cin>>x;
		if(x=='X' || x=='O' || x=='x' || x=='o')
		{
		     i=2;
		}
		else
		{
			i=1;
		}
	}
	}
	display_board(board);
	input(board,p1,p2,won,x);
	getch();
}
