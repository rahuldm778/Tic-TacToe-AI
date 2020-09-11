#include<iostream>
using namespace std;
int index1;
char board[9] = {'*','*','*','*','*','*','*','*','*'};// Single array represents the board '*' means empty box in board

int isFull()// Board is full
{
    for(int i =0;i<9;i++)
    {
        if(board[i]!='X')
        {
            if(board[i]!='O')
               {
                 return 0;
               }
        }
    }
return 1;
}

int checkwin()
{
	if (board[1-1] == board[2-1] && board[2-1] == board[3-1] && board[2-1] != '*' )

		return 1;
	else if (board[4-1] == board[5-1] && board[5-1] == board[6-1] && board[5-1] != '*')

		return 1;
	else if (board[7-1] == board[8-1] && board[8-1] == board[9-1] && board[8-1] != '*')

		return 1;
	else if (board[1-1] == board[4-1] && board[4-1] == board[7-1] && board[4-1] != '*')

		return 1;
	else if (board[2-1] == board[5-1] && board[5-1] == board[8-1] && board[5-1] != '*')

		return 1;
	else if (board[3-1] == board[6-1] && board[6-1] == board[9-1] && board[6-1] != '*')

		return 1;
	else if (board[1-1] == board[5-1] && board[5-1] == board[9-1] && board[5-1] != '*')

		return 1;
	else if (board[3-1] == board[5-1] && board[5-1] == board[7-1] && board[5-1] != '*')

		return 1;
	else if (board[1-1] != '*' && board[2-1] != '*' && board[3-1] != '*'
                    && board[4-1] != '*' && board[5-1] != '*' && board[6-1] != '*'
                  && board[7-1] != '*' && board[8-1] != '*' && board[9-1] != '*')

		return 0;
	else
		return -1;
}

int user_won()//Checks whether user has won
{
    for(int i=0;i<9;i+=3)
    {
        if((board[i]==board[i+1])&&(board[i+1]==board[i+2])&&(board[i]=='O'))
            return 1;
    }
    for(int i=0;i<3;i++)
    {
        if((board[i]==board[i+3])&&(board[i+3]==board[i+6])&&(board[i]=='O'))
            return 1;
    }
    if((board[0]==board[4])&&(board[4]==board[8])&&(board[0]=='O'))
    {
        return 1;
    }
    if((board[2]==board[4])&&(board[4]==board[6])&&(board[2]=='O'))
    {
        return 1;
    }
    return 0;
}

int cpu_won()// Checks whether CPU has won
{
    for(int i=0;i<9;i+=3)
    {
        if((board[i]==board[i+1])&&(board[i+1]==board[i+2])&&(board[i]=='X'))
            return 1;
    }
    for(int i=0;i<3;i++)
    {
        if((board[i]==board[i+3])&&(board[i+3]==board[i+6])&&(board[i]=='X'))
            return 1;
    }
    if((board[0]==board[4])&&(board[4]==board[8])&&(board[0]=='X'))
    {
        return 1;
    }
    if((board[2]==board[4])&&(board[4]==board[6])&&(board[2]=='X'))
    {
        return 1;
    }
    return 0;
}

void draw_board() //display tic-tac-toe board
{
    cout<<endl;
    cout<<board[0]<<"|"<<board[1]<<"|"<<board[2]<<endl;
    cout<<"-----"<<endl;
    cout<<board[3]<<"|"<<board[4]<<"|"<<board[5]<<endl;
    cout<<"-----"<<endl;
    cout<<board[6]<<"|"<<board[7]<<"|"<<board[8]<<endl;
}

int minimax(bool flag)// The minimax function
{

    int max_val=-1000,min_val=1000;
    int i,j,value = 1;
    if(cpu_won() == 1)
        {return 10;}
    else if(user_won() == 1)
        {return -10;}
    else if(isFull()== 1)
        {return 0;}
    int score[9] = {1,1,1,1,1,1,1,1,1};//if score[i]=1 then it is empty

        for(i=0;i<9;i++)
            {
                 if(board[i] == '*')
                {
                    if(min_val>max_val) // reverse of pruning condition.....
                  {
                      if(flag == true)
                   {
                     board[i] = 'X';
                     value = minimax(false);
                   }
                    else
                    {
                      board[i] = 'O';
                      value = minimax(true);
                    }
                  board[i] = '*';
                  score[i] = value;
                 }
               }
            }

        if(flag == true)
        {
                 max_val = -1000;
                 for(j=0;j<9;j++)
                {
                    if(score[j] > max_val && score[j] != 1)
                    {
                        max_val = score[j];
                        index1 = j;
                    }
                }
                return max_val;
        }
        if(flag == false)
        {
                min_val = 1000;
                for(j=0;j<9;j++)
                {
                    if(score[j] < min_val && score[j] != 1)
                    {
                        min_val = score[j];
                        index1 = j;
                    }
                }
            return min_val;
        }
}

int main() //The main function
{
   int move,choice,mood,posn,player;
   cout<<"-------------------------TIC TAC TOE-----------------------------------------------------";
inva:cout<<endl<<"Enter 1 for Player vs Player. \nEnter 2 for Player vs CPU.";
   cin>>mood;
   if(mood==1){
     cout<<endl<<"Player1--->(O)      Player2------>(X)";
     cout<<endl<<"SELECT : 1-> Player1 first   2-> Player2 first:";
     cin>>player;
     while(checkwin()==-1)
		{
			draw_board();
			player=(player%2)?1:2;
			cout<<"Player "<<player<<" enter your position: ";
			cin>>posn;
			if((posn>=1&&posn<=9)&& board[posn-1]=='*')
			{
				if(player==1)
					board[posn-1]='O';
				else
					board[posn-1]='X';
			}
			else
			{
				cout<<"Invalid Move. \n";
				player--;
			}
			player++;
		}
	    draw_board();
	    if(checkwin()==1)
		    cout<<"==>\aPlayer "<<--player<<" win ";
	    else
		    cout<<"==>\aGame draw";
   }
   else if(mood == 2 )
   {
     cout<<endl<<"USER--->(O)      CPU------>(X)";
     cout<<endl<<"SELECT : 1-> Player first 2-> CPU first:";
     cin>>choice;
     if(choice == 1)
     {
         draw_board();
        up2:cout<<endl<<"Enter the move:";
           cin>>move;
           if(board[move-1]=='*')
           {
             board[move-1] = 'O';
             draw_board();
           }
           else
           {
               cout<<endl<<"Invalid Move......Try different move";
               goto up2;
           }
     }

      while(true)
      {

          cout<<endl<<"CPU MOVE....";
          minimax(true);
          board[index1] = 'X';
          draw_board();
          if(cpu_won()==1)
          {
              cout<<endl<<"CPU WON.....";
              break;
          }
          if(isFull()==1)
          {
              cout<<endl<<"Draw....";
              break;
          }
  again:  cout<<endl<<"Enter the move:";
          cin>>move;
          if(board[move-1]=='*')
           {
             board[move-1] = 'O';
             draw_board();
           }
           else
           {
               cout<<endl<<"Invalid Move......Try different move";
               goto again;
           }
           if(user_won()==1)
           {
               cout<<endl<<"You Won......";
               break;
           }
           if(isFull() == 1)
          {
              cout<<endl<<"Draw....";
              break;
          }
      }
   }
   else
   {
     goto inva;
   }

    return 0;

}
