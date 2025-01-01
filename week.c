#include <stdio.h>
#include <time.h>
#include "day.h"

char w_days[7][5];

void get_curr_week(int only_curr_mdays)
{
	int curr_month = var_day.tm_mon;

	while (var_day.tm_wday != 0)
	{
		set_prec_day(1);
	}

	// Get the next 7 days
	for (int i = 0; i < 7; i++)
	{
		if (var_day.tm_mon == curr_month || !only_curr_mdays)
		{
			if (var_day.tm_mday < 10)
			{
				snprintf(w_days[i], sizeof(w_days[i]), "[0%d]", var_day.tm_mday);
			}
			else
			{
				snprintf(w_days[i], sizeof(w_days[i]), "[%d]", var_day.tm_mday);
			}
		}
		else
			snprintf(w_days[i], sizeof(w_days[i]), "    ", var_day.tm_mday);

		set_next_day(1);
	}

}