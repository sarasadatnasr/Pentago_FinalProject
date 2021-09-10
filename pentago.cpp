#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <windows.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

struct Point{
    int x;
    int y;
};

// Point SelectPoints[36];

wstring wTable[14];
wstring wTempTable[14];
wstring wSelectSmall[3];
wstring wSelectBig[7];


int smallSelectCordinates[36];

int main(){

//_setmode(_fileno(stdout), _O_U8TEXT);
_setmode(_fileno(stdout), _O_U16TEXT);
SetConsoleOutputCP(CP_UTF8);

int SelectPoints[6][6][2]={{{0,0 },{0,4},{0,8},{0,13},{0,17},{0,21}},
                           {{2,0 },{2,4},{2,8},{2,13},{2,17},{2,21}},
                           {{4,0 },{4,4},{4,8},{4,13},{4,17},{4,21}},
                           {{7,0 },{7,4},{7,8},{7,13},{7,17},{7,21}},
                           {{9,0 },{9,4},{9,8},{9,13},{9,17},{9,21}},
                           {{11,0},{11,4},{11,8},{11,13},{11,17},{11,21}}};


wTable[0]  = L"┌───┬───┬───┐┌───┬───┬───┐";
wTable[1]  = L"│   │   │   ││   │   │   │";
wTable[2]  = L"├───┼───┼───┤├───┼───┼───┤";
wTable[3]  = L"│   │   │   ││   │   │   │";
wTable[4]  = L"├───┼───┼───┤├───┼───┼───┤";
wTable[5]  = L"│   │   │   ││   │   │   │";
wTable[6]  = L"└───┴───┴───┘└───┴───┴───┘";
wTable[7]  = L"┌───┬───┬───┐┌───┬───┬───┐";
wTable[8]  = L"│   │   │   ││   │   │   │";
wTable[9]  = L"├───┼───┼───┤├───┼───┼───┤";
wTable[10] = L"│   │   │   ││   │   │   │";
wTable[11] = L"├───┼───┼───┤├───┼───┼───┤";
wTable[12] = L"│   │   │   ││   │   │   │";
wTable[13] = L"└───┴───┴───┘└───┴───┴───┘";

wSelectBig[0]= L"╔═══════════╗";
wSelectBig[1]= L"║           ║";
wSelectBig[2]= L"║           ║";
wSelectBig[3]= L"║           ║";
wSelectBig[4]= L"║           ║";
wSelectBig[5]= L"║           ║";
wSelectBig[6]= L"╚═══════════╝";

wSelectSmall[0]=L"╔═══╗";
wSelectSmall[1]=L"║   ║";
wSelectSmall[2]=L"╚═══╝";





int a,b,x,y;


a=0;
b=0;





char ch;

do {

    system("cls");
    for (int i=0; i<14; i++){
        wTempTable[i] = wTable[i];
    }
    
    x= SelectPoints[a][b][0];
    y= SelectPoints[a][b][1];

    for (int i=0; i<3; i++)
     for (int j=0; j<5; j++){
          wTempTable[x+i][y+j]=wSelectSmall[i][j];
    }


    for (int i=0; i<14; i++){
    wcout << wTempTable[i] << endl;
    }

    ch=getch();

    switch (ch)
    {
    case 'A':
    case 'a':
        b--;
        break;
    case 'D':
    case 'd':
        b++;
        break;
    case 'W':
    case 'w':
        a--;
        break;
    case 'S':
    case 's':
        a++;
        break;
    }


}while(ch != 'q');

 

	
	getchar();
	return 0 ;
}
