#include <stdio.h>
#include <time.h>
#include "utils.h"
#include "const.h"
#include "infos.h"
#include "day.h"
#include "week.h"

#define TRUE 1
#define FALSE 0

void main_menu();
void week_menu();
void month_menu();
void print_week();
void print_month();

int main()
{
	set_date(time(NULL));

	printf("Today is %d %s, %s %d.\n\n", var_day.tm_year + 1900, get_month(var_day.tm_mon), get_weekday(var_day.tm_wday), var_day.tm_mday);

	main_menu();
	return 0;
}

// Call the main menu.
void main_menu()
{
	set_date(time(NULL));
	printf("MAIN MENU\n W - Show the current week.\n M - Show the current month.\n C - Show the current time.\n Z - Show more options.\n> ");
	char cmd;
	if (scanf("%c", &cmd) >= 1)
	{
		clear_input_buffer();
		switch (toupper(cmd))
		{
		case 'W':
			print_week();
			week_menu();
			break;
		case 'M':
			print_month();
			month_menu();
			break;
		case 'C':
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
			set_prec_day(14);
			print_week();
			week_menu();
			break;
		case 'A':
			set_next_day(6);
			print_week();
			week_menu();
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
	int curr_mon = var_day.tm_mon;
	char cmd;
	if (scanf("%c", &cmd) >= 1)
	{
		clear_input_buffer();

		switch (toupper(cmd))
		{
		case 'D':
			printf("Not implemented yet");
			month_menu();
			break;
		case 'B':
			while (var_day.tm_mon == curr_mon)
			{
				set_prec_day(1);
			}
			curr_mon = var_day.tm_mon;
			print_month();
			while (var_day.tm_mon != curr_mon)
			{
				set_prec_day(1);
			}
			month_menu();
			break;
		case 'A':
			while (var_day.tm_mon == curr_mon)
			{
				set_next_day(1);
			}
			curr_mon = var_day.tm_mon;
			print_month();
			while (var_day.tm_mon != curr_mon)
			{
				set_prec_day(1);
			}
			month_menu();
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

void print_week()
{
	get_curr_week(FALSE);

	printf("\n%s    %s    %s    %s    %s    %s    %s\n", *w_days, *(w_days + 1), *(w_days + 2), *(w_days + 3), *(w_days + 4), *(w_days + 5), *(w_days + 6));
}

void print_month()
{
	// Get the first day of the month
	while (var_day.tm_mday != 1)
	{
		set_prec_day(1);
	}

	int temp_month = var_day.tm_mon; // The month of the printed month

	printf("\n| %s %d |\n", get_month(var_day.tm_mon), var_day.tm_year + 1900);

	for (int i = 0; i < 6; i++)
	{
		get_curr_week(TRUE);

		printf("\n%s    %s    %s    %s    %s    %s    %s\n", *w_days, *(w_days + 1), *(w_days + 2), *(w_days + 3), *(w_days + 4), *(w_days + 5), *(w_days + 6));

		if (var_day.tm_mon != temp_month)
			break;
	}
	printf("\n");

	// Go back to the month it was
	while (var_day.tm_mon != temp_month)
	{
		set_prec_day(1);
	}
}