#ifndef DAY_H
#define DAY_H

time_t var_t; // Variable storing a time_t
struct tm var_day; // Variable storing a day

void set_next_day(int count);
void set_prec_day(int count);
void set_date(time_t t);

#endif
