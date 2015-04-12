#ifndef DATECONVERTER_H_INCLUDED
#define DATECONVERTER_H_INCLUDED


    #include<stdio.h>
    #include<string.h>
    #include<windows.h>
    #include<time.h>

    #define BS_MINIMUM_YEAR 2000
    #include"DateConverter.h"
	typedef struct{
			int year;
			int month;
			int day;
			}Date;

    ///THIS IS A DATE TAKEN AS REFERENCE ARE EQUAL...
    Date bs_base_date={2000,01,01},ad_base_date={1943,04,14};   ///Day: wednesday
    Date bs_extreme_date={2099,12,30},ad_extreme_date={2043,4,13};

    Date add_days_in_BS_date(Date dt,int days);
    int days_in_year_BS(int year);
    int days_in_month_BS(int year,int month);
    int days_remaining_in_BS_year(Date dt);
    int days_till_in_BS_date(Date dt);
    int is_leap_year(int year);
    int days_in_month_AD(int year,int month);
    int days_in_AD_year(int year);
    int days_remaining_in_AD_year(Date dt);
    int days_till_in_AD_date(Date dt);
    int difference_of_BS_dates(Date d1,Date d2);
    Date add_days_in_AD_date(Date dt,int days);
    Date add_days_in_BS_date(Date dt,int days);
    Date convert_AD_date_to_BS(Date ad_date);

    int NepaliDate[100][12]={
                             {30,32,31,32,31,30,30,30,29,30,29,31} ,	///This Includes number of day in month...
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,31,32,32,31,30,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,31} ,
							 {30,32,31,32,31,30,30,30,29,30,29,31} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,31,32,32,31,30,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,31} ,
							 {31,31,31,32,31,31,29,30,30,29,29,31} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,31,32,32,31,30,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,31} ,
							 {31,31,31,32,31,31,29,30,30,29,30,30} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,31,32,32,31,30,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,31} ,
							 {31,31,31,32,31,31,29,30,30,29,30,30} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,30,29,31} ,
							 {31,31,31,32,31,31,30,29,30,29,30,30} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,30,29,31} ,
							 {31,31,31,32,31,31,30,29,30,29,30,30} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,31} ,
							 {30,32,31,32,31,30,30,30,29,30,29,31} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,31,32,31,32,30,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,31} ,
							 {30,32,31,32,31,30,30,30,29,30,29,31} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,31,32,32,31,30,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,31} ,
							 {30,32,31,32,31,31,29,30,30,29,29,31} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,31,32,32,31,30,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,31} ,
							 {31,31,31,32,31,31,29,30,30,29,30,30} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,31,32,32,31,30,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,31} ,
							 {31,31,31,32,31,31,29,30,30,29,30,30} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,31} ,
							 {31,31,31,32,31,31,30,29,30,29,30,30} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,30,29,31} ,
							 {31,31,31,32,31,31,30,29,30,29,30,30} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,30,29,31} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,31,32,31,32,30,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,31} ,
							 {30,32,31,32,31,30,30,30,29,30,29,31} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,31,32,32,31,30,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,31} ,
							 {30,32,31,32,31,31,29,30,29,30,29,31} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,31,32,32,31,30,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,31} ,
							 {31,31,31,32,31,31,29,30,30,29,29,31} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,31,32,32,31,30,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,31} ,
							 {31,31,31,32,31,31,29,30,30,29,30,30} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,31} ,
							 {31,31,31,32,31,31,30,29,30,29,30,30} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,30,29,31} ,
							 {31,31,31,32,31,31,30,29,30,29,30,30} ,
							 {31,31,32,31,31,31,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,29,30,30} ,
							 {31,31,32,32,31,30,30,30,29,30,30,30} ,
							 {30,32,31,32,31,30,30,30,29,30,30,30} ,
							 {31,31,32,31,31,30,30,30,29,30,30,30} ,
							 {31,31,32,31,31,30,30,30,29,30,30,30} ,
							 {31,32,31,32,30,31,30,30,29,30,30,30} ,
							 {30,32,31,32,31,30,30,30,29,30,30,30} ,
							 {31,31,32,31,31,31,30,30,29,30,30,30} ,
							 {30,31,32,32,30,31,30,30,29,30,30,30} ,
							 {30,32,31,32,31,30,30,30,29,30,30,30} ,
							 {30,32,31,32,31,30,30,30,29,30,30,30} ,
							 {31,31,32,31,31,31,30,30,29,30,30,30} ,
							 {30,31,32,32,31,30,30,30,29,30,30,30} ,
							 {30,32,31,32,31,30,30,30,29,30,30,30} ,
							 {31,31,32,31,31,30,30,30,29,30,30,30} ,
							 {31,31,32,31,31,31,30,29,30,30,30,30} ,
							 {30,31,32,32,31,30,30,29,30,29,30,30} ,
							 {31,32,31,32,31,30,30,30,29,30,30,30} ,
							 {31,31,32,31,31,31,29,30,29,30,29,31} ,
							 {31,31,32,31,31,31,30,29,29,30,30,30}
                            };




