#ifndef _TXT_H
	#define _TXT_H
	#include<stdio.h>
	#include<conio.h>
	#include"graphics_lib.h"

    #define CHAR_CODE 220
void Aprintf(int x,int y,int color,int SLEEP_TIME)
{
	int i,j;
	TextColor(color);
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
                Sleep(SLEEP_TIME);
			gotoxy(x+j,y+i);
			if((i==0)&&(j==3 || j==4 || j==5)) printf("%c",(char)CHAR_CODE);
			else if((i==1)&&(j==2 || j==3 || j==5 || j==6)) printf("%c",(char)CHAR_CODE);
			else if(i==2 &&(j==2 ||j==6)) printf("%c",(char)CHAR_CODE);
			else if(i>1 &&(j==0 || j==1 || j==7 || j==8)) printf("%c",(char)CHAR_CODE);
			else if((j==0 || j==8) && i>3) printf("%c",(char)CHAR_CODE);
			else if(i==6) printf("%c",(char)CHAR_CODE);
			else	printf("");
			}
		}
	gotoxy(x+9+2,y);
}
void Bprintf(int x,int y,int color,int SLEEP_TIME)
{
	int i,j;
	TextColor(color);
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
                Sleep(SLEEP_TIME);
			gotoxy(x+j,y+i);
			if((i==1 || i==2||i==3) && j>1 && j<7) printf("");
			else if((i==5 || i==6 || i==7) && j>1 && j<7) printf("");
			else if((i==0 || i==4 || i==8) && j==8) printf("");
			else printf("%c",(char)CHAR_CODE);
			}
		}
	gotoxy(x+9+2,y);
}
void Cprintf(int x,int y,int color,int SLEEP_TIME)
{
	int i,j;
	TextColor(color);
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
                Sleep(SLEEP_TIME);
			gotoxy(x+j,y+i);
			if((i==0 || i==8) && j>0) printf("%c",(char)CHAR_CODE);
			else if((j==0 || j==1) && i>0 && i<8) printf("%c",(char)CHAR_CODE);
			else	printf("");
			}
		}
}
void Dprintf(int x,int y,int color,int SLEEP_TIME)
{
	int i,j;
	TextColor(color);
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
                Sleep(SLEEP_TIME);
			gotoxy(x+j,y+i);
			if((i==0||i==8) && j<8) printf("%c",(char)CHAR_CODE);
			else if((j==3 ||j==4 || j==7 ||j==8)&&i>0 &&i<8) printf("%c",(char)CHAR_CODE);
			else	printf("");
			}
		}
}
void Eprintf(int x,int y,int color,int SLEEP_TIME)
{
	int i,j;
	TextColor(color);
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
                Sleep(SLEEP_TIME);
			gotoxy(x+j,y+i);
			if((i==0 ||i==4 ||i==8)&&j>0) printf("%c",(char)CHAR_CODE);
			else if((j==0 ||j==1)&&i>0&&i<8) printf("%c",(char)CHAR_CODE);
			else	printf("");
			}
		}
}
void Fprintf(int x,int y,int color,int SLEEP_TIME)
{
	int i,j;
	TextColor(color);
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
                Sleep(SLEEP_TIME);
			gotoxy(x+j,y+i);
			if((i==0||i==3)&&j>0) printf("%c",(char)CHAR_CODE);
			else if((j==0||j==1)&&i>0) printf("%c",(char)CHAR_CODE);
			else	printf("");
			}
		}
}
void Gprintf(int x,int y,int color,int SLEEP_TIME)
{
	int i,j;
	TextColor(color);
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
                Sleep(SLEEP_TIME);
			gotoxy(x+j,y+i);
			if(i==0 && j>1 && j<8) printf("%c",(char)CHAR_CODE);
			else if(i==1 &&(j==2 || j==3 || j==7 || j==8)) printf("%c",(char)CHAR_CODE);
			else if((j==0||j==1)&&i>1&&i<7) printf("%c",(char)CHAR_CODE);
			else if(i==4 && j>4) printf("%c",(char)CHAR_CODE);
			else if((i==5||i==6||i==7)&&(j==7||j==8)) printf("%c",(char)CHAR_CODE);
			else if(i==7 && (j==1||j==2)) printf("%c",(char)CHAR_CODE);
			else if(i==8&&j>1&&j<7) printf("%c",(char)CHAR_CODE);
			else	printf("");
			}
		}
}
void Hprintf(int x,int y,int color,int SLEEP_TIME)
{
	int i,j;
	TextColor(color);
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
                Sleep(SLEEP_TIME);
			gotoxy(x+j,y+i);
			if(j==0||j==1||j==7||j==8) printf("%c",(char)CHAR_CODE);
			else if(i==4) printf("%c",(char)CHAR_CODE);
			else	printf("");
			}
		}
}
void Iprintf(int x,int y,int color,int SLEEP_TIME)
{
	int i,j;
	TextColor(color);
	for(i=0;i<9;i++){
		for(j=0;j<8;j++){
                Sleep(SLEEP_TIME);
			gotoxy(x+j,y+i);
			if(j==3 || j==4) printf("%c",(char)CHAR_CODE);
			else printf("");
			}
		}
	gotoxy(x+9+2,y);
}
void Jprintf(int x,int y,int color,int SLEEP_TIME)
{
	int i,j;
	TextColor(color);
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
                Sleep(SLEEP_TIME);
			gotoxy(x+j,y+i);
			if((j==7||j==8)&&i<8) printf("%c",(char)CHAR_CODE);
			else if((j==0||j==1)&&i>3&&i<8) printf("%c",(char)CHAR_CODE);
			else if(i==8 && j>0 &&j<8) printf("%c",(char)CHAR_CODE);
			else	printf("");
			}
		}
}
void Kprintf(int x,int y,int color,int SLEEP_TIME)
{
	int i,j;
	TextColor(color);
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
                Sleep(SLEEP_TIME);
			gotoxy(x+j,y+i);
			if(j==0||j==1) printf("%c",(char)CHAR_CODE);
			else if((i==0||i==8)&&j>6) printf("%c",(char)CHAR_CODE);
			else if((i==1||i==7)&&(j==6||j==7)) printf("%c",(char)CHAR_CODE);
			else if((i==2||i==6)&&(j==5||j==6)) printf("%c",(char)CHAR_CODE);
			else if(i==3&&(j==3||j==4||j==5)) printf("%c",(char)CHAR_CODE);
			else if(i==4&&(j==2||j==3||j==4)) printf("%c",(char)CHAR_CODE);
			else if(i==5&&(j==4||j==5)) printf("%c",(char)CHAR_CODE);
			else	printf("");
			}
		}
}
void Lprintf(int x,int y,int color,int SLEEP_TIME)
{
	int i,j;
	TextColor(color);
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
                Sleep(SLEEP_TIME);
			gotoxy(x+j,y+i);
			if(j==0||j==1) printf("%c",(char)CHAR_CODE);
			else if(i==8) printf("%c",(char)CHAR_CODE);
			else	printf("");
			}
		}
}
void Mprintf(int x,int y,int color,int SLEEP_TIME)
{
	int i,j;
	TextColor(color);
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
                Sleep(SLEEP_TIME);
			gotoxy(x+j,y+i);
			if(j==0||j==1||j==7||j==8) printf("%c",(char)CHAR_CODE);
			else if((j==2||j==6)&&(i==1||i==2)) printf("%c",(char)CHAR_CODE);
			else if((j==3||j==5)&&(i==2||i==3)) printf("%c",(char)CHAR_CODE);
			else if(j==4&&(i==3||i==4)) printf("%c",(char)CHAR_CODE);
			else	printf("");
			}
		}
}
void Nprintf(int x,int y,int color,int SLEEP_TIME)
{
	int i,j;
	TextColor(color);
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
                Sleep(SLEEP_TIME);
			gotoxy(x+j,y+i);
			if(j<2 || j>6) printf("%c",(char)CHAR_CODE);
			else if(i==(j-1)) printf("%c",(char)CHAR_CODE);
			else if(j==(i-1)) printf("%c",(char)CHAR_CODE);
			else if(i==j) printf("%c",(char)CHAR_CODE);
			else	printf("");
			}
		}
}
void Oprintf(int x,int y,int color,int SLEEP_TIME)
{
	int i,j;
	TextColor(color);
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
                Sleep(SLEEP_TIME);
			gotoxy(x+j,y+i);
			if((i==0||i==8)&&(j>1 &&j<7)) printf("%c",(char)CHAR_CODE);
			else if((i==1||i==7)&&(j==1||j==2||j==6||j==7)) printf("%c",(char)CHAR_CODE);
			else if((j==0||j==1||j==7||j==8)&&i>1&&i<7) printf("%c",(char)CHAR_CODE);
			else	printf("");
			}
		}
}
void Pprintf(int x,int y,int color,int SLEEP_TIME)
{
	int i,j;
	TextColor(color);
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
                Sleep(SLEEP_TIME);
			gotoxy(x+j,y+i);
			if(j==0||j==1) printf("%c",(char)CHAR_CODE);
			else if((i==0||i==4)&&j<8) printf("%c",(char)CHAR_CODE);
			else if((i==1||i==2||i==3)&&(j==7||j==8)) printf("%c",(char)CHAR_CODE);
			else	printf("");
			}
		}
}
void Qprintf(int x,int y,int color,int SLEEP_TIME)
{
	int i,j;
	TextColor(color);
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
                Sleep(SLEEP_TIME);
			gotoxy(x+j,y+i);
			if((i==0||i==7)&&j>1&&j<7) printf("%c",(char)CHAR_CODE);
			else if(i==1&&(j==1||j==2||j==6||j==7)) printf("%c",(char)CHAR_CODE);
			else if((i>1&&i<6)&&(j==0||j==1||j==7||j==8)) printf("%c",(char)CHAR_CODE);
			else if(i==6&&(j==1||j==5||j==7||j==8)) printf("%c",(char)CHAR_CODE);
			else if(i==7&&j==7) printf("%c",(char)CHAR_CODE);
			else if(i==8 &&j>5) printf("%c",(char)CHAR_CODE);
			else	printf("");
			}
		}
}
void Rprintf(int x,int y,int color,int SLEEP_TIME)
{
	int i,j;
	TextColor(color);
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
                Sleep(SLEEP_TIME);
			gotoxy(x+j,y+i);
			if(j==0||j==1) printf("%c",(char)CHAR_CODE);
			else if(i==0 &&j<8) printf("%c",(char)CHAR_CODE);
			else if((i==1||i==2)&&(j==7||j==8)) printf("%c",(char)CHAR_CODE);
			else if(i==3 &&j>4 && j<8) printf("%c",(char)CHAR_CODE);
			else if(i==4&&j>1&&j<7) printf("%c",(char)CHAR_CODE);
			else if(i==5 && j==5) printf("%c",(char)CHAR_CODE);
			else if(i==6&&(j==6||j==7)) printf("%c",(char)CHAR_CODE);
			else if((i==7||i==8)&&(j==7||j==8)) printf("%c",(char)CHAR_CODE);
			else	printf("");
			}
		}
}
void Sprintf(int x,int y,int color,int SLEEP_TIME)
{
	int i,j;
	TextColor(color);
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
                Sleep(SLEEP_TIME);
			gotoxy(x+j,y+i);
			if((i==0||i==8)&&j>0&&j<8) printf("%c",(char)CHAR_CODE);
			else if((j==0||j==1)&&i>0&&i<4) printf("%c",(char)CHAR_CODE);
			else if(i==1&&(j==7||j==8)) printf("%c",(char)CHAR_CODE);
			else if(i==4&&j>1&&j<8) printf("%c",(char)CHAR_CODE);
			else if((j==7||j==8)&&i>4&&i<8) printf("%c",(char)CHAR_CODE);
			else if(i==7&&(j==0||j==1)) printf("%c",(char)CHAR_CODE);
			else	printf("");
			}
		}
}
void Tprintf(int x,int y,int color,int SLEEP_TIME)
{
	int i,j;
	TextColor(color);
	for(i=0;i<9;i++){
		for(j=0;j<10;j++){
                Sleep(SLEEP_TIME);
			gotoxy(x+j,y+i);
			if(i==0) printf("%c",(char)CHAR_CODE);
			else if(j==4||j==5) printf("%c",(char)CHAR_CODE);
			else	printf("");
			}
		}
}
void Uprintf(int x,int y,int color,int SLEEP_TIME)
{
	int i,j;
	TextColor(color);
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
                Sleep(SLEEP_TIME);
			gotoxy(x+j,y+i);
			if((j==0||j==1||j==7||j==8)&&i<8) printf("%c",(char)CHAR_CODE);
			else if(i==8&&j>0&&j<8) printf("%c",(char)CHAR_CODE);
			else	printf("");
			}
		}
}
void Vprintf(int x,int y,int color,int SLEEP_TIME)
{
	int i,j;
	TextColor(color);
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
                Sleep(SLEEP_TIME);
			gotoxy(x+j,y+i);
			if((j==0||j==1||j==7||j==8)&&i<6) printf("%c",(char)CHAR_CODE);
			else if(i==6&&(j==1||j==2||j==6||j==7)) printf("%c",(char)CHAR_CODE);
			else if(i==7&&j>1&&j<7) printf("%c",(char)CHAR_CODE);
			else if(i==8&&j>2&&j<6) printf("%c",(char)CHAR_CODE);
			else if((i==6&&j==2)||(i==6&&j==6)) printf("%c",(char)CHAR_CODE);
			else	printf("");
			}
		}
}
void Wprintf(int x,int y,int color,int SLEEP_TIME)
{
	int i,j;
	TextColor(color);
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
                Sleep(SLEEP_TIME);
			gotoxy(x+j,y+i);
			if((j==0||j==8)&&i<8) printf("%c",(char)CHAR_CODE);
			else if(j==1||j==7) printf("%c",(char)CHAR_CODE);
			else if((i==7||i==8)&&(j==2||j==6)) printf("%c",(char)CHAR_CODE);
			else if((i==6||i==7)&&(j==3||j==5)) printf("%c",(char)CHAR_CODE);
			else if(j==4&&i>3&&i<7) printf("%c",(char)CHAR_CODE);
			else	printf("");
			}
		}
}
void Xprintf(int x,int y,int color,int SLEEP_TIME)
{
	int i,j;
	TextColor(color);
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
                Sleep(SLEEP_TIME);
			gotoxy(x+j,y+i);
			if((i==0||i==8)&&(j==0||j==1||j==7||j==8)) printf("%c",(char)CHAR_CODE);
			else if((i==1||i==7)&&(j==1||j==2||j==6||j==7)) printf("%c",(char)CHAR_CODE);
			else if((i==2||i==6)&&(j==2||j==3||j==5||j==6)) printf("%c",(char)CHAR_CODE);
			else if((j==3||j==5)&&i>2&&i<6) printf("%c",(char)CHAR_CODE);
			else if(j==4&&i==4) printf("%c",(char)CHAR_CODE);
			else	printf("");
			}
		}
}
void Yprintf(int x,int y,int color,int SLEEP_TIME)
{
	int i,j;
	TextColor(color);
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
                Sleep(SLEEP_TIME);
			gotoxy(x+j,y+i);
			if((j==0||j==1||j==7||j==8)&&i<5) printf("%c",(char)CHAR_CODE);
			else if(i==5&&j>0&&j<8) printf("%c",(char)CHAR_CODE);
			else if(i==6&&j>1&&j<7) printf("%c",(char)CHAR_CODE);
			else if(i==7&&(j==3||j==4||j==5)) printf("%c",(char)CHAR_CODE);
			else if(i==8&&(j==3||j==4||j==5)) printf("%c",(char)CHAR_CODE);
			else	printf("");
			}
		}
}
void Zprintf(int x,int y,int color,int SLEEP_TIME)
{
	int i,j;
	TextColor(color);
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
                Sleep(SLEEP_TIME);
			gotoxy(x+j,y+i);
			if(i==0||i==8) printf("%c",(char)CHAR_CODE);
			else if(i==1&&(j==6||j==7)) printf("%c",(char)CHAR_CODE);
			else if(i==2&&(j==5||j==6)) printf("%c",(char)CHAR_CODE);
			else if(i==3&&(j==4||j==5)) printf("%c",(char)CHAR_CODE);
			else if(i==4&&(j==3||j==4)) printf("%c",(char)CHAR_CODE);
			else if(i==5&&(j==2||j==3)) printf("%c",(char)CHAR_CODE);
			else if(i==6&&(j==1||j==2)) printf("%c",(char)CHAR_CODE);
			else if(i==7&&(j==0||j==1)) printf("%c",(char)CHAR_CODE);
			else	printf("");
			}
		}
}

