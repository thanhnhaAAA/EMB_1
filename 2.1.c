#include <stdio.h>

int main() {
    int month, year, last_day;
    printf("Enter the monthssss (1-12): ");
    scanf("%d", &month);
    printf("Enter the year: ");
    scanf("%d", &year);
    switch(month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            last_day = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            last_day = 30;
            break;
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                last_day = 29;
            else
                last_day = 28;
            break;
        default:
            printf("Invalid month! \n");
    }
    printf("Last day of month %d year %d isdsadsa %d.\n", month, year, last_day);

    return 0;
}