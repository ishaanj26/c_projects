/*
AUTHENTICATION PAGE
Code improved by Ishaan Jain
you can Copy and Learn
*/


#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void divider()
{
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }
}

int menu()
{
    int c;
    printf("\n******************MAIN MENU******************\n");
    printf("1. SIGNUP\n");
    printf("2. LOGIN\n");
    printf("3. FORGOT PASSWORD or USERNAME\n");
    printf("4. CHANGE PASSWORD\n");
    printf("5. DELETE ACCOUNT\n");
    printf("6. EXIT\n");
    divider();
    printf("\nEnter your choice:");
    scanf("%d", &c);
    return c;
}

struct account
{
    char first_name[20];
    char last_name[20];
    char username[30];
    char phone_number[15];
    char gender;
    char DOB[10];
    char pass1[20];
};

void signup();
void takePassword(char pass[20]);
void login();
void forgot();
void changePassword();
void deleteAccount();

int main()
{
    while (1)
    {
        system("cls");
        switch (menu())
        {
        case 1:
            signup();
            break;
        case 2:
            login();
            break;
        case 3:
            forgot();
            break;
        case 4:
            changePassword();
            break;
        case 5:
            deleteAccount();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid Option\n");
            break;
        }
    }

    return 0;
}

void signup()
{
    system("cls");
    struct account a1;
    char pass2[20];
    printf("CREATING NEW ACCOUNT\n");
    divider();
    printf("\nEnter your first name\n");
    scanf("%s", &a1.first_name);
    printf("Enter your last name\n");
    scanf("%s", &a1.last_name);
    printf("Enter your username\n");
    scanf("%s", &a1.username);
    printf("Enter your Phone Number\n");
    scanf("%s", &a1.phone_number);
    fflush(stdin); // used when string scanned before char
    printf("Enter your Gender\n");
    scanf("%c", &a1.gender);
    printf("Enter your Date of Birth\n");
    scanf("%s", &a1.DOB);
    printf("Enter your Password\n");
    takePassword(a1.pass1);
conf_pass:
    printf("\nConfirm your password\n");
    scanf("%s", &pass2);
    if (strcmp(a1.pass1, pass2))
    {
        printf("Password inValid. Try Again\n");
        goto conf_pass;
    }
    else
    {
        printf("Password Valid.\n");
        getch();
        FILE *fp = fopen("account.txt", "w");
        fwrite(&a1, sizeof(struct account), 1, fp);
        fclose(fp);
    }
}