int days_in_month_BS(int year,int month)
{
    return NepaliDate[(year-BS_MINIMUM_YEAR)][(month-1)];
}
int days_in_year_BS(int year)
{
    int i,days=0;
    for(i=1;i<=12;i++)
        days+=days_in_month_BS(year,i);
    return days;
}

int days_remaining_in_BS_year(Date dt)
{
    int days,i;
    days=(days_in_month_BS(dt.year,dt.month)-dt.day);
    for(i=(dt.month+1);i<=12;i++)
        days+=days_in_month_BS(dt.year,i);
    return days;
}

int days_till_in_BS_date(Date dt)
{
    int days=dt.day,i;
    for(i=1;i<dt.month;i++)
        days+=days_in_month_BS(dt.year,i);
    return days;
}


int is_leap_year(int year)
{
    if((year%100!=0 && year%4==0) || year%400==0)
        return 1;
    else
        return 0;
}
int days_in_month_AD(int year,int month)
{
    switch(month){
      case 1 : return(31); break;
      case 2 : if(is_leap_year(year)){
		 return(29);    break;
      }
	       else{
		 return(28);    break;}
      case 3 : return(31);  break;
      case 4 : return(30);  break;
      case 5 : return(31);  break;
      case 6 : return(30);  break;
      case 7 : return(31);  break;
      case 8 : return(31);  break;
      case 9 : return(30);  break;
      case 10: return(31);  break;
      case 11: return(30);  break;
      case 12: return(31);  break;
      default: return(-1);  break;
    }
}

int days_in_AD_year(int year)
{
if(is_leap_year(year))
    return 366;
else
    return 365;
}

int days_remaining_in_AD_year(Date dt)
{
int days,i;
    days=(days_in_month_AD(dt.year,dt.month)-dt.day);
    for(i=(dt.month+1);i<=12;i++)
        days+=days_in_month_AD(dt.year,i);
return days;
}

int days_till_in_AD_date(Date dt)
{
int days=dt.day,i;
    for(i=1;i<dt.month;i++)
        days+=days_in_month_AD(dt.year,i);
return days;
}

int difference_of_BS_dates(Date d1,Date d2)    ///subtract d2 from d1
{
int diff_day=0,yr,ver;
        if(d1.year==d2.year)
            ver=1;
        else
            ver=0;
        for(yr=d2.year;yr<=d1.year;yr++){
            if(yr==d2.year){
                if(ver)
                    diff_day+=(days_remaining_in_BS_year(d2)-days_remaining_in_BS_year(d1));
                else
                    diff_day+=(days_remaining_in_BS_year(d2));
            }else if(yr>d2.year && yr<d1.year)
                diff_day+=days_in_year_BS(yr);
            else if(yr==d1.year)
                diff_day+=days_till_in_BS_date(d1);
        }
    return diff_day;
}

int difference_of_AD_dates(Date d1,Date d2)    ///subtract d2 from d1
{
int diff_day=0,yr,ver;
        if(d1.year==d2.year)
            ver=1;
        else
            ver=0;
        for(yr=d2.year;yr<=d1.year;++yr){
            if(yr==d2.year){
                if(ver==1)
                    diff_day+=(days_remaining_in_AD_year(d2)-days_remaining_in_AD_year(d1));
                else
                    diff_day+=(days_remaining_in_AD_year(d2));
            }else if(yr>d2.year && yr<d1.year)
                diff_day+=days_in_AD_year(yr);
            else if(yr==d1.year)
                diff_day+=days_till_in_AD_date(d1);
        }
    return diff_day;
}

Date add_days_in_AD_date(Date dt,int days)
{
Date date=dt;
int year=dt.year;
    while(days>0){
        if(days>=days_remaining_in_AD_year(date)){
            days-=days_remaining_in_AD_year(date)+1;
            ++date.year;
            date.month=1;
            date.day=1;
        }else if((days<days_remaining_in_AD_year(date)) && days>(days_in_month_AD(date.year,date.month)-date.day)){
            days-=days_in_month_AD(date.year,date.month)-date.day+1;
            ++date.month;
            date.day=1;
        }else{
            date.day+=days;
            days=0;
        }
    }
return date;
}

