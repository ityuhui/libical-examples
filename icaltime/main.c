#include <libical/icaltime.h>
#include <stdio.h>

int main()
{
    const char *date_time_string = "20110617T065959Z";
    struct icaltimetype ict = icaltime_from_string(date_time_string);
    time_t atime = icaltime_as_timet(ict);
    printf("The time is %ld\n", atime);
    return 0;
}
