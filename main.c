#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include "utils.h"

struct tm date;

void main_menu();
void week_menu();
void print_week(struct tm* ptr_date);

int main() {
	time_t t = time(NULL);
	date = *localtime(&t);

	while (date.tm_wday != 0)
	{
		t -= 86400; // Remove 1 day
		date = *localtime(&t);
	}

	main_menu();
	return 0;
}

void main_menu()
{
	printf("MAIN MENU\n W - Show the current week.\n M - Show the current month.\n C - Show the current time.\n Z - Show more options.\n");
	char cmd;
	if (scanf("%c", &cmd) >= 1)
	{
		clear_input_buffer();
		switch (toupper(cmd))
		{
		case 'W':
			print_week(&date);
			week_menu();
			break;
		case 'M':
			printf("Not implemented yet");
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
	else printf("Error in number of characters entered (Below 1)");
}

void week_menu()
{
	printf("WEEK MENU\n D - Show the events of a certain day.\n B - Go to last week.\n A - Go to next week.\n M - Return to main menu.\n");
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
	else printf("Error in number of characters entered (Below 1)");
}

void print_week(struct tm* ptr_date)
{
	printf("\n[%d]    [%d]    [%d]    [%d]    [%d]    [%d]    [%d]\n\n", ptr_date->tm_mday, ptr_date->tm_mday + 1, ptr_date->tm_mday + 2, ptr_date->tm_mday + 3, ptr_date->tm_mday + 4, ptr_date->tm_mday + 5, ptr_date->tm_mday + 6);
}

