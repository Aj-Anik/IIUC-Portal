#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define t_std 500
// the regis code (Dont hack it :))
#define Regcode "IIUC95Auth"

// colors
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

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

// Function to get current date and day
void getCurrentDateTime(char *dateStr, char *dayStr) {
    time_t now;
    struct tm *timeinfo;
    
    time(&now);
    timeinfo = localtime(&now);
    
    // Format date as DD-MM-YY
    strftime(dateStr, 50, "%d-%m-%y", timeinfo);
    
    // Get day name
    strftime(dayStr, 20, "%A", timeinfo);
}

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
    printf(BOLD GREEN "===================================================\n" RESET);
    printf(BOLD YELLOW "   INTERNATIONAL ISLAMIC UNIVERSITY CHITTAGONG\n" RESET);
    printf(BOLD GREEN "===================================================\n" RESET);

    time_t t;
    struct tm *tm_info;
    char buffer[50];

    time(&t);
    tm_info = localtime(&t);

    // Format: e.g., "Thursday, 07 August 2025"
    strftime(buffer, sizeof(buffer), "%A, %d %B %Y", tm_info);

    // Optional color for date header
    printf("\033[1;34m%s\033[0m\n\n", buffer);

    printf(BLUE "** Press 1 for " RESET CYAN "Registration (Student)\n" RESET);
    printf(BLUE "** Press 2 for " RESET CYAN "Login (Student)\n" RESET);
    printf(BLUE "** Press 3 for " RESET CYAN "Login (Teacher)\n" RESET);
    printf(BLUE "** Press 4 for " RESET CYAN "Registration (Teacher)\n" RESET);
    printf(RED "** Press 5 to " RESET BOLD RED "Exit\n\n" RESET);

    printf(GREEN "Enter your choice: " RESET);
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
    printf(BOLD CYAN "----Welcome To IIUC Student Portal Registration Page----\n\n" RESET);
    FILE *log;

    printf(BOLD GREEN "\n=== Registration ===\n" RESET);
    printf(YELLOW "Enter Your Full Name\n" RESET);
    fgets(fname, sizeof(fname), stdin);
    fname[strcspn(fname, "\n")] = 0;
    printf(YELLOW "Enter Your ID\n" RESET);
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = 0;
    printf(YELLOW "Enter Your Password \n" RESET);
    fgets(pass, sizeof(pass), stdin);
    pass[strcspn(pass, "\n")] = 0;

    log = fopen("userinfo.txt", "a");
    fprintf(log, "%s %s\n", id, pass);
    fclose(log);
    printf(BOLD GREEN "\nRegistration successful!\n\n" RESET);
    printf(CYAN "Your Username : " RESET BOLD "%s\n" RESET, id);
    printf(CYAN "Your Password : " RESET BOLD "%s\n\n" RESET, pass);
    printf(BLUE "To Login press 2\n" RESET);
    scanf("%d", &n);
    if (n == 2)
    {
        login();
    }
}
void login()
{
    system("cls");

    printf(BOLD CYAN "----Welcome To IIUC Student Portal Login Page----\n\n" RESET);
here:
    printf(BOLD GREEN "\n=== Login ===\n" RESET);
    printf(YELLOW "Enter username: " RESET);
    scanf("%s", id);
    printf(YELLOW "Enter password: " RESET);
    scanf("%s", pass);

    FILE *log;
    log = fopen("userinfo.txt", "r");
    if (log == NULL)
    {
        printf(RED "Error opening file or no registered users.\n" RESET);
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
        printf(BOLD GREEN "Login successful! Welcome, " RESET BOLD CYAN "%s\n\n\n\n" RESET, id);
        stdt();
    }
    else
    {
        system("cls");
        printf(BOLD RED "Login failed. Invalid username or password.\n" RESET);
        goto here;
    }
}
void loginT()
{
    system("cls");
    printf(BOLD MAGENTA "----Welcome to Teacher's Login----\n\n" RESET);
    int T = 0;
here:
    printf(YELLOW "Enter username: " RESET);
    scanf("%s", id);
    printf(YELLOW "Enter password: " RESET);
    scanf("%s", pass);
    FILE *ln;
    ln = fopen("teacherinfo.txt", "r");
    if (ln == NULL)
    {
        printf(RED "Error opening file or no registered users.\n" RESET);
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

        printf(BOLD GREEN "Login successful! Welcome, " RESET BOLD MAGENTA "%s\n" RESET, id);
    }
    else
    {
        printf(BOLD RED "Login failed. Invalid username or password.\n" RESET);
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
    printf(CYAN "Logging in" RESET);
    for (int i = 0; i < 3; i++)
    {
        printf(CYAN "." RESET);
        fflush(stdout);
        sleep(1);
    }
    printf("\n");
    system("cls");
    int T1;
yes:
    printf(BLUE "1." RESET CYAN "Room Availability\n" RESET);
    printf(BLUE "2." RESET CYAN "Class Checker\n" RESET);
    printf(BLUE "3." RESET CYAN "Weekly Test Marks\n" RESET);
    printf(BLUE "4." RESET CYAN "Write Notice\n" RESET);
    printf(RED "5." RESET BOLD RED "LogOut\n" RESET);

    printf(GREEN "Choose From 1-5 : " RESET);
    scanf("%d", &T1);
    if (T1 < 1 || T1 > 5)
    {
        system("cls");
        printf(RED "Wrong Input .....\nTry Again\n" RESET);
        goto yes;
    }

    if (T1 == 1)
    {
        system("cls");
        room_check();
        printf(BLUE "Press 1 to back\n" RESET);
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
            printf(RED "Invalid Input \nTry Again : " RESET);
            goto P;
        }
    }
    if (T1 == 2)
    {
        system("cls");
        class_check();

        printf(BLUE "Press 1 to back\n" RESET);
        scanf("%d", &z);
        if (z == 1)
        {
            system("cls");
            goto yes;
        }
        else
        {
            printf(RED "Invalid Input \nTry Again : " RESET);
            goto P;
        }
    }
    if (T1 == 5)
    {
        system("cls");
        printf(CYAN "Logging OUT" RESET);
        for (int i = 0; i < 3; i++)
        {
            printf(CYAN "." RESET);
            fflush(stdout);
            sleep(1);
        }
        printf("\n");
        main();
    }
    if (T1 == 3)
    {
        std_marks();
        printf(BLUE "Press 1 to back\n" RESET);
        scanf("%d", &z);
        if (z == 1)
        {
            system("cls");
            goto yes;
        }
    }
    if (T1 == 4)
    {
        system("cls");
        FILE *not;
        not = fopen("notice.txt", "a"); // Append mode
        if (!not)
        {
            printf(RED "Error opening notice.txt.\n" RESET);
            goto yes;
        }
        getchar(); // clear input buffer
        char notice[256];
        char currentDate[50];
        char currentDay[20];

        // Get current date and day automatically
        getCurrentDateTime(currentDate, currentDay);
        
        printf(GREEN "Current Date: %s (%s)\n" RESET, currentDate, currentDay);
        printf(CYAN "Enter your notice: " RESET);
        fgets(notice, sizeof(notice), stdin);
        notice[strcspn(notice, "\n")] = 0;

        fprintf(not, "[%s - %s] %s: %s\n\n", currentDate, currentDay, id, notice); 
        fclose(not);
        printf(GREEN "Notice sent successfully!\n" RESET);

        printf(BLUE "\nPress 1 to go back\n" RESET);
        scanf("%d", &z);
        if (z == 1)
        {
            system("cls");
            goto yes;
        }
        else
        {
            system("cls");
            goto yes;
        }
    }
}
void stdt()
{
    system("cls");
    printf(YELLOW "Logging in" RESET);
    for (int i = 0; i < 3; i++)
    {
        printf(YELLOW "." RESET);
        fflush(stdout);
        sleep(1);
    }
    printf("\n");
    // printf("\nWelcome %s\n", i);
    system("cls");
no:
    printf(CYAN BOLD "\n=== STUDENT PORTAL ===\n\n" RESET);
    printf(BLUE "1. Room Check\n" RESET);
    printf(BLUE "2. Class Check\n" RESET);
    printf(BLUE "3. Registrated Subject\n" RESET);
    printf(BLUE "4. Teacher's List\n" RESET);
    printf(BLUE "5. CGPA Calculator\n" RESET);
    printf(BLUE "6. Weekly Result\n" RESET);
    printf(BLUE "7. View Notices\n" RESET);
    printf(BLUE "8. LogOut\n\n" RESET);

    printf(YELLOW "Choose From 1-8 : " RESET);
    scanf("%d", &s);
    if (s < 1 || s > 8)
    {
        system("cls");
        printf(RED "Wrong Input .....\nTry Again\n" RESET);
        goto no;
    }
    if (s == 1)
    {
        system("cls");
        printf(CYAN "Room Check :\n" RESET);
        room_check();

        printf(BLUE "Press 1 to back\n" RESET);
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
            printf(RED "Invalid Input \nTry Again : " RESET);
            goto T;
        }
    }
    if (s == 3)
    {
        system("cls");
        printf(CYAN "   Credit Hour |Registrated Subjects:\n\n" RESET);
        printf(GREEN "1.     3       |Computer Programming 1\n" RESET);
        printf(GREEN "2.    1.5      |Computer Programming 1 Lab\n" RESET);
        printf(GREEN "3.     3       |Basic Electrical Engineering\n" RESET);
        printf(GREEN "4.    1.5      |Basic Electrical Engineering Lab\n" RESET);
        printf(GREEN "5.     2       |Advanced English\n" RESET);
        printf(GREEN "6.     1       |Text of Ethics and Morality \n" RESET);
        printf(GREEN "7.     3       |Mathematics I (Differential and Integral Calculus)\n" RESET);
        printf(GREEN "8.     3       |Physics I (Mechanics, Waves, Heat and Thermodynamics)\n\n" RESET);

        printf(BLUE "Press 1 to back\n" RESET);
        scanf("%d", &z);
        if (z == 1)
        {
            system("cls");
            goto no;
        }
        else
        {
            system("cls");
            printf(RED "Invalid Input \nTry Again : " RESET);
            goto T;
        }
    }
    if (s == 4)
    {
        system("cls");
        printf(CYAN "Teacher's Info :\n\n\n" RESET);
        printf(MAGENTA "Teacher's Name   |         Email Address     |  Phone Number\n\n" RESET);
        printf(GREEN "Jamil As-ad      | jamilasad1@gmail.com      |  01626890190\n" RESET);
        printf(GREEN "Sahariar Reza    | Sahariarp@gmail.com       |  01521328094\n" RESET);
        printf(GREEN "Md.Rashedul Islam| rashed_math@gmail.com     |  01717121186\n" RESET);
        printf(GREEN "Kafil Uddin      | mdkafil_iiuc@gmail.com    |  01819101372\n" RESET);
        printf(GREEN "Abdullah Al Mamun| mamun.phys@gmail.com      |  01521483685\n\n" RESET);
        printf(BLUE "Press 1 to back\n" RESET);
        scanf("%d", &z);
        if (z == 1)
        {
            system("cls");
            goto no;
        }
        else
        {
            printf(RED "Invalid Input \nTry Again : " RESET);
            goto T;
        }
    }
    if (s == 2)
    {
        system("cls");
        class_check();
        printf(BLUE "Press 1 to back\n" RESET);
        scanf("%d", &z);
        if (z == 1)
        {
            system("cls");
            goto no;
        }
        else
        {
            printf(RED "Invalid Input \nTry Again : " RESET);
            goto T;
        }
    }
    if (s == 5)
    {
        cgpa();
        printf(BLUE "Press 1 to back\n" RESET);
        scanf("%d", &z);
        if (z == 1)
        {
            system("cls");
            goto no;
        }
        else
        {
            system("cls");
            printf(RED "Invalid Input \nTry Again : " RESET);
            goto T;
        }
    }
    if (s == 7)
    {
        system("cls");
        char currentDate[50];
        char currentDay[20];
        getCurrentDateTime(currentDate, currentDay);
        
        printf(MAGENTA "Today: %s (%s)\n" RESET, currentDate, currentDay);
        
        FILE *not = fopen("notice.txt", "r");
        if (!not)
        {
            printf(YELLOW "No notices available.\n" RESET);
        }
        else
        {
            char line[256];
            printf(CYAN BOLD "\n--- Latest Notices ---\n\n" RESET);
            while (fgets(line, sizeof(line), not))
            {
                printf(GREEN "%s" RESET, line);
            }
            fclose(not);
        }

        printf(BLUE "\nPress 1 to go back\n" RESET);
        scanf("%d", &z);
        if (z == 1)
        {
            system("cls");
            goto no;
        }
        else
        {
            system("cls");
            goto no;
        }
    }

    if (s == 8)
    {
        system("cls");
        printf(CYAN "Logging OUT" RESET);
        for (int i = 0; i < 3; i++)
        {
            printf(CYAN "." RESET);
            fflush(stdout);
            sleep(1);
        }
        printf("\n");
        main();
    }
    if (s == 6)
    {
        system("cls");
        FILE *check;
        check = fopen("weeklymarks.txt", "r");
        if (check == NULL)
        {
            printf(YELLOW "No weekly marks recorded yet.\n" RESET);
        }
        else
        {
            char line[256];
            printf(CYAN BOLD "\n--- Weekly Test Marks ---\n\n" RESET);
            while (fgets(line, sizeof(line), check))
            {
                printf(GREEN "%s" RESET, line);
            }
            fclose(check);
        }
        printf(BLUE "\nPress 1 to back\n" RESET);
        scanf("%d", &z);
        if (z == 1)
        {
            system("cls");
            goto no;
        }
        else
        {
            system("cls");
            printf(RED "Invalid Input \nTry Again : " RESET);
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

    printf(CYAN BOLD "Welcome to Teacher Registration\n\n" RESET);
pc:
    printf(YELLOW "Enter The 10 Digit Code Provided By the Authority to registration :\n" RESET);
    fgets(regT, sizeof(regT), stdin);
    regT[strcspn(regT, "\n")] = 0;
    if (strcmp(regT, chk) == 0)
    {
        printf(GREEN "Verification Successful\nNow You can Proceed\n" RESET);
        system("cls");
        printf(CYAN BOLD "----Welcome To Teacher Registration Page----\n\n" RESET);
        FILE *Tea;

        printf(MAGENTA "\n=== Registration ===\n" RESET);
        printf(YELLOW "Enter Your Name\n" RESET);
        fgets(Tname, sizeof(Tname), stdin);
        Tname[strcspn(Tname, "\n")] = 0;
        printf(YELLOW "Enter Your ID Name\n" RESET);
        fgets(Tid, sizeof(Tid), stdin);
        Tid[strcspn(Tid, "\n")] = 0;
        printf(YELLOW "Enter Your Password \n" RESET);
        fgets(Tpass, sizeof(Tpass), stdin);
        Tpass[strcspn(Tpass, "\n")] = 0;

        Tea = fopen("teacherinfo.txt", "a");
        fprintf(Tea, "%s %s\n", Tid, Tpass);
        fclose(Tea);
        printf(GREEN "\nRegistration successful!\n\n" RESET);
        printf(BLUE "Your Username : %s\n" RESET, Tid);
        printf(BLUE "Your Password : %s\n\n" RESET, Tpass);
    logt:
        printf(BLUE "To Login press 2\n" RESET);
        scanf("%d", &n);
        if (n == 2)
        {
            loginT();
        }
        else
        {
            printf(RED "Try Again\n\n" RESET);
            goto logt;
        }
    }
    else
    {
        pck--;
        system("cls");
        printf(RED "You have %d chances\n" RESET, pck);

        if (pck == 0)
        {
            system("cls");
            printf(RED BOLD "You Have Been Blocked\nContract In 'ACAD' " RESET);

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
    printf(CYAN "Enter Day (1-5)\n" RESET);
    printf(BLUE "1.Sat  2.Sun  3.Mon  4.Tues  5.Wed\n" RESET);
    scanf("%d", &d);
    printf(YELLOW "Enter period number (1-6): " RESET);
    scanf("%d", &period);
    printf(YELLOW "Enter room name (e.g., C105): " RESET);
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
    printf(CYAN "Enter Day (1-5)\n" RESET);
    printf(BLUE "1.Sat  2.Sun  3.Mon  4.Tues  5.Wed\n" RESET);
    scanf("%d", &d);
    printf(YELLOW "Enter your section (1AM/1BM/1CM): " RESET);
    scanf("%s", section);
    printf(YELLOW "Enter period number (1-6): " RESET);
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

            printf(MAGENTA "\nTime: %s\n" RESET, time);
            if (strcmp(section, "1AM") == 0)
                printf(GREEN "Class: %s\n" RESET, am);
            else if (strcmp(section, "1BM") == 0)
                printf(GREEN "Class: %s\n" RESET, bm);
            else if (strcmp(section, "1CM") == 0)
                printf(GREEN "Class: %s\n" RESET, cm);
            else
                printf(RED "Invalid section!\n" RESET);
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
    printf(CYAN "Enter the number of subjects: " RESET);
    scanf("%d", &n);

    getchar();
    char subjectName[n][50];
    float marks[n];
    float gpa[n], credits[n];

    float totalPoints = 0.0, totalCredits = 0.0;

    for (int i = 0; i < n; i++)
    {
        printf(YELLOW "\nSubject %d:\n" RESET, i + 1);

        printf(CYAN "Subject Name: " RESET);
        fgets(subjectName[i], sizeof(subjectName[i]), stdin);
        subjectName[i][strcspn(subjectName[i], "\n")] = '\0';

        printf(CYAN "Enter credit for %s: " RESET, subjectName[i]);
        scanf("%f", &credits[i]);

        printf(CYAN "Enter marks for %s: " RESET, subjectName[i]);
        scanf("%f", &marks[i]);
        getchar();

        gpa[i] = convertMarksToGPA(marks[i]);

        totalPoints += gpa[i] * credits[i];
        totalCredits += credits[i];
    }

    float cgpa = totalPoints / totalCredits;

    system("cls");
    printf(MAGENTA BOLD "\n===== Result Summary =====\n" RESET);
    for (int i = 0; i < n; i++)
    {
        printf(GREEN "Subject: %-20s | Credit: %.1f | Marks: %.0f | GPA: %.2f\n" RESET,
               subjectName[i], credits[i], marks[i], gpa[i]);
    }

    printf(BLUE "\nTotal Credits: %.2f" RESET, totalCredits);
    printf(BLUE "\nTotal Grade Points: %.2f" RESET, totalPoints);
    printf(CYAN BOLD "\nCGPA: %.2f\n\n" RESET, cgpa);
}
void std_marks()
{
    system("cls");
    int S;
    FILE *mark;
    mark = fopen("weeklymarks.txt", "a");
    if (!mark)
    {
        printf(RED "Error opening weeklymarks.txt for writing.\n" RESET);
        return;
    }
    getchar(); // Clear input buffer
    char currentDate[50];
    char currentDay[20];
    
    // Get current date and day automatically
    getCurrentDateTime(currentDate, currentDay);
    
    printf(GREEN "Current Date: %s (%s)\n" RESET, currentDate, currentDay);
    printf(CYAN "Enter The Subject Name: " RESET);
    fgets(sub, sizeof(sub), stdin);
    sub[strcspn(sub, "\n")] = 0;

    printf(YELLOW "\nEnter The Total Present Students: " RESET);
    scanf("%d", &S);
    getchar(); // Clear input buffer
    fprintf(mark, "EXAM DATE : %s (%s) \nEXAM NAME : %s   Student(Participated): %d\n\n", currentDate, currentDay, sub, S);
    int arr[S];
    for (int i = 0; i < S; i++)
    {
        char studentid[10];
        int marks;
        printf(BLUE "Enter Student %d ID: " RESET, i + 1);
        fgets(studentid, sizeof(studentid), stdin);
        studentid[strcspn(studentid, "\n")] = 0;
        printf(BLUE "Enter marks for %s: " RESET, studentid);
        scanf("%d", &marks);
        getchar(); // Clear input buffer
        arr[i] = marks;
        fprintf(mark, "Student: %s, Marks: %d\n\n\n", studentid, marks);
    }
    fclose(mark);
    printf(GREEN "\nWeekly test marks recorded successfully!\n" RESET);
}
