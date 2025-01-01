#ifndef EVENT_H
#define EVENT_H

struct event
{
	char name[200];
	unsigned short dayOfTheYear;
	char recursivity;
};

void write_event();
struct event read_event();
#endif