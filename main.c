#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void room_check()
{
    FILE *fp;
    char line[555];
    char room[50];
    int period;

    // Ask user input
    printf("Enter period number (1-6): ");
    scanf("%d", &period);
    printf("Enter room name (e.g., C105): ");
    scanf("%s", room);

    // Open routine file
    fp = fopen("routine.txt", "r");
    if (!fp)
    {#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define t_std 500
// the regis code need for registration for the teachers
#define Regcode "IIUC95Auth"

// Global Variables:
int n, s;
int z;
char sub[100];
char Tid[100];
char Tname[100];
char Tpass[100];
char fname[100];
char id[100];
char pass[20];
char regT[20];
char file_id[100], file_pass[100];

// Functions

void std_marks();
void cgpa();
float convertMarksToGPA(int marks);
void class_check();
void loginT();
void regis();
void login();
void OptT();
void stdt();
void teacher_reg();
void room_check();


// Structure
struct student
{
    char fname[100];
    char id[100];
    char pass[20];
};


int main()
{
    system("cls");
    printf("\033[1;32mINTERNATIONAL ISLAMIC UNIVERSITY CHITTAGONG\033[0m\n\n\n");
    printf("**Press 1 for Registration(Student)**\n");
    printf("**Press 2 for Login(Student)**\n");
    printf("**Press 3 for Login(Teacher)**\n");
    printf("**Press 4 for Registration(Teacher)**\n");
    printf("**Press 5 for (Exit)**\n");

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
        teacher_reg();
    }
    if (n == 5)
    {
        system("cls");
        printf("Exiting............");
        return 0;
    }

    return 0;
}
// Function Shuru

void regis()
{
    system("cls");
    printf("----Welcome To IIUC Student Portal Registration Page----\n\n");
    FILE *log;

    printf("\n=== Registration ===\n");
    printf("Enter Your Full Name\n");
    fgets(fname, sizeof(fname), stdin);
    fname[strcspn(fname, "\n")] = 0;
    printf("Enter Your ID\n");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = 0;
    printf("Enter Your Password \n");
    fgets(pass, sizeof(pass), stdin);
    pass[strcspn(pass, "\n")] = 0;

    log = fopen("userinfo.txt", "a");
    fprintf(log, "%s %s\n", id, pass);
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
        stdt();
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
    system("cls");
    FILE *not;
    if (not == NULL)
    {
        not = fopen("notice.txt", "w");
    }
    int T1;
    char notice[100];
yes:
    printf("1.Room Availability\n");
    printf("2.Class Checker\n");
    printf("3.Weekly Test Marks\n");
    printf("4.LogOut\n");
    printf("Choose From 1-3 : ");
    scanf("%d", &T1);
    if (T1 < 1 || T1 > 4)
    {
        system("cls");
        printf("Wrong Input .....\nTry Again\n");
        goto yes;
    }
    if (T1 == 1)
    {
        system("cls");
        room_check();
        printf("Press 1 to back\n");
    P:
        scanf("%d", &z);
        if (z == 1)
        {
            system("cls");
            goto yes;
        }
        else
        {
            system("cls");
            printf("Invalid Input \nTry Again : ");
            goto P;
        }
    }
    if (T1 == 2)
    {
        system("cls");
        class_check();

        printf("Press 1 to back\n");
        scanf("%d", &z);
        if (z == 1)
        {
            system("cls");
            goto yes;
        }
        else
        {
            printf("Invalid Input \nTry Again : ");
            goto P;
        }
    }
    if (T1 == 4)
    {
        main();
    }
    if (T1 == 3)
    {
        std_marks();
    }
}
void stdt()
{
    system("cls");
    //printf("\nWelcome %s\n", i);
    printf("Semester : 1st\n\n\n");
no:
    printf("1.Room Check\n");
    printf("2.Class Check\n");
    printf("3.Registrated Subject\n");
    printf("4.Teacher's List\n");
    printf("5.CGPA Calculator\n");
    printf("6.Weekly Result\n");
    printf("7.LogOut\n\n");

    printf("Choose From 1-7 : ");
    scanf("%d", &s);
    if (s < 1 || s > 7)
    {
        system("cls");
        printf("Wrong Input .....\nTry Again\n");
        goto no;
    }
    if (s == 1)
    {
        system("cls");
        printf("Room Check :\n");
        room_check();

        printf("Press 1 to back\n");
    T:
        scanf("%d", &z);
        if (z == 1)
        {
            system("cls");
            goto no;
        }
        else
        {
            system("cls");
            printf("Invalid Input \nTry Again : ");
            goto T;
        }
    }
    if (s == 3)
    {
        system("cls");
        printf("   Credit Hour |Registrated Subjects:\n\n");
        printf("1.     3       |Computer Programming 1\n");
        printf("2.    1.5      |Computer Programming 1 Lab\n");
        printf("3.     3       |Basic Electrical Engineering\n");
        printf("4.    1.5      |Basic Electrical Engineering Lab\n");
        printf("5.     2       |Advanced English\n");
        printf("6.     1       |Text of Ethics and Morality \n");
        printf("7.     3       |Mathematics I (Differential and Integral Calculus)\n");
        printf("8.     3       |Physics I (Mechanics, Waves, Heat and Thermodynamics)\n\n");

        printf("Press 1 to back\n");
        scanf("%d", &z);
        if (z == 1)
        {
            system("cls");
            goto no;
        }
        else
        {
            system("cls");
            printf("Invalid Input \nTry Again : ");
            goto T;
        }
    }
    if (s == 4)
    {
        system("cls");
        printf("Teacher's Info :\n\n\n");
        printf("Teacher's Name   |         Email Address     |  Phone Number\n\n");
        printf("Jamil As-ad      | jamilasad1@gmail.com      |  01626890190\n");
        printf("Sahariar Reza    | Sahariarp@gmail.com       |  01521328094\n");
        printf("Md.Rashedul Islam| rashed_math@gmail.com     |  01717121186\n");
        printf("Kafil Uddin      | mdkafil_iiuc@gmail.com    |  01819101372\n");
        printf("Abdullah Al Mamun| mamun.phys@gmail.com      |  01521483685\n\n");
        printf("Press 1 to back\n");
        scanf("%d", &z);
        if (z == 1)
        {
            system("cls");
            goto no;
        }
        else
        {
            printf("Invalid Input \nTry Again : %d", &z);
            goto T;
        }
    }
    if (s == 2)
    {
        system("cls");
        class_check();
        printf("Press 1 to back\n");
        scanf("%d", &z);
        if (z == 1)
        {
            system("cls");
            goto no;
        }
        else
        {
            printf("Invalid Input \nTry Again : %d", &z);
            goto T;
        }
    }
    if (s == 5)
    {
        cgpa();
        printf("Press 1 to back\n");
        scanf("%d", &z);
        if (z == 1)
        {
            system("cls");
            goto no;
        }
        else
        {
            system("cls");
            printf("Invalid Input \nTry Again : ");
            goto T;
        }
    }
    if (s == 7)
    {
        main();
    }
    if (s == 6)
    {
        system("cls");
        FILE *check;
        check = fopen("weeklymarks.txt", "r");
        if (check == NULL) {
            printf("No weekly marks recorded yet.\n");
        } else {
            char line[256];
            printf("\n--- Weekly Test Marks ---\n\n");
            while (fgets(line, sizeof(line), check)) {
                printf("%s", line);
            }
            fclose(check);
        }
        printf("\nPress 1 to back\n");
        scanf("%d", &z);
        if (z == 1) {
            system("cls");
            goto no;
        } else {
            system("cls");
            printf("Invalid Input \nTry Again : ");
            goto T;
        }
        
    }
}
void teacher_reg()
{
    system("cls");
    char chk[20];
    int pck = 3;
    strcpy(chk, Regcode);

    printf("Welcome to Registration\n\n");
pc:
    printf("Enter The 10 Digit Code Provided By the Authority to registration :\n");
    fgets(regT, sizeof(regT), stdin);
    regT[strcspn(regT, "\n")] = 0;
    if (strcmp(regT, chk) == 0)
    {
        printf("Verification Successful\nNow You can Proceed\n");
        system("cls");
        printf("----Welcome To Teacher Registration Page----\n\n");
        FILE *Tea;

        printf("\n=== Registration ===\n");
        printf("Enter Your Name\n");
        fgets(Tname, sizeof(Tname), stdin);
        Tname[strcspn(Tname, "\n")] = 0;
        printf("Enter Your ID Name\n");
        fgets(Tid, sizeof(Tid), stdin);
        Tid[strcspn(Tid, "\n")] = 0;
        printf("Enter Your Password \n");
        fgets(Tpass, sizeof(Tpass), stdin);
        Tpass[strcspn(Tpass, "\n")] = 0;

        Tea = fopen("teacherinfo.txt", "a");
        fprintf(Tea, "%s %s %s\n", Tname, Tid, Tpass);
        fclose(Tea);
        printf("\nRegistration successful!\n\n");
        printf("Your Username : %s\n", Tid);
        printf("Your Password : %s\n\n", Tpass);
    logt:
        printf("To Login press 2\n");
        scanf("%d", &n);
        if (n == 2)
        {
            loginT();
        }
        else
        {
            printf("Try Again\n\n");
            goto logt;
        }
    }
    else
    {
        pck--;
        system("cls");
        printf("You have %d chances\n", pck);

        if (pck == 0)
        {
            system("cls");
            printf("You Have Been Blocked\nContract In 'ACAD' ");

            return;
        }
        goto pc;
    }
}
void room_check()
{
    system("cls");
    FILE *fp;
    char line[555];
    char room[50];
    int period;
    int d;

    // Ask user input
    printf("Enter Day (1-5)\n");
    printf("1.Sat  2.Sun  3.Mon  4.Tues  5.Wed\n");
    scanf("%d", &d);
    printf("Enter period number (1-6): ");
    scanf("%d", &period);
    printf("Enter room name (e.g., C105): ");
    scanf("%s", room);

    // Days
    if (d == 1)
    {
        fp = fopen("saturday.txt", "r");
        if (!fp)
        {
            printf("Could not open routine file.\n");
        }
    }
    else if (d == 2)
    {
        fp = fopen("sunday.txt", "r");
        if (!fp)
        {
            printf("Could not open routine file.\n");
        }
    }
    else if (d == 3)
    {
        fp = fopen("monday.txt", "r");
        if (!fp)
        {
            printf("Could not open routine file.\n");
        }
    }
    else if (d == 4)
    {
        fp = fopen("tuesday.txt", "r");
        if (!fp)
        {
            printf("Could not open routine file.\n");
        }
    }
    else if (d == 5)
    {
        fp = fopen("wednesday.txt", "r");
        if (!fp)
        {
            printf("Could not open routine file.\n");
        }
    }

    // Skip header line
    fgets(line, sizeof(line), fp);

    int current = 0, found = 0;
    while (fgets(line, sizeof(line), fp))
    {
        current++;

        // If we are at the requested period
        if (current == period)
        {
            line[strcspn(line, "\n")] = 0; // Remove newline

            // Split using semicolon
            char *time = strtok(line, ";");
            char *am = strtok(NULL, ";");
            char *bm = strtok(NULL, ";");
            char *cm = strtok(NULL, ";");

            // Check if the room exists in this period
            if ((am && strstr(am, room)) || (bm && strstr(bm, room)) || (cm && strstr(cm, room)))
            {
                printf("\nRoom %s is OCCUPIED in period %d.\n", room, period);
                found = 1;
            }
            else
            {
                printf("\nRoom %s is EMPTY in period %d.\n", room, period);
            }
            break;
        }
    }

    fclose(fp);

    // Handle invalid period
    if (current < period)
    {
        printf("\nInvalid period number. No such row in the file.\n");
    }
}
void class_check()
{
    FILE *fp;
    char line[256];
    char section[10];
    int period;
    int d;

    // Ask user for input
    printf("Enter Day (1-5)\n");
    printf("1.Sat  2.Sun  3.Mon  4.Tues  5.Wed\n");
    scanf("%d", &d);
    printf("Enter your section (1AM/1BM/1CM): ");
    scanf("%s", section);
    printf("Enter period number (1-6): ");
    scanf("%d", &period);

    // Days
    if (d == 1)
    {
        fp = fopen("saturday.txt", "r");
        if (!fp)
        {
            printf("Could not open routine file.\n");
        }
    }
    else if (d == 2)
    {
        fp = fopen("sunday.txt", "r");
        if (!fp)
        {
            printf("Could not open routine file.\n");
        }
    }
    else if (d == 3)
    {
        fp = fopen("monday.txt", "r");
        if (!fp)
        {
            printf("Could not open routine file.\n");
        }
    }
    else if (d == 4)
    {
        fp = fopen("tuesday.txt", "r");
        if (!fp)
        {
            printf("Could not open routine file.\n");
        }
    }
    else if (d == 5)
    {
        fp = fopen("wednesday.txt", "r");
        if (!fp)
        {
            printf("Could not open routine file.\n");
        }
    }
    // Read header (ignore first line)
    fgets(line, sizeof(line), fp);

    int current = 0;
    while (fgets(line, sizeof(line), fp))
    {
        current++;
        if (current == period)
        {
            // Remove newline
            line[strcspn(line, "\n")] = 0;

            // Split CSV line
            char *token = strtok(line, ";");
            char *time = token;
            char *am = strtok(NULL, ";");
            char *bm = strtok(NULL, ";");
            char *cm = strtok(NULL, ";");

            printf("\nTime: %s\n", time);
            if (strcmp(section, "1AM") == 0)
                printf("Class: %s\n", am);
            else if (strcmp(section, "1BM") == 0)
                printf("Class: %s\n", bm);
            else if (strcmp(section, "1CM") == 0)
                printf("Class: %s\n", cm);
            else
                printf("Invalid section!\n");
            break;
        }
    }

    fclose(fp);
}
float convertMarksToGPA(int marks)
{
    if (marks >= 80)
        return 4.0;
    else if (marks >= 75)
        return 3.75;
    else if (marks >= 70)
        return 3.5;
    else if (marks >= 65)
        return 3.25;
    else if (marks >= 60)
        return 3.0;
    else if (marks >= 55)
        return 2.75;
    else if (marks >= 50)
        return 2.5;
    else if (marks >= 45)
        return 2.25;
    else if (marks >= 40)
        return 2.0;
    else
        return 0.0;
}
void cgpa()
{
    system("cls");
    int n;
    printf("Enter the number of subjects: ");
    scanf("%d", &n);

    getchar();
    char subjectName[n][50];
    float marks[n];
    float gpa[n], credits[n];

    float totalPoints = 0.0, totalCredits = 0.0;

    for (int i = 0; i < n; i++)
    {
        printf("\nSubject %d:\n", i + 1);

        printf("Subject Name: ");
        fgets(subjectName[i], sizeof(subjectName[i]), stdin);
        subjectName[i][strcspn(subjectName[i], "\n")] = '\0';

        printf("Enter credit for %s: ", subjectName[i]);
        scanf("%f", &credits[i]);

        printf("Enter marks for %s: ", subjectName[i]);
        scanf("%f", &marks[i]);
        getchar();

        gpa[i] = convertMarksToGPA(marks[i]);

        totalPoints += gpa[i] * credits[i];
        totalCredits += credits[i];
    }

    float cgpa = totalPoints / totalCredits;

    system("cls");
    printf("\n===== Result Summary =====\n");
    for (int i = 0; i < n; i++)
    {
        printf("Subject: %-20s | Credit: %.1f | Marks: %.0f | GPA: %.2f\n",
               subjectName[i], credits[i], marks[i], gpa[i]);
    }

    printf("\nTotal Credits: %.2f", totalCredits);
    printf("\nTotal Grade Points: %.2f", totalPoints);
    printf("\nCGPA: %.2f\n\n", cgpa);
}
void std_marks()
{
    system("cls");
    int S;
    FILE *mark;
    mark = fopen("weeklymarks.txt", "a");
    if (!mark)
    {
        printf("Error opening weeklymarks.txt for writing.\n");
        return;
    }
    getchar(); // Clear input buffer
    char date[100];
    printf("Enter Date(MM-DD-YY): ");
    fgets(date, sizeof(date), stdin);
    date[strcspn(date, "\n")] = 0;
    printf("Enter The Subject Name: ");
    fgets(sub, sizeof(sub), stdin);
    sub[strcspn(sub, "\n")] = 0;

    printf("\nEnter The Total Present Students: ");
    scanf("%d", &S);
    getchar(); // Clear input buffer
    fprintf(mark, "EXAM DATE : %s \nEXAM NAME : %s   Student(Participated): %d\n\n",date, sub, S);
    int arr[S];
    for (int i = 0; i < S; i++)
    {
        char studentid[10];
        int marks;
        printf("Enter Student %d ID: ", i + 1);
        fgets(studentid, sizeof(studentid), stdin);
        studentid[strcspn(studentid, "\n")] = 0;
        printf("Enter marks for %s: ", studentid);
        scanf("%d", &marks);
        getchar(); // Clear input buffer
        arr[i] = marks;
        fprintf(mark, "Student: %s, Marks: %d\n\n\n", studentid, marks);
    }
    fclose(mark);
    printf("\nWeekly test marks recorded successfully!\n");
}

    }

    // Skip header line
    fgets(line, sizeof(line), fp);

    int current = 0, found = 0;
    while (fgets(line, sizeof(line), fp))
    {
        current++;

        // If we are at the requested period
        if (current == period)
        {
            line[strcspn(line, "\n")] = 0; // Remove newline

            // Split using semicolon
            char *time = strtok(line, ";");
            char *am = strtok(NULL, ";");
            char *bm = strtok(NULL, ";");
            char *cm = strtok(NULL, ";");

            // Check if the room exists in this period
            if ((am && strstr(am, room)) || (bm && strstr(bm, room)) || (cm && strstr(cm, room)))
            {
                printf("\nRoom %s is OCCUPIED in period %d.\n", room, period);
                found = 1;
            }
            else
            {
                printf("\nRoom %s is EMPTY in period %d.\n", room, period);
            }
            break;
        }
    }

    fclose(fp);

    // Handle invalid period
    if (current < period)
    {
        printf("\nInvalid period number. No such row in the file.\n");
    }

}