Date add_days_in_BS_date(Date dt,int days)
{
Date date=dt;
int year=dt.year;
    while(days>0){
        if(days>=days_remaining_in_BS_year(date)){
            days-=days_remaining_in_BS_year(date)+1;
            ++date.year;
            date.month=1;
            date.day=1;
        }else if((days<days_remaining_in_BS_year(date)) && days>(days_in_month_BS(date.year,date.month)-date.day)){
            days-=days_in_month_BS(date.year,date.month)-date.day+1;
            ++date.month;
            date.day=1;
        }else{
            date.day+=days;
            days=0;
        }
    }
return date;
}


Date subtract_days_in_AD_date(Date dt,int days)
{
Date date=dt;
int year=dt.year;
    while(days>0){
        if(days>=days_till_in_AD_date(date)){
            days-=days_till_in_AD_date(date);
            --date.year;
            date.month=12;
            date.day=days_in_month_AD(date.year,12);
        }else if((days<days_till_in_AD_date(date)) && days>=(date.day)){
            days-=date.day;
            --date.month;
            date.day=days_in_month_AD(date.year,date.month);
        }else{
            date.day-=days;
            days=0;
        }
    }
return date;
}

Date subtract_days_in_BS_date(Date dt,int days)
{
Date date=dt;
int year=dt.year;
    while(days>0){
        if(days>=days_till_in_BS_date(date)){
            days-=days_till_in_BS_date(date);
            --date.year;
            date.month=12;
            date.day=days_in_month_BS(date.year,12);
        }else if((days<days_till_in_BS_date(date)) && days>=(date.day)){
            days-=date.day;
            --date.month;
            date.day=days_in_month_BS(date.year,date.month);
        }else{
            date.day-=days;
            days=0;
        }
    }
return date;
}
Date convert_AD_date_to_BS(Date ad_date)
{
int diff_days;
Date converted_BS_date;
    diff_days=difference_of_AD_dates(ad_date,ad_base_date);
    converted_BS_date=add_days_in_BS_date(bs_base_date,diff_days);
return converted_BS_date;
}

Date convert_BS_date_to_AD(Date bs_date)
{
int diff_days;
Date converted_AD_date;
    diff_days=difference_of_BS_dates(bs_date,bs_base_date);
    converted_AD_date=add_days_in_AD_date(ad_base_date,diff_days);
return converted_AD_date;
}
Date get_now_bs_date()
{
    SYSTEMTIME systime;
    Date now_bs_date,now_ad_date;
    GetLocalTime(&systime);
    now_ad_date.year=systime.wYear;
    now_ad_date.month=systime.wMonth;
    now_ad_date.day=systime.wDay;
    now_bs_date=convert_AD_date_to_BS(now_ad_date);
return now_bs_date;
}
void print_nepali_date(Date np_date)
{
    int w_month=np_date.month,w_day=which_day_BS(np_date);
    char month_text[10],day_text[10];
    switch(w_month){
    case 1:
        strcpy(month_text,"Baishak");
        break;
    case 2:
        strcpy(month_text,"Jestha");
        break;
    case 3:
        strcpy(month_text,"Aashad");
        break;
    case 4:
        strcpy(month_text,"Shrawan");
        break;
    case 5:
        strcpy(month_text,"Bhadra");
        break;
    case 6:
        strcpy(month_text,"Ashwin");
        break;
    case 7:
        strcpy(month_text,"Kartik");
        break;
    case 8:
        strcpy(month_text,"Mangsir");
        break;
    case 9:
        strcpy(month_text,"Paush");
        break;
    case 10:
        strcpy(month_text,"Margh");
        break;
    case 11:
        strcpy(month_text,"Falgun");
        break;
    case 12:
        strcpy(month_text,"Chaitra");
        break;
    default:
        strcpy(month_text,"ERROR");
        break;
    }


    switch(w_day){
    case 0:
        strcpy(day_text,"Aaitabar");
        break;
    case 1:
        strcpy(day_text,"Sombar");
        break;
    case 2:
        strcpy(day_text,"Mangalbar");
        break;
    case 3:
        strcpy(day_text,"Budhabar");
        break;
    case 4:
        strcpy(day_text,"Bihibar");
        break;
    case 5:
        strcpy(day_text,"Sukrabar");
        break;
    case 6:
        strcpy(day_text,"Sanibar");
        break;
    default:
        strcpy(day_text,"ERROR");
        break;
    }
    printf("%-9s,%-9s %-.2d,%-.4d",day_text,month_text,np_date.day,np_date.year);
}

