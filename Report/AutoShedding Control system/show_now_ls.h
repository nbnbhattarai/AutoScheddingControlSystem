#ifndef SHOW_NOW_LS_H
#define SHOW_NOW_LS_H
#include<stdio.h>
#include"graphics_lib.h"
#include"ls.h"
#include"DateConverter.h"
#define TAB_BG_TEXT 32
#define NO 0
#define YES !NO
#define ON 1
#define OFF !ON
ls_group group[8];
    typedef struct{
                int lx,ly,width,height,items,now_pos;
                char *item_char[32];
    }Tab;
void refresh_group_state(ls_group *grp)
{
Time now,ls_morning[2],ls_night[2];
Date now_date=get_now_bs_date();
    now=get_now_time();
    ls_morning[0]=grp->day[now_date.day+1].morning[0];
    ls_morning[1]=grp->day[now_date.day+1].morning[1];
    ls_night[0]=grp->day[now_date.day+1].night[0];
    ls_night[1]=grp->day[now_date.day+1].night[1];
if((is_greater_time(ls_morning[1],now) && is_greater_time(now,ls_morning[0])) || (is_greater_time(ls_night[1],now) && is_greater_time(now,ls_night[1])))
    grp->state=ON;
else
    grp->state=OFF;
}
void draw_ls_schedule_tab_content(ls_group grp)
{
Time time_went;
int i,j,min_v=1,max_v=4,a;
    grp.is_off=NO;
    refresh_group_state(&grp);
    for(j=0;j<=1;j++){
    for(i=min_v;i<=max_v;i++){
        ///DrawBox0(4+j*38,i*4-j*4*4+(i-min_v),35,4);
        TextColor(126);
        gotoxy(5+j*37,i*4-j*4*4+(i-min_v)-1);
        switch(i){
            case 1:
                printf("Aaitabar.");
                break;
            case 2:
                printf("Sombar.");
                break;
            case 3:
                printf("Mangalbar.");
                break;
            case 4:
                printf("Budhabar.");
                break;
            case 5:
                printf("Bihibar.");
                break;
            case 6:
                printf("Sukrabar.");
                break;
            case 7:
                printf("Sanibar.");
                break;
            }
            if(which_day_BS(get_now_bs_date())==(i-1)){
                gotoxy(42,18);  printf("Status %c",28);
                if(grp.state==ON && grp.is_off==NO)
                    TextColor(112);
                else
                    TextColor(124);
                gotoxy(48,18);
                printf("%c",220);
                gotoxy(48,19);
                printf("%c",223);
                    gotoxy(49,18);
                printf("%c",220);
                gotoxy(49,19);
                printf("%c",223);
                TextColor(116);
            }else
                TextColor(113);
        gotoxy(5+j*37,i*4-j*4*4+(i-min_v));    printf("Morning:\t%.2d:%.2d:%.2d - %.2d:%.2d:%.2d",grp.day[i].morning[0].hour,grp.day[i].morning[0].minute,grp.day[i].morning[0].second,grp.day[i].morning[1].hour,grp.day[i].morning[1].minute,grp.day[i].morning[1].second);
        gotoxy(5+j*37,1+i*4-j*4*4+(i-min_v));    printf("Night:\t%.2d:%.2d:%.2d - %.2d:%.2d:%.2d",grp.day[i].night[0].hour,grp.day[i].night[0].minute,grp.day[i].night[0].second,grp.day[i].night[1].hour,grp.day[i].night[1].minute,grp.day[i].night[1].second);
        gotoxy(5+j*37,2+i*4-j*4*4+(i-min_v));
        TextColor(127);

    }
    min_v=max_v+1;
    max_v=7;
}
}
void draw_tab(Tab tb)
{
    int i,j,min_v=1,max_v=4;
    TextColor(241);
    DrawBox1(tb.lx,tb.ly+1,tb.width,tb.height-1,TAB_BG_TEXT);
    gotoxy(tb.lx,tb.ly);    cprintf(" ",144);
    for(i=1;i<=tb.items;i++){
        if(i==tb.now_pos)
                TextColor(240);
        else
            TextColor(144);
        gotoxy(tb.lx+1+(i-1)*11,tb.ly);   printf(" %s  ",tb.item_char[i]);
    TextColor(144);
    }
    gotoxy(tb.lx+tb.width,tb.ly+tb.height);   cprintf("  ",144);
    for(j=0;j<=1;j++){
        for(i=min_v;i<=max_v;i++){
        TextColor(126);
        DrawBox0(4+j*37,i*4-j*4*4+(i-min_v)-1,35,4,TAB_BG_TEXT);
        }
    min_v=max_v+1;
    max_v=8;
    }
    draw_ls_schedule_tab_content(group[tb.now_pos]);
}
void refresh_draw_tab(Tab tb,int last_now_pos)
{
        TextColor(144);
        gotoxy(tb.lx+1+(last_now_pos-1)*11,tb.ly);   printf(" %s  ",tb.item_char[last_now_pos]);
        TextColor(240);
        gotoxy(tb.lx+1+(tb.now_pos-1)*11,tb.ly);   printf(" %s  ",tb.item_char[tb.now_pos]);
}

