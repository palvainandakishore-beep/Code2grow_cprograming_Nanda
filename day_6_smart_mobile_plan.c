#include <stdio.h>
int main()
{
    int dataused,student_status,coperate_status,extradata;
    float base_cost,extra_cost, finalbill,discount;
    char plan;
    printf("Enter the data used (in GB): ");
    scanf("%d", &dataused);
    printf("enter student status (1 for yes , 0 for no): ");
    scanf("%d", &student_status);
    printf("enter coperate status (1 for yes , 0 for no): ");
    scanf("%d", &coperate_status);
    if (dataused>100)
    {
        printf("excessive data usage\n");
    }
    if(dataused<30)
    {
        base_cost=299;
        extradata=dataused-30;
        extra_cost=extradata*50;
        printf("selected plan: silver\n");
    }
    else if(dataused>=30 && dataused<=60)
    {
        base_cost=499;
        extradata=dataused>=60?dataused-60:0;
        extra_cost=extradata*40;
        printf("selected plan: gold\n");
    }
    else if(dataused>60 && dataused<=100)
    {
        base_cost=799;
        extradata=dataused-60;
        extra_cost=extradata*30;
        printf("selected plan: platinum\n");
    }
        
    finalbill=base_cost+extra_cost;
    if(student_status==1)
    {
        discount=finalbill*0.15;
        finalbill=finalbill-discount;
    }
    else if(coperate_status==1)
    {
        discount=finalbill*0.10;
        finalbill=finalbill-discount;
    }
    printf("user plan summary\n");
    printf("Data used: %d GB\n", dataused);
    printf("Base cost: %f\n", base_cost);
    printf("Extra data used: %d GB\n", extradata);
    printf("Extra cost: %f\n", extra_cost);
    printf("Discount applied IN rupees : %f\n", discount);
    printf("Final bill: %f\n", finalbill);
    return 0;
}