void takePassword(char pass[20])
{
    int i = 0;
    char ch;
    while (1)
    {
        ch = getch();
        if (ch == 13) // 13 means enter
        {
            pass[i] = '\0';
            break;
        }
        else if (ch == 8)
        { // 8means backspace
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else if (ch == 9 || ch == 32)
        { // 9means tab and 32 means space
            continue;
        }
        else
        {
            pass[i] = ch;
            printf("*");
            i++;
        }
    }
};

void login()
{
    system("cls");
    char user[30];
    char log_pass[20];
    struct account a1;
    FILE *fp = fopen("account.txt", "r");
    fread(&a1, sizeof(struct account), 1, fp);
name:
    printf("Enter Username\n");
    scanf("%s", user);
    if (strcmp(a1.username, user))
    {
        printf("Please enter correct Username\n");
        goto name;
    }
    else
    {
    password:
        printf("Please enter Password\n");
        takePassword(log_pass);
        if (strcmp(a1.pass1, log_pass))
        {
            printf("\nThe password is wrong \n");
            goto password;
        }
        else
        {
            system("cls");
            printf("\n************WELCOME %s************\n", a1.first_name);
            divider();
            printf("\nYour Details \n");
            divider();
            printf("\nUsername     : %s\n", a1.username);
            printf("first name   : %s\n", a1.first_name);
            printf("Last name    : %s\n", a1.last_name);
            printf("phone number : %s\n", a1.phone_number);
            printf("Gender       : %c\n", a1.gender);
            printf("Password     : %s\n", a1.pass1);
        }
        fclose(fp);
        getch();
    }
}

void forgot()
{
    system("cls");
    char user[30];
    char pass2[20];
    char phone2[20];
    int choice;
    struct account a1;
    FILE *ptr = fopen("account.txt", "r");
    fread(&a1, sizeof(struct account), 1, ptr);
    printf("Searching Account\n");
    divider();
choice:
    printf("\n 1. Search by username");
    printf("\n 2. Search by password");
    printf("\n 3. Search by PhoneNumber");
    printf("\n 4. Return to Main Menu");
    divider();
    printf("\nEnter the choice\n");
    scanf("%d", &choice);
    system("cls");
    if (choice == 1)
    {
        printf("Enter the username\n");
        scanf("%s", user);
        if (strcmp(a1.username, user))
        {
            printf("You have enter the wrong username");
            goto choice;
        }
        else
        {
            printf("ACCOUNT FOUND!!!!! \n");
            printf("Your Details \n");
            printf("\nUsername     : %s\n", a1.username);
            printf("first name   : %s\n", a1.first_name);
            printf("Last name    : %s\n", a1.last_name);
            printf("phone number : %s\n", a1.phone_number);
            printf("Gender       : %c\n", a1.gender);
            printf("Password     : %s\n", a1.pass1);
            getch();
        }
    }
    else if (choice == 2)
    {
        printf("Enter the password\n");
        scanf("%s", pass2);
        if (strcmp(a1.pass1, pass2))
        {
            printf("You have enter the wrong password\n");
            goto choice;
        }
        else
        {
            printf("ACCOUNT FOUND!!!!! \n");
            printf("\nYour Details \n");
            printf("\nUsername     : %s\n", a1.username);
            printf("first name   : %s\n", a1.first_name);
            printf("Last name    : %s\n", a1.last_name);
            printf("phone number : %s\n", a1.phone_number);
            printf("Gender       : %c\n", a1.gender);
            printf("Password     : %s\n", a1.pass1);
            getch();
        }
    }
    else if (choice == 3)
    {
        printf("Enter the phoneNumber\n");
        scanf("%s", phone2);
        if (strcmp(a1.phone_number, phone2))
        {
            printf("You have enter the wrong phoneNumber\n");
            goto choice;
        }
        else
        {
            system("cls");
            printf("ACCOUNT FOUND!!!!! \n");
            printf("\nYour Details \n");
            printf("\nUsername     : %s\n", a1.username);
            printf("first name   : %s\n", a1.first_name);
            printf("Last name    : %s\n", a1.last_name);
            printf("phone number : %s\n", a1.phone_number);
            printf("Gender       : %c\n", a1.gender);
            printf("Password     : %s\n", a1.pass1);
            getch();
        }
    }
    else if (choice == 4)
    {
        return;
    }

    else
    {
        printf("You have entered a wrong choice");
        goto choice;
    }
    fclose(ptr);
}

void changePassword()
{
    system("cls");
    srand(time(0));
    int number1 = rand();
    int number2;
    char pass2[20];
number:
    printf("Random Number: %d \n", number1);
    printf("Enter the Number:\n");
    scanf("%d", &number2);
    if (number1 == number2)
    {
        struct account a1;
        FILE *fp = fopen("account.txt", "w");
        fread(&a1, sizeof(struct account), 1, fp);
        divider();
        printf("\nEnter new password\n");
        takePassword(a1.pass1);
    confirm:
        printf("\nConfirm Password\n");
        scanf("%s", pass2);
            divider();
        if (strcmp(pass2, a1.pass1))
        {
            printf("Passowrd Invalid.Try Aagin\n");
            goto confirm;
        }
        else
        {
            fp = fopen("account.txt", "w");
            fwrite(&a1, sizeof(struct account), 1, fp);
            printf("**************Password Changed Successfully**************\n");
            getch();
        }
        fclose(fp);
    }
    else
    {
        printf("You have entred the wrong Code. Please enter the correct code\n");
        goto number;
    }
}

void deleteAccount()
{
    system("cls");
    FILE *fp = fopen("account.txt", "r");
    char c = fgetc(fp);
    if (c == EOF)
    {
        printf("NO ACCOUNT TO DELETE\n");
        getch();
        return;
    }
    else
    {
        printf("ARE YOU SURE YOU WANT TO DELETE YOUR ACCOUNT (Y/N)\n");
        char c = getche();
        if (c == 'y' || c == 'Y')
        {
            fp = fopen("account.txt", "w");
            fprintf(fp, " ");
            printf("\nThe account is deleted\n");
            getch();
        }
        else if (c == 'n' || c == 'N')
        {
            printf("\nThe account is not deleted\n");
            getch();
        }
        else
        {
            printf("\n Wrong Input\n");
            getch();
            return;
        }
    }
}