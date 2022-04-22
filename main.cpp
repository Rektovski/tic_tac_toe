// tic-tac-toe OtarMurmanishvili

#include <bits/stdc++.h>
using namespace std;

char A[5][5];

short i,j;
short check=1;
short Count=1;
char C; // X || O
bool T=true;

void board();
void draw();
void checkWin();
void checkTie();
void clearBoard();
void Rule();

int main(){
    board();
    while(T){
        draw();
        Rule();
    }
}

void board(){
    for(i=0;i<5;++i)A[0][i]=A[4][i]='*';
    for(i=1;i<=3;++i)A[i][0]=A[i][4]='*';
    clearBoard();
}
void draw(){
    for(i=0;i<=4;++i){
        for(j=0;j<=4;++j){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}
void checkWin(){
    if(A[1][1]=='X' && A[1][2]=='X' && A[1][3]=='X' ||
       A[2][1]=='X' && A[2][2]=='X' && A[2][3]=='X' ||
       A[3][1]=='X' && A[3][2]=='X' && A[3][3]=='X' ||
       A[1][1]=='X' && A[2][1]=='X' && A[3][1]=='X' ||
       A[1][2]=='X' && A[2][2]=='X' && A[3][2]=='X' ||
       A[1][3]=='X' && A[2][3]=='X' && A[3][3]=='X' ||
       A[1][1]=='X' && A[2][2]=='X' && A[3][3]=='X' ||
       A[3][1]=='X' && A[2][2]=='X' && A[1][3]=='X')cout<<"X wins!\n",draw();

    if(A[1][1]=='Y' && A[1][2]=='Y' && A[1][3]=='Y' ||
       A[2][1]=='Y' && A[2][2]=='Y' && A[2][3]=='Y' ||
       A[3][1]=='Y' && A[3][2]=='Y' && A[3][3]=='Y' ||
       A[1][1]=='Y' && A[2][1]=='Y' && A[3][1]=='Y' ||
       A[1][2]=='Y' && A[2][2]=='Y' && A[3][2]=='Y' ||
       A[1][3]=='Y' && A[2][3]=='Y' && A[3][3]=='Y' ||
       A[1][1]=='Y' && A[2][2]=='Y' && A[3][3]=='Y' ||
       A[3][1]=='Y' && A[2][2]=='Y' && A[1][3]=='Y')cout<<"Y wins!\n",draw();

    cout<<"Wanna restart? - Y/N? \n";
    cin>>C;
    if(C=='Y')T=true,clearBoard(),Count=1;
    else T=false;
}
void checkTie(){
    short ans=0;
    for(i=1;i<=3;++i){
        for(j=1;j<=3;++j){
            if(A[i][j]=='X' || A[i][j]=='O')++ans;
        }
    }
    if(ans==9 && T)T=false,draw(),cout<<"Tie! \n";
}
void clearBoard(){
    for(i=1;i<=3;++i){
        for(j=1;j<=3;++j){
            A[i][j]='-';
        }
    }
}
void Rule(){
    if(check==1)check=2,cout<<Count++<<": Input X coordinates: \n\n";
    else check=1,cout<<Count++<<": Input O coordinates: \n\n";
    cin>>C>>i>>j;
    if(A[i][j]=='X' || A[i][j]=='Y'){
        cout<<"This coordinates are already full! \n";
        cout<<"Wanna restart? - Y/N? \n";
        cin>>C;
        if(C=='Y')clearBoard(),Count=1;
        else T=false;
    }
    else if(A[i][j]=='-' && check==2 && C=='X')A[i][j]='X';
    else if(A[i][j]=='-' && check==1 && C=='O')A[i][j]='O';
    else if(A[i][j]=='-' && C!='X' && C!='O'){
        if(check==2)cout<<"ERROR! You must input 'X'. You chose another character. \n";
        else cout<<"ERROR! You must input 'O'. You chose another character. \n";
        cout<<"Wanna restart? - Y/N? \n";
        cin>>C;
        if(C=='Y')T=true,clearBoard(),Count=1;
        else T=false;
    }
    else if(i<1 || i>3 || j<1 || j>3){
        cout<<"ERROR! You must input from 1 to 3. You chose another digit. \n";
        cout<<"Wanna restart? - Y/N? \n";
        cin>>C;
        if(C=='Y')T=true,clearBoard(),Count=1;
        else T=false;
    }
    checkWin();
    checkTie();
}
