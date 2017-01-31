#include <stdio.h>
#include<stdlib.h>

int maxsize = 5;
typedef struct time_details {
    int hour;
    int min;
    char am_pm[3];
}Time;
typedef struct train_details {
    char name_train[30];
    Time time;
}TrainDetail;


void EnterDetails(void);
void PrintDetails(void);
void main()
{
  EnterDetails();
    
}

void EnterDetails(void)
{

    TrainDetail Train[maxsize];
    int count = 0, TempTime;
    printf("TRAIN DETAILS\n");
    for(count=0;count<maxsize;count++)
    {
    printf("NAME?\n");
    scanf("%s", Train[count].name_train);
    printf("TIME (Format:1130 for 11:30)");
    scanf("%d", &TempTime);
    printf("AM/PM");
    scanf("%s", Train[count].time.am_pm);
    if(Train[count].time.am_pm[0]=='P' ||Train[count].time.am_pm[0]=='p')
        Train[count].time.hour=((TempTime/100)+12);
    else
        Train[count].time.hour=(TempTime/100);
    Train[count].time.min=(TempTime%100);
    }
        for(count=0;count<maxsize;count++)
    {
        printf("NAME: %s\n", Train[count].name_train);
        printf("TIME: %d:%d\n", Train[count].time.hour, Train[count].time.min);
        printf("---------------\n");
    }


}


