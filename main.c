#include <stdio.h>
#include <time.h>
#include "utils.h"
#include "const.h"
#include "infos.h"
#include "day.h"
#include "week.h"

#define TRUE 1
#define FALSE 0

time_t t_default; // A time_t of the current date.

void main_menu();
void week_menu();
void month_menu();
void print_week(time_t date_to_change);
void print_month(time_t date_to_change);

int main()
{
	t_default = time(NULL);
	set_date(t_default);

	printf("Today is %d %s, %s %d.\n\n", var_day.tm_year + 1900, get_month(&var_day.tm_mon), get_weekday(&var_day.tm_wday), var_day.tm_mday);

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
			print_week(t_default);
			week_menu();
			break;
		case 'M':
			print_month(t_default);
			month_menu();
			break;
		case 'C':
			set_date(t_default);
			if (var_day.tm_min < 10)
			{
				printf("%d:0%d\n", var_day.tm_hour, var_day.tm_min);
			}
			else
			{
				printf("%d:%d\n", var_day.tm_hour, var_day.tm_min);
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

void print_week(time_t date)
{
	set_date(date);

	get_curr_week(FALSE);

	printf("\n%s    %s    %s    %s    %s    %s    %s\n", *w_days, *(w_days + 1), *(w_days + 2), *(w_days + 3), *(w_days + 4), *(w_days + 5), *(w_days + 6));
}

void print_month(time_t date)
{
	set_date(date);

	// Get the first day of the month
	while (var_day.tm_mday != 1)
	{
		set_prec_day(1);
	}

	for (int i = 0; i < 5; i++)
	{
		get_curr_week(TRUE);

		printf("\n%s    %s    %s    %s    %s    %s    %s\n", *w_days, *(w_days + 1), *(w_days + 2), *(w_days + 3), *(w_days + 4), *(w_days + 5), *(w_days + 6));
	}
	printf("\n");
}