#ifndef LS_H
#define LS_H
    #define MAX_PLACES_IN_A_GROUP 32
    #define NUMBER_OF_GROUPS 7
    #include<stdio.h>
    #include<windows.h>
    #include<time.h>
    #define LS_SCHEDULE_FILE_NAME "ls-schedule.ls"

 ///   #include "D:\c\GR_H\DateConverter.h"


    typedef struct{
                    unsigned int hour,minute,second;
    }Time;
    typedef struct{
                    Time morning[2],day[2],night[2];
    }Day;
    typedef struct{
                    unsigned int number;
                    Day day[8];///0,1-morning time,2,3-day time,4,5-evening time; day[1] is starting and is indicated to sunday.
                    int places_id[MAX_PLACES_IN_A_GROUP];
                    int state,is_off; ///shows wheather perticular group is on or off 1-ON 0-OFF
    }ls_group;

    ls_group grps[(NUMBER_OF_GROUPS+1)];


    Time copy_time(Time source)
    {
        Time dest;
        dest.hour=source.hour;
        dest.minute=source.minute;
        dest.second=source.second;
    return dest;
    }
    ls_group copy_group_times(ls_group g_source,int diff_day) /* diff_day --> difference of day between two group g1 and g2 having same schedule*/
    {
        ls_group g_dist;
        int i,i1;
        for(i=1;i<=7;i++){
                if((i+diff_day)<=7)
                   i1=(i+diff_day);
                else
                    i1=(i+diff_day-7);
            g_dist.day[i1].morning[0]=(g_source.day[i].morning[0]);
            g_dist.day[i1].morning[1]=(g_source.day[i].morning[1]);
            g_dist.day[i1].night[0]=(g_source.day[i].night[0]);
            g_dist.day[i1].night[1]=(g_source.day[i].night[1]);
        }
    return g_dist;
    }
    Time add_time(Time t1,Time t2)
    {
        Time sum;
        sum.hour=t1.hour+t2.hour;
        sum.minute=t1.minute+t2.minute;
        sum.second=t1.second+t2.second;
        if (sum.second>=60){
            ++sum.minute;
            sum.second-=60;
        }
        if(sum.minute>=60){
            ++sum.hour;
            sum.minute-=60;
        }
        return sum;
    }
    Time subtract_time(Time t1,Time t2)
    {
        Time sub;
        int seconds;
        if((t1.hour>t2.hour) || (t1.hour==t2.hour && t1.minute>t2.minute) || (t1.hour==t2.hour && t1.minute==t2.minute && t1.second>t2.second)){
           seconds=(t1.hour*3600+t1.minute*60+t1.second)-(t2.hour*3600+t2.minute*60+t2.second);
           sub.hour=(seconds/3600);
           sub.minute=(seconds-sub.hour*3600)/60;
           sub.second=(seconds-sub.hour*3600-sub.minute*60);
        }
        else{
            seconds=(t2.hour*3600+t2.minute*60+t2.second)-(t1.hour*3600+t1.minute*60+t1.second);
           sub.hour=(seconds/3600);
           sub.minute=(seconds-sub.hour*3600)/60;
           sub.second=(seconds-sub.hour*3600-sub.minute*60);
        }
    return sub;
    }

            ///Increament function
    Time time_increase(Time source_actual,Time increase_time)
    {
        Time source,time_temp;
        source=copy_time(source_actual);
                time_temp=add_time(source,increase_time);
        source=copy_time(time_temp);
    return source;
    }

    void time_printf(Time t1)
    {
    printf("%.2u:%.2u",t1.hour,t1.minute);
    }
    void time_fprintf(FILE *fle,Time t1)
    {
    fprintf(fle,"%.2u:%.2u:%.2u",t1.hour,t1.minute,t1.second);
    }
    void file_printf(char file_name[32])
    {
        FILE *ls_file;
        char ch_file;
        ls_file=fopen(file_name,"r");
        if(ls_file==NULL)
            printf("\n\tNO loadshedding Schedule Found!\n\tFirst create a loadshedding schedule...");
        else{
            while((ch_file=fgetc(ls_file))!=EOF)
                printf("%c",ch_file);
        }
    fclose(ls_file);
    }

    ///Function to take the default time on making loadshedding schedule
    Time use_default_ls_time(char   ver) ///character to verify which time is to make default 'm'-> morning
    {
        Time t1;
        if(ver=='m'){
            t1.hour=3;
            t1.minute=0;
            t1.second=0;
        }
        else if(ver=='d'){
            t1.hour=12;
            t1.minute=0;
            t1.second=0;
        }
        else if(ver=='n'){
            t1.hour=13;
            t1.minute=0;
            t1.second=0;
        }
        else{
            t1.hour=0;
            t1.minute=0;
            t1.second=0;
        }
    return t1;
    }
    ///Function to initialize all the time of a week one day's time given..
