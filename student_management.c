#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct info
{
    char fname[50];
    char lname[50];
    int roll;
    float cgpa;
    int cid[10];
} st[55];

void addStudent();
void find_rl();
void find_fn();
void total_students();
void del_s();
void up_s();

int no_of_students = 0;
int main()
{
    int choice;
    while (1)
    {
        printf("The Task that you want to perform\n");
        printf("1. Add the Student Details\n");
        printf("2. Find the Student Details by Roll Number\n");
        printf("3. Find the Student Details by First Name\n");
        printf("4. Find the Total number of Students\n");
        printf("5. Delete the Students Details by Roll Number\n");
        printf("6. Update the Students Details by Roll Number\n");
        printf("7. To Exit\n");
        printf("Enter your choice to find the task\n");
        scanf("%d", &choice);
        system("cls");
        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            find_rl();
            break;
        case 3:
            find_fn();
            break;
        case 4:
            total_students();
            break;
        case 5:
            del_s();
            break;
        case 6:
            up_s();
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Invalid Input\n");
        }
    }
    return 0;
}

void addStudent()
{
    printf("Add the Students Details\n");
    printf("-------------------------\n");
    printf("Enter the first name of student\n");
    scanf("%s", st[no_of_students].fname);
    printf("Enter the last name of student\n");
    scanf("%s", st[no_of_students].lname);
    printf("Enter the Roll Number\n");
    scanf("%d", &st[no_of_students].roll);
    printf("Enter the CGPA you obtained\n");
    scanf("%f", &st[no_of_students].cgpa);
    printf("Enter the course ID of each course\n");
    for (int j = 0; j < 5; j++)
    {
        scanf("%d", &st[no_of_students].cid[j]);
    }
    no_of_students = no_of_students + 1;
}

void find_rl()
{
    int roll_no;
    printf("Enter the Roll Number of the student\n");
    scanf("%d", &roll_no);
    for (int i = 0; i < no_of_students; i++)
    {
        if (roll_no == st[i].roll)
        {
            printf("The Students Details are\n");
            printf("The First name is %s\n", st[i].fname);
            printf("The Last name is %s\n", st[i].lname);
            printf("The CGPA is %.3f\n", st[i].cgpa);
            printf("Enter the course ID of each course\n");
            for (int j = 0; j < 5; j++)
            {
                printf("The course ID are %d\n", st[i].cid[j]);
            }
            printf("\n\n");
            break;
        }
    }
}

void find_fn()
{
    char a[50];
    printf("Enter the First Name of the student\n");
    scanf("%s", &a);
    for (int i = 0; i < no_of_students; i++)
    {
        if (!strcmp(a, st[i].fname))
        {
            printf("The Students Details are\n");
            printf("The First name is %s\n", st[i].fname);
            printf("The Last name is %s\n", st[i].lname);
            printf("The CGPA is %.3f\n", st[i].cgpa);
            printf("Enter the course ID of each course\n");
            for (int j = 0; j < 5; j++)
            {
                printf("The course ID are %d\n", st[i].cid[j]);
            }
            printf("\n\n");
        }
    }
}

void total_students()
{
    printf("The total number of Student is %d\n", no_of_students);
    printf("\n you can have a max of 50 students\n");
    printf("you can have %d more students\n", 50 - no_of_students);
}

void del_s()
{
    int a;
    printf("Enter the Roll Number which you want to delete\n");
    scanf("%d", &a);
    for (int j = 0; j < no_of_students; j++)
    {
        if (a == st[j].roll)
        {
            for (int k = j; k < 49; k++)
            {
                st[k] = st[k + 1];
            }
            no_of_students--;
            printf("The Roll Number is removed Successfully\n");
        }
    }
}

void up_s()
{
    printf("Enter the roll number to update the entry : ");
    int x;
    scanf("%ld", &x);
    for (int j = 0; j < no_of_students; j++)
    {
        if (st[j].roll == x)
        {
            printf("1. first name\n"
                   "2. last name\n"
                   "3. roll no.\n"
                   "4. CGPA\n"
                   "5. courses\n");
            int z;
            scanf("%d", &z);
            switch (z)
            {
            case 1:
                printf("Enter the new first name : \n");
                scanf("%s", st[j].fname);
                break;
            case 2:
                printf("Enter the new last name : \n");
                scanf("%s", st[j].lname);
                break;
            case 3:
                printf("Enter the new roll number : \n");
                scanf("%d", &st[j].roll);
                break;
            case 4:
                printf("Enter the new CGPA : \n");
                scanf("%f", &st[j].cgpa);
                break;
            case 5:
                printf("Enter the new courses \n");
                scanf(
                    "%d%d%d%d%d", &st[j].cid[0],
                    &st[j].cid[1], &st[j].cid[2],
                    &st[j].cid[3], &st[j].cid[4]);
                break;
            }
            printf("UPDATED SUCCESSFULLY.\n");
        }
    }
}