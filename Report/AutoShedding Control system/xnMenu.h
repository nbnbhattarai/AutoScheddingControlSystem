/****
Title: Graphical Slide Menu named xnMenu library for a c program...
Programmed by:Nabin Bhattarai
Date:2014-02-02
copyright(c)-Nabin Bhattarai 2014-2015
****/

#ifndef XNMENU_H_INCLUDED
#define XNMENU_H_INCLUDED
#include<stdio.h>
#include"graphics_lib.h"
#define MENU_TEXT_COLOR 244
#define MENU_TEXT_COLOR_NOW_POS 128
#define WINDOW_BG_COLOR 227
#define WINDOW_BG_TEXT 177
#define UP_ARROW 1
/*#define DOWN_ARROW 2
#define LEFT_ARROW 3
#define RIGHT_ARROW 4*/
typedef struct{
            int lx,ly,width;
            int items,now_pos,is_popup,last_pos;
            char *item_char[32];
            }xnMenu;
void print_xnMenu(xnMenu mn)
{
int i;
TextColor(0);
if(mn.ly+mn.items+3<25)
    DrawBox0(mn.lx+1,mn.ly+1,mn.width,2+mn.items,32);
else
    DrawBox0(mn.lx+1,mn.ly-1,mn.width,2+mn.items,32);
TextColor(MENU_TEXT_COLOR);
DrawBox1(mn.lx,mn.ly,mn.width,2+mn.items,32);
mn.last_pos=mn.now_pos;
for(i=1;i<=mn.items;i++){
    if(i==mn.now_pos)
        TextColor(MENU_TEXT_COLOR_NOW_POS);
    else
        TextColor(MENU_TEXT_COLOR);
    DrawBox0(mn.lx+1,mn.ly+i,mn.width-2,1,32);
    if(strcmp(mn.item_char[i],"-")!=0){
    gotoxy(mn.lx+2,mn.ly+1+(i-1));  printf("%s",mn.item_char[i]);
    }else{
    gotoxy(mn.lx,mn.ly+i); TextColor(MENU_TEXT_COLOR);    printf("%c",(char)195);
    DrawHorizontalLine1(mn.lx+1,mn.ly+i,mn.width-1);
    gotoxy(mn.lx+mn.width-1,mn.ly+i); TextColor(MENU_TEXT_COLOR);    printf("%c",(char)180);
    }
}
}
void refresh_draw_xnMenu(xnMenu mn,int up_or_down)
{
    if(up_or_down==UP_ARROW){
        TextColor(MENU_TEXT_COLOR_NOW_POS);
        DrawBox0(mn.lx+1,mn.ly+mn.now_pos,mn.width-2,1,32);
        gotoxy(mn.lx+2,mn.ly+1+(mn.now_pos-1));  printf("%s",mn.item_char[mn.now_pos]);
        TextColor(MENU_TEXT_COLOR);
        DrawBox0(mn.lx+1,mn.ly+mn.last_pos,mn.width-2,1,32);
        gotoxy(mn.lx+2,mn.ly+1+(mn.last_pos-1));  printf("%s",mn.item_char[mn.last_pos]);

        }else{
        TextColor(MENU_TEXT_COLOR_NOW_POS);
        DrawBox0(mn.lx+1,mn.ly+mn.now_pos,mn.width-2,1,32);
        gotoxy(mn.lx+2,mn.ly+1+(mn.now_pos-1));  printf("%s",mn.item_char[mn.now_pos]);
        TextColor(MENU_TEXT_COLOR);
        DrawBox0(mn.lx+1,mn.ly+mn.last_pos,mn.width-2,1,32);
        gotoxy(mn.lx+2,mn.ly+1+(mn.last_pos-1));  printf("%s",mn.item_char[mn.last_pos]);
        }
}
int handle_xnMenu(xnMenu mnu)
{
int an;
char get;
get=getch();
    if(get==72){        ///up arrow
        if(mnu.now_pos>1 && mnu.now_pos!=1){
            mnu.last_pos=mnu.now_pos--;
            if(strcmp(mnu.item_char[mnu.now_pos],"-")==0){
                mnu.now_pos--;
            }
            if(strcmp(mnu.item_char[mnu.now_pos],"-")!=0){
                refresh_draw_xnMenu(mnu,UP_ARROW);
                mnu.last_pos++;
            }
        }
        handle_xnMenu(mnu);
    }
    else if(get==80){   ///down arrow
        if(mnu.now_pos<mnu.items && mnu.now_pos!=mnu.items){
            mnu.last_pos=mnu.now_pos++;
            if(strcmp(mnu.item_char[mnu.now_pos],"-")==0){
                mnu.now_pos++;
            }
            if(strcmp(mnu.item_char[mnu.now_pos],"-")!=0){
                refresh_draw_xnMenu(mnu,UP_ARROW);
                mnu.last_pos++;
            }
        }
        handle_xnMenu(mnu);
    }
    else if(get==27 || get==75){
            TextColor(WINDOW_BG_COLOR);
        ClearBox(mnu.lx,mnu.ly,mnu.width+1,mnu.items+3,WINDOW_BG_TEXT);
    }else if(get==13)
        return mnu.now_pos;
    else
        handle_xnMenu(mnu);
}

#endif // XNMENU_H_INCLUDED
