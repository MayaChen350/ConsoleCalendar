char* get_month(int* month);
char* get_weekday(int* weekday);

// Get the month index converted to a string.
char* get_month(int* month)
{
	switch (*month)
	{
	case 0:
		return "January";
		break;
	case 1:
		return "February";
		break;
	case 2:
		return "March";
		break;
	case 3:
		return "April";
		break;
	case 4:
		return "May";
		break;
	case 5:
		return "June";
		break;
	case 6:
		return "July";
		break;
	case 7:
		return "August";
		break;
	case 8:
		return "September";
		break;
	case 9:
		return "October";
		break;
	case 10:
		return "November";
		break;
	case 11:
		return "December";
		break;
	}
}

// Get the month index converted to a string.
char* get_weekday(int* weekday)
{
	switch (*weekday)
	{
	case 0:
		return "Sun";
		break;
	case 1:
		return "Mon";
		break;
	case 2:
		return "Tue";
		break;
	case 3:
		return "Wed";
		break;
	case 4:
		return "Thu";
		break;
	case 5:
		return "Fri";
		break;
	case 6:
		return "Sat";
		break;
	}
}