void handle_tab_control(Tab tb)
{
char ch;
int in,day,a;
Time t_gone,t_remaining,now,morning[2],night[2];
    while(!kbhit()){
    day=which_day_BS(get_now_bs_date())+1;
    now=get_now_time();
    morning[0]=group[tb.now_pos].day[day].morning[0];
    morning[1]=group[tb.now_pos].day[day].morning[1];
    night[0]=group[tb.now_pos].day[day].night[0];
    night[1]=group[tb.now_pos].day[day].night[1];
    if(group[tb.now_pos].state==YES){
        if(is_greater_time(morning[1],now) && is_greater_time(now,morning[0])){
            t_remaining=subtract_time(morning[1],now);
            t_gone=subtract_time(now,morning[0]);
        }else if(is_greater_time(now,night[1])){
            morning[0]=group[tb.now_pos].day[day+1].morning[0];
            morning[0].hour+=24;
            t_remaining=subtract_time(morning[0],now);
            t_gone=subtract_time(now,night[1]);
        }
        else{
            t_remaining=subtract_time(night[1],now);
            t_gone=subtract_time(now,night[0]);
        }
    }else{
        if(is_greater_time(now,morning[1]) && is_greater_time(night[0],now)){
            t_remaining=subtract_time(night[0],now);
            t_gone=subtract_time(now,morning[1]);
        }else{
            morning[0].hour+=24;
            t_remaining=subtract_time(morning[0],now);
            t_gone=subtract_time(now,night[1]);
        }
    }
        TextColor(112);
        gotoxy(50,24);  print_now_nepali_date();
        gotoxy(70,0);   printf("%.2d:%.2d:%.2d",get_now_time().hour,get_now_time().minute,get_now_time().second);
        gotoxy(42,20);
        TextColor(127);
        printf("(");
        time_printf(t_gone);    printf(",- "); time_printf(t_remaining);
        printf(")");
    Sleep(0);
        }
    ch=getch();
    switch(ch){
        case 75:    ///left key
            if(tb.now_pos>1){
                tb.now_pos--;
                refresh_draw_tab(tb,(tb.now_pos+1));
                draw_ls_schedule_tab_content(group[tb.now_pos]);
            }
            else if(tb.now_pos==1){
                tb.now_pos=tb.items;
                refresh_draw_tab(tb,1);
                draw_ls_schedule_tab_content(group[tb.now_pos]);
            }
            handle_tab_control(tb);
            break;
        case 77:    ///right key
            if(tb.now_pos<tb.items){
                    tb.now_pos++;
                refresh_draw_tab(tb,(tb.now_pos-1));
                draw_ls_schedule_tab_content(group[tb.now_pos]);
            }
            else if(tb.now_pos==tb.items){
                tb.now_pos=1;
                refresh_draw_tab(tb,tb.items);
                draw_ls_schedule_tab_content(group[tb.now_pos]);
            }
            handle_tab_control(tb);
            break;
        case 49:
            in=tb.now_pos;
            tb.now_pos=1;
            refresh_draw_tab(tb,in);
                draw_ls_schedule_tab_content(group[tb.now_pos]);
            handle_tab_control(tb);
            break;
        case 50:
            in=tb.now_pos;
            tb.now_pos=2;
            refresh_draw_tab(tb,in);
                draw_ls_schedule_tab_content(group[tb.now_pos]);
            handle_tab_control(tb);
            break;
        case 51:
            in=tb.now_pos;
            tb.now_pos=3;
            refresh_draw_tab(tb,in);
                draw_ls_schedule_tab_content(group[tb.now_pos]);
            handle_tab_control(tb);
            break;
        case 52:
            in=tb.now_pos;
            tb.now_pos=4;
            refresh_draw_tab(tb,in);
                draw_ls_schedule_tab_content(group[tb.now_pos]);
            handle_tab_control(tb);
            break;
        case 53:
            in=tb.now_pos;
            tb.now_pos=5;
            refresh_draw_tab(tb,in);
                draw_ls_schedule_tab_content(group[tb.now_pos]);
            handle_tab_control(tb);
            break;
        case 54:
            in=tb.now_pos;
            tb.now_pos=6;
            refresh_draw_tab(tb,in);
                draw_ls_schedule_tab_content(group[tb.now_pos]);
            handle_tab_control(tb);
            break;
        case 55:
            in=tb.now_pos;
            tb.now_pos=7;
            refresh_draw_tab(tb,in);
                draw_ls_schedule_tab_content(group[tb.now_pos]);
            handle_tab_control(tb);
            break;
        case 27:
            break;
        case 'r':
        case 'R':
            for(a=1;a<=7;a++)
                group[a]=load_group_ls_time(LS_SCHEDULE_FILE_NAME,a);
            draw_ls_schedule_tab_content(group[tb.now_pos]);
            handle_tab_control(tb);
            break;
        default:
            handle_tab_control(tb);
            break;
    }
}
int show_now_loadshedding()
{
Tab grp_tab;
int a;
for(a=1;a<=7;a++)
    group[a]=load_group_ls_time(LS_SCHEDULE_FILE_NAME,a);
ShowConsoleCursor(0);
grp_tab.lx=0;
grp_tab.ly=1;
grp_tab.height=22;
grp_tab.width=80;
grp_tab.items=7;
grp_tab.now_pos=1;
grp_tab.item_char[1]="Group-01";
grp_tab.item_char[2]="Group-02";
grp_tab.item_char[3]="Group-03";
grp_tab.item_char[4]="Group-04";
grp_tab.item_char[5]="Group-05";
grp_tab.item_char[6]="Group-06";
grp_tab.item_char[7]="Group-07";
TextColor(112);
DrawBox0(0,0,80,1,TAB_BG_TEXT);   gotoxy(1,0); putchar(240);
gotoxy(3,0);    printf("Loadshedding Schedule",254);
draw_tab(grp_tab);
TextColor(151);   DrawBox0(0,23,80,1,TAB_BG_TEXT);
TextColor(112);   DrawBox0(0,24,80,1,TAB_BG_TEXT);
gotoxy(0,24);
cprintf("\x1B",112); cprintf("ESC   R",115); cprintf("efresh     ",112);
gotoxy(0,0);
handle_tab_control(grp_tab);
getch();
}

#endif // SHOW_NOW_LS_H