void print_now_nepali_date(void)
{
Date bs_dt=get_now_bs_date();
    print_nepali_date(bs_dt);
}
void print_now_nepali_time(void)
{
    char month_text[16];
    SYSTEMTIME systime;
    GetLocalTime(&systime);
    printf("%.2d:%.2d:%.2d",systime.wHour,systime.wMinute,systime.wSecond);
}
int which_day_BS(Date bs_date)
{
int diff_day,dy,day;
diff_day=difference_of_BS_dates(bs_date,bs_base_date);
dy=(diff_day%7);
    switch(dy){
    case 0:
        day=3;
        break;
    case 1:
        day=4;
        break;
    case 2:
        day=5;
        break;
    case 3:
        day=6;
        break;
    case 4:
        day=0;
        break;
    case 5:
        day=1;
        break;
    case 6:
        day=2;
        break;
    default:
        day=-1;
        break;
    }
return day;
}
int which_day_AD(Date dte)
{
    int days=difference_of_AD_dates(dte,ad_base_date),day,dy;
    dy=(days%7);
    switch(dy){
    case 0:
        day=3;
        break;
    case 1:
        day=4;
        break;
    case 2:
        day=5;
        break;
    case 3:
        day=6;
        break;
    case 4:
        day=0;
        break;
    case 5:
        day=1;
        break;
    case 6:
        day=2;
        break;
    default:
        day=-1;
        break;
    }
return day;
}

void print_ad_date(Date ad_date)
{
int which_day=which_day_AD(ad_date);
char month_text[10],day_text[10];
switch(ad_date.month){
    case 1:
        strcpy(month_text,"January");
        break;
    case 2:
        strcpy(month_text,"February");
        break;
    case 3:
        strcpy(month_text,"March");
        break;
    case 4:
        strcpy(month_text,"April");
        break;
    case 5:
        strcpy(month_text,"May");
        break;
    case 6:
        strcpy(month_text,"June");
        break;
    case 7:
        strcpy(month_text,"July");
        break;
    case 8:
        strcpy(month_text,"August");
        break;
    case 9:
        strcpy(month_text,"September");
        break;
    case 10:
        strcpy(month_text,"October");
        break;
    case 11:
        strcpy(month_text,"November");
        break;
    case 12:
        strcpy(month_text,"December");
        break;
    default:
        strcpy(month_text,"ERROR");
        break;
        }

    switch(which_day){
            case 0:
                strcpy(day_text,"Sunday");
                break;
            case 1:
                strcpy(day_text,"Monday");
                break;
            case 2:
                strcpy(day_text,"Tuesday");
                break;
            case 3:
                strcpy(day_text,"Wednesday");
                break;
            case 4:
                strcpy(day_text,"Thursday");
                break;
            case 5:
                strcpy(day_text,"Friday");
                break;
            case 6:
                strcpy(day_text,"Saturday");
                break;
            default:
                strcpy(day_text,"ERROR");
                break;
                }
printf("%-9s,%-9s %-.2d,%-.4d",day_text,month_text,ad_date.day,ad_date.year);
}
int is_valid_date(Date dt,int is_bs_date)
{
if(is_bs_date){
    if(dt.year<bs_base_date.year || (dt.year==bs_base_date.year && dt.month<bs_base_date.month) || dt.year>bs_extreme_date.year || (dt.year>bs_extreme_date.year && dt.month>bs_extreme_date.month) || dt.day<bs_base_date.day ||(dt.year=bs_base_date.year && dt.month==bs_base_date.month && dt.day>=bs_base_date.day)||(dt.year=bs_extreme_date.year && dt.month==bs_extreme_date.month && dt.day<=bs_extreme_date.day))
        return 0;
    else
        return 1;
}else{
    if(dt.year<ad_base_date.year || (dt.year==ad_base_date.year && dt.month<ad_base_date.month) || dt.year>ad_extreme_date.year || (dt.year>ad_extreme_date.year && dt.month>ad_extreme_date.month) || dt.day<ad_base_date.day ||(dt.year=ad_base_date.year && dt.month==ad_base_date.month && dt.day>=ad_base_date.day)||(dt.year=ad_extreme_date.year && dt.month==ad_extreme_date.month && dt.day<=ad_extreme_date.day))
        return 0;
    else
        return 1;
}
}
#endif // DATECONVERTER_H_INCLUDED
