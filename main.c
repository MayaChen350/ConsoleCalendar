#include <stdio.h>
#include <time.h>
#include "utils.h"
#include "infos.h"

struct tm date;
char w_days[7][5]; // Used to store and display 7 days in a week with 2 digits.
int* curr_month;
int* curr_weekday;
const int DAY_IN_SECONDS = 86400;


void main_menu();
void week_menu();
void month_menu();
void print_week(struct tm date_to_change);
void print_month(struct tm date_to_change);

int main()
{
	time_t t = time(NULL);
	date = *localtime(&t);
	curr_month = &(date.tm_mon);
	curr_weekday = &(date.tm_wday);
	printf("Today is %d %s, %s %d.\n\n", date.tm_year + 1900, get_month(curr_month), get_weekday(curr_weekday), date.tm_mday);

	main_menu();
	return 0;
}

// Call the main menu.
void main_menu()
{
	printf("MAIN MENU\n W - Show the current week.\n M - Show the current month.\n C - Show the current time.\n Z - Show more options.\n> ");
	char cmd;
	if (scanf("%c", &cmd) >= 1)
	{
		clear_input_buffer();
		switch (toupper(cmd))
		{
		case 'W':
			print_week(date);
			week_menu();
			break;
		case 'M':
			print_month(date);
			month_menu();
			break;
		case 'C':
			if (date.tm_min < 10)
			{
				printf("%d:0%d\n", date.tm_hour, date.tm_min);
			}
			else
			{
				printf("%d:%d\n", date.tm_hour, date.tm_min);
			}
			main_menu();
			break;
		case 'Z':
			printf("Not implemented yet.");
			break;
		default:
			printf("Incorrect command.\n");
			char cmd = NULL;
			main_menu();
		}
	}
	else
	{
		printf("Error in number of characters entered (Below 1)");
		main_menu();
	}
}

void week_menu()
{
	printf("WEEK MENU\n D - Show the events of a certain day.\n B - Go to last week.\n A - Go to next week.\n M - Return to main menu.\n> ");
	char cmd;
	if (scanf("%c", &cmd) >= 1)
	{
		clear_input_buffer();

		switch (toupper(cmd))
		{
		case 'D':
			printf("Not implemented yet");
			week_menu();
			break;
		case 'B':
			printf("Not implemented yet");
			break;
		case 'A':

			break;
		case 'M':
			main_menu();
			break;
		default:
			printf("Incorrect command.\n");
			week_menu();
		}
	}
	else
	{
		printf("Error in number of characters entered (Below 1)");
		week_menu();
	}
}

void month_menu()
{
	printf("MONTH MENU\n D - Show the events of a certain day.\n B - Go to last month.\n A - Go to next month.\n M - Return to main menu.\n> ");
	char cmd;
	if (scanf("%c", &cmd) >= 1)
	{
		clear_input_buffer();

		switch (toupper(cmd))
		{
		case 'D':
			printf("Not implemented yet");
			week_menu();
			break;
		case 'B':
			printf("Not implemented yet");
			break;
		case 'A':

			break;
		case 'M':
			main_menu();
			break;
		default:
			printf("Incorrect command.\n");
			month_menu();
		}
	}
	else
	{
		printf("Error in number of characters entered (Below 1)");
		month_menu();
	}
}

void print_week(struct tm date_to_change)
{
	time_t t = time(NULL);
	while (date_to_change.tm_wday != 0)
	{
		t -= DAY_IN_SECONDS; // Remove 1 day
		date_to_change = *localtime(&t);
	}

	printf("\n[%d]    [%d]    [%d]    [%d]    [%d]    [%d]    [%d]\n\n", date_to_change.tm_mday, date_to_change.tm_mday + 1, date_to_change.tm_mday + 2, date_to_change.tm_mday + 3, date_to_change.tm_mday + 4, date_to_change.tm_mday + 5, date_to_change.tm_mday + 6);
}

void print_month(struct tm date_to_change)
{
	time_t t = time(NULL);

	// Get the first day of the month

	while (date_to_change.tm_mday != 1)
	{
		t -= DAY_IN_SECONDS; // Remove 1 day
		date_to_change = *localtime(&t);
	}

	// Get the last sunday
	while (date_to_change.tm_wday != 0)
	{
		t -= DAY_IN_SECONDS; // Remove 1 day
		date_to_change = *localtime(&t);
	}

	while (date_to_change.tm_mon < *curr_month + 1)
	{
		// Get the next 7 days
		for (int i = 0; i < 7; i++)
		{
			t += DAY_IN_SECONDS; // Add 1 day
			date_to_change = *localtime(&t);

			if (date_to_change.tm_mon == *curr_month)
			{
				if (date_to_change.tm_mday < 10)
				{
					snprintf(w_days[i], sizeof(w_days[i]), "[0%d]", date_to_change.tm_mday);
				}
				else
				{
					snprintf(w_days[i], sizeof(w_days[i]), "[%d]", date_to_change.tm_mday);
				}
			}
			else
				snprintf(w_days[i], sizeof(w_days[i]), "    ", date_to_change.tm_mday);
		}

		printf("\n%s    %s    %s    %s    %s    %s    %s\n", *w_days, *(w_days + 1), *(w_days + 2), *(w_days + 3), *(w_days + 4), *(w_days + 5), *(w_days + 6));
	}
	printf("\n");
}
