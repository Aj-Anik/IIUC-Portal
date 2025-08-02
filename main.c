#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define t_std 500

// Global Variable:
int n , s;
char fname[100];
char lname[100];
char id[100];
char pass[20];
char file_id[100], file_pass[100];

//Functions
void loginT();
void regis();
void login();
void OptT();
void stdt();

//Structure
struct student
{
    char fname[100];
    char lname[100];
    char id[100];
    char pass[20];
};

// Function Shuru 

void regis()
{
    printf("----Welcome To IIUC Student Portal Registration Page----\n\n");
    FILE *log;
    printf("\n=== Registration ===\n");
    printf("Enter Your First Name\n");
    fgets(fname, sizeof(fname), stdin);
    fname[strcspn(fname, "\n")] = 0;
    printf("Enter Your Last Name\n");
    fgets(lname, sizeof(lname), stdin);
    lname[strcspn(lname, "\n")] = 0;
    printf("Enter Your ID Name\n");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = 0;
    printf("Enter Your Password \n");
    fgets(pass, sizeof(pass), stdin);
    pass[strcspn(pass, "\n")] = 0;
    log = fopen("userinfo.txt", "a");
    fprintf(log, "%s %s %s %s\n", fname, lname, id, pass);
    fclose(log);
    printf("\nRegistration successful!\n\n");
    printf("Your Username : %s\n", id);
    printf("Your Password : %s\n\n", pass);
    printf("To Login press 2\n");
    scanf("%d", &n);
    if (n == 2)
    {
        login();
    }
}
void login()
{
    system("cls");
here:
    printf("----Welcome To IIUC Student Portal Login Page----\n\n");
    printf("\n=== Login ===\n");
    printf("Enter username: ");
    scanf("%s", id);
    printf("Enter password: ");
    scanf("%s", pass);


    FILE *log;
    log = fopen("userinfo.txt", "r");
    if (log == NULL)
    {
        printf("Error opening file or no registered users.\n");
        return;
    }
    int found = 0;
    while (fscanf(log, "%s %s", file_id, file_pass) != EOF)
    {
        if (strcmp(id, file_id) == 0 && strcmp(pass, file_pass) == 0)
        {
            found = 1;
            break;
        }
    }
    fclose(log);
    if (found)
    {
        system("cls");
        printf("Login successful! Welcome, %s\n\n\n\n", id);
        stdt(id);
    }
    else
    {
        printf("Login failed. Invalid username or password.\n");
        goto here;
    }
}
void loginT()
{
    int T = 0;
here:
    printf("Enter username: ");
    scanf("%s", id);
    printf("Enter password: ");
    scanf("%s", pass);
    FILE *ln;
    ln = fopen("teacherinfo.txt", "r");
    if (ln == NULL)
    {
        printf("Error opening file or no registered users.\n");
        return;
    }
    int found = 0;
    while (fscanf(ln, "%s %s", file_id, file_pass) != EOF)
    {
        if (strcmp(id, file_id) == 0 && strcmp(pass, file_pass) == 0)
        {
            found = 1;
            break;
        }
    }
    fclose(ln);
    if (found)
    {
        T = 1;
        printf("Login successful! Welcome, %s\n", id);
    }
    else
    {
        printf("Login failed. Invalid username or password.\n");
        goto here;
    }
    if (T == 1)
    {
        OptT();
    }
}
void OptT()
{
    FILE *not;
    if (not == NULL)
    {
        not = fopen("notice.txt", "w");
    }
    int T1;
    char notice[100];
    printf("1.Notice\n");
    printf("2.Room Checker\n");
    printf("3.Routine\n");
    scanf("%d", &T1);
    if(T1 == 1)
    {
        printf("Write a Short Notice \n\n");
        gets(notice);

        not = fopen("notice.txt", "a");

        fprintf(not, "%c", notice);
    }
}
void stdt(int i)
{
    printf("\nWelcome %s\n",i);
    printf("Section : 1BM \n");
    printf("Semester : 1st\n\n\n\n");
    printf("1.Routine\n");
    printf("2.Registrated Subject\n");
    printf("3.Notice[Teacher]\n");
    printf("4.Advisor Info\n");
    printf("5.Teacher's List\n");
    
    now:
    printf("Choose From 1-5 : ");
    scanf("%d",&s);
    if(s<1 || s > 5)
    {
        system("cls");
        printf("Wrong Input .....\nTry Again\n");
        goto now;
    }
    if(s == 1)
    {
        printf("Routine:\n");
    }
    if(s == 2)
    {
        printf("Registrated Subjects:\n\n");
        printf("Registrated Subjects:\n\n");
    }

}
// Main Function

int main()
{
    printf("**Press 1 for Registration(Student)**\n");
    printf("**Press 2 for Login(Student)**\n");
    printf("**Press 3 for Login(Teacher)**\n");
    printf("**Press 4 for Exit**\n");

    struct student a[t_std];
    
    FILE *log;
    if (log == 0)
    {
        fopen("userinfo.txt", "w");
    }
    fflush(stdin); // Clear input buffer before taking input
    scanf("%d", &n);
    getchar(); // Consume the newline left by scanf
    if (n == 1)
    {
        regis();
    }
    if (n == 2)
    {
        login();
    }
    if (n == 3)
    {
        loginT();
    }
    if (n == 4)
    {
        system("cls");
        printf("Exiting............");
        return 0;
    }

    return 0;
}
