#include <stdio.h>
#include <stdbool.h>

bool leapYear(int year) {
	if (year % 4 != 0) {
		return false;
	}
	else if (year % 100 != 0) {
		return true;
	}
	else if (year % 400 != 0) {
		return false;
	}
	else {
		return true;
	}
}

void add_days_to_date(int* mm, int* dd, int* yy, int days_left_to_add) {
	int days_in_month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	while (days_left_to_add > 0) {
		int days_left_in_month = days_in_month[*mm] - *dd;
		if (*mm == 2 && leapYear(*yy)) {
			days_left_in_month++;
		}
		if (days_left_to_add > days_left_in_month) {
			days_left_to_add -= days_left_in_month;
			*dd = 1;
			if (*mm == 12) {
				*mm = 1;
				(*yy)++;
			}
			else {
				(*mm)++;
			}
		}
		else {
			*dd += days_left_to_add;
			days_left_to_add = 0;
		}
	}
}

int main() {
	int mm, dd, yy, days_left_to_add;
	printf("Please enter a date between the years 1800 and 10000 in the formate mm dd yy and provide the number of days to add to this date: ");
	scanf("%d %d %d %d", &mm, &dd, &yy, &days_left_to_add);
	add_days_to_date(&mm, &dd, &yy, days_left_to_add);
	printf("The new date is: %d %d %d\n", mm, dd, yy);
	return 0;
}