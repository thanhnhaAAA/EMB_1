#include<stdio.h>
#include<math.h>
#include <ctype.h>
#include <time.h>
    /************************************************************************ 
    * Funtion for 103: Change lowercase or uppercase letters and vice versa *
    *************************************************************************/
char change_case(char c) {
    if (islower(c)) {
        return toupper(c);
    } else if (isupper(c)) {
        return tolower(c);
    }
    return c; // If the character is not upper or lower case, return itself
}
    /************************************************************************ 
    * Funtion for 204: Find the largest number between three numbers        *
    *************************************************************************/
int max(int num1, int num2, int num3) {
    if (num1 >= num2 && num1 >= num3) {
        return num1;
    } else if (num2 >= num1 && num2 >= num3) {
        return num2;
    } else {
        return num3;
    }
}
    /************************************************************************ 
    * Funtion for 207: Swap the values ​​of two variables                     *
    *************************************************************************/
void swap207(int *a, int *b) {
    int temp; 
    temp = *a; 
    *a = *b; 
    *b = temp; 
}
    /************************************************************************ 
    * Funtion for 209:    no need for temporary variables                   *
    *************************************************************************/
void swap208(int *a, int *b) {
    *a = *a + *b; 
    *b = *a - *b; 
    *a = *a - *b; 
}
    /************************************************************************ 
    * Funtion for 209: electric bill                                        *
    *************************************************************************/
int calculate_bill(int consumption) {
    int Level1 = 600;
    int Level2 = 900;
    int Level3 = 1200;
    int Level4 = 1500;
    int bill = 0;

    if (consumption <= 100) {
        bill = Level1 * consumption;
    } else if (consumption <= 150) {
        bill = Level1 * 100 + Level2 * (consumption - 100);
    } else if (consumption <= 250) {
        bill = Level1 * 100 + Level2 * 50 + Level3 * (consumption - 150);
    } else {
        bill = Level1 * 100 + Level2 * 50 + Level3 * 100 + Level4 * (consumption - 250);
    }

    return bill;
}
    /************************************************************************ 
    * Funtion for 2010:     Calculate the 2 day keeping interval            *                         *
    *************************************************************************/
// 1.Function to check if a year is a leap year
int isLeapYear(int year) {
    if (year % 400 == 0) return 1;
    if (year % 100 == 0) return 0;
    if (year % 4 == 0) return 1;
    return 0;
}

// 2.Function to check if a date is valid
int isValidDate(int day, int month, int year) {
    if (month < 1 || month > 12) return 0;
    if (day < 1) return 0;
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if (day > 31) return 0;
            break;
        case 4: case 6: case 9: case 11:
            if (day > 30) return 0;
            break;
        case 2:
            if (isLeapYear(year)) {
                if (day > 29) return 0;
            } else {
                if (day > 28) return 0;
            }
            break;
        default:
            return 0;
    }
    return 1;
}

// 3.Function to input a date from the user
void inputDate(int *day, int *month, int *year) {
    while (1) {
        printf("Enter day (1-31): ");
        scanf("%d", day);
        printf("Enter month (1-12): ");
        scanf("%d", month);
        printf("Enter year: ");
        scanf("%d", year);

        if (!isValidDate(*day, *month, *year)) {
            printf("Invalid date, please re-enter.\n");
        } else {
            printf("Valid date: %d / %d / %d\n", *day, *month, *year);
            break;
        }
    }
}

// Function to calculate the number of days between two dates
int calculateDaysBetween(int day1, int month1, int year1, int day2, int month2, int year2) {
    struct tm date1 = {0};
    struct tm date2 = {0};
    time_t time1, time2;

    date1.tm_mday = day1;
    date1.tm_mon = month1 - 1; // Months start from 0
    date1.tm_year = year1 - 1900; // Years start from 1900

    date2.tm_mday = day2;
    date2.tm_mon = month2 - 1; // Months start from 0
    date2.tm_year = year2 - 1900; // Years start from 1900

    time1 = mktime(&date1);
    time2 = mktime(&date2);

    double difference = difftime(time2, time1) / (60 * 60 * 24);
    return (int)difference;
}
    /************************************************************************ 
    * Funtion for 304:     Function to calculate average mark               *       
    *************************************************************************/
        // Function to calculate average mark
        float calculateAverage(int marks[], int numSubjects) {
            if (numSubjects <= 0) {
                return 0.0; // Return 0 if there are no subjects to avoid division by zero
            }
            
            int sum = 0;
            for (int i = 0; i < numSubjects; i++) {
                sum += marks[i];
            }
            
            return (float)sum / numSubjects;
        }


