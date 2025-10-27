
#include <stdio.h>
int main()
{
    int age,health;
    char gender;
    float final_premium;
    printf("enter value for age:");
    scanf("%d",&age);
    printf("enter value for gender:M/F");
    scanf(" %c",&gender);
    printf("enter value for health condition:1-healthy/0-unhealthy");
    scanf("%d",&health);
  
    if(age<25 && health==0 )
    {
        printf("status=not_eligible");
    }
    else if(age<25 && health==1)
    {
        if(gender=='M')
        {
            final_premium=5000;
            printf("final_premium=%f\n",final_premium);
        }
        else
        {
            final_premium=5000*0.9;
            printf("final_premium=%f\n",final_premium);
        }
    }
    else if(age>=25 &&age<=40 && health==1)
    {
        if(gender=='M')
        {
            final_premium=7000;
            printf("final_premium=%f\n",final_premium);
        }
        else
        {
            final_premium=7000*0.9;
            printf("final_premium=%f\n",final_premium);
        }
    }
    else if(age>=25 && age<=40 && health==1)
    {
        if(gender=='M')
        {
            final_premium=9500;
            printf("final_premium=%f\n",final_premium);
        }
        else
        {
            final_premium=9500*0.9;
            printf("final_premium=%f\n",final_premium);
        }
    }
    else if(age>40 && age<=60 && health==1)
    {
        if(gender=='M')
        {
            final_premium=10000;
            printf("final-premium=%f\n",final_premium);
        }
        else
        {
            final_premium=10000*0.9;
            printf("final_premium=%f\n",final_premium);
        }
        
    }
    else if(age>40 && age<=60 && health==1)
    {
        if(gender=='M' )
        {
            final_premium=13000;
            printf("final_premium=%f\n",final_premium);
        }
        else
        {
            final_premium=13000*0.9;
            printf("final_premium=%f\n",final_premium);
        }
    }
    else if(age>60 && health==1)
    {
        if(gender=='M' )
        {
            final_premium=15000;
            printf("final_premium=%f\n",final_premium);
        }
        else
        {
            final_premium=15000*0.9;
            printf("final_premium=%f\n",final_premium);
        }
    }
    else 
    {
        printf("Status=not_eligible");
    }
   


printf("customer details:\n");
printf("age:%d\n",age);
printf("gender:%c\n",gender );
printf("final premium:%.2f\n",final_premium);
return 0;   
    
}
