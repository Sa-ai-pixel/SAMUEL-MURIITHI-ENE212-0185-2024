#include <stdio.h>
#include <string.h>

int balance = 5000;
int correctPin = 9999;
char correctUsername[50] = "John";

int login(char username[50], int pin){
    if(strcmp(correctUsername, username) == 0 && pin == correctPin){
        return 1;
    }
    return 0;
}

void checkBalance(){
    int pin;
    printf("\nEnter PIN to check balance: ");
    scanf("%d", &pin);
    if(pin == correctPin){
        printf("Your balance is: %d\n", balance);
    }else{
        printf("Wrong PIN!\n");
    }
}

void deposit(){
    int amount;
    printf("\nEnter amount to deposit: ");
    scanf("%d", &amount);
    if(amount > 0){
        balance = balance + amount;
        printf("Deposit successful! New balance: %d\n", balance);
    }else{
        printf("Invalid amount!\n");
    }
}

void withdraw(){
    int amount;
    int pin;
    printf("\nEnter amount to withdraw: ");
    scanf("%d", &amount);
    printf("Enter PIN: ");
    scanf("%d", &pin);

    if(pin != correctPin){
        printf("Wrong PIN! Transaction failed.\n");
        return;
    }
    if(amount > balance){
        printf("Insufficient balance! Your balance is: %d\n", balance);
    }else if(amount <= 0){
        printf("Invalid amount!\n");
    }else{
        balance = balance - amount;
        printf("Transaction successful! You withdrew %d. New balance: %d\n", amount, balance);
    }
}

int main(){
    char username[50];
    int pin;
    int choice;

    printf("=== ATM SYSTEM ===\n");
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter PIN: ");
    scanf("%d", &pin);

    if(login(username, pin) == 1){
        printf("\nWelcome, %s!\n", username);

        while(1){
            printf("\n--- MENU ---\n");
            printf("1. Check Balance\n");
            printf("2. Deposit\n");
            printf("3. Withdraw\n");
            printf("4. Exit\n");
            printf("Choose option: ");
            scanf("%d", &choice);

            if(choice == 1){
                checkBalance();
            }else if(choice == 2){
                deposit();
            }else if(choice == 3){
                withdraw();
            }else if(choice == 4){
                printf("Thank you, %s. Goodbye!\n", username);
                break;
            }else{
                printf("Invalid option!\n");
            }
        }
    }else{
        printf("Wrong username or pin, please try again\n");
    }
    return 0;
}
