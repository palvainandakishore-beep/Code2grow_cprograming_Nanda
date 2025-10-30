#include<stdio.h>
int main()
{
    int choice;
    float balance=10000.00;
    float amount,bonus;
    do{//using do loop untill the customer exit
      printf("1.Deposit Money:\n");
      printf("2.Withdraw Money:\n");
      printf("3.Check Balance:\n");
      printf("4.Exit :\n");
      printf("enter value for choice: ");
      scanf("%d",&choice); 

      if(choice==1) //deposit
     {
        printf("Enter amount to Deposit:");
        scanf("%f",&amount);
        if(amount>25000)
        {
            bonus=amount*0.01; 
            printf("the bonus is:%f\n",bonus);
        balance+=amount+bonus; // bonus of 1%  
        }
        else
        {
            balance+=amount;
        }
        balance-=5; // service charge
        printf("service charge $5 appiled\n");
        printf("updated balance is:$%f\n",balance);
        }
        else if(choice==2) // withdraw
     { 
        printf("Enter amount to withdraw: ");
        scanf("%f",&amount);
        if(amount>balance)
        {
            printf("Warning: Insufficient funds.\n");
        }
        else{
            balance-=amount;
            balance-=5;// service charge
            printf("service charge $5 is applied\n");
            printf("updated balance is :$%f\n",balance);
        }
        }
        else if(choice==3)// check bank balance
        {
        printf("your current balance is:$%f\n",balance);
        }
        else if (choice==4)
        {
            printf("Thank you for banking with us ");
        }
    }
    while(choice!=4);
return 0;

}