void TXTprintf(char *text,int x,int y,int color,int SLEEP_TIME)
{
	int x1,y1;
	char ch;
	x1=x;
	y1=y;
	while((*text)!='\0'){
		ch=*text;
		gotoxy(x,y);
		switch(ch){
		case 'a':
				Aprintf(x,y,color,SLEEP_TIME);
				break;
		case 'A':
				Aprintf(x,y,color,SLEEP_TIME);
				break;
		case 'b':
				Bprintf(x,y,color,SLEEP_TIME);
				break;
		case 'B':
				Bprintf(x,y,color,SLEEP_TIME);
				break;
		case 'c':
				Cprintf(x,y,color,SLEEP_TIME);
				break;
		case 'C':
				Cprintf(x,y,color,SLEEP_TIME);
				break;
		case 'd':
				Dprintf(x,y,color,SLEEP_TIME);
				break;
		case 'D':
				Dprintf(x,y,color,SLEEP_TIME);
				break;
		case 'e':
				Eprintf(x,y,color,SLEEP_TIME);
				break;
		case 'E':
				Eprintf(x,y,color,SLEEP_TIME);
				break;
		case 'f':
				Fprintf(x,y,color,SLEEP_TIME);
				break;
		case 'F':
				Fprintf(x,y,color,SLEEP_TIME);
				break;
		case 'g':
				Gprintf(x,y,color,SLEEP_TIME);
				break;
		case 'G':
				Gprintf(x,y,color,SLEEP_TIME);
				break;
		case 'h':
				Hprintf(x,y,color,SLEEP_TIME);
				break;
		case 'H':
				Hprintf(x,y,color,SLEEP_TIME);
				break;
		case 'i':
				Iprintf(x,y,color,SLEEP_TIME);
				break;
		case 'I':
				Iprintf(x,y,color,SLEEP_TIME);
				break;
		case 'j':
				Jprintf(x,y,color,SLEEP_TIME);
				break;
		case 'J':
				Jprintf(x,y,color,SLEEP_TIME);
				break;

		case 'k':
				Kprintf(x,y,color,SLEEP_TIME);
				break;
		case 'K':
				Kprintf(x,y,color,SLEEP_TIME);
				break;
		case 'l':
				Lprintf(x,y,color,SLEEP_TIME);
				break;
		case 'L':
				Lprintf(x,y,color,SLEEP_TIME);
				break;
		case 'm':
				Mprintf(x,y,color,SLEEP_TIME);
				break;
		case 'M':
				Mprintf(x,y,color,SLEEP_TIME);
				break;
		case 'n':
				Nprintf(x,y,color,SLEEP_TIME);
				break;
		case 'N':
				Nprintf(x,y,color,SLEEP_TIME);
				break;
		case 'o':
				Oprintf(x,y,color,SLEEP_TIME);
				break;
		case 'O':
				Oprintf(x,y,color,SLEEP_TIME);
				break;
		case 'p':
				Pprintf(x,y,color,SLEEP_TIME);
				break;
		case 'P':
				Pprintf(x,y,color,SLEEP_TIME);
				break;
		case 'q':
				Qprintf(x,y,color,SLEEP_TIME);
				break;
		case 'Q':
				Qprintf(x,y,color,SLEEP_TIME);
				break;
		case 'r':
				Rprintf(x,y,color,SLEEP_TIME);
				break;
		case 'R':
				Rprintf(x,y,color,SLEEP_TIME);
				break;
		case 's':
				Sprintf(x,y,color,SLEEP_TIME);
				break;
		case 'S':
				Sprintf(x,y,color,SLEEP_TIME);
				break;
		case 't':
				Tprintf(x,y,color,SLEEP_TIME);
				break;
		case 'T':
				Tprintf(x,y,color,SLEEP_TIME);
				break;
		case 'u':
				Uprintf(x,y,color,SLEEP_TIME);
				break;
		case 'U':
				Uprintf(x,y,color,SLEEP_TIME);
				break;
		case 'v':
				Vprintf(x,y,color,SLEEP_TIME);
				break;
		case 'V':
				Vprintf(x,y,color,SLEEP_TIME);
				break;
		case 'w':
				Wprintf(x,y,color,SLEEP_TIME);
				break;
		case 'W':
				Wprintf(x,y,color,SLEEP_TIME);
				break;
		case 'x':
				Xprintf(x,y,color,SLEEP_TIME);
				break;
		case 'X':
				Xprintf(x,y,color,SLEEP_TIME);
				break;
		case 'y':
				Yprintf(x,y,color,SLEEP_TIME);
				break;
		case 'Y':
				Yprintf(x,y,color,SLEEP_TIME);
				break;
		case 'z':
				Zprintf(x,y,color,SLEEP_TIME);
				break;
		case 'Z':
				Zprintf(x,y,color,SLEEP_TIME);
				break;
		case '\n':
				x=x1;
				y=y1+11;
				break;
		default:
			break;
			}
		x+=11;
		++text;
	}
}
#endif
