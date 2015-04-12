#ifndef AUTOSHEDDING_H_INCLUDED
#define AUTOSHEDDING_H_INCLUDED

    #include<stdio.h>
    #include"ls.h"

   ///Function to make a loadshedding schedule and print it in a file
    void auto_schedule_make(char file_name[32],Time time_a_day,Time morning_start_time,Time night_start_time)
    {
    ///define variables
        FILE *file_ls_schedule;
        int time_a_day_seconds,time_morning_seconds,time_night_seconds,i,j;
        Time morning_time,night_time;   ///times structure to store loadshedding time of morning and night.

    ///Initialization
        file_ls_schedule=fopen(file_name,"w");

        grps[1].day[1].morning[0]=morning_start_time;
        grps[1].day[1].night[0]=night_start_time;
        time_a_day_seconds=(time_a_day.hour*3600+time_a_day.minute*60+time_a_day.second);///store time in second.
        time_morning_seconds=(time_a_day_seconds/2);       ///divide time by 2 for morning..
        morning_time.hour=(time_morning_seconds/3600);
        morning_time.minute=(time_morning_seconds-morning_time.hour*3600)/60;
        morning_time.second=(time_morning_seconds-morning_time.hour*3600-morning_time.minute*60);
        time_night_seconds=(time_a_day_seconds-time_morning_seconds);
        night_time.hour=(time_night_seconds/3600);
        night_time.minute=(time_night_seconds-night_time.hour*3600)/60;
        night_time.second=(time_night_seconds-night_time.hour*3600-night_time.minute*60);

        grps[1].day[1].morning[1]=add_time(grps[1].day[1].morning[0],morning_time);
        grps[1].day[1].night[1]=add_time(grps[1].day[1].night[0],night_time);
        grps[1]=initialize_group_ls_time(grps[1],1);
        for(i=2;i<=7;i++)
            grps[i]=copy_group_times(grps[1],(i-1));
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

    void auto_schedule_make_week_time(char file_name[16],ls_group grp)
    {
        FILE *file_ls_schedule;
        int i,j;
        file_ls_schedule=fopen(file_name,"w");
        for(i=1;i<=7;i++)
            grps[i]=copy_group_times(grp,(i-1));
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
#endif // AUTOSHEDDING_H_INCLUDED
