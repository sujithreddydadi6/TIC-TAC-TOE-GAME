// TIC TAC TOE GAME PROJECT IN C
#include<stdio.h>
#include<stdlib.h>
char sq[9]={'0','1','2','3','4','5','6','7','8'};//initalising and declaring the 3*3 square
int checkwin(){
    for(int i=0;i<9;i=i+3){// For all rows
        if(sq[i]==sq[i+1] && sq[i]==sq[i+2])return 1;
    }
    for(int i=0;i<3;i++){//For all coloumns
        if(sq[i]==sq[i+3] && sq[i]==sq[i+6])return 1;
    }
    if(sq[0]==sq[4] && sq[0]==sq[8])return 1;// for diagnol
    if(sq[2]==sq[4] && sq[2]==sq[6])return 1;//For diagnol
    int co=0;
    char h;
    for(int i=0;i<9;i++){
        h=i+'0';
        if(sq[i]!=h)co++;//checking if it is a draw
    }
    if(co==9)return 0;
    return -1;
}

void drawsquare(){
    system("clear");
    printf("Tic Tac Toe\n");
    printf("player-1 X    player-2 O\n");
    printf("%c %c %c\n",sq[0],sq[1],sq[2]);
    printf("%c %c %c\n",sq[3],sq[4],sq[5]);
    printf("%c %c %c\n",sq[6],sq[7],sq[8]);
}
int main(){
    int player=1,i=-1,ch,j=0;
    char mark='I';
    while(i==-1){
        drawsquare();
        if(j==1)printf("Invalid option Enter Again\n");//if option is invalid 
        j=0;
        if(player%2==1){
            player=1;
            mark='X';
        }
        else {
            player=2;
            mark='O';
        }
        printf("It's player-%d turn\n",player);
        scanf("%d",&ch);
        if(ch == 0 && sq[0]=='0')sq[0]=mark;
        else if(ch == 1 && sq[1]=='1')sq[1]=mark;
        else if(ch == 2 && sq[2]=='2')sq[2]=mark;
        else if(ch == 3 && sq[3]=='3')sq[3]=mark;
        else if(ch == 4 && sq[4]=='4')sq[4]=mark;
        else if(ch == 5 && sq[5]=='5')sq[5]=mark;
        else if(ch == 6 && sq[6]=='6')sq[6]=mark;
        else if(ch == 7 && sq[7]=='7')sq[7]=mark;
        else if(ch == 8 && sq[8]=='8')sq[8]=mark;
        else{//if entered ch is invalid
            j=1;
            player--;
        }
        i=checkwin();//check who won the game
        player++;
    }
    drawsquare();
    if(i==1){
        if(player==1)player=2;
        else player=1;
        printf("CONGRATULATIONS\nwinner is player %d",player);
    }
    if(i==0)printf("Game Draw");
}