void class_check()
{
    FILE *fp;
    char line[256];
    char section[10];
    int period;

    // Ask user for input
    printf("Enter your section (1AM/1BM/1CM): ");
    scanf("%s", section);
    printf("Enter period number (1-6): ");
    scanf("%d", &period);

    // Open routine file
    fp = fopen("routine.txt", "r");
    if (!fp)
    {
        printf("Could not open routine file.\n");
    }

    // Read header (ignore first line)
    fgets(line, sizeof(line), fp);

    int current = 0;
    while (fgets(line, sizeof(line), fp))
    {
        current++;
        if (current == period)
        {
            // Remove newline
            line[strcspn(line, "\n")] = 0;

            // Split CSV line
            char *token = strtok(line, ";");
            char *time = token;
            char *am = strtok(NULL, ";");
            char *bm = strtok(NULL, ";");
            char *cm = strtok(NULL, ";");

            printf("\nTime: %s\n", time);
            if (strcmp(section, "1AM") == 0)
                printf("Class: %s\n", am);
            else if (strcmp(section, "1BM") == 0)
                printf("Class: %s\n", bm);
            else if (strcmp(section, "1CM") == 0)
                printf("Class: %s\n", cm);
            else
                printf("Invalid section!\n");
            break;
        }
    }

    fclose(fp);
}

int main()
{
    printf("\\\\choose the option\\\\\n\n");

    printf("\\\\1. Student Login...\n");
    printf("\\\\2. Teacher Login...\n");
    printf("\\\\3. Student Registration...\n");

    int opt;
    scanf("%d", &opt);

    if (opt > 3 || opt < 1)
    {
        printf("choose between 1-3\n\n");
    }
    else if (opt == 1)
    {
        printf("student page\n");

        printf("1. Class check\n");
        printf("2. Room check\n");

        int opts;
        scanf("%d", &opts);

        if (opts > 2 || opts < 1)
        {
            printf("choose between 1-2\n\n");
        }
        else if (opts == 1) // class check
        {
            class_check();
        }
        else if (opts == 2) // Room check
        {
            room_check();
        }
    }
    else if (opt == 2)
    {
        printf("Teacher page\n");

        printf("1. Room check\n");

        int optt;

        scanf("%d", &optt);

        if (optt == 1)
        {
            room_check();
        }
        
    }
    else if (opt == 3)
    {
        FILE *fp = fopen("student_info.txt", "r");

        if (!fp)
    {
        printf("Could not open routine file.\n");
    }
    
    }
    
    return 0;
}