int main(){
    printf("          -----------------------------------------\n");
    printf("          -     welcom to the program by Hung     -\n");
    printf("          -----------------------------------------\n");

    /****************************************************************************
    *           Start the program by asking the user to select Run or Exit      *
    *****************************************************************************/
        /****************************************************************************
    *           Use Switch for users to choose exercises                        *
    *****************************************************************************/
        int exercise;
        printf("-------------------------------------------------------\n");
        printf("-      Enter exrcise name according the menthod       -\n");
        printf("-            'chapter name 0 lesson order'            -\n");
        printf("-------------------------------------------------------\n");
        printf("101 - theoretical exercises                             \n");
        printf("102 - theoretical exercises                             \n");
        printf("103 - change character                                  \n");
        printf("104 - theoretical exercises                             \n");
        printf("105 - theoretical exercises                             \n");
        printf("106 - do no thing                                       \n");
        printf("107 - perimeter and area of a rectangle                 \n");
        printf("201 - the last day of the month                         \n");
        printf("202 - Calculate factorial                               \n");
        printf("203 - compare two number                                \n");
        printf("204 - find the largest valua among three numbers        \n");
        printf("205 - check even number of odd number                   \n");
        printf("206 - check the leap year                               \n");
        printf("207 - change the value two variable to use 1 varable    \n");
        printf("208 - change the value two variable do not use 1 varable \n");
        printf("209 - change the value two variable to use 1 varable    \n");
        printf("2010 - calculate distance between 2 time periods       \n");
    
    start_1:
    char start;
    printf(" Run(r) or Exit(e) ");
    scanf(" %c",&start);
    switch (start)
    {
    case 'R':
    case 'r':
    /****************************************************************************
    *           Use Switch for users to choose exercises                        *
    *****************************************************************************/
        int exercise;

        scanf("%d",&exercise);
    switch (exercise)
        {
        case 101:                         // different
            printf(" _____________________________________________________________\n");
            printf(" _ include<....>   |   used for the C/C++ standard library.  _\n");
            printf(" _ include'....'   |   used for user-defined libraries.      _\n");
            printf(" _____________________________________________________________\n");
            goto start_1;

        case 102:                        // should
            printf(" _____________________________________________________________\n");
            printf(" + x = 100    |   char, or unsigned char, or int, etc…       +\n");
            printf(" + y = 49.322 |   float, double.                             +\n");
            printf(" _____________________________________________________________\n");
            goto start_1;

        case 103:                       // change character
            ls103:
            char alphabet;
            char choice_0;
            printf("change character");
            printf("__________ Enter alphabet_____________ : ");
            scanf(" %c",&alphabet);
            alphabet = change_case(alphabet);
            printf("_________Changed characters___________ :%c\n", alphabet);
            printf("Do you want to enter more characters? (y/n): \n");
            scanf(" %c", &choice_0);
            if( choice_0 == 'y' ||choice_0 == 'Y'){
                    goto ls103;
            }else{
                    goto start_1;
            }
        case 104:                      // sizeof 
            printf("    -----------------------------------------------------------------\n");
            printf("    - struct {                  |                                   -\n");           
            printf("    -    char c1;               |                                   -\n");
            printf("    -    short sh2;             |      Size of struct: 16 bytes     -\n");
            printf("    -    long  l2;              |                                   -\n");
            printf("    -  } t1;                    |                                   -\n");
            printf("    -----------------------------------------------------------------\n");
            printf("    -----------------------------------------------------------------\n");
            printf("    #pragma pack(1)             |                                   -\n"); 
            printf("    - struct {                  |                                   -\n");
            printf("    -    char c1;               |                                   -\n");
            printf("    -    short sh2;             |      Size of struct: 11 bytes     -\n");
            printf("    -    long  l2;              |                                   -\n");
            printf("    -  } t2;                    |                                   -\n");
            printf("    -----------------------------------------------------------------\n");
            printf("    -----------------------------------------------------------------\n");
            printf("    - union {                   |                                   -\n");           
            printf("    -   short c1;               |                                   -\n");
            printf("    -   long sh2;               |      Size of struct: 8 bytes      -\n");
            printf("    -   char  l2;               |                                   -\n");
            printf("    -  } u3;                    |                                   -\n");
            printf("    -----------------------------------------------------------------\n");
            printf("    -----------------------------------------------------------------\n");
            printf("    - struct {                  |                                   -\n");           
            printf("    -    int c1 = 3;            |                                   -\n");
            printf("    -    short sh2 =2;          |      Size of struct: 8 bytes      -\n");
            printf("    -    long  l2 = 6;          |                                   -\n");
            printf("    -  } t1;                    |                                   -\n");
            printf("    -----------------------------------------------------------------\n");
            goto start_1;
            break;
        case 105:
            printf("    -----------------------------------------------------------------\n");
            printf("    -#define      | Macro definition.                               -\n");
            printf("    -#include     | Includes header file.                           -\n");
            printf("    -#if          | Starts the preprocessing condition block.       -\n");
            printf("    -#ifdef       | Check if macro is defined or not.               -\n");
            printf("    -#ifndef      | Check if the macro is not defined.              -\n");
            printf("    -#else        | Another part of the condition block.            -\n");
            printf("    -#elif        | Combine else and if in preprocessor directives. -\n");
            printf("    -----------------------------------------------------------------\n");
            goto start_1;
        case 106:
            printf("-------------------------- DO NOT THINGS ------------------------\n");
            goto start_1;
        case 107:                // perimeter and area of a rectangle
            ls107:
            char choice_1;
            float edge1,edge2,V,S;
            printf("perimeter and area of a rectangle");
            printf("--------- Calculate the perimeter and area of a rectangle--------\n");
            printf(" Enter first edge  ");
            scanf("%f",&edge1);
            printf(" Enter second edge ");
            scanf("%f",&edge2);
            V = (edge1 + edge2)*2;
            S = edge1 * edge2;
            printf("perimeter of a rectangle %.2f and area of a rectangle %.2f\n ",V,S);
             printf("do you want to check again? (y/n): \n");
            scanf(" %c", &choice_1);
            if( choice_1 == 'y' ||choice_1 == 'Y'){
                    goto ls107;
            }else{
                    goto start_1;
            }
            
        case 201:
            ls201:
            char choice_2;
            int month_201, year_201;
            printf("enter the number of months : ");
            scanf("%d",&month_201);
            printf("enter the mumber of year : ");
            scanf("%d",&year_201);
            while (month_201 < 1 || month_201 > 12 )  // because one year has 12 months
            {
            printf(" nhap lai thang cho phu hop "); // re-enter the month
            scanf("%d",&month_201);
            }
            
            if(month_201 == 1 || month_201 == 3|| month_201 == 5||month_201 == 7|| month_201 == 8||month_201 == 10|| month_201 == 12){
                printf(" That month has 31 days \n");
                }else if(month_201 == 2){
                    if(year_201 %4 == 0){  // find leap yeas 
                    printf("That month has 29 days \n");
                }else{
                    printf(" that month has 28 days \n");
                }
                }else{
                    printf(" That month has 30 days \n"); 
            }
            // muốn tìm lại nữa
            printf("do you want to check again? (y/n): \n");
            scanf(" %c", &choice_2);
            if( choice_2 == 'y' ||choice_2 == 'Y'){
                    goto ls201;
            }else{
                    goto start_1;
            }
        case 202:        //factorial
            ls202:
            int factorial;
            int i_factorial = 1;
            long long A = 1;
            char choice_3;
            printf(" enter value for x ");
            scanf("%d",&factorial);
            while(i_factorial <= factorial){  // factorial is product from 0 to n
                A = i_factorial*A;
                i_factorial++;        // ascending
            }
            printf(" Value %d! is %lld \n",factorial,A);
            printf("do you want to check again? (y/n): \n");
            scanf(" %c", &choice_3);
            if( choice_3 == 'y' ||choice_3 == 'Y'){
                    goto ls202;
            }else{
                    goto start_1;
            }
        case 203:
                ls203:
                char choice_4;
                float num1,num2;
                printf("enter value a : ");
                scanf("%f",&num1);
                printf("enter value b : ");
                scanf("%f",&num2);
                if( num1 == num2){
                    printf(" %f = %f ",num1,num2);
                }else if (num1 > num2) {
                        printf(" %f > %f \n",num1,num2);
                        }else{
                        printf(" %f < %f \n",num1,num2);
                }
            printf("do you want to check again? (y/n): \n");
            scanf(" %c", &choice_4);
            if( choice_4 == 'y' ||choice_4 == 'Y'){
                    goto ls203;
            }else{
                    goto start_1;
            }
        case 204:
            ls204:
            int a, b, c;
            char choice_5;
            printf("enter a,b,c : ");
            scanf("%d %d %d", &a, &b, &c);

            int largest = max(a, b, c);
            printf(" 1th : %d\n", largest);
            printf("do you want to check again? (y/n): \n");
            scanf(" %c", &choice_5);
            if( choice_5 == 'y' ||choice_5 == 'Y'){
                    goto ls204;
            }else{
                    goto start_1;
            }
        case 205:
            ls205:
            char choice_6;
            int numrangdom;
            printf(" Enter a number ");
            scanf("%d",&numrangdom);
            if(numrangdom %2 == 0){
                printf("even number \n");
            }else{
                printf("odd number \n");
            }
            printf("do you want to check again? (y/n): \n");
            scanf(" %c", &choice_6);
            if( choice_6 == 'y' ||choice_6 == 'Y'){
                    goto ls205;
            }else{
                    goto start_1;
            }
        case 206:
            ls206:
            char choice_7;
            int year1;
            printf(" Enter a year want check ");
            scanf("%d",&year1);
            if(year1 %4 == 0 && year1 %400 != 0){
                printf("It is a leap year ");
            }else{
                printf("It isn't a leap year ");
            }
            printf("do you want to check again? (y/n): \n");
            scanf(" %c", &choice_7);
            if( choice_7 == 'y' ||choice_7 == 'Y'){
                    goto ls206;
            }else{
                    goto start_1;
            }
        case 207:
            ls207:
            char choice_8;
            int x1, y1;

            printf("Enter value x: ");
            scanf("%d", &x1);

            printf("enter value y: ");
            scanf("%d", &y1);
            printf("befor:\n");
            printf("x = %d\n", x1);
            printf("y = %d\n", y1);
            swap207(&x1, &y1);
            printf("after:\n");
            printf("x = %d\n", x1);
            printf("y = %d\n", y1);
            printf("do you want to check again? (y/n): \n");
            scanf(" %c", &choice_8);
            if( choice_8 == 'y' ||choice_8 == 'Y'){
                    goto ls207;
            }else{
                    goto start_1;
            }
        case 208:
            ls208:
            char choice_9;
            int x_1010, y_1010;

            printf("Enter value x: ");
            scanf("%d", &x_1010);

            printf("enter value y: ");
            scanf("%d", &y_1010);
                        printf("befor:\n");
            printf("x_1010 = %d\n", x_1010);
            printf("y = %d\n", y_1010);
            swap208(&x_1010, &y_1010);
            printf("after:\n");
            printf("x_1010 = %d\n", x_1010);
            printf("y = %d\n", y_1010);
            printf("do you want to check again? (y/n): \n");
            scanf(" %c", &choice_9);
            if( choice_9 == 'y' ||choice_9 == 'Y'){
                    goto ls208;
            }else{
                    goto start_1;
            }
        case 209:
            ls209:
            char choice_10;
            int consumption;
            printf("Enter kWh consumed: ");
            scanf("%d", &consumption);

            int total_bill = calculate_bill(consumption);
            printf("The electricity bill is %d VND\n", total_bill);
              printf("do you want to check again? (y/n): \n");
            scanf(" %c", &choice_10);
            if( choice_10 == 'y' ||choice_10 == 'Y'){
                    goto ls209;
            }else{
                    goto start_1;
            }
        case 2010:
            ls2010:
            char choice_11;
                  
            int day1_2010, month1_2010, year1_2010;
            int day2_2010, month2_2010, year2_2010;

            printf("Enter the first date:\n");
            inputDate(&day1_2010, &month1_2010, &year1_2010);

            printf("Enter the second date:\n");
            inputDate(&day2_2010, &month2_2010, &year2_2010);

            int daysBetween = calculateDaysBetween(day1_2010, month1_2010, year1_2010, day2_2010, month2_2010, year2_2010);
            printf("The number of days between the two dates is: %d\n", daysBetween);
            printf("do you want to check again? (y/n): \n");
            scanf(" %c", &choice_11);
            if( choice_11 == 'y' ||choice_11 == 'Y'){
                    goto ls2010;
            }else{
                    goto start_1;
            }
        case 304:
            ls304:
            char choice_12;
            int numSubjects;
    
            printf("Enter the number of subjects: ");
            scanf("%d", &numSubjects);
            
            if (numSubjects <= 0) {
                printf("Number of subjects must be greater than zero.\n");
                return 1; // Exit with an error code
            }
            
            int marks[numSubjects];
            
            printf("Enter the marks for %d subjects:\n", numSubjects);
            for (int i = 0; i < numSubjects; i++) {
                printf("Subject %d: ", i + 1);
                scanf("%d", &marks[i]);
            }
            
            float average = calculateAverage(marks, numSubjects);
            printf("The average mark is: %.2f\n", average);
            
            printf("do you want to check again? (y/n): \n");
            scanf(" %c", &choice_12);
            if( choice_12 == 'y' ||choice_12 == 'Y'){
                    goto ls304;
            }else{
                    goto start_1;
            }
        case 302:
            printf("hung");
        

            
        }   
        
    case 'E':
    // case 'e':
        break;

        default:
        break;
    
    }

}


