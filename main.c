#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define t_std 500

// Global Variable:
int n , s;
int z;
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
    system("cls");
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
    
    printf("----Welcome To IIUC Student Portal Login Page----\n\n");
    here:
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
        system("cls");
        printf("Login failed. Invalid username or password.\n");
        goto here;
    }
}
void loginT()
{
    system("cls");
    printf("----Welcome to Teacher's Login----\n\n");
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
    no:
    printf("1.Routine\n");
    printf("2.Registrated Subject\n");
    printf("3.Notice[Teacher]\n");
    printf("4.Teacher's List\n");
    
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

        printf("Press 1 to back\n");
        T:
        scanf("%d",&z);
        if(z == 1)
        {
            system("cls");
            goto no;
        }
        else{
            system("cls");
            printf("Invalid Input \nTry Again : ");
            goto T;
        }
    }
    if(s == 2)
    {
        printf("   Credit Hour |Registrated Subjects:\n\n");
        printf("1.     3       |Computer Programming 1\n");
        printf("2.    1.5      |Computer Programming 1 Lab\n");
        printf("3.     3       |Basic Electrical Engineering\n");
        printf("4.    1.5      |Basic Electrical Engineering Lab\n");
        printf("5.     2       |Advanced English\n");
        printf("6.     1       |Text of Ethics and Morality \n");
        printf("7.     3       |Mathematics I (Differential and Integral Calculus)\n");
        printf("8.     3       |Physics I (Mechanics, Waves, Heat and Thermodynamics)\n");
        
        printf("Press 1 to back\n");
        scanf("%d",&z);
        if(z == 1)
        {
            system("cls");
            goto no;
        }
        else{
            printf("Invalid Input \nTry Again : ");
            goto T;
        }
    }
    if(s == 3)
    {
        printf("Notice From Teacher : \n");
        printf("Press 1 to back\n");
        scanf("%d",&z);
        if(z == 1)
        {
            system("cls");
            goto no;
        }
        else{
            printf("Invalid Input \nTry Again : ");
            goto T;
        }
    }
    if(s == 4)
    {
        printf("Teacher's Info :\n\n\n");
        printf("Teacher's Name   |         Email Address     |  Phone Number\n\n");
        printf("Jamil As-ad      | jamilasad1@gmail.com      |  01626890190\n");
        printf("Sahariar Reza    | Sahariarp@gmail.com       |  01521328094\n");
        printf("Md.Rashedul Islam| rashed_math@gmail.com     |  01717121186\n");
        printf("Kafil Uddin      | mdkafil_iiuc@gmail.com    |  01819101372\n");
        printf("Abdullah Al Mamun| mamun.phys@gmail.com      |  01521483685\n");
        printf("Press 1 to back\n");
        scanf("%d",&z);
        if(z == 1)
        {
            system("cls");
            goto no;
        }
        else{
            printf("Invalid Input \nTry Again : %d",&z);
            goto T;
        }
        
    }

}


// Main Function

int main()
{
    printf("**Press 1 for Registration(Student)**\n");
    printf("**Press 2 for Login(Student)**\n");
    printf("**Press 3 for Login(Teacher)**\n");
    printf("**Press 4 for (Exit)**\n");

    struct student a[t_std];
    
    FILE *log;
    if (log == 0)
    {
        fopen("userinfo.txt", "w");
    }
    fflush(stdin); 
    scanf("%d", &n);
    getchar(); 
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
