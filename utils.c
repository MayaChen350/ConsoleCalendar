#include <stdio.h>

void clear_input_buffer()
{
	char c;
	do
	{
		c = getchar();
	} while (c != '\n');
}