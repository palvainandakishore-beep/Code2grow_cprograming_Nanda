#include<stdio.h>
int main()
{
   int totalbill,units_consumed;
   printf("enter total units consumed:");
   scanf("%d",&units_consumed);
   if(units_consumed<=100)
   {
       printf("the rate per unit is 3.00\n");
       totalbill=units_consumed*3+50.0;//fixed meter charge
       printf("the total bill is %d\n",totalbill);
   }
else if(units_consumed>=101 && units_consumed<=200)
{
    printf("the rate per unit is 4.50\n");
    totalbill=units_consumed*4.50+50.0;//fixed meter charge
    printf("the total bill is %d\n",totalbill);
}
else if(units_consumed>=201 && units_consumed<=300)
{
    printf("the rate per unit is 6.00\n");
    totalbill=units_consumed*6.00+50.0;//fixed meter charge
    printf("the total bill is %d\n",totalbill);
}
else
{
    printf("the rate per unit is 8.00\n");
    totalbill=units_consumed*8.00+50.0;//fixed meter charge
    printf("the total bill is %d\n",totalbill);
}  
return 0;
}