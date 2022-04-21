#include <bits/stdc++.h>
using namespace std;

char A[5][5];

bool T=true;

void board();
void draw();
void checkWin();

int main() {
    short i,j,check=1;
    char C; // X || Y
    board();
    while(T){
        draw();
        if(check==1)check=2,cout<<"Input X coordinates: \n\n";
        else check=1,cout<<"Input O coordinates: \n\n";
        cin>>C>>i>>j;
        if(A[i][j]=='-' && check==2 && C=='X')A[i][j]='X';
        else if(A[i][j]=='-' && check==1 && C=='O')A[i][j]='O';
            else {cout<<"ERROR!\n";break;}
        checkWin();
    }
}

void board(){
    short i,j;
    for(i=0;i<5;++i)A[0][i]=A[4][i]='*';
    for(i=1;i<=3;++i)A[i][0]=A[i][4]='*';
    for(i=1;i<=3;++i){
        for(j=1;j<=3;++j){
            A[i][j]='-';
        }
    }

}
void draw(){
    short i,j;
    for(i=0;i<=4;++i){
        for(j=0;j<=4;++j){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}
void checkWin(){
    if(A[1][1]=='X' && A[1][2]=='X' && A[1][3]=='X')T=false,cout<<"X wins!\n",draw();
    if(A[2][1]=='X' && A[2][2]=='X' && A[2][3]=='X')T=false,cout<<"X wins!\n",draw();
    if(A[3][1]=='X' && A[3][2]=='X' && A[3][3]=='X')T=false,cout<<"X wins!\n",draw();
    if(A[1][1]=='X' && A[2][1]=='X' && A[3][1]=='X')T=false,cout<<"X wins!\n",draw();
    if(A[1][2]=='X' && A[2][2]=='X' && A[3][2]=='X')T=false,cout<<"X wins!\n",draw();
    if(A[1][3]=='X' && A[2][3]=='X' && A[3][3]=='X')T=false,cout<<"X wins!\n",draw();
    if(A[1][1]=='X' && A[2][2]=='X' && A[3][3]=='X')T=false,cout<<"X wins!\n",draw();
    if(A[3][1]=='X' && A[2][2]=='X' && A[1][3]=='X')T=false,cout<<"X wins!\n",draw();

    if(A[1][1]=='Y' && A[1][2]=='Y' && A[1][3]=='Y')T=false,cout<<"Y wins!\n",draw();
    if(A[2][1]=='Y' && A[2][2]=='Y' && A[2][3]=='Y')T=false,cout<<"Y wins!\n",draw();
    if(A[3][1]=='Y' && A[3][2]=='Y' && A[3][3]=='Y')T=false,cout<<"Y wins!\n",draw();
    if(A[1][1]=='Y' && A[2][1]=='Y' && A[3][1]=='Y')T=false,cout<<"Y wins!\n",draw();
    if(A[1][2]=='Y' && A[2][2]=='Y' && A[3][2]=='Y')T=false,cout<<"Y wins!\n",draw();
    if(A[1][3]=='Y' && A[2][3]=='Y' && A[3][3]=='Y')T=false,cout<<"Y wins!\n",draw();
    if(A[1][1]=='Y' && A[2][2]=='Y' && A[3][3]=='Y')T=false,cout<<"Y wins!\n",draw();
    if(A[3][1]=='Y' && A[2][2]=='Y' && A[1][3]=='Y')T=false,cout<<"Y wins!\n",draw();
}