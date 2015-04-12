#include <stdio.h>
#include <stdlib.h>
#include "graphics_lib.h"
#include "ls.h"
#include "DateConverter.h"
#include "AutoShedding.h"
#include"show_now_ls.h"
#include"TXT.h"
void main_menu();
void make_ls_schedule();
void group_is_off_no()
{
int i;
    for(i=1;i<=7;i++)
        group[i].is_off=NO;
}
void make_ls_schedule()
{
int ms,i;
char file_name[20]=LS_SCHEDULE_FILE_NAME;
ls_group grp;
Time td,default_morning_start={1,0,0},default_night_start={14,0,0};
gotoxy(1,24);   printf("Choose one option.");
xnMenu mnu_mls;
mnu_mls.lx=25; mnu_mls.ly=2;mnu_mls.width=25;mnu_mls.items=3; mnu_mls.now_pos=1; mnu_mls.last_pos=1;
    mnu_mls.item_char[1]="Time Duration.";
    mnu_mls.item_char[2]="One day time";
    mnu_mls.item_char[3]="All week time";
print_xnMenu(mnu_mls);
ms=handle_xnMenu(mnu_mls);
    switch(ms){
        case 1:
            TextColor(112);
                system("cls");
                DrawBox1(0,1,80,23,32);
                gotoxy(1,24);   printf("This will make loadshedding schedule using default time.");
                gotoxy(1,3);    printf("Enter Duration of loadshedding(hh/mm/ss):");
                ShowConsoleCursor(YES);
                scanf("%d%d%d",&td.hour,&td.minute,&td.second);
                ShowConsoleCursor(NO);
                auto_schedule_make(file_name,td,default_morning_start,default_night_start);
                Sleep(200);
                gotoxy(1,24); printf("Schedule made successfuflly..                                                                      ");
                Sleep(1000);
                main_menu();
        break;
        case 2:
            TextColor(112);
                system("cls");
                DrawBox1(0,1,80,23,32);
                gotoxy(1,24);   printf("This will make loadshedding schedule using time you provide.");
                gotoxy(1,3);    printf("Enter Duration of loadshedding(hh/mm/ss):");
                ShowConsoleCursor(YES);
                scanf("%d%d%d",&td.hour,&td.minute,&td.second);
                gotoxy(1,4);
                printf("Enter least morning time to start loadshedding:");
                scanf("%d%d%d",&default_morning_start.hour,&default_morning_start.minute,&default_morning_start.second);
                gotoxy(1,5);
                printf("Enter least night time to start loadshedding:");
                scanf("%d%d%d",&default_night_start.hour,&default_night_start.minute,&default_night_start.second);
                ShowConsoleCursor(NO);
                auto_schedule_make(file_name,td,default_morning_start,default_night_start);
                Sleep(200);
                gotoxy(1,24); printf("Schedule made successfuflly..                                                                      ");
                Sleep(1000);
                main_menu();
        break;
        case 3:
            TextColor(112);
                system("cls");
                gotoxy(1,24);   printf("This will make loadshedding schedule using group-1 time.");
            for(i=1;i<=7;i++){
                DrawBox1(0,1,80,23,32);
                gotoxy(1,3);
                ShowConsoleCursor(YES);
                printf("Enter loadshedding time morning of day %d(hh/mm/ss):",i);
                scanf("%d%d%d",&grp.day[i].morning[0].hour,&grp.day[i].morning[0].minute,&grp.day[i].morning[0].second);
                gotoxy(1,4);    printf("to (hh/mm/ss):");
                scanf("%d%d%d",&grp.day[i].morning[1].hour,&grp.day[i].morning[1].minute,&grp.day[i].morning[1].second);
                gotoxy(1,5);    printf("Enter loadshedding time night of day %d(hh/mm/ss):",i);
                scanf("%d%d%d",&grp.day[i].night[0].hour,&grp.day[i].night[0].minute,&grp.day[i].night[0].second);
                gotoxy(1,6);    printf("to (hh/mm/ss):");
                scanf("%d%d%d",&grp.day[i].night[1].hour,&grp.day[i].night[1].minute,&grp.day[i].night[1].second);
            }
            auto_schedule_make_week_time(file_name,grp);
            Sleep(200);
                gotoxy(1,24); printf("Schedule made successfuflly..                                                                      ");
                Sleep(1000);
            main_menu();
        break;
        default:
            main_menu();
        break;
        }
    }

