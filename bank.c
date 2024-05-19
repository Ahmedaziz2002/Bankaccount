#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//A structure for a bank account
struct BankAccount{
    int accountno;
    char ownername[50];
    float balance;
    float amount;
};
//functioin to open a new account
struct BankAccount openAccount(int accountno,char ownername[50],float initialbalance,float amount){
    struct BankAccount newAccount;
    newAccount.accountno=accountno;
    strcpy(newAccount.ownername,ownername);
    newAccount.balance=initialbalance;
    printf("ACCOUNT SUCCESSFULLY OPENED!");
    return newAccount;
}
void deposit(struct BankAccount*accountno,float balance,float amount);

//function to deposit money into an account
void deposit(struct BankAccount*accountno,float balance,float amount){
    accountno->balance+=amount;
    printf("Deposit of $.%2f successful.\n",amount);
}
//Function to withdraw money from the account
void withdraw(struct BankAccount*account,float amount){
    if(account->balance>=amount){
        account->balance-=amount;
        printf("Withdrawal of $.%2f successful.\n",amount);
    }else{
        printf("Insufficient Balance.\n");
    }
}
int main(){
    struct BankAccount myAccount;
    myAccount=openAccount(1001,"Ahmed Aziz",10000000.0,1000.0);

    int choice;
    float amount;

    printf("WELCOME,%s!\n",myAccount.ownername);

    do{
        printf("\n Choose an option:\n");
        printf("1.Deposit\n");
        printf("2.Withdraw\n");
        printf("3.Check Balance\n");
        printf("4.Exit\n");
        printf("Enter your choice\n");
        scanf(" %d",(int*)&choice);

        switch (choice){
            case 1:
            printf("Enter Amount to Deposit:");
            scanf("%f",&amount);
            deposit(&myAccount, amount,amount);
            break;

            case 2:
            printf("Enter Amount to withdraw:");
            scanf("%f",&amount);
            withdraw(&myAccount, amount);
            break;

            case 3:
            printf("Current Balance:$.%2f\n",myAccount.balance);
            break;

            case 4:
            printf("Thank you for visiting our service.Have it nice!");
            break;

            default:
            printf("Invalid choice try Again!");

        }
    }while (choice!=4);
    return 0;
}
