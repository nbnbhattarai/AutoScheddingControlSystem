#ifndef GRAPHICS_LIB_H
    #define GRAPHICS_LIB_H
    #include<windows.h>
    #include<stdio.h>
    #define LENGTH_LIST 10
    #define MAX_ROWS_IN_LIST 18
    #define GO_TOP gotoxy(0,0);


/***Structure to the list.***/
typedef struct{
                int lx,ly,sn,types;     //sn-no of rows in a list and types-no of items about to keep record.
                char *caption,*titles;  //Caption- Text to be written above the list table and titles- Text to write in box about it's items..
                }List;


/***gotoxy(x,y) function alternative to gotoxy() function of conio.h header file***/
void gotoxy (int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/***Function to draw box having double border***/
void DrawBox2(int lx,int ly,int width,int height,int bg_text)
{
int i, j;
for(j=0;j<height;j++)
        for(i=0;i<width;i++){
            gotoxy(lx+i,ly+j);
            if(i==0 && j==0)    printf("%c",(char)201);
            else if(i>0 && i<(width-1) && (j==0 || j==(height-1)))    printf("%c",(char)205);
            else if(i==(width-1) && j==0)    printf("%c",(char)187);
            else if((i==0 || i==(width-1)) && j>0 && j<(height-1))    printf("%c",(char)186);
            else if(i==0 && j==(height-1))    printf("%c",(char)200);
            else if(i==(width-1) && j==(height-1))    printf("%c",(char)188);
            else printf("%c",(char)bg_text);
        }
}

/***Function to draw a box having single boder..***/
void DrawBox1(int lx,int ly,int width,int height,int bg_text)
{
int i, j;
for(j=0;j<height;j++)
        for(i=0;i<width;i++){
            gotoxy(lx+i,ly+j);
            if(i==0 && j==0)    printf("%c",(char)218);
            else if(i>0 && i<(width-1) && (j==0 || j==(height-1)))    printf("%c",(char)196);
            else if(i==(width-1) && j==0)    printf("%c",(char)191);
            else if((i==0 || i==(width-1)) && j>0 && j<(height-1))    printf("%c",(char)179);
            else if(i==0 && j==(height-1))    printf("%c",(char)192);
            else if(i==(width-1) && j==(height-1))    printf("%c",(char)217);
            else printf("%c",(char)bg_text);
        }
}

/***Function to draw a box having no boder..***/
void DrawBox0(int lx,int ly,int width,int height,int bg_text)
{
int i, j;
for(j=0;j<height;j++)
        for(i=0;i<width;i++){
            gotoxy(lx+i,ly+j);
            printf("%c",(char)bg_text);
        }
}
/***Function to clear the drawn box***/
void ClearBox(int lx,int ly,int width,int height,int bg_text)
{
    int i,j;
    for(j=0;j<height;j++){
        for(i=0;i<width;i++){
            gotoxy(lx+i,ly+j);
            printf("%c",(char)bg_text);
        }
    }
}
void ClearBoxOnly(int lx,int ly,int width,int height,int bg_text)
{
    int i,j;
    for(j=0;j<height;j++){
        for(i=0;i<width;i++){
            gotoxy(lx+i,ly+j);
            if(i==0 || i== (width-1) || j==0 || j==(height-1))            printf("%c",(char)bg_text);
        }
    }
}

/***function to draw a line(horizontal) single border...***/
void DrawHorizontalLine1(int lx,int ly,int len)
{
    int i;
    for(i=0;i<len;i++){
        gotoxy(lx+i,ly);
        printf("%c",(char)196);
    }
}

/***function to draw a line(horizontal) double border...***/
void DrawHorizontalLine2(int lx,int ly,int len)
{
    int i;
    for(i=0;i<len;i++){
        gotoxy(lx+i,ly);
        printf("%c",(char)205);
    }
}

/***function to draw a line(Vertical) single border...***/
void DrawVerticalLine1(int lx,int ly,int len)
{
    int i;
    for(i=0;i<len;i++){
        gotoxy(lx,ly+i);
        printf("%c",(char)179);
    }
}

/***function to draw a line(vertical) double border...***/
void DrawVerticalLine2(int lx,int ly,int len)
{
    int i;
    for(i=0;i<len;i++){
        gotoxy(lx,ly+i);
        printf("%c",(char)186);
    }
}

/***Function to print text with color***/
void cprintf(char *text,unsigned int color)
{
    HANDLE hConsole;
    hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,color);
    printf("%s",text);
    SetConsoleTextAttribute(hConsole,7);
}