void power_control()
{
int ms,grp_no;
xnMenu mnu_mls;
mnu_mls.lx=25; mnu_mls.ly=5;mnu_mls.width=25;mnu_mls.items=2; mnu_mls.now_pos=1; mnu_mls.last_pos=1;
    mnu_mls.item_char[1]="Power OFF";
    mnu_mls.item_char[2]="Power ON";
print_xnMenu(mnu_mls);
ms=handle_xnMenu(mnu_mls);
    switch(ms){
        case 1:
                DrawBox1(15,10,45,4,32);
                gotoxy(17,11);  printf("Enter group number to power off:"); scanf("%d",&grp_no);
                DrawBox0(15,10,45,4,32);
                if(grp_no>0 && grp_no<=7)
                    group[grp_no].is_off=YES;
                else{
                    gotoxy(17,12);
                    printf("Enter valid group no.");
                    power_control();
                }
            main_menu();
            break;
        case 2:
                DrawBox1(15,10,45,4,32);
                gotoxy(17,11);  printf("Enter group number to power on:"); scanf("%d",&grp_no);
                DrawBox0(15,10,45,4,32);
                if(grp_no>0 && grp_no<=7)
                    group[grp_no].is_off=NO;
                else{
                    gotoxy(17,12);
                    printf("Enter valid group no.");
                    power_control();
                }
            main_menu();
            break;
        default:
            main_menu();
            break;
        }
}
void main_menu()
{
    char chs;
    TextColor(240);
    system("cls");
    int menu_s;
    xnMenu main_xnMenu;
    ShowConsoleCursor(NO);
    TextColor(112);
    DrawBox0(0,1,80,23,177);
    TXTprintf("ASCS",19,6,121,0);
    DrawHorizontalLine2(19,16,42);
    gotoxy(27,16);  printf("AutoShedding Control System.");
    gotoxy(3,0);    cprintf("Main Menu",128);
    TextColor(240);
    gotoxy(1,0);    printf("%c",240);
    gotoxy(1,24);   printf("Select One Option.");
    TextColor(128);
    main_xnMenu.lx=2;main_xnMenu.ly=1,main_xnMenu.items=5;main_xnMenu.width=30;main_xnMenu.now_pos=1;
    main_xnMenu.item_char[1]="Make LS schedule";
    main_xnMenu.item_char[2]="View LS schedule";
    main_xnMenu.item_char[3]="Power Control";
    main_xnMenu.item_char[4]="-";
    main_xnMenu.item_char[5]="Exit";
    GO_TOP
    while(!kbhit()){
            TextColor(240);
            gotoxy(52,0);   print_now_nepali_date();
            gotoxy(71,24);  print_now_nepali_time();
            Sleep(10);
    }
    chs=getch();
    if(chs=='m' || chs=='M' || chs==78){
        print_xnMenu(main_xnMenu);
        menu_s=handle_xnMenu(main_xnMenu);
    switch(menu_s){
    case 1:
            make_ls_schedule();
        break;
    case 2:
            show_now_loadshedding();
            main_menu();
        break;
    case 3:
            power_control();
        break;
    case 5:
        DrawBox2(0,20,80,4,32);
        gotoxy(2,21);
        printf("Are you sure to exit?(\"system may crash\")(y/n):");
        if(getchar()=='y' || getchar()=='Y')
            exit(EXIT_SUCCESS);
        else
            main_menu();
        break;
    default:
        main_menu();
        break;
    }
    }
    else
        main_menu();
}

int main()
{
    group_is_off_no();
    ShowConsoleCursor(NO);
    TextColor(240);
    system("cls");
    TextColor(112);
    DrawBox0(0,1,80,23,177);
    TXTprintf("ASCS",19,6,121,05);
    TextColor(55);
    DrawBox0(19,16,44,5,32);
    LoadingAnimation(26,17,30,10,"Loading...",55);
    Sleep(100);
    TextColor(112);
    DrawBox0(14,16,44,5,177);
    main_menu();
    return 0;
}