/**Declearation of time***/Time time_increase_duration={1,0,0};
    ls_group initialize_group_ls_time(ls_group g1,int day)
    {
        int i;
        ls_group g2=g1;
        for(i=1;i<=7;i++){
            if(i==day)
                continue;
                ///Increase or decrease time with ls time.
            else if(i>day){
                g2.day[day].morning[0]=(add_time(g2.day[day].morning[0],time_increase_duration));
                g2.day[day].morning[1]=(add_time(g2.day[day].morning[1],time_increase_duration));
                g2.day[day].night[0]=(add_time(g2.day[day].night[0],time_increase_duration));
                g2.day[day].night[1]=(add_time(g2.day[day].night[1],time_increase_duration));
            }
            else if(i<day){
                g2.day[day].morning[0]=(subtract_time(g2.day[day].morning[0],time_increase_duration));
                g2.day[day].morning[1]=(subtract_time(g2.day[day].morning[1],time_increase_duration));
                g2.day[day].night[0]=(subtract_time(g2.day[day].night[0],time_increase_duration));
                g2.day[day].night[1]=(subtract_time(g2.day[day].night[1],time_increase_duration));
            }
            g1.day[i].morning[0]=(g2.day[day].morning[0]);
            g1.day[i].morning[1]=(g2.day[day].morning[1]);
            g1.day[i].night[0]= (g2.day[day].night[0]);
            g1.day[i].night[1]=(g2.day[day].night[1]);
        }
    return g1;
    }

void fprintf_ls_schedule(char file_name[32],ls_group *grps)
{
FILE *file_ls_schedule;
int i,j;
    file_ls_schedule=fopen(file_name,"w");
        fprintf(file_ls_schedule,"\t\t\t\t\tSUN.\t\t\t\t\t\tMON.\t\t\t\t\t\tTUE.\t\t\t\t\t\tWED.\t\t\t\t\t\tTHU.\t\t\t\t\t\tFRI.\t\t\t\t\t\tSAT.");
        for(i=1;i<=7;i++){
        fprintf(file_ls_schedule,"\nGroup-%d\t\t\t",i);
            for(j=1;j<=7;j++){
            time_fprintf(file_ls_schedule,grps[i].day[j].morning[0]);   fprintf(file_ls_schedule,"-");
            time_fprintf(file_ls_schedule,grps[i].day[j].morning[1]);   fprintf(file_ls_schedule,"\t\t\t");
            }
            fprintf(file_ls_schedule,"\n\t\t\t\t");
            for(j=1;j<=7;j++){
            time_fprintf(file_ls_schedule,grps[i].day[j].night[0]);     fprintf(file_ls_schedule,"-");
            time_fprintf(file_ls_schedule,grps[i].day[j].night[1]);     fprintf(file_ls_schedule,"\t\t\t");
            }
            fprintf(file_ls_schedule,"\n");
        }
    fclose(file_ls_schedule);
}
Time get_now_time()
{
Time tme;
SYSTEMTIME systime;
    GetLocalTime(&systime);
    tme.hour=systime.wHour;
    tme.minute=systime.wMinute;
    tme.second=systime.wSecond;
return tme;
}
///Function to load loadshedding database from .ls file saved by the program..
Time load_ls_time(FILE *fl)
{
Time ls_tm={0,0,0};;
    fscanf(fl,"%d",&ls_tm.hour);
    fseek(fl,1,SEEK_CUR);
    fscanf(fl,"%d",&ls_tm.minute);
    fseek(fl,1,SEEK_CUR);
    fscanf(fl,"%d",&ls_tm.second);
return ls_tm;
}
ls_group load_group_ls_time(char f_name[32],unsigned int grp_no)
{
int i,cursor_pos_1=81,cursor_pos_2=226;
ls_group grps[3];
FILE *ls_schedule;
ls_schedule=fopen(f_name,"r");
fseek(ls_schedule,cursor_pos_1,SEEK_SET);
    for(i=1;i<=7;i++){
        grps[1].day[i].morning[0]=load_ls_time(ls_schedule);
        fseek(ls_schedule,1,SEEK_CUR);
        grps[1].day[i].morning[1]=load_ls_time(ls_schedule);
        fseek(ls_schedule,3,SEEK_CUR);
    }
    fseek(ls_schedule,cursor_pos_2,SEEK_SET);
    for(i=1;i<=7;i++){
        grps[1].day[i].night[0]=load_ls_time(ls_schedule);
        fseek(ls_schedule,1,SEEK_CUR);
        grps[1].day[i].night[1]=load_ls_time(ls_schedule);
        fseek(ls_schedule,3,SEEK_CUR);
    }
        grps[2]=copy_group_times(grps[1],(grp_no-1));
        return grps[2];
fclose(ls_schedule);
}
int is_greater_time(Time t1,Time t2)
{
    if(t1.hour>t2.hour || (t1.hour==t2.hour && t1.minute>t2.minute) || (t1.hour==t2.hour && t1.minute==t2.minute && t1.second>t2.second))
        return 1;
    else
        return 0;
}
#endif // LS_H_INCLUDED