/***Function to set a text color to this terminal***/
void TextColor(unsigned int color)
{
    HANDLE hConsole;
    hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,color);
}

/***Function to print list to screen***/
void PrintList(List lst){
    int tsn,sns,i,most,j;
    char ch_verify;
    gotoxy(30,0);   TextColor(2);   printf("%s:",lst.caption);    TextColor(7);
do{
        sns=lst.sn;
        most=0;
    do{
            if(sns>MAX_ROWS_IN_LIST)
                tsn=MAX_ROWS_IN_LIST;
            else
                tsn=sns;
        DrawBox1(lst.lx,lst.ly,lst.types*LENGTH_LIST,4+tsn,32);
        gotoxy(lst.lx,lst.ly+2);  printf("%c",(char)195);
        gotoxy(lst.lx+lst.types*LENGTH_LIST-1,lst.ly+2);  printf("%c",(char)180);
        DrawHorizontalLine1(lst.lx+1,lst.ly+2,lst.types*LENGTH_LIST-2);
        gotoxy(lst.lx+1,lst.ly+1);  TextColor(2);   printf("%s",lst.titles);    TextColor(7);
        for(i=most,j=0;i<(tsn+most);i++,j++){
            gotoxy(lst.lx+1,lst.ly+3+j);
            printf("%d",i+1);
        }
        most+=tsn;
        sns-=tsn;
        gotoxy(lst.lx,lst.ly+4+tsn);  cprintf("Press Enter to continue...",3);    getch();  ClearBox(lst.lx,lst.ly,lst.types*LENGTH_LIST,4+tsn,32);  printf("\r"); printf("                            ");
    }while(sns>0);
        gotoxy(0,1);    cprintf("Show list again?(y/n):\xDB\b",7);  ch_verify=getch();
}while(ch_verify=='y' || ch_verify=='Y');
}

/***Function to hide cursor of console***/
void ShowConsoleCursor(BOOL show)
{
    HANDLE out=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorinfo;
    GetConsoleCursorInfo(out,&cursorinfo);
    cursorinfo.bVisible=show;
    SetConsoleCursorInfo(out,&cursorinfo);
}
///Animation of loading data
void LoadingAnimation(int lx,int ly,int width,int sleep_time,char *loading_title,int text_color)
{
int i,j,sleep=0,txt_clr=((text_color)/16)*16+(text_color)/16;
ShowConsoleCursor(FALSE);
gotoxy(lx,ly);    cprintf(loading_title,text_color);
    for(j=1;j<=2;j++){
        for(i=1;i<=width;i++){
                    gotoxy(lx,ly+1);    TextColor(text_color);   printf("%.2d %c",(i*100)/(width),(char)37);
                    gotoxy(lx+i-1,ly+2);    TextColor(txt_clr);  printf("%c",(char)219);
                    gotoxy(lx+i-1,ly+3);    TextColor(txt_clr);  printf("%c",(char)223);   TextColor(7);
                    Sleep(sleep);
        }
    sleep=sleep_time;
    txt_clr++;
    }
}
///Function to print main_window
void print_main_window(int bg_text)
{
    int i, j,width=80,height=25,lx=0,ly=0;
for(j=0;j<height;j++)
        for(i=0;i<width;i++){
            gotoxy(lx+i,ly+j);
            if(i==0 && j==0)    printf("%c",(char)201);
            else if(i>0 && i<(width-1) && (j==0 || j==(height-1)))    printf("%c",(char)205);
            else if(i>0 && i<(width-1) && (j==2 || j==(height-3)))    printf("%c",(char)196);
            else if(i==0 && (j==2 || j==(height-3)))    printf("%c",(char)199);
            else if(i==(width-1) && (j==2 || j==(height-3)))    printf("%c",(char)182);
            else if(i==(width-1) && j==0)    printf("%c",(char)187);
            else if((i==0 || i==(width-1)) && j>0 && j<(height-1))    printf("%c",(char)186);
            else if(i==0 && j==(height-1))    printf("%c",(char)200);
            else if(i==(width-1) && j==(height-1))    printf("%c",(char)188);
            else printf("%c",(char)bg_text);
        }
}
#include"xnMenu.h"
#endif // GRAPHICS_LIB_H_INCLUDED
