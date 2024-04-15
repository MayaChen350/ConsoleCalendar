#include <time.h>
#include "const.h"

time_t var_t; // Variable storing a time_t
struct tm var_day; // Variable storing a day

void set_next_day(int count);
void set_prec_day(int count);
void set_date(time_t t);

void set_next_day(int count)
{
	var_t += DAY_IN_SECONDS * count;
	var_day = *localtime(&var_t);
}

void set_prec_day(int count)
{
	var_t -= DAY_IN_SECONDS * count;
	var_day = *localtime(&var_t);
}

void set_date(time_t t)
{
	var_t = t;
	var_day = *localtime(&